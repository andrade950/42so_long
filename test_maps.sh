#!/bin/bash

# Colors for output
GREEN='\033[0;32m'
RED='\033[0;31m'
BLUE='\033[0;34m'
YELLOW='\033[0;33m'
NC='\033[0m' # No Color

# Function to display usage information
usage() {
    echo -e "${YELLOW}Usage:${NC} $0 <path_to_so_long_executable> <path_to_maps_folder>"
    echo "Example: $0 ./so_long ./maps"
    exit 1
}

# Check if correct number of arguments is provided
if [ $# -ne 2 ]; then
    usage
fi

SO_LONG_EXECUTABLE="$1"
MAPS_FOLDER="$2"

# Check if executable exists
if [ ! -f "$SO_LONG_EXECUTABLE" ]; then
    echo -e "${RED}Error: Executable '$SO_LONG_EXECUTABLE' not found${NC}"
    exit 1
fi

# Check if maps folder exists
if [ ! -d "$MAPS_FOLDER" ]; then
    echo -e "${RED}Error: Maps folder '$MAPS_FOLDER' not found${NC}"
    exit 1
fi

# Determine if it's normal or bonus version
if strings "$SO_LONG_EXECUTABLE" | grep -q "bonus"; then
    VERSION="BONUS"
else
    VERSION="NORMAL"
fi

echo -e "${BLUE}=== SO_LONG MAP TESTER ===${NC}"
echo -e "${YELLOW}Executable:${NC} $SO_LONG_EXECUTABLE"
echo -e "${YELLOW}Version detected:${NC} $VERSION"
echo -e "${YELLOW}Maps folder:${NC} $MAPS_FOLDER"
echo -e "${BLUE}===========================${NC}\n"

# Arrays to store map information
VALID_MAPS=()
INVALID_MAPS=()
INVALID_REASONS=()

# Test each map file in the folder
for MAP_FILE in "$MAPS_FOLDER"/*.{ber,BER}; do
    # Skip if no matching files found
    [ -e "$MAP_FILE" ] || continue
    
    MAP_NAME=$(basename "$MAP_FILE")
    
    echo -e "${YELLOW}Testing map:${NC} $MAP_NAME"
    
    # Create a temporary file to capture output
    TEMP_OUTPUT=$(mktemp)
    
    # Run so_long with the map and capture both stdout and stderr
    "$SO_LONG_EXECUTABLE" "$MAP_FILE" > "$TEMP_OUTPUT" 2>&1
    EXIT_CODE=$?
    
    # Read the output
    OUTPUT=$(cat "$TEMP_OUTPUT")
    rm "$TEMP_OUTPUT"
    
    # Check for error messages
    if echo "$OUTPUT" | grep -q "Error"; then
        ERROR_MSG=$(echo "$OUTPUT" | grep "Error" | head -1)
        echo -e "${RED}✗ INVALID${NC}: $ERROR_MSG"
        INVALID_MAPS+=("$MAP_FILE")
        INVALID_REASONS+=("$ERROR_MSG")
    elif [ $EXIT_CODE -eq 0 ]; then
        echo -e "${GREEN}✓ VALID${NC}: Map passes validation"
        VALID_MAPS+=("$MAP_FILE")
    else
        echo -e "${RED}✗ INVALID${NC}: Unknown error (Exit code: $EXIT_CODE)"
        INVALID_MAPS+=("$MAP_FILE")
        INVALID_REASONS+=("Unknown error (Exit code: $EXIT_CODE)")
    fi
    echo ""
done

# Display summary
TOTAL_MAPS=$((${#VALID_MAPS[@]} + ${#INVALID_MAPS[@]}))
echo -e "${BLUE}=== SUMMARY ===${NC}"
echo -e "${YELLOW}Total maps tested:${NC} $TOTAL_MAPS"
echo -e "${GREEN}Valid maps:${NC} ${#VALID_MAPS[@]}"
echo -e "${RED}Invalid maps:${NC} ${#INVALID_MAPS[@]}"
echo -e "${BLUE}==============${NC}"

# If no maps were found
if [ $TOTAL_MAPS -eq 0 ]; then
    echo -e "${RED}No map files found in '$MAPS_FOLDER'. Make sure your maps have .ber or .BER extension.${NC}"
    exit 1
fi

# List all invalid maps with their reasons
if [ ${#INVALID_MAPS[@]} -gt 0 ]; then
    echo -e "\n${BLUE}=== INVALID MAPS ===${NC}"
    for ((i=0; i<${#INVALID_MAPS[@]}; i++)); do
        MAP_NAME=$(basename "${INVALID_MAPS[$i]}")
        echo -e "${RED}${MAP_NAME}:${NC} ${INVALID_REASONS[$i]}"
    done
    echo ""
fi

# Interactive mode to open each valid map
if [ ${#VALID_MAPS[@]} -gt 0 ]; then
    echo -e "${BLUE}=== INTERACTIVE MAP TESTING ===${NC}"
    echo -e "You can now open each valid map one by one.\n"

    for ((i=0; i<${#VALID_MAPS[@]}; i++)); do
        MAP_FILE="${VALID_MAPS[$i]}"
        MAP_NAME=$(basename "$MAP_FILE")
        
        echo -e "${YELLOW}Map ${i+1}/${#VALID_MAPS[@]}:${NC} $MAP_NAME"
        read -p "Press Enter to open this map (or type 'skip' to skip, 'quit' to exit): " RESPONSE
        
        if [[ "$RESPONSE" == "quit" ]]; then
            echo -e "${BLUE}Exiting map tester.${NC}"
            exit 0
        elif [[ "$RESPONSE" == "skip" ]]; then
            echo -e "${YELLOW}Skipping map.${NC}\n"
            continue
        else
            echo -e "${GREEN}Opening map...${NC}"
            "$SO_LONG_EXECUTABLE" "$MAP_FILE"
            echo -e "\n${GREEN}Map test complete.${NC}\n"
        fi
    done
else
    echo -e "\n${YELLOW}No valid maps found to test interactively.${NC}"
fi

echo -e "\n${BLUE}All maps have been tested.${NC}"

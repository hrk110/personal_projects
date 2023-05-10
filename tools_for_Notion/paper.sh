#!/bin/bash

# Check the number of arguments
if [ $# -ne 1 ]; then
  echo "Usage: $0 doi"
  exit 1
fi

# Store the argument doi in a variable
doi=$1

# Activate the conda environment
conda activate tools_for_notion

# Run python script
python paper_retriever.py "$doi"

# Deactivate the conda environment
conda deactivate

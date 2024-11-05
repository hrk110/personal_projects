#!/bin/bash

# a wrapper script for paper_retriever.py

ROOT_DIR="${HOME}/repos/personal_projects/tools_for_Notion/paper_retriever"
# shellcheck disable=SC1090
# below requires latest shellcheck
source "${ROOT_DIR}/.venv/bin/activate"

python "${ROOT_DIR}/paper_retriever.py"

deactivate

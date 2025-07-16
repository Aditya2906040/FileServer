#!/bin/bash

# Ask for commit message
read -p "Commit message: " msg

# Run the commands
git add .
git commit -m "$msg"
git push

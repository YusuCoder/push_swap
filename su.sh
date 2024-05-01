#!/bin/bash

# Updating each submodule to the latest commit on its respective branch
git submodule update --remote --merge
# Commit changes in the main repository
git add .
git commit -m "Auto update script is updating submodules"
# Commit changes in each submodule and push
git submodule foreach 'git add . && git commit -m "Auto update script updating the submodules" && git push'

#!/usr/bin/env pwsh

# .\gitPush.ps1

# Stage all changes
git add .

# Capture the list of newly added files (starting with "A" for new files)
$newFiles = git status --porcelain | Where-Object { $_ -match '^\s*A\s' } | ForEach-Object { $_ -replace '^\s*A\s+', '' }

# Replace spaces with underscores for display purposes
$displayFiles = $newFiles -replace ' ', '_'

# Commit changes with correct handling of filenames
git commit -m "add $($displayFiles -join ', ')" -- $newFiles

# Push changes to the main branch
git push -u origin main

#!/usr/bin/env pwsh

# Stage all changes
git add .

# Capture the list of newly added files (starting with "A" for new files)
$newFiles = git status --porcelain | Where-Object { $_ -match '^\s*A\s' } | ForEach-Object { $_ -replace '^\s*A\s+', '' }

# If no new files are found, exit the script
if (-not $newFiles) {
    Write-Host "No new files to commit."
    exit 0
}

# Show the files that are being committed
Write-Host "Committing the following new files:"
foreach ($file in $newFiles) {
    Write-Host $file
}

# Replace spaces with underscores for display purposes
$displayFiles = $newFiles -replace ' ', '_'

# Debugging output for the command
Write-Host "Debugging commit command:"
Write-Host "git commit -m 'Add new files: $($displayFiles -join ', ')'" 

# Commit changes with correct handling of filenames
git commit -m "Add new files: $($displayFiles -join ', ')" -- $newFiles

# Push changes to the main branch
git push -u origin main

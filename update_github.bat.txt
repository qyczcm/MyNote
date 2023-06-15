@echo off

setlocal

set folder_path=D:\MyNote
set commit_message="update"

cd /d %folder_path%

REM 执行 git status
echo Running: git status
git status

REM 执行 git add -A
echo Running: git add -A
git add -A

REM 执行 git commit -a -m "update"
echo Running: git commit -a -m %commit_message%
git commit -a -m %commit_message%

REM 执行 git push origin master -f
echo Running: git push origin master -f
git push origin master -f

endlocal

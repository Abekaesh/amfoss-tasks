## Steps for the solution of the task-02
1. For creating directory with the name Coordinates-Location, used the command: ***mkdir Coordinates-Location*** .To move into that directory ,use ***cd Coordinates-Location*** .
2. For creating directory with the name North, used the command: ***mkdir North*** .To move into that directory , use ***cd North***.
3. For creating NDegree.txt , use: ***cat > NDegree.txt*** ,and type the content that are to be stored in the file. Atlast to save and close the file press "Ctrl + D".
4. Do the above step to create and store values in the files named NMinutes.txt,NSeconds.txt.
5. Use ***cat NDegrees.txt NMinutes.txt NSeconds.txt >> NorthCoordinate.txt*** to concatenate three files and store them in separate file named NorthCoordinate.txt.
6. To copy NorthCoordinate.txt to the Coordinates-Location directory and rename it as North.txt , use: ***cp NorthCoordinate.txt Coordinates-Location/North.txt*** and to remove the file NorthCoordinate.txt ,use:***rm NorthCoordinate.txt***.
7. Steps from 2 to 7 are to be repeated for the coordinates of east.
8. To create local repository , download git bash and run ***apt -get install git***,then for clone through https run, ***git clone https://github.com/Abekaesh/amfoss-tasks***.
9. Then to submit the task-02 folder on github, run ***git add task-02*** and ***git commit -m "my first commit through terminal"*** to save changes.
10. Finally run ***git push*** to submit the files in github repository.

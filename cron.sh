echo `date`
cd /home/triten/Projects/Neet
git add .
git commit -m "chore: adding new templates"
git push origin master
git push octo master
if [ $? -eq 0 ]; then
    echo OK
else
    echo FAIL
fi

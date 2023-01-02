from tableCreater import tableCreater
from fileGetter import fileGetter


fileGetter.getDirc()

availID = tableCreater.getID()
tableDict = tableCreater.CourseReader(availID)

# tableCreater.tableCreateType(tableDict)
tableCreater.tableCreateName(tableDict)

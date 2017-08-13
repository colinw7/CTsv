#include <CQTsvTable.h>
#include <CQTsvModel.h>

CQTsvTable::
CQTsvTable(QWidget *parent) :
 QTableView(parent)
{
  setObjectName("table");
}

void
CQTsvTable::
setModel(CQTsvModel *model)
{
  QTableView::setModel(model);
}

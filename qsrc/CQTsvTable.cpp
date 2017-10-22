#include <CQTsvTable.h>
#include <CQTsvModel.h>
#include <CQHeaderView.h>

CQTsvTable::
CQTsvTable(QWidget *parent) :
 QTableView(parent)
{
  setObjectName("table");

  setAlternatingRowColors(true);

  header_ = new CQHeaderView(this);

  setHorizontalHeader(header_);
}

void
CQTsvTable::
setModel(CQTsvModel *model)
{
  QTableView::setModel(model);
}

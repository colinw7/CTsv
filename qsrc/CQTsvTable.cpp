#include <CQTsvTable.h>
#include <CQTsvModel.h>

#include <QHeaderView>
#include <QSortFilterProxyModel>

CQTsvTable::
CQTsvTable(QWidget *parent) :
 CQTableView(parent)
{
  setObjectName("tsvTable");

  setSortingEnabled(true);

  horizontalHeader()->setSectionsClickable(true);

  proxy_ = new QSortFilterProxyModel;

  proxy_->setObjectName("tsvTableProxy");
}

CQTsvTable::
~CQTsvTable()
{
  delete proxy_;
}

void
CQTsvTable::
setModel(CQTsvModel *model)
{
  proxy_->setSourceModel(model);

  QTableView::setModel(proxy_);
}

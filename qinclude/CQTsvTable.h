#ifndef CQTsvTable_H
#define CQTsvTable_H

#include <CQTableView.h>

class CQTsvModel;
class QSortFilterProxyModel;

class CQTsvTable : public CQTableView {
  Q_OBJECT

 public:
  CQTsvTable(QWidget *parent=nullptr);
 ~CQTsvTable();

  void setModel(CQTsvModel *model);

 private:
  CQTsvModel*            model_ { nullptr };
  QSortFilterProxyModel* proxy_ { nullptr };
};

#endif

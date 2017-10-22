#ifndef CQTsvTable_H
#define CQTsvTable_H

#include <QTableView>

class CQTsvModel;
class CQHeaderView;

class CQTsvTable : public QTableView {
  Q_OBJECT

 public:
  CQTsvTable(QWidget *parent=nullptr);

  void setModel(CQTsvModel *model);

 private:
  CQTsvModel*   model_  { nullptr };
  CQHeaderView* header_ { nullptr };
};

#endif

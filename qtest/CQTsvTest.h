#ifndef CQTsvTest_H
#define CQTsvTest_H

#include <QFrame>

class CQTsvTable;
class CQTsvModel;

class CQTsvTest : public QFrame {
  Q_OBJECT

 public:
  CQTsvTest();

  bool isHeader() const { return header_; }
  void setHeader(bool b) { header_ = b; }

  void load(const QString &filename);

 private:
  bool        header_ { false };
  CQTsvTable *table_  { nullptr };
  CQTsvModel *model_  { nullptr };
};

#endif

#include <CQTsvTest.h>
#include <CQTsvTable.h>
#include <CQTsvModel.h>
#include <CArgs.h>

#include <QApplication>
#include <QToolButton>
#include <QVBoxLayout>
#include <iostream>

int
main(int argc, char **argv)
{
  QApplication app(argc, argv);

  CArgs args("-comment_header:b      (Comment Header) "
             "-first_line_header:b   (First Line Header) "
             "-first_column_header:b (First Column Header) "
             "-filter:s              (Filter)");

  args.parse(&argc, argv);

  bool    comment_header      = args.getArg<bool>("-comment_header");
  bool    first_line_header   = args.getArg<bool>("-first_line_header");
  bool    first_column_header = args.getArg<bool>("-first_column_header");
  QString filter              = args.getArg<std::string>("-filter").c_str();

  std::vector<QString> filenames;

  for (int i = 1; i < argc; ++i)
    filenames.push_back(argv[i]);

  if (filenames.empty())
    exit(1);

  //---

  CQTsvTest test;

  test.setCommentHeader    (comment_header);
  test.setFirstLineHeader  (first_line_header);
  test.setFirstColumnHeader(first_column_header);

  if (filter.length())
    test.setFilter(filter);

  test.load(filenames[0]);

  test.show();

  app.exec();

  return 0;
}

//-----

CQTsvTest::
CQTsvTest()
{
  QVBoxLayout *layout = new QVBoxLayout(this);

  table_ = new CQTsvTable;

  layout->addWidget(table_);
}

CQTsvTest::
~CQTsvTest()
{
  delete table_;
  delete model_;
}

void
CQTsvTest::
load(const QString &filename)
{
  model_ = new CQTsvModel;

  if (isCommentHeader())
    model_->setCommentHeader(true);

  if (isFirstLineHeader())
    model_->setFirstLineHeader(true);

  if (isFirstColumnHeader())
    model_->setFirstColumnHeader(true);

  if (filter().length())
    model_->setFilter(filter());

  model_->load(filename);

  table_->setModel(model_);
}

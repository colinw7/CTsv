#include <CQTsvTest.h>
#include <CQTsvTable.h>
#include <CQTsvModel.h>

#include <QApplication>
#include <QToolButton>
#include <QVBoxLayout>
#include <iostream>

int
main(int argc, char **argv)
{
  QApplication app(argc, argv);

  std::vector<QString> filenames;

  bool header = false;

  for (int i = 1; i < argc; ++i) {
    if (argv[i][0] == '-') {
      std::string arg = &argv[i][1];

      if (arg == "header")
        header = true;
      else
        std::cerr << "Invalid option '" << arg << "'" << std::endl;
    }
    else
      filenames.push_back(argv[i]);
  }

  if (filenames.empty())
    exit(1);

  //---

  CQTsvTest test;

  test.setHeader(header);

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

void
CQTsvTest::
load(const QString &filename)
{
  model_ = new CQTsvModel;

  if (isHeader())
    model_->setCommentHeader(true);

  model_->load(filename);

  table_->setModel(model_);
}

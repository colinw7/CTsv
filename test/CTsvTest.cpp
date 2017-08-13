#include <CTsv.h>
#include <CStrUtil.h>
#include <iostream>

int
main(int argc, char **argv)
{
  std::string filename;
  bool        quote = false;

  for (auto i = 1; i < argc; ++i) {
    if (argv[i][0] == '-') {
      std::string arg(&argv[i][1]);

      if (arg == "quote")
        quote = true;
      else
        std::cerr << "Unhandled option: " << arg << std::endl;
    }
    else
      filename = argv[i];
  }

  if (filename == "") {
    std::cerr << "CTsvTest <filename>" << std::endl;
    exit(1);
  }

  CTsv tsv(filename);

  if (! tsv.load()) {
    std::cerr << "Invalid file '" << filename << "'" << std::endl;
    exit(1);
  }

  for (const auto &fields : tsv.data()) {
    bool first = true;

    for (const auto &field : fields) {
      if (! first)
        std::cout << "|";

      if (quote)
        std::cout << "\"" << field << "\"";
      else
        std::cout << field;

      first = false;
    }

    std::cout << std::endl;
  }

  exit(0);
}

#include <iostream>

#include <QCoreApplication>
#include <QDebug>
#include <QStringList>

#include <header_file_cleaner.h>

#define DOCTEST_CONFIG_IMPLEMENT
#include <doctest.h>

int main(int argc, char* argv[]) {
  QCoreApplication app(argc, argv);

  //  doctest::Context context;
  //  int res = context.run();  // run

  //  if (context.shouldExit()) {
  //    return res;
  //  }

  QStringList arguments = app.arguments();
  arguments.pop_front();

  if (argc < 2) {
    return 2;
  }

  bool is_edit_mode = false;
  QString file_path = arguments.last();
  if (!file_path.endsWith(".h")) {
    return 3;
  }

  arguments.pop_back();

  for (auto argument : arguments) {
    if (argument == "-i") {
      is_edit_mode = true;
    }
  }

  int return_code =
      HeaderFileCleaner::FixHeaderGuardsInFile(file_path, is_edit_mode);

  if (return_code != 0) {
    std::cout << file_path.toLocal8Bit().data() << "\n";
    return return_code;
  }

  return 0;
}

#ifndef HEADER_GUARD_MAKER_H
#define HEADER_GUARD_MAKER_H

class QString;

class HeaderGuardMaker {
 public:
  static QString ReadHeaderGuardFromText(const QString& text);
  static QString ContructHeaderGuardForFileWithName(
      const QString& short_file_name);
};

#endif  // HEADER_GUARD_MAKER_H

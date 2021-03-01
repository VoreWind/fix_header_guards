#ifndef HEADER_GUARD_MAKER_H
#define HEADER_GUARD_MAKER_H

class QString;

class HeaderGuardMaker {
 public:
  static QString ReadHeaderGuardFromText(const QString& text) noexcept;
  static QString ContructHeaderGuardForFileWithName(
      const QString& short_file_name) noexcept;
};

#endif  // HEADER_GUARD_MAKER_H

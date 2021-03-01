#ifndef HEADER_GUARD_FIXER_H
#define HEADER_GUARD_FIXER_H

class QString;

class HeaderGuardFixer {
 public:
  static bool IsFileHeaderGuardValid(const QString& source_file_text,
                                     const QString& short_file_name);

  static QString FixHeaderGuardsInText(const QString& source_file_text,
                                       const QString& short_file_name);
};

#endif  // HEADER_GUARD_FIXER_H

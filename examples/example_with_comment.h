// This is a comment.
/* This is another comment.*/

#include <QByteArray>

#ifndef EXAMPLE_WITH_COMMENT_H
#define EXAMPLE_WITH_COMMENT_H

#include <QString>

class SomeClass {

public:
  static int Foo(int herp, bool derp);

private:
  static bool Bar(const QString &gloop);
};

#endif  // EXAMPLE_WITH_COMMENT_H


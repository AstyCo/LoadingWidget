#include <QString>
#include <QtTest>

class ClassTest : public QObject
{
    Q_OBJECT

public:
    ClassTest();

private Q_SLOTS:
    void testCase1();
};

ClassTest::ClassTest()
{
}

void ClassTest::testCase1()
{
    QVERIFY2(true, "Failure");
}

QTEST_APPLESS_MAIN(ClassTest)

#include "tst_classtest.moc"

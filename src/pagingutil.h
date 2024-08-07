#pragma once

#include <qobject.h>

class PagingUtil : public QObject {
    Q_OBJECT

public:
    explicit PagingUtil(QObject* parent = nullptr);
    virtual ~PagingUtil();

    PagingUtil& operator=(const PagingUtil& other);

    int getTotalSize() const;
    void setTotalSize(int size);

    int getDisplaySize() const;
    void setDisplaySize(int size);

    void numberSelected(int number);

    virtual void reCacheNumbers() = 0;

    bool isSelectedNumber(int number) const;

    QList<int> getCurCacheNumbers() const {
        return curCacheNumbers;
    }

    int getCurrentSelectedNumber() const {
        return curSelectNumber;
    }

Q_SIGNALS:
    void numberArraySizeChanged();
    void numbersChanged();
    void numberSelectChanged();

protected:
    //total data size
    int totalSize;
    //max number of pages to display
    int displaySize;
    //current selected number value
    int curSelectNumber;

    //current display numbers
    QList<int> curCacheNumbers;

private:
    void pre2ReCacheNumbers();

    friend class Pagination;
};

#include "pagingutil.h"

PagingUtil::PagingUtil(QObject* parent)
    : QObject(parent)
    , totalSize(10)
    , displaySize(2)
    , curSelectNumber(1)
{

}

PagingUtil::~PagingUtil() {
}

PagingUtil &PagingUtil::operator=(const PagingUtil &other) {
    this->totalSize = other.totalSize;
    this->displaySize = other.displaySize;
    this->curSelectNumber = other.curSelectNumber;
    return *this;
}

int PagingUtil::getTotalSize() const {
    return totalSize;
}

void PagingUtil::setTotalSize(int size) {
    totalSize = size;
    pre2ReCacheNumbers();
}

int PagingUtil::getDisplaySize() const {
    return displaySize;
}

void PagingUtil::setDisplaySize(int size) {
    Q_ASSERT(size > 0);
    displaySize = size;
    pre2ReCacheNumbers();
}


void PagingUtil::numberSelected(int number) {
    if (number < 1) {
        return;
    }
    if (number > getTotalSize()) {
        return;
    }

    curSelectNumber = number;
    pre2ReCacheNumbers();
    emit numberSelectChanged();
}

bool PagingUtil::isSelectedNumber(int number) const {
    return curSelectNumber == number;
}

void PagingUtil::pre2ReCacheNumbers() {
    int oldNumberSize = curCacheNumbers.size();

    reCacheNumbers();

    if (curCacheNumbers.size() != oldNumberSize) {
        emit numberArraySizeChanged();
    }

    emit numbersChanged();

    //check select number when total size changed
    auto totalSize = getTotalSize();
    if (curSelectNumber > totalSize) {
        curSelectNumber = totalSize;
        emit numberSelectChanged();
    }
}

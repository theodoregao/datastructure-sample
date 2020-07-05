#include "BobbleSort.h"

void BobbleSort::sortByPrice()
{
    sortInternal(lowPrice);
}

void BobbleSort::sortByPriceDescend()
{
    sortInternal(highPrice);
}

void BobbleSort::sortByIsbn()
{
    sortInternal(lowIsbn);
}

void BobbleSort::sortByIsbnDescend()
{
    sortInternal(highIsbn);
}

void BobbleSort::sortByDate()
{
    sortInternal(lowDate);
}

void BobbleSort::sortByDateDescend()
{
    sortInternal(highDate);
}

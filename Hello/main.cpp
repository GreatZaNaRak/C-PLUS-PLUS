#include <list>
#include <vector>
#include <iterator>
#include "stdio.h"
#include <iostream>

using namespace std;

void loop(list<int> store)
{
    for (auto i = store.begin() ; i != store.end() ; i++) {
        printf("%d ", *i);
    }
    printf("\n");
}


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);

    list<int> store;
    int n, pos, ball, run;
    scanf("%d%d%d", &n, &pos, &ball);
    while(n--) {
        scanf("%d", &run);
        store.push_back(run);
    }

    int j = pos;

    auto sum = store.begin();
    while(j--) sum++;
    store.insert(sum, ball);

    auto sht = store.begin();
    int k = pos;
    int tar = 0;
    while(k--) {sht++; tar++;}

    bool check = false;

    auto tmp = sht;
    auto ers = store.begin();

    if (tar == 0) {
        if (*tmp == *next(tmp, 1) && *tmp == *next(tmp, 2)) check = true;
    }
    else if (tar == 1) {
        if (*tmp == *prev(tmp, 1) && *tmp == *next(tmp, 1)) check = true;
        if (*tmp == *next(tmp, 1) && *tmp == *next(tmp, 2)) check = true;
    }
    else if (tar == store.size()) {
        if (*tmp == *prev(tmp, 1) && *tmp == *prev(tmp, 2)) check = true;
    }
    else if (tar == store.size() - 1) {
        if (*tmp == *prev(tmp, 1) && *tmp == *prev(tmp, 2)) check = true;
        if (*tmp == *prev(tmp, 1) && *tmp == *next(tmp, 1)) check = true;
    }
    else {
        if (*tmp == *prev(tmp, 1) && *tmp == *next(tmp, 1)) check = true;
        if (*tmp == *prev(tmp, 1) && *tmp == *prev(tmp, 2)) check = true;
        if (*tmp == *next(tmp, 1) && *tmp == *next(tmp, 2)) check = true;
    }


    if (check) {
        auto run = sht;
        run--;


        while (run != --store.begin() && *run == ball) {
            run--;
        }
        run++;

        while (run != store.end() && *run == ball) {
            ers = store.erase(run++);
        }
    }

    bool cnt = false;
    for (auto i = store.begin() ; i != --store.end() ; i++) {
        if (*i != *next(i, 1)) cnt = true;
    }

    if (!cnt) {
        printf("\n");
        return 0;
    }

    if (*ers != *prev(ers, 1)) {
        loop(store);
        return 0;
    }

    while (true) {

        bool check = false;
        int tarZ = *ers;
        auto tmp = ers;

        if (*tmp != *prev(tmp, 1)) break;

        if (ers == store.begin()) {
            if (*tmp == *next(tmp, 1) && *tmp == *next(tmp, 2)) check = true;
        }
        else if (ers == ++store.begin()) {
            if (*tmp == *prev(tmp, 1) && *tmp == *next(tmp, 1)) check = true;
            if (*tmp == *next(tmp, 1) && *tmp == *next(tmp, 2)) check = true;
        }
        else if (ers == --store.end()) {
            if (*tmp == *prev(tmp, 1) && *tmp == *prev(tmp, 2)) check = true;
        }
        else if (ers == ----store.end()) {
            if (*tmp == *prev(tmp, 1) && *tmp == *prev(tmp, 2)) check = true;
            if (*tmp == *prev(tmp, 1) && *tmp == *next(tmp, 1)) check = true;
        }
        else {
            if (*tmp == *prev(tmp, 1) && *tmp == *next(tmp, 1)) check = true;
            if (*tmp == *prev(tmp, 1) && *tmp == *prev(tmp, 2)) check = true;
            if (*tmp == *next(tmp, 1) && *tmp == *next(tmp, 2)) check = true;
        }

        if (!check) break;

        auto run = tmp;
        run--;

        while (run != --store.begin() && *run == tarZ) {
            //cout << *run << " ";
            run--;
        }
        run++;

        while (run != store.end() && *run == tarZ) {
            ers = store.erase(run++);
        }
    }

    loop(store);
}

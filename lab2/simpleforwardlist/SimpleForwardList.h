//
// Created by damian on 12.03.18.
//

#ifndef JIMP_EXERCISES_SIMPLEFORWARDLIST_H
#define JIMP_EXERCISES_SIMPLEFORWARDLIST_H

struct ForwardList
{
    int value = 0;
    ForwardList * next = nullptr;
};


ForwardList *CreateNode(int value);
void DestroyList(ForwardList *list);


#endif //JIMP_EXERCISES_SIMPLEFORWARDLIST_H

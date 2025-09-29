//
// Created by nematpour on 9/29/2025.
//

#ifndef TODOLIST_OBSERVER_H
#define TODOLIST_OBSERVER_H
#pragma once
class Observer {
public:
    virtual void onTaskChanged() = 0;
    virtual ~Observer() = default;
};

#endif //TODOLIST_OBSERVER_H

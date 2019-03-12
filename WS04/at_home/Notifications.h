//
//  Notifications.h
//  pro1
//
//  Created by Liu Wenxuan on 2019-02-08.
//  Copyright © 2019 Liu Wenxuan. All rights reserved.
//

#ifndef SICT_NOTIFICATIONS_H
#define SICT_NOTIFICATIONS_H
#include "Message.h"
namespace sict {
    class Notifications{
        const Message** mp;
        size_t max;
        size_t num;
    public:
        Notifications():mp{nullptr},max{0},num{0}{}
        Notifications(int mx);
        ~Notifications();
        Notifications(const Notifications&);
        Notifications(Notifications&&);
        Notifications& operator=(const Notifications&);
        Notifications& operator=(Notifications&&);
        Notifications& operator+=(const Message& msg);
        Notifications& operator-=(const Message& msg);
        void display(std::ostream& os)const;
        size_t size() const;
    };
    std::ostream& operator<<( std::ostream& os, const Notifications& noti);
}
#endif /* SICT_NOTIFICATIONS_H */


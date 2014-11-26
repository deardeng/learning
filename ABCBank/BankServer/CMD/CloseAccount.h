#ifndef _CLOSE_ACCOUNT_H_
#define _CLOSE_ACCOUNT_H

#include "Transaction.h"

namespace CMD{
    class CloseAccount : public Transaction{
        public:
            virtual void Execute(BankSession& session);
    };
}

#endif //_CLOSE_ACCOUNT_H_

#pragma once
#include <string>

template <class TResultType> class Result {
private:
  TResultType m_resultType;
  std::string m_errorMessage;
  bool m_success;

public:
  Result(TResultType resultType) {
    this->m_success = true;
    this->m_errorMessage = "";
    this->m_resultType = resultType;
  }

  Result(std::string error) {
    this->m_success = false;
    this->m_errorMessage = error;
  }

  bool isSuccess() { return this->m_success; }

  TResultType getResult() { return this->m_resultType; }

  std::string getErrorMessage() { return this->m_errorMessage; }
};

struct Account {
  std::string name;
};

Result<Account> save_account(std::string accountName) {
  // do stuff
  if (accountName.length() > 100) {
    return Result<Account>("Account Name Too Long");
  }
  if (accountName.length() == 0) {
    return Result<Account>("Account Name Cannot Be Empty");
  }
  if (accountName.length() < 10) {
    return Result<Account>("Account Name Too Short");
  }
  // save account
  Account account = Account();
  account.name = accountName;
  return Result<Account>(account);
}

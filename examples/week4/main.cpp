#include <iostream>
#include <vector>

struct Row {
private:
  int m_id;
  int m_accountNumber;
  float m_transactionAmount;

public:
  Row(int id, int accountNumber, float transactionAmount) {
    this->m_id = id;
    this->m_accountNumber = accountNumber;
    this->m_transactionAmount = transactionAmount;
  }
  int getId() { return this->m_id; }
  int getAccountNumber() { return this->m_accountNumber; }
  float getAmount() { return this->m_transactionAmount; }
};

class AbstractDatabase {
private:
  int m_identity = 0;

public:
  virtual std::vector<Row> *getRowsByAccountNumber(int accountNumber) = 0;
  virtual void addRow(Row row) = 0;
  int nextIdentity() { return ++m_identity; }
};

class InMemoryDatabase : AbstractDatabase {
private:
  int m_identity;
  std::vector<Row> *m_rows;

public:
  InMemoryDatabase() { m_rows = new std::vector<Row>(); }

  std::vector<Row> *getRowsByAccountNumber(int accountNumber) {
    std::vector<Row> *ret = new std::vector<Row>();
    for (auto r : (*this->m_rows)) {
      if (r.getAccountNumber() == accountNumber) {
        ret->push_back(r);
      }
    }
    return ret;
  }

  void addRow(Row row) { this->m_rows->push_back(row); }
};

class Bank {
private:
  AbstractDatabase *m_database;

public:
  Bank(AbstractDatabase *database) { this->m_database = database; }
  void depositMoney(int accountId, float amount) {
    if (amount <= 0.0) {
      std::cout << "Cannot Deposit Negative Ammount" << std::endl;
      return;
    }
    Row r = Row(m_database->nextIdentity(), accountId, amount);
    this->m_database->addRow(r);
  }

  float checkBalance(int accountId) {
    std::vector<Row> *rows =
        this->m_database->getRowsByAccountNumber(accountId);
    float total = 0.0;
    for (auto r : (*rows)) {
      total += r.getAmount();
    }
    return total;
  }

  void withdraw(int accountId, float amount) {
    if (amount >= 0.0) {
      std::cout << "Cannot Withdraw Positive Ammount" << std::endl;
      return;
    }
    Row r = Row(m_database->nextIdentity(), accountId, amount);
    this->m_database->addRow(r);
  }
};

int main() {}

#include <cstdio>
#include <unordered_map>
#include <stdexcept>

struct Logger {
    virtual ~Logger() = default;
    virtual void log_transfer (long from , long to, double ammount) = 0;
};

struct ConsoleLogger : Logger {
    explicit ConsoleLogger(const char *tag) : tag{tag} {}
    void log_transfer(long from, long to, double ammount) override {
        printf("[%s] %ld -> %ld: %f\n", tag, from, to, ammount);
    }
    private:
    const char *tag;
};

struct AccountDataBase {
    virtual ~AccountDataBase() = default;
    virtual double get_balanced(long id) const = 0;
    virtual void set_balance(long id, double ammount) = 0;
};

struct InMemoryAccountDatabase : AccountDataBase {
    double get_balanced(long id) const override {
        auto it = accounts.find(id);
        if (it != accounts.end()) return it->second;
        throw std::runtime_error("Account not found");
    }
    void set_balance(long id, double ammount) override {
        accounts[id] = ammount;
    }
    private:
        std::unordered_map<long, double> accounts;
};


struct Bank {
    Bank(Logger* logger, AccountDataBase* db) 
    : logger{logger}, db{db} {}
    void set_logger(Logger* new_logger) {
        logger = new_logger;
    }

    void make_transfer(long from, long to, double ammount) {
        if (db->get_balanced(from) < ammount) {
            throw std::runtime_error("Insufficient funds");
    }
        db->set_balance(from, db->get_balanced(from) - ammount);
        db->set_balance(to, db->get_balanced(to) + ammount);

        if (logger) {
            logger->log_transfer(from, to, ammount);
        }
    }
    private:
        Logger* logger{};
        AccountDataBase* db{};
};

int main() {
    ConsoleLogger console_logger("Console");
    InMemoryAccountDatabase db;

    db.set_balance(1000, 100.0);
    db.set_balance(2000, 50.0);

    Bank bank(&console_logger, &db);

    bank.make_transfer(1000, 2000, 10.0);
    bank.make_transfer(2000, 1000, 25.0);
    return 0;
}

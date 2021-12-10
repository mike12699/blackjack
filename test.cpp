#include "utils.h"
#include "main.cpp"

class PlayerTestsHarness : public AbstractTestHarness{
    private:
        Player p = Player();
    public:
        PlayerTestsHarness() {
            register_test_func("Player Test", [this]() -> void { assert_equal(21, p.getTotal());});
        }
};

class DealerTestHarness : public AbstractTestHarness{
    private:
        Dealer d = Dealer();
    public:
        DealerTestHarness() {
            register_test_func("Dealer Test", [this]() -> void {assert_equal(21, d.getTotal());});
        }
};

class GlobalTestManager : public TestManager{
    public:
        GlobalTestManager() { add_test("Player Tests", PlayerTestsHarness());}
        GlobalTestManager() { add_test("Dealer Tests", DealerTestHarness());}
};

int main() {
    GlobalTestManager tr = GlobalTestManager();
    tr.execute();
}

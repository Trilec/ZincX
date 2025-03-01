#include "graphics/ZGraphicsView.h"
#include "graphics/DOSGraphicsBackend.h"
#include <memory>
#include <iostream>

int main() {
    std::cout << "Starting ZincX Test\n";
    auto backend = std::make_unique<DOSGraphicsBackend>();
    ZGraphicsView view(std::move(backend));
    view.render(); // Outputs initialization message
    std::cout << "Test Complete\n";
    return 0;
}
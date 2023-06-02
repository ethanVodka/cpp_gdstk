#include <stdio.h>

#include "gdstk.h"

using namespace gdstk;

int main(int argc, char* argv[]) {
    Library lib = {};
    lib.init("library", 1e-6, 1e-9);

    Cell cell = {};
    cell.name = copy_string("FIRST", NULL);
    lib.cell_array.append(&cell);

    Polygon rect = rectangle(Vec2{ 0, 0 }, Vec2{ 2, 1 }, make_tag(0, 0));
    cell.polygon_array.append(&rect);

    lib.write_gds("../first.gds", 0, NULL);
    lib.write_oas("../first.oas", 0, 6, OASIS_CONFIG_DETECT_ALL);
    cell.write_svg("../first.svg", 10, 6, NULL, NULL, "#222222", 5, true, NULL);

    rect.clear();
    cell.clear();
    lib.clear();
    return 0;
}
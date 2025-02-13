#include "ctermui_screen.h"

void periodic(ctermui_screen_t *screen_p) {
  ctermui_screen_t screen = *screen_p;
  ctermui_layout_t root = screen->root;
  ctermui_component_t text_input = root->components[0];
  if (screen->loop_count == 0) {
    TextInput *t = (TextInput *)text_input->core_component;
    t->selected = 1;
  }
  ctermui_screen_refresh_layout(screen, root);
}

int main() {
  ctermui_screen_t screen = ctermui_screen_init();
  ctermui_layout_t root = ctermui_layout_new_root(
      CTERMUI_HORIZONTAL, screen->width, screen->height);
  ctermui_component_t text_input = ctermui_new_text_input(
      "text", CTERMUI_BLUE, CTERMUI_CYAN, 100, 100, screen->keyboard_events);
  ctermui_layout_add_component(root, text_input);
  ctermui_screen_set_layout_root(screen, root);
  ctermui_screen_loop_start(screen, periodic, 1000);
}

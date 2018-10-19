// Main function of the planar data processor (PDP) software reference model.

#include <stdbool.h>

bool PdpProcess() { return true; }

int main() {
  // call the pdp function
  bool ret = PdpProcess();

  if (!ret)
    return -1;

  return 0;
}

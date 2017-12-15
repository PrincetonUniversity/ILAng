import ila

def write(state):
  #f = open('assign.in','w')
  print state
  #f.write('x0 %d' % state['X0'])
  #f.close()

def sim(state_in):
  write(state_in)
  state_out = state_in
  state_out['X1'] = 0
  return state_out

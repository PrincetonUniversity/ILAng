import ila


def loadILAs():
    vILA = ila.Abstraction('vaes')
    vILA.importAll('vILA/all')
    vuILA = vILA.get_microabstraction('aes_compute')
    vuILA.importAll('vILA/allu')
    
    cILA = ila.Abstraction('caes')
    cILA.importAll('cILA/all')
    cuILA = cILA.get_microabstraction('aes_compute')
    cuILA.importAll('cILA/allu')

    return (vILA,vuILA,cILA,cuILA)
    
class EQCheck:
    def __init__(self,a1,ua1, a2,ua2):
        self.a1 = a1
        self.ua1 = ua1
        self.a2 = a2
        self.ua2 = ua2
    def BaseCase(self,bound1,bound2, decode1, decode2, conclusion1,conclusion2, CrossConclusion):
        u1 = self.a1.newUnroller(self.ua1,setInitCondition = True)
        u1.addAssumption(decode1)
        u1.unrollTo(bound1)
        for c in conclusion1:
            print 'Checking base assertion:', c
            u1.checkAssertion( c )

        u2 = self.a2.newUnroller(self.ua2,setInitCondition = True)
        u2.addAssumption(decode2)
        u2.unrollTo(bound2)
        for c in conclusion2:
            print 'Checking base assertion:', c
            u2.checkAssertion( c )

        for n1,n2 in CrossConclusion:
            print 'Checking left.%s = right.%s' % (n1,n2)
            if( ila.eqcheck( u1, u2 , n1 , n2) ):
                print 'It is valid.'

    def BMC(self,bound1,bound2, decode1, decode2, conclusion1,conclusion2, conclusionCross):
        u1 = self.a1.newUnroller(self.ua1,setInitCondition = True)
        u1.addAssumption(decode1)
        u1.unrollTo(bound1)
        for c in conclusion1:
            print 'Checking base assertion:', c
            u1.checkAssertion( c )

        u2 = self.a2.newUnroller(self.ua2,setInitCondition = True)
        u2.addAssumption(decode2)
        u2.unrollTo(bound2)
        for c in conclusion2:
            print 'Checking base assertion:', c
            u2.checkAssertion( c )

        for n1,n2 in conclusionCross:
            print 'Checking left.%s = right.%s' % (n1,n2)
            if( ila.eqcheck( u1, u2 , n1 , n2) ):
                print 'It is valid.'

    def InductiveStep(self,bound1,bound2, inv1,inv2,invCross):
        ## For abs 1
        u1 = self.a1.newUnroller(self.ua1,setInitCondition = False)

        print 'Checking invariants:'
        invStr = ' AND '.join(['$%d' % idx for idx in range(len(inv1))])
        for idx,inv in enumerate(inv1):
            print '$%d = %s' % (idx,inv)

        for inv in inv1:
            u1.addAssumption(inv)

        u1.unrollTo(bound1)
        u1.addAssumption( self.ua1.fetch_valid )
        for idx,inv in enumerate(inv1):
            print invStr + ' -> ' + '$%d' % (idx)
            u1.checkAssertion(inv)

        ## For abs 2
        print 'Checking invariants:'
        u2 = self.a2.newUnroller(self.ua2,setInitCondition = False)
        invStr = ' AND '.join(['$%d' % idx for idx in range(len(inv2))])
        for idx,inv in enumerate(inv2):
            print '$%d = %s' % (idx,inv)

        for inv in inv2:
            u2.addAssumption(inv)

        u2.unrollTo(bound2)
        u2.addAssumption( self.ua2.fetch_valid )
        for idx,inv in enumerate(inv2):
            print invStr + ' -> ' + '$%d' % (idx)
            if u2.checkAssertion(inv) == False:
                print 'Fail!'
                return False

        ## Cross 
        CrossAssumpt = []
        for n1,n2 in invCross:
            CrossAssumpt.append((1,n1,n2))
        for n1,n2 in invCross:
            if ila.eqcheck(u1,u2,n1,n2,assumption = CrossAssumpt) == False:
                print 'left.{n1} = right.{n2}  --/-->  left.{n1} = right.{n2}'.format (n1=n1,n2=n2)
                return False

    def Exit(self,bound1,bound2, a1,a2,c1,c2,CrossAssumpt, CrossConclusion):
        ## For abs 1
        u1 = self.a1.newUnroller(self.ua1,setInitCondition = False)

        print 'Assuming:'
        invStr = ' AND '.join(['$%d' % idx for idx in range(len(a1))] + ['$$'])
        for idx,inv in enumerate(a1):
            print '$%d = %s' % (idx,inv)

        for inv in a1:
            u1.addAssumption(inv)

        u1.unrollTo(bound1)
        u1.addAssumption( ~ self.ua1.fetch_valid )
        print 'And also: micro-prog ends $$: ', ~ self.ua1.fetch_valid

        for idx,cond in enumerate(c1):
            print invStr + ' -> ' + str(cond)
            u1.checkAssertion(cond)

        ## For abs 2
        u2 = self.a2.newUnroller(self.ua2,setInitCondition = False)
        print 'Assuming:'
        invStr = ' AND '.join(['$%d' % idx for idx in range(len(a2))] + ['$$'])
        for idx,inv in enumerate(a2):
            print '$%d = %s' % (idx,inv)

        for inv in a2:
            u2.addAssumption(inv)

        u2.unrollTo(bound2)
        u2.addAssumption( ~ self.ua2.fetch_valid )
        print 'And also: micro-prog ends $$: ', ~ self.ua2.fetch_valid

        for idx,cond in enumerate(c2):
            print invStr + ' -> ' + str(cond)
            u2.checkAssertion(cond)

        ## Cross 
        CrossAssumptList = []
        for n1,n2 in CrossAssumpt:
            CrossAssumptList.append((1,n1,n2))
        for n1,n2 in CrossConclusion:
            ila.enablelog("Unroller")
            ila.setloglevel(3,"info.txt")
            if ila.eqcheck(u1,u2,n1,n2,assumption = CrossAssumptList) == False:
                print 'left.{n1} = right.{n2}  --/-->  left.{n1} = right.{n2}'.format (n1=n1,n2=n2)
            else:
                print 'left.{n1} = right.{n2}  ==>>  left.{n1} = right.{n2}'.format (n1=n1,n2=n2)

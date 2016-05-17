#include "common.hpp"
#include "model_oc8051_class.hpp"

BIT_VEC model_oc8051::cppUpdateFun_P2()
{
	BIT_VEC cppVar_31641;
	BIT_VEC cppVar_31642 = ROM.rd(PC);
	bool cppVar_31644 = (cppVar_31642 == 210);
	if (cppVar_31644) {
	BIT_VEC cppVar_31645;
	BIT_VEC cppVar_31646;
	BIT_VEC cppVar_31648 = PC + 1;
	cppVar_31648 = (cppVar_31648 & cppMask_un_16_);
	BIT_VEC cppVar_31649 = ROM.rd(cppVar_31648);
	BIT_VEC cppVar_31650 = (cppVar_31649 >> 7) & cppMask_un_1_;
	bool cppVar_31652 = (cppVar_31650 == 1);
	if (cppVar_31652) {
	BIT_VEC cppVar_31653 = PC + 1;
	cppVar_31653 = (cppVar_31653 & cppMask_un_16_);
	BIT_VEC cppVar_31654 = ROM.rd(cppVar_31653);
	BIT_VEC cppVar_31655 = (cppVar_31654 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_31657 = (cppVar_31655 << 3) | 0;
	cppVar_31657 = (cppVar_31657 & cppMask_un_8_);
	cppVar_31646 = cppVar_31657;
	} else {
	BIT_VEC cppVar_31658 = PC + 1;
	cppVar_31658 = (cppVar_31658 & cppMask_un_16_);
	BIT_VEC cppVar_31659 = ROM.rd(cppVar_31658);
	BIT_VEC cppVar_31660 = (cppVar_31659 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_31661 = (cppVar_31660 & cppMask_un_5_);
	BIT_VEC cppVar_31663 = cppVar_31661 + 32;
	cppVar_31663 = (cppVar_31663 & cppMask_un_8_);
	cppVar_31646 = cppVar_31663;
	}
	bool cppVar_31665 = (cppVar_31646 == 160);
	if (cppVar_31665) {
	BIT_VEC cppVar_31667 = PC + 1;
	cppVar_31667 = (cppVar_31667 & cppMask_un_16_);
	BIT_VEC cppVar_31668 = ROM.rd(cppVar_31667);
	BIT_VEC cppVar_31669 = (cppVar_31668 >> 0) & cppMask_un_3_;
	BIT_VEC cppVar_31670 = (cppVar_31669 & cppMask_un_3_);
	BIT_VEC cppVar_31671 = 1 << static_cast<unsigned>(cppVar_31670);
	cppVar_31671 = (cppVar_31671 & cppMask_un_8_);
	BIT_VEC cppVar_31672 = ~cppVar_31671;
	BIT_VEC cppVar_31673;
	BIT_VEC cppVar_31674;
	BIT_VEC cppVar_31675 = PC + 1;
	cppVar_31675 = (cppVar_31675 & cppMask_un_16_);
	BIT_VEC cppVar_31676 = ROM.rd(cppVar_31675);
	BIT_VEC cppVar_31677 = (cppVar_31676 >> 7) & cppMask_un_1_;
	bool cppVar_31678 = (cppVar_31677 == 1);
	if (cppVar_31678) {
	BIT_VEC cppVar_31679 = PC + 1;
	cppVar_31679 = (cppVar_31679 & cppMask_un_16_);
	BIT_VEC cppVar_31680 = ROM.rd(cppVar_31679);
	BIT_VEC cppVar_31681 = (cppVar_31680 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_31682 = (cppVar_31681 << 3) | 0;
	cppVar_31682 = (cppVar_31682 & cppMask_un_8_);
	cppVar_31674 = cppVar_31682;
	} else {
	BIT_VEC cppVar_31683 = PC + 1;
	cppVar_31683 = (cppVar_31683 & cppMask_un_16_);
	BIT_VEC cppVar_31684 = ROM.rd(cppVar_31683);
	BIT_VEC cppVar_31685 = (cppVar_31684 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_31686 = (cppVar_31685 & cppMask_un_5_);
	BIT_VEC cppVar_31687 = cppVar_31686 + 32;
	cppVar_31687 = (cppVar_31687 & cppMask_un_8_);
	cppVar_31674 = cppVar_31687;
	}
	BIT_VEC cppVar_31688 = (cppVar_31674 >> 7) & cppMask_un_1_;
	bool cppVar_31690 = (cppVar_31688 == 0);
	if (cppVar_31690) {
	BIT_VEC cppVar_31691;
	BIT_VEC cppVar_31692 = PC + 1;
	cppVar_31692 = (cppVar_31692 & cppMask_un_16_);
	BIT_VEC cppVar_31693 = ROM.rd(cppVar_31692);
	BIT_VEC cppVar_31694 = (cppVar_31693 >> 7) & cppMask_un_1_;
	bool cppVar_31695 = (cppVar_31694 == 1);
	if (cppVar_31695) {
	BIT_VEC cppVar_31696 = PC + 1;
	cppVar_31696 = (cppVar_31696 & cppMask_un_16_);
	BIT_VEC cppVar_31697 = ROM.rd(cppVar_31696);
	BIT_VEC cppVar_31698 = (cppVar_31697 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_31699 = (cppVar_31698 << 3) | 0;
	cppVar_31699 = (cppVar_31699 & cppMask_un_8_);
	cppVar_31691 = cppVar_31699;
	} else {
	BIT_VEC cppVar_31700 = PC + 1;
	cppVar_31700 = (cppVar_31700 & cppMask_un_16_);
	BIT_VEC cppVar_31701 = ROM.rd(cppVar_31700);
	BIT_VEC cppVar_31702 = (cppVar_31701 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_31703 = (cppVar_31702 & cppMask_un_5_);
	BIT_VEC cppVar_31704 = cppVar_31703 + 32;
	cppVar_31704 = (cppVar_31704 & cppMask_un_8_);
	cppVar_31691 = cppVar_31704;
	}
	BIT_VEC cppVar_31705 = IRAM.rd(cppVar_31691);
	cppVar_31673 = cppVar_31705;
	} else {
	BIT_VEC cppVar_31706;
	BIT_VEC cppVar_31707;
	BIT_VEC cppVar_31708 = PC + 1;
	cppVar_31708 = (cppVar_31708 & cppMask_un_16_);
	BIT_VEC cppVar_31709 = ROM.rd(cppVar_31708);
	BIT_VEC cppVar_31710 = (cppVar_31709 >> 7) & cppMask_un_1_;
	bool cppVar_31711 = (cppVar_31710 == 1);
	if (cppVar_31711) {
	BIT_VEC cppVar_31712 = PC + 1;
	cppVar_31712 = (cppVar_31712 & cppMask_un_16_);
	BIT_VEC cppVar_31713 = ROM.rd(cppVar_31712);
	BIT_VEC cppVar_31714 = (cppVar_31713 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_31715 = (cppVar_31714 << 3) | 0;
	cppVar_31715 = (cppVar_31715 & cppMask_un_8_);
	cppVar_31707 = cppVar_31715;
	} else {
	BIT_VEC cppVar_31716 = PC + 1;
	cppVar_31716 = (cppVar_31716 & cppMask_un_16_);
	BIT_VEC cppVar_31717 = ROM.rd(cppVar_31716);
	BIT_VEC cppVar_31718 = (cppVar_31717 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_31719 = (cppVar_31718 & cppMask_un_5_);
	BIT_VEC cppVar_31720 = cppVar_31719 + 32;
	cppVar_31720 = (cppVar_31720 & cppMask_un_8_);
	cppVar_31707 = cppVar_31720;
	}
	bool cppVar_31722 = (cppVar_31707 == 128);
	if (cppVar_31722) {
	cppVar_31706 = P0;
	} else {
	BIT_VEC cppVar_31723;
	BIT_VEC cppVar_31724;
	BIT_VEC cppVar_31725 = PC + 1;
	cppVar_31725 = (cppVar_31725 & cppMask_un_16_);
	BIT_VEC cppVar_31726 = ROM.rd(cppVar_31725);
	BIT_VEC cppVar_31727 = (cppVar_31726 >> 7) & cppMask_un_1_;
	bool cppVar_31728 = (cppVar_31727 == 1);
	if (cppVar_31728) {
	BIT_VEC cppVar_31729 = PC + 1;
	cppVar_31729 = (cppVar_31729 & cppMask_un_16_);
	BIT_VEC cppVar_31730 = ROM.rd(cppVar_31729);
	BIT_VEC cppVar_31731 = (cppVar_31730 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_31732 = (cppVar_31731 << 3) | 0;
	cppVar_31732 = (cppVar_31732 & cppMask_un_8_);
	cppVar_31724 = cppVar_31732;
	} else {
	BIT_VEC cppVar_31733 = PC + 1;
	cppVar_31733 = (cppVar_31733 & cppMask_un_16_);
	BIT_VEC cppVar_31734 = ROM.rd(cppVar_31733);
	BIT_VEC cppVar_31735 = (cppVar_31734 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_31736 = (cppVar_31735 & cppMask_un_5_);
	BIT_VEC cppVar_31737 = cppVar_31736 + 32;
	cppVar_31737 = (cppVar_31737 & cppMask_un_8_);
	cppVar_31724 = cppVar_31737;
	}
	bool cppVar_31739 = (cppVar_31724 == 129);
	if (cppVar_31739) {
	cppVar_31723 = SP;
	} else {
	BIT_VEC cppVar_31740;
	BIT_VEC cppVar_31741;
	BIT_VEC cppVar_31742 = PC + 1;
	cppVar_31742 = (cppVar_31742 & cppMask_un_16_);
	BIT_VEC cppVar_31743 = ROM.rd(cppVar_31742);
	BIT_VEC cppVar_31744 = (cppVar_31743 >> 7) & cppMask_un_1_;
	bool cppVar_31745 = (cppVar_31744 == 1);
	if (cppVar_31745) {
	BIT_VEC cppVar_31746 = PC + 1;
	cppVar_31746 = (cppVar_31746 & cppMask_un_16_);
	BIT_VEC cppVar_31747 = ROM.rd(cppVar_31746);
	BIT_VEC cppVar_31748 = (cppVar_31747 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_31749 = (cppVar_31748 << 3) | 0;
	cppVar_31749 = (cppVar_31749 & cppMask_un_8_);
	cppVar_31741 = cppVar_31749;
	} else {
	BIT_VEC cppVar_31750 = PC + 1;
	cppVar_31750 = (cppVar_31750 & cppMask_un_16_);
	BIT_VEC cppVar_31751 = ROM.rd(cppVar_31750);
	BIT_VEC cppVar_31752 = (cppVar_31751 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_31753 = (cppVar_31752 & cppMask_un_5_);
	BIT_VEC cppVar_31754 = cppVar_31753 + 32;
	cppVar_31754 = (cppVar_31754 & cppMask_un_8_);
	cppVar_31741 = cppVar_31754;
	}
	bool cppVar_31756 = (cppVar_31741 == 130);
	if (cppVar_31756) {
	cppVar_31740 = DPL;
	} else {
	BIT_VEC cppVar_31757;
	BIT_VEC cppVar_31758;
	BIT_VEC cppVar_31759 = PC + 1;
	cppVar_31759 = (cppVar_31759 & cppMask_un_16_);
	BIT_VEC cppVar_31760 = ROM.rd(cppVar_31759);
	BIT_VEC cppVar_31761 = (cppVar_31760 >> 7) & cppMask_un_1_;
	bool cppVar_31762 = (cppVar_31761 == 1);
	if (cppVar_31762) {
	BIT_VEC cppVar_31763 = PC + 1;
	cppVar_31763 = (cppVar_31763 & cppMask_un_16_);
	BIT_VEC cppVar_31764 = ROM.rd(cppVar_31763);
	BIT_VEC cppVar_31765 = (cppVar_31764 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_31766 = (cppVar_31765 << 3) | 0;
	cppVar_31766 = (cppVar_31766 & cppMask_un_8_);
	cppVar_31758 = cppVar_31766;
	} else {
	BIT_VEC cppVar_31767 = PC + 1;
	cppVar_31767 = (cppVar_31767 & cppMask_un_16_);
	BIT_VEC cppVar_31768 = ROM.rd(cppVar_31767);
	BIT_VEC cppVar_31769 = (cppVar_31768 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_31770 = (cppVar_31769 & cppMask_un_5_);
	BIT_VEC cppVar_31771 = cppVar_31770 + 32;
	cppVar_31771 = (cppVar_31771 & cppMask_un_8_);
	cppVar_31758 = cppVar_31771;
	}
	bool cppVar_31773 = (cppVar_31758 == 131);
	if (cppVar_31773) {
	cppVar_31757 = DPH;
	} else {
	BIT_VEC cppVar_31774;
	BIT_VEC cppVar_31775;
	BIT_VEC cppVar_31776 = PC + 1;
	cppVar_31776 = (cppVar_31776 & cppMask_un_16_);
	BIT_VEC cppVar_31777 = ROM.rd(cppVar_31776);
	BIT_VEC cppVar_31778 = (cppVar_31777 >> 7) & cppMask_un_1_;
	bool cppVar_31779 = (cppVar_31778 == 1);
	if (cppVar_31779) {
	BIT_VEC cppVar_31780 = PC + 1;
	cppVar_31780 = (cppVar_31780 & cppMask_un_16_);
	BIT_VEC cppVar_31781 = ROM.rd(cppVar_31780);
	BIT_VEC cppVar_31782 = (cppVar_31781 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_31783 = (cppVar_31782 << 3) | 0;
	cppVar_31783 = (cppVar_31783 & cppMask_un_8_);
	cppVar_31775 = cppVar_31783;
	} else {
	BIT_VEC cppVar_31784 = PC + 1;
	cppVar_31784 = (cppVar_31784 & cppMask_un_16_);
	BIT_VEC cppVar_31785 = ROM.rd(cppVar_31784);
	BIT_VEC cppVar_31786 = (cppVar_31785 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_31787 = (cppVar_31786 & cppMask_un_5_);
	BIT_VEC cppVar_31788 = cppVar_31787 + 32;
	cppVar_31788 = (cppVar_31788 & cppMask_un_8_);
	cppVar_31775 = cppVar_31788;
	}
	bool cppVar_31790 = (cppVar_31775 == 135);
	if (cppVar_31790) {
	cppVar_31774 = PCON;
	} else {
	BIT_VEC cppVar_31791;
	BIT_VEC cppVar_31792;
	BIT_VEC cppVar_31793 = PC + 1;
	cppVar_31793 = (cppVar_31793 & cppMask_un_16_);
	BIT_VEC cppVar_31794 = ROM.rd(cppVar_31793);
	BIT_VEC cppVar_31795 = (cppVar_31794 >> 7) & cppMask_un_1_;
	bool cppVar_31796 = (cppVar_31795 == 1);
	if (cppVar_31796) {
	BIT_VEC cppVar_31797 = PC + 1;
	cppVar_31797 = (cppVar_31797 & cppMask_un_16_);
	BIT_VEC cppVar_31798 = ROM.rd(cppVar_31797);
	BIT_VEC cppVar_31799 = (cppVar_31798 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_31800 = (cppVar_31799 << 3) | 0;
	cppVar_31800 = (cppVar_31800 & cppMask_un_8_);
	cppVar_31792 = cppVar_31800;
	} else {
	BIT_VEC cppVar_31801 = PC + 1;
	cppVar_31801 = (cppVar_31801 & cppMask_un_16_);
	BIT_VEC cppVar_31802 = ROM.rd(cppVar_31801);
	BIT_VEC cppVar_31803 = (cppVar_31802 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_31804 = (cppVar_31803 & cppMask_un_5_);
	BIT_VEC cppVar_31805 = cppVar_31804 + 32;
	cppVar_31805 = (cppVar_31805 & cppMask_un_8_);
	cppVar_31792 = cppVar_31805;
	}
	bool cppVar_31807 = (cppVar_31792 == 136);
	if (cppVar_31807) {
	cppVar_31791 = TCON;
	} else {
	BIT_VEC cppVar_31808;
	BIT_VEC cppVar_31809;
	BIT_VEC cppVar_31810 = PC + 1;
	cppVar_31810 = (cppVar_31810 & cppMask_un_16_);
	BIT_VEC cppVar_31811 = ROM.rd(cppVar_31810);
	BIT_VEC cppVar_31812 = (cppVar_31811 >> 7) & cppMask_un_1_;
	bool cppVar_31813 = (cppVar_31812 == 1);
	if (cppVar_31813) {
	BIT_VEC cppVar_31814 = PC + 1;
	cppVar_31814 = (cppVar_31814 & cppMask_un_16_);
	BIT_VEC cppVar_31815 = ROM.rd(cppVar_31814);
	BIT_VEC cppVar_31816 = (cppVar_31815 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_31817 = (cppVar_31816 << 3) | 0;
	cppVar_31817 = (cppVar_31817 & cppMask_un_8_);
	cppVar_31809 = cppVar_31817;
	} else {
	BIT_VEC cppVar_31818 = PC + 1;
	cppVar_31818 = (cppVar_31818 & cppMask_un_16_);
	BIT_VEC cppVar_31819 = ROM.rd(cppVar_31818);
	BIT_VEC cppVar_31820 = (cppVar_31819 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_31821 = (cppVar_31820 & cppMask_un_5_);
	BIT_VEC cppVar_31822 = cppVar_31821 + 32;
	cppVar_31822 = (cppVar_31822 & cppMask_un_8_);
	cppVar_31809 = cppVar_31822;
	}
	bool cppVar_31824 = (cppVar_31809 == 137);
	if (cppVar_31824) {
	cppVar_31808 = TMOD;
	} else {
	BIT_VEC cppVar_31825;
	BIT_VEC cppVar_31826;
	BIT_VEC cppVar_31827 = PC + 1;
	cppVar_31827 = (cppVar_31827 & cppMask_un_16_);
	BIT_VEC cppVar_31828 = ROM.rd(cppVar_31827);
	BIT_VEC cppVar_31829 = (cppVar_31828 >> 7) & cppMask_un_1_;
	bool cppVar_31830 = (cppVar_31829 == 1);
	if (cppVar_31830) {
	BIT_VEC cppVar_31831 = PC + 1;
	cppVar_31831 = (cppVar_31831 & cppMask_un_16_);
	BIT_VEC cppVar_31832 = ROM.rd(cppVar_31831);
	BIT_VEC cppVar_31833 = (cppVar_31832 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_31834 = (cppVar_31833 << 3) | 0;
	cppVar_31834 = (cppVar_31834 & cppMask_un_8_);
	cppVar_31826 = cppVar_31834;
	} else {
	BIT_VEC cppVar_31835 = PC + 1;
	cppVar_31835 = (cppVar_31835 & cppMask_un_16_);
	BIT_VEC cppVar_31836 = ROM.rd(cppVar_31835);
	BIT_VEC cppVar_31837 = (cppVar_31836 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_31838 = (cppVar_31837 & cppMask_un_5_);
	BIT_VEC cppVar_31839 = cppVar_31838 + 32;
	cppVar_31839 = (cppVar_31839 & cppMask_un_8_);
	cppVar_31826 = cppVar_31839;
	}
	bool cppVar_31841 = (cppVar_31826 == 138);
	if (cppVar_31841) {
	cppVar_31825 = TL0;
	} else {
	BIT_VEC cppVar_31842;
	BIT_VEC cppVar_31843;
	BIT_VEC cppVar_31844 = PC + 1;
	cppVar_31844 = (cppVar_31844 & cppMask_un_16_);
	BIT_VEC cppVar_31845 = ROM.rd(cppVar_31844);
	BIT_VEC cppVar_31846 = (cppVar_31845 >> 7) & cppMask_un_1_;
	bool cppVar_31847 = (cppVar_31846 == 1);
	if (cppVar_31847) {
	BIT_VEC cppVar_31848 = PC + 1;
	cppVar_31848 = (cppVar_31848 & cppMask_un_16_);
	BIT_VEC cppVar_31849 = ROM.rd(cppVar_31848);
	BIT_VEC cppVar_31850 = (cppVar_31849 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_31851 = (cppVar_31850 << 3) | 0;
	cppVar_31851 = (cppVar_31851 & cppMask_un_8_);
	cppVar_31843 = cppVar_31851;
	} else {
	BIT_VEC cppVar_31852 = PC + 1;
	cppVar_31852 = (cppVar_31852 & cppMask_un_16_);
	BIT_VEC cppVar_31853 = ROM.rd(cppVar_31852);
	BIT_VEC cppVar_31854 = (cppVar_31853 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_31855 = (cppVar_31854 & cppMask_un_5_);
	BIT_VEC cppVar_31856 = cppVar_31855 + 32;
	cppVar_31856 = (cppVar_31856 & cppMask_un_8_);
	cppVar_31843 = cppVar_31856;
	}
	bool cppVar_31858 = (cppVar_31843 == 140);
	if (cppVar_31858) {
	cppVar_31842 = TH0;
	} else {
	BIT_VEC cppVar_31859;
	BIT_VEC cppVar_31860;
	BIT_VEC cppVar_31861 = PC + 1;
	cppVar_31861 = (cppVar_31861 & cppMask_un_16_);
	BIT_VEC cppVar_31862 = ROM.rd(cppVar_31861);
	BIT_VEC cppVar_31863 = (cppVar_31862 >> 7) & cppMask_un_1_;
	bool cppVar_31864 = (cppVar_31863 == 1);
	if (cppVar_31864) {
	BIT_VEC cppVar_31865 = PC + 1;
	cppVar_31865 = (cppVar_31865 & cppMask_un_16_);
	BIT_VEC cppVar_31866 = ROM.rd(cppVar_31865);
	BIT_VEC cppVar_31867 = (cppVar_31866 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_31868 = (cppVar_31867 << 3) | 0;
	cppVar_31868 = (cppVar_31868 & cppMask_un_8_);
	cppVar_31860 = cppVar_31868;
	} else {
	BIT_VEC cppVar_31869 = PC + 1;
	cppVar_31869 = (cppVar_31869 & cppMask_un_16_);
	BIT_VEC cppVar_31870 = ROM.rd(cppVar_31869);
	BIT_VEC cppVar_31871 = (cppVar_31870 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_31872 = (cppVar_31871 & cppMask_un_5_);
	BIT_VEC cppVar_31873 = cppVar_31872 + 32;
	cppVar_31873 = (cppVar_31873 & cppMask_un_8_);
	cppVar_31860 = cppVar_31873;
	}
	bool cppVar_31875 = (cppVar_31860 == 139);
	if (cppVar_31875) {
	cppVar_31859 = TL1;
	} else {
	BIT_VEC cppVar_31876;
	BIT_VEC cppVar_31877;
	BIT_VEC cppVar_31878 = PC + 1;
	cppVar_31878 = (cppVar_31878 & cppMask_un_16_);
	BIT_VEC cppVar_31879 = ROM.rd(cppVar_31878);
	BIT_VEC cppVar_31880 = (cppVar_31879 >> 7) & cppMask_un_1_;
	bool cppVar_31881 = (cppVar_31880 == 1);
	if (cppVar_31881) {
	BIT_VEC cppVar_31882 = PC + 1;
	cppVar_31882 = (cppVar_31882 & cppMask_un_16_);
	BIT_VEC cppVar_31883 = ROM.rd(cppVar_31882);
	BIT_VEC cppVar_31884 = (cppVar_31883 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_31885 = (cppVar_31884 << 3) | 0;
	cppVar_31885 = (cppVar_31885 & cppMask_un_8_);
	cppVar_31877 = cppVar_31885;
	} else {
	BIT_VEC cppVar_31886 = PC + 1;
	cppVar_31886 = (cppVar_31886 & cppMask_un_16_);
	BIT_VEC cppVar_31887 = ROM.rd(cppVar_31886);
	BIT_VEC cppVar_31888 = (cppVar_31887 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_31889 = (cppVar_31888 & cppMask_un_5_);
	BIT_VEC cppVar_31890 = cppVar_31889 + 32;
	cppVar_31890 = (cppVar_31890 & cppMask_un_8_);
	cppVar_31877 = cppVar_31890;
	}
	bool cppVar_31892 = (cppVar_31877 == 141);
	if (cppVar_31892) {
	cppVar_31876 = TH1;
	} else {
	BIT_VEC cppVar_31893;
	BIT_VEC cppVar_31894;
	BIT_VEC cppVar_31895 = PC + 1;
	cppVar_31895 = (cppVar_31895 & cppMask_un_16_);
	BIT_VEC cppVar_31896 = ROM.rd(cppVar_31895);
	BIT_VEC cppVar_31897 = (cppVar_31896 >> 7) & cppMask_un_1_;
	bool cppVar_31898 = (cppVar_31897 == 1);
	if (cppVar_31898) {
	BIT_VEC cppVar_31899 = PC + 1;
	cppVar_31899 = (cppVar_31899 & cppMask_un_16_);
	BIT_VEC cppVar_31900 = ROM.rd(cppVar_31899);
	BIT_VEC cppVar_31901 = (cppVar_31900 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_31902 = (cppVar_31901 << 3) | 0;
	cppVar_31902 = (cppVar_31902 & cppMask_un_8_);
	cppVar_31894 = cppVar_31902;
	} else {
	BIT_VEC cppVar_31903 = PC + 1;
	cppVar_31903 = (cppVar_31903 & cppMask_un_16_);
	BIT_VEC cppVar_31904 = ROM.rd(cppVar_31903);
	BIT_VEC cppVar_31905 = (cppVar_31904 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_31906 = (cppVar_31905 & cppMask_un_5_);
	BIT_VEC cppVar_31907 = cppVar_31906 + 32;
	cppVar_31907 = (cppVar_31907 & cppMask_un_8_);
	cppVar_31894 = cppVar_31907;
	}
	bool cppVar_31909 = (cppVar_31894 == 144);
	if (cppVar_31909) {
	cppVar_31893 = P1;
	} else {
	BIT_VEC cppVar_31910;
	BIT_VEC cppVar_31911;
	BIT_VEC cppVar_31912 = PC + 1;
	cppVar_31912 = (cppVar_31912 & cppMask_un_16_);
	BIT_VEC cppVar_31913 = ROM.rd(cppVar_31912);
	BIT_VEC cppVar_31914 = (cppVar_31913 >> 7) & cppMask_un_1_;
	bool cppVar_31915 = (cppVar_31914 == 1);
	if (cppVar_31915) {
	BIT_VEC cppVar_31916 = PC + 1;
	cppVar_31916 = (cppVar_31916 & cppMask_un_16_);
	BIT_VEC cppVar_31917 = ROM.rd(cppVar_31916);
	BIT_VEC cppVar_31918 = (cppVar_31917 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_31919 = (cppVar_31918 << 3) | 0;
	cppVar_31919 = (cppVar_31919 & cppMask_un_8_);
	cppVar_31911 = cppVar_31919;
	} else {
	BIT_VEC cppVar_31920 = PC + 1;
	cppVar_31920 = (cppVar_31920 & cppMask_un_16_);
	BIT_VEC cppVar_31921 = ROM.rd(cppVar_31920);
	BIT_VEC cppVar_31922 = (cppVar_31921 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_31923 = (cppVar_31922 & cppMask_un_5_);
	BIT_VEC cppVar_31924 = cppVar_31923 + 32;
	cppVar_31924 = (cppVar_31924 & cppMask_un_8_);
	cppVar_31911 = cppVar_31924;
	}
	bool cppVar_31926 = (cppVar_31911 == 152);
	if (cppVar_31926) {
	cppVar_31910 = SCON;
	} else {
	BIT_VEC cppVar_31927;
	BIT_VEC cppVar_31928;
	BIT_VEC cppVar_31929 = PC + 1;
	cppVar_31929 = (cppVar_31929 & cppMask_un_16_);
	BIT_VEC cppVar_31930 = ROM.rd(cppVar_31929);
	BIT_VEC cppVar_31931 = (cppVar_31930 >> 7) & cppMask_un_1_;
	bool cppVar_31932 = (cppVar_31931 == 1);
	if (cppVar_31932) {
	BIT_VEC cppVar_31933 = PC + 1;
	cppVar_31933 = (cppVar_31933 & cppMask_un_16_);
	BIT_VEC cppVar_31934 = ROM.rd(cppVar_31933);
	BIT_VEC cppVar_31935 = (cppVar_31934 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_31936 = (cppVar_31935 << 3) | 0;
	cppVar_31936 = (cppVar_31936 & cppMask_un_8_);
	cppVar_31928 = cppVar_31936;
	} else {
	BIT_VEC cppVar_31937 = PC + 1;
	cppVar_31937 = (cppVar_31937 & cppMask_un_16_);
	BIT_VEC cppVar_31938 = ROM.rd(cppVar_31937);
	BIT_VEC cppVar_31939 = (cppVar_31938 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_31940 = (cppVar_31939 & cppMask_un_5_);
	BIT_VEC cppVar_31941 = cppVar_31940 + 32;
	cppVar_31941 = (cppVar_31941 & cppMask_un_8_);
	cppVar_31928 = cppVar_31941;
	}
	bool cppVar_31943 = (cppVar_31928 == 153);
	if (cppVar_31943) {
	cppVar_31927 = SBUF;
	} else {
	BIT_VEC cppVar_31944;
	BIT_VEC cppVar_31945;
	BIT_VEC cppVar_31946 = PC + 1;
	cppVar_31946 = (cppVar_31946 & cppMask_un_16_);
	BIT_VEC cppVar_31947 = ROM.rd(cppVar_31946);
	BIT_VEC cppVar_31948 = (cppVar_31947 >> 7) & cppMask_un_1_;
	bool cppVar_31949 = (cppVar_31948 == 1);
	if (cppVar_31949) {
	BIT_VEC cppVar_31950 = PC + 1;
	cppVar_31950 = (cppVar_31950 & cppMask_un_16_);
	BIT_VEC cppVar_31951 = ROM.rd(cppVar_31950);
	BIT_VEC cppVar_31952 = (cppVar_31951 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_31953 = (cppVar_31952 << 3) | 0;
	cppVar_31953 = (cppVar_31953 & cppMask_un_8_);
	cppVar_31945 = cppVar_31953;
	} else {
	BIT_VEC cppVar_31954 = PC + 1;
	cppVar_31954 = (cppVar_31954 & cppMask_un_16_);
	BIT_VEC cppVar_31955 = ROM.rd(cppVar_31954);
	BIT_VEC cppVar_31956 = (cppVar_31955 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_31957 = (cppVar_31956 & cppMask_un_5_);
	BIT_VEC cppVar_31958 = cppVar_31957 + 32;
	cppVar_31958 = (cppVar_31958 & cppMask_un_8_);
	cppVar_31945 = cppVar_31958;
	}
	bool cppVar_31960 = (cppVar_31945 == 160);
	if (cppVar_31960) {
	cppVar_31944 = P2;
	} else {
	BIT_VEC cppVar_31961;
	BIT_VEC cppVar_31962;
	BIT_VEC cppVar_31963 = PC + 1;
	cppVar_31963 = (cppVar_31963 & cppMask_un_16_);
	BIT_VEC cppVar_31964 = ROM.rd(cppVar_31963);
	BIT_VEC cppVar_31965 = (cppVar_31964 >> 7) & cppMask_un_1_;
	bool cppVar_31966 = (cppVar_31965 == 1);
	if (cppVar_31966) {
	BIT_VEC cppVar_31967 = PC + 1;
	cppVar_31967 = (cppVar_31967 & cppMask_un_16_);
	BIT_VEC cppVar_31968 = ROM.rd(cppVar_31967);
	BIT_VEC cppVar_31969 = (cppVar_31968 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_31970 = (cppVar_31969 << 3) | 0;
	cppVar_31970 = (cppVar_31970 & cppMask_un_8_);
	cppVar_31962 = cppVar_31970;
	} else {
	BIT_VEC cppVar_31971 = PC + 1;
	cppVar_31971 = (cppVar_31971 & cppMask_un_16_);
	BIT_VEC cppVar_31972 = ROM.rd(cppVar_31971);
	BIT_VEC cppVar_31973 = (cppVar_31972 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_31974 = (cppVar_31973 & cppMask_un_5_);
	BIT_VEC cppVar_31975 = cppVar_31974 + 32;
	cppVar_31975 = (cppVar_31975 & cppMask_un_8_);
	cppVar_31962 = cppVar_31975;
	}
	bool cppVar_31977 = (cppVar_31962 == 168);
	if (cppVar_31977) {
	cppVar_31961 = IE;
	} else {
	BIT_VEC cppVar_31978;
	BIT_VEC cppVar_31979;
	BIT_VEC cppVar_31980 = PC + 1;
	cppVar_31980 = (cppVar_31980 & cppMask_un_16_);
	BIT_VEC cppVar_31981 = ROM.rd(cppVar_31980);
	BIT_VEC cppVar_31982 = (cppVar_31981 >> 7) & cppMask_un_1_;
	bool cppVar_31983 = (cppVar_31982 == 1);
	if (cppVar_31983) {
	BIT_VEC cppVar_31984 = PC + 1;
	cppVar_31984 = (cppVar_31984 & cppMask_un_16_);
	BIT_VEC cppVar_31985 = ROM.rd(cppVar_31984);
	BIT_VEC cppVar_31986 = (cppVar_31985 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_31987 = (cppVar_31986 << 3) | 0;
	cppVar_31987 = (cppVar_31987 & cppMask_un_8_);
	cppVar_31979 = cppVar_31987;
	} else {
	BIT_VEC cppVar_31988 = PC + 1;
	cppVar_31988 = (cppVar_31988 & cppMask_un_16_);
	BIT_VEC cppVar_31989 = ROM.rd(cppVar_31988);
	BIT_VEC cppVar_31990 = (cppVar_31989 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_31991 = (cppVar_31990 & cppMask_un_5_);
	BIT_VEC cppVar_31992 = cppVar_31991 + 32;
	cppVar_31992 = (cppVar_31992 & cppMask_un_8_);
	cppVar_31979 = cppVar_31992;
	}
	bool cppVar_31994 = (cppVar_31979 == 176);
	if (cppVar_31994) {
	cppVar_31978 = P3;
	} else {
	BIT_VEC cppVar_31995;
	BIT_VEC cppVar_31996;
	BIT_VEC cppVar_31997 = PC + 1;
	cppVar_31997 = (cppVar_31997 & cppMask_un_16_);
	BIT_VEC cppVar_31998 = ROM.rd(cppVar_31997);
	BIT_VEC cppVar_31999 = (cppVar_31998 >> 7) & cppMask_un_1_;
	bool cppVar_32000 = (cppVar_31999 == 1);
	if (cppVar_32000) {
	BIT_VEC cppVar_32001 = PC + 1;
	cppVar_32001 = (cppVar_32001 & cppMask_un_16_);
	BIT_VEC cppVar_32002 = ROM.rd(cppVar_32001);
	BIT_VEC cppVar_32003 = (cppVar_32002 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_32004 = (cppVar_32003 << 3) | 0;
	cppVar_32004 = (cppVar_32004 & cppMask_un_8_);
	cppVar_31996 = cppVar_32004;
	} else {
	BIT_VEC cppVar_32005 = PC + 1;
	cppVar_32005 = (cppVar_32005 & cppMask_un_16_);
	BIT_VEC cppVar_32006 = ROM.rd(cppVar_32005);
	BIT_VEC cppVar_32007 = (cppVar_32006 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_32008 = (cppVar_32007 & cppMask_un_5_);
	BIT_VEC cppVar_32009 = cppVar_32008 + 32;
	cppVar_32009 = (cppVar_32009 & cppMask_un_8_);
	cppVar_31996 = cppVar_32009;
	}
	bool cppVar_32011 = (cppVar_31996 == 184);
	if (cppVar_32011) {
	cppVar_31995 = IP;
	} else {
	BIT_VEC cppVar_32012;
	BIT_VEC cppVar_32013;
	BIT_VEC cppVar_32014 = PC + 1;
	cppVar_32014 = (cppVar_32014 & cppMask_un_16_);
	BIT_VEC cppVar_32015 = ROM.rd(cppVar_32014);
	BIT_VEC cppVar_32016 = (cppVar_32015 >> 7) & cppMask_un_1_;
	bool cppVar_32017 = (cppVar_32016 == 1);
	if (cppVar_32017) {
	BIT_VEC cppVar_32018 = PC + 1;
	cppVar_32018 = (cppVar_32018 & cppMask_un_16_);
	BIT_VEC cppVar_32019 = ROM.rd(cppVar_32018);
	BIT_VEC cppVar_32020 = (cppVar_32019 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_32021 = (cppVar_32020 << 3) | 0;
	cppVar_32021 = (cppVar_32021 & cppMask_un_8_);
	cppVar_32013 = cppVar_32021;
	} else {
	BIT_VEC cppVar_32022 = PC + 1;
	cppVar_32022 = (cppVar_32022 & cppMask_un_16_);
	BIT_VEC cppVar_32023 = ROM.rd(cppVar_32022);
	BIT_VEC cppVar_32024 = (cppVar_32023 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_32025 = (cppVar_32024 & cppMask_un_5_);
	BIT_VEC cppVar_32026 = cppVar_32025 + 32;
	cppVar_32026 = (cppVar_32026 & cppMask_un_8_);
	cppVar_32013 = cppVar_32026;
	}
	bool cppVar_32028 = (cppVar_32013 == 208);
	if (cppVar_32028) {
	cppVar_32012 = PSW;
	} else {
	BIT_VEC cppVar_32029;
	BIT_VEC cppVar_32030;
	BIT_VEC cppVar_32031 = PC + 1;
	cppVar_32031 = (cppVar_32031 & cppMask_un_16_);
	BIT_VEC cppVar_32032 = ROM.rd(cppVar_32031);
	BIT_VEC cppVar_32033 = (cppVar_32032 >> 7) & cppMask_un_1_;
	bool cppVar_32034 = (cppVar_32033 == 1);
	if (cppVar_32034) {
	BIT_VEC cppVar_32035 = PC + 1;
	cppVar_32035 = (cppVar_32035 & cppMask_un_16_);
	BIT_VEC cppVar_32036 = ROM.rd(cppVar_32035);
	BIT_VEC cppVar_32037 = (cppVar_32036 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_32038 = (cppVar_32037 << 3) | 0;
	cppVar_32038 = (cppVar_32038 & cppMask_un_8_);
	cppVar_32030 = cppVar_32038;
	} else {
	BIT_VEC cppVar_32039 = PC + 1;
	cppVar_32039 = (cppVar_32039 & cppMask_un_16_);
	BIT_VEC cppVar_32040 = ROM.rd(cppVar_32039);
	BIT_VEC cppVar_32041 = (cppVar_32040 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_32042 = (cppVar_32041 & cppMask_un_5_);
	BIT_VEC cppVar_32043 = cppVar_32042 + 32;
	cppVar_32043 = (cppVar_32043 & cppMask_un_8_);
	cppVar_32030 = cppVar_32043;
	}
	bool cppVar_32045 = (cppVar_32030 == 224);
	if (cppVar_32045) {
	cppVar_32029 = ACC;
	} else {
	BIT_VEC cppVar_32046;
	BIT_VEC cppVar_32047;
	BIT_VEC cppVar_32048 = PC + 1;
	cppVar_32048 = (cppVar_32048 & cppMask_un_16_);
	BIT_VEC cppVar_32049 = ROM.rd(cppVar_32048);
	BIT_VEC cppVar_32050 = (cppVar_32049 >> 7) & cppMask_un_1_;
	bool cppVar_32051 = (cppVar_32050 == 1);
	if (cppVar_32051) {
	BIT_VEC cppVar_32052 = PC + 1;
	cppVar_32052 = (cppVar_32052 & cppMask_un_16_);
	BIT_VEC cppVar_32053 = ROM.rd(cppVar_32052);
	BIT_VEC cppVar_32054 = (cppVar_32053 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_32055 = (cppVar_32054 << 3) | 0;
	cppVar_32055 = (cppVar_32055 & cppMask_un_8_);
	cppVar_32047 = cppVar_32055;
	} else {
	BIT_VEC cppVar_32056 = PC + 1;
	cppVar_32056 = (cppVar_32056 & cppMask_un_16_);
	BIT_VEC cppVar_32057 = ROM.rd(cppVar_32056);
	BIT_VEC cppVar_32058 = (cppVar_32057 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_32059 = (cppVar_32058 & cppMask_un_5_);
	BIT_VEC cppVar_32060 = cppVar_32059 + 32;
	cppVar_32060 = (cppVar_32060 & cppMask_un_8_);
	cppVar_32047 = cppVar_32060;
	}
	bool cppVar_32062 = (cppVar_32047 == 240);
	if (cppVar_32062) {
	cppVar_32046 = B;
	} else {
	cppVar_32046 = 0;
	}
	cppVar_32029 = cppVar_32046;
	}
	cppVar_32012 = cppVar_32029;
	}
	cppVar_31995 = cppVar_32012;
	}
	cppVar_31978 = cppVar_31995;
	}
	cppVar_31961 = cppVar_31978;
	}
	cppVar_31944 = cppVar_31961;
	}
	cppVar_31927 = cppVar_31944;
	}
	cppVar_31910 = cppVar_31927;
	}
	cppVar_31893 = cppVar_31910;
	}
	cppVar_31876 = cppVar_31893;
	}
	cppVar_31859 = cppVar_31876;
	}
	cppVar_31842 = cppVar_31859;
	}
	cppVar_31825 = cppVar_31842;
	}
	cppVar_31808 = cppVar_31825;
	}
	cppVar_31791 = cppVar_31808;
	}
	cppVar_31774 = cppVar_31791;
	}
	cppVar_31757 = cppVar_31774;
	}
	cppVar_31740 = cppVar_31757;
	}
	cppVar_31723 = cppVar_31740;
	}
	cppVar_31706 = cppVar_31723;
	}
	cppVar_31673 = cppVar_31706;
	}
	BIT_VEC cppVar_32064 = cppVar_31672 & cppVar_31673;
	BIT_VEC cppVar_32066 = 1;
	BIT_VEC cppVar_32067 = PC + 1;
	cppVar_32067 = (cppVar_32067 & cppMask_un_16_);
	BIT_VEC cppVar_32068 = ROM.rd(cppVar_32067);
	BIT_VEC cppVar_32069 = (cppVar_32068 >> 0) & cppMask_un_3_;
	BIT_VEC cppVar_32070 = (cppVar_32069 & cppMask_un_3_);
	BIT_VEC cppVar_32071 = cppVar_32066 << static_cast<unsigned>(cppVar_32070);
	cppVar_32071 = (cppVar_32071 & cppMask_un_8_);
	BIT_VEC cppVar_32072 = cppVar_32064 | cppVar_32071;
	cppVar_31645 = cppVar_32072;
	} else {
	cppVar_31645 = P2;
	}
	cppVar_31641 = cppVar_31645;
	} else {
	BIT_VEC cppVar_32073;
	BIT_VEC cppVar_32074 = ROM.rd(PC);
	bool cppVar_32076 = (cppVar_32074 == 208);
	if (cppVar_32076) {
	BIT_VEC cppVar_32077;
	BIT_VEC cppVar_32079 = PC + 1;
	cppVar_32079 = (cppVar_32079 & cppMask_un_16_);
	BIT_VEC cppVar_32080 = ROM.rd(cppVar_32079);
	bool cppVar_32082 = (cppVar_32080 == 160);
	if (cppVar_32082) {
	BIT_VEC cppVar_32083 = IRAM.rd(SP);
	cppVar_32077 = cppVar_32083;
	} else {
	cppVar_32077 = P2;
	}
	cppVar_32073 = cppVar_32077;
	} else {
	BIT_VEC cppVar_32084;
	BIT_VEC cppVar_32085 = ROM.rd(PC);
	bool cppVar_32087 = (cppVar_32085 == 245);
	BIT_VEC cppVar_32088 = ROM.rd(PC);
	bool cppVar_32090 = (cppVar_32088 == 197);
	bool cppVar_32091 = cppVar_32087 || cppVar_32090;
	if (cppVar_32091) {
	BIT_VEC cppVar_32092;
	BIT_VEC cppVar_32094 = PC + 1;
	cppVar_32094 = (cppVar_32094 & cppMask_un_16_);
	BIT_VEC cppVar_32095 = ROM.rd(cppVar_32094);
	bool cppVar_32097 = (cppVar_32095 == 160);
	if (cppVar_32097) {
	cppVar_32092 = ACC;
	} else {
	cppVar_32092 = P2;
	}
	cppVar_32084 = cppVar_32092;
	} else {
	BIT_VEC cppVar_32098;
	BIT_VEC cppVar_32099 = ROM.rd(PC);
	bool cppVar_32101 = (cppVar_32099 == 178);
	if (cppVar_32101) {
	BIT_VEC cppVar_32102;
	BIT_VEC cppVar_32103;
	BIT_VEC cppVar_32105 = PC + 1;
	cppVar_32105 = (cppVar_32105 & cppMask_un_16_);
	BIT_VEC cppVar_32106 = ROM.rd(cppVar_32105);
	BIT_VEC cppVar_32107 = (cppVar_32106 >> 7) & cppMask_un_1_;
	bool cppVar_32109 = (cppVar_32107 == 1);
	if (cppVar_32109) {
	BIT_VEC cppVar_32110 = PC + 1;
	cppVar_32110 = (cppVar_32110 & cppMask_un_16_);
	BIT_VEC cppVar_32111 = ROM.rd(cppVar_32110);
	BIT_VEC cppVar_32112 = (cppVar_32111 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_32114 = (cppVar_32112 << 3) | 0;
	cppVar_32114 = (cppVar_32114 & cppMask_un_8_);
	cppVar_32103 = cppVar_32114;
	} else {
	BIT_VEC cppVar_32115 = PC + 1;
	cppVar_32115 = (cppVar_32115 & cppMask_un_16_);
	BIT_VEC cppVar_32116 = ROM.rd(cppVar_32115);
	BIT_VEC cppVar_32117 = (cppVar_32116 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_32118 = (cppVar_32117 & cppMask_un_5_);
	BIT_VEC cppVar_32120 = cppVar_32118 + 32;
	cppVar_32120 = (cppVar_32120 & cppMask_un_8_);
	cppVar_32103 = cppVar_32120;
	}
	bool cppVar_32122 = (cppVar_32103 == 160);
	if (cppVar_32122) {
	BIT_VEC cppVar_32124 = PC + 1;
	cppVar_32124 = (cppVar_32124 & cppMask_un_16_);
	BIT_VEC cppVar_32125 = ROM.rd(cppVar_32124);
	BIT_VEC cppVar_32126 = (cppVar_32125 >> 0) & cppMask_un_3_;
	BIT_VEC cppVar_32127 = (cppVar_32126 & cppMask_un_3_);
	BIT_VEC cppVar_32128 = 1 << static_cast<unsigned>(cppVar_32127);
	cppVar_32128 = (cppVar_32128 & cppMask_un_8_);
	BIT_VEC cppVar_32129 = ~cppVar_32128;
	BIT_VEC cppVar_32130;
	BIT_VEC cppVar_32131;
	BIT_VEC cppVar_32132 = PC + 1;
	cppVar_32132 = (cppVar_32132 & cppMask_un_16_);
	BIT_VEC cppVar_32133 = ROM.rd(cppVar_32132);
	BIT_VEC cppVar_32134 = (cppVar_32133 >> 7) & cppMask_un_1_;
	bool cppVar_32135 = (cppVar_32134 == 1);
	if (cppVar_32135) {
	BIT_VEC cppVar_32136 = PC + 1;
	cppVar_32136 = (cppVar_32136 & cppMask_un_16_);
	BIT_VEC cppVar_32137 = ROM.rd(cppVar_32136);
	BIT_VEC cppVar_32138 = (cppVar_32137 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_32139 = (cppVar_32138 << 3) | 0;
	cppVar_32139 = (cppVar_32139 & cppMask_un_8_);
	cppVar_32131 = cppVar_32139;
	} else {
	BIT_VEC cppVar_32140 = PC + 1;
	cppVar_32140 = (cppVar_32140 & cppMask_un_16_);
	BIT_VEC cppVar_32141 = ROM.rd(cppVar_32140);
	BIT_VEC cppVar_32142 = (cppVar_32141 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_32143 = (cppVar_32142 & cppMask_un_5_);
	BIT_VEC cppVar_32144 = cppVar_32143 + 32;
	cppVar_32144 = (cppVar_32144 & cppMask_un_8_);
	cppVar_32131 = cppVar_32144;
	}
	BIT_VEC cppVar_32145 = (cppVar_32131 >> 7) & cppMask_un_1_;
	bool cppVar_32147 = (cppVar_32145 == 0);
	if (cppVar_32147) {
	BIT_VEC cppVar_32148;
	BIT_VEC cppVar_32149 = PC + 1;
	cppVar_32149 = (cppVar_32149 & cppMask_un_16_);
	BIT_VEC cppVar_32150 = ROM.rd(cppVar_32149);
	BIT_VEC cppVar_32151 = (cppVar_32150 >> 7) & cppMask_un_1_;
	bool cppVar_32152 = (cppVar_32151 == 1);
	if (cppVar_32152) {
	BIT_VEC cppVar_32153 = PC + 1;
	cppVar_32153 = (cppVar_32153 & cppMask_un_16_);
	BIT_VEC cppVar_32154 = ROM.rd(cppVar_32153);
	BIT_VEC cppVar_32155 = (cppVar_32154 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_32156 = (cppVar_32155 << 3) | 0;
	cppVar_32156 = (cppVar_32156 & cppMask_un_8_);
	cppVar_32148 = cppVar_32156;
	} else {
	BIT_VEC cppVar_32157 = PC + 1;
	cppVar_32157 = (cppVar_32157 & cppMask_un_16_);
	BIT_VEC cppVar_32158 = ROM.rd(cppVar_32157);
	BIT_VEC cppVar_32159 = (cppVar_32158 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_32160 = (cppVar_32159 & cppMask_un_5_);
	BIT_VEC cppVar_32161 = cppVar_32160 + 32;
	cppVar_32161 = (cppVar_32161 & cppMask_un_8_);
	cppVar_32148 = cppVar_32161;
	}
	BIT_VEC cppVar_32162 = IRAM.rd(cppVar_32148);
	cppVar_32130 = cppVar_32162;
	} else {
	BIT_VEC cppVar_32163;
	BIT_VEC cppVar_32164;
	BIT_VEC cppVar_32165 = PC + 1;
	cppVar_32165 = (cppVar_32165 & cppMask_un_16_);
	BIT_VEC cppVar_32166 = ROM.rd(cppVar_32165);
	BIT_VEC cppVar_32167 = (cppVar_32166 >> 7) & cppMask_un_1_;
	bool cppVar_32168 = (cppVar_32167 == 1);
	if (cppVar_32168) {
	BIT_VEC cppVar_32169 = PC + 1;
	cppVar_32169 = (cppVar_32169 & cppMask_un_16_);
	BIT_VEC cppVar_32170 = ROM.rd(cppVar_32169);
	BIT_VEC cppVar_32171 = (cppVar_32170 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_32172 = (cppVar_32171 << 3) | 0;
	cppVar_32172 = (cppVar_32172 & cppMask_un_8_);
	cppVar_32164 = cppVar_32172;
	} else {
	BIT_VEC cppVar_32173 = PC + 1;
	cppVar_32173 = (cppVar_32173 & cppMask_un_16_);
	BIT_VEC cppVar_32174 = ROM.rd(cppVar_32173);
	BIT_VEC cppVar_32175 = (cppVar_32174 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_32176 = (cppVar_32175 & cppMask_un_5_);
	BIT_VEC cppVar_32177 = cppVar_32176 + 32;
	cppVar_32177 = (cppVar_32177 & cppMask_un_8_);
	cppVar_32164 = cppVar_32177;
	}
	bool cppVar_32179 = (cppVar_32164 == 128);
	if (cppVar_32179) {
	cppVar_32163 = P0;
	} else {
	BIT_VEC cppVar_32180;
	BIT_VEC cppVar_32181;
	BIT_VEC cppVar_32182 = PC + 1;
	cppVar_32182 = (cppVar_32182 & cppMask_un_16_);
	BIT_VEC cppVar_32183 = ROM.rd(cppVar_32182);
	BIT_VEC cppVar_32184 = (cppVar_32183 >> 7) & cppMask_un_1_;
	bool cppVar_32185 = (cppVar_32184 == 1);
	if (cppVar_32185) {
	BIT_VEC cppVar_32186 = PC + 1;
	cppVar_32186 = (cppVar_32186 & cppMask_un_16_);
	BIT_VEC cppVar_32187 = ROM.rd(cppVar_32186);
	BIT_VEC cppVar_32188 = (cppVar_32187 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_32189 = (cppVar_32188 << 3) | 0;
	cppVar_32189 = (cppVar_32189 & cppMask_un_8_);
	cppVar_32181 = cppVar_32189;
	} else {
	BIT_VEC cppVar_32190 = PC + 1;
	cppVar_32190 = (cppVar_32190 & cppMask_un_16_);
	BIT_VEC cppVar_32191 = ROM.rd(cppVar_32190);
	BIT_VEC cppVar_32192 = (cppVar_32191 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_32193 = (cppVar_32192 & cppMask_un_5_);
	BIT_VEC cppVar_32194 = cppVar_32193 + 32;
	cppVar_32194 = (cppVar_32194 & cppMask_un_8_);
	cppVar_32181 = cppVar_32194;
	}
	bool cppVar_32196 = (cppVar_32181 == 129);
	if (cppVar_32196) {
	cppVar_32180 = SP;
	} else {
	BIT_VEC cppVar_32197;
	BIT_VEC cppVar_32198;
	BIT_VEC cppVar_32199 = PC + 1;
	cppVar_32199 = (cppVar_32199 & cppMask_un_16_);
	BIT_VEC cppVar_32200 = ROM.rd(cppVar_32199);
	BIT_VEC cppVar_32201 = (cppVar_32200 >> 7) & cppMask_un_1_;
	bool cppVar_32202 = (cppVar_32201 == 1);
	if (cppVar_32202) {
	BIT_VEC cppVar_32203 = PC + 1;
	cppVar_32203 = (cppVar_32203 & cppMask_un_16_);
	BIT_VEC cppVar_32204 = ROM.rd(cppVar_32203);
	BIT_VEC cppVar_32205 = (cppVar_32204 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_32206 = (cppVar_32205 << 3) | 0;
	cppVar_32206 = (cppVar_32206 & cppMask_un_8_);
	cppVar_32198 = cppVar_32206;
	} else {
	BIT_VEC cppVar_32207 = PC + 1;
	cppVar_32207 = (cppVar_32207 & cppMask_un_16_);
	BIT_VEC cppVar_32208 = ROM.rd(cppVar_32207);
	BIT_VEC cppVar_32209 = (cppVar_32208 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_32210 = (cppVar_32209 & cppMask_un_5_);
	BIT_VEC cppVar_32211 = cppVar_32210 + 32;
	cppVar_32211 = (cppVar_32211 & cppMask_un_8_);
	cppVar_32198 = cppVar_32211;
	}
	bool cppVar_32213 = (cppVar_32198 == 130);
	if (cppVar_32213) {
	cppVar_32197 = DPL;
	} else {
	BIT_VEC cppVar_32214;
	BIT_VEC cppVar_32215;
	BIT_VEC cppVar_32216 = PC + 1;
	cppVar_32216 = (cppVar_32216 & cppMask_un_16_);
	BIT_VEC cppVar_32217 = ROM.rd(cppVar_32216);
	BIT_VEC cppVar_32218 = (cppVar_32217 >> 7) & cppMask_un_1_;
	bool cppVar_32219 = (cppVar_32218 == 1);
	if (cppVar_32219) {
	BIT_VEC cppVar_32220 = PC + 1;
	cppVar_32220 = (cppVar_32220 & cppMask_un_16_);
	BIT_VEC cppVar_32221 = ROM.rd(cppVar_32220);
	BIT_VEC cppVar_32222 = (cppVar_32221 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_32223 = (cppVar_32222 << 3) | 0;
	cppVar_32223 = (cppVar_32223 & cppMask_un_8_);
	cppVar_32215 = cppVar_32223;
	} else {
	BIT_VEC cppVar_32224 = PC + 1;
	cppVar_32224 = (cppVar_32224 & cppMask_un_16_);
	BIT_VEC cppVar_32225 = ROM.rd(cppVar_32224);
	BIT_VEC cppVar_32226 = (cppVar_32225 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_32227 = (cppVar_32226 & cppMask_un_5_);
	BIT_VEC cppVar_32228 = cppVar_32227 + 32;
	cppVar_32228 = (cppVar_32228 & cppMask_un_8_);
	cppVar_32215 = cppVar_32228;
	}
	bool cppVar_32230 = (cppVar_32215 == 131);
	if (cppVar_32230) {
	cppVar_32214 = DPH;
	} else {
	BIT_VEC cppVar_32231;
	BIT_VEC cppVar_32232;
	BIT_VEC cppVar_32233 = PC + 1;
	cppVar_32233 = (cppVar_32233 & cppMask_un_16_);
	BIT_VEC cppVar_32234 = ROM.rd(cppVar_32233);
	BIT_VEC cppVar_32235 = (cppVar_32234 >> 7) & cppMask_un_1_;
	bool cppVar_32236 = (cppVar_32235 == 1);
	if (cppVar_32236) {
	BIT_VEC cppVar_32237 = PC + 1;
	cppVar_32237 = (cppVar_32237 & cppMask_un_16_);
	BIT_VEC cppVar_32238 = ROM.rd(cppVar_32237);
	BIT_VEC cppVar_32239 = (cppVar_32238 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_32240 = (cppVar_32239 << 3) | 0;
	cppVar_32240 = (cppVar_32240 & cppMask_un_8_);
	cppVar_32232 = cppVar_32240;
	} else {
	BIT_VEC cppVar_32241 = PC + 1;
	cppVar_32241 = (cppVar_32241 & cppMask_un_16_);
	BIT_VEC cppVar_32242 = ROM.rd(cppVar_32241);
	BIT_VEC cppVar_32243 = (cppVar_32242 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_32244 = (cppVar_32243 & cppMask_un_5_);
	BIT_VEC cppVar_32245 = cppVar_32244 + 32;
	cppVar_32245 = (cppVar_32245 & cppMask_un_8_);
	cppVar_32232 = cppVar_32245;
	}
	bool cppVar_32247 = (cppVar_32232 == 135);
	if (cppVar_32247) {
	cppVar_32231 = PCON;
	} else {
	BIT_VEC cppVar_32248;
	BIT_VEC cppVar_32249;
	BIT_VEC cppVar_32250 = PC + 1;
	cppVar_32250 = (cppVar_32250 & cppMask_un_16_);
	BIT_VEC cppVar_32251 = ROM.rd(cppVar_32250);
	BIT_VEC cppVar_32252 = (cppVar_32251 >> 7) & cppMask_un_1_;
	bool cppVar_32253 = (cppVar_32252 == 1);
	if (cppVar_32253) {
	BIT_VEC cppVar_32254 = PC + 1;
	cppVar_32254 = (cppVar_32254 & cppMask_un_16_);
	BIT_VEC cppVar_32255 = ROM.rd(cppVar_32254);
	BIT_VEC cppVar_32256 = (cppVar_32255 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_32257 = (cppVar_32256 << 3) | 0;
	cppVar_32257 = (cppVar_32257 & cppMask_un_8_);
	cppVar_32249 = cppVar_32257;
	} else {
	BIT_VEC cppVar_32258 = PC + 1;
	cppVar_32258 = (cppVar_32258 & cppMask_un_16_);
	BIT_VEC cppVar_32259 = ROM.rd(cppVar_32258);
	BIT_VEC cppVar_32260 = (cppVar_32259 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_32261 = (cppVar_32260 & cppMask_un_5_);
	BIT_VEC cppVar_32262 = cppVar_32261 + 32;
	cppVar_32262 = (cppVar_32262 & cppMask_un_8_);
	cppVar_32249 = cppVar_32262;
	}
	bool cppVar_32264 = (cppVar_32249 == 136);
	if (cppVar_32264) {
	cppVar_32248 = TCON;
	} else {
	BIT_VEC cppVar_32265;
	BIT_VEC cppVar_32266;
	BIT_VEC cppVar_32267 = PC + 1;
	cppVar_32267 = (cppVar_32267 & cppMask_un_16_);
	BIT_VEC cppVar_32268 = ROM.rd(cppVar_32267);
	BIT_VEC cppVar_32269 = (cppVar_32268 >> 7) & cppMask_un_1_;
	bool cppVar_32270 = (cppVar_32269 == 1);
	if (cppVar_32270) {
	BIT_VEC cppVar_32271 = PC + 1;
	cppVar_32271 = (cppVar_32271 & cppMask_un_16_);
	BIT_VEC cppVar_32272 = ROM.rd(cppVar_32271);
	BIT_VEC cppVar_32273 = (cppVar_32272 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_32274 = (cppVar_32273 << 3) | 0;
	cppVar_32274 = (cppVar_32274 & cppMask_un_8_);
	cppVar_32266 = cppVar_32274;
	} else {
	BIT_VEC cppVar_32275 = PC + 1;
	cppVar_32275 = (cppVar_32275 & cppMask_un_16_);
	BIT_VEC cppVar_32276 = ROM.rd(cppVar_32275);
	BIT_VEC cppVar_32277 = (cppVar_32276 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_32278 = (cppVar_32277 & cppMask_un_5_);
	BIT_VEC cppVar_32279 = cppVar_32278 + 32;
	cppVar_32279 = (cppVar_32279 & cppMask_un_8_);
	cppVar_32266 = cppVar_32279;
	}
	bool cppVar_32281 = (cppVar_32266 == 137);
	if (cppVar_32281) {
	cppVar_32265 = TMOD;
	} else {
	BIT_VEC cppVar_32282;
	BIT_VEC cppVar_32283;
	BIT_VEC cppVar_32284 = PC + 1;
	cppVar_32284 = (cppVar_32284 & cppMask_un_16_);
	BIT_VEC cppVar_32285 = ROM.rd(cppVar_32284);
	BIT_VEC cppVar_32286 = (cppVar_32285 >> 7) & cppMask_un_1_;
	bool cppVar_32287 = (cppVar_32286 == 1);
	if (cppVar_32287) {
	BIT_VEC cppVar_32288 = PC + 1;
	cppVar_32288 = (cppVar_32288 & cppMask_un_16_);
	BIT_VEC cppVar_32289 = ROM.rd(cppVar_32288);
	BIT_VEC cppVar_32290 = (cppVar_32289 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_32291 = (cppVar_32290 << 3) | 0;
	cppVar_32291 = (cppVar_32291 & cppMask_un_8_);
	cppVar_32283 = cppVar_32291;
	} else {
	BIT_VEC cppVar_32292 = PC + 1;
	cppVar_32292 = (cppVar_32292 & cppMask_un_16_);
	BIT_VEC cppVar_32293 = ROM.rd(cppVar_32292);
	BIT_VEC cppVar_32294 = (cppVar_32293 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_32295 = (cppVar_32294 & cppMask_un_5_);
	BIT_VEC cppVar_32296 = cppVar_32295 + 32;
	cppVar_32296 = (cppVar_32296 & cppMask_un_8_);
	cppVar_32283 = cppVar_32296;
	}
	bool cppVar_32298 = (cppVar_32283 == 138);
	if (cppVar_32298) {
	cppVar_32282 = TL0;
	} else {
	BIT_VEC cppVar_32299;
	BIT_VEC cppVar_32300;
	BIT_VEC cppVar_32301 = PC + 1;
	cppVar_32301 = (cppVar_32301 & cppMask_un_16_);
	BIT_VEC cppVar_32302 = ROM.rd(cppVar_32301);
	BIT_VEC cppVar_32303 = (cppVar_32302 >> 7) & cppMask_un_1_;
	bool cppVar_32304 = (cppVar_32303 == 1);
	if (cppVar_32304) {
	BIT_VEC cppVar_32305 = PC + 1;
	cppVar_32305 = (cppVar_32305 & cppMask_un_16_);
	BIT_VEC cppVar_32306 = ROM.rd(cppVar_32305);
	BIT_VEC cppVar_32307 = (cppVar_32306 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_32308 = (cppVar_32307 << 3) | 0;
	cppVar_32308 = (cppVar_32308 & cppMask_un_8_);
	cppVar_32300 = cppVar_32308;
	} else {
	BIT_VEC cppVar_32309 = PC + 1;
	cppVar_32309 = (cppVar_32309 & cppMask_un_16_);
	BIT_VEC cppVar_32310 = ROM.rd(cppVar_32309);
	BIT_VEC cppVar_32311 = (cppVar_32310 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_32312 = (cppVar_32311 & cppMask_un_5_);
	BIT_VEC cppVar_32313 = cppVar_32312 + 32;
	cppVar_32313 = (cppVar_32313 & cppMask_un_8_);
	cppVar_32300 = cppVar_32313;
	}
	bool cppVar_32315 = (cppVar_32300 == 140);
	if (cppVar_32315) {
	cppVar_32299 = TH0;
	} else {
	BIT_VEC cppVar_32316;
	BIT_VEC cppVar_32317;
	BIT_VEC cppVar_32318 = PC + 1;
	cppVar_32318 = (cppVar_32318 & cppMask_un_16_);
	BIT_VEC cppVar_32319 = ROM.rd(cppVar_32318);
	BIT_VEC cppVar_32320 = (cppVar_32319 >> 7) & cppMask_un_1_;
	bool cppVar_32321 = (cppVar_32320 == 1);
	if (cppVar_32321) {
	BIT_VEC cppVar_32322 = PC + 1;
	cppVar_32322 = (cppVar_32322 & cppMask_un_16_);
	BIT_VEC cppVar_32323 = ROM.rd(cppVar_32322);
	BIT_VEC cppVar_32324 = (cppVar_32323 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_32325 = (cppVar_32324 << 3) | 0;
	cppVar_32325 = (cppVar_32325 & cppMask_un_8_);
	cppVar_32317 = cppVar_32325;
	} else {
	BIT_VEC cppVar_32326 = PC + 1;
	cppVar_32326 = (cppVar_32326 & cppMask_un_16_);
	BIT_VEC cppVar_32327 = ROM.rd(cppVar_32326);
	BIT_VEC cppVar_32328 = (cppVar_32327 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_32329 = (cppVar_32328 & cppMask_un_5_);
	BIT_VEC cppVar_32330 = cppVar_32329 + 32;
	cppVar_32330 = (cppVar_32330 & cppMask_un_8_);
	cppVar_32317 = cppVar_32330;
	}
	bool cppVar_32332 = (cppVar_32317 == 139);
	if (cppVar_32332) {
	cppVar_32316 = TL1;
	} else {
	BIT_VEC cppVar_32333;
	BIT_VEC cppVar_32334;
	BIT_VEC cppVar_32335 = PC + 1;
	cppVar_32335 = (cppVar_32335 & cppMask_un_16_);
	BIT_VEC cppVar_32336 = ROM.rd(cppVar_32335);
	BIT_VEC cppVar_32337 = (cppVar_32336 >> 7) & cppMask_un_1_;
	bool cppVar_32338 = (cppVar_32337 == 1);
	if (cppVar_32338) {
	BIT_VEC cppVar_32339 = PC + 1;
	cppVar_32339 = (cppVar_32339 & cppMask_un_16_);
	BIT_VEC cppVar_32340 = ROM.rd(cppVar_32339);
	BIT_VEC cppVar_32341 = (cppVar_32340 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_32342 = (cppVar_32341 << 3) | 0;
	cppVar_32342 = (cppVar_32342 & cppMask_un_8_);
	cppVar_32334 = cppVar_32342;
	} else {
	BIT_VEC cppVar_32343 = PC + 1;
	cppVar_32343 = (cppVar_32343 & cppMask_un_16_);
	BIT_VEC cppVar_32344 = ROM.rd(cppVar_32343);
	BIT_VEC cppVar_32345 = (cppVar_32344 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_32346 = (cppVar_32345 & cppMask_un_5_);
	BIT_VEC cppVar_32347 = cppVar_32346 + 32;
	cppVar_32347 = (cppVar_32347 & cppMask_un_8_);
	cppVar_32334 = cppVar_32347;
	}
	bool cppVar_32349 = (cppVar_32334 == 141);
	if (cppVar_32349) {
	cppVar_32333 = TH1;
	} else {
	BIT_VEC cppVar_32350;
	BIT_VEC cppVar_32351;
	BIT_VEC cppVar_32352 = PC + 1;
	cppVar_32352 = (cppVar_32352 & cppMask_un_16_);
	BIT_VEC cppVar_32353 = ROM.rd(cppVar_32352);
	BIT_VEC cppVar_32354 = (cppVar_32353 >> 7) & cppMask_un_1_;
	bool cppVar_32355 = (cppVar_32354 == 1);
	if (cppVar_32355) {
	BIT_VEC cppVar_32356 = PC + 1;
	cppVar_32356 = (cppVar_32356 & cppMask_un_16_);
	BIT_VEC cppVar_32357 = ROM.rd(cppVar_32356);
	BIT_VEC cppVar_32358 = (cppVar_32357 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_32359 = (cppVar_32358 << 3) | 0;
	cppVar_32359 = (cppVar_32359 & cppMask_un_8_);
	cppVar_32351 = cppVar_32359;
	} else {
	BIT_VEC cppVar_32360 = PC + 1;
	cppVar_32360 = (cppVar_32360 & cppMask_un_16_);
	BIT_VEC cppVar_32361 = ROM.rd(cppVar_32360);
	BIT_VEC cppVar_32362 = (cppVar_32361 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_32363 = (cppVar_32362 & cppMask_un_5_);
	BIT_VEC cppVar_32364 = cppVar_32363 + 32;
	cppVar_32364 = (cppVar_32364 & cppMask_un_8_);
	cppVar_32351 = cppVar_32364;
	}
	bool cppVar_32366 = (cppVar_32351 == 144);
	if (cppVar_32366) {
	cppVar_32350 = P1;
	} else {
	BIT_VEC cppVar_32367;
	BIT_VEC cppVar_32368;
	BIT_VEC cppVar_32369 = PC + 1;
	cppVar_32369 = (cppVar_32369 & cppMask_un_16_);
	BIT_VEC cppVar_32370 = ROM.rd(cppVar_32369);
	BIT_VEC cppVar_32371 = (cppVar_32370 >> 7) & cppMask_un_1_;
	bool cppVar_32372 = (cppVar_32371 == 1);
	if (cppVar_32372) {
	BIT_VEC cppVar_32373 = PC + 1;
	cppVar_32373 = (cppVar_32373 & cppMask_un_16_);
	BIT_VEC cppVar_32374 = ROM.rd(cppVar_32373);
	BIT_VEC cppVar_32375 = (cppVar_32374 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_32376 = (cppVar_32375 << 3) | 0;
	cppVar_32376 = (cppVar_32376 & cppMask_un_8_);
	cppVar_32368 = cppVar_32376;
	} else {
	BIT_VEC cppVar_32377 = PC + 1;
	cppVar_32377 = (cppVar_32377 & cppMask_un_16_);
	BIT_VEC cppVar_32378 = ROM.rd(cppVar_32377);
	BIT_VEC cppVar_32379 = (cppVar_32378 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_32380 = (cppVar_32379 & cppMask_un_5_);
	BIT_VEC cppVar_32381 = cppVar_32380 + 32;
	cppVar_32381 = (cppVar_32381 & cppMask_un_8_);
	cppVar_32368 = cppVar_32381;
	}
	bool cppVar_32383 = (cppVar_32368 == 152);
	if (cppVar_32383) {
	cppVar_32367 = SCON;
	} else {
	BIT_VEC cppVar_32384;
	BIT_VEC cppVar_32385;
	BIT_VEC cppVar_32386 = PC + 1;
	cppVar_32386 = (cppVar_32386 & cppMask_un_16_);
	BIT_VEC cppVar_32387 = ROM.rd(cppVar_32386);
	BIT_VEC cppVar_32388 = (cppVar_32387 >> 7) & cppMask_un_1_;
	bool cppVar_32389 = (cppVar_32388 == 1);
	if (cppVar_32389) {
	BIT_VEC cppVar_32390 = PC + 1;
	cppVar_32390 = (cppVar_32390 & cppMask_un_16_);
	BIT_VEC cppVar_32391 = ROM.rd(cppVar_32390);
	BIT_VEC cppVar_32392 = (cppVar_32391 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_32393 = (cppVar_32392 << 3) | 0;
	cppVar_32393 = (cppVar_32393 & cppMask_un_8_);
	cppVar_32385 = cppVar_32393;
	} else {
	BIT_VEC cppVar_32394 = PC + 1;
	cppVar_32394 = (cppVar_32394 & cppMask_un_16_);
	BIT_VEC cppVar_32395 = ROM.rd(cppVar_32394);
	BIT_VEC cppVar_32396 = (cppVar_32395 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_32397 = (cppVar_32396 & cppMask_un_5_);
	BIT_VEC cppVar_32398 = cppVar_32397 + 32;
	cppVar_32398 = (cppVar_32398 & cppMask_un_8_);
	cppVar_32385 = cppVar_32398;
	}
	bool cppVar_32400 = (cppVar_32385 == 153);
	if (cppVar_32400) {
	cppVar_32384 = SBUF;
	} else {
	BIT_VEC cppVar_32401;
	BIT_VEC cppVar_32402;
	BIT_VEC cppVar_32403 = PC + 1;
	cppVar_32403 = (cppVar_32403 & cppMask_un_16_);
	BIT_VEC cppVar_32404 = ROM.rd(cppVar_32403);
	BIT_VEC cppVar_32405 = (cppVar_32404 >> 7) & cppMask_un_1_;
	bool cppVar_32406 = (cppVar_32405 == 1);
	if (cppVar_32406) {
	BIT_VEC cppVar_32407 = PC + 1;
	cppVar_32407 = (cppVar_32407 & cppMask_un_16_);
	BIT_VEC cppVar_32408 = ROM.rd(cppVar_32407);
	BIT_VEC cppVar_32409 = (cppVar_32408 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_32410 = (cppVar_32409 << 3) | 0;
	cppVar_32410 = (cppVar_32410 & cppMask_un_8_);
	cppVar_32402 = cppVar_32410;
	} else {
	BIT_VEC cppVar_32411 = PC + 1;
	cppVar_32411 = (cppVar_32411 & cppMask_un_16_);
	BIT_VEC cppVar_32412 = ROM.rd(cppVar_32411);
	BIT_VEC cppVar_32413 = (cppVar_32412 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_32414 = (cppVar_32413 & cppMask_un_5_);
	BIT_VEC cppVar_32415 = cppVar_32414 + 32;
	cppVar_32415 = (cppVar_32415 & cppMask_un_8_);
	cppVar_32402 = cppVar_32415;
	}
	bool cppVar_32417 = (cppVar_32402 == 160);
	if (cppVar_32417) {
	cppVar_32401 = P2;
	} else {
	BIT_VEC cppVar_32418;
	BIT_VEC cppVar_32419;
	BIT_VEC cppVar_32420 = PC + 1;
	cppVar_32420 = (cppVar_32420 & cppMask_un_16_);
	BIT_VEC cppVar_32421 = ROM.rd(cppVar_32420);
	BIT_VEC cppVar_32422 = (cppVar_32421 >> 7) & cppMask_un_1_;
	bool cppVar_32423 = (cppVar_32422 == 1);
	if (cppVar_32423) {
	BIT_VEC cppVar_32424 = PC + 1;
	cppVar_32424 = (cppVar_32424 & cppMask_un_16_);
	BIT_VEC cppVar_32425 = ROM.rd(cppVar_32424);
	BIT_VEC cppVar_32426 = (cppVar_32425 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_32427 = (cppVar_32426 << 3) | 0;
	cppVar_32427 = (cppVar_32427 & cppMask_un_8_);
	cppVar_32419 = cppVar_32427;
	} else {
	BIT_VEC cppVar_32428 = PC + 1;
	cppVar_32428 = (cppVar_32428 & cppMask_un_16_);
	BIT_VEC cppVar_32429 = ROM.rd(cppVar_32428);
	BIT_VEC cppVar_32430 = (cppVar_32429 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_32431 = (cppVar_32430 & cppMask_un_5_);
	BIT_VEC cppVar_32432 = cppVar_32431 + 32;
	cppVar_32432 = (cppVar_32432 & cppMask_un_8_);
	cppVar_32419 = cppVar_32432;
	}
	bool cppVar_32434 = (cppVar_32419 == 168);
	if (cppVar_32434) {
	cppVar_32418 = IE;
	} else {
	BIT_VEC cppVar_32435;
	BIT_VEC cppVar_32436;
	BIT_VEC cppVar_32437 = PC + 1;
	cppVar_32437 = (cppVar_32437 & cppMask_un_16_);
	BIT_VEC cppVar_32438 = ROM.rd(cppVar_32437);
	BIT_VEC cppVar_32439 = (cppVar_32438 >> 7) & cppMask_un_1_;
	bool cppVar_32440 = (cppVar_32439 == 1);
	if (cppVar_32440) {
	BIT_VEC cppVar_32441 = PC + 1;
	cppVar_32441 = (cppVar_32441 & cppMask_un_16_);
	BIT_VEC cppVar_32442 = ROM.rd(cppVar_32441);
	BIT_VEC cppVar_32443 = (cppVar_32442 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_32444 = (cppVar_32443 << 3) | 0;
	cppVar_32444 = (cppVar_32444 & cppMask_un_8_);
	cppVar_32436 = cppVar_32444;
	} else {
	BIT_VEC cppVar_32445 = PC + 1;
	cppVar_32445 = (cppVar_32445 & cppMask_un_16_);
	BIT_VEC cppVar_32446 = ROM.rd(cppVar_32445);
	BIT_VEC cppVar_32447 = (cppVar_32446 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_32448 = (cppVar_32447 & cppMask_un_5_);
	BIT_VEC cppVar_32449 = cppVar_32448 + 32;
	cppVar_32449 = (cppVar_32449 & cppMask_un_8_);
	cppVar_32436 = cppVar_32449;
	}
	bool cppVar_32451 = (cppVar_32436 == 176);
	if (cppVar_32451) {
	cppVar_32435 = P3;
	} else {
	BIT_VEC cppVar_32452;
	BIT_VEC cppVar_32453;
	BIT_VEC cppVar_32454 = PC + 1;
	cppVar_32454 = (cppVar_32454 & cppMask_un_16_);
	BIT_VEC cppVar_32455 = ROM.rd(cppVar_32454);
	BIT_VEC cppVar_32456 = (cppVar_32455 >> 7) & cppMask_un_1_;
	bool cppVar_32457 = (cppVar_32456 == 1);
	if (cppVar_32457) {
	BIT_VEC cppVar_32458 = PC + 1;
	cppVar_32458 = (cppVar_32458 & cppMask_un_16_);
	BIT_VEC cppVar_32459 = ROM.rd(cppVar_32458);
	BIT_VEC cppVar_32460 = (cppVar_32459 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_32461 = (cppVar_32460 << 3) | 0;
	cppVar_32461 = (cppVar_32461 & cppMask_un_8_);
	cppVar_32453 = cppVar_32461;
	} else {
	BIT_VEC cppVar_32462 = PC + 1;
	cppVar_32462 = (cppVar_32462 & cppMask_un_16_);
	BIT_VEC cppVar_32463 = ROM.rd(cppVar_32462);
	BIT_VEC cppVar_32464 = (cppVar_32463 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_32465 = (cppVar_32464 & cppMask_un_5_);
	BIT_VEC cppVar_32466 = cppVar_32465 + 32;
	cppVar_32466 = (cppVar_32466 & cppMask_un_8_);
	cppVar_32453 = cppVar_32466;
	}
	bool cppVar_32468 = (cppVar_32453 == 184);
	if (cppVar_32468) {
	cppVar_32452 = IP;
	} else {
	BIT_VEC cppVar_32469;
	BIT_VEC cppVar_32470;
	BIT_VEC cppVar_32471 = PC + 1;
	cppVar_32471 = (cppVar_32471 & cppMask_un_16_);
	BIT_VEC cppVar_32472 = ROM.rd(cppVar_32471);
	BIT_VEC cppVar_32473 = (cppVar_32472 >> 7) & cppMask_un_1_;
	bool cppVar_32474 = (cppVar_32473 == 1);
	if (cppVar_32474) {
	BIT_VEC cppVar_32475 = PC + 1;
	cppVar_32475 = (cppVar_32475 & cppMask_un_16_);
	BIT_VEC cppVar_32476 = ROM.rd(cppVar_32475);
	BIT_VEC cppVar_32477 = (cppVar_32476 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_32478 = (cppVar_32477 << 3) | 0;
	cppVar_32478 = (cppVar_32478 & cppMask_un_8_);
	cppVar_32470 = cppVar_32478;
	} else {
	BIT_VEC cppVar_32479 = PC + 1;
	cppVar_32479 = (cppVar_32479 & cppMask_un_16_);
	BIT_VEC cppVar_32480 = ROM.rd(cppVar_32479);
	BIT_VEC cppVar_32481 = (cppVar_32480 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_32482 = (cppVar_32481 & cppMask_un_5_);
	BIT_VEC cppVar_32483 = cppVar_32482 + 32;
	cppVar_32483 = (cppVar_32483 & cppMask_un_8_);
	cppVar_32470 = cppVar_32483;
	}
	bool cppVar_32485 = (cppVar_32470 == 208);
	if (cppVar_32485) {
	cppVar_32469 = PSW;
	} else {
	BIT_VEC cppVar_32486;
	BIT_VEC cppVar_32487;
	BIT_VEC cppVar_32488 = PC + 1;
	cppVar_32488 = (cppVar_32488 & cppMask_un_16_);
	BIT_VEC cppVar_32489 = ROM.rd(cppVar_32488);
	BIT_VEC cppVar_32490 = (cppVar_32489 >> 7) & cppMask_un_1_;
	bool cppVar_32491 = (cppVar_32490 == 1);
	if (cppVar_32491) {
	BIT_VEC cppVar_32492 = PC + 1;
	cppVar_32492 = (cppVar_32492 & cppMask_un_16_);
	BIT_VEC cppVar_32493 = ROM.rd(cppVar_32492);
	BIT_VEC cppVar_32494 = (cppVar_32493 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_32495 = (cppVar_32494 << 3) | 0;
	cppVar_32495 = (cppVar_32495 & cppMask_un_8_);
	cppVar_32487 = cppVar_32495;
	} else {
	BIT_VEC cppVar_32496 = PC + 1;
	cppVar_32496 = (cppVar_32496 & cppMask_un_16_);
	BIT_VEC cppVar_32497 = ROM.rd(cppVar_32496);
	BIT_VEC cppVar_32498 = (cppVar_32497 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_32499 = (cppVar_32498 & cppMask_un_5_);
	BIT_VEC cppVar_32500 = cppVar_32499 + 32;
	cppVar_32500 = (cppVar_32500 & cppMask_un_8_);
	cppVar_32487 = cppVar_32500;
	}
	bool cppVar_32502 = (cppVar_32487 == 224);
	if (cppVar_32502) {
	cppVar_32486 = ACC;
	} else {
	BIT_VEC cppVar_32503;
	BIT_VEC cppVar_32504;
	BIT_VEC cppVar_32505 = PC + 1;
	cppVar_32505 = (cppVar_32505 & cppMask_un_16_);
	BIT_VEC cppVar_32506 = ROM.rd(cppVar_32505);
	BIT_VEC cppVar_32507 = (cppVar_32506 >> 7) & cppMask_un_1_;
	bool cppVar_32508 = (cppVar_32507 == 1);
	if (cppVar_32508) {
	BIT_VEC cppVar_32509 = PC + 1;
	cppVar_32509 = (cppVar_32509 & cppMask_un_16_);
	BIT_VEC cppVar_32510 = ROM.rd(cppVar_32509);
	BIT_VEC cppVar_32511 = (cppVar_32510 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_32512 = (cppVar_32511 << 3) | 0;
	cppVar_32512 = (cppVar_32512 & cppMask_un_8_);
	cppVar_32504 = cppVar_32512;
	} else {
	BIT_VEC cppVar_32513 = PC + 1;
	cppVar_32513 = (cppVar_32513 & cppMask_un_16_);
	BIT_VEC cppVar_32514 = ROM.rd(cppVar_32513);
	BIT_VEC cppVar_32515 = (cppVar_32514 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_32516 = (cppVar_32515 & cppMask_un_5_);
	BIT_VEC cppVar_32517 = cppVar_32516 + 32;
	cppVar_32517 = (cppVar_32517 & cppMask_un_8_);
	cppVar_32504 = cppVar_32517;
	}
	bool cppVar_32519 = (cppVar_32504 == 240);
	if (cppVar_32519) {
	cppVar_32503 = B;
	} else {
	cppVar_32503 = 0;
	}
	cppVar_32486 = cppVar_32503;
	}
	cppVar_32469 = cppVar_32486;
	}
	cppVar_32452 = cppVar_32469;
	}
	cppVar_32435 = cppVar_32452;
	}
	cppVar_32418 = cppVar_32435;
	}
	cppVar_32401 = cppVar_32418;
	}
	cppVar_32384 = cppVar_32401;
	}
	cppVar_32367 = cppVar_32384;
	}
	cppVar_32350 = cppVar_32367;
	}
	cppVar_32333 = cppVar_32350;
	}
	cppVar_32316 = cppVar_32333;
	}
	cppVar_32299 = cppVar_32316;
	}
	cppVar_32282 = cppVar_32299;
	}
	cppVar_32265 = cppVar_32282;
	}
	cppVar_32248 = cppVar_32265;
	}
	cppVar_32231 = cppVar_32248;
	}
	cppVar_32214 = cppVar_32231;
	}
	cppVar_32197 = cppVar_32214;
	}
	cppVar_32180 = cppVar_32197;
	}
	cppVar_32163 = cppVar_32180;
	}
	cppVar_32130 = cppVar_32163;
	}
	BIT_VEC cppVar_32521 = cppVar_32129 & cppVar_32130;
	BIT_VEC cppVar_32522;
	BIT_VEC cppVar_32523;
	BIT_VEC cppVar_32524 = PC + 1;
	cppVar_32524 = (cppVar_32524 & cppMask_un_16_);
	BIT_VEC cppVar_32525 = ROM.rd(cppVar_32524);
	BIT_VEC cppVar_32526 = (cppVar_32525 >> 7) & cppMask_un_1_;
	bool cppVar_32528 = (cppVar_32526 == 1);
	if (cppVar_32528) {
	BIT_VEC cppVar_32529 = PC + 1;
	cppVar_32529 = (cppVar_32529 & cppMask_un_16_);
	BIT_VEC cppVar_32530 = ROM.rd(cppVar_32529);
	BIT_VEC cppVar_32531 = (cppVar_32530 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_32533 = (cppVar_32531 << 3) | 0;
	cppVar_32533 = (cppVar_32533 & cppMask_un_8_);
	cppVar_32523 = cppVar_32533;
	} else {
	BIT_VEC cppVar_32534 = PC + 1;
	cppVar_32534 = (cppVar_32534 & cppMask_un_16_);
	BIT_VEC cppVar_32535 = ROM.rd(cppVar_32534);
	BIT_VEC cppVar_32536 = (cppVar_32535 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_32537 = (cppVar_32536 & cppMask_un_5_);
	BIT_VEC cppVar_32539 = cppVar_32537 + 32;
	cppVar_32539 = (cppVar_32539 & cppMask_un_8_);
	cppVar_32523 = cppVar_32539;
	}
	BIT_VEC cppVar_32540 = (cppVar_32523 >> 7) & cppMask_un_1_;
	bool cppVar_32542 = (cppVar_32540 == 0);
	if (cppVar_32542) {
	BIT_VEC cppVar_32543;
	BIT_VEC cppVar_32544 = PC + 1;
	cppVar_32544 = (cppVar_32544 & cppMask_un_16_);
	BIT_VEC cppVar_32545 = ROM.rd(cppVar_32544);
	BIT_VEC cppVar_32546 = (cppVar_32545 >> 7) & cppMask_un_1_;
	bool cppVar_32547 = (cppVar_32546 == 1);
	if (cppVar_32547) {
	BIT_VEC cppVar_32548 = PC + 1;
	cppVar_32548 = (cppVar_32548 & cppMask_un_16_);
	BIT_VEC cppVar_32549 = ROM.rd(cppVar_32548);
	BIT_VEC cppVar_32550 = (cppVar_32549 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_32551 = (cppVar_32550 << 3) | 0;
	cppVar_32551 = (cppVar_32551 & cppMask_un_8_);
	cppVar_32543 = cppVar_32551;
	} else {
	BIT_VEC cppVar_32552 = PC + 1;
	cppVar_32552 = (cppVar_32552 & cppMask_un_16_);
	BIT_VEC cppVar_32553 = ROM.rd(cppVar_32552);
	BIT_VEC cppVar_32554 = (cppVar_32553 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_32555 = (cppVar_32554 & cppMask_un_5_);
	BIT_VEC cppVar_32556 = cppVar_32555 + 32;
	cppVar_32556 = (cppVar_32556 & cppMask_un_8_);
	cppVar_32543 = cppVar_32556;
	}
	BIT_VEC cppVar_32557 = IRAM.rd(cppVar_32543);
	cppVar_32522 = cppVar_32557;
	} else {
	BIT_VEC cppVar_32558;
	BIT_VEC cppVar_32559;
	BIT_VEC cppVar_32560 = PC + 1;
	cppVar_32560 = (cppVar_32560 & cppMask_un_16_);
	BIT_VEC cppVar_32561 = ROM.rd(cppVar_32560);
	BIT_VEC cppVar_32562 = (cppVar_32561 >> 7) & cppMask_un_1_;
	bool cppVar_32563 = (cppVar_32562 == 1);
	if (cppVar_32563) {
	BIT_VEC cppVar_32564 = PC + 1;
	cppVar_32564 = (cppVar_32564 & cppMask_un_16_);
	BIT_VEC cppVar_32565 = ROM.rd(cppVar_32564);
	BIT_VEC cppVar_32566 = (cppVar_32565 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_32567 = (cppVar_32566 << 3) | 0;
	cppVar_32567 = (cppVar_32567 & cppMask_un_8_);
	cppVar_32559 = cppVar_32567;
	} else {
	BIT_VEC cppVar_32568 = PC + 1;
	cppVar_32568 = (cppVar_32568 & cppMask_un_16_);
	BIT_VEC cppVar_32569 = ROM.rd(cppVar_32568);
	BIT_VEC cppVar_32570 = (cppVar_32569 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_32571 = (cppVar_32570 & cppMask_un_5_);
	BIT_VEC cppVar_32572 = cppVar_32571 + 32;
	cppVar_32572 = (cppVar_32572 & cppMask_un_8_);
	cppVar_32559 = cppVar_32572;
	}
	bool cppVar_32574 = (cppVar_32559 == 128);
	if (cppVar_32574) {
	cppVar_32558 = P0;
	} else {
	BIT_VEC cppVar_32575;
	BIT_VEC cppVar_32576;
	BIT_VEC cppVar_32577 = PC + 1;
	cppVar_32577 = (cppVar_32577 & cppMask_un_16_);
	BIT_VEC cppVar_32578 = ROM.rd(cppVar_32577);
	BIT_VEC cppVar_32579 = (cppVar_32578 >> 7) & cppMask_un_1_;
	bool cppVar_32580 = (cppVar_32579 == 1);
	if (cppVar_32580) {
	BIT_VEC cppVar_32581 = PC + 1;
	cppVar_32581 = (cppVar_32581 & cppMask_un_16_);
	BIT_VEC cppVar_32582 = ROM.rd(cppVar_32581);
	BIT_VEC cppVar_32583 = (cppVar_32582 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_32584 = (cppVar_32583 << 3) | 0;
	cppVar_32584 = (cppVar_32584 & cppMask_un_8_);
	cppVar_32576 = cppVar_32584;
	} else {
	BIT_VEC cppVar_32585 = PC + 1;
	cppVar_32585 = (cppVar_32585 & cppMask_un_16_);
	BIT_VEC cppVar_32586 = ROM.rd(cppVar_32585);
	BIT_VEC cppVar_32587 = (cppVar_32586 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_32588 = (cppVar_32587 & cppMask_un_5_);
	BIT_VEC cppVar_32589 = cppVar_32588 + 32;
	cppVar_32589 = (cppVar_32589 & cppMask_un_8_);
	cppVar_32576 = cppVar_32589;
	}
	bool cppVar_32591 = (cppVar_32576 == 129);
	if (cppVar_32591) {
	cppVar_32575 = SP;
	} else {
	BIT_VEC cppVar_32592;
	BIT_VEC cppVar_32593;
	BIT_VEC cppVar_32594 = PC + 1;
	cppVar_32594 = (cppVar_32594 & cppMask_un_16_);
	BIT_VEC cppVar_32595 = ROM.rd(cppVar_32594);
	BIT_VEC cppVar_32596 = (cppVar_32595 >> 7) & cppMask_un_1_;
	bool cppVar_32597 = (cppVar_32596 == 1);
	if (cppVar_32597) {
	BIT_VEC cppVar_32598 = PC + 1;
	cppVar_32598 = (cppVar_32598 & cppMask_un_16_);
	BIT_VEC cppVar_32599 = ROM.rd(cppVar_32598);
	BIT_VEC cppVar_32600 = (cppVar_32599 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_32601 = (cppVar_32600 << 3) | 0;
	cppVar_32601 = (cppVar_32601 & cppMask_un_8_);
	cppVar_32593 = cppVar_32601;
	} else {
	BIT_VEC cppVar_32602 = PC + 1;
	cppVar_32602 = (cppVar_32602 & cppMask_un_16_);
	BIT_VEC cppVar_32603 = ROM.rd(cppVar_32602);
	BIT_VEC cppVar_32604 = (cppVar_32603 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_32605 = (cppVar_32604 & cppMask_un_5_);
	BIT_VEC cppVar_32606 = cppVar_32605 + 32;
	cppVar_32606 = (cppVar_32606 & cppMask_un_8_);
	cppVar_32593 = cppVar_32606;
	}
	bool cppVar_32608 = (cppVar_32593 == 130);
	if (cppVar_32608) {
	cppVar_32592 = DPL;
	} else {
	BIT_VEC cppVar_32609;
	BIT_VEC cppVar_32610;
	BIT_VEC cppVar_32611 = PC + 1;
	cppVar_32611 = (cppVar_32611 & cppMask_un_16_);
	BIT_VEC cppVar_32612 = ROM.rd(cppVar_32611);
	BIT_VEC cppVar_32613 = (cppVar_32612 >> 7) & cppMask_un_1_;
	bool cppVar_32614 = (cppVar_32613 == 1);
	if (cppVar_32614) {
	BIT_VEC cppVar_32615 = PC + 1;
	cppVar_32615 = (cppVar_32615 & cppMask_un_16_);
	BIT_VEC cppVar_32616 = ROM.rd(cppVar_32615);
	BIT_VEC cppVar_32617 = (cppVar_32616 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_32618 = (cppVar_32617 << 3) | 0;
	cppVar_32618 = (cppVar_32618 & cppMask_un_8_);
	cppVar_32610 = cppVar_32618;
	} else {
	BIT_VEC cppVar_32619 = PC + 1;
	cppVar_32619 = (cppVar_32619 & cppMask_un_16_);
	BIT_VEC cppVar_32620 = ROM.rd(cppVar_32619);
	BIT_VEC cppVar_32621 = (cppVar_32620 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_32622 = (cppVar_32621 & cppMask_un_5_);
	BIT_VEC cppVar_32623 = cppVar_32622 + 32;
	cppVar_32623 = (cppVar_32623 & cppMask_un_8_);
	cppVar_32610 = cppVar_32623;
	}
	bool cppVar_32625 = (cppVar_32610 == 131);
	if (cppVar_32625) {
	cppVar_32609 = DPH;
	} else {
	BIT_VEC cppVar_32626;
	BIT_VEC cppVar_32627;
	BIT_VEC cppVar_32628 = PC + 1;
	cppVar_32628 = (cppVar_32628 & cppMask_un_16_);
	BIT_VEC cppVar_32629 = ROM.rd(cppVar_32628);
	BIT_VEC cppVar_32630 = (cppVar_32629 >> 7) & cppMask_un_1_;
	bool cppVar_32631 = (cppVar_32630 == 1);
	if (cppVar_32631) {
	BIT_VEC cppVar_32632 = PC + 1;
	cppVar_32632 = (cppVar_32632 & cppMask_un_16_);
	BIT_VEC cppVar_32633 = ROM.rd(cppVar_32632);
	BIT_VEC cppVar_32634 = (cppVar_32633 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_32635 = (cppVar_32634 << 3) | 0;
	cppVar_32635 = (cppVar_32635 & cppMask_un_8_);
	cppVar_32627 = cppVar_32635;
	} else {
	BIT_VEC cppVar_32636 = PC + 1;
	cppVar_32636 = (cppVar_32636 & cppMask_un_16_);
	BIT_VEC cppVar_32637 = ROM.rd(cppVar_32636);
	BIT_VEC cppVar_32638 = (cppVar_32637 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_32639 = (cppVar_32638 & cppMask_un_5_);
	BIT_VEC cppVar_32640 = cppVar_32639 + 32;
	cppVar_32640 = (cppVar_32640 & cppMask_un_8_);
	cppVar_32627 = cppVar_32640;
	}
	bool cppVar_32642 = (cppVar_32627 == 135);
	if (cppVar_32642) {
	cppVar_32626 = PCON;
	} else {
	BIT_VEC cppVar_32643;
	BIT_VEC cppVar_32644;
	BIT_VEC cppVar_32645 = PC + 1;
	cppVar_32645 = (cppVar_32645 & cppMask_un_16_);
	BIT_VEC cppVar_32646 = ROM.rd(cppVar_32645);
	BIT_VEC cppVar_32647 = (cppVar_32646 >> 7) & cppMask_un_1_;
	bool cppVar_32648 = (cppVar_32647 == 1);
	if (cppVar_32648) {
	BIT_VEC cppVar_32649 = PC + 1;
	cppVar_32649 = (cppVar_32649 & cppMask_un_16_);
	BIT_VEC cppVar_32650 = ROM.rd(cppVar_32649);
	BIT_VEC cppVar_32651 = (cppVar_32650 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_32652 = (cppVar_32651 << 3) | 0;
	cppVar_32652 = (cppVar_32652 & cppMask_un_8_);
	cppVar_32644 = cppVar_32652;
	} else {
	BIT_VEC cppVar_32653 = PC + 1;
	cppVar_32653 = (cppVar_32653 & cppMask_un_16_);
	BIT_VEC cppVar_32654 = ROM.rd(cppVar_32653);
	BIT_VEC cppVar_32655 = (cppVar_32654 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_32656 = (cppVar_32655 & cppMask_un_5_);
	BIT_VEC cppVar_32657 = cppVar_32656 + 32;
	cppVar_32657 = (cppVar_32657 & cppMask_un_8_);
	cppVar_32644 = cppVar_32657;
	}
	bool cppVar_32659 = (cppVar_32644 == 136);
	if (cppVar_32659) {
	cppVar_32643 = TCON;
	} else {
	BIT_VEC cppVar_32660;
	BIT_VEC cppVar_32661;
	BIT_VEC cppVar_32662 = PC + 1;
	cppVar_32662 = (cppVar_32662 & cppMask_un_16_);
	BIT_VEC cppVar_32663 = ROM.rd(cppVar_32662);
	BIT_VEC cppVar_32664 = (cppVar_32663 >> 7) & cppMask_un_1_;
	bool cppVar_32665 = (cppVar_32664 == 1);
	if (cppVar_32665) {
	BIT_VEC cppVar_32666 = PC + 1;
	cppVar_32666 = (cppVar_32666 & cppMask_un_16_);
	BIT_VEC cppVar_32667 = ROM.rd(cppVar_32666);
	BIT_VEC cppVar_32668 = (cppVar_32667 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_32669 = (cppVar_32668 << 3) | 0;
	cppVar_32669 = (cppVar_32669 & cppMask_un_8_);
	cppVar_32661 = cppVar_32669;
	} else {
	BIT_VEC cppVar_32670 = PC + 1;
	cppVar_32670 = (cppVar_32670 & cppMask_un_16_);
	BIT_VEC cppVar_32671 = ROM.rd(cppVar_32670);
	BIT_VEC cppVar_32672 = (cppVar_32671 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_32673 = (cppVar_32672 & cppMask_un_5_);
	BIT_VEC cppVar_32674 = cppVar_32673 + 32;
	cppVar_32674 = (cppVar_32674 & cppMask_un_8_);
	cppVar_32661 = cppVar_32674;
	}
	bool cppVar_32676 = (cppVar_32661 == 137);
	if (cppVar_32676) {
	cppVar_32660 = TMOD;
	} else {
	BIT_VEC cppVar_32677;
	BIT_VEC cppVar_32678;
	BIT_VEC cppVar_32679 = PC + 1;
	cppVar_32679 = (cppVar_32679 & cppMask_un_16_);
	BIT_VEC cppVar_32680 = ROM.rd(cppVar_32679);
	BIT_VEC cppVar_32681 = (cppVar_32680 >> 7) & cppMask_un_1_;
	bool cppVar_32682 = (cppVar_32681 == 1);
	if (cppVar_32682) {
	BIT_VEC cppVar_32683 = PC + 1;
	cppVar_32683 = (cppVar_32683 & cppMask_un_16_);
	BIT_VEC cppVar_32684 = ROM.rd(cppVar_32683);
	BIT_VEC cppVar_32685 = (cppVar_32684 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_32686 = (cppVar_32685 << 3) | 0;
	cppVar_32686 = (cppVar_32686 & cppMask_un_8_);
	cppVar_32678 = cppVar_32686;
	} else {
	BIT_VEC cppVar_32687 = PC + 1;
	cppVar_32687 = (cppVar_32687 & cppMask_un_16_);
	BIT_VEC cppVar_32688 = ROM.rd(cppVar_32687);
	BIT_VEC cppVar_32689 = (cppVar_32688 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_32690 = (cppVar_32689 & cppMask_un_5_);
	BIT_VEC cppVar_32691 = cppVar_32690 + 32;
	cppVar_32691 = (cppVar_32691 & cppMask_un_8_);
	cppVar_32678 = cppVar_32691;
	}
	bool cppVar_32693 = (cppVar_32678 == 138);
	if (cppVar_32693) {
	cppVar_32677 = TL0;
	} else {
	BIT_VEC cppVar_32694;
	BIT_VEC cppVar_32695;
	BIT_VEC cppVar_32696 = PC + 1;
	cppVar_32696 = (cppVar_32696 & cppMask_un_16_);
	BIT_VEC cppVar_32697 = ROM.rd(cppVar_32696);
	BIT_VEC cppVar_32698 = (cppVar_32697 >> 7) & cppMask_un_1_;
	bool cppVar_32699 = (cppVar_32698 == 1);
	if (cppVar_32699) {
	BIT_VEC cppVar_32700 = PC + 1;
	cppVar_32700 = (cppVar_32700 & cppMask_un_16_);
	BIT_VEC cppVar_32701 = ROM.rd(cppVar_32700);
	BIT_VEC cppVar_32702 = (cppVar_32701 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_32703 = (cppVar_32702 << 3) | 0;
	cppVar_32703 = (cppVar_32703 & cppMask_un_8_);
	cppVar_32695 = cppVar_32703;
	} else {
	BIT_VEC cppVar_32704 = PC + 1;
	cppVar_32704 = (cppVar_32704 & cppMask_un_16_);
	BIT_VEC cppVar_32705 = ROM.rd(cppVar_32704);
	BIT_VEC cppVar_32706 = (cppVar_32705 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_32707 = (cppVar_32706 & cppMask_un_5_);
	BIT_VEC cppVar_32708 = cppVar_32707 + 32;
	cppVar_32708 = (cppVar_32708 & cppMask_un_8_);
	cppVar_32695 = cppVar_32708;
	}
	bool cppVar_32710 = (cppVar_32695 == 140);
	if (cppVar_32710) {
	cppVar_32694 = TH0;
	} else {
	BIT_VEC cppVar_32711;
	BIT_VEC cppVar_32712;
	BIT_VEC cppVar_32713 = PC + 1;
	cppVar_32713 = (cppVar_32713 & cppMask_un_16_);
	BIT_VEC cppVar_32714 = ROM.rd(cppVar_32713);
	BIT_VEC cppVar_32715 = (cppVar_32714 >> 7) & cppMask_un_1_;
	bool cppVar_32716 = (cppVar_32715 == 1);
	if (cppVar_32716) {
	BIT_VEC cppVar_32717 = PC + 1;
	cppVar_32717 = (cppVar_32717 & cppMask_un_16_);
	BIT_VEC cppVar_32718 = ROM.rd(cppVar_32717);
	BIT_VEC cppVar_32719 = (cppVar_32718 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_32720 = (cppVar_32719 << 3) | 0;
	cppVar_32720 = (cppVar_32720 & cppMask_un_8_);
	cppVar_32712 = cppVar_32720;
	} else {
	BIT_VEC cppVar_32721 = PC + 1;
	cppVar_32721 = (cppVar_32721 & cppMask_un_16_);
	BIT_VEC cppVar_32722 = ROM.rd(cppVar_32721);
	BIT_VEC cppVar_32723 = (cppVar_32722 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_32724 = (cppVar_32723 & cppMask_un_5_);
	BIT_VEC cppVar_32725 = cppVar_32724 + 32;
	cppVar_32725 = (cppVar_32725 & cppMask_un_8_);
	cppVar_32712 = cppVar_32725;
	}
	bool cppVar_32727 = (cppVar_32712 == 139);
	if (cppVar_32727) {
	cppVar_32711 = TL1;
	} else {
	BIT_VEC cppVar_32728;
	BIT_VEC cppVar_32729;
	BIT_VEC cppVar_32730 = PC + 1;
	cppVar_32730 = (cppVar_32730 & cppMask_un_16_);
	BIT_VEC cppVar_32731 = ROM.rd(cppVar_32730);
	BIT_VEC cppVar_32732 = (cppVar_32731 >> 7) & cppMask_un_1_;
	bool cppVar_32733 = (cppVar_32732 == 1);
	if (cppVar_32733) {
	BIT_VEC cppVar_32734 = PC + 1;
	cppVar_32734 = (cppVar_32734 & cppMask_un_16_);
	BIT_VEC cppVar_32735 = ROM.rd(cppVar_32734);
	BIT_VEC cppVar_32736 = (cppVar_32735 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_32737 = (cppVar_32736 << 3) | 0;
	cppVar_32737 = (cppVar_32737 & cppMask_un_8_);
	cppVar_32729 = cppVar_32737;
	} else {
	BIT_VEC cppVar_32738 = PC + 1;
	cppVar_32738 = (cppVar_32738 & cppMask_un_16_);
	BIT_VEC cppVar_32739 = ROM.rd(cppVar_32738);
	BIT_VEC cppVar_32740 = (cppVar_32739 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_32741 = (cppVar_32740 & cppMask_un_5_);
	BIT_VEC cppVar_32742 = cppVar_32741 + 32;
	cppVar_32742 = (cppVar_32742 & cppMask_un_8_);
	cppVar_32729 = cppVar_32742;
	}
	bool cppVar_32744 = (cppVar_32729 == 141);
	if (cppVar_32744) {
	cppVar_32728 = TH1;
	} else {
	BIT_VEC cppVar_32745;
	BIT_VEC cppVar_32746;
	BIT_VEC cppVar_32747 = PC + 1;
	cppVar_32747 = (cppVar_32747 & cppMask_un_16_);
	BIT_VEC cppVar_32748 = ROM.rd(cppVar_32747);
	BIT_VEC cppVar_32749 = (cppVar_32748 >> 7) & cppMask_un_1_;
	bool cppVar_32750 = (cppVar_32749 == 1);
	if (cppVar_32750) {
	BIT_VEC cppVar_32751 = PC + 1;
	cppVar_32751 = (cppVar_32751 & cppMask_un_16_);
	BIT_VEC cppVar_32752 = ROM.rd(cppVar_32751);
	BIT_VEC cppVar_32753 = (cppVar_32752 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_32754 = (cppVar_32753 << 3) | 0;
	cppVar_32754 = (cppVar_32754 & cppMask_un_8_);
	cppVar_32746 = cppVar_32754;
	} else {
	BIT_VEC cppVar_32755 = PC + 1;
	cppVar_32755 = (cppVar_32755 & cppMask_un_16_);
	BIT_VEC cppVar_32756 = ROM.rd(cppVar_32755);
	BIT_VEC cppVar_32757 = (cppVar_32756 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_32758 = (cppVar_32757 & cppMask_un_5_);
	BIT_VEC cppVar_32759 = cppVar_32758 + 32;
	cppVar_32759 = (cppVar_32759 & cppMask_un_8_);
	cppVar_32746 = cppVar_32759;
	}
	bool cppVar_32761 = (cppVar_32746 == 144);
	if (cppVar_32761) {
	cppVar_32745 = P1;
	} else {
	BIT_VEC cppVar_32762;
	BIT_VEC cppVar_32763;
	BIT_VEC cppVar_32764 = PC + 1;
	cppVar_32764 = (cppVar_32764 & cppMask_un_16_);
	BIT_VEC cppVar_32765 = ROM.rd(cppVar_32764);
	BIT_VEC cppVar_32766 = (cppVar_32765 >> 7) & cppMask_un_1_;
	bool cppVar_32767 = (cppVar_32766 == 1);
	if (cppVar_32767) {
	BIT_VEC cppVar_32768 = PC + 1;
	cppVar_32768 = (cppVar_32768 & cppMask_un_16_);
	BIT_VEC cppVar_32769 = ROM.rd(cppVar_32768);
	BIT_VEC cppVar_32770 = (cppVar_32769 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_32771 = (cppVar_32770 << 3) | 0;
	cppVar_32771 = (cppVar_32771 & cppMask_un_8_);
	cppVar_32763 = cppVar_32771;
	} else {
	BIT_VEC cppVar_32772 = PC + 1;
	cppVar_32772 = (cppVar_32772 & cppMask_un_16_);
	BIT_VEC cppVar_32773 = ROM.rd(cppVar_32772);
	BIT_VEC cppVar_32774 = (cppVar_32773 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_32775 = (cppVar_32774 & cppMask_un_5_);
	BIT_VEC cppVar_32776 = cppVar_32775 + 32;
	cppVar_32776 = (cppVar_32776 & cppMask_un_8_);
	cppVar_32763 = cppVar_32776;
	}
	bool cppVar_32778 = (cppVar_32763 == 152);
	if (cppVar_32778) {
	cppVar_32762 = SCON;
	} else {
	BIT_VEC cppVar_32779;
	BIT_VEC cppVar_32780;
	BIT_VEC cppVar_32781 = PC + 1;
	cppVar_32781 = (cppVar_32781 & cppMask_un_16_);
	BIT_VEC cppVar_32782 = ROM.rd(cppVar_32781);
	BIT_VEC cppVar_32783 = (cppVar_32782 >> 7) & cppMask_un_1_;
	bool cppVar_32784 = (cppVar_32783 == 1);
	if (cppVar_32784) {
	BIT_VEC cppVar_32785 = PC + 1;
	cppVar_32785 = (cppVar_32785 & cppMask_un_16_);
	BIT_VEC cppVar_32786 = ROM.rd(cppVar_32785);
	BIT_VEC cppVar_32787 = (cppVar_32786 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_32788 = (cppVar_32787 << 3) | 0;
	cppVar_32788 = (cppVar_32788 & cppMask_un_8_);
	cppVar_32780 = cppVar_32788;
	} else {
	BIT_VEC cppVar_32789 = PC + 1;
	cppVar_32789 = (cppVar_32789 & cppMask_un_16_);
	BIT_VEC cppVar_32790 = ROM.rd(cppVar_32789);
	BIT_VEC cppVar_32791 = (cppVar_32790 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_32792 = (cppVar_32791 & cppMask_un_5_);
	BIT_VEC cppVar_32793 = cppVar_32792 + 32;
	cppVar_32793 = (cppVar_32793 & cppMask_un_8_);
	cppVar_32780 = cppVar_32793;
	}
	bool cppVar_32795 = (cppVar_32780 == 153);
	if (cppVar_32795) {
	cppVar_32779 = SBUF;
	} else {
	BIT_VEC cppVar_32796;
	BIT_VEC cppVar_32797;
	BIT_VEC cppVar_32798 = PC + 1;
	cppVar_32798 = (cppVar_32798 & cppMask_un_16_);
	BIT_VEC cppVar_32799 = ROM.rd(cppVar_32798);
	BIT_VEC cppVar_32800 = (cppVar_32799 >> 7) & cppMask_un_1_;
	bool cppVar_32801 = (cppVar_32800 == 1);
	if (cppVar_32801) {
	BIT_VEC cppVar_32802 = PC + 1;
	cppVar_32802 = (cppVar_32802 & cppMask_un_16_);
	BIT_VEC cppVar_32803 = ROM.rd(cppVar_32802);
	BIT_VEC cppVar_32804 = (cppVar_32803 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_32805 = (cppVar_32804 << 3) | 0;
	cppVar_32805 = (cppVar_32805 & cppMask_un_8_);
	cppVar_32797 = cppVar_32805;
	} else {
	BIT_VEC cppVar_32806 = PC + 1;
	cppVar_32806 = (cppVar_32806 & cppMask_un_16_);
	BIT_VEC cppVar_32807 = ROM.rd(cppVar_32806);
	BIT_VEC cppVar_32808 = (cppVar_32807 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_32809 = (cppVar_32808 & cppMask_un_5_);
	BIT_VEC cppVar_32810 = cppVar_32809 + 32;
	cppVar_32810 = (cppVar_32810 & cppMask_un_8_);
	cppVar_32797 = cppVar_32810;
	}
	bool cppVar_32812 = (cppVar_32797 == 160);
	if (cppVar_32812) {
	cppVar_32796 = P2;
	} else {
	BIT_VEC cppVar_32813;
	BIT_VEC cppVar_32814;
	BIT_VEC cppVar_32815 = PC + 1;
	cppVar_32815 = (cppVar_32815 & cppMask_un_16_);
	BIT_VEC cppVar_32816 = ROM.rd(cppVar_32815);
	BIT_VEC cppVar_32817 = (cppVar_32816 >> 7) & cppMask_un_1_;
	bool cppVar_32818 = (cppVar_32817 == 1);
	if (cppVar_32818) {
	BIT_VEC cppVar_32819 = PC + 1;
	cppVar_32819 = (cppVar_32819 & cppMask_un_16_);
	BIT_VEC cppVar_32820 = ROM.rd(cppVar_32819);
	BIT_VEC cppVar_32821 = (cppVar_32820 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_32822 = (cppVar_32821 << 3) | 0;
	cppVar_32822 = (cppVar_32822 & cppMask_un_8_);
	cppVar_32814 = cppVar_32822;
	} else {
	BIT_VEC cppVar_32823 = PC + 1;
	cppVar_32823 = (cppVar_32823 & cppMask_un_16_);
	BIT_VEC cppVar_32824 = ROM.rd(cppVar_32823);
	BIT_VEC cppVar_32825 = (cppVar_32824 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_32826 = (cppVar_32825 & cppMask_un_5_);
	BIT_VEC cppVar_32827 = cppVar_32826 + 32;
	cppVar_32827 = (cppVar_32827 & cppMask_un_8_);
	cppVar_32814 = cppVar_32827;
	}
	bool cppVar_32829 = (cppVar_32814 == 168);
	if (cppVar_32829) {
	cppVar_32813 = IE;
	} else {
	BIT_VEC cppVar_32830;
	BIT_VEC cppVar_32831;
	BIT_VEC cppVar_32832 = PC + 1;
	cppVar_32832 = (cppVar_32832 & cppMask_un_16_);
	BIT_VEC cppVar_32833 = ROM.rd(cppVar_32832);
	BIT_VEC cppVar_32834 = (cppVar_32833 >> 7) & cppMask_un_1_;
	bool cppVar_32835 = (cppVar_32834 == 1);
	if (cppVar_32835) {
	BIT_VEC cppVar_32836 = PC + 1;
	cppVar_32836 = (cppVar_32836 & cppMask_un_16_);
	BIT_VEC cppVar_32837 = ROM.rd(cppVar_32836);
	BIT_VEC cppVar_32838 = (cppVar_32837 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_32839 = (cppVar_32838 << 3) | 0;
	cppVar_32839 = (cppVar_32839 & cppMask_un_8_);
	cppVar_32831 = cppVar_32839;
	} else {
	BIT_VEC cppVar_32840 = PC + 1;
	cppVar_32840 = (cppVar_32840 & cppMask_un_16_);
	BIT_VEC cppVar_32841 = ROM.rd(cppVar_32840);
	BIT_VEC cppVar_32842 = (cppVar_32841 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_32843 = (cppVar_32842 & cppMask_un_5_);
	BIT_VEC cppVar_32844 = cppVar_32843 + 32;
	cppVar_32844 = (cppVar_32844 & cppMask_un_8_);
	cppVar_32831 = cppVar_32844;
	}
	bool cppVar_32846 = (cppVar_32831 == 176);
	if (cppVar_32846) {
	cppVar_32830 = P3;
	} else {
	BIT_VEC cppVar_32847;
	BIT_VEC cppVar_32848;
	BIT_VEC cppVar_32849 = PC + 1;
	cppVar_32849 = (cppVar_32849 & cppMask_un_16_);
	BIT_VEC cppVar_32850 = ROM.rd(cppVar_32849);
	BIT_VEC cppVar_32851 = (cppVar_32850 >> 7) & cppMask_un_1_;
	bool cppVar_32852 = (cppVar_32851 == 1);
	if (cppVar_32852) {
	BIT_VEC cppVar_32853 = PC + 1;
	cppVar_32853 = (cppVar_32853 & cppMask_un_16_);
	BIT_VEC cppVar_32854 = ROM.rd(cppVar_32853);
	BIT_VEC cppVar_32855 = (cppVar_32854 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_32856 = (cppVar_32855 << 3) | 0;
	cppVar_32856 = (cppVar_32856 & cppMask_un_8_);
	cppVar_32848 = cppVar_32856;
	} else {
	BIT_VEC cppVar_32857 = PC + 1;
	cppVar_32857 = (cppVar_32857 & cppMask_un_16_);
	BIT_VEC cppVar_32858 = ROM.rd(cppVar_32857);
	BIT_VEC cppVar_32859 = (cppVar_32858 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_32860 = (cppVar_32859 & cppMask_un_5_);
	BIT_VEC cppVar_32861 = cppVar_32860 + 32;
	cppVar_32861 = (cppVar_32861 & cppMask_un_8_);
	cppVar_32848 = cppVar_32861;
	}
	bool cppVar_32863 = (cppVar_32848 == 184);
	if (cppVar_32863) {
	cppVar_32847 = IP;
	} else {
	BIT_VEC cppVar_32864;
	BIT_VEC cppVar_32865;
	BIT_VEC cppVar_32866 = PC + 1;
	cppVar_32866 = (cppVar_32866 & cppMask_un_16_);
	BIT_VEC cppVar_32867 = ROM.rd(cppVar_32866);
	BIT_VEC cppVar_32868 = (cppVar_32867 >> 7) & cppMask_un_1_;
	bool cppVar_32869 = (cppVar_32868 == 1);
	if (cppVar_32869) {
	BIT_VEC cppVar_32870 = PC + 1;
	cppVar_32870 = (cppVar_32870 & cppMask_un_16_);
	BIT_VEC cppVar_32871 = ROM.rd(cppVar_32870);
	BIT_VEC cppVar_32872 = (cppVar_32871 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_32873 = (cppVar_32872 << 3) | 0;
	cppVar_32873 = (cppVar_32873 & cppMask_un_8_);
	cppVar_32865 = cppVar_32873;
	} else {
	BIT_VEC cppVar_32874 = PC + 1;
	cppVar_32874 = (cppVar_32874 & cppMask_un_16_);
	BIT_VEC cppVar_32875 = ROM.rd(cppVar_32874);
	BIT_VEC cppVar_32876 = (cppVar_32875 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_32877 = (cppVar_32876 & cppMask_un_5_);
	BIT_VEC cppVar_32878 = cppVar_32877 + 32;
	cppVar_32878 = (cppVar_32878 & cppMask_un_8_);
	cppVar_32865 = cppVar_32878;
	}
	bool cppVar_32880 = (cppVar_32865 == 208);
	if (cppVar_32880) {
	cppVar_32864 = PSW;
	} else {
	BIT_VEC cppVar_32881;
	BIT_VEC cppVar_32882;
	BIT_VEC cppVar_32883 = PC + 1;
	cppVar_32883 = (cppVar_32883 & cppMask_un_16_);
	BIT_VEC cppVar_32884 = ROM.rd(cppVar_32883);
	BIT_VEC cppVar_32885 = (cppVar_32884 >> 7) & cppMask_un_1_;
	bool cppVar_32886 = (cppVar_32885 == 1);
	if (cppVar_32886) {
	BIT_VEC cppVar_32887 = PC + 1;
	cppVar_32887 = (cppVar_32887 & cppMask_un_16_);
	BIT_VEC cppVar_32888 = ROM.rd(cppVar_32887);
	BIT_VEC cppVar_32889 = (cppVar_32888 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_32890 = (cppVar_32889 << 3) | 0;
	cppVar_32890 = (cppVar_32890 & cppMask_un_8_);
	cppVar_32882 = cppVar_32890;
	} else {
	BIT_VEC cppVar_32891 = PC + 1;
	cppVar_32891 = (cppVar_32891 & cppMask_un_16_);
	BIT_VEC cppVar_32892 = ROM.rd(cppVar_32891);
	BIT_VEC cppVar_32893 = (cppVar_32892 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_32894 = (cppVar_32893 & cppMask_un_5_);
	BIT_VEC cppVar_32895 = cppVar_32894 + 32;
	cppVar_32895 = (cppVar_32895 & cppMask_un_8_);
	cppVar_32882 = cppVar_32895;
	}
	bool cppVar_32897 = (cppVar_32882 == 224);
	if (cppVar_32897) {
	cppVar_32881 = ACC;
	} else {
	BIT_VEC cppVar_32898;
	BIT_VEC cppVar_32899;
	BIT_VEC cppVar_32900 = PC + 1;
	cppVar_32900 = (cppVar_32900 & cppMask_un_16_);
	BIT_VEC cppVar_32901 = ROM.rd(cppVar_32900);
	BIT_VEC cppVar_32902 = (cppVar_32901 >> 7) & cppMask_un_1_;
	bool cppVar_32903 = (cppVar_32902 == 1);
	if (cppVar_32903) {
	BIT_VEC cppVar_32904 = PC + 1;
	cppVar_32904 = (cppVar_32904 & cppMask_un_16_);
	BIT_VEC cppVar_32905 = ROM.rd(cppVar_32904);
	BIT_VEC cppVar_32906 = (cppVar_32905 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_32907 = (cppVar_32906 << 3) | 0;
	cppVar_32907 = (cppVar_32907 & cppMask_un_8_);
	cppVar_32899 = cppVar_32907;
	} else {
	BIT_VEC cppVar_32908 = PC + 1;
	cppVar_32908 = (cppVar_32908 & cppMask_un_16_);
	BIT_VEC cppVar_32909 = ROM.rd(cppVar_32908);
	BIT_VEC cppVar_32910 = (cppVar_32909 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_32911 = (cppVar_32910 & cppMask_un_5_);
	BIT_VEC cppVar_32912 = cppVar_32911 + 32;
	cppVar_32912 = (cppVar_32912 & cppMask_un_8_);
	cppVar_32899 = cppVar_32912;
	}
	bool cppVar_32914 = (cppVar_32899 == 240);
	if (cppVar_32914) {
	cppVar_32898 = B;
	} else {
	cppVar_32898 = 0;
	}
	cppVar_32881 = cppVar_32898;
	}
	cppVar_32864 = cppVar_32881;
	}
	cppVar_32847 = cppVar_32864;
	}
	cppVar_32830 = cppVar_32847;
	}
	cppVar_32813 = cppVar_32830;
	}
	cppVar_32796 = cppVar_32813;
	}
	cppVar_32779 = cppVar_32796;
	}
	cppVar_32762 = cppVar_32779;
	}
	cppVar_32745 = cppVar_32762;
	}
	cppVar_32728 = cppVar_32745;
	}
	cppVar_32711 = cppVar_32728;
	}
	cppVar_32694 = cppVar_32711;
	}
	cppVar_32677 = cppVar_32694;
	}
	cppVar_32660 = cppVar_32677;
	}
	cppVar_32643 = cppVar_32660;
	}
	cppVar_32626 = cppVar_32643;
	}
	cppVar_32609 = cppVar_32626;
	}
	cppVar_32592 = cppVar_32609;
	}
	cppVar_32575 = cppVar_32592;
	}
	cppVar_32558 = cppVar_32575;
	}
	cppVar_32522 = cppVar_32558;
	}
	BIT_VEC cppVar_32916 = PC + 1;
	cppVar_32916 = (cppVar_32916 & cppMask_un_16_);
	BIT_VEC cppVar_32917 = ROM.rd(cppVar_32916);
	BIT_VEC cppVar_32918 = (cppVar_32917 >> 0) & cppMask_un_3_;
	BIT_VEC cppVar_32919 = (cppVar_32522 >> static_cast<unsigned>(cppVar_32918)) & 0x1;
	BIT_VEC cppVar_32920 = ~cppVar_32919;
	BIT_VEC cppVar_32921 = (cppVar_32920 & cppMask_un_1_);
	BIT_VEC cppVar_32922 = PC + 1;
	cppVar_32922 = (cppVar_32922 & cppMask_un_16_);
	BIT_VEC cppVar_32923 = ROM.rd(cppVar_32922);
	BIT_VEC cppVar_32924 = (cppVar_32923 >> 0) & cppMask_un_3_;
	BIT_VEC cppVar_32925 = (cppVar_32924 & cppMask_un_3_);
	BIT_VEC cppVar_32926 = cppVar_32921 << static_cast<unsigned>(cppVar_32925);
	cppVar_32926 = (cppVar_32926 & cppMask_un_8_);
	BIT_VEC cppVar_32927 = cppVar_32521 | cppVar_32926;
	cppVar_32102 = cppVar_32927;
	} else {
	cppVar_32102 = P2;
	}
	cppVar_32098 = cppVar_32102;
	} else {
	BIT_VEC cppVar_32928;
	BIT_VEC cppVar_32929 = ROM.rd(PC);
	bool cppVar_32931 = (cppVar_32929 == 146);
	if (cppVar_32931) {
	BIT_VEC cppVar_32932;
	BIT_VEC cppVar_32933;
	BIT_VEC cppVar_32935 = PC + 1;
	cppVar_32935 = (cppVar_32935 & cppMask_un_16_);
	BIT_VEC cppVar_32936 = ROM.rd(cppVar_32935);
	BIT_VEC cppVar_32937 = (cppVar_32936 >> 7) & cppMask_un_1_;
	bool cppVar_32939 = (cppVar_32937 == 1);
	if (cppVar_32939) {
	BIT_VEC cppVar_32940 = PC + 1;
	cppVar_32940 = (cppVar_32940 & cppMask_un_16_);
	BIT_VEC cppVar_32941 = ROM.rd(cppVar_32940);
	BIT_VEC cppVar_32942 = (cppVar_32941 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_32944 = (cppVar_32942 << 3) | 0;
	cppVar_32944 = (cppVar_32944 & cppMask_un_8_);
	cppVar_32933 = cppVar_32944;
	} else {
	BIT_VEC cppVar_32945 = PC + 1;
	cppVar_32945 = (cppVar_32945 & cppMask_un_16_);
	BIT_VEC cppVar_32946 = ROM.rd(cppVar_32945);
	BIT_VEC cppVar_32947 = (cppVar_32946 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_32948 = (cppVar_32947 & cppMask_un_5_);
	BIT_VEC cppVar_32950 = cppVar_32948 + 32;
	cppVar_32950 = (cppVar_32950 & cppMask_un_8_);
	cppVar_32933 = cppVar_32950;
	}
	bool cppVar_32952 = (cppVar_32933 == 160);
	if (cppVar_32952) {
	BIT_VEC cppVar_32954 = PC + 1;
	cppVar_32954 = (cppVar_32954 & cppMask_un_16_);
	BIT_VEC cppVar_32955 = ROM.rd(cppVar_32954);
	BIT_VEC cppVar_32956 = (cppVar_32955 >> 0) & cppMask_un_3_;
	BIT_VEC cppVar_32957 = (cppVar_32956 & cppMask_un_3_);
	BIT_VEC cppVar_32958 = 1 << static_cast<unsigned>(cppVar_32957);
	cppVar_32958 = (cppVar_32958 & cppMask_un_8_);
	BIT_VEC cppVar_32959 = ~cppVar_32958;
	BIT_VEC cppVar_32960;
	BIT_VEC cppVar_32961;
	BIT_VEC cppVar_32962 = PC + 1;
	cppVar_32962 = (cppVar_32962 & cppMask_un_16_);
	BIT_VEC cppVar_32963 = ROM.rd(cppVar_32962);
	BIT_VEC cppVar_32964 = (cppVar_32963 >> 7) & cppMask_un_1_;
	bool cppVar_32965 = (cppVar_32964 == 1);
	if (cppVar_32965) {
	BIT_VEC cppVar_32966 = PC + 1;
	cppVar_32966 = (cppVar_32966 & cppMask_un_16_);
	BIT_VEC cppVar_32967 = ROM.rd(cppVar_32966);
	BIT_VEC cppVar_32968 = (cppVar_32967 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_32969 = (cppVar_32968 << 3) | 0;
	cppVar_32969 = (cppVar_32969 & cppMask_un_8_);
	cppVar_32961 = cppVar_32969;
	} else {
	BIT_VEC cppVar_32970 = PC + 1;
	cppVar_32970 = (cppVar_32970 & cppMask_un_16_);
	BIT_VEC cppVar_32971 = ROM.rd(cppVar_32970);
	BIT_VEC cppVar_32972 = (cppVar_32971 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_32973 = (cppVar_32972 & cppMask_un_5_);
	BIT_VEC cppVar_32974 = cppVar_32973 + 32;
	cppVar_32974 = (cppVar_32974 & cppMask_un_8_);
	cppVar_32961 = cppVar_32974;
	}
	BIT_VEC cppVar_32975 = (cppVar_32961 >> 7) & cppMask_un_1_;
	bool cppVar_32977 = (cppVar_32975 == 0);
	if (cppVar_32977) {
	BIT_VEC cppVar_32978;
	BIT_VEC cppVar_32979 = PC + 1;
	cppVar_32979 = (cppVar_32979 & cppMask_un_16_);
	BIT_VEC cppVar_32980 = ROM.rd(cppVar_32979);
	BIT_VEC cppVar_32981 = (cppVar_32980 >> 7) & cppMask_un_1_;
	bool cppVar_32982 = (cppVar_32981 == 1);
	if (cppVar_32982) {
	BIT_VEC cppVar_32983 = PC + 1;
	cppVar_32983 = (cppVar_32983 & cppMask_un_16_);
	BIT_VEC cppVar_32984 = ROM.rd(cppVar_32983);
	BIT_VEC cppVar_32985 = (cppVar_32984 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_32986 = (cppVar_32985 << 3) | 0;
	cppVar_32986 = (cppVar_32986 & cppMask_un_8_);
	cppVar_32978 = cppVar_32986;
	} else {
	BIT_VEC cppVar_32987 = PC + 1;
	cppVar_32987 = (cppVar_32987 & cppMask_un_16_);
	BIT_VEC cppVar_32988 = ROM.rd(cppVar_32987);
	BIT_VEC cppVar_32989 = (cppVar_32988 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_32990 = (cppVar_32989 & cppMask_un_5_);
	BIT_VEC cppVar_32991 = cppVar_32990 + 32;
	cppVar_32991 = (cppVar_32991 & cppMask_un_8_);
	cppVar_32978 = cppVar_32991;
	}
	BIT_VEC cppVar_32992 = IRAM.rd(cppVar_32978);
	cppVar_32960 = cppVar_32992;
	} else {
	BIT_VEC cppVar_32993;
	BIT_VEC cppVar_32994;
	BIT_VEC cppVar_32995 = PC + 1;
	cppVar_32995 = (cppVar_32995 & cppMask_un_16_);
	BIT_VEC cppVar_32996 = ROM.rd(cppVar_32995);
	BIT_VEC cppVar_32997 = (cppVar_32996 >> 7) & cppMask_un_1_;
	bool cppVar_32998 = (cppVar_32997 == 1);
	if (cppVar_32998) {
	BIT_VEC cppVar_32999 = PC + 1;
	cppVar_32999 = (cppVar_32999 & cppMask_un_16_);
	BIT_VEC cppVar_33000 = ROM.rd(cppVar_32999);
	BIT_VEC cppVar_33001 = (cppVar_33000 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_33002 = (cppVar_33001 << 3) | 0;
	cppVar_33002 = (cppVar_33002 & cppMask_un_8_);
	cppVar_32994 = cppVar_33002;
	} else {
	BIT_VEC cppVar_33003 = PC + 1;
	cppVar_33003 = (cppVar_33003 & cppMask_un_16_);
	BIT_VEC cppVar_33004 = ROM.rd(cppVar_33003);
	BIT_VEC cppVar_33005 = (cppVar_33004 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_33006 = (cppVar_33005 & cppMask_un_5_);
	BIT_VEC cppVar_33007 = cppVar_33006 + 32;
	cppVar_33007 = (cppVar_33007 & cppMask_un_8_);
	cppVar_32994 = cppVar_33007;
	}
	bool cppVar_33009 = (cppVar_32994 == 128);
	if (cppVar_33009) {
	cppVar_32993 = P0;
	} else {
	BIT_VEC cppVar_33010;
	BIT_VEC cppVar_33011;
	BIT_VEC cppVar_33012 = PC + 1;
	cppVar_33012 = (cppVar_33012 & cppMask_un_16_);
	BIT_VEC cppVar_33013 = ROM.rd(cppVar_33012);
	BIT_VEC cppVar_33014 = (cppVar_33013 >> 7) & cppMask_un_1_;
	bool cppVar_33015 = (cppVar_33014 == 1);
	if (cppVar_33015) {
	BIT_VEC cppVar_33016 = PC + 1;
	cppVar_33016 = (cppVar_33016 & cppMask_un_16_);
	BIT_VEC cppVar_33017 = ROM.rd(cppVar_33016);
	BIT_VEC cppVar_33018 = (cppVar_33017 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_33019 = (cppVar_33018 << 3) | 0;
	cppVar_33019 = (cppVar_33019 & cppMask_un_8_);
	cppVar_33011 = cppVar_33019;
	} else {
	BIT_VEC cppVar_33020 = PC + 1;
	cppVar_33020 = (cppVar_33020 & cppMask_un_16_);
	BIT_VEC cppVar_33021 = ROM.rd(cppVar_33020);
	BIT_VEC cppVar_33022 = (cppVar_33021 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_33023 = (cppVar_33022 & cppMask_un_5_);
	BIT_VEC cppVar_33024 = cppVar_33023 + 32;
	cppVar_33024 = (cppVar_33024 & cppMask_un_8_);
	cppVar_33011 = cppVar_33024;
	}
	bool cppVar_33026 = (cppVar_33011 == 129);
	if (cppVar_33026) {
	cppVar_33010 = SP;
	} else {
	BIT_VEC cppVar_33027;
	BIT_VEC cppVar_33028;
	BIT_VEC cppVar_33029 = PC + 1;
	cppVar_33029 = (cppVar_33029 & cppMask_un_16_);
	BIT_VEC cppVar_33030 = ROM.rd(cppVar_33029);
	BIT_VEC cppVar_33031 = (cppVar_33030 >> 7) & cppMask_un_1_;
	bool cppVar_33032 = (cppVar_33031 == 1);
	if (cppVar_33032) {
	BIT_VEC cppVar_33033 = PC + 1;
	cppVar_33033 = (cppVar_33033 & cppMask_un_16_);
	BIT_VEC cppVar_33034 = ROM.rd(cppVar_33033);
	BIT_VEC cppVar_33035 = (cppVar_33034 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_33036 = (cppVar_33035 << 3) | 0;
	cppVar_33036 = (cppVar_33036 & cppMask_un_8_);
	cppVar_33028 = cppVar_33036;
	} else {
	BIT_VEC cppVar_33037 = PC + 1;
	cppVar_33037 = (cppVar_33037 & cppMask_un_16_);
	BIT_VEC cppVar_33038 = ROM.rd(cppVar_33037);
	BIT_VEC cppVar_33039 = (cppVar_33038 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_33040 = (cppVar_33039 & cppMask_un_5_);
	BIT_VEC cppVar_33041 = cppVar_33040 + 32;
	cppVar_33041 = (cppVar_33041 & cppMask_un_8_);
	cppVar_33028 = cppVar_33041;
	}
	bool cppVar_33043 = (cppVar_33028 == 130);
	if (cppVar_33043) {
	cppVar_33027 = DPL;
	} else {
	BIT_VEC cppVar_33044;
	BIT_VEC cppVar_33045;
	BIT_VEC cppVar_33046 = PC + 1;
	cppVar_33046 = (cppVar_33046 & cppMask_un_16_);
	BIT_VEC cppVar_33047 = ROM.rd(cppVar_33046);
	BIT_VEC cppVar_33048 = (cppVar_33047 >> 7) & cppMask_un_1_;
	bool cppVar_33049 = (cppVar_33048 == 1);
	if (cppVar_33049) {
	BIT_VEC cppVar_33050 = PC + 1;
	cppVar_33050 = (cppVar_33050 & cppMask_un_16_);
	BIT_VEC cppVar_33051 = ROM.rd(cppVar_33050);
	BIT_VEC cppVar_33052 = (cppVar_33051 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_33053 = (cppVar_33052 << 3) | 0;
	cppVar_33053 = (cppVar_33053 & cppMask_un_8_);
	cppVar_33045 = cppVar_33053;
	} else {
	BIT_VEC cppVar_33054 = PC + 1;
	cppVar_33054 = (cppVar_33054 & cppMask_un_16_);
	BIT_VEC cppVar_33055 = ROM.rd(cppVar_33054);
	BIT_VEC cppVar_33056 = (cppVar_33055 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_33057 = (cppVar_33056 & cppMask_un_5_);
	BIT_VEC cppVar_33058 = cppVar_33057 + 32;
	cppVar_33058 = (cppVar_33058 & cppMask_un_8_);
	cppVar_33045 = cppVar_33058;
	}
	bool cppVar_33060 = (cppVar_33045 == 131);
	if (cppVar_33060) {
	cppVar_33044 = DPH;
	} else {
	BIT_VEC cppVar_33061;
	BIT_VEC cppVar_33062;
	BIT_VEC cppVar_33063 = PC + 1;
	cppVar_33063 = (cppVar_33063 & cppMask_un_16_);
	BIT_VEC cppVar_33064 = ROM.rd(cppVar_33063);
	BIT_VEC cppVar_33065 = (cppVar_33064 >> 7) & cppMask_un_1_;
	bool cppVar_33066 = (cppVar_33065 == 1);
	if (cppVar_33066) {
	BIT_VEC cppVar_33067 = PC + 1;
	cppVar_33067 = (cppVar_33067 & cppMask_un_16_);
	BIT_VEC cppVar_33068 = ROM.rd(cppVar_33067);
	BIT_VEC cppVar_33069 = (cppVar_33068 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_33070 = (cppVar_33069 << 3) | 0;
	cppVar_33070 = (cppVar_33070 & cppMask_un_8_);
	cppVar_33062 = cppVar_33070;
	} else {
	BIT_VEC cppVar_33071 = PC + 1;
	cppVar_33071 = (cppVar_33071 & cppMask_un_16_);
	BIT_VEC cppVar_33072 = ROM.rd(cppVar_33071);
	BIT_VEC cppVar_33073 = (cppVar_33072 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_33074 = (cppVar_33073 & cppMask_un_5_);
	BIT_VEC cppVar_33075 = cppVar_33074 + 32;
	cppVar_33075 = (cppVar_33075 & cppMask_un_8_);
	cppVar_33062 = cppVar_33075;
	}
	bool cppVar_33077 = (cppVar_33062 == 135);
	if (cppVar_33077) {
	cppVar_33061 = PCON;
	} else {
	BIT_VEC cppVar_33078;
	BIT_VEC cppVar_33079;
	BIT_VEC cppVar_33080 = PC + 1;
	cppVar_33080 = (cppVar_33080 & cppMask_un_16_);
	BIT_VEC cppVar_33081 = ROM.rd(cppVar_33080);
	BIT_VEC cppVar_33082 = (cppVar_33081 >> 7) & cppMask_un_1_;
	bool cppVar_33083 = (cppVar_33082 == 1);
	if (cppVar_33083) {
	BIT_VEC cppVar_33084 = PC + 1;
	cppVar_33084 = (cppVar_33084 & cppMask_un_16_);
	BIT_VEC cppVar_33085 = ROM.rd(cppVar_33084);
	BIT_VEC cppVar_33086 = (cppVar_33085 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_33087 = (cppVar_33086 << 3) | 0;
	cppVar_33087 = (cppVar_33087 & cppMask_un_8_);
	cppVar_33079 = cppVar_33087;
	} else {
	BIT_VEC cppVar_33088 = PC + 1;
	cppVar_33088 = (cppVar_33088 & cppMask_un_16_);
	BIT_VEC cppVar_33089 = ROM.rd(cppVar_33088);
	BIT_VEC cppVar_33090 = (cppVar_33089 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_33091 = (cppVar_33090 & cppMask_un_5_);
	BIT_VEC cppVar_33092 = cppVar_33091 + 32;
	cppVar_33092 = (cppVar_33092 & cppMask_un_8_);
	cppVar_33079 = cppVar_33092;
	}
	bool cppVar_33094 = (cppVar_33079 == 136);
	if (cppVar_33094) {
	cppVar_33078 = TCON;
	} else {
	BIT_VEC cppVar_33095;
	BIT_VEC cppVar_33096;
	BIT_VEC cppVar_33097 = PC + 1;
	cppVar_33097 = (cppVar_33097 & cppMask_un_16_);
	BIT_VEC cppVar_33098 = ROM.rd(cppVar_33097);
	BIT_VEC cppVar_33099 = (cppVar_33098 >> 7) & cppMask_un_1_;
	bool cppVar_33100 = (cppVar_33099 == 1);
	if (cppVar_33100) {
	BIT_VEC cppVar_33101 = PC + 1;
	cppVar_33101 = (cppVar_33101 & cppMask_un_16_);
	BIT_VEC cppVar_33102 = ROM.rd(cppVar_33101);
	BIT_VEC cppVar_33103 = (cppVar_33102 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_33104 = (cppVar_33103 << 3) | 0;
	cppVar_33104 = (cppVar_33104 & cppMask_un_8_);
	cppVar_33096 = cppVar_33104;
	} else {
	BIT_VEC cppVar_33105 = PC + 1;
	cppVar_33105 = (cppVar_33105 & cppMask_un_16_);
	BIT_VEC cppVar_33106 = ROM.rd(cppVar_33105);
	BIT_VEC cppVar_33107 = (cppVar_33106 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_33108 = (cppVar_33107 & cppMask_un_5_);
	BIT_VEC cppVar_33109 = cppVar_33108 + 32;
	cppVar_33109 = (cppVar_33109 & cppMask_un_8_);
	cppVar_33096 = cppVar_33109;
	}
	bool cppVar_33111 = (cppVar_33096 == 137);
	if (cppVar_33111) {
	cppVar_33095 = TMOD;
	} else {
	BIT_VEC cppVar_33112;
	BIT_VEC cppVar_33113;
	BIT_VEC cppVar_33114 = PC + 1;
	cppVar_33114 = (cppVar_33114 & cppMask_un_16_);
	BIT_VEC cppVar_33115 = ROM.rd(cppVar_33114);
	BIT_VEC cppVar_33116 = (cppVar_33115 >> 7) & cppMask_un_1_;
	bool cppVar_33117 = (cppVar_33116 == 1);
	if (cppVar_33117) {
	BIT_VEC cppVar_33118 = PC + 1;
	cppVar_33118 = (cppVar_33118 & cppMask_un_16_);
	BIT_VEC cppVar_33119 = ROM.rd(cppVar_33118);
	BIT_VEC cppVar_33120 = (cppVar_33119 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_33121 = (cppVar_33120 << 3) | 0;
	cppVar_33121 = (cppVar_33121 & cppMask_un_8_);
	cppVar_33113 = cppVar_33121;
	} else {
	BIT_VEC cppVar_33122 = PC + 1;
	cppVar_33122 = (cppVar_33122 & cppMask_un_16_);
	BIT_VEC cppVar_33123 = ROM.rd(cppVar_33122);
	BIT_VEC cppVar_33124 = (cppVar_33123 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_33125 = (cppVar_33124 & cppMask_un_5_);
	BIT_VEC cppVar_33126 = cppVar_33125 + 32;
	cppVar_33126 = (cppVar_33126 & cppMask_un_8_);
	cppVar_33113 = cppVar_33126;
	}
	bool cppVar_33128 = (cppVar_33113 == 138);
	if (cppVar_33128) {
	cppVar_33112 = TL0;
	} else {
	BIT_VEC cppVar_33129;
	BIT_VEC cppVar_33130;
	BIT_VEC cppVar_33131 = PC + 1;
	cppVar_33131 = (cppVar_33131 & cppMask_un_16_);
	BIT_VEC cppVar_33132 = ROM.rd(cppVar_33131);
	BIT_VEC cppVar_33133 = (cppVar_33132 >> 7) & cppMask_un_1_;
	bool cppVar_33134 = (cppVar_33133 == 1);
	if (cppVar_33134) {
	BIT_VEC cppVar_33135 = PC + 1;
	cppVar_33135 = (cppVar_33135 & cppMask_un_16_);
	BIT_VEC cppVar_33136 = ROM.rd(cppVar_33135);
	BIT_VEC cppVar_33137 = (cppVar_33136 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_33138 = (cppVar_33137 << 3) | 0;
	cppVar_33138 = (cppVar_33138 & cppMask_un_8_);
	cppVar_33130 = cppVar_33138;
	} else {
	BIT_VEC cppVar_33139 = PC + 1;
	cppVar_33139 = (cppVar_33139 & cppMask_un_16_);
	BIT_VEC cppVar_33140 = ROM.rd(cppVar_33139);
	BIT_VEC cppVar_33141 = (cppVar_33140 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_33142 = (cppVar_33141 & cppMask_un_5_);
	BIT_VEC cppVar_33143 = cppVar_33142 + 32;
	cppVar_33143 = (cppVar_33143 & cppMask_un_8_);
	cppVar_33130 = cppVar_33143;
	}
	bool cppVar_33145 = (cppVar_33130 == 140);
	if (cppVar_33145) {
	cppVar_33129 = TH0;
	} else {
	BIT_VEC cppVar_33146;
	BIT_VEC cppVar_33147;
	BIT_VEC cppVar_33148 = PC + 1;
	cppVar_33148 = (cppVar_33148 & cppMask_un_16_);
	BIT_VEC cppVar_33149 = ROM.rd(cppVar_33148);
	BIT_VEC cppVar_33150 = (cppVar_33149 >> 7) & cppMask_un_1_;
	bool cppVar_33151 = (cppVar_33150 == 1);
	if (cppVar_33151) {
	BIT_VEC cppVar_33152 = PC + 1;
	cppVar_33152 = (cppVar_33152 & cppMask_un_16_);
	BIT_VEC cppVar_33153 = ROM.rd(cppVar_33152);
	BIT_VEC cppVar_33154 = (cppVar_33153 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_33155 = (cppVar_33154 << 3) | 0;
	cppVar_33155 = (cppVar_33155 & cppMask_un_8_);
	cppVar_33147 = cppVar_33155;
	} else {
	BIT_VEC cppVar_33156 = PC + 1;
	cppVar_33156 = (cppVar_33156 & cppMask_un_16_);
	BIT_VEC cppVar_33157 = ROM.rd(cppVar_33156);
	BIT_VEC cppVar_33158 = (cppVar_33157 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_33159 = (cppVar_33158 & cppMask_un_5_);
	BIT_VEC cppVar_33160 = cppVar_33159 + 32;
	cppVar_33160 = (cppVar_33160 & cppMask_un_8_);
	cppVar_33147 = cppVar_33160;
	}
	bool cppVar_33162 = (cppVar_33147 == 139);
	if (cppVar_33162) {
	cppVar_33146 = TL1;
	} else {
	BIT_VEC cppVar_33163;
	BIT_VEC cppVar_33164;
	BIT_VEC cppVar_33165 = PC + 1;
	cppVar_33165 = (cppVar_33165 & cppMask_un_16_);
	BIT_VEC cppVar_33166 = ROM.rd(cppVar_33165);
	BIT_VEC cppVar_33167 = (cppVar_33166 >> 7) & cppMask_un_1_;
	bool cppVar_33168 = (cppVar_33167 == 1);
	if (cppVar_33168) {
	BIT_VEC cppVar_33169 = PC + 1;
	cppVar_33169 = (cppVar_33169 & cppMask_un_16_);
	BIT_VEC cppVar_33170 = ROM.rd(cppVar_33169);
	BIT_VEC cppVar_33171 = (cppVar_33170 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_33172 = (cppVar_33171 << 3) | 0;
	cppVar_33172 = (cppVar_33172 & cppMask_un_8_);
	cppVar_33164 = cppVar_33172;
	} else {
	BIT_VEC cppVar_33173 = PC + 1;
	cppVar_33173 = (cppVar_33173 & cppMask_un_16_);
	BIT_VEC cppVar_33174 = ROM.rd(cppVar_33173);
	BIT_VEC cppVar_33175 = (cppVar_33174 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_33176 = (cppVar_33175 & cppMask_un_5_);
	BIT_VEC cppVar_33177 = cppVar_33176 + 32;
	cppVar_33177 = (cppVar_33177 & cppMask_un_8_);
	cppVar_33164 = cppVar_33177;
	}
	bool cppVar_33179 = (cppVar_33164 == 141);
	if (cppVar_33179) {
	cppVar_33163 = TH1;
	} else {
	BIT_VEC cppVar_33180;
	BIT_VEC cppVar_33181;
	BIT_VEC cppVar_33182 = PC + 1;
	cppVar_33182 = (cppVar_33182 & cppMask_un_16_);
	BIT_VEC cppVar_33183 = ROM.rd(cppVar_33182);
	BIT_VEC cppVar_33184 = (cppVar_33183 >> 7) & cppMask_un_1_;
	bool cppVar_33185 = (cppVar_33184 == 1);
	if (cppVar_33185) {
	BIT_VEC cppVar_33186 = PC + 1;
	cppVar_33186 = (cppVar_33186 & cppMask_un_16_);
	BIT_VEC cppVar_33187 = ROM.rd(cppVar_33186);
	BIT_VEC cppVar_33188 = (cppVar_33187 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_33189 = (cppVar_33188 << 3) | 0;
	cppVar_33189 = (cppVar_33189 & cppMask_un_8_);
	cppVar_33181 = cppVar_33189;
	} else {
	BIT_VEC cppVar_33190 = PC + 1;
	cppVar_33190 = (cppVar_33190 & cppMask_un_16_);
	BIT_VEC cppVar_33191 = ROM.rd(cppVar_33190);
	BIT_VEC cppVar_33192 = (cppVar_33191 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_33193 = (cppVar_33192 & cppMask_un_5_);
	BIT_VEC cppVar_33194 = cppVar_33193 + 32;
	cppVar_33194 = (cppVar_33194 & cppMask_un_8_);
	cppVar_33181 = cppVar_33194;
	}
	bool cppVar_33196 = (cppVar_33181 == 144);
	if (cppVar_33196) {
	cppVar_33180 = P1;
	} else {
	BIT_VEC cppVar_33197;
	BIT_VEC cppVar_33198;
	BIT_VEC cppVar_33199 = PC + 1;
	cppVar_33199 = (cppVar_33199 & cppMask_un_16_);
	BIT_VEC cppVar_33200 = ROM.rd(cppVar_33199);
	BIT_VEC cppVar_33201 = (cppVar_33200 >> 7) & cppMask_un_1_;
	bool cppVar_33202 = (cppVar_33201 == 1);
	if (cppVar_33202) {
	BIT_VEC cppVar_33203 = PC + 1;
	cppVar_33203 = (cppVar_33203 & cppMask_un_16_);
	BIT_VEC cppVar_33204 = ROM.rd(cppVar_33203);
	BIT_VEC cppVar_33205 = (cppVar_33204 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_33206 = (cppVar_33205 << 3) | 0;
	cppVar_33206 = (cppVar_33206 & cppMask_un_8_);
	cppVar_33198 = cppVar_33206;
	} else {
	BIT_VEC cppVar_33207 = PC + 1;
	cppVar_33207 = (cppVar_33207 & cppMask_un_16_);
	BIT_VEC cppVar_33208 = ROM.rd(cppVar_33207);
	BIT_VEC cppVar_33209 = (cppVar_33208 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_33210 = (cppVar_33209 & cppMask_un_5_);
	BIT_VEC cppVar_33211 = cppVar_33210 + 32;
	cppVar_33211 = (cppVar_33211 & cppMask_un_8_);
	cppVar_33198 = cppVar_33211;
	}
	bool cppVar_33213 = (cppVar_33198 == 152);
	if (cppVar_33213) {
	cppVar_33197 = SCON;
	} else {
	BIT_VEC cppVar_33214;
	BIT_VEC cppVar_33215;
	BIT_VEC cppVar_33216 = PC + 1;
	cppVar_33216 = (cppVar_33216 & cppMask_un_16_);
	BIT_VEC cppVar_33217 = ROM.rd(cppVar_33216);
	BIT_VEC cppVar_33218 = (cppVar_33217 >> 7) & cppMask_un_1_;
	bool cppVar_33219 = (cppVar_33218 == 1);
	if (cppVar_33219) {
	BIT_VEC cppVar_33220 = PC + 1;
	cppVar_33220 = (cppVar_33220 & cppMask_un_16_);
	BIT_VEC cppVar_33221 = ROM.rd(cppVar_33220);
	BIT_VEC cppVar_33222 = (cppVar_33221 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_33223 = (cppVar_33222 << 3) | 0;
	cppVar_33223 = (cppVar_33223 & cppMask_un_8_);
	cppVar_33215 = cppVar_33223;
	} else {
	BIT_VEC cppVar_33224 = PC + 1;
	cppVar_33224 = (cppVar_33224 & cppMask_un_16_);
	BIT_VEC cppVar_33225 = ROM.rd(cppVar_33224);
	BIT_VEC cppVar_33226 = (cppVar_33225 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_33227 = (cppVar_33226 & cppMask_un_5_);
	BIT_VEC cppVar_33228 = cppVar_33227 + 32;
	cppVar_33228 = (cppVar_33228 & cppMask_un_8_);
	cppVar_33215 = cppVar_33228;
	}
	bool cppVar_33230 = (cppVar_33215 == 153);
	if (cppVar_33230) {
	cppVar_33214 = SBUF;
	} else {
	BIT_VEC cppVar_33231;
	BIT_VEC cppVar_33232;
	BIT_VEC cppVar_33233 = PC + 1;
	cppVar_33233 = (cppVar_33233 & cppMask_un_16_);
	BIT_VEC cppVar_33234 = ROM.rd(cppVar_33233);
	BIT_VEC cppVar_33235 = (cppVar_33234 >> 7) & cppMask_un_1_;
	bool cppVar_33236 = (cppVar_33235 == 1);
	if (cppVar_33236) {
	BIT_VEC cppVar_33237 = PC + 1;
	cppVar_33237 = (cppVar_33237 & cppMask_un_16_);
	BIT_VEC cppVar_33238 = ROM.rd(cppVar_33237);
	BIT_VEC cppVar_33239 = (cppVar_33238 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_33240 = (cppVar_33239 << 3) | 0;
	cppVar_33240 = (cppVar_33240 & cppMask_un_8_);
	cppVar_33232 = cppVar_33240;
	} else {
	BIT_VEC cppVar_33241 = PC + 1;
	cppVar_33241 = (cppVar_33241 & cppMask_un_16_);
	BIT_VEC cppVar_33242 = ROM.rd(cppVar_33241);
	BIT_VEC cppVar_33243 = (cppVar_33242 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_33244 = (cppVar_33243 & cppMask_un_5_);
	BIT_VEC cppVar_33245 = cppVar_33244 + 32;
	cppVar_33245 = (cppVar_33245 & cppMask_un_8_);
	cppVar_33232 = cppVar_33245;
	}
	bool cppVar_33247 = (cppVar_33232 == 160);
	if (cppVar_33247) {
	cppVar_33231 = P2;
	} else {
	BIT_VEC cppVar_33248;
	BIT_VEC cppVar_33249;
	BIT_VEC cppVar_33250 = PC + 1;
	cppVar_33250 = (cppVar_33250 & cppMask_un_16_);
	BIT_VEC cppVar_33251 = ROM.rd(cppVar_33250);
	BIT_VEC cppVar_33252 = (cppVar_33251 >> 7) & cppMask_un_1_;
	bool cppVar_33253 = (cppVar_33252 == 1);
	if (cppVar_33253) {
	BIT_VEC cppVar_33254 = PC + 1;
	cppVar_33254 = (cppVar_33254 & cppMask_un_16_);
	BIT_VEC cppVar_33255 = ROM.rd(cppVar_33254);
	BIT_VEC cppVar_33256 = (cppVar_33255 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_33257 = (cppVar_33256 << 3) | 0;
	cppVar_33257 = (cppVar_33257 & cppMask_un_8_);
	cppVar_33249 = cppVar_33257;
	} else {
	BIT_VEC cppVar_33258 = PC + 1;
	cppVar_33258 = (cppVar_33258 & cppMask_un_16_);
	BIT_VEC cppVar_33259 = ROM.rd(cppVar_33258);
	BIT_VEC cppVar_33260 = (cppVar_33259 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_33261 = (cppVar_33260 & cppMask_un_5_);
	BIT_VEC cppVar_33262 = cppVar_33261 + 32;
	cppVar_33262 = (cppVar_33262 & cppMask_un_8_);
	cppVar_33249 = cppVar_33262;
	}
	bool cppVar_33264 = (cppVar_33249 == 168);
	if (cppVar_33264) {
	cppVar_33248 = IE;
	} else {
	BIT_VEC cppVar_33265;
	BIT_VEC cppVar_33266;
	BIT_VEC cppVar_33267 = PC + 1;
	cppVar_33267 = (cppVar_33267 & cppMask_un_16_);
	BIT_VEC cppVar_33268 = ROM.rd(cppVar_33267);
	BIT_VEC cppVar_33269 = (cppVar_33268 >> 7) & cppMask_un_1_;
	bool cppVar_33270 = (cppVar_33269 == 1);
	if (cppVar_33270) {
	BIT_VEC cppVar_33271 = PC + 1;
	cppVar_33271 = (cppVar_33271 & cppMask_un_16_);
	BIT_VEC cppVar_33272 = ROM.rd(cppVar_33271);
	BIT_VEC cppVar_33273 = (cppVar_33272 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_33274 = (cppVar_33273 << 3) | 0;
	cppVar_33274 = (cppVar_33274 & cppMask_un_8_);
	cppVar_33266 = cppVar_33274;
	} else {
	BIT_VEC cppVar_33275 = PC + 1;
	cppVar_33275 = (cppVar_33275 & cppMask_un_16_);
	BIT_VEC cppVar_33276 = ROM.rd(cppVar_33275);
	BIT_VEC cppVar_33277 = (cppVar_33276 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_33278 = (cppVar_33277 & cppMask_un_5_);
	BIT_VEC cppVar_33279 = cppVar_33278 + 32;
	cppVar_33279 = (cppVar_33279 & cppMask_un_8_);
	cppVar_33266 = cppVar_33279;
	}
	bool cppVar_33281 = (cppVar_33266 == 176);
	if (cppVar_33281) {
	cppVar_33265 = P3;
	} else {
	BIT_VEC cppVar_33282;
	BIT_VEC cppVar_33283;
	BIT_VEC cppVar_33284 = PC + 1;
	cppVar_33284 = (cppVar_33284 & cppMask_un_16_);
	BIT_VEC cppVar_33285 = ROM.rd(cppVar_33284);
	BIT_VEC cppVar_33286 = (cppVar_33285 >> 7) & cppMask_un_1_;
	bool cppVar_33287 = (cppVar_33286 == 1);
	if (cppVar_33287) {
	BIT_VEC cppVar_33288 = PC + 1;
	cppVar_33288 = (cppVar_33288 & cppMask_un_16_);
	BIT_VEC cppVar_33289 = ROM.rd(cppVar_33288);
	BIT_VEC cppVar_33290 = (cppVar_33289 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_33291 = (cppVar_33290 << 3) | 0;
	cppVar_33291 = (cppVar_33291 & cppMask_un_8_);
	cppVar_33283 = cppVar_33291;
	} else {
	BIT_VEC cppVar_33292 = PC + 1;
	cppVar_33292 = (cppVar_33292 & cppMask_un_16_);
	BIT_VEC cppVar_33293 = ROM.rd(cppVar_33292);
	BIT_VEC cppVar_33294 = (cppVar_33293 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_33295 = (cppVar_33294 & cppMask_un_5_);
	BIT_VEC cppVar_33296 = cppVar_33295 + 32;
	cppVar_33296 = (cppVar_33296 & cppMask_un_8_);
	cppVar_33283 = cppVar_33296;
	}
	bool cppVar_33298 = (cppVar_33283 == 184);
	if (cppVar_33298) {
	cppVar_33282 = IP;
	} else {
	BIT_VEC cppVar_33299;
	BIT_VEC cppVar_33300;
	BIT_VEC cppVar_33301 = PC + 1;
	cppVar_33301 = (cppVar_33301 & cppMask_un_16_);
	BIT_VEC cppVar_33302 = ROM.rd(cppVar_33301);
	BIT_VEC cppVar_33303 = (cppVar_33302 >> 7) & cppMask_un_1_;
	bool cppVar_33304 = (cppVar_33303 == 1);
	if (cppVar_33304) {
	BIT_VEC cppVar_33305 = PC + 1;
	cppVar_33305 = (cppVar_33305 & cppMask_un_16_);
	BIT_VEC cppVar_33306 = ROM.rd(cppVar_33305);
	BIT_VEC cppVar_33307 = (cppVar_33306 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_33308 = (cppVar_33307 << 3) | 0;
	cppVar_33308 = (cppVar_33308 & cppMask_un_8_);
	cppVar_33300 = cppVar_33308;
	} else {
	BIT_VEC cppVar_33309 = PC + 1;
	cppVar_33309 = (cppVar_33309 & cppMask_un_16_);
	BIT_VEC cppVar_33310 = ROM.rd(cppVar_33309);
	BIT_VEC cppVar_33311 = (cppVar_33310 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_33312 = (cppVar_33311 & cppMask_un_5_);
	BIT_VEC cppVar_33313 = cppVar_33312 + 32;
	cppVar_33313 = (cppVar_33313 & cppMask_un_8_);
	cppVar_33300 = cppVar_33313;
	}
	bool cppVar_33315 = (cppVar_33300 == 208);
	if (cppVar_33315) {
	cppVar_33299 = PSW;
	} else {
	BIT_VEC cppVar_33316;
	BIT_VEC cppVar_33317;
	BIT_VEC cppVar_33318 = PC + 1;
	cppVar_33318 = (cppVar_33318 & cppMask_un_16_);
	BIT_VEC cppVar_33319 = ROM.rd(cppVar_33318);
	BIT_VEC cppVar_33320 = (cppVar_33319 >> 7) & cppMask_un_1_;
	bool cppVar_33321 = (cppVar_33320 == 1);
	if (cppVar_33321) {
	BIT_VEC cppVar_33322 = PC + 1;
	cppVar_33322 = (cppVar_33322 & cppMask_un_16_);
	BIT_VEC cppVar_33323 = ROM.rd(cppVar_33322);
	BIT_VEC cppVar_33324 = (cppVar_33323 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_33325 = (cppVar_33324 << 3) | 0;
	cppVar_33325 = (cppVar_33325 & cppMask_un_8_);
	cppVar_33317 = cppVar_33325;
	} else {
	BIT_VEC cppVar_33326 = PC + 1;
	cppVar_33326 = (cppVar_33326 & cppMask_un_16_);
	BIT_VEC cppVar_33327 = ROM.rd(cppVar_33326);
	BIT_VEC cppVar_33328 = (cppVar_33327 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_33329 = (cppVar_33328 & cppMask_un_5_);
	BIT_VEC cppVar_33330 = cppVar_33329 + 32;
	cppVar_33330 = (cppVar_33330 & cppMask_un_8_);
	cppVar_33317 = cppVar_33330;
	}
	bool cppVar_33332 = (cppVar_33317 == 224);
	if (cppVar_33332) {
	cppVar_33316 = ACC;
	} else {
	BIT_VEC cppVar_33333;
	BIT_VEC cppVar_33334;
	BIT_VEC cppVar_33335 = PC + 1;
	cppVar_33335 = (cppVar_33335 & cppMask_un_16_);
	BIT_VEC cppVar_33336 = ROM.rd(cppVar_33335);
	BIT_VEC cppVar_33337 = (cppVar_33336 >> 7) & cppMask_un_1_;
	bool cppVar_33338 = (cppVar_33337 == 1);
	if (cppVar_33338) {
	BIT_VEC cppVar_33339 = PC + 1;
	cppVar_33339 = (cppVar_33339 & cppMask_un_16_);
	BIT_VEC cppVar_33340 = ROM.rd(cppVar_33339);
	BIT_VEC cppVar_33341 = (cppVar_33340 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_33342 = (cppVar_33341 << 3) | 0;
	cppVar_33342 = (cppVar_33342 & cppMask_un_8_);
	cppVar_33334 = cppVar_33342;
	} else {
	BIT_VEC cppVar_33343 = PC + 1;
	cppVar_33343 = (cppVar_33343 & cppMask_un_16_);
	BIT_VEC cppVar_33344 = ROM.rd(cppVar_33343);
	BIT_VEC cppVar_33345 = (cppVar_33344 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_33346 = (cppVar_33345 & cppMask_un_5_);
	BIT_VEC cppVar_33347 = cppVar_33346 + 32;
	cppVar_33347 = (cppVar_33347 & cppMask_un_8_);
	cppVar_33334 = cppVar_33347;
	}
	bool cppVar_33349 = (cppVar_33334 == 240);
	if (cppVar_33349) {
	cppVar_33333 = B;
	} else {
	cppVar_33333 = 0;
	}
	cppVar_33316 = cppVar_33333;
	}
	cppVar_33299 = cppVar_33316;
	}
	cppVar_33282 = cppVar_33299;
	}
	cppVar_33265 = cppVar_33282;
	}
	cppVar_33248 = cppVar_33265;
	}
	cppVar_33231 = cppVar_33248;
	}
	cppVar_33214 = cppVar_33231;
	}
	cppVar_33197 = cppVar_33214;
	}
	cppVar_33180 = cppVar_33197;
	}
	cppVar_33163 = cppVar_33180;
	}
	cppVar_33146 = cppVar_33163;
	}
	cppVar_33129 = cppVar_33146;
	}
	cppVar_33112 = cppVar_33129;
	}
	cppVar_33095 = cppVar_33112;
	}
	cppVar_33078 = cppVar_33095;
	}
	cppVar_33061 = cppVar_33078;
	}
	cppVar_33044 = cppVar_33061;
	}
	cppVar_33027 = cppVar_33044;
	}
	cppVar_33010 = cppVar_33027;
	}
	cppVar_32993 = cppVar_33010;
	}
	cppVar_32960 = cppVar_32993;
	}
	BIT_VEC cppVar_33351 = cppVar_32959 & cppVar_32960;
	BIT_VEC cppVar_33352 = (PSW >> 7) & cppMask_un_1_;
	BIT_VEC cppVar_33353 = (cppVar_33352 & cppMask_un_1_);
	BIT_VEC cppVar_33354 = PC + 1;
	cppVar_33354 = (cppVar_33354 & cppMask_un_16_);
	BIT_VEC cppVar_33355 = ROM.rd(cppVar_33354);
	BIT_VEC cppVar_33356 = (cppVar_33355 >> 0) & cppMask_un_3_;
	BIT_VEC cppVar_33357 = (cppVar_33356 & cppMask_un_3_);
	BIT_VEC cppVar_33358 = cppVar_33353 << static_cast<unsigned>(cppVar_33357);
	cppVar_33358 = (cppVar_33358 & cppMask_un_8_);
	BIT_VEC cppVar_33359 = cppVar_33351 | cppVar_33358;
	cppVar_32932 = cppVar_33359;
	} else {
	cppVar_32932 = P2;
	}
	cppVar_32928 = cppVar_32932;
	} else {
	BIT_VEC cppVar_33360;
	BIT_VEC cppVar_33361 = ROM.rd(PC);
	bool cppVar_33363 = (cppVar_33361 == 143);
	if (cppVar_33363) {
	BIT_VEC cppVar_33364;
	BIT_VEC cppVar_33366 = PC + 1;
	cppVar_33366 = (cppVar_33366 & cppMask_un_16_);
	BIT_VEC cppVar_33367 = ROM.rd(cppVar_33366);
	bool cppVar_33369 = (cppVar_33367 == 160);
	if (cppVar_33369) {
	BIT_VEC cppVar_33370;
	BIT_VEC cppVar_33372 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_33374 = (cppVar_33372 << 3) | 7;
	cppVar_33374 = (cppVar_33374 & cppMask_un_5_);
	BIT_VEC cppVar_33375 = (0 << 5) | cppVar_33374;
	cppVar_33375 = (cppVar_33375 & cppMask_un_8_);
	BIT_VEC cppVar_33376 = (cppVar_33375 >> 7) & cppMask_un_1_;
	bool cppVar_33378 = (cppVar_33376 == 0);
	if (cppVar_33378) {
	BIT_VEC cppVar_33379 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_33380 = (cppVar_33379 << 3) | 7;
	cppVar_33380 = (cppVar_33380 & cppMask_un_5_);
	BIT_VEC cppVar_33381 = (0 << 5) | cppVar_33380;
	cppVar_33381 = (cppVar_33381 & cppMask_un_8_);
	BIT_VEC cppVar_33382 = IRAM.rd(cppVar_33381);
	cppVar_33370 = cppVar_33382;
	} else {
	BIT_VEC cppVar_33383;
	BIT_VEC cppVar_33384 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_33385 = (cppVar_33384 << 3) | 7;
	cppVar_33385 = (cppVar_33385 & cppMask_un_5_);
	BIT_VEC cppVar_33386 = (0 << 5) | cppVar_33385;
	cppVar_33386 = (cppVar_33386 & cppMask_un_8_);
	bool cppVar_33388 = (cppVar_33386 == 128);
	if (cppVar_33388) {
	cppVar_33383 = P0;
	} else {
	BIT_VEC cppVar_33389;
	BIT_VEC cppVar_33390 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_33391 = (cppVar_33390 << 3) | 7;
	cppVar_33391 = (cppVar_33391 & cppMask_un_5_);
	BIT_VEC cppVar_33392 = (0 << 5) | cppVar_33391;
	cppVar_33392 = (cppVar_33392 & cppMask_un_8_);
	bool cppVar_33394 = (cppVar_33392 == 129);
	if (cppVar_33394) {
	cppVar_33389 = SP;
	} else {
	BIT_VEC cppVar_33395;
	BIT_VEC cppVar_33396 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_33397 = (cppVar_33396 << 3) | 7;
	cppVar_33397 = (cppVar_33397 & cppMask_un_5_);
	BIT_VEC cppVar_33398 = (0 << 5) | cppVar_33397;
	cppVar_33398 = (cppVar_33398 & cppMask_un_8_);
	bool cppVar_33400 = (cppVar_33398 == 130);
	if (cppVar_33400) {
	cppVar_33395 = DPL;
	} else {
	BIT_VEC cppVar_33401;
	BIT_VEC cppVar_33402 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_33403 = (cppVar_33402 << 3) | 7;
	cppVar_33403 = (cppVar_33403 & cppMask_un_5_);
	BIT_VEC cppVar_33404 = (0 << 5) | cppVar_33403;
	cppVar_33404 = (cppVar_33404 & cppMask_un_8_);
	bool cppVar_33406 = (cppVar_33404 == 131);
	if (cppVar_33406) {
	cppVar_33401 = DPH;
	} else {
	BIT_VEC cppVar_33407;
	BIT_VEC cppVar_33408 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_33409 = (cppVar_33408 << 3) | 7;
	cppVar_33409 = (cppVar_33409 & cppMask_un_5_);
	BIT_VEC cppVar_33410 = (0 << 5) | cppVar_33409;
	cppVar_33410 = (cppVar_33410 & cppMask_un_8_);
	bool cppVar_33412 = (cppVar_33410 == 135);
	if (cppVar_33412) {
	cppVar_33407 = PCON;
	} else {
	BIT_VEC cppVar_33413;
	BIT_VEC cppVar_33414 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_33415 = (cppVar_33414 << 3) | 7;
	cppVar_33415 = (cppVar_33415 & cppMask_un_5_);
	BIT_VEC cppVar_33416 = (0 << 5) | cppVar_33415;
	cppVar_33416 = (cppVar_33416 & cppMask_un_8_);
	bool cppVar_33418 = (cppVar_33416 == 136);
	if (cppVar_33418) {
	cppVar_33413 = TCON;
	} else {
	BIT_VEC cppVar_33419;
	BIT_VEC cppVar_33420 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_33421 = (cppVar_33420 << 3) | 7;
	cppVar_33421 = (cppVar_33421 & cppMask_un_5_);
	BIT_VEC cppVar_33422 = (0 << 5) | cppVar_33421;
	cppVar_33422 = (cppVar_33422 & cppMask_un_8_);
	bool cppVar_33424 = (cppVar_33422 == 137);
	if (cppVar_33424) {
	cppVar_33419 = TMOD;
	} else {
	BIT_VEC cppVar_33425;
	BIT_VEC cppVar_33426 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_33427 = (cppVar_33426 << 3) | 7;
	cppVar_33427 = (cppVar_33427 & cppMask_un_5_);
	BIT_VEC cppVar_33428 = (0 << 5) | cppVar_33427;
	cppVar_33428 = (cppVar_33428 & cppMask_un_8_);
	bool cppVar_33430 = (cppVar_33428 == 138);
	if (cppVar_33430) {
	cppVar_33425 = TL0;
	} else {
	BIT_VEC cppVar_33431;
	BIT_VEC cppVar_33432 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_33433 = (cppVar_33432 << 3) | 7;
	cppVar_33433 = (cppVar_33433 & cppMask_un_5_);
	BIT_VEC cppVar_33434 = (0 << 5) | cppVar_33433;
	cppVar_33434 = (cppVar_33434 & cppMask_un_8_);
	bool cppVar_33436 = (cppVar_33434 == 140);
	if (cppVar_33436) {
	cppVar_33431 = TH0;
	} else {
	BIT_VEC cppVar_33437;
	BIT_VEC cppVar_33438 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_33439 = (cppVar_33438 << 3) | 7;
	cppVar_33439 = (cppVar_33439 & cppMask_un_5_);
	BIT_VEC cppVar_33440 = (0 << 5) | cppVar_33439;
	cppVar_33440 = (cppVar_33440 & cppMask_un_8_);
	bool cppVar_33442 = (cppVar_33440 == 139);
	if (cppVar_33442) {
	cppVar_33437 = TL1;
	} else {
	BIT_VEC cppVar_33443;
	BIT_VEC cppVar_33444 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_33445 = (cppVar_33444 << 3) | 7;
	cppVar_33445 = (cppVar_33445 & cppMask_un_5_);
	BIT_VEC cppVar_33446 = (0 << 5) | cppVar_33445;
	cppVar_33446 = (cppVar_33446 & cppMask_un_8_);
	bool cppVar_33448 = (cppVar_33446 == 141);
	if (cppVar_33448) {
	cppVar_33443 = TH1;
	} else {
	BIT_VEC cppVar_33449;
	BIT_VEC cppVar_33450 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_33451 = (cppVar_33450 << 3) | 7;
	cppVar_33451 = (cppVar_33451 & cppMask_un_5_);
	BIT_VEC cppVar_33452 = (0 << 5) | cppVar_33451;
	cppVar_33452 = (cppVar_33452 & cppMask_un_8_);
	bool cppVar_33454 = (cppVar_33452 == 144);
	if (cppVar_33454) {
	cppVar_33449 = P1;
	} else {
	BIT_VEC cppVar_33455;
	BIT_VEC cppVar_33456 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_33457 = (cppVar_33456 << 3) | 7;
	cppVar_33457 = (cppVar_33457 & cppMask_un_5_);
	BIT_VEC cppVar_33458 = (0 << 5) | cppVar_33457;
	cppVar_33458 = (cppVar_33458 & cppMask_un_8_);
	bool cppVar_33460 = (cppVar_33458 == 152);
	if (cppVar_33460) {
	cppVar_33455 = SCON;
	} else {
	BIT_VEC cppVar_33461;
	BIT_VEC cppVar_33462 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_33463 = (cppVar_33462 << 3) | 7;
	cppVar_33463 = (cppVar_33463 & cppMask_un_5_);
	BIT_VEC cppVar_33464 = (0 << 5) | cppVar_33463;
	cppVar_33464 = (cppVar_33464 & cppMask_un_8_);
	bool cppVar_33466 = (cppVar_33464 == 153);
	if (cppVar_33466) {
	cppVar_33461 = SBUF;
	} else {
	BIT_VEC cppVar_33467;
	BIT_VEC cppVar_33468 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_33469 = (cppVar_33468 << 3) | 7;
	cppVar_33469 = (cppVar_33469 & cppMask_un_5_);
	BIT_VEC cppVar_33470 = (0 << 5) | cppVar_33469;
	cppVar_33470 = (cppVar_33470 & cppMask_un_8_);
	bool cppVar_33472 = (cppVar_33470 == 160);
	if (cppVar_33472) {
	cppVar_33467 = P2;
	} else {
	BIT_VEC cppVar_33473;
	BIT_VEC cppVar_33474 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_33475 = (cppVar_33474 << 3) | 7;
	cppVar_33475 = (cppVar_33475 & cppMask_un_5_);
	BIT_VEC cppVar_33476 = (0 << 5) | cppVar_33475;
	cppVar_33476 = (cppVar_33476 & cppMask_un_8_);
	bool cppVar_33478 = (cppVar_33476 == 168);
	if (cppVar_33478) {
	cppVar_33473 = IE;
	} else {
	BIT_VEC cppVar_33479;
	BIT_VEC cppVar_33480 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_33481 = (cppVar_33480 << 3) | 7;
	cppVar_33481 = (cppVar_33481 & cppMask_un_5_);
	BIT_VEC cppVar_33482 = (0 << 5) | cppVar_33481;
	cppVar_33482 = (cppVar_33482 & cppMask_un_8_);
	bool cppVar_33484 = (cppVar_33482 == 176);
	if (cppVar_33484) {
	cppVar_33479 = P3;
	} else {
	BIT_VEC cppVar_33485;
	BIT_VEC cppVar_33486 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_33487 = (cppVar_33486 << 3) | 7;
	cppVar_33487 = (cppVar_33487 & cppMask_un_5_);
	BIT_VEC cppVar_33488 = (0 << 5) | cppVar_33487;
	cppVar_33488 = (cppVar_33488 & cppMask_un_8_);
	bool cppVar_33490 = (cppVar_33488 == 184);
	if (cppVar_33490) {
	cppVar_33485 = IP;
	} else {
	BIT_VEC cppVar_33491;
	BIT_VEC cppVar_33492 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_33493 = (cppVar_33492 << 3) | 7;
	cppVar_33493 = (cppVar_33493 & cppMask_un_5_);
	BIT_VEC cppVar_33494 = (0 << 5) | cppVar_33493;
	cppVar_33494 = (cppVar_33494 & cppMask_un_8_);
	bool cppVar_33496 = (cppVar_33494 == 208);
	if (cppVar_33496) {
	cppVar_33491 = PSW;
	} else {
	BIT_VEC cppVar_33497;
	BIT_VEC cppVar_33498 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_33499 = (cppVar_33498 << 3) | 7;
	cppVar_33499 = (cppVar_33499 & cppMask_un_5_);
	BIT_VEC cppVar_33500 = (0 << 5) | cppVar_33499;
	cppVar_33500 = (cppVar_33500 & cppMask_un_8_);
	bool cppVar_33502 = (cppVar_33500 == 224);
	if (cppVar_33502) {
	cppVar_33497 = ACC;
	} else {
	BIT_VEC cppVar_33503;
	BIT_VEC cppVar_33504 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_33505 = (cppVar_33504 << 3) | 7;
	cppVar_33505 = (cppVar_33505 & cppMask_un_5_);
	BIT_VEC cppVar_33506 = (0 << 5) | cppVar_33505;
	cppVar_33506 = (cppVar_33506 & cppMask_un_8_);
	bool cppVar_33508 = (cppVar_33506 == 240);
	if (cppVar_33508) {
	cppVar_33503 = B;
	} else {
	cppVar_33503 = 0;
	}
	cppVar_33497 = cppVar_33503;
	}
	cppVar_33491 = cppVar_33497;
	}
	cppVar_33485 = cppVar_33491;
	}
	cppVar_33479 = cppVar_33485;
	}
	cppVar_33473 = cppVar_33479;
	}
	cppVar_33467 = cppVar_33473;
	}
	cppVar_33461 = cppVar_33467;
	}
	cppVar_33455 = cppVar_33461;
	}
	cppVar_33449 = cppVar_33455;
	}
	cppVar_33443 = cppVar_33449;
	}
	cppVar_33437 = cppVar_33443;
	}
	cppVar_33431 = cppVar_33437;
	}
	cppVar_33425 = cppVar_33431;
	}
	cppVar_33419 = cppVar_33425;
	}
	cppVar_33413 = cppVar_33419;
	}
	cppVar_33407 = cppVar_33413;
	}
	cppVar_33401 = cppVar_33407;
	}
	cppVar_33395 = cppVar_33401;
	}
	cppVar_33389 = cppVar_33395;
	}
	cppVar_33383 = cppVar_33389;
	}
	cppVar_33370 = cppVar_33383;
	}
	cppVar_33364 = cppVar_33370;
	} else {
	cppVar_33364 = P2;
	}
	cppVar_33360 = cppVar_33364;
	} else {
	BIT_VEC cppVar_33510;
	BIT_VEC cppVar_33511 = ROM.rd(PC);
	bool cppVar_33513 = (cppVar_33511 == 142);
	if (cppVar_33513) {
	BIT_VEC cppVar_33514;
	BIT_VEC cppVar_33516 = PC + 1;
	cppVar_33516 = (cppVar_33516 & cppMask_un_16_);
	BIT_VEC cppVar_33517 = ROM.rd(cppVar_33516);
	bool cppVar_33519 = (cppVar_33517 == 160);
	if (cppVar_33519) {
	BIT_VEC cppVar_33520;
	BIT_VEC cppVar_33522 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_33524 = (cppVar_33522 << 3) | 6;
	cppVar_33524 = (cppVar_33524 & cppMask_un_5_);
	BIT_VEC cppVar_33525 = (0 << 5) | cppVar_33524;
	cppVar_33525 = (cppVar_33525 & cppMask_un_8_);
	BIT_VEC cppVar_33526 = (cppVar_33525 >> 7) & cppMask_un_1_;
	bool cppVar_33528 = (cppVar_33526 == 0);
	if (cppVar_33528) {
	BIT_VEC cppVar_33529 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_33530 = (cppVar_33529 << 3) | 6;
	cppVar_33530 = (cppVar_33530 & cppMask_un_5_);
	BIT_VEC cppVar_33531 = (0 << 5) | cppVar_33530;
	cppVar_33531 = (cppVar_33531 & cppMask_un_8_);
	BIT_VEC cppVar_33532 = IRAM.rd(cppVar_33531);
	cppVar_33520 = cppVar_33532;
	} else {
	BIT_VEC cppVar_33533;
	BIT_VEC cppVar_33534 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_33535 = (cppVar_33534 << 3) | 6;
	cppVar_33535 = (cppVar_33535 & cppMask_un_5_);
	BIT_VEC cppVar_33536 = (0 << 5) | cppVar_33535;
	cppVar_33536 = (cppVar_33536 & cppMask_un_8_);
	bool cppVar_33538 = (cppVar_33536 == 128);
	if (cppVar_33538) {
	cppVar_33533 = P0;
	} else {
	BIT_VEC cppVar_33539;
	BIT_VEC cppVar_33540 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_33541 = (cppVar_33540 << 3) | 6;
	cppVar_33541 = (cppVar_33541 & cppMask_un_5_);
	BIT_VEC cppVar_33542 = (0 << 5) | cppVar_33541;
	cppVar_33542 = (cppVar_33542 & cppMask_un_8_);
	bool cppVar_33544 = (cppVar_33542 == 129);
	if (cppVar_33544) {
	cppVar_33539 = SP;
	} else {
	BIT_VEC cppVar_33545;
	BIT_VEC cppVar_33546 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_33547 = (cppVar_33546 << 3) | 6;
	cppVar_33547 = (cppVar_33547 & cppMask_un_5_);
	BIT_VEC cppVar_33548 = (0 << 5) | cppVar_33547;
	cppVar_33548 = (cppVar_33548 & cppMask_un_8_);
	bool cppVar_33550 = (cppVar_33548 == 130);
	if (cppVar_33550) {
	cppVar_33545 = DPL;
	} else {
	BIT_VEC cppVar_33551;
	BIT_VEC cppVar_33552 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_33553 = (cppVar_33552 << 3) | 6;
	cppVar_33553 = (cppVar_33553 & cppMask_un_5_);
	BIT_VEC cppVar_33554 = (0 << 5) | cppVar_33553;
	cppVar_33554 = (cppVar_33554 & cppMask_un_8_);
	bool cppVar_33556 = (cppVar_33554 == 131);
	if (cppVar_33556) {
	cppVar_33551 = DPH;
	} else {
	BIT_VEC cppVar_33557;
	BIT_VEC cppVar_33558 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_33559 = (cppVar_33558 << 3) | 6;
	cppVar_33559 = (cppVar_33559 & cppMask_un_5_);
	BIT_VEC cppVar_33560 = (0 << 5) | cppVar_33559;
	cppVar_33560 = (cppVar_33560 & cppMask_un_8_);
	bool cppVar_33562 = (cppVar_33560 == 135);
	if (cppVar_33562) {
	cppVar_33557 = PCON;
	} else {
	BIT_VEC cppVar_33563;
	BIT_VEC cppVar_33564 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_33565 = (cppVar_33564 << 3) | 6;
	cppVar_33565 = (cppVar_33565 & cppMask_un_5_);
	BIT_VEC cppVar_33566 = (0 << 5) | cppVar_33565;
	cppVar_33566 = (cppVar_33566 & cppMask_un_8_);
	bool cppVar_33568 = (cppVar_33566 == 136);
	if (cppVar_33568) {
	cppVar_33563 = TCON;
	} else {
	BIT_VEC cppVar_33569;
	BIT_VEC cppVar_33570 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_33571 = (cppVar_33570 << 3) | 6;
	cppVar_33571 = (cppVar_33571 & cppMask_un_5_);
	BIT_VEC cppVar_33572 = (0 << 5) | cppVar_33571;
	cppVar_33572 = (cppVar_33572 & cppMask_un_8_);
	bool cppVar_33574 = (cppVar_33572 == 137);
	if (cppVar_33574) {
	cppVar_33569 = TMOD;
	} else {
	BIT_VEC cppVar_33575;
	BIT_VEC cppVar_33576 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_33577 = (cppVar_33576 << 3) | 6;
	cppVar_33577 = (cppVar_33577 & cppMask_un_5_);
	BIT_VEC cppVar_33578 = (0 << 5) | cppVar_33577;
	cppVar_33578 = (cppVar_33578 & cppMask_un_8_);
	bool cppVar_33580 = (cppVar_33578 == 138);
	if (cppVar_33580) {
	cppVar_33575 = TL0;
	} else {
	BIT_VEC cppVar_33581;
	BIT_VEC cppVar_33582 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_33583 = (cppVar_33582 << 3) | 6;
	cppVar_33583 = (cppVar_33583 & cppMask_un_5_);
	BIT_VEC cppVar_33584 = (0 << 5) | cppVar_33583;
	cppVar_33584 = (cppVar_33584 & cppMask_un_8_);
	bool cppVar_33586 = (cppVar_33584 == 140);
	if (cppVar_33586) {
	cppVar_33581 = TH0;
	} else {
	BIT_VEC cppVar_33587;
	BIT_VEC cppVar_33588 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_33589 = (cppVar_33588 << 3) | 6;
	cppVar_33589 = (cppVar_33589 & cppMask_un_5_);
	BIT_VEC cppVar_33590 = (0 << 5) | cppVar_33589;
	cppVar_33590 = (cppVar_33590 & cppMask_un_8_);
	bool cppVar_33592 = (cppVar_33590 == 139);
	if (cppVar_33592) {
	cppVar_33587 = TL1;
	} else {
	BIT_VEC cppVar_33593;
	BIT_VEC cppVar_33594 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_33595 = (cppVar_33594 << 3) | 6;
	cppVar_33595 = (cppVar_33595 & cppMask_un_5_);
	BIT_VEC cppVar_33596 = (0 << 5) | cppVar_33595;
	cppVar_33596 = (cppVar_33596 & cppMask_un_8_);
	bool cppVar_33598 = (cppVar_33596 == 141);
	if (cppVar_33598) {
	cppVar_33593 = TH1;
	} else {
	BIT_VEC cppVar_33599;
	BIT_VEC cppVar_33600 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_33601 = (cppVar_33600 << 3) | 6;
	cppVar_33601 = (cppVar_33601 & cppMask_un_5_);
	BIT_VEC cppVar_33602 = (0 << 5) | cppVar_33601;
	cppVar_33602 = (cppVar_33602 & cppMask_un_8_);
	bool cppVar_33604 = (cppVar_33602 == 144);
	if (cppVar_33604) {
	cppVar_33599 = P1;
	} else {
	BIT_VEC cppVar_33605;
	BIT_VEC cppVar_33606 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_33607 = (cppVar_33606 << 3) | 6;
	cppVar_33607 = (cppVar_33607 & cppMask_un_5_);
	BIT_VEC cppVar_33608 = (0 << 5) | cppVar_33607;
	cppVar_33608 = (cppVar_33608 & cppMask_un_8_);
	bool cppVar_33610 = (cppVar_33608 == 152);
	if (cppVar_33610) {
	cppVar_33605 = SCON;
	} else {
	BIT_VEC cppVar_33611;
	BIT_VEC cppVar_33612 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_33613 = (cppVar_33612 << 3) | 6;
	cppVar_33613 = (cppVar_33613 & cppMask_un_5_);
	BIT_VEC cppVar_33614 = (0 << 5) | cppVar_33613;
	cppVar_33614 = (cppVar_33614 & cppMask_un_8_);
	bool cppVar_33616 = (cppVar_33614 == 153);
	if (cppVar_33616) {
	cppVar_33611 = SBUF;
	} else {
	BIT_VEC cppVar_33617;
	BIT_VEC cppVar_33618 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_33619 = (cppVar_33618 << 3) | 6;
	cppVar_33619 = (cppVar_33619 & cppMask_un_5_);
	BIT_VEC cppVar_33620 = (0 << 5) | cppVar_33619;
	cppVar_33620 = (cppVar_33620 & cppMask_un_8_);
	bool cppVar_33622 = (cppVar_33620 == 160);
	if (cppVar_33622) {
	cppVar_33617 = P2;
	} else {
	BIT_VEC cppVar_33623;
	BIT_VEC cppVar_33624 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_33625 = (cppVar_33624 << 3) | 6;
	cppVar_33625 = (cppVar_33625 & cppMask_un_5_);
	BIT_VEC cppVar_33626 = (0 << 5) | cppVar_33625;
	cppVar_33626 = (cppVar_33626 & cppMask_un_8_);
	bool cppVar_33628 = (cppVar_33626 == 168);
	if (cppVar_33628) {
	cppVar_33623 = IE;
	} else {
	BIT_VEC cppVar_33629;
	BIT_VEC cppVar_33630 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_33631 = (cppVar_33630 << 3) | 6;
	cppVar_33631 = (cppVar_33631 & cppMask_un_5_);
	BIT_VEC cppVar_33632 = (0 << 5) | cppVar_33631;
	cppVar_33632 = (cppVar_33632 & cppMask_un_8_);
	bool cppVar_33634 = (cppVar_33632 == 176);
	if (cppVar_33634) {
	cppVar_33629 = P3;
	} else {
	BIT_VEC cppVar_33635;
	BIT_VEC cppVar_33636 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_33637 = (cppVar_33636 << 3) | 6;
	cppVar_33637 = (cppVar_33637 & cppMask_un_5_);
	BIT_VEC cppVar_33638 = (0 << 5) | cppVar_33637;
	cppVar_33638 = (cppVar_33638 & cppMask_un_8_);
	bool cppVar_33640 = (cppVar_33638 == 184);
	if (cppVar_33640) {
	cppVar_33635 = IP;
	} else {
	BIT_VEC cppVar_33641;
	BIT_VEC cppVar_33642 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_33643 = (cppVar_33642 << 3) | 6;
	cppVar_33643 = (cppVar_33643 & cppMask_un_5_);
	BIT_VEC cppVar_33644 = (0 << 5) | cppVar_33643;
	cppVar_33644 = (cppVar_33644 & cppMask_un_8_);
	bool cppVar_33646 = (cppVar_33644 == 208);
	if (cppVar_33646) {
	cppVar_33641 = PSW;
	} else {
	BIT_VEC cppVar_33647;
	BIT_VEC cppVar_33648 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_33649 = (cppVar_33648 << 3) | 6;
	cppVar_33649 = (cppVar_33649 & cppMask_un_5_);
	BIT_VEC cppVar_33650 = (0 << 5) | cppVar_33649;
	cppVar_33650 = (cppVar_33650 & cppMask_un_8_);
	bool cppVar_33652 = (cppVar_33650 == 224);
	if (cppVar_33652) {
	cppVar_33647 = ACC;
	} else {
	BIT_VEC cppVar_33653;
	BIT_VEC cppVar_33654 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_33655 = (cppVar_33654 << 3) | 6;
	cppVar_33655 = (cppVar_33655 & cppMask_un_5_);
	BIT_VEC cppVar_33656 = (0 << 5) | cppVar_33655;
	cppVar_33656 = (cppVar_33656 & cppMask_un_8_);
	bool cppVar_33658 = (cppVar_33656 == 240);
	if (cppVar_33658) {
	cppVar_33653 = B;
	} else {
	cppVar_33653 = 0;
	}
	cppVar_33647 = cppVar_33653;
	}
	cppVar_33641 = cppVar_33647;
	}
	cppVar_33635 = cppVar_33641;
	}
	cppVar_33629 = cppVar_33635;
	}
	cppVar_33623 = cppVar_33629;
	}
	cppVar_33617 = cppVar_33623;
	}
	cppVar_33611 = cppVar_33617;
	}
	cppVar_33605 = cppVar_33611;
	}
	cppVar_33599 = cppVar_33605;
	}
	cppVar_33593 = cppVar_33599;
	}
	cppVar_33587 = cppVar_33593;
	}
	cppVar_33581 = cppVar_33587;
	}
	cppVar_33575 = cppVar_33581;
	}
	cppVar_33569 = cppVar_33575;
	}
	cppVar_33563 = cppVar_33569;
	}
	cppVar_33557 = cppVar_33563;
	}
	cppVar_33551 = cppVar_33557;
	}
	cppVar_33545 = cppVar_33551;
	}
	cppVar_33539 = cppVar_33545;
	}
	cppVar_33533 = cppVar_33539;
	}
	cppVar_33520 = cppVar_33533;
	}
	cppVar_33514 = cppVar_33520;
	} else {
	cppVar_33514 = P2;
	}
	cppVar_33510 = cppVar_33514;
	} else {
	BIT_VEC cppVar_33660;
	BIT_VEC cppVar_33661 = ROM.rd(PC);
	bool cppVar_33663 = (cppVar_33661 == 141);
	if (cppVar_33663) {
	BIT_VEC cppVar_33664;
	BIT_VEC cppVar_33666 = PC + 1;
	cppVar_33666 = (cppVar_33666 & cppMask_un_16_);
	BIT_VEC cppVar_33667 = ROM.rd(cppVar_33666);
	bool cppVar_33669 = (cppVar_33667 == 160);
	if (cppVar_33669) {
	BIT_VEC cppVar_33670;
	BIT_VEC cppVar_33672 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_33674 = (cppVar_33672 << 3) | 5;
	cppVar_33674 = (cppVar_33674 & cppMask_un_5_);
	BIT_VEC cppVar_33675 = (0 << 5) | cppVar_33674;
	cppVar_33675 = (cppVar_33675 & cppMask_un_8_);
	BIT_VEC cppVar_33676 = (cppVar_33675 >> 7) & cppMask_un_1_;
	bool cppVar_33678 = (cppVar_33676 == 0);
	if (cppVar_33678) {
	BIT_VEC cppVar_33679 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_33680 = (cppVar_33679 << 3) | 5;
	cppVar_33680 = (cppVar_33680 & cppMask_un_5_);
	BIT_VEC cppVar_33681 = (0 << 5) | cppVar_33680;
	cppVar_33681 = (cppVar_33681 & cppMask_un_8_);
	BIT_VEC cppVar_33682 = IRAM.rd(cppVar_33681);
	cppVar_33670 = cppVar_33682;
	} else {
	BIT_VEC cppVar_33683;
	BIT_VEC cppVar_33684 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_33685 = (cppVar_33684 << 3) | 5;
	cppVar_33685 = (cppVar_33685 & cppMask_un_5_);
	BIT_VEC cppVar_33686 = (0 << 5) | cppVar_33685;
	cppVar_33686 = (cppVar_33686 & cppMask_un_8_);
	bool cppVar_33688 = (cppVar_33686 == 128);
	if (cppVar_33688) {
	cppVar_33683 = P0;
	} else {
	BIT_VEC cppVar_33689;
	BIT_VEC cppVar_33690 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_33691 = (cppVar_33690 << 3) | 5;
	cppVar_33691 = (cppVar_33691 & cppMask_un_5_);
	BIT_VEC cppVar_33692 = (0 << 5) | cppVar_33691;
	cppVar_33692 = (cppVar_33692 & cppMask_un_8_);
	bool cppVar_33694 = (cppVar_33692 == 129);
	if (cppVar_33694) {
	cppVar_33689 = SP;
	} else {
	BIT_VEC cppVar_33695;
	BIT_VEC cppVar_33696 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_33697 = (cppVar_33696 << 3) | 5;
	cppVar_33697 = (cppVar_33697 & cppMask_un_5_);
	BIT_VEC cppVar_33698 = (0 << 5) | cppVar_33697;
	cppVar_33698 = (cppVar_33698 & cppMask_un_8_);
	bool cppVar_33700 = (cppVar_33698 == 130);
	if (cppVar_33700) {
	cppVar_33695 = DPL;
	} else {
	BIT_VEC cppVar_33701;
	BIT_VEC cppVar_33702 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_33703 = (cppVar_33702 << 3) | 5;
	cppVar_33703 = (cppVar_33703 & cppMask_un_5_);
	BIT_VEC cppVar_33704 = (0 << 5) | cppVar_33703;
	cppVar_33704 = (cppVar_33704 & cppMask_un_8_);
	bool cppVar_33706 = (cppVar_33704 == 131);
	if (cppVar_33706) {
	cppVar_33701 = DPH;
	} else {
	BIT_VEC cppVar_33707;
	BIT_VEC cppVar_33708 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_33709 = (cppVar_33708 << 3) | 5;
	cppVar_33709 = (cppVar_33709 & cppMask_un_5_);
	BIT_VEC cppVar_33710 = (0 << 5) | cppVar_33709;
	cppVar_33710 = (cppVar_33710 & cppMask_un_8_);
	bool cppVar_33712 = (cppVar_33710 == 135);
	if (cppVar_33712) {
	cppVar_33707 = PCON;
	} else {
	BIT_VEC cppVar_33713;
	BIT_VEC cppVar_33714 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_33715 = (cppVar_33714 << 3) | 5;
	cppVar_33715 = (cppVar_33715 & cppMask_un_5_);
	BIT_VEC cppVar_33716 = (0 << 5) | cppVar_33715;
	cppVar_33716 = (cppVar_33716 & cppMask_un_8_);
	bool cppVar_33718 = (cppVar_33716 == 136);
	if (cppVar_33718) {
	cppVar_33713 = TCON;
	} else {
	BIT_VEC cppVar_33719;
	BIT_VEC cppVar_33720 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_33721 = (cppVar_33720 << 3) | 5;
	cppVar_33721 = (cppVar_33721 & cppMask_un_5_);
	BIT_VEC cppVar_33722 = (0 << 5) | cppVar_33721;
	cppVar_33722 = (cppVar_33722 & cppMask_un_8_);
	bool cppVar_33724 = (cppVar_33722 == 137);
	if (cppVar_33724) {
	cppVar_33719 = TMOD;
	} else {
	BIT_VEC cppVar_33725;
	BIT_VEC cppVar_33726 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_33727 = (cppVar_33726 << 3) | 5;
	cppVar_33727 = (cppVar_33727 & cppMask_un_5_);
	BIT_VEC cppVar_33728 = (0 << 5) | cppVar_33727;
	cppVar_33728 = (cppVar_33728 & cppMask_un_8_);
	bool cppVar_33730 = (cppVar_33728 == 138);
	if (cppVar_33730) {
	cppVar_33725 = TL0;
	} else {
	BIT_VEC cppVar_33731;
	BIT_VEC cppVar_33732 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_33733 = (cppVar_33732 << 3) | 5;
	cppVar_33733 = (cppVar_33733 & cppMask_un_5_);
	BIT_VEC cppVar_33734 = (0 << 5) | cppVar_33733;
	cppVar_33734 = (cppVar_33734 & cppMask_un_8_);
	bool cppVar_33736 = (cppVar_33734 == 140);
	if (cppVar_33736) {
	cppVar_33731 = TH0;
	} else {
	BIT_VEC cppVar_33737;
	BIT_VEC cppVar_33738 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_33739 = (cppVar_33738 << 3) | 5;
	cppVar_33739 = (cppVar_33739 & cppMask_un_5_);
	BIT_VEC cppVar_33740 = (0 << 5) | cppVar_33739;
	cppVar_33740 = (cppVar_33740 & cppMask_un_8_);
	bool cppVar_33742 = (cppVar_33740 == 139);
	if (cppVar_33742) {
	cppVar_33737 = TL1;
	} else {
	BIT_VEC cppVar_33743;
	BIT_VEC cppVar_33744 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_33745 = (cppVar_33744 << 3) | 5;
	cppVar_33745 = (cppVar_33745 & cppMask_un_5_);
	BIT_VEC cppVar_33746 = (0 << 5) | cppVar_33745;
	cppVar_33746 = (cppVar_33746 & cppMask_un_8_);
	bool cppVar_33748 = (cppVar_33746 == 141);
	if (cppVar_33748) {
	cppVar_33743 = TH1;
	} else {
	BIT_VEC cppVar_33749;
	BIT_VEC cppVar_33750 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_33751 = (cppVar_33750 << 3) | 5;
	cppVar_33751 = (cppVar_33751 & cppMask_un_5_);
	BIT_VEC cppVar_33752 = (0 << 5) | cppVar_33751;
	cppVar_33752 = (cppVar_33752 & cppMask_un_8_);
	bool cppVar_33754 = (cppVar_33752 == 144);
	if (cppVar_33754) {
	cppVar_33749 = P1;
	} else {
	BIT_VEC cppVar_33755;
	BIT_VEC cppVar_33756 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_33757 = (cppVar_33756 << 3) | 5;
	cppVar_33757 = (cppVar_33757 & cppMask_un_5_);
	BIT_VEC cppVar_33758 = (0 << 5) | cppVar_33757;
	cppVar_33758 = (cppVar_33758 & cppMask_un_8_);
	bool cppVar_33760 = (cppVar_33758 == 152);
	if (cppVar_33760) {
	cppVar_33755 = SCON;
	} else {
	BIT_VEC cppVar_33761;
	BIT_VEC cppVar_33762 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_33763 = (cppVar_33762 << 3) | 5;
	cppVar_33763 = (cppVar_33763 & cppMask_un_5_);
	BIT_VEC cppVar_33764 = (0 << 5) | cppVar_33763;
	cppVar_33764 = (cppVar_33764 & cppMask_un_8_);
	bool cppVar_33766 = (cppVar_33764 == 153);
	if (cppVar_33766) {
	cppVar_33761 = SBUF;
	} else {
	BIT_VEC cppVar_33767;
	BIT_VEC cppVar_33768 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_33769 = (cppVar_33768 << 3) | 5;
	cppVar_33769 = (cppVar_33769 & cppMask_un_5_);
	BIT_VEC cppVar_33770 = (0 << 5) | cppVar_33769;
	cppVar_33770 = (cppVar_33770 & cppMask_un_8_);
	bool cppVar_33772 = (cppVar_33770 == 160);
	if (cppVar_33772) {
	cppVar_33767 = P2;
	} else {
	BIT_VEC cppVar_33773;
	BIT_VEC cppVar_33774 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_33775 = (cppVar_33774 << 3) | 5;
	cppVar_33775 = (cppVar_33775 & cppMask_un_5_);
	BIT_VEC cppVar_33776 = (0 << 5) | cppVar_33775;
	cppVar_33776 = (cppVar_33776 & cppMask_un_8_);
	bool cppVar_33778 = (cppVar_33776 == 168);
	if (cppVar_33778) {
	cppVar_33773 = IE;
	} else {
	BIT_VEC cppVar_33779;
	BIT_VEC cppVar_33780 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_33781 = (cppVar_33780 << 3) | 5;
	cppVar_33781 = (cppVar_33781 & cppMask_un_5_);
	BIT_VEC cppVar_33782 = (0 << 5) | cppVar_33781;
	cppVar_33782 = (cppVar_33782 & cppMask_un_8_);
	bool cppVar_33784 = (cppVar_33782 == 176);
	if (cppVar_33784) {
	cppVar_33779 = P3;
	} else {
	BIT_VEC cppVar_33785;
	BIT_VEC cppVar_33786 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_33787 = (cppVar_33786 << 3) | 5;
	cppVar_33787 = (cppVar_33787 & cppMask_un_5_);
	BIT_VEC cppVar_33788 = (0 << 5) | cppVar_33787;
	cppVar_33788 = (cppVar_33788 & cppMask_un_8_);
	bool cppVar_33790 = (cppVar_33788 == 184);
	if (cppVar_33790) {
	cppVar_33785 = IP;
	} else {
	BIT_VEC cppVar_33791;
	BIT_VEC cppVar_33792 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_33793 = (cppVar_33792 << 3) | 5;
	cppVar_33793 = (cppVar_33793 & cppMask_un_5_);
	BIT_VEC cppVar_33794 = (0 << 5) | cppVar_33793;
	cppVar_33794 = (cppVar_33794 & cppMask_un_8_);
	bool cppVar_33796 = (cppVar_33794 == 208);
	if (cppVar_33796) {
	cppVar_33791 = PSW;
	} else {
	BIT_VEC cppVar_33797;
	BIT_VEC cppVar_33798 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_33799 = (cppVar_33798 << 3) | 5;
	cppVar_33799 = (cppVar_33799 & cppMask_un_5_);
	BIT_VEC cppVar_33800 = (0 << 5) | cppVar_33799;
	cppVar_33800 = (cppVar_33800 & cppMask_un_8_);
	bool cppVar_33802 = (cppVar_33800 == 224);
	if (cppVar_33802) {
	cppVar_33797 = ACC;
	} else {
	BIT_VEC cppVar_33803;
	BIT_VEC cppVar_33804 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_33805 = (cppVar_33804 << 3) | 5;
	cppVar_33805 = (cppVar_33805 & cppMask_un_5_);
	BIT_VEC cppVar_33806 = (0 << 5) | cppVar_33805;
	cppVar_33806 = (cppVar_33806 & cppMask_un_8_);
	bool cppVar_33808 = (cppVar_33806 == 240);
	if (cppVar_33808) {
	cppVar_33803 = B;
	} else {
	cppVar_33803 = 0;
	}
	cppVar_33797 = cppVar_33803;
	}
	cppVar_33791 = cppVar_33797;
	}
	cppVar_33785 = cppVar_33791;
	}
	cppVar_33779 = cppVar_33785;
	}
	cppVar_33773 = cppVar_33779;
	}
	cppVar_33767 = cppVar_33773;
	}
	cppVar_33761 = cppVar_33767;
	}
	cppVar_33755 = cppVar_33761;
	}
	cppVar_33749 = cppVar_33755;
	}
	cppVar_33743 = cppVar_33749;
	}
	cppVar_33737 = cppVar_33743;
	}
	cppVar_33731 = cppVar_33737;
	}
	cppVar_33725 = cppVar_33731;
	}
	cppVar_33719 = cppVar_33725;
	}
	cppVar_33713 = cppVar_33719;
	}
	cppVar_33707 = cppVar_33713;
	}
	cppVar_33701 = cppVar_33707;
	}
	cppVar_33695 = cppVar_33701;
	}
	cppVar_33689 = cppVar_33695;
	}
	cppVar_33683 = cppVar_33689;
	}
	cppVar_33670 = cppVar_33683;
	}
	cppVar_33664 = cppVar_33670;
	} else {
	cppVar_33664 = P2;
	}
	cppVar_33660 = cppVar_33664;
	} else {
	BIT_VEC cppVar_33810;
	BIT_VEC cppVar_33811 = ROM.rd(PC);
	bool cppVar_33813 = (cppVar_33811 == 140);
	if (cppVar_33813) {
	BIT_VEC cppVar_33814;
	BIT_VEC cppVar_33816 = PC + 1;
	cppVar_33816 = (cppVar_33816 & cppMask_un_16_);
	BIT_VEC cppVar_33817 = ROM.rd(cppVar_33816);
	bool cppVar_33819 = (cppVar_33817 == 160);
	if (cppVar_33819) {
	BIT_VEC cppVar_33820;
	BIT_VEC cppVar_33822 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_33824 = (cppVar_33822 << 3) | 4;
	cppVar_33824 = (cppVar_33824 & cppMask_un_5_);
	BIT_VEC cppVar_33825 = (0 << 5) | cppVar_33824;
	cppVar_33825 = (cppVar_33825 & cppMask_un_8_);
	BIT_VEC cppVar_33826 = (cppVar_33825 >> 7) & cppMask_un_1_;
	bool cppVar_33828 = (cppVar_33826 == 0);
	if (cppVar_33828) {
	BIT_VEC cppVar_33829 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_33830 = (cppVar_33829 << 3) | 4;
	cppVar_33830 = (cppVar_33830 & cppMask_un_5_);
	BIT_VEC cppVar_33831 = (0 << 5) | cppVar_33830;
	cppVar_33831 = (cppVar_33831 & cppMask_un_8_);
	BIT_VEC cppVar_33832 = IRAM.rd(cppVar_33831);
	cppVar_33820 = cppVar_33832;
	} else {
	BIT_VEC cppVar_33833;
	BIT_VEC cppVar_33834 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_33835 = (cppVar_33834 << 3) | 4;
	cppVar_33835 = (cppVar_33835 & cppMask_un_5_);
	BIT_VEC cppVar_33836 = (0 << 5) | cppVar_33835;
	cppVar_33836 = (cppVar_33836 & cppMask_un_8_);
	bool cppVar_33838 = (cppVar_33836 == 128);
	if (cppVar_33838) {
	cppVar_33833 = P0;
	} else {
	BIT_VEC cppVar_33839;
	BIT_VEC cppVar_33840 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_33841 = (cppVar_33840 << 3) | 4;
	cppVar_33841 = (cppVar_33841 & cppMask_un_5_);
	BIT_VEC cppVar_33842 = (0 << 5) | cppVar_33841;
	cppVar_33842 = (cppVar_33842 & cppMask_un_8_);
	bool cppVar_33844 = (cppVar_33842 == 129);
	if (cppVar_33844) {
	cppVar_33839 = SP;
	} else {
	BIT_VEC cppVar_33845;
	BIT_VEC cppVar_33846 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_33847 = (cppVar_33846 << 3) | 4;
	cppVar_33847 = (cppVar_33847 & cppMask_un_5_);
	BIT_VEC cppVar_33848 = (0 << 5) | cppVar_33847;
	cppVar_33848 = (cppVar_33848 & cppMask_un_8_);
	bool cppVar_33850 = (cppVar_33848 == 130);
	if (cppVar_33850) {
	cppVar_33845 = DPL;
	} else {
	BIT_VEC cppVar_33851;
	BIT_VEC cppVar_33852 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_33853 = (cppVar_33852 << 3) | 4;
	cppVar_33853 = (cppVar_33853 & cppMask_un_5_);
	BIT_VEC cppVar_33854 = (0 << 5) | cppVar_33853;
	cppVar_33854 = (cppVar_33854 & cppMask_un_8_);
	bool cppVar_33856 = (cppVar_33854 == 131);
	if (cppVar_33856) {
	cppVar_33851 = DPH;
	} else {
	BIT_VEC cppVar_33857;
	BIT_VEC cppVar_33858 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_33859 = (cppVar_33858 << 3) | 4;
	cppVar_33859 = (cppVar_33859 & cppMask_un_5_);
	BIT_VEC cppVar_33860 = (0 << 5) | cppVar_33859;
	cppVar_33860 = (cppVar_33860 & cppMask_un_8_);
	bool cppVar_33862 = (cppVar_33860 == 135);
	if (cppVar_33862) {
	cppVar_33857 = PCON;
	} else {
	BIT_VEC cppVar_33863;
	BIT_VEC cppVar_33864 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_33865 = (cppVar_33864 << 3) | 4;
	cppVar_33865 = (cppVar_33865 & cppMask_un_5_);
	BIT_VEC cppVar_33866 = (0 << 5) | cppVar_33865;
	cppVar_33866 = (cppVar_33866 & cppMask_un_8_);
	bool cppVar_33868 = (cppVar_33866 == 136);
	if (cppVar_33868) {
	cppVar_33863 = TCON;
	} else {
	BIT_VEC cppVar_33869;
	BIT_VEC cppVar_33870 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_33871 = (cppVar_33870 << 3) | 4;
	cppVar_33871 = (cppVar_33871 & cppMask_un_5_);
	BIT_VEC cppVar_33872 = (0 << 5) | cppVar_33871;
	cppVar_33872 = (cppVar_33872 & cppMask_un_8_);
	bool cppVar_33874 = (cppVar_33872 == 137);
	if (cppVar_33874) {
	cppVar_33869 = TMOD;
	} else {
	BIT_VEC cppVar_33875;
	BIT_VEC cppVar_33876 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_33877 = (cppVar_33876 << 3) | 4;
	cppVar_33877 = (cppVar_33877 & cppMask_un_5_);
	BIT_VEC cppVar_33878 = (0 << 5) | cppVar_33877;
	cppVar_33878 = (cppVar_33878 & cppMask_un_8_);
	bool cppVar_33880 = (cppVar_33878 == 138);
	if (cppVar_33880) {
	cppVar_33875 = TL0;
	} else {
	BIT_VEC cppVar_33881;
	BIT_VEC cppVar_33882 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_33883 = (cppVar_33882 << 3) | 4;
	cppVar_33883 = (cppVar_33883 & cppMask_un_5_);
	BIT_VEC cppVar_33884 = (0 << 5) | cppVar_33883;
	cppVar_33884 = (cppVar_33884 & cppMask_un_8_);
	bool cppVar_33886 = (cppVar_33884 == 140);
	if (cppVar_33886) {
	cppVar_33881 = TH0;
	} else {
	BIT_VEC cppVar_33887;
	BIT_VEC cppVar_33888 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_33889 = (cppVar_33888 << 3) | 4;
	cppVar_33889 = (cppVar_33889 & cppMask_un_5_);
	BIT_VEC cppVar_33890 = (0 << 5) | cppVar_33889;
	cppVar_33890 = (cppVar_33890 & cppMask_un_8_);
	bool cppVar_33892 = (cppVar_33890 == 139);
	if (cppVar_33892) {
	cppVar_33887 = TL1;
	} else {
	BIT_VEC cppVar_33893;
	BIT_VEC cppVar_33894 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_33895 = (cppVar_33894 << 3) | 4;
	cppVar_33895 = (cppVar_33895 & cppMask_un_5_);
	BIT_VEC cppVar_33896 = (0 << 5) | cppVar_33895;
	cppVar_33896 = (cppVar_33896 & cppMask_un_8_);
	bool cppVar_33898 = (cppVar_33896 == 141);
	if (cppVar_33898) {
	cppVar_33893 = TH1;
	} else {
	BIT_VEC cppVar_33899;
	BIT_VEC cppVar_33900 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_33901 = (cppVar_33900 << 3) | 4;
	cppVar_33901 = (cppVar_33901 & cppMask_un_5_);
	BIT_VEC cppVar_33902 = (0 << 5) | cppVar_33901;
	cppVar_33902 = (cppVar_33902 & cppMask_un_8_);
	bool cppVar_33904 = (cppVar_33902 == 144);
	if (cppVar_33904) {
	cppVar_33899 = P1;
	} else {
	BIT_VEC cppVar_33905;
	BIT_VEC cppVar_33906 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_33907 = (cppVar_33906 << 3) | 4;
	cppVar_33907 = (cppVar_33907 & cppMask_un_5_);
	BIT_VEC cppVar_33908 = (0 << 5) | cppVar_33907;
	cppVar_33908 = (cppVar_33908 & cppMask_un_8_);
	bool cppVar_33910 = (cppVar_33908 == 152);
	if (cppVar_33910) {
	cppVar_33905 = SCON;
	} else {
	BIT_VEC cppVar_33911;
	BIT_VEC cppVar_33912 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_33913 = (cppVar_33912 << 3) | 4;
	cppVar_33913 = (cppVar_33913 & cppMask_un_5_);
	BIT_VEC cppVar_33914 = (0 << 5) | cppVar_33913;
	cppVar_33914 = (cppVar_33914 & cppMask_un_8_);
	bool cppVar_33916 = (cppVar_33914 == 153);
	if (cppVar_33916) {
	cppVar_33911 = SBUF;
	} else {
	BIT_VEC cppVar_33917;
	BIT_VEC cppVar_33918 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_33919 = (cppVar_33918 << 3) | 4;
	cppVar_33919 = (cppVar_33919 & cppMask_un_5_);
	BIT_VEC cppVar_33920 = (0 << 5) | cppVar_33919;
	cppVar_33920 = (cppVar_33920 & cppMask_un_8_);
	bool cppVar_33922 = (cppVar_33920 == 160);
	if (cppVar_33922) {
	cppVar_33917 = P2;
	} else {
	BIT_VEC cppVar_33923;
	BIT_VEC cppVar_33924 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_33925 = (cppVar_33924 << 3) | 4;
	cppVar_33925 = (cppVar_33925 & cppMask_un_5_);
	BIT_VEC cppVar_33926 = (0 << 5) | cppVar_33925;
	cppVar_33926 = (cppVar_33926 & cppMask_un_8_);
	bool cppVar_33928 = (cppVar_33926 == 168);
	if (cppVar_33928) {
	cppVar_33923 = IE;
	} else {
	BIT_VEC cppVar_33929;
	BIT_VEC cppVar_33930 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_33931 = (cppVar_33930 << 3) | 4;
	cppVar_33931 = (cppVar_33931 & cppMask_un_5_);
	BIT_VEC cppVar_33932 = (0 << 5) | cppVar_33931;
	cppVar_33932 = (cppVar_33932 & cppMask_un_8_);
	bool cppVar_33934 = (cppVar_33932 == 176);
	if (cppVar_33934) {
	cppVar_33929 = P3;
	} else {
	BIT_VEC cppVar_33935;
	BIT_VEC cppVar_33936 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_33937 = (cppVar_33936 << 3) | 4;
	cppVar_33937 = (cppVar_33937 & cppMask_un_5_);
	BIT_VEC cppVar_33938 = (0 << 5) | cppVar_33937;
	cppVar_33938 = (cppVar_33938 & cppMask_un_8_);
	bool cppVar_33940 = (cppVar_33938 == 184);
	if (cppVar_33940) {
	cppVar_33935 = IP;
	} else {
	BIT_VEC cppVar_33941;
	BIT_VEC cppVar_33942 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_33943 = (cppVar_33942 << 3) | 4;
	cppVar_33943 = (cppVar_33943 & cppMask_un_5_);
	BIT_VEC cppVar_33944 = (0 << 5) | cppVar_33943;
	cppVar_33944 = (cppVar_33944 & cppMask_un_8_);
	bool cppVar_33946 = (cppVar_33944 == 208);
	if (cppVar_33946) {
	cppVar_33941 = PSW;
	} else {
	BIT_VEC cppVar_33947;
	BIT_VEC cppVar_33948 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_33949 = (cppVar_33948 << 3) | 4;
	cppVar_33949 = (cppVar_33949 & cppMask_un_5_);
	BIT_VEC cppVar_33950 = (0 << 5) | cppVar_33949;
	cppVar_33950 = (cppVar_33950 & cppMask_un_8_);
	bool cppVar_33952 = (cppVar_33950 == 224);
	if (cppVar_33952) {
	cppVar_33947 = ACC;
	} else {
	BIT_VEC cppVar_33953;
	BIT_VEC cppVar_33954 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_33955 = (cppVar_33954 << 3) | 4;
	cppVar_33955 = (cppVar_33955 & cppMask_un_5_);
	BIT_VEC cppVar_33956 = (0 << 5) | cppVar_33955;
	cppVar_33956 = (cppVar_33956 & cppMask_un_8_);
	bool cppVar_33958 = (cppVar_33956 == 240);
	if (cppVar_33958) {
	cppVar_33953 = B;
	} else {
	cppVar_33953 = 0;
	}
	cppVar_33947 = cppVar_33953;
	}
	cppVar_33941 = cppVar_33947;
	}
	cppVar_33935 = cppVar_33941;
	}
	cppVar_33929 = cppVar_33935;
	}
	cppVar_33923 = cppVar_33929;
	}
	cppVar_33917 = cppVar_33923;
	}
	cppVar_33911 = cppVar_33917;
	}
	cppVar_33905 = cppVar_33911;
	}
	cppVar_33899 = cppVar_33905;
	}
	cppVar_33893 = cppVar_33899;
	}
	cppVar_33887 = cppVar_33893;
	}
	cppVar_33881 = cppVar_33887;
	}
	cppVar_33875 = cppVar_33881;
	}
	cppVar_33869 = cppVar_33875;
	}
	cppVar_33863 = cppVar_33869;
	}
	cppVar_33857 = cppVar_33863;
	}
	cppVar_33851 = cppVar_33857;
	}
	cppVar_33845 = cppVar_33851;
	}
	cppVar_33839 = cppVar_33845;
	}
	cppVar_33833 = cppVar_33839;
	}
	cppVar_33820 = cppVar_33833;
	}
	cppVar_33814 = cppVar_33820;
	} else {
	cppVar_33814 = P2;
	}
	cppVar_33810 = cppVar_33814;
	} else {
	BIT_VEC cppVar_33960;
	BIT_VEC cppVar_33961 = ROM.rd(PC);
	bool cppVar_33963 = (cppVar_33961 == 139);
	if (cppVar_33963) {
	BIT_VEC cppVar_33964;
	BIT_VEC cppVar_33966 = PC + 1;
	cppVar_33966 = (cppVar_33966 & cppMask_un_16_);
	BIT_VEC cppVar_33967 = ROM.rd(cppVar_33966);
	bool cppVar_33969 = (cppVar_33967 == 160);
	if (cppVar_33969) {
	BIT_VEC cppVar_33970;
	BIT_VEC cppVar_33972 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_33974 = (cppVar_33972 << 3) | 3;
	cppVar_33974 = (cppVar_33974 & cppMask_un_5_);
	BIT_VEC cppVar_33975 = (0 << 5) | cppVar_33974;
	cppVar_33975 = (cppVar_33975 & cppMask_un_8_);
	BIT_VEC cppVar_33976 = (cppVar_33975 >> 7) & cppMask_un_1_;
	bool cppVar_33978 = (cppVar_33976 == 0);
	if (cppVar_33978) {
	BIT_VEC cppVar_33979 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_33980 = (cppVar_33979 << 3) | 3;
	cppVar_33980 = (cppVar_33980 & cppMask_un_5_);
	BIT_VEC cppVar_33981 = (0 << 5) | cppVar_33980;
	cppVar_33981 = (cppVar_33981 & cppMask_un_8_);
	BIT_VEC cppVar_33982 = IRAM.rd(cppVar_33981);
	cppVar_33970 = cppVar_33982;
	} else {
	BIT_VEC cppVar_33983;
	BIT_VEC cppVar_33984 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_33985 = (cppVar_33984 << 3) | 3;
	cppVar_33985 = (cppVar_33985 & cppMask_un_5_);
	BIT_VEC cppVar_33986 = (0 << 5) | cppVar_33985;
	cppVar_33986 = (cppVar_33986 & cppMask_un_8_);
	bool cppVar_33988 = (cppVar_33986 == 128);
	if (cppVar_33988) {
	cppVar_33983 = P0;
	} else {
	BIT_VEC cppVar_33989;
	BIT_VEC cppVar_33990 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_33991 = (cppVar_33990 << 3) | 3;
	cppVar_33991 = (cppVar_33991 & cppMask_un_5_);
	BIT_VEC cppVar_33992 = (0 << 5) | cppVar_33991;
	cppVar_33992 = (cppVar_33992 & cppMask_un_8_);
	bool cppVar_33994 = (cppVar_33992 == 129);
	if (cppVar_33994) {
	cppVar_33989 = SP;
	} else {
	BIT_VEC cppVar_33995;
	BIT_VEC cppVar_33996 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_33997 = (cppVar_33996 << 3) | 3;
	cppVar_33997 = (cppVar_33997 & cppMask_un_5_);
	BIT_VEC cppVar_33998 = (0 << 5) | cppVar_33997;
	cppVar_33998 = (cppVar_33998 & cppMask_un_8_);
	bool cppVar_34000 = (cppVar_33998 == 130);
	if (cppVar_34000) {
	cppVar_33995 = DPL;
	} else {
	BIT_VEC cppVar_34001;
	BIT_VEC cppVar_34002 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_34003 = (cppVar_34002 << 3) | 3;
	cppVar_34003 = (cppVar_34003 & cppMask_un_5_);
	BIT_VEC cppVar_34004 = (0 << 5) | cppVar_34003;
	cppVar_34004 = (cppVar_34004 & cppMask_un_8_);
	bool cppVar_34006 = (cppVar_34004 == 131);
	if (cppVar_34006) {
	cppVar_34001 = DPH;
	} else {
	BIT_VEC cppVar_34007;
	BIT_VEC cppVar_34008 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_34009 = (cppVar_34008 << 3) | 3;
	cppVar_34009 = (cppVar_34009 & cppMask_un_5_);
	BIT_VEC cppVar_34010 = (0 << 5) | cppVar_34009;
	cppVar_34010 = (cppVar_34010 & cppMask_un_8_);
	bool cppVar_34012 = (cppVar_34010 == 135);
	if (cppVar_34012) {
	cppVar_34007 = PCON;
	} else {
	BIT_VEC cppVar_34013;
	BIT_VEC cppVar_34014 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_34015 = (cppVar_34014 << 3) | 3;
	cppVar_34015 = (cppVar_34015 & cppMask_un_5_);
	BIT_VEC cppVar_34016 = (0 << 5) | cppVar_34015;
	cppVar_34016 = (cppVar_34016 & cppMask_un_8_);
	bool cppVar_34018 = (cppVar_34016 == 136);
	if (cppVar_34018) {
	cppVar_34013 = TCON;
	} else {
	BIT_VEC cppVar_34019;
	BIT_VEC cppVar_34020 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_34021 = (cppVar_34020 << 3) | 3;
	cppVar_34021 = (cppVar_34021 & cppMask_un_5_);
	BIT_VEC cppVar_34022 = (0 << 5) | cppVar_34021;
	cppVar_34022 = (cppVar_34022 & cppMask_un_8_);
	bool cppVar_34024 = (cppVar_34022 == 137);
	if (cppVar_34024) {
	cppVar_34019 = TMOD;
	} else {
	BIT_VEC cppVar_34025;
	BIT_VEC cppVar_34026 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_34027 = (cppVar_34026 << 3) | 3;
	cppVar_34027 = (cppVar_34027 & cppMask_un_5_);
	BIT_VEC cppVar_34028 = (0 << 5) | cppVar_34027;
	cppVar_34028 = (cppVar_34028 & cppMask_un_8_);
	bool cppVar_34030 = (cppVar_34028 == 138);
	if (cppVar_34030) {
	cppVar_34025 = TL0;
	} else {
	BIT_VEC cppVar_34031;
	BIT_VEC cppVar_34032 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_34033 = (cppVar_34032 << 3) | 3;
	cppVar_34033 = (cppVar_34033 & cppMask_un_5_);
	BIT_VEC cppVar_34034 = (0 << 5) | cppVar_34033;
	cppVar_34034 = (cppVar_34034 & cppMask_un_8_);
	bool cppVar_34036 = (cppVar_34034 == 140);
	if (cppVar_34036) {
	cppVar_34031 = TH0;
	} else {
	BIT_VEC cppVar_34037;
	BIT_VEC cppVar_34038 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_34039 = (cppVar_34038 << 3) | 3;
	cppVar_34039 = (cppVar_34039 & cppMask_un_5_);
	BIT_VEC cppVar_34040 = (0 << 5) | cppVar_34039;
	cppVar_34040 = (cppVar_34040 & cppMask_un_8_);
	bool cppVar_34042 = (cppVar_34040 == 139);
	if (cppVar_34042) {
	cppVar_34037 = TL1;
	} else {
	BIT_VEC cppVar_34043;
	BIT_VEC cppVar_34044 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_34045 = (cppVar_34044 << 3) | 3;
	cppVar_34045 = (cppVar_34045 & cppMask_un_5_);
	BIT_VEC cppVar_34046 = (0 << 5) | cppVar_34045;
	cppVar_34046 = (cppVar_34046 & cppMask_un_8_);
	bool cppVar_34048 = (cppVar_34046 == 141);
	if (cppVar_34048) {
	cppVar_34043 = TH1;
	} else {
	BIT_VEC cppVar_34049;
	BIT_VEC cppVar_34050 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_34051 = (cppVar_34050 << 3) | 3;
	cppVar_34051 = (cppVar_34051 & cppMask_un_5_);
	BIT_VEC cppVar_34052 = (0 << 5) | cppVar_34051;
	cppVar_34052 = (cppVar_34052 & cppMask_un_8_);
	bool cppVar_34054 = (cppVar_34052 == 144);
	if (cppVar_34054) {
	cppVar_34049 = P1;
	} else {
	BIT_VEC cppVar_34055;
	BIT_VEC cppVar_34056 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_34057 = (cppVar_34056 << 3) | 3;
	cppVar_34057 = (cppVar_34057 & cppMask_un_5_);
	BIT_VEC cppVar_34058 = (0 << 5) | cppVar_34057;
	cppVar_34058 = (cppVar_34058 & cppMask_un_8_);
	bool cppVar_34060 = (cppVar_34058 == 152);
	if (cppVar_34060) {
	cppVar_34055 = SCON;
	} else {
	BIT_VEC cppVar_34061;
	BIT_VEC cppVar_34062 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_34063 = (cppVar_34062 << 3) | 3;
	cppVar_34063 = (cppVar_34063 & cppMask_un_5_);
	BIT_VEC cppVar_34064 = (0 << 5) | cppVar_34063;
	cppVar_34064 = (cppVar_34064 & cppMask_un_8_);
	bool cppVar_34066 = (cppVar_34064 == 153);
	if (cppVar_34066) {
	cppVar_34061 = SBUF;
	} else {
	BIT_VEC cppVar_34067;
	BIT_VEC cppVar_34068 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_34069 = (cppVar_34068 << 3) | 3;
	cppVar_34069 = (cppVar_34069 & cppMask_un_5_);
	BIT_VEC cppVar_34070 = (0 << 5) | cppVar_34069;
	cppVar_34070 = (cppVar_34070 & cppMask_un_8_);
	bool cppVar_34072 = (cppVar_34070 == 160);
	if (cppVar_34072) {
	cppVar_34067 = P2;
	} else {
	BIT_VEC cppVar_34073;
	BIT_VEC cppVar_34074 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_34075 = (cppVar_34074 << 3) | 3;
	cppVar_34075 = (cppVar_34075 & cppMask_un_5_);
	BIT_VEC cppVar_34076 = (0 << 5) | cppVar_34075;
	cppVar_34076 = (cppVar_34076 & cppMask_un_8_);
	bool cppVar_34078 = (cppVar_34076 == 168);
	if (cppVar_34078) {
	cppVar_34073 = IE;
	} else {
	BIT_VEC cppVar_34079;
	BIT_VEC cppVar_34080 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_34081 = (cppVar_34080 << 3) | 3;
	cppVar_34081 = (cppVar_34081 & cppMask_un_5_);
	BIT_VEC cppVar_34082 = (0 << 5) | cppVar_34081;
	cppVar_34082 = (cppVar_34082 & cppMask_un_8_);
	bool cppVar_34084 = (cppVar_34082 == 176);
	if (cppVar_34084) {
	cppVar_34079 = P3;
	} else {
	BIT_VEC cppVar_34085;
	BIT_VEC cppVar_34086 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_34087 = (cppVar_34086 << 3) | 3;
	cppVar_34087 = (cppVar_34087 & cppMask_un_5_);
	BIT_VEC cppVar_34088 = (0 << 5) | cppVar_34087;
	cppVar_34088 = (cppVar_34088 & cppMask_un_8_);
	bool cppVar_34090 = (cppVar_34088 == 184);
	if (cppVar_34090) {
	cppVar_34085 = IP;
	} else {
	BIT_VEC cppVar_34091;
	BIT_VEC cppVar_34092 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_34093 = (cppVar_34092 << 3) | 3;
	cppVar_34093 = (cppVar_34093 & cppMask_un_5_);
	BIT_VEC cppVar_34094 = (0 << 5) | cppVar_34093;
	cppVar_34094 = (cppVar_34094 & cppMask_un_8_);
	bool cppVar_34096 = (cppVar_34094 == 208);
	if (cppVar_34096) {
	cppVar_34091 = PSW;
	} else {
	BIT_VEC cppVar_34097;
	BIT_VEC cppVar_34098 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_34099 = (cppVar_34098 << 3) | 3;
	cppVar_34099 = (cppVar_34099 & cppMask_un_5_);
	BIT_VEC cppVar_34100 = (0 << 5) | cppVar_34099;
	cppVar_34100 = (cppVar_34100 & cppMask_un_8_);
	bool cppVar_34102 = (cppVar_34100 == 224);
	if (cppVar_34102) {
	cppVar_34097 = ACC;
	} else {
	BIT_VEC cppVar_34103;
	BIT_VEC cppVar_34104 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_34105 = (cppVar_34104 << 3) | 3;
	cppVar_34105 = (cppVar_34105 & cppMask_un_5_);
	BIT_VEC cppVar_34106 = (0 << 5) | cppVar_34105;
	cppVar_34106 = (cppVar_34106 & cppMask_un_8_);
	bool cppVar_34108 = (cppVar_34106 == 240);
	if (cppVar_34108) {
	cppVar_34103 = B;
	} else {
	cppVar_34103 = 0;
	}
	cppVar_34097 = cppVar_34103;
	}
	cppVar_34091 = cppVar_34097;
	}
	cppVar_34085 = cppVar_34091;
	}
	cppVar_34079 = cppVar_34085;
	}
	cppVar_34073 = cppVar_34079;
	}
	cppVar_34067 = cppVar_34073;
	}
	cppVar_34061 = cppVar_34067;
	}
	cppVar_34055 = cppVar_34061;
	}
	cppVar_34049 = cppVar_34055;
	}
	cppVar_34043 = cppVar_34049;
	}
	cppVar_34037 = cppVar_34043;
	}
	cppVar_34031 = cppVar_34037;
	}
	cppVar_34025 = cppVar_34031;
	}
	cppVar_34019 = cppVar_34025;
	}
	cppVar_34013 = cppVar_34019;
	}
	cppVar_34007 = cppVar_34013;
	}
	cppVar_34001 = cppVar_34007;
	}
	cppVar_33995 = cppVar_34001;
	}
	cppVar_33989 = cppVar_33995;
	}
	cppVar_33983 = cppVar_33989;
	}
	cppVar_33970 = cppVar_33983;
	}
	cppVar_33964 = cppVar_33970;
	} else {
	cppVar_33964 = P2;
	}
	cppVar_33960 = cppVar_33964;
	} else {
	BIT_VEC cppVar_34110;
	BIT_VEC cppVar_34111 = ROM.rd(PC);
	bool cppVar_34113 = (cppVar_34111 == 138);
	if (cppVar_34113) {
	BIT_VEC cppVar_34114;
	BIT_VEC cppVar_34116 = PC + 1;
	cppVar_34116 = (cppVar_34116 & cppMask_un_16_);
	BIT_VEC cppVar_34117 = ROM.rd(cppVar_34116);
	bool cppVar_34119 = (cppVar_34117 == 160);
	if (cppVar_34119) {
	BIT_VEC cppVar_34120;
	BIT_VEC cppVar_34122 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_34124 = (cppVar_34122 << 3) | 2;
	cppVar_34124 = (cppVar_34124 & cppMask_un_5_);
	BIT_VEC cppVar_34125 = (0 << 5) | cppVar_34124;
	cppVar_34125 = (cppVar_34125 & cppMask_un_8_);
	BIT_VEC cppVar_34126 = (cppVar_34125 >> 7) & cppMask_un_1_;
	bool cppVar_34128 = (cppVar_34126 == 0);
	if (cppVar_34128) {
	BIT_VEC cppVar_34129 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_34130 = (cppVar_34129 << 3) | 2;
	cppVar_34130 = (cppVar_34130 & cppMask_un_5_);
	BIT_VEC cppVar_34131 = (0 << 5) | cppVar_34130;
	cppVar_34131 = (cppVar_34131 & cppMask_un_8_);
	BIT_VEC cppVar_34132 = IRAM.rd(cppVar_34131);
	cppVar_34120 = cppVar_34132;
	} else {
	BIT_VEC cppVar_34133;
	BIT_VEC cppVar_34134 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_34135 = (cppVar_34134 << 3) | 2;
	cppVar_34135 = (cppVar_34135 & cppMask_un_5_);
	BIT_VEC cppVar_34136 = (0 << 5) | cppVar_34135;
	cppVar_34136 = (cppVar_34136 & cppMask_un_8_);
	bool cppVar_34138 = (cppVar_34136 == 128);
	if (cppVar_34138) {
	cppVar_34133 = P0;
	} else {
	BIT_VEC cppVar_34139;
	BIT_VEC cppVar_34140 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_34141 = (cppVar_34140 << 3) | 2;
	cppVar_34141 = (cppVar_34141 & cppMask_un_5_);
	BIT_VEC cppVar_34142 = (0 << 5) | cppVar_34141;
	cppVar_34142 = (cppVar_34142 & cppMask_un_8_);
	bool cppVar_34144 = (cppVar_34142 == 129);
	if (cppVar_34144) {
	cppVar_34139 = SP;
	} else {
	BIT_VEC cppVar_34145;
	BIT_VEC cppVar_34146 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_34147 = (cppVar_34146 << 3) | 2;
	cppVar_34147 = (cppVar_34147 & cppMask_un_5_);
	BIT_VEC cppVar_34148 = (0 << 5) | cppVar_34147;
	cppVar_34148 = (cppVar_34148 & cppMask_un_8_);
	bool cppVar_34150 = (cppVar_34148 == 130);
	if (cppVar_34150) {
	cppVar_34145 = DPL;
	} else {
	BIT_VEC cppVar_34151;
	BIT_VEC cppVar_34152 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_34153 = (cppVar_34152 << 3) | 2;
	cppVar_34153 = (cppVar_34153 & cppMask_un_5_);
	BIT_VEC cppVar_34154 = (0 << 5) | cppVar_34153;
	cppVar_34154 = (cppVar_34154 & cppMask_un_8_);
	bool cppVar_34156 = (cppVar_34154 == 131);
	if (cppVar_34156) {
	cppVar_34151 = DPH;
	} else {
	BIT_VEC cppVar_34157;
	BIT_VEC cppVar_34158 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_34159 = (cppVar_34158 << 3) | 2;
	cppVar_34159 = (cppVar_34159 & cppMask_un_5_);
	BIT_VEC cppVar_34160 = (0 << 5) | cppVar_34159;
	cppVar_34160 = (cppVar_34160 & cppMask_un_8_);
	bool cppVar_34162 = (cppVar_34160 == 135);
	if (cppVar_34162) {
	cppVar_34157 = PCON;
	} else {
	BIT_VEC cppVar_34163;
	BIT_VEC cppVar_34164 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_34165 = (cppVar_34164 << 3) | 2;
	cppVar_34165 = (cppVar_34165 & cppMask_un_5_);
	BIT_VEC cppVar_34166 = (0 << 5) | cppVar_34165;
	cppVar_34166 = (cppVar_34166 & cppMask_un_8_);
	bool cppVar_34168 = (cppVar_34166 == 136);
	if (cppVar_34168) {
	cppVar_34163 = TCON;
	} else {
	BIT_VEC cppVar_34169;
	BIT_VEC cppVar_34170 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_34171 = (cppVar_34170 << 3) | 2;
	cppVar_34171 = (cppVar_34171 & cppMask_un_5_);
	BIT_VEC cppVar_34172 = (0 << 5) | cppVar_34171;
	cppVar_34172 = (cppVar_34172 & cppMask_un_8_);
	bool cppVar_34174 = (cppVar_34172 == 137);
	if (cppVar_34174) {
	cppVar_34169 = TMOD;
	} else {
	BIT_VEC cppVar_34175;
	BIT_VEC cppVar_34176 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_34177 = (cppVar_34176 << 3) | 2;
	cppVar_34177 = (cppVar_34177 & cppMask_un_5_);
	BIT_VEC cppVar_34178 = (0 << 5) | cppVar_34177;
	cppVar_34178 = (cppVar_34178 & cppMask_un_8_);
	bool cppVar_34180 = (cppVar_34178 == 138);
	if (cppVar_34180) {
	cppVar_34175 = TL0;
	} else {
	BIT_VEC cppVar_34181;
	BIT_VEC cppVar_34182 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_34183 = (cppVar_34182 << 3) | 2;
	cppVar_34183 = (cppVar_34183 & cppMask_un_5_);
	BIT_VEC cppVar_34184 = (0 << 5) | cppVar_34183;
	cppVar_34184 = (cppVar_34184 & cppMask_un_8_);
	bool cppVar_34186 = (cppVar_34184 == 140);
	if (cppVar_34186) {
	cppVar_34181 = TH0;
	} else {
	BIT_VEC cppVar_34187;
	BIT_VEC cppVar_34188 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_34189 = (cppVar_34188 << 3) | 2;
	cppVar_34189 = (cppVar_34189 & cppMask_un_5_);
	BIT_VEC cppVar_34190 = (0 << 5) | cppVar_34189;
	cppVar_34190 = (cppVar_34190 & cppMask_un_8_);
	bool cppVar_34192 = (cppVar_34190 == 139);
	if (cppVar_34192) {
	cppVar_34187 = TL1;
	} else {
	BIT_VEC cppVar_34193;
	BIT_VEC cppVar_34194 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_34195 = (cppVar_34194 << 3) | 2;
	cppVar_34195 = (cppVar_34195 & cppMask_un_5_);
	BIT_VEC cppVar_34196 = (0 << 5) | cppVar_34195;
	cppVar_34196 = (cppVar_34196 & cppMask_un_8_);
	bool cppVar_34198 = (cppVar_34196 == 141);
	if (cppVar_34198) {
	cppVar_34193 = TH1;
	} else {
	BIT_VEC cppVar_34199;
	BIT_VEC cppVar_34200 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_34201 = (cppVar_34200 << 3) | 2;
	cppVar_34201 = (cppVar_34201 & cppMask_un_5_);
	BIT_VEC cppVar_34202 = (0 << 5) | cppVar_34201;
	cppVar_34202 = (cppVar_34202 & cppMask_un_8_);
	bool cppVar_34204 = (cppVar_34202 == 144);
	if (cppVar_34204) {
	cppVar_34199 = P1;
	} else {
	BIT_VEC cppVar_34205;
	BIT_VEC cppVar_34206 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_34207 = (cppVar_34206 << 3) | 2;
	cppVar_34207 = (cppVar_34207 & cppMask_un_5_);
	BIT_VEC cppVar_34208 = (0 << 5) | cppVar_34207;
	cppVar_34208 = (cppVar_34208 & cppMask_un_8_);
	bool cppVar_34210 = (cppVar_34208 == 152);
	if (cppVar_34210) {
	cppVar_34205 = SCON;
	} else {
	BIT_VEC cppVar_34211;
	BIT_VEC cppVar_34212 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_34213 = (cppVar_34212 << 3) | 2;
	cppVar_34213 = (cppVar_34213 & cppMask_un_5_);
	BIT_VEC cppVar_34214 = (0 << 5) | cppVar_34213;
	cppVar_34214 = (cppVar_34214 & cppMask_un_8_);
	bool cppVar_34216 = (cppVar_34214 == 153);
	if (cppVar_34216) {
	cppVar_34211 = SBUF;
	} else {
	BIT_VEC cppVar_34217;
	BIT_VEC cppVar_34218 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_34219 = (cppVar_34218 << 3) | 2;
	cppVar_34219 = (cppVar_34219 & cppMask_un_5_);
	BIT_VEC cppVar_34220 = (0 << 5) | cppVar_34219;
	cppVar_34220 = (cppVar_34220 & cppMask_un_8_);
	bool cppVar_34222 = (cppVar_34220 == 160);
	if (cppVar_34222) {
	cppVar_34217 = P2;
	} else {
	BIT_VEC cppVar_34223;
	BIT_VEC cppVar_34224 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_34225 = (cppVar_34224 << 3) | 2;
	cppVar_34225 = (cppVar_34225 & cppMask_un_5_);
	BIT_VEC cppVar_34226 = (0 << 5) | cppVar_34225;
	cppVar_34226 = (cppVar_34226 & cppMask_un_8_);
	bool cppVar_34228 = (cppVar_34226 == 168);
	if (cppVar_34228) {
	cppVar_34223 = IE;
	} else {
	BIT_VEC cppVar_34229;
	BIT_VEC cppVar_34230 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_34231 = (cppVar_34230 << 3) | 2;
	cppVar_34231 = (cppVar_34231 & cppMask_un_5_);
	BIT_VEC cppVar_34232 = (0 << 5) | cppVar_34231;
	cppVar_34232 = (cppVar_34232 & cppMask_un_8_);
	bool cppVar_34234 = (cppVar_34232 == 176);
	if (cppVar_34234) {
	cppVar_34229 = P3;
	} else {
	BIT_VEC cppVar_34235;
	BIT_VEC cppVar_34236 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_34237 = (cppVar_34236 << 3) | 2;
	cppVar_34237 = (cppVar_34237 & cppMask_un_5_);
	BIT_VEC cppVar_34238 = (0 << 5) | cppVar_34237;
	cppVar_34238 = (cppVar_34238 & cppMask_un_8_);
	bool cppVar_34240 = (cppVar_34238 == 184);
	if (cppVar_34240) {
	cppVar_34235 = IP;
	} else {
	BIT_VEC cppVar_34241;
	BIT_VEC cppVar_34242 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_34243 = (cppVar_34242 << 3) | 2;
	cppVar_34243 = (cppVar_34243 & cppMask_un_5_);
	BIT_VEC cppVar_34244 = (0 << 5) | cppVar_34243;
	cppVar_34244 = (cppVar_34244 & cppMask_un_8_);
	bool cppVar_34246 = (cppVar_34244 == 208);
	if (cppVar_34246) {
	cppVar_34241 = PSW;
	} else {
	BIT_VEC cppVar_34247;
	BIT_VEC cppVar_34248 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_34249 = (cppVar_34248 << 3) | 2;
	cppVar_34249 = (cppVar_34249 & cppMask_un_5_);
	BIT_VEC cppVar_34250 = (0 << 5) | cppVar_34249;
	cppVar_34250 = (cppVar_34250 & cppMask_un_8_);
	bool cppVar_34252 = (cppVar_34250 == 224);
	if (cppVar_34252) {
	cppVar_34247 = ACC;
	} else {
	BIT_VEC cppVar_34253;
	BIT_VEC cppVar_34254 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_34255 = (cppVar_34254 << 3) | 2;
	cppVar_34255 = (cppVar_34255 & cppMask_un_5_);
	BIT_VEC cppVar_34256 = (0 << 5) | cppVar_34255;
	cppVar_34256 = (cppVar_34256 & cppMask_un_8_);
	bool cppVar_34258 = (cppVar_34256 == 240);
	if (cppVar_34258) {
	cppVar_34253 = B;
	} else {
	cppVar_34253 = 0;
	}
	cppVar_34247 = cppVar_34253;
	}
	cppVar_34241 = cppVar_34247;
	}
	cppVar_34235 = cppVar_34241;
	}
	cppVar_34229 = cppVar_34235;
	}
	cppVar_34223 = cppVar_34229;
	}
	cppVar_34217 = cppVar_34223;
	}
	cppVar_34211 = cppVar_34217;
	}
	cppVar_34205 = cppVar_34211;
	}
	cppVar_34199 = cppVar_34205;
	}
	cppVar_34193 = cppVar_34199;
	}
	cppVar_34187 = cppVar_34193;
	}
	cppVar_34181 = cppVar_34187;
	}
	cppVar_34175 = cppVar_34181;
	}
	cppVar_34169 = cppVar_34175;
	}
	cppVar_34163 = cppVar_34169;
	}
	cppVar_34157 = cppVar_34163;
	}
	cppVar_34151 = cppVar_34157;
	}
	cppVar_34145 = cppVar_34151;
	}
	cppVar_34139 = cppVar_34145;
	}
	cppVar_34133 = cppVar_34139;
	}
	cppVar_34120 = cppVar_34133;
	}
	cppVar_34114 = cppVar_34120;
	} else {
	cppVar_34114 = P2;
	}
	cppVar_34110 = cppVar_34114;
	} else {
	BIT_VEC cppVar_34260;
	BIT_VEC cppVar_34261 = ROM.rd(PC);
	bool cppVar_34263 = (cppVar_34261 == 137);
	if (cppVar_34263) {
	BIT_VEC cppVar_34264;
	BIT_VEC cppVar_34266 = PC + 1;
	cppVar_34266 = (cppVar_34266 & cppMask_un_16_);
	BIT_VEC cppVar_34267 = ROM.rd(cppVar_34266);
	bool cppVar_34269 = (cppVar_34267 == 160);
	if (cppVar_34269) {
	BIT_VEC cppVar_34270;
	BIT_VEC cppVar_34272 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_34274 = (cppVar_34272 << 3) | 1;
	cppVar_34274 = (cppVar_34274 & cppMask_un_5_);
	BIT_VEC cppVar_34275 = (0 << 5) | cppVar_34274;
	cppVar_34275 = (cppVar_34275 & cppMask_un_8_);
	BIT_VEC cppVar_34276 = (cppVar_34275 >> 7) & cppMask_un_1_;
	bool cppVar_34278 = (cppVar_34276 == 0);
	if (cppVar_34278) {
	BIT_VEC cppVar_34279 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_34280 = (cppVar_34279 << 3) | 1;
	cppVar_34280 = (cppVar_34280 & cppMask_un_5_);
	BIT_VEC cppVar_34281 = (0 << 5) | cppVar_34280;
	cppVar_34281 = (cppVar_34281 & cppMask_un_8_);
	BIT_VEC cppVar_34282 = IRAM.rd(cppVar_34281);
	cppVar_34270 = cppVar_34282;
	} else {
	BIT_VEC cppVar_34283;
	BIT_VEC cppVar_34284 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_34285 = (cppVar_34284 << 3) | 1;
	cppVar_34285 = (cppVar_34285 & cppMask_un_5_);
	BIT_VEC cppVar_34286 = (0 << 5) | cppVar_34285;
	cppVar_34286 = (cppVar_34286 & cppMask_un_8_);
	bool cppVar_34288 = (cppVar_34286 == 128);
	if (cppVar_34288) {
	cppVar_34283 = P0;
	} else {
	BIT_VEC cppVar_34289;
	BIT_VEC cppVar_34290 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_34291 = (cppVar_34290 << 3) | 1;
	cppVar_34291 = (cppVar_34291 & cppMask_un_5_);
	BIT_VEC cppVar_34292 = (0 << 5) | cppVar_34291;
	cppVar_34292 = (cppVar_34292 & cppMask_un_8_);
	bool cppVar_34294 = (cppVar_34292 == 129);
	if (cppVar_34294) {
	cppVar_34289 = SP;
	} else {
	BIT_VEC cppVar_34295;
	BIT_VEC cppVar_34296 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_34297 = (cppVar_34296 << 3) | 1;
	cppVar_34297 = (cppVar_34297 & cppMask_un_5_);
	BIT_VEC cppVar_34298 = (0 << 5) | cppVar_34297;
	cppVar_34298 = (cppVar_34298 & cppMask_un_8_);
	bool cppVar_34300 = (cppVar_34298 == 130);
	if (cppVar_34300) {
	cppVar_34295 = DPL;
	} else {
	BIT_VEC cppVar_34301;
	BIT_VEC cppVar_34302 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_34303 = (cppVar_34302 << 3) | 1;
	cppVar_34303 = (cppVar_34303 & cppMask_un_5_);
	BIT_VEC cppVar_34304 = (0 << 5) | cppVar_34303;
	cppVar_34304 = (cppVar_34304 & cppMask_un_8_);
	bool cppVar_34306 = (cppVar_34304 == 131);
	if (cppVar_34306) {
	cppVar_34301 = DPH;
	} else {
	BIT_VEC cppVar_34307;
	BIT_VEC cppVar_34308 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_34309 = (cppVar_34308 << 3) | 1;
	cppVar_34309 = (cppVar_34309 & cppMask_un_5_);
	BIT_VEC cppVar_34310 = (0 << 5) | cppVar_34309;
	cppVar_34310 = (cppVar_34310 & cppMask_un_8_);
	bool cppVar_34312 = (cppVar_34310 == 135);
	if (cppVar_34312) {
	cppVar_34307 = PCON;
	} else {
	BIT_VEC cppVar_34313;
	BIT_VEC cppVar_34314 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_34315 = (cppVar_34314 << 3) | 1;
	cppVar_34315 = (cppVar_34315 & cppMask_un_5_);
	BIT_VEC cppVar_34316 = (0 << 5) | cppVar_34315;
	cppVar_34316 = (cppVar_34316 & cppMask_un_8_);
	bool cppVar_34318 = (cppVar_34316 == 136);
	if (cppVar_34318) {
	cppVar_34313 = TCON;
	} else {
	BIT_VEC cppVar_34319;
	BIT_VEC cppVar_34320 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_34321 = (cppVar_34320 << 3) | 1;
	cppVar_34321 = (cppVar_34321 & cppMask_un_5_);
	BIT_VEC cppVar_34322 = (0 << 5) | cppVar_34321;
	cppVar_34322 = (cppVar_34322 & cppMask_un_8_);
	bool cppVar_34324 = (cppVar_34322 == 137);
	if (cppVar_34324) {
	cppVar_34319 = TMOD;
	} else {
	BIT_VEC cppVar_34325;
	BIT_VEC cppVar_34326 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_34327 = (cppVar_34326 << 3) | 1;
	cppVar_34327 = (cppVar_34327 & cppMask_un_5_);
	BIT_VEC cppVar_34328 = (0 << 5) | cppVar_34327;
	cppVar_34328 = (cppVar_34328 & cppMask_un_8_);
	bool cppVar_34330 = (cppVar_34328 == 138);
	if (cppVar_34330) {
	cppVar_34325 = TL0;
	} else {
	BIT_VEC cppVar_34331;
	BIT_VEC cppVar_34332 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_34333 = (cppVar_34332 << 3) | 1;
	cppVar_34333 = (cppVar_34333 & cppMask_un_5_);
	BIT_VEC cppVar_34334 = (0 << 5) | cppVar_34333;
	cppVar_34334 = (cppVar_34334 & cppMask_un_8_);
	bool cppVar_34336 = (cppVar_34334 == 140);
	if (cppVar_34336) {
	cppVar_34331 = TH0;
	} else {
	BIT_VEC cppVar_34337;
	BIT_VEC cppVar_34338 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_34339 = (cppVar_34338 << 3) | 1;
	cppVar_34339 = (cppVar_34339 & cppMask_un_5_);
	BIT_VEC cppVar_34340 = (0 << 5) | cppVar_34339;
	cppVar_34340 = (cppVar_34340 & cppMask_un_8_);
	bool cppVar_34342 = (cppVar_34340 == 139);
	if (cppVar_34342) {
	cppVar_34337 = TL1;
	} else {
	BIT_VEC cppVar_34343;
	BIT_VEC cppVar_34344 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_34345 = (cppVar_34344 << 3) | 1;
	cppVar_34345 = (cppVar_34345 & cppMask_un_5_);
	BIT_VEC cppVar_34346 = (0 << 5) | cppVar_34345;
	cppVar_34346 = (cppVar_34346 & cppMask_un_8_);
	bool cppVar_34348 = (cppVar_34346 == 141);
	if (cppVar_34348) {
	cppVar_34343 = TH1;
	} else {
	BIT_VEC cppVar_34349;
	BIT_VEC cppVar_34350 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_34351 = (cppVar_34350 << 3) | 1;
	cppVar_34351 = (cppVar_34351 & cppMask_un_5_);
	BIT_VEC cppVar_34352 = (0 << 5) | cppVar_34351;
	cppVar_34352 = (cppVar_34352 & cppMask_un_8_);
	bool cppVar_34354 = (cppVar_34352 == 144);
	if (cppVar_34354) {
	cppVar_34349 = P1;
	} else {
	BIT_VEC cppVar_34355;
	BIT_VEC cppVar_34356 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_34357 = (cppVar_34356 << 3) | 1;
	cppVar_34357 = (cppVar_34357 & cppMask_un_5_);
	BIT_VEC cppVar_34358 = (0 << 5) | cppVar_34357;
	cppVar_34358 = (cppVar_34358 & cppMask_un_8_);
	bool cppVar_34360 = (cppVar_34358 == 152);
	if (cppVar_34360) {
	cppVar_34355 = SCON;
	} else {
	BIT_VEC cppVar_34361;
	BIT_VEC cppVar_34362 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_34363 = (cppVar_34362 << 3) | 1;
	cppVar_34363 = (cppVar_34363 & cppMask_un_5_);
	BIT_VEC cppVar_34364 = (0 << 5) | cppVar_34363;
	cppVar_34364 = (cppVar_34364 & cppMask_un_8_);
	bool cppVar_34366 = (cppVar_34364 == 153);
	if (cppVar_34366) {
	cppVar_34361 = SBUF;
	} else {
	BIT_VEC cppVar_34367;
	BIT_VEC cppVar_34368 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_34369 = (cppVar_34368 << 3) | 1;
	cppVar_34369 = (cppVar_34369 & cppMask_un_5_);
	BIT_VEC cppVar_34370 = (0 << 5) | cppVar_34369;
	cppVar_34370 = (cppVar_34370 & cppMask_un_8_);
	bool cppVar_34372 = (cppVar_34370 == 160);
	if (cppVar_34372) {
	cppVar_34367 = P2;
	} else {
	BIT_VEC cppVar_34373;
	BIT_VEC cppVar_34374 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_34375 = (cppVar_34374 << 3) | 1;
	cppVar_34375 = (cppVar_34375 & cppMask_un_5_);
	BIT_VEC cppVar_34376 = (0 << 5) | cppVar_34375;
	cppVar_34376 = (cppVar_34376 & cppMask_un_8_);
	bool cppVar_34378 = (cppVar_34376 == 168);
	if (cppVar_34378) {
	cppVar_34373 = IE;
	} else {
	BIT_VEC cppVar_34379;
	BIT_VEC cppVar_34380 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_34381 = (cppVar_34380 << 3) | 1;
	cppVar_34381 = (cppVar_34381 & cppMask_un_5_);
	BIT_VEC cppVar_34382 = (0 << 5) | cppVar_34381;
	cppVar_34382 = (cppVar_34382 & cppMask_un_8_);
	bool cppVar_34384 = (cppVar_34382 == 176);
	if (cppVar_34384) {
	cppVar_34379 = P3;
	} else {
	BIT_VEC cppVar_34385;
	BIT_VEC cppVar_34386 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_34387 = (cppVar_34386 << 3) | 1;
	cppVar_34387 = (cppVar_34387 & cppMask_un_5_);
	BIT_VEC cppVar_34388 = (0 << 5) | cppVar_34387;
	cppVar_34388 = (cppVar_34388 & cppMask_un_8_);
	bool cppVar_34390 = (cppVar_34388 == 184);
	if (cppVar_34390) {
	cppVar_34385 = IP;
	} else {
	BIT_VEC cppVar_34391;
	BIT_VEC cppVar_34392 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_34393 = (cppVar_34392 << 3) | 1;
	cppVar_34393 = (cppVar_34393 & cppMask_un_5_);
	BIT_VEC cppVar_34394 = (0 << 5) | cppVar_34393;
	cppVar_34394 = (cppVar_34394 & cppMask_un_8_);
	bool cppVar_34396 = (cppVar_34394 == 208);
	if (cppVar_34396) {
	cppVar_34391 = PSW;
	} else {
	BIT_VEC cppVar_34397;
	BIT_VEC cppVar_34398 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_34399 = (cppVar_34398 << 3) | 1;
	cppVar_34399 = (cppVar_34399 & cppMask_un_5_);
	BIT_VEC cppVar_34400 = (0 << 5) | cppVar_34399;
	cppVar_34400 = (cppVar_34400 & cppMask_un_8_);
	bool cppVar_34402 = (cppVar_34400 == 224);
	if (cppVar_34402) {
	cppVar_34397 = ACC;
	} else {
	BIT_VEC cppVar_34403;
	BIT_VEC cppVar_34404 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_34405 = (cppVar_34404 << 3) | 1;
	cppVar_34405 = (cppVar_34405 & cppMask_un_5_);
	BIT_VEC cppVar_34406 = (0 << 5) | cppVar_34405;
	cppVar_34406 = (cppVar_34406 & cppMask_un_8_);
	bool cppVar_34408 = (cppVar_34406 == 240);
	if (cppVar_34408) {
	cppVar_34403 = B;
	} else {
	cppVar_34403 = 0;
	}
	cppVar_34397 = cppVar_34403;
	}
	cppVar_34391 = cppVar_34397;
	}
	cppVar_34385 = cppVar_34391;
	}
	cppVar_34379 = cppVar_34385;
	}
	cppVar_34373 = cppVar_34379;
	}
	cppVar_34367 = cppVar_34373;
	}
	cppVar_34361 = cppVar_34367;
	}
	cppVar_34355 = cppVar_34361;
	}
	cppVar_34349 = cppVar_34355;
	}
	cppVar_34343 = cppVar_34349;
	}
	cppVar_34337 = cppVar_34343;
	}
	cppVar_34331 = cppVar_34337;
	}
	cppVar_34325 = cppVar_34331;
	}
	cppVar_34319 = cppVar_34325;
	}
	cppVar_34313 = cppVar_34319;
	}
	cppVar_34307 = cppVar_34313;
	}
	cppVar_34301 = cppVar_34307;
	}
	cppVar_34295 = cppVar_34301;
	}
	cppVar_34289 = cppVar_34295;
	}
	cppVar_34283 = cppVar_34289;
	}
	cppVar_34270 = cppVar_34283;
	}
	cppVar_34264 = cppVar_34270;
	} else {
	cppVar_34264 = P2;
	}
	cppVar_34260 = cppVar_34264;
	} else {
	BIT_VEC cppVar_34410;
	BIT_VEC cppVar_34411 = ROM.rd(PC);
	bool cppVar_34413 = (cppVar_34411 == 136);
	if (cppVar_34413) {
	BIT_VEC cppVar_34414;
	BIT_VEC cppVar_34416 = PC + 1;
	cppVar_34416 = (cppVar_34416 & cppMask_un_16_);
	BIT_VEC cppVar_34417 = ROM.rd(cppVar_34416);
	bool cppVar_34419 = (cppVar_34417 == 160);
	if (cppVar_34419) {
	BIT_VEC cppVar_34420;
	BIT_VEC cppVar_34422 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_34424 = (cppVar_34422 << 3) | 0;
	cppVar_34424 = (cppVar_34424 & cppMask_un_5_);
	BIT_VEC cppVar_34425 = (0 << 5) | cppVar_34424;
	cppVar_34425 = (cppVar_34425 & cppMask_un_8_);
	BIT_VEC cppVar_34426 = (cppVar_34425 >> 7) & cppMask_un_1_;
	bool cppVar_34428 = (cppVar_34426 == 0);
	if (cppVar_34428) {
	BIT_VEC cppVar_34429 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_34430 = (cppVar_34429 << 3) | 0;
	cppVar_34430 = (cppVar_34430 & cppMask_un_5_);
	BIT_VEC cppVar_34431 = (0 << 5) | cppVar_34430;
	cppVar_34431 = (cppVar_34431 & cppMask_un_8_);
	BIT_VEC cppVar_34432 = IRAM.rd(cppVar_34431);
	cppVar_34420 = cppVar_34432;
	} else {
	BIT_VEC cppVar_34433;
	BIT_VEC cppVar_34434 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_34435 = (cppVar_34434 << 3) | 0;
	cppVar_34435 = (cppVar_34435 & cppMask_un_5_);
	BIT_VEC cppVar_34436 = (0 << 5) | cppVar_34435;
	cppVar_34436 = (cppVar_34436 & cppMask_un_8_);
	bool cppVar_34438 = (cppVar_34436 == 128);
	if (cppVar_34438) {
	cppVar_34433 = P0;
	} else {
	BIT_VEC cppVar_34439;
	BIT_VEC cppVar_34440 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_34441 = (cppVar_34440 << 3) | 0;
	cppVar_34441 = (cppVar_34441 & cppMask_un_5_);
	BIT_VEC cppVar_34442 = (0 << 5) | cppVar_34441;
	cppVar_34442 = (cppVar_34442 & cppMask_un_8_);
	bool cppVar_34444 = (cppVar_34442 == 129);
	if (cppVar_34444) {
	cppVar_34439 = SP;
	} else {
	BIT_VEC cppVar_34445;
	BIT_VEC cppVar_34446 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_34447 = (cppVar_34446 << 3) | 0;
	cppVar_34447 = (cppVar_34447 & cppMask_un_5_);
	BIT_VEC cppVar_34448 = (0 << 5) | cppVar_34447;
	cppVar_34448 = (cppVar_34448 & cppMask_un_8_);
	bool cppVar_34450 = (cppVar_34448 == 130);
	if (cppVar_34450) {
	cppVar_34445 = DPL;
	} else {
	BIT_VEC cppVar_34451;
	BIT_VEC cppVar_34452 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_34453 = (cppVar_34452 << 3) | 0;
	cppVar_34453 = (cppVar_34453 & cppMask_un_5_);
	BIT_VEC cppVar_34454 = (0 << 5) | cppVar_34453;
	cppVar_34454 = (cppVar_34454 & cppMask_un_8_);
	bool cppVar_34456 = (cppVar_34454 == 131);
	if (cppVar_34456) {
	cppVar_34451 = DPH;
	} else {
	BIT_VEC cppVar_34457;
	BIT_VEC cppVar_34458 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_34459 = (cppVar_34458 << 3) | 0;
	cppVar_34459 = (cppVar_34459 & cppMask_un_5_);
	BIT_VEC cppVar_34460 = (0 << 5) | cppVar_34459;
	cppVar_34460 = (cppVar_34460 & cppMask_un_8_);
	bool cppVar_34462 = (cppVar_34460 == 135);
	if (cppVar_34462) {
	cppVar_34457 = PCON;
	} else {
	BIT_VEC cppVar_34463;
	BIT_VEC cppVar_34464 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_34465 = (cppVar_34464 << 3) | 0;
	cppVar_34465 = (cppVar_34465 & cppMask_un_5_);
	BIT_VEC cppVar_34466 = (0 << 5) | cppVar_34465;
	cppVar_34466 = (cppVar_34466 & cppMask_un_8_);
	bool cppVar_34468 = (cppVar_34466 == 136);
	if (cppVar_34468) {
	cppVar_34463 = TCON;
	} else {
	BIT_VEC cppVar_34469;
	BIT_VEC cppVar_34470 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_34471 = (cppVar_34470 << 3) | 0;
	cppVar_34471 = (cppVar_34471 & cppMask_un_5_);
	BIT_VEC cppVar_34472 = (0 << 5) | cppVar_34471;
	cppVar_34472 = (cppVar_34472 & cppMask_un_8_);
	bool cppVar_34474 = (cppVar_34472 == 137);
	if (cppVar_34474) {
	cppVar_34469 = TMOD;
	} else {
	BIT_VEC cppVar_34475;
	BIT_VEC cppVar_34476 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_34477 = (cppVar_34476 << 3) | 0;
	cppVar_34477 = (cppVar_34477 & cppMask_un_5_);
	BIT_VEC cppVar_34478 = (0 << 5) | cppVar_34477;
	cppVar_34478 = (cppVar_34478 & cppMask_un_8_);
	bool cppVar_34480 = (cppVar_34478 == 138);
	if (cppVar_34480) {
	cppVar_34475 = TL0;
	} else {
	BIT_VEC cppVar_34481;
	BIT_VEC cppVar_34482 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_34483 = (cppVar_34482 << 3) | 0;
	cppVar_34483 = (cppVar_34483 & cppMask_un_5_);
	BIT_VEC cppVar_34484 = (0 << 5) | cppVar_34483;
	cppVar_34484 = (cppVar_34484 & cppMask_un_8_);
	bool cppVar_34486 = (cppVar_34484 == 140);
	if (cppVar_34486) {
	cppVar_34481 = TH0;
	} else {
	BIT_VEC cppVar_34487;
	BIT_VEC cppVar_34488 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_34489 = (cppVar_34488 << 3) | 0;
	cppVar_34489 = (cppVar_34489 & cppMask_un_5_);
	BIT_VEC cppVar_34490 = (0 << 5) | cppVar_34489;
	cppVar_34490 = (cppVar_34490 & cppMask_un_8_);
	bool cppVar_34492 = (cppVar_34490 == 139);
	if (cppVar_34492) {
	cppVar_34487 = TL1;
	} else {
	BIT_VEC cppVar_34493;
	BIT_VEC cppVar_34494 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_34495 = (cppVar_34494 << 3) | 0;
	cppVar_34495 = (cppVar_34495 & cppMask_un_5_);
	BIT_VEC cppVar_34496 = (0 << 5) | cppVar_34495;
	cppVar_34496 = (cppVar_34496 & cppMask_un_8_);
	bool cppVar_34498 = (cppVar_34496 == 141);
	if (cppVar_34498) {
	cppVar_34493 = TH1;
	} else {
	BIT_VEC cppVar_34499;
	BIT_VEC cppVar_34500 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_34501 = (cppVar_34500 << 3) | 0;
	cppVar_34501 = (cppVar_34501 & cppMask_un_5_);
	BIT_VEC cppVar_34502 = (0 << 5) | cppVar_34501;
	cppVar_34502 = (cppVar_34502 & cppMask_un_8_);
	bool cppVar_34504 = (cppVar_34502 == 144);
	if (cppVar_34504) {
	cppVar_34499 = P1;
	} else {
	BIT_VEC cppVar_34505;
	BIT_VEC cppVar_34506 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_34507 = (cppVar_34506 << 3) | 0;
	cppVar_34507 = (cppVar_34507 & cppMask_un_5_);
	BIT_VEC cppVar_34508 = (0 << 5) | cppVar_34507;
	cppVar_34508 = (cppVar_34508 & cppMask_un_8_);
	bool cppVar_34510 = (cppVar_34508 == 152);
	if (cppVar_34510) {
	cppVar_34505 = SCON;
	} else {
	BIT_VEC cppVar_34511;
	BIT_VEC cppVar_34512 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_34513 = (cppVar_34512 << 3) | 0;
	cppVar_34513 = (cppVar_34513 & cppMask_un_5_);
	BIT_VEC cppVar_34514 = (0 << 5) | cppVar_34513;
	cppVar_34514 = (cppVar_34514 & cppMask_un_8_);
	bool cppVar_34516 = (cppVar_34514 == 153);
	if (cppVar_34516) {
	cppVar_34511 = SBUF;
	} else {
	BIT_VEC cppVar_34517;
	BIT_VEC cppVar_34518 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_34519 = (cppVar_34518 << 3) | 0;
	cppVar_34519 = (cppVar_34519 & cppMask_un_5_);
	BIT_VEC cppVar_34520 = (0 << 5) | cppVar_34519;
	cppVar_34520 = (cppVar_34520 & cppMask_un_8_);
	bool cppVar_34522 = (cppVar_34520 == 160);
	if (cppVar_34522) {
	cppVar_34517 = P2;
	} else {
	BIT_VEC cppVar_34523;
	BIT_VEC cppVar_34524 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_34525 = (cppVar_34524 << 3) | 0;
	cppVar_34525 = (cppVar_34525 & cppMask_un_5_);
	BIT_VEC cppVar_34526 = (0 << 5) | cppVar_34525;
	cppVar_34526 = (cppVar_34526 & cppMask_un_8_);
	bool cppVar_34528 = (cppVar_34526 == 168);
	if (cppVar_34528) {
	cppVar_34523 = IE;
	} else {
	BIT_VEC cppVar_34529;
	BIT_VEC cppVar_34530 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_34531 = (cppVar_34530 << 3) | 0;
	cppVar_34531 = (cppVar_34531 & cppMask_un_5_);
	BIT_VEC cppVar_34532 = (0 << 5) | cppVar_34531;
	cppVar_34532 = (cppVar_34532 & cppMask_un_8_);
	bool cppVar_34534 = (cppVar_34532 == 176);
	if (cppVar_34534) {
	cppVar_34529 = P3;
	} else {
	BIT_VEC cppVar_34535;
	BIT_VEC cppVar_34536 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_34537 = (cppVar_34536 << 3) | 0;
	cppVar_34537 = (cppVar_34537 & cppMask_un_5_);
	BIT_VEC cppVar_34538 = (0 << 5) | cppVar_34537;
	cppVar_34538 = (cppVar_34538 & cppMask_un_8_);
	bool cppVar_34540 = (cppVar_34538 == 184);
	if (cppVar_34540) {
	cppVar_34535 = IP;
	} else {
	BIT_VEC cppVar_34541;
	BIT_VEC cppVar_34542 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_34543 = (cppVar_34542 << 3) | 0;
	cppVar_34543 = (cppVar_34543 & cppMask_un_5_);
	BIT_VEC cppVar_34544 = (0 << 5) | cppVar_34543;
	cppVar_34544 = (cppVar_34544 & cppMask_un_8_);
	bool cppVar_34546 = (cppVar_34544 == 208);
	if (cppVar_34546) {
	cppVar_34541 = PSW;
	} else {
	BIT_VEC cppVar_34547;
	BIT_VEC cppVar_34548 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_34549 = (cppVar_34548 << 3) | 0;
	cppVar_34549 = (cppVar_34549 & cppMask_un_5_);
	BIT_VEC cppVar_34550 = (0 << 5) | cppVar_34549;
	cppVar_34550 = (cppVar_34550 & cppMask_un_8_);
	bool cppVar_34552 = (cppVar_34550 == 224);
	if (cppVar_34552) {
	cppVar_34547 = ACC;
	} else {
	BIT_VEC cppVar_34553;
	BIT_VEC cppVar_34554 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_34555 = (cppVar_34554 << 3) | 0;
	cppVar_34555 = (cppVar_34555 & cppMask_un_5_);
	BIT_VEC cppVar_34556 = (0 << 5) | cppVar_34555;
	cppVar_34556 = (cppVar_34556 & cppMask_un_8_);
	bool cppVar_34558 = (cppVar_34556 == 240);
	if (cppVar_34558) {
	cppVar_34553 = B;
	} else {
	cppVar_34553 = 0;
	}
	cppVar_34547 = cppVar_34553;
	}
	cppVar_34541 = cppVar_34547;
	}
	cppVar_34535 = cppVar_34541;
	}
	cppVar_34529 = cppVar_34535;
	}
	cppVar_34523 = cppVar_34529;
	}
	cppVar_34517 = cppVar_34523;
	}
	cppVar_34511 = cppVar_34517;
	}
	cppVar_34505 = cppVar_34511;
	}
	cppVar_34499 = cppVar_34505;
	}
	cppVar_34493 = cppVar_34499;
	}
	cppVar_34487 = cppVar_34493;
	}
	cppVar_34481 = cppVar_34487;
	}
	cppVar_34475 = cppVar_34481;
	}
	cppVar_34469 = cppVar_34475;
	}
	cppVar_34463 = cppVar_34469;
	}
	cppVar_34457 = cppVar_34463;
	}
	cppVar_34451 = cppVar_34457;
	}
	cppVar_34445 = cppVar_34451;
	}
	cppVar_34439 = cppVar_34445;
	}
	cppVar_34433 = cppVar_34439;
	}
	cppVar_34420 = cppVar_34433;
	}
	cppVar_34414 = cppVar_34420;
	} else {
	cppVar_34414 = P2;
	}
	cppVar_34410 = cppVar_34414;
	} else {
	BIT_VEC cppVar_34560;
	BIT_VEC cppVar_34561 = ROM.rd(PC);
	bool cppVar_34563 = (cppVar_34561 == 135);
	if (cppVar_34563) {
	BIT_VEC cppVar_34564;
	BIT_VEC cppVar_34566 = PC + 1;
	cppVar_34566 = (cppVar_34566 & cppMask_un_16_);
	BIT_VEC cppVar_34567 = ROM.rd(cppVar_34566);
	bool cppVar_34569 = (cppVar_34567 == 160);
	if (cppVar_34569) {
	BIT_VEC cppVar_34571 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_34573 = (cppVar_34571 << 3) | 1;
	cppVar_34573 = (cppVar_34573 & cppMask_un_5_);
	BIT_VEC cppVar_34574 = (0 << 5) | cppVar_34573;
	cppVar_34574 = (cppVar_34574 & cppMask_un_8_);
	BIT_VEC cppVar_34575 = IRAM.rd(cppVar_34574);
	BIT_VEC cppVar_34576 = IRAM.rd(cppVar_34575);
	cppVar_34564 = cppVar_34576;
	} else {
	cppVar_34564 = P2;
	}
	cppVar_34560 = cppVar_34564;
	} else {
	BIT_VEC cppVar_34577;
	BIT_VEC cppVar_34578 = ROM.rd(PC);
	bool cppVar_34580 = (cppVar_34578 == 134);
	if (cppVar_34580) {
	BIT_VEC cppVar_34581;
	BIT_VEC cppVar_34583 = PC + 1;
	cppVar_34583 = (cppVar_34583 & cppMask_un_16_);
	BIT_VEC cppVar_34584 = ROM.rd(cppVar_34583);
	bool cppVar_34586 = (cppVar_34584 == 160);
	if (cppVar_34586) {
	BIT_VEC cppVar_34588 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_34590 = (cppVar_34588 << 3) | 0;
	cppVar_34590 = (cppVar_34590 & cppMask_un_5_);
	BIT_VEC cppVar_34591 = (0 << 5) | cppVar_34590;
	cppVar_34591 = (cppVar_34591 & cppMask_un_8_);
	BIT_VEC cppVar_34592 = IRAM.rd(cppVar_34591);
	BIT_VEC cppVar_34593 = IRAM.rd(cppVar_34592);
	cppVar_34581 = cppVar_34593;
	} else {
	cppVar_34581 = P2;
	}
	cppVar_34577 = cppVar_34581;
	} else {
	BIT_VEC cppVar_34594;
	BIT_VEC cppVar_34595 = ROM.rd(PC);
	bool cppVar_34597 = (cppVar_34595 == 133);
	if (cppVar_34597) {
	BIT_VEC cppVar_34598;
	BIT_VEC cppVar_34600 = PC + 2;
	cppVar_34600 = (cppVar_34600 & cppMask_un_16_);
	BIT_VEC cppVar_34601 = ROM.rd(cppVar_34600);
	bool cppVar_34603 = (cppVar_34601 == 160);
	if (cppVar_34603) {
	BIT_VEC cppVar_34604;
	BIT_VEC cppVar_34606 = PC + 1;
	cppVar_34606 = (cppVar_34606 & cppMask_un_16_);
	BIT_VEC cppVar_34607 = ROM.rd(cppVar_34606);
	BIT_VEC cppVar_34608 = (cppVar_34607 >> 7) & cppMask_un_1_;
	bool cppVar_34610 = (cppVar_34608 == 0);
	if (cppVar_34610) {
	BIT_VEC cppVar_34611 = PC + 1;
	cppVar_34611 = (cppVar_34611 & cppMask_un_16_);
	BIT_VEC cppVar_34612 = ROM.rd(cppVar_34611);
	BIT_VEC cppVar_34613 = IRAM.rd(cppVar_34612);
	cppVar_34604 = cppVar_34613;
	} else {
	BIT_VEC cppVar_34614;
	BIT_VEC cppVar_34615 = PC + 1;
	cppVar_34615 = (cppVar_34615 & cppMask_un_16_);
	BIT_VEC cppVar_34616 = ROM.rd(cppVar_34615);
	bool cppVar_34618 = (cppVar_34616 == 128);
	if (cppVar_34618) {
	cppVar_34614 = P0;
	} else {
	BIT_VEC cppVar_34619;
	BIT_VEC cppVar_34620 = PC + 1;
	cppVar_34620 = (cppVar_34620 & cppMask_un_16_);
	BIT_VEC cppVar_34621 = ROM.rd(cppVar_34620);
	bool cppVar_34623 = (cppVar_34621 == 129);
	if (cppVar_34623) {
	cppVar_34619 = SP;
	} else {
	BIT_VEC cppVar_34624;
	BIT_VEC cppVar_34625 = PC + 1;
	cppVar_34625 = (cppVar_34625 & cppMask_un_16_);
	BIT_VEC cppVar_34626 = ROM.rd(cppVar_34625);
	bool cppVar_34628 = (cppVar_34626 == 130);
	if (cppVar_34628) {
	cppVar_34624 = DPL;
	} else {
	BIT_VEC cppVar_34629;
	BIT_VEC cppVar_34630 = PC + 1;
	cppVar_34630 = (cppVar_34630 & cppMask_un_16_);
	BIT_VEC cppVar_34631 = ROM.rd(cppVar_34630);
	bool cppVar_34633 = (cppVar_34631 == 131);
	if (cppVar_34633) {
	cppVar_34629 = DPH;
	} else {
	BIT_VEC cppVar_34634;
	BIT_VEC cppVar_34635 = PC + 1;
	cppVar_34635 = (cppVar_34635 & cppMask_un_16_);
	BIT_VEC cppVar_34636 = ROM.rd(cppVar_34635);
	bool cppVar_34638 = (cppVar_34636 == 135);
	if (cppVar_34638) {
	cppVar_34634 = PCON;
	} else {
	BIT_VEC cppVar_34639;
	BIT_VEC cppVar_34640 = PC + 1;
	cppVar_34640 = (cppVar_34640 & cppMask_un_16_);
	BIT_VEC cppVar_34641 = ROM.rd(cppVar_34640);
	bool cppVar_34643 = (cppVar_34641 == 136);
	if (cppVar_34643) {
	cppVar_34639 = TCON;
	} else {
	BIT_VEC cppVar_34644;
	BIT_VEC cppVar_34645 = PC + 1;
	cppVar_34645 = (cppVar_34645 & cppMask_un_16_);
	BIT_VEC cppVar_34646 = ROM.rd(cppVar_34645);
	bool cppVar_34648 = (cppVar_34646 == 137);
	if (cppVar_34648) {
	cppVar_34644 = TMOD;
	} else {
	BIT_VEC cppVar_34649;
	BIT_VEC cppVar_34650 = PC + 1;
	cppVar_34650 = (cppVar_34650 & cppMask_un_16_);
	BIT_VEC cppVar_34651 = ROM.rd(cppVar_34650);
	bool cppVar_34653 = (cppVar_34651 == 138);
	if (cppVar_34653) {
	cppVar_34649 = TL0;
	} else {
	BIT_VEC cppVar_34654;
	BIT_VEC cppVar_34655 = PC + 1;
	cppVar_34655 = (cppVar_34655 & cppMask_un_16_);
	BIT_VEC cppVar_34656 = ROM.rd(cppVar_34655);
	bool cppVar_34658 = (cppVar_34656 == 140);
	if (cppVar_34658) {
	cppVar_34654 = TH0;
	} else {
	BIT_VEC cppVar_34659;
	BIT_VEC cppVar_34660 = PC + 1;
	cppVar_34660 = (cppVar_34660 & cppMask_un_16_);
	BIT_VEC cppVar_34661 = ROM.rd(cppVar_34660);
	bool cppVar_34663 = (cppVar_34661 == 139);
	if (cppVar_34663) {
	cppVar_34659 = TL1;
	} else {
	BIT_VEC cppVar_34664;
	BIT_VEC cppVar_34665 = PC + 1;
	cppVar_34665 = (cppVar_34665 & cppMask_un_16_);
	BIT_VEC cppVar_34666 = ROM.rd(cppVar_34665);
	bool cppVar_34668 = (cppVar_34666 == 141);
	if (cppVar_34668) {
	cppVar_34664 = TH1;
	} else {
	BIT_VEC cppVar_34669;
	BIT_VEC cppVar_34670 = PC + 1;
	cppVar_34670 = (cppVar_34670 & cppMask_un_16_);
	BIT_VEC cppVar_34671 = ROM.rd(cppVar_34670);
	bool cppVar_34673 = (cppVar_34671 == 144);
	if (cppVar_34673) {
	cppVar_34669 = P1;
	} else {
	BIT_VEC cppVar_34674;
	BIT_VEC cppVar_34675 = PC + 1;
	cppVar_34675 = (cppVar_34675 & cppMask_un_16_);
	BIT_VEC cppVar_34676 = ROM.rd(cppVar_34675);
	bool cppVar_34678 = (cppVar_34676 == 152);
	if (cppVar_34678) {
	cppVar_34674 = SCON;
	} else {
	BIT_VEC cppVar_34679;
	BIT_VEC cppVar_34680 = PC + 1;
	cppVar_34680 = (cppVar_34680 & cppMask_un_16_);
	BIT_VEC cppVar_34681 = ROM.rd(cppVar_34680);
	bool cppVar_34683 = (cppVar_34681 == 153);
	if (cppVar_34683) {
	cppVar_34679 = SBUF;
	} else {
	BIT_VEC cppVar_34684;
	BIT_VEC cppVar_34685 = PC + 1;
	cppVar_34685 = (cppVar_34685 & cppMask_un_16_);
	BIT_VEC cppVar_34686 = ROM.rd(cppVar_34685);
	bool cppVar_34688 = (cppVar_34686 == 160);
	if (cppVar_34688) {
	cppVar_34684 = P2;
	} else {
	BIT_VEC cppVar_34689;
	BIT_VEC cppVar_34690 = PC + 1;
	cppVar_34690 = (cppVar_34690 & cppMask_un_16_);
	BIT_VEC cppVar_34691 = ROM.rd(cppVar_34690);
	bool cppVar_34693 = (cppVar_34691 == 168);
	if (cppVar_34693) {
	cppVar_34689 = IE;
	} else {
	BIT_VEC cppVar_34694;
	BIT_VEC cppVar_34695 = PC + 1;
	cppVar_34695 = (cppVar_34695 & cppMask_un_16_);
	BIT_VEC cppVar_34696 = ROM.rd(cppVar_34695);
	bool cppVar_34698 = (cppVar_34696 == 176);
	if (cppVar_34698) {
	cppVar_34694 = P3;
	} else {
	BIT_VEC cppVar_34699;
	BIT_VEC cppVar_34700 = PC + 1;
	cppVar_34700 = (cppVar_34700 & cppMask_un_16_);
	BIT_VEC cppVar_34701 = ROM.rd(cppVar_34700);
	bool cppVar_34703 = (cppVar_34701 == 184);
	if (cppVar_34703) {
	cppVar_34699 = IP;
	} else {
	BIT_VEC cppVar_34704;
	BIT_VEC cppVar_34705 = PC + 1;
	cppVar_34705 = (cppVar_34705 & cppMask_un_16_);
	BIT_VEC cppVar_34706 = ROM.rd(cppVar_34705);
	bool cppVar_34708 = (cppVar_34706 == 208);
	if (cppVar_34708) {
	cppVar_34704 = PSW;
	} else {
	BIT_VEC cppVar_34709;
	BIT_VEC cppVar_34710 = PC + 1;
	cppVar_34710 = (cppVar_34710 & cppMask_un_16_);
	BIT_VEC cppVar_34711 = ROM.rd(cppVar_34710);
	bool cppVar_34713 = (cppVar_34711 == 224);
	if (cppVar_34713) {
	cppVar_34709 = ACC;
	} else {
	BIT_VEC cppVar_34714;
	BIT_VEC cppVar_34715 = PC + 1;
	cppVar_34715 = (cppVar_34715 & cppMask_un_16_);
	BIT_VEC cppVar_34716 = ROM.rd(cppVar_34715);
	bool cppVar_34718 = (cppVar_34716 == 240);
	if (cppVar_34718) {
	cppVar_34714 = B;
	} else {
	cppVar_34714 = 0;
	}
	cppVar_34709 = cppVar_34714;
	}
	cppVar_34704 = cppVar_34709;
	}
	cppVar_34699 = cppVar_34704;
	}
	cppVar_34694 = cppVar_34699;
	}
	cppVar_34689 = cppVar_34694;
	}
	cppVar_34684 = cppVar_34689;
	}
	cppVar_34679 = cppVar_34684;
	}
	cppVar_34674 = cppVar_34679;
	}
	cppVar_34669 = cppVar_34674;
	}
	cppVar_34664 = cppVar_34669;
	}
	cppVar_34659 = cppVar_34664;
	}
	cppVar_34654 = cppVar_34659;
	}
	cppVar_34649 = cppVar_34654;
	}
	cppVar_34644 = cppVar_34649;
	}
	cppVar_34639 = cppVar_34644;
	}
	cppVar_34634 = cppVar_34639;
	}
	cppVar_34629 = cppVar_34634;
	}
	cppVar_34624 = cppVar_34629;
	}
	cppVar_34619 = cppVar_34624;
	}
	cppVar_34614 = cppVar_34619;
	}
	cppVar_34604 = cppVar_34614;
	}
	cppVar_34598 = cppVar_34604;
	} else {
	cppVar_34598 = P2;
	}
	cppVar_34594 = cppVar_34598;
	} else {
	BIT_VEC cppVar_34720;
	BIT_VEC cppVar_34721 = ROM.rd(PC);
	bool cppVar_34723 = (cppVar_34721 == 117);
	if (cppVar_34723) {
	BIT_VEC cppVar_34724;
	BIT_VEC cppVar_34726 = PC + 1;
	cppVar_34726 = (cppVar_34726 & cppMask_un_16_);
	BIT_VEC cppVar_34727 = ROM.rd(cppVar_34726);
	bool cppVar_34729 = (cppVar_34727 == 160);
	if (cppVar_34729) {
	BIT_VEC cppVar_34731 = PC + 2;
	cppVar_34731 = (cppVar_34731 & cppMask_un_16_);
	BIT_VEC cppVar_34732 = ROM.rd(cppVar_34731);
	cppVar_34724 = cppVar_34732;
	} else {
	cppVar_34724 = P2;
	}
	cppVar_34720 = cppVar_34724;
	} else {
	BIT_VEC cppVar_34733;
	BIT_VEC cppVar_34734 = ROM.rd(PC);
	bool cppVar_34736 = (cppVar_34734 == 99);
	if (cppVar_34736) {
	BIT_VEC cppVar_34737;
	BIT_VEC cppVar_34739 = PC + 1;
	cppVar_34739 = (cppVar_34739 & cppMask_un_16_);
	BIT_VEC cppVar_34740 = ROM.rd(cppVar_34739);
	bool cppVar_34742 = (cppVar_34740 == 160);
	if (cppVar_34742) {
	BIT_VEC cppVar_34743;
	BIT_VEC cppVar_34744 = PC + 1;
	cppVar_34744 = (cppVar_34744 & cppMask_un_16_);
	BIT_VEC cppVar_34745 = ROM.rd(cppVar_34744);
	BIT_VEC cppVar_34746 = (cppVar_34745 >> 7) & cppMask_un_1_;
	bool cppVar_34748 = (cppVar_34746 == 0);
	if (cppVar_34748) {
	BIT_VEC cppVar_34749 = PC + 1;
	cppVar_34749 = (cppVar_34749 & cppMask_un_16_);
	BIT_VEC cppVar_34750 = ROM.rd(cppVar_34749);
	BIT_VEC cppVar_34751 = IRAM.rd(cppVar_34750);
	cppVar_34743 = cppVar_34751;
	} else {
	BIT_VEC cppVar_34752;
	BIT_VEC cppVar_34753 = PC + 1;
	cppVar_34753 = (cppVar_34753 & cppMask_un_16_);
	BIT_VEC cppVar_34754 = ROM.rd(cppVar_34753);
	bool cppVar_34756 = (cppVar_34754 == 128);
	if (cppVar_34756) {
	cppVar_34752 = P0;
	} else {
	BIT_VEC cppVar_34757;
	BIT_VEC cppVar_34758 = PC + 1;
	cppVar_34758 = (cppVar_34758 & cppMask_un_16_);
	BIT_VEC cppVar_34759 = ROM.rd(cppVar_34758);
	bool cppVar_34761 = (cppVar_34759 == 129);
	if (cppVar_34761) {
	cppVar_34757 = SP;
	} else {
	BIT_VEC cppVar_34762;
	BIT_VEC cppVar_34763 = PC + 1;
	cppVar_34763 = (cppVar_34763 & cppMask_un_16_);
	BIT_VEC cppVar_34764 = ROM.rd(cppVar_34763);
	bool cppVar_34766 = (cppVar_34764 == 130);
	if (cppVar_34766) {
	cppVar_34762 = DPL;
	} else {
	BIT_VEC cppVar_34767;
	BIT_VEC cppVar_34768 = PC + 1;
	cppVar_34768 = (cppVar_34768 & cppMask_un_16_);
	BIT_VEC cppVar_34769 = ROM.rd(cppVar_34768);
	bool cppVar_34771 = (cppVar_34769 == 131);
	if (cppVar_34771) {
	cppVar_34767 = DPH;
	} else {
	BIT_VEC cppVar_34772;
	BIT_VEC cppVar_34773 = PC + 1;
	cppVar_34773 = (cppVar_34773 & cppMask_un_16_);
	BIT_VEC cppVar_34774 = ROM.rd(cppVar_34773);
	bool cppVar_34776 = (cppVar_34774 == 135);
	if (cppVar_34776) {
	cppVar_34772 = PCON;
	} else {
	BIT_VEC cppVar_34777;
	BIT_VEC cppVar_34778 = PC + 1;
	cppVar_34778 = (cppVar_34778 & cppMask_un_16_);
	BIT_VEC cppVar_34779 = ROM.rd(cppVar_34778);
	bool cppVar_34781 = (cppVar_34779 == 136);
	if (cppVar_34781) {
	cppVar_34777 = TCON;
	} else {
	BIT_VEC cppVar_34782;
	BIT_VEC cppVar_34783 = PC + 1;
	cppVar_34783 = (cppVar_34783 & cppMask_un_16_);
	BIT_VEC cppVar_34784 = ROM.rd(cppVar_34783);
	bool cppVar_34786 = (cppVar_34784 == 137);
	if (cppVar_34786) {
	cppVar_34782 = TMOD;
	} else {
	BIT_VEC cppVar_34787;
	BIT_VEC cppVar_34788 = PC + 1;
	cppVar_34788 = (cppVar_34788 & cppMask_un_16_);
	BIT_VEC cppVar_34789 = ROM.rd(cppVar_34788);
	bool cppVar_34791 = (cppVar_34789 == 138);
	if (cppVar_34791) {
	cppVar_34787 = TL0;
	} else {
	BIT_VEC cppVar_34792;
	BIT_VEC cppVar_34793 = PC + 1;
	cppVar_34793 = (cppVar_34793 & cppMask_un_16_);
	BIT_VEC cppVar_34794 = ROM.rd(cppVar_34793);
	bool cppVar_34796 = (cppVar_34794 == 140);
	if (cppVar_34796) {
	cppVar_34792 = TH0;
	} else {
	BIT_VEC cppVar_34797;
	BIT_VEC cppVar_34798 = PC + 1;
	cppVar_34798 = (cppVar_34798 & cppMask_un_16_);
	BIT_VEC cppVar_34799 = ROM.rd(cppVar_34798);
	bool cppVar_34801 = (cppVar_34799 == 139);
	if (cppVar_34801) {
	cppVar_34797 = TL1;
	} else {
	BIT_VEC cppVar_34802;
	BIT_VEC cppVar_34803 = PC + 1;
	cppVar_34803 = (cppVar_34803 & cppMask_un_16_);
	BIT_VEC cppVar_34804 = ROM.rd(cppVar_34803);
	bool cppVar_34806 = (cppVar_34804 == 141);
	if (cppVar_34806) {
	cppVar_34802 = TH1;
	} else {
	BIT_VEC cppVar_34807;
	BIT_VEC cppVar_34808 = PC + 1;
	cppVar_34808 = (cppVar_34808 & cppMask_un_16_);
	BIT_VEC cppVar_34809 = ROM.rd(cppVar_34808);
	bool cppVar_34811 = (cppVar_34809 == 144);
	if (cppVar_34811) {
	cppVar_34807 = P1;
	} else {
	BIT_VEC cppVar_34812;
	BIT_VEC cppVar_34813 = PC + 1;
	cppVar_34813 = (cppVar_34813 & cppMask_un_16_);
	BIT_VEC cppVar_34814 = ROM.rd(cppVar_34813);
	bool cppVar_34816 = (cppVar_34814 == 152);
	if (cppVar_34816) {
	cppVar_34812 = SCON;
	} else {
	BIT_VEC cppVar_34817;
	BIT_VEC cppVar_34818 = PC + 1;
	cppVar_34818 = (cppVar_34818 & cppMask_un_16_);
	BIT_VEC cppVar_34819 = ROM.rd(cppVar_34818);
	bool cppVar_34821 = (cppVar_34819 == 153);
	if (cppVar_34821) {
	cppVar_34817 = SBUF;
	} else {
	BIT_VEC cppVar_34822;
	BIT_VEC cppVar_34823 = PC + 1;
	cppVar_34823 = (cppVar_34823 & cppMask_un_16_);
	BIT_VEC cppVar_34824 = ROM.rd(cppVar_34823);
	bool cppVar_34826 = (cppVar_34824 == 160);
	if (cppVar_34826) {
	cppVar_34822 = P2;
	} else {
	BIT_VEC cppVar_34827;
	BIT_VEC cppVar_34828 = PC + 1;
	cppVar_34828 = (cppVar_34828 & cppMask_un_16_);
	BIT_VEC cppVar_34829 = ROM.rd(cppVar_34828);
	bool cppVar_34831 = (cppVar_34829 == 168);
	if (cppVar_34831) {
	cppVar_34827 = IE;
	} else {
	BIT_VEC cppVar_34832;
	BIT_VEC cppVar_34833 = PC + 1;
	cppVar_34833 = (cppVar_34833 & cppMask_un_16_);
	BIT_VEC cppVar_34834 = ROM.rd(cppVar_34833);
	bool cppVar_34836 = (cppVar_34834 == 176);
	if (cppVar_34836) {
	cppVar_34832 = P3;
	} else {
	BIT_VEC cppVar_34837;
	BIT_VEC cppVar_34838 = PC + 1;
	cppVar_34838 = (cppVar_34838 & cppMask_un_16_);
	BIT_VEC cppVar_34839 = ROM.rd(cppVar_34838);
	bool cppVar_34841 = (cppVar_34839 == 184);
	if (cppVar_34841) {
	cppVar_34837 = IP;
	} else {
	BIT_VEC cppVar_34842;
	BIT_VEC cppVar_34843 = PC + 1;
	cppVar_34843 = (cppVar_34843 & cppMask_un_16_);
	BIT_VEC cppVar_34844 = ROM.rd(cppVar_34843);
	bool cppVar_34846 = (cppVar_34844 == 208);
	if (cppVar_34846) {
	cppVar_34842 = PSW;
	} else {
	BIT_VEC cppVar_34847;
	BIT_VEC cppVar_34848 = PC + 1;
	cppVar_34848 = (cppVar_34848 & cppMask_un_16_);
	BIT_VEC cppVar_34849 = ROM.rd(cppVar_34848);
	bool cppVar_34851 = (cppVar_34849 == 224);
	if (cppVar_34851) {
	cppVar_34847 = ACC;
	} else {
	BIT_VEC cppVar_34852;
	BIT_VEC cppVar_34853 = PC + 1;
	cppVar_34853 = (cppVar_34853 & cppMask_un_16_);
	BIT_VEC cppVar_34854 = ROM.rd(cppVar_34853);
	bool cppVar_34856 = (cppVar_34854 == 240);
	if (cppVar_34856) {
	cppVar_34852 = B;
	} else {
	cppVar_34852 = 0;
	}
	cppVar_34847 = cppVar_34852;
	}
	cppVar_34842 = cppVar_34847;
	}
	cppVar_34837 = cppVar_34842;
	}
	cppVar_34832 = cppVar_34837;
	}
	cppVar_34827 = cppVar_34832;
	}
	cppVar_34822 = cppVar_34827;
	}
	cppVar_34817 = cppVar_34822;
	}
	cppVar_34812 = cppVar_34817;
	}
	cppVar_34807 = cppVar_34812;
	}
	cppVar_34802 = cppVar_34807;
	}
	cppVar_34797 = cppVar_34802;
	}
	cppVar_34792 = cppVar_34797;
	}
	cppVar_34787 = cppVar_34792;
	}
	cppVar_34782 = cppVar_34787;
	}
	cppVar_34777 = cppVar_34782;
	}
	cppVar_34772 = cppVar_34777;
	}
	cppVar_34767 = cppVar_34772;
	}
	cppVar_34762 = cppVar_34767;
	}
	cppVar_34757 = cppVar_34762;
	}
	cppVar_34752 = cppVar_34757;
	}
	cppVar_34743 = cppVar_34752;
	}
	BIT_VEC cppVar_34859 = PC + 2;
	cppVar_34859 = (cppVar_34859 & cppMask_un_16_);
	BIT_VEC cppVar_34860 = ROM.rd(cppVar_34859);
	BIT_VEC cppVar_34861 = cppVar_34743 ^ cppVar_34860;
	cppVar_34737 = cppVar_34861;
	} else {
	cppVar_34737 = P2;
	}
	cppVar_34733 = cppVar_34737;
	} else {
	BIT_VEC cppVar_34862;
	BIT_VEC cppVar_34863 = ROM.rd(PC);
	bool cppVar_34865 = (cppVar_34863 == 98);
	if (cppVar_34865) {
	BIT_VEC cppVar_34866;
	BIT_VEC cppVar_34868 = PC + 1;
	cppVar_34868 = (cppVar_34868 & cppMask_un_16_);
	BIT_VEC cppVar_34869 = ROM.rd(cppVar_34868);
	bool cppVar_34871 = (cppVar_34869 == 160);
	if (cppVar_34871) {
	BIT_VEC cppVar_34872;
	BIT_VEC cppVar_34873 = PC + 1;
	cppVar_34873 = (cppVar_34873 & cppMask_un_16_);
	BIT_VEC cppVar_34874 = ROM.rd(cppVar_34873);
	BIT_VEC cppVar_34875 = (cppVar_34874 >> 7) & cppMask_un_1_;
	bool cppVar_34877 = (cppVar_34875 == 0);
	if (cppVar_34877) {
	BIT_VEC cppVar_34878 = PC + 1;
	cppVar_34878 = (cppVar_34878 & cppMask_un_16_);
	BIT_VEC cppVar_34879 = ROM.rd(cppVar_34878);
	BIT_VEC cppVar_34880 = IRAM.rd(cppVar_34879);
	cppVar_34872 = cppVar_34880;
	} else {
	BIT_VEC cppVar_34881;
	BIT_VEC cppVar_34882 = PC + 1;
	cppVar_34882 = (cppVar_34882 & cppMask_un_16_);
	BIT_VEC cppVar_34883 = ROM.rd(cppVar_34882);
	bool cppVar_34885 = (cppVar_34883 == 128);
	if (cppVar_34885) {
	cppVar_34881 = P0;
	} else {
	BIT_VEC cppVar_34886;
	BIT_VEC cppVar_34887 = PC + 1;
	cppVar_34887 = (cppVar_34887 & cppMask_un_16_);
	BIT_VEC cppVar_34888 = ROM.rd(cppVar_34887);
	bool cppVar_34890 = (cppVar_34888 == 129);
	if (cppVar_34890) {
	cppVar_34886 = SP;
	} else {
	BIT_VEC cppVar_34891;
	BIT_VEC cppVar_34892 = PC + 1;
	cppVar_34892 = (cppVar_34892 & cppMask_un_16_);
	BIT_VEC cppVar_34893 = ROM.rd(cppVar_34892);
	bool cppVar_34895 = (cppVar_34893 == 130);
	if (cppVar_34895) {
	cppVar_34891 = DPL;
	} else {
	BIT_VEC cppVar_34896;
	BIT_VEC cppVar_34897 = PC + 1;
	cppVar_34897 = (cppVar_34897 & cppMask_un_16_);
	BIT_VEC cppVar_34898 = ROM.rd(cppVar_34897);
	bool cppVar_34900 = (cppVar_34898 == 131);
	if (cppVar_34900) {
	cppVar_34896 = DPH;
	} else {
	BIT_VEC cppVar_34901;
	BIT_VEC cppVar_34902 = PC + 1;
	cppVar_34902 = (cppVar_34902 & cppMask_un_16_);
	BIT_VEC cppVar_34903 = ROM.rd(cppVar_34902);
	bool cppVar_34905 = (cppVar_34903 == 135);
	if (cppVar_34905) {
	cppVar_34901 = PCON;
	} else {
	BIT_VEC cppVar_34906;
	BIT_VEC cppVar_34907 = PC + 1;
	cppVar_34907 = (cppVar_34907 & cppMask_un_16_);
	BIT_VEC cppVar_34908 = ROM.rd(cppVar_34907);
	bool cppVar_34910 = (cppVar_34908 == 136);
	if (cppVar_34910) {
	cppVar_34906 = TCON;
	} else {
	BIT_VEC cppVar_34911;
	BIT_VEC cppVar_34912 = PC + 1;
	cppVar_34912 = (cppVar_34912 & cppMask_un_16_);
	BIT_VEC cppVar_34913 = ROM.rd(cppVar_34912);
	bool cppVar_34915 = (cppVar_34913 == 137);
	if (cppVar_34915) {
	cppVar_34911 = TMOD;
	} else {
	BIT_VEC cppVar_34916;
	BIT_VEC cppVar_34917 = PC + 1;
	cppVar_34917 = (cppVar_34917 & cppMask_un_16_);
	BIT_VEC cppVar_34918 = ROM.rd(cppVar_34917);
	bool cppVar_34920 = (cppVar_34918 == 138);
	if (cppVar_34920) {
	cppVar_34916 = TL0;
	} else {
	BIT_VEC cppVar_34921;
	BIT_VEC cppVar_34922 = PC + 1;
	cppVar_34922 = (cppVar_34922 & cppMask_un_16_);
	BIT_VEC cppVar_34923 = ROM.rd(cppVar_34922);
	bool cppVar_34925 = (cppVar_34923 == 140);
	if (cppVar_34925) {
	cppVar_34921 = TH0;
	} else {
	BIT_VEC cppVar_34926;
	BIT_VEC cppVar_34927 = PC + 1;
	cppVar_34927 = (cppVar_34927 & cppMask_un_16_);
	BIT_VEC cppVar_34928 = ROM.rd(cppVar_34927);
	bool cppVar_34930 = (cppVar_34928 == 139);
	if (cppVar_34930) {
	cppVar_34926 = TL1;
	} else {
	BIT_VEC cppVar_34931;
	BIT_VEC cppVar_34932 = PC + 1;
	cppVar_34932 = (cppVar_34932 & cppMask_un_16_);
	BIT_VEC cppVar_34933 = ROM.rd(cppVar_34932);
	bool cppVar_34935 = (cppVar_34933 == 141);
	if (cppVar_34935) {
	cppVar_34931 = TH1;
	} else {
	BIT_VEC cppVar_34936;
	BIT_VEC cppVar_34937 = PC + 1;
	cppVar_34937 = (cppVar_34937 & cppMask_un_16_);
	BIT_VEC cppVar_34938 = ROM.rd(cppVar_34937);
	bool cppVar_34940 = (cppVar_34938 == 144);
	if (cppVar_34940) {
	cppVar_34936 = P1;
	} else {
	BIT_VEC cppVar_34941;
	BIT_VEC cppVar_34942 = PC + 1;
	cppVar_34942 = (cppVar_34942 & cppMask_un_16_);
	BIT_VEC cppVar_34943 = ROM.rd(cppVar_34942);
	bool cppVar_34945 = (cppVar_34943 == 152);
	if (cppVar_34945) {
	cppVar_34941 = SCON;
	} else {
	BIT_VEC cppVar_34946;
	BIT_VEC cppVar_34947 = PC + 1;
	cppVar_34947 = (cppVar_34947 & cppMask_un_16_);
	BIT_VEC cppVar_34948 = ROM.rd(cppVar_34947);
	bool cppVar_34950 = (cppVar_34948 == 153);
	if (cppVar_34950) {
	cppVar_34946 = SBUF;
	} else {
	BIT_VEC cppVar_34951;
	BIT_VEC cppVar_34952 = PC + 1;
	cppVar_34952 = (cppVar_34952 & cppMask_un_16_);
	BIT_VEC cppVar_34953 = ROM.rd(cppVar_34952);
	bool cppVar_34955 = (cppVar_34953 == 160);
	if (cppVar_34955) {
	cppVar_34951 = P2;
	} else {
	BIT_VEC cppVar_34956;
	BIT_VEC cppVar_34957 = PC + 1;
	cppVar_34957 = (cppVar_34957 & cppMask_un_16_);
	BIT_VEC cppVar_34958 = ROM.rd(cppVar_34957);
	bool cppVar_34960 = (cppVar_34958 == 168);
	if (cppVar_34960) {
	cppVar_34956 = IE;
	} else {
	BIT_VEC cppVar_34961;
	BIT_VEC cppVar_34962 = PC + 1;
	cppVar_34962 = (cppVar_34962 & cppMask_un_16_);
	BIT_VEC cppVar_34963 = ROM.rd(cppVar_34962);
	bool cppVar_34965 = (cppVar_34963 == 176);
	if (cppVar_34965) {
	cppVar_34961 = P3;
	} else {
	BIT_VEC cppVar_34966;
	BIT_VEC cppVar_34967 = PC + 1;
	cppVar_34967 = (cppVar_34967 & cppMask_un_16_);
	BIT_VEC cppVar_34968 = ROM.rd(cppVar_34967);
	bool cppVar_34970 = (cppVar_34968 == 184);
	if (cppVar_34970) {
	cppVar_34966 = IP;
	} else {
	BIT_VEC cppVar_34971;
	BIT_VEC cppVar_34972 = PC + 1;
	cppVar_34972 = (cppVar_34972 & cppMask_un_16_);
	BIT_VEC cppVar_34973 = ROM.rd(cppVar_34972);
	bool cppVar_34975 = (cppVar_34973 == 208);
	if (cppVar_34975) {
	cppVar_34971 = PSW;
	} else {
	BIT_VEC cppVar_34976;
	BIT_VEC cppVar_34977 = PC + 1;
	cppVar_34977 = (cppVar_34977 & cppMask_un_16_);
	BIT_VEC cppVar_34978 = ROM.rd(cppVar_34977);
	bool cppVar_34980 = (cppVar_34978 == 224);
	if (cppVar_34980) {
	cppVar_34976 = ACC;
	} else {
	BIT_VEC cppVar_34981;
	BIT_VEC cppVar_34982 = PC + 1;
	cppVar_34982 = (cppVar_34982 & cppMask_un_16_);
	BIT_VEC cppVar_34983 = ROM.rd(cppVar_34982);
	bool cppVar_34985 = (cppVar_34983 == 240);
	if (cppVar_34985) {
	cppVar_34981 = B;
	} else {
	cppVar_34981 = 0;
	}
	cppVar_34976 = cppVar_34981;
	}
	cppVar_34971 = cppVar_34976;
	}
	cppVar_34966 = cppVar_34971;
	}
	cppVar_34961 = cppVar_34966;
	}
	cppVar_34956 = cppVar_34961;
	}
	cppVar_34951 = cppVar_34956;
	}
	cppVar_34946 = cppVar_34951;
	}
	cppVar_34941 = cppVar_34946;
	}
	cppVar_34936 = cppVar_34941;
	}
	cppVar_34931 = cppVar_34936;
	}
	cppVar_34926 = cppVar_34931;
	}
	cppVar_34921 = cppVar_34926;
	}
	cppVar_34916 = cppVar_34921;
	}
	cppVar_34911 = cppVar_34916;
	}
	cppVar_34906 = cppVar_34911;
	}
	cppVar_34901 = cppVar_34906;
	}
	cppVar_34896 = cppVar_34901;
	}
	cppVar_34891 = cppVar_34896;
	}
	cppVar_34886 = cppVar_34891;
	}
	cppVar_34881 = cppVar_34886;
	}
	cppVar_34872 = cppVar_34881;
	}
	BIT_VEC cppVar_34987 = cppVar_34872 ^ ACC;
	cppVar_34866 = cppVar_34987;
	} else {
	cppVar_34866 = P2;
	}
	cppVar_34862 = cppVar_34866;
	} else {
	BIT_VEC cppVar_34988;
	BIT_VEC cppVar_34989 = ROM.rd(PC);
	bool cppVar_34991 = (cppVar_34989 == 83);
	if (cppVar_34991) {
	BIT_VEC cppVar_34992;
	BIT_VEC cppVar_34994 = PC + 1;
	cppVar_34994 = (cppVar_34994 & cppMask_un_16_);
	BIT_VEC cppVar_34995 = ROM.rd(cppVar_34994);
	bool cppVar_34997 = (cppVar_34995 == 160);
	if (cppVar_34997) {
	BIT_VEC cppVar_34998;
	BIT_VEC cppVar_34999 = PC + 1;
	cppVar_34999 = (cppVar_34999 & cppMask_un_16_);
	BIT_VEC cppVar_35000 = ROM.rd(cppVar_34999);
	BIT_VEC cppVar_35001 = (cppVar_35000 >> 7) & cppMask_un_1_;
	bool cppVar_35003 = (cppVar_35001 == 0);
	if (cppVar_35003) {
	BIT_VEC cppVar_35004 = PC + 1;
	cppVar_35004 = (cppVar_35004 & cppMask_un_16_);
	BIT_VEC cppVar_35005 = ROM.rd(cppVar_35004);
	BIT_VEC cppVar_35006 = IRAM.rd(cppVar_35005);
	cppVar_34998 = cppVar_35006;
	} else {
	BIT_VEC cppVar_35007;
	BIT_VEC cppVar_35008 = PC + 1;
	cppVar_35008 = (cppVar_35008 & cppMask_un_16_);
	BIT_VEC cppVar_35009 = ROM.rd(cppVar_35008);
	bool cppVar_35011 = (cppVar_35009 == 128);
	if (cppVar_35011) {
	cppVar_35007 = P0;
	} else {
	BIT_VEC cppVar_35012;
	BIT_VEC cppVar_35013 = PC + 1;
	cppVar_35013 = (cppVar_35013 & cppMask_un_16_);
	BIT_VEC cppVar_35014 = ROM.rd(cppVar_35013);
	bool cppVar_35016 = (cppVar_35014 == 129);
	if (cppVar_35016) {
	cppVar_35012 = SP;
	} else {
	BIT_VEC cppVar_35017;
	BIT_VEC cppVar_35018 = PC + 1;
	cppVar_35018 = (cppVar_35018 & cppMask_un_16_);
	BIT_VEC cppVar_35019 = ROM.rd(cppVar_35018);
	bool cppVar_35021 = (cppVar_35019 == 130);
	if (cppVar_35021) {
	cppVar_35017 = DPL;
	} else {
	BIT_VEC cppVar_35022;
	BIT_VEC cppVar_35023 = PC + 1;
	cppVar_35023 = (cppVar_35023 & cppMask_un_16_);
	BIT_VEC cppVar_35024 = ROM.rd(cppVar_35023);
	bool cppVar_35026 = (cppVar_35024 == 131);
	if (cppVar_35026) {
	cppVar_35022 = DPH;
	} else {
	BIT_VEC cppVar_35027;
	BIT_VEC cppVar_35028 = PC + 1;
	cppVar_35028 = (cppVar_35028 & cppMask_un_16_);
	BIT_VEC cppVar_35029 = ROM.rd(cppVar_35028);
	bool cppVar_35031 = (cppVar_35029 == 135);
	if (cppVar_35031) {
	cppVar_35027 = PCON;
	} else {
	BIT_VEC cppVar_35032;
	BIT_VEC cppVar_35033 = PC + 1;
	cppVar_35033 = (cppVar_35033 & cppMask_un_16_);
	BIT_VEC cppVar_35034 = ROM.rd(cppVar_35033);
	bool cppVar_35036 = (cppVar_35034 == 136);
	if (cppVar_35036) {
	cppVar_35032 = TCON;
	} else {
	BIT_VEC cppVar_35037;
	BIT_VEC cppVar_35038 = PC + 1;
	cppVar_35038 = (cppVar_35038 & cppMask_un_16_);
	BIT_VEC cppVar_35039 = ROM.rd(cppVar_35038);
	bool cppVar_35041 = (cppVar_35039 == 137);
	if (cppVar_35041) {
	cppVar_35037 = TMOD;
	} else {
	BIT_VEC cppVar_35042;
	BIT_VEC cppVar_35043 = PC + 1;
	cppVar_35043 = (cppVar_35043 & cppMask_un_16_);
	BIT_VEC cppVar_35044 = ROM.rd(cppVar_35043);
	bool cppVar_35046 = (cppVar_35044 == 138);
	if (cppVar_35046) {
	cppVar_35042 = TL0;
	} else {
	BIT_VEC cppVar_35047;
	BIT_VEC cppVar_35048 = PC + 1;
	cppVar_35048 = (cppVar_35048 & cppMask_un_16_);
	BIT_VEC cppVar_35049 = ROM.rd(cppVar_35048);
	bool cppVar_35051 = (cppVar_35049 == 140);
	if (cppVar_35051) {
	cppVar_35047 = TH0;
	} else {
	BIT_VEC cppVar_35052;
	BIT_VEC cppVar_35053 = PC + 1;
	cppVar_35053 = (cppVar_35053 & cppMask_un_16_);
	BIT_VEC cppVar_35054 = ROM.rd(cppVar_35053);
	bool cppVar_35056 = (cppVar_35054 == 139);
	if (cppVar_35056) {
	cppVar_35052 = TL1;
	} else {
	BIT_VEC cppVar_35057;
	BIT_VEC cppVar_35058 = PC + 1;
	cppVar_35058 = (cppVar_35058 & cppMask_un_16_);
	BIT_VEC cppVar_35059 = ROM.rd(cppVar_35058);
	bool cppVar_35061 = (cppVar_35059 == 141);
	if (cppVar_35061) {
	cppVar_35057 = TH1;
	} else {
	BIT_VEC cppVar_35062;
	BIT_VEC cppVar_35063 = PC + 1;
	cppVar_35063 = (cppVar_35063 & cppMask_un_16_);
	BIT_VEC cppVar_35064 = ROM.rd(cppVar_35063);
	bool cppVar_35066 = (cppVar_35064 == 144);
	if (cppVar_35066) {
	cppVar_35062 = P1;
	} else {
	BIT_VEC cppVar_35067;
	BIT_VEC cppVar_35068 = PC + 1;
	cppVar_35068 = (cppVar_35068 & cppMask_un_16_);
	BIT_VEC cppVar_35069 = ROM.rd(cppVar_35068);
	bool cppVar_35071 = (cppVar_35069 == 152);
	if (cppVar_35071) {
	cppVar_35067 = SCON;
	} else {
	BIT_VEC cppVar_35072;
	BIT_VEC cppVar_35073 = PC + 1;
	cppVar_35073 = (cppVar_35073 & cppMask_un_16_);
	BIT_VEC cppVar_35074 = ROM.rd(cppVar_35073);
	bool cppVar_35076 = (cppVar_35074 == 153);
	if (cppVar_35076) {
	cppVar_35072 = SBUF;
	} else {
	BIT_VEC cppVar_35077;
	BIT_VEC cppVar_35078 = PC + 1;
	cppVar_35078 = (cppVar_35078 & cppMask_un_16_);
	BIT_VEC cppVar_35079 = ROM.rd(cppVar_35078);
	bool cppVar_35081 = (cppVar_35079 == 160);
	if (cppVar_35081) {
	cppVar_35077 = P2;
	} else {
	BIT_VEC cppVar_35082;
	BIT_VEC cppVar_35083 = PC + 1;
	cppVar_35083 = (cppVar_35083 & cppMask_un_16_);
	BIT_VEC cppVar_35084 = ROM.rd(cppVar_35083);
	bool cppVar_35086 = (cppVar_35084 == 168);
	if (cppVar_35086) {
	cppVar_35082 = IE;
	} else {
	BIT_VEC cppVar_35087;
	BIT_VEC cppVar_35088 = PC + 1;
	cppVar_35088 = (cppVar_35088 & cppMask_un_16_);
	BIT_VEC cppVar_35089 = ROM.rd(cppVar_35088);
	bool cppVar_35091 = (cppVar_35089 == 176);
	if (cppVar_35091) {
	cppVar_35087 = P3;
	} else {
	BIT_VEC cppVar_35092;
	BIT_VEC cppVar_35093 = PC + 1;
	cppVar_35093 = (cppVar_35093 & cppMask_un_16_);
	BIT_VEC cppVar_35094 = ROM.rd(cppVar_35093);
	bool cppVar_35096 = (cppVar_35094 == 184);
	if (cppVar_35096) {
	cppVar_35092 = IP;
	} else {
	BIT_VEC cppVar_35097;
	BIT_VEC cppVar_35098 = PC + 1;
	cppVar_35098 = (cppVar_35098 & cppMask_un_16_);
	BIT_VEC cppVar_35099 = ROM.rd(cppVar_35098);
	bool cppVar_35101 = (cppVar_35099 == 208);
	if (cppVar_35101) {
	cppVar_35097 = PSW;
	} else {
	BIT_VEC cppVar_35102;
	BIT_VEC cppVar_35103 = PC + 1;
	cppVar_35103 = (cppVar_35103 & cppMask_un_16_);
	BIT_VEC cppVar_35104 = ROM.rd(cppVar_35103);
	bool cppVar_35106 = (cppVar_35104 == 224);
	if (cppVar_35106) {
	cppVar_35102 = ACC;
	} else {
	BIT_VEC cppVar_35107;
	BIT_VEC cppVar_35108 = PC + 1;
	cppVar_35108 = (cppVar_35108 & cppMask_un_16_);
	BIT_VEC cppVar_35109 = ROM.rd(cppVar_35108);
	bool cppVar_35111 = (cppVar_35109 == 240);
	if (cppVar_35111) {
	cppVar_35107 = B;
	} else {
	cppVar_35107 = 0;
	}
	cppVar_35102 = cppVar_35107;
	}
	cppVar_35097 = cppVar_35102;
	}
	cppVar_35092 = cppVar_35097;
	}
	cppVar_35087 = cppVar_35092;
	}
	cppVar_35082 = cppVar_35087;
	}
	cppVar_35077 = cppVar_35082;
	}
	cppVar_35072 = cppVar_35077;
	}
	cppVar_35067 = cppVar_35072;
	}
	cppVar_35062 = cppVar_35067;
	}
	cppVar_35057 = cppVar_35062;
	}
	cppVar_35052 = cppVar_35057;
	}
	cppVar_35047 = cppVar_35052;
	}
	cppVar_35042 = cppVar_35047;
	}
	cppVar_35037 = cppVar_35042;
	}
	cppVar_35032 = cppVar_35037;
	}
	cppVar_35027 = cppVar_35032;
	}
	cppVar_35022 = cppVar_35027;
	}
	cppVar_35017 = cppVar_35022;
	}
	cppVar_35012 = cppVar_35017;
	}
	cppVar_35007 = cppVar_35012;
	}
	cppVar_34998 = cppVar_35007;
	}
	BIT_VEC cppVar_35114 = PC + 2;
	cppVar_35114 = (cppVar_35114 & cppMask_un_16_);
	BIT_VEC cppVar_35115 = ROM.rd(cppVar_35114);
	BIT_VEC cppVar_35116 = cppVar_34998 & cppVar_35115;
	cppVar_34992 = cppVar_35116;
	} else {
	cppVar_34992 = P2;
	}
	cppVar_34988 = cppVar_34992;
	} else {
	BIT_VEC cppVar_35117;
	BIT_VEC cppVar_35118 = ROM.rd(PC);
	bool cppVar_35120 = (cppVar_35118 == 82);
	if (cppVar_35120) {
	BIT_VEC cppVar_35121;
	BIT_VEC cppVar_35123 = PC + 1;
	cppVar_35123 = (cppVar_35123 & cppMask_un_16_);
	BIT_VEC cppVar_35124 = ROM.rd(cppVar_35123);
	bool cppVar_35126 = (cppVar_35124 == 160);
	if (cppVar_35126) {
	BIT_VEC cppVar_35127;
	BIT_VEC cppVar_35128 = PC + 1;
	cppVar_35128 = (cppVar_35128 & cppMask_un_16_);
	BIT_VEC cppVar_35129 = ROM.rd(cppVar_35128);
	BIT_VEC cppVar_35130 = (cppVar_35129 >> 7) & cppMask_un_1_;
	bool cppVar_35132 = (cppVar_35130 == 0);
	if (cppVar_35132) {
	BIT_VEC cppVar_35133 = PC + 1;
	cppVar_35133 = (cppVar_35133 & cppMask_un_16_);
	BIT_VEC cppVar_35134 = ROM.rd(cppVar_35133);
	BIT_VEC cppVar_35135 = IRAM.rd(cppVar_35134);
	cppVar_35127 = cppVar_35135;
	} else {
	BIT_VEC cppVar_35136;
	BIT_VEC cppVar_35137 = PC + 1;
	cppVar_35137 = (cppVar_35137 & cppMask_un_16_);
	BIT_VEC cppVar_35138 = ROM.rd(cppVar_35137);
	bool cppVar_35140 = (cppVar_35138 == 128);
	if (cppVar_35140) {
	cppVar_35136 = P0;
	} else {
	BIT_VEC cppVar_35141;
	BIT_VEC cppVar_35142 = PC + 1;
	cppVar_35142 = (cppVar_35142 & cppMask_un_16_);
	BIT_VEC cppVar_35143 = ROM.rd(cppVar_35142);
	bool cppVar_35145 = (cppVar_35143 == 129);
	if (cppVar_35145) {
	cppVar_35141 = SP;
	} else {
	BIT_VEC cppVar_35146;
	BIT_VEC cppVar_35147 = PC + 1;
	cppVar_35147 = (cppVar_35147 & cppMask_un_16_);
	BIT_VEC cppVar_35148 = ROM.rd(cppVar_35147);
	bool cppVar_35150 = (cppVar_35148 == 130);
	if (cppVar_35150) {
	cppVar_35146 = DPL;
	} else {
	BIT_VEC cppVar_35151;
	BIT_VEC cppVar_35152 = PC + 1;
	cppVar_35152 = (cppVar_35152 & cppMask_un_16_);
	BIT_VEC cppVar_35153 = ROM.rd(cppVar_35152);
	bool cppVar_35155 = (cppVar_35153 == 131);
	if (cppVar_35155) {
	cppVar_35151 = DPH;
	} else {
	BIT_VEC cppVar_35156;
	BIT_VEC cppVar_35157 = PC + 1;
	cppVar_35157 = (cppVar_35157 & cppMask_un_16_);
	BIT_VEC cppVar_35158 = ROM.rd(cppVar_35157);
	bool cppVar_35160 = (cppVar_35158 == 135);
	if (cppVar_35160) {
	cppVar_35156 = PCON;
	} else {
	BIT_VEC cppVar_35161;
	BIT_VEC cppVar_35162 = PC + 1;
	cppVar_35162 = (cppVar_35162 & cppMask_un_16_);
	BIT_VEC cppVar_35163 = ROM.rd(cppVar_35162);
	bool cppVar_35165 = (cppVar_35163 == 136);
	if (cppVar_35165) {
	cppVar_35161 = TCON;
	} else {
	BIT_VEC cppVar_35166;
	BIT_VEC cppVar_35167 = PC + 1;
	cppVar_35167 = (cppVar_35167 & cppMask_un_16_);
	BIT_VEC cppVar_35168 = ROM.rd(cppVar_35167);
	bool cppVar_35170 = (cppVar_35168 == 137);
	if (cppVar_35170) {
	cppVar_35166 = TMOD;
	} else {
	BIT_VEC cppVar_35171;
	BIT_VEC cppVar_35172 = PC + 1;
	cppVar_35172 = (cppVar_35172 & cppMask_un_16_);
	BIT_VEC cppVar_35173 = ROM.rd(cppVar_35172);
	bool cppVar_35175 = (cppVar_35173 == 138);
	if (cppVar_35175) {
	cppVar_35171 = TL0;
	} else {
	BIT_VEC cppVar_35176;
	BIT_VEC cppVar_35177 = PC + 1;
	cppVar_35177 = (cppVar_35177 & cppMask_un_16_);
	BIT_VEC cppVar_35178 = ROM.rd(cppVar_35177);
	bool cppVar_35180 = (cppVar_35178 == 140);
	if (cppVar_35180) {
	cppVar_35176 = TH0;
	} else {
	BIT_VEC cppVar_35181;
	BIT_VEC cppVar_35182 = PC + 1;
	cppVar_35182 = (cppVar_35182 & cppMask_un_16_);
	BIT_VEC cppVar_35183 = ROM.rd(cppVar_35182);
	bool cppVar_35185 = (cppVar_35183 == 139);
	if (cppVar_35185) {
	cppVar_35181 = TL1;
	} else {
	BIT_VEC cppVar_35186;
	BIT_VEC cppVar_35187 = PC + 1;
	cppVar_35187 = (cppVar_35187 & cppMask_un_16_);
	BIT_VEC cppVar_35188 = ROM.rd(cppVar_35187);
	bool cppVar_35190 = (cppVar_35188 == 141);
	if (cppVar_35190) {
	cppVar_35186 = TH1;
	} else {
	BIT_VEC cppVar_35191;
	BIT_VEC cppVar_35192 = PC + 1;
	cppVar_35192 = (cppVar_35192 & cppMask_un_16_);
	BIT_VEC cppVar_35193 = ROM.rd(cppVar_35192);
	bool cppVar_35195 = (cppVar_35193 == 144);
	if (cppVar_35195) {
	cppVar_35191 = P1;
	} else {
	BIT_VEC cppVar_35196;
	BIT_VEC cppVar_35197 = PC + 1;
	cppVar_35197 = (cppVar_35197 & cppMask_un_16_);
	BIT_VEC cppVar_35198 = ROM.rd(cppVar_35197);
	bool cppVar_35200 = (cppVar_35198 == 152);
	if (cppVar_35200) {
	cppVar_35196 = SCON;
	} else {
	BIT_VEC cppVar_35201;
	BIT_VEC cppVar_35202 = PC + 1;
	cppVar_35202 = (cppVar_35202 & cppMask_un_16_);
	BIT_VEC cppVar_35203 = ROM.rd(cppVar_35202);
	bool cppVar_35205 = (cppVar_35203 == 153);
	if (cppVar_35205) {
	cppVar_35201 = SBUF;
	} else {
	BIT_VEC cppVar_35206;
	BIT_VEC cppVar_35207 = PC + 1;
	cppVar_35207 = (cppVar_35207 & cppMask_un_16_);
	BIT_VEC cppVar_35208 = ROM.rd(cppVar_35207);
	bool cppVar_35210 = (cppVar_35208 == 160);
	if (cppVar_35210) {
	cppVar_35206 = P2;
	} else {
	BIT_VEC cppVar_35211;
	BIT_VEC cppVar_35212 = PC + 1;
	cppVar_35212 = (cppVar_35212 & cppMask_un_16_);
	BIT_VEC cppVar_35213 = ROM.rd(cppVar_35212);
	bool cppVar_35215 = (cppVar_35213 == 168);
	if (cppVar_35215) {
	cppVar_35211 = IE;
	} else {
	BIT_VEC cppVar_35216;
	BIT_VEC cppVar_35217 = PC + 1;
	cppVar_35217 = (cppVar_35217 & cppMask_un_16_);
	BIT_VEC cppVar_35218 = ROM.rd(cppVar_35217);
	bool cppVar_35220 = (cppVar_35218 == 176);
	if (cppVar_35220) {
	cppVar_35216 = P3;
	} else {
	BIT_VEC cppVar_35221;
	BIT_VEC cppVar_35222 = PC + 1;
	cppVar_35222 = (cppVar_35222 & cppMask_un_16_);
	BIT_VEC cppVar_35223 = ROM.rd(cppVar_35222);
	bool cppVar_35225 = (cppVar_35223 == 184);
	if (cppVar_35225) {
	cppVar_35221 = IP;
	} else {
	BIT_VEC cppVar_35226;
	BIT_VEC cppVar_35227 = PC + 1;
	cppVar_35227 = (cppVar_35227 & cppMask_un_16_);
	BIT_VEC cppVar_35228 = ROM.rd(cppVar_35227);
	bool cppVar_35230 = (cppVar_35228 == 208);
	if (cppVar_35230) {
	cppVar_35226 = PSW;
	} else {
	BIT_VEC cppVar_35231;
	BIT_VEC cppVar_35232 = PC + 1;
	cppVar_35232 = (cppVar_35232 & cppMask_un_16_);
	BIT_VEC cppVar_35233 = ROM.rd(cppVar_35232);
	bool cppVar_35235 = (cppVar_35233 == 224);
	if (cppVar_35235) {
	cppVar_35231 = ACC;
	} else {
	BIT_VEC cppVar_35236;
	BIT_VEC cppVar_35237 = PC + 1;
	cppVar_35237 = (cppVar_35237 & cppMask_un_16_);
	BIT_VEC cppVar_35238 = ROM.rd(cppVar_35237);
	bool cppVar_35240 = (cppVar_35238 == 240);
	if (cppVar_35240) {
	cppVar_35236 = B;
	} else {
	cppVar_35236 = 0;
	}
	cppVar_35231 = cppVar_35236;
	}
	cppVar_35226 = cppVar_35231;
	}
	cppVar_35221 = cppVar_35226;
	}
	cppVar_35216 = cppVar_35221;
	}
	cppVar_35211 = cppVar_35216;
	}
	cppVar_35206 = cppVar_35211;
	}
	cppVar_35201 = cppVar_35206;
	}
	cppVar_35196 = cppVar_35201;
	}
	cppVar_35191 = cppVar_35196;
	}
	cppVar_35186 = cppVar_35191;
	}
	cppVar_35181 = cppVar_35186;
	}
	cppVar_35176 = cppVar_35181;
	}
	cppVar_35171 = cppVar_35176;
	}
	cppVar_35166 = cppVar_35171;
	}
	cppVar_35161 = cppVar_35166;
	}
	cppVar_35156 = cppVar_35161;
	}
	cppVar_35151 = cppVar_35156;
	}
	cppVar_35146 = cppVar_35151;
	}
	cppVar_35141 = cppVar_35146;
	}
	cppVar_35136 = cppVar_35141;
	}
	cppVar_35127 = cppVar_35136;
	}
	BIT_VEC cppVar_35242 = cppVar_35127 & ACC;
	cppVar_35121 = cppVar_35242;
	} else {
	cppVar_35121 = P2;
	}
	cppVar_35117 = cppVar_35121;
	} else {
	BIT_VEC cppVar_35243;
	BIT_VEC cppVar_35244 = ROM.rd(PC);
	bool cppVar_35246 = (cppVar_35244 == 67);
	if (cppVar_35246) {
	BIT_VEC cppVar_35247;
	BIT_VEC cppVar_35249 = PC + 1;
	cppVar_35249 = (cppVar_35249 & cppMask_un_16_);
	BIT_VEC cppVar_35250 = ROM.rd(cppVar_35249);
	bool cppVar_35252 = (cppVar_35250 == 160);
	if (cppVar_35252) {
	BIT_VEC cppVar_35253;
	BIT_VEC cppVar_35254 = PC + 1;
	cppVar_35254 = (cppVar_35254 & cppMask_un_16_);
	BIT_VEC cppVar_35255 = ROM.rd(cppVar_35254);
	BIT_VEC cppVar_35256 = (cppVar_35255 >> 7) & cppMask_un_1_;
	bool cppVar_35258 = (cppVar_35256 == 0);
	if (cppVar_35258) {
	BIT_VEC cppVar_35259 = PC + 1;
	cppVar_35259 = (cppVar_35259 & cppMask_un_16_);
	BIT_VEC cppVar_35260 = ROM.rd(cppVar_35259);
	BIT_VEC cppVar_35261 = IRAM.rd(cppVar_35260);
	cppVar_35253 = cppVar_35261;
	} else {
	BIT_VEC cppVar_35262;
	BIT_VEC cppVar_35263 = PC + 1;
	cppVar_35263 = (cppVar_35263 & cppMask_un_16_);
	BIT_VEC cppVar_35264 = ROM.rd(cppVar_35263);
	bool cppVar_35266 = (cppVar_35264 == 128);
	if (cppVar_35266) {
	cppVar_35262 = P0;
	} else {
	BIT_VEC cppVar_35267;
	BIT_VEC cppVar_35268 = PC + 1;
	cppVar_35268 = (cppVar_35268 & cppMask_un_16_);
	BIT_VEC cppVar_35269 = ROM.rd(cppVar_35268);
	bool cppVar_35271 = (cppVar_35269 == 129);
	if (cppVar_35271) {
	cppVar_35267 = SP;
	} else {
	BIT_VEC cppVar_35272;
	BIT_VEC cppVar_35273 = PC + 1;
	cppVar_35273 = (cppVar_35273 & cppMask_un_16_);
	BIT_VEC cppVar_35274 = ROM.rd(cppVar_35273);
	bool cppVar_35276 = (cppVar_35274 == 130);
	if (cppVar_35276) {
	cppVar_35272 = DPL;
	} else {
	BIT_VEC cppVar_35277;
	BIT_VEC cppVar_35278 = PC + 1;
	cppVar_35278 = (cppVar_35278 & cppMask_un_16_);
	BIT_VEC cppVar_35279 = ROM.rd(cppVar_35278);
	bool cppVar_35281 = (cppVar_35279 == 131);
	if (cppVar_35281) {
	cppVar_35277 = DPH;
	} else {
	BIT_VEC cppVar_35282;
	BIT_VEC cppVar_35283 = PC + 1;
	cppVar_35283 = (cppVar_35283 & cppMask_un_16_);
	BIT_VEC cppVar_35284 = ROM.rd(cppVar_35283);
	bool cppVar_35286 = (cppVar_35284 == 135);
	if (cppVar_35286) {
	cppVar_35282 = PCON;
	} else {
	BIT_VEC cppVar_35287;
	BIT_VEC cppVar_35288 = PC + 1;
	cppVar_35288 = (cppVar_35288 & cppMask_un_16_);
	BIT_VEC cppVar_35289 = ROM.rd(cppVar_35288);
	bool cppVar_35291 = (cppVar_35289 == 136);
	if (cppVar_35291) {
	cppVar_35287 = TCON;
	} else {
	BIT_VEC cppVar_35292;
	BIT_VEC cppVar_35293 = PC + 1;
	cppVar_35293 = (cppVar_35293 & cppMask_un_16_);
	BIT_VEC cppVar_35294 = ROM.rd(cppVar_35293);
	bool cppVar_35296 = (cppVar_35294 == 137);
	if (cppVar_35296) {
	cppVar_35292 = TMOD;
	} else {
	BIT_VEC cppVar_35297;
	BIT_VEC cppVar_35298 = PC + 1;
	cppVar_35298 = (cppVar_35298 & cppMask_un_16_);
	BIT_VEC cppVar_35299 = ROM.rd(cppVar_35298);
	bool cppVar_35301 = (cppVar_35299 == 138);
	if (cppVar_35301) {
	cppVar_35297 = TL0;
	} else {
	BIT_VEC cppVar_35302;
	BIT_VEC cppVar_35303 = PC + 1;
	cppVar_35303 = (cppVar_35303 & cppMask_un_16_);
	BIT_VEC cppVar_35304 = ROM.rd(cppVar_35303);
	bool cppVar_35306 = (cppVar_35304 == 140);
	if (cppVar_35306) {
	cppVar_35302 = TH0;
	} else {
	BIT_VEC cppVar_35307;
	BIT_VEC cppVar_35308 = PC + 1;
	cppVar_35308 = (cppVar_35308 & cppMask_un_16_);
	BIT_VEC cppVar_35309 = ROM.rd(cppVar_35308);
	bool cppVar_35311 = (cppVar_35309 == 139);
	if (cppVar_35311) {
	cppVar_35307 = TL1;
	} else {
	BIT_VEC cppVar_35312;
	BIT_VEC cppVar_35313 = PC + 1;
	cppVar_35313 = (cppVar_35313 & cppMask_un_16_);
	BIT_VEC cppVar_35314 = ROM.rd(cppVar_35313);
	bool cppVar_35316 = (cppVar_35314 == 141);
	if (cppVar_35316) {
	cppVar_35312 = TH1;
	} else {
	BIT_VEC cppVar_35317;
	BIT_VEC cppVar_35318 = PC + 1;
	cppVar_35318 = (cppVar_35318 & cppMask_un_16_);
	BIT_VEC cppVar_35319 = ROM.rd(cppVar_35318);
	bool cppVar_35321 = (cppVar_35319 == 144);
	if (cppVar_35321) {
	cppVar_35317 = P1;
	} else {
	BIT_VEC cppVar_35322;
	BIT_VEC cppVar_35323 = PC + 1;
	cppVar_35323 = (cppVar_35323 & cppMask_un_16_);
	BIT_VEC cppVar_35324 = ROM.rd(cppVar_35323);
	bool cppVar_35326 = (cppVar_35324 == 152);
	if (cppVar_35326) {
	cppVar_35322 = SCON;
	} else {
	BIT_VEC cppVar_35327;
	BIT_VEC cppVar_35328 = PC + 1;
	cppVar_35328 = (cppVar_35328 & cppMask_un_16_);
	BIT_VEC cppVar_35329 = ROM.rd(cppVar_35328);
	bool cppVar_35331 = (cppVar_35329 == 153);
	if (cppVar_35331) {
	cppVar_35327 = SBUF;
	} else {
	BIT_VEC cppVar_35332;
	BIT_VEC cppVar_35333 = PC + 1;
	cppVar_35333 = (cppVar_35333 & cppMask_un_16_);
	BIT_VEC cppVar_35334 = ROM.rd(cppVar_35333);
	bool cppVar_35336 = (cppVar_35334 == 160);
	if (cppVar_35336) {
	cppVar_35332 = P2;
	} else {
	BIT_VEC cppVar_35337;
	BIT_VEC cppVar_35338 = PC + 1;
	cppVar_35338 = (cppVar_35338 & cppMask_un_16_);
	BIT_VEC cppVar_35339 = ROM.rd(cppVar_35338);
	bool cppVar_35341 = (cppVar_35339 == 168);
	if (cppVar_35341) {
	cppVar_35337 = IE;
	} else {
	BIT_VEC cppVar_35342;
	BIT_VEC cppVar_35343 = PC + 1;
	cppVar_35343 = (cppVar_35343 & cppMask_un_16_);
	BIT_VEC cppVar_35344 = ROM.rd(cppVar_35343);
	bool cppVar_35346 = (cppVar_35344 == 176);
	if (cppVar_35346) {
	cppVar_35342 = P3;
	} else {
	BIT_VEC cppVar_35347;
	BIT_VEC cppVar_35348 = PC + 1;
	cppVar_35348 = (cppVar_35348 & cppMask_un_16_);
	BIT_VEC cppVar_35349 = ROM.rd(cppVar_35348);
	bool cppVar_35351 = (cppVar_35349 == 184);
	if (cppVar_35351) {
	cppVar_35347 = IP;
	} else {
	BIT_VEC cppVar_35352;
	BIT_VEC cppVar_35353 = PC + 1;
	cppVar_35353 = (cppVar_35353 & cppMask_un_16_);
	BIT_VEC cppVar_35354 = ROM.rd(cppVar_35353);
	bool cppVar_35356 = (cppVar_35354 == 208);
	if (cppVar_35356) {
	cppVar_35352 = PSW;
	} else {
	BIT_VEC cppVar_35357;
	BIT_VEC cppVar_35358 = PC + 1;
	cppVar_35358 = (cppVar_35358 & cppMask_un_16_);
	BIT_VEC cppVar_35359 = ROM.rd(cppVar_35358);
	bool cppVar_35361 = (cppVar_35359 == 224);
	if (cppVar_35361) {
	cppVar_35357 = ACC;
	} else {
	BIT_VEC cppVar_35362;
	BIT_VEC cppVar_35363 = PC + 1;
	cppVar_35363 = (cppVar_35363 & cppMask_un_16_);
	BIT_VEC cppVar_35364 = ROM.rd(cppVar_35363);
	bool cppVar_35366 = (cppVar_35364 == 240);
	if (cppVar_35366) {
	cppVar_35362 = B;
	} else {
	cppVar_35362 = 0;
	}
	cppVar_35357 = cppVar_35362;
	}
	cppVar_35352 = cppVar_35357;
	}
	cppVar_35347 = cppVar_35352;
	}
	cppVar_35342 = cppVar_35347;
	}
	cppVar_35337 = cppVar_35342;
	}
	cppVar_35332 = cppVar_35337;
	}
	cppVar_35327 = cppVar_35332;
	}
	cppVar_35322 = cppVar_35327;
	}
	cppVar_35317 = cppVar_35322;
	}
	cppVar_35312 = cppVar_35317;
	}
	cppVar_35307 = cppVar_35312;
	}
	cppVar_35302 = cppVar_35307;
	}
	cppVar_35297 = cppVar_35302;
	}
	cppVar_35292 = cppVar_35297;
	}
	cppVar_35287 = cppVar_35292;
	}
	cppVar_35282 = cppVar_35287;
	}
	cppVar_35277 = cppVar_35282;
	}
	cppVar_35272 = cppVar_35277;
	}
	cppVar_35267 = cppVar_35272;
	}
	cppVar_35262 = cppVar_35267;
	}
	cppVar_35253 = cppVar_35262;
	}
	BIT_VEC cppVar_35369 = PC + 2;
	cppVar_35369 = (cppVar_35369 & cppMask_un_16_);
	BIT_VEC cppVar_35370 = ROM.rd(cppVar_35369);
	BIT_VEC cppVar_35371 = cppVar_35253 | cppVar_35370;
	cppVar_35247 = cppVar_35371;
	} else {
	cppVar_35247 = P2;
	}
	cppVar_35243 = cppVar_35247;
	} else {
	BIT_VEC cppVar_35372;
	BIT_VEC cppVar_35373 = ROM.rd(PC);
	bool cppVar_35375 = (cppVar_35373 == 66);
	if (cppVar_35375) {
	BIT_VEC cppVar_35376;
	BIT_VEC cppVar_35378 = PC + 1;
	cppVar_35378 = (cppVar_35378 & cppMask_un_16_);
	BIT_VEC cppVar_35379 = ROM.rd(cppVar_35378);
	bool cppVar_35381 = (cppVar_35379 == 160);
	if (cppVar_35381) {
	BIT_VEC cppVar_35382;
	BIT_VEC cppVar_35383 = PC + 1;
	cppVar_35383 = (cppVar_35383 & cppMask_un_16_);
	BIT_VEC cppVar_35384 = ROM.rd(cppVar_35383);
	BIT_VEC cppVar_35385 = (cppVar_35384 >> 7) & cppMask_un_1_;
	bool cppVar_35387 = (cppVar_35385 == 0);
	if (cppVar_35387) {
	BIT_VEC cppVar_35388 = PC + 1;
	cppVar_35388 = (cppVar_35388 & cppMask_un_16_);
	BIT_VEC cppVar_35389 = ROM.rd(cppVar_35388);
	BIT_VEC cppVar_35390 = IRAM.rd(cppVar_35389);
	cppVar_35382 = cppVar_35390;
	} else {
	BIT_VEC cppVar_35391;
	BIT_VEC cppVar_35392 = PC + 1;
	cppVar_35392 = (cppVar_35392 & cppMask_un_16_);
	BIT_VEC cppVar_35393 = ROM.rd(cppVar_35392);
	bool cppVar_35395 = (cppVar_35393 == 128);
	if (cppVar_35395) {
	cppVar_35391 = P0;
	} else {
	BIT_VEC cppVar_35396;
	BIT_VEC cppVar_35397 = PC + 1;
	cppVar_35397 = (cppVar_35397 & cppMask_un_16_);
	BIT_VEC cppVar_35398 = ROM.rd(cppVar_35397);
	bool cppVar_35400 = (cppVar_35398 == 129);
	if (cppVar_35400) {
	cppVar_35396 = SP;
	} else {
	BIT_VEC cppVar_35401;
	BIT_VEC cppVar_35402 = PC + 1;
	cppVar_35402 = (cppVar_35402 & cppMask_un_16_);
	BIT_VEC cppVar_35403 = ROM.rd(cppVar_35402);
	bool cppVar_35405 = (cppVar_35403 == 130);
	if (cppVar_35405) {
	cppVar_35401 = DPL;
	} else {
	BIT_VEC cppVar_35406;
	BIT_VEC cppVar_35407 = PC + 1;
	cppVar_35407 = (cppVar_35407 & cppMask_un_16_);
	BIT_VEC cppVar_35408 = ROM.rd(cppVar_35407);
	bool cppVar_35410 = (cppVar_35408 == 131);
	if (cppVar_35410) {
	cppVar_35406 = DPH;
	} else {
	BIT_VEC cppVar_35411;
	BIT_VEC cppVar_35412 = PC + 1;
	cppVar_35412 = (cppVar_35412 & cppMask_un_16_);
	BIT_VEC cppVar_35413 = ROM.rd(cppVar_35412);
	bool cppVar_35415 = (cppVar_35413 == 135);
	if (cppVar_35415) {
	cppVar_35411 = PCON;
	} else {
	BIT_VEC cppVar_35416;
	BIT_VEC cppVar_35417 = PC + 1;
	cppVar_35417 = (cppVar_35417 & cppMask_un_16_);
	BIT_VEC cppVar_35418 = ROM.rd(cppVar_35417);
	bool cppVar_35420 = (cppVar_35418 == 136);
	if (cppVar_35420) {
	cppVar_35416 = TCON;
	} else {
	BIT_VEC cppVar_35421;
	BIT_VEC cppVar_35422 = PC + 1;
	cppVar_35422 = (cppVar_35422 & cppMask_un_16_);
	BIT_VEC cppVar_35423 = ROM.rd(cppVar_35422);
	bool cppVar_35425 = (cppVar_35423 == 137);
	if (cppVar_35425) {
	cppVar_35421 = TMOD;
	} else {
	BIT_VEC cppVar_35426;
	BIT_VEC cppVar_35427 = PC + 1;
	cppVar_35427 = (cppVar_35427 & cppMask_un_16_);
	BIT_VEC cppVar_35428 = ROM.rd(cppVar_35427);
	bool cppVar_35430 = (cppVar_35428 == 138);
	if (cppVar_35430) {
	cppVar_35426 = TL0;
	} else {
	BIT_VEC cppVar_35431;
	BIT_VEC cppVar_35432 = PC + 1;
	cppVar_35432 = (cppVar_35432 & cppMask_un_16_);
	BIT_VEC cppVar_35433 = ROM.rd(cppVar_35432);
	bool cppVar_35435 = (cppVar_35433 == 140);
	if (cppVar_35435) {
	cppVar_35431 = TH0;
	} else {
	BIT_VEC cppVar_35436;
	BIT_VEC cppVar_35437 = PC + 1;
	cppVar_35437 = (cppVar_35437 & cppMask_un_16_);
	BIT_VEC cppVar_35438 = ROM.rd(cppVar_35437);
	bool cppVar_35440 = (cppVar_35438 == 139);
	if (cppVar_35440) {
	cppVar_35436 = TL1;
	} else {
	BIT_VEC cppVar_35441;
	BIT_VEC cppVar_35442 = PC + 1;
	cppVar_35442 = (cppVar_35442 & cppMask_un_16_);
	BIT_VEC cppVar_35443 = ROM.rd(cppVar_35442);
	bool cppVar_35445 = (cppVar_35443 == 141);
	if (cppVar_35445) {
	cppVar_35441 = TH1;
	} else {
	BIT_VEC cppVar_35446;
	BIT_VEC cppVar_35447 = PC + 1;
	cppVar_35447 = (cppVar_35447 & cppMask_un_16_);
	BIT_VEC cppVar_35448 = ROM.rd(cppVar_35447);
	bool cppVar_35450 = (cppVar_35448 == 144);
	if (cppVar_35450) {
	cppVar_35446 = P1;
	} else {
	BIT_VEC cppVar_35451;
	BIT_VEC cppVar_35452 = PC + 1;
	cppVar_35452 = (cppVar_35452 & cppMask_un_16_);
	BIT_VEC cppVar_35453 = ROM.rd(cppVar_35452);
	bool cppVar_35455 = (cppVar_35453 == 152);
	if (cppVar_35455) {
	cppVar_35451 = SCON;
	} else {
	BIT_VEC cppVar_35456;
	BIT_VEC cppVar_35457 = PC + 1;
	cppVar_35457 = (cppVar_35457 & cppMask_un_16_);
	BIT_VEC cppVar_35458 = ROM.rd(cppVar_35457);
	bool cppVar_35460 = (cppVar_35458 == 153);
	if (cppVar_35460) {
	cppVar_35456 = SBUF;
	} else {
	BIT_VEC cppVar_35461;
	BIT_VEC cppVar_35462 = PC + 1;
	cppVar_35462 = (cppVar_35462 & cppMask_un_16_);
	BIT_VEC cppVar_35463 = ROM.rd(cppVar_35462);
	bool cppVar_35465 = (cppVar_35463 == 160);
	if (cppVar_35465) {
	cppVar_35461 = P2;
	} else {
	BIT_VEC cppVar_35466;
	BIT_VEC cppVar_35467 = PC + 1;
	cppVar_35467 = (cppVar_35467 & cppMask_un_16_);
	BIT_VEC cppVar_35468 = ROM.rd(cppVar_35467);
	bool cppVar_35470 = (cppVar_35468 == 168);
	if (cppVar_35470) {
	cppVar_35466 = IE;
	} else {
	BIT_VEC cppVar_35471;
	BIT_VEC cppVar_35472 = PC + 1;
	cppVar_35472 = (cppVar_35472 & cppMask_un_16_);
	BIT_VEC cppVar_35473 = ROM.rd(cppVar_35472);
	bool cppVar_35475 = (cppVar_35473 == 176);
	if (cppVar_35475) {
	cppVar_35471 = P3;
	} else {
	BIT_VEC cppVar_35476;
	BIT_VEC cppVar_35477 = PC + 1;
	cppVar_35477 = (cppVar_35477 & cppMask_un_16_);
	BIT_VEC cppVar_35478 = ROM.rd(cppVar_35477);
	bool cppVar_35480 = (cppVar_35478 == 184);
	if (cppVar_35480) {
	cppVar_35476 = IP;
	} else {
	BIT_VEC cppVar_35481;
	BIT_VEC cppVar_35482 = PC + 1;
	cppVar_35482 = (cppVar_35482 & cppMask_un_16_);
	BIT_VEC cppVar_35483 = ROM.rd(cppVar_35482);
	bool cppVar_35485 = (cppVar_35483 == 208);
	if (cppVar_35485) {
	cppVar_35481 = PSW;
	} else {
	BIT_VEC cppVar_35486;
	BIT_VEC cppVar_35487 = PC + 1;
	cppVar_35487 = (cppVar_35487 & cppMask_un_16_);
	BIT_VEC cppVar_35488 = ROM.rd(cppVar_35487);
	bool cppVar_35490 = (cppVar_35488 == 224);
	if (cppVar_35490) {
	cppVar_35486 = ACC;
	} else {
	BIT_VEC cppVar_35491;
	BIT_VEC cppVar_35492 = PC + 1;
	cppVar_35492 = (cppVar_35492 & cppMask_un_16_);
	BIT_VEC cppVar_35493 = ROM.rd(cppVar_35492);
	bool cppVar_35495 = (cppVar_35493 == 240);
	if (cppVar_35495) {
	cppVar_35491 = B;
	} else {
	cppVar_35491 = 0;
	}
	cppVar_35486 = cppVar_35491;
	}
	cppVar_35481 = cppVar_35486;
	}
	cppVar_35476 = cppVar_35481;
	}
	cppVar_35471 = cppVar_35476;
	}
	cppVar_35466 = cppVar_35471;
	}
	cppVar_35461 = cppVar_35466;
	}
	cppVar_35456 = cppVar_35461;
	}
	cppVar_35451 = cppVar_35456;
	}
	cppVar_35446 = cppVar_35451;
	}
	cppVar_35441 = cppVar_35446;
	}
	cppVar_35436 = cppVar_35441;
	}
	cppVar_35431 = cppVar_35436;
	}
	cppVar_35426 = cppVar_35431;
	}
	cppVar_35421 = cppVar_35426;
	}
	cppVar_35416 = cppVar_35421;
	}
	cppVar_35411 = cppVar_35416;
	}
	cppVar_35406 = cppVar_35411;
	}
	cppVar_35401 = cppVar_35406;
	}
	cppVar_35396 = cppVar_35401;
	}
	cppVar_35391 = cppVar_35396;
	}
	cppVar_35382 = cppVar_35391;
	}
	BIT_VEC cppVar_35497 = cppVar_35382 | ACC;
	cppVar_35376 = cppVar_35497;
	} else {
	cppVar_35376 = P2;
	}
	cppVar_35372 = cppVar_35376;
	} else {
	BIT_VEC cppVar_35498;
	BIT_VEC cppVar_35499 = ROM.rd(PC);
	bool cppVar_35501 = (cppVar_35499 == 213);
	BIT_VEC cppVar_35502 = ROM.rd(PC);
	bool cppVar_35504 = (cppVar_35502 == 21);
	bool cppVar_35505 = cppVar_35501 || cppVar_35504;
	if (cppVar_35505) {
	BIT_VEC cppVar_35506;
	BIT_VEC cppVar_35508 = PC + 1;
	cppVar_35508 = (cppVar_35508 & cppMask_un_16_);
	BIT_VEC cppVar_35509 = ROM.rd(cppVar_35508);
	bool cppVar_35511 = (cppVar_35509 == 160);
	if (cppVar_35511) {
	BIT_VEC cppVar_35512;
	BIT_VEC cppVar_35513 = PC + 1;
	cppVar_35513 = (cppVar_35513 & cppMask_un_16_);
	BIT_VEC cppVar_35514 = ROM.rd(cppVar_35513);
	BIT_VEC cppVar_35515 = (cppVar_35514 >> 7) & cppMask_un_1_;
	bool cppVar_35517 = (cppVar_35515 == 0);
	if (cppVar_35517) {
	BIT_VEC cppVar_35518 = PC + 1;
	cppVar_35518 = (cppVar_35518 & cppMask_un_16_);
	BIT_VEC cppVar_35519 = ROM.rd(cppVar_35518);
	BIT_VEC cppVar_35520 = IRAM.rd(cppVar_35519);
	cppVar_35512 = cppVar_35520;
	} else {
	BIT_VEC cppVar_35521;
	BIT_VEC cppVar_35522 = PC + 1;
	cppVar_35522 = (cppVar_35522 & cppMask_un_16_);
	BIT_VEC cppVar_35523 = ROM.rd(cppVar_35522);
	bool cppVar_35525 = (cppVar_35523 == 128);
	if (cppVar_35525) {
	cppVar_35521 = P0;
	} else {
	BIT_VEC cppVar_35526;
	BIT_VEC cppVar_35527 = PC + 1;
	cppVar_35527 = (cppVar_35527 & cppMask_un_16_);
	BIT_VEC cppVar_35528 = ROM.rd(cppVar_35527);
	bool cppVar_35530 = (cppVar_35528 == 129);
	if (cppVar_35530) {
	cppVar_35526 = SP;
	} else {
	BIT_VEC cppVar_35531;
	BIT_VEC cppVar_35532 = PC + 1;
	cppVar_35532 = (cppVar_35532 & cppMask_un_16_);
	BIT_VEC cppVar_35533 = ROM.rd(cppVar_35532);
	bool cppVar_35535 = (cppVar_35533 == 130);
	if (cppVar_35535) {
	cppVar_35531 = DPL;
	} else {
	BIT_VEC cppVar_35536;
	BIT_VEC cppVar_35537 = PC + 1;
	cppVar_35537 = (cppVar_35537 & cppMask_un_16_);
	BIT_VEC cppVar_35538 = ROM.rd(cppVar_35537);
	bool cppVar_35540 = (cppVar_35538 == 131);
	if (cppVar_35540) {
	cppVar_35536 = DPH;
	} else {
	BIT_VEC cppVar_35541;
	BIT_VEC cppVar_35542 = PC + 1;
	cppVar_35542 = (cppVar_35542 & cppMask_un_16_);
	BIT_VEC cppVar_35543 = ROM.rd(cppVar_35542);
	bool cppVar_35545 = (cppVar_35543 == 135);
	if (cppVar_35545) {
	cppVar_35541 = PCON;
	} else {
	BIT_VEC cppVar_35546;
	BIT_VEC cppVar_35547 = PC + 1;
	cppVar_35547 = (cppVar_35547 & cppMask_un_16_);
	BIT_VEC cppVar_35548 = ROM.rd(cppVar_35547);
	bool cppVar_35550 = (cppVar_35548 == 136);
	if (cppVar_35550) {
	cppVar_35546 = TCON;
	} else {
	BIT_VEC cppVar_35551;
	BIT_VEC cppVar_35552 = PC + 1;
	cppVar_35552 = (cppVar_35552 & cppMask_un_16_);
	BIT_VEC cppVar_35553 = ROM.rd(cppVar_35552);
	bool cppVar_35555 = (cppVar_35553 == 137);
	if (cppVar_35555) {
	cppVar_35551 = TMOD;
	} else {
	BIT_VEC cppVar_35556;
	BIT_VEC cppVar_35557 = PC + 1;
	cppVar_35557 = (cppVar_35557 & cppMask_un_16_);
	BIT_VEC cppVar_35558 = ROM.rd(cppVar_35557);
	bool cppVar_35560 = (cppVar_35558 == 138);
	if (cppVar_35560) {
	cppVar_35556 = TL0;
	} else {
	BIT_VEC cppVar_35561;
	BIT_VEC cppVar_35562 = PC + 1;
	cppVar_35562 = (cppVar_35562 & cppMask_un_16_);
	BIT_VEC cppVar_35563 = ROM.rd(cppVar_35562);
	bool cppVar_35565 = (cppVar_35563 == 140);
	if (cppVar_35565) {
	cppVar_35561 = TH0;
	} else {
	BIT_VEC cppVar_35566;
	BIT_VEC cppVar_35567 = PC + 1;
	cppVar_35567 = (cppVar_35567 & cppMask_un_16_);
	BIT_VEC cppVar_35568 = ROM.rd(cppVar_35567);
	bool cppVar_35570 = (cppVar_35568 == 139);
	if (cppVar_35570) {
	cppVar_35566 = TL1;
	} else {
	BIT_VEC cppVar_35571;
	BIT_VEC cppVar_35572 = PC + 1;
	cppVar_35572 = (cppVar_35572 & cppMask_un_16_);
	BIT_VEC cppVar_35573 = ROM.rd(cppVar_35572);
	bool cppVar_35575 = (cppVar_35573 == 141);
	if (cppVar_35575) {
	cppVar_35571 = TH1;
	} else {
	BIT_VEC cppVar_35576;
	BIT_VEC cppVar_35577 = PC + 1;
	cppVar_35577 = (cppVar_35577 & cppMask_un_16_);
	BIT_VEC cppVar_35578 = ROM.rd(cppVar_35577);
	bool cppVar_35580 = (cppVar_35578 == 144);
	if (cppVar_35580) {
	cppVar_35576 = P1;
	} else {
	BIT_VEC cppVar_35581;
	BIT_VEC cppVar_35582 = PC + 1;
	cppVar_35582 = (cppVar_35582 & cppMask_un_16_);
	BIT_VEC cppVar_35583 = ROM.rd(cppVar_35582);
	bool cppVar_35585 = (cppVar_35583 == 152);
	if (cppVar_35585) {
	cppVar_35581 = SCON;
	} else {
	BIT_VEC cppVar_35586;
	BIT_VEC cppVar_35587 = PC + 1;
	cppVar_35587 = (cppVar_35587 & cppMask_un_16_);
	BIT_VEC cppVar_35588 = ROM.rd(cppVar_35587);
	bool cppVar_35590 = (cppVar_35588 == 153);
	if (cppVar_35590) {
	cppVar_35586 = SBUF;
	} else {
	BIT_VEC cppVar_35591;
	BIT_VEC cppVar_35592 = PC + 1;
	cppVar_35592 = (cppVar_35592 & cppMask_un_16_);
	BIT_VEC cppVar_35593 = ROM.rd(cppVar_35592);
	bool cppVar_35595 = (cppVar_35593 == 160);
	if (cppVar_35595) {
	cppVar_35591 = P2;
	} else {
	BIT_VEC cppVar_35596;
	BIT_VEC cppVar_35597 = PC + 1;
	cppVar_35597 = (cppVar_35597 & cppMask_un_16_);
	BIT_VEC cppVar_35598 = ROM.rd(cppVar_35597);
	bool cppVar_35600 = (cppVar_35598 == 168);
	if (cppVar_35600) {
	cppVar_35596 = IE;
	} else {
	BIT_VEC cppVar_35601;
	BIT_VEC cppVar_35602 = PC + 1;
	cppVar_35602 = (cppVar_35602 & cppMask_un_16_);
	BIT_VEC cppVar_35603 = ROM.rd(cppVar_35602);
	bool cppVar_35605 = (cppVar_35603 == 176);
	if (cppVar_35605) {
	cppVar_35601 = P3;
	} else {
	BIT_VEC cppVar_35606;
	BIT_VEC cppVar_35607 = PC + 1;
	cppVar_35607 = (cppVar_35607 & cppMask_un_16_);
	BIT_VEC cppVar_35608 = ROM.rd(cppVar_35607);
	bool cppVar_35610 = (cppVar_35608 == 184);
	if (cppVar_35610) {
	cppVar_35606 = IP;
	} else {
	BIT_VEC cppVar_35611;
	BIT_VEC cppVar_35612 = PC + 1;
	cppVar_35612 = (cppVar_35612 & cppMask_un_16_);
	BIT_VEC cppVar_35613 = ROM.rd(cppVar_35612);
	bool cppVar_35615 = (cppVar_35613 == 208);
	if (cppVar_35615) {
	cppVar_35611 = PSW;
	} else {
	BIT_VEC cppVar_35616;
	BIT_VEC cppVar_35617 = PC + 1;
	cppVar_35617 = (cppVar_35617 & cppMask_un_16_);
	BIT_VEC cppVar_35618 = ROM.rd(cppVar_35617);
	bool cppVar_35620 = (cppVar_35618 == 224);
	if (cppVar_35620) {
	cppVar_35616 = ACC;
	} else {
	BIT_VEC cppVar_35621;
	BIT_VEC cppVar_35622 = PC + 1;
	cppVar_35622 = (cppVar_35622 & cppMask_un_16_);
	BIT_VEC cppVar_35623 = ROM.rd(cppVar_35622);
	bool cppVar_35625 = (cppVar_35623 == 240);
	if (cppVar_35625) {
	cppVar_35621 = B;
	} else {
	cppVar_35621 = 0;
	}
	cppVar_35616 = cppVar_35621;
	}
	cppVar_35611 = cppVar_35616;
	}
	cppVar_35606 = cppVar_35611;
	}
	cppVar_35601 = cppVar_35606;
	}
	cppVar_35596 = cppVar_35601;
	}
	cppVar_35591 = cppVar_35596;
	}
	cppVar_35586 = cppVar_35591;
	}
	cppVar_35581 = cppVar_35586;
	}
	cppVar_35576 = cppVar_35581;
	}
	cppVar_35571 = cppVar_35576;
	}
	cppVar_35566 = cppVar_35571;
	}
	cppVar_35561 = cppVar_35566;
	}
	cppVar_35556 = cppVar_35561;
	}
	cppVar_35551 = cppVar_35556;
	}
	cppVar_35546 = cppVar_35551;
	}
	cppVar_35541 = cppVar_35546;
	}
	cppVar_35536 = cppVar_35541;
	}
	cppVar_35531 = cppVar_35536;
	}
	cppVar_35526 = cppVar_35531;
	}
	cppVar_35521 = cppVar_35526;
	}
	cppVar_35512 = cppVar_35521;
	}
	BIT_VEC cppVar_35628 = cppVar_35512 - 1;
	cppVar_35628 = (cppVar_35628 & cppMask_un_8_);
	cppVar_35506 = cppVar_35628;
	} else {
	cppVar_35506 = P2;
	}
	cppVar_35498 = cppVar_35506;
	} else {
	BIT_VEC cppVar_35629;
	BIT_VEC cppVar_35630 = ROM.rd(PC);
	bool cppVar_35632 = (cppVar_35630 == 194);
	BIT_VEC cppVar_35633 = ROM.rd(PC);
	bool cppVar_35635 = (cppVar_35633 == 16);
	bool cppVar_35636 = cppVar_35632 || cppVar_35635;
	if (cppVar_35636) {
	BIT_VEC cppVar_35637;
	BIT_VEC cppVar_35638;
	BIT_VEC cppVar_35640 = PC + 1;
	cppVar_35640 = (cppVar_35640 & cppMask_un_16_);
	BIT_VEC cppVar_35641 = ROM.rd(cppVar_35640);
	BIT_VEC cppVar_35642 = (cppVar_35641 >> 7) & cppMask_un_1_;
	bool cppVar_35644 = (cppVar_35642 == 1);
	if (cppVar_35644) {
	BIT_VEC cppVar_35645 = PC + 1;
	cppVar_35645 = (cppVar_35645 & cppMask_un_16_);
	BIT_VEC cppVar_35646 = ROM.rd(cppVar_35645);
	BIT_VEC cppVar_35647 = (cppVar_35646 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_35649 = (cppVar_35647 << 3) | 0;
	cppVar_35649 = (cppVar_35649 & cppMask_un_8_);
	cppVar_35638 = cppVar_35649;
	} else {
	BIT_VEC cppVar_35650 = PC + 1;
	cppVar_35650 = (cppVar_35650 & cppMask_un_16_);
	BIT_VEC cppVar_35651 = ROM.rd(cppVar_35650);
	BIT_VEC cppVar_35652 = (cppVar_35651 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_35653 = (cppVar_35652 & cppMask_un_5_);
	BIT_VEC cppVar_35655 = cppVar_35653 + 32;
	cppVar_35655 = (cppVar_35655 & cppMask_un_8_);
	cppVar_35638 = cppVar_35655;
	}
	bool cppVar_35657 = (cppVar_35638 == 160);
	if (cppVar_35657) {
	BIT_VEC cppVar_35659 = PC + 1;
	cppVar_35659 = (cppVar_35659 & cppMask_un_16_);
	BIT_VEC cppVar_35660 = ROM.rd(cppVar_35659);
	BIT_VEC cppVar_35661 = (cppVar_35660 >> 0) & cppMask_un_3_;
	BIT_VEC cppVar_35662 = (cppVar_35661 & cppMask_un_3_);
	BIT_VEC cppVar_35663 = 1 << static_cast<unsigned>(cppVar_35662);
	cppVar_35663 = (cppVar_35663 & cppMask_un_8_);
	BIT_VEC cppVar_35664 = ~cppVar_35663;
	BIT_VEC cppVar_35665;
	BIT_VEC cppVar_35666;
	BIT_VEC cppVar_35667 = PC + 1;
	cppVar_35667 = (cppVar_35667 & cppMask_un_16_);
	BIT_VEC cppVar_35668 = ROM.rd(cppVar_35667);
	BIT_VEC cppVar_35669 = (cppVar_35668 >> 7) & cppMask_un_1_;
	bool cppVar_35670 = (cppVar_35669 == 1);
	if (cppVar_35670) {
	BIT_VEC cppVar_35671 = PC + 1;
	cppVar_35671 = (cppVar_35671 & cppMask_un_16_);
	BIT_VEC cppVar_35672 = ROM.rd(cppVar_35671);
	BIT_VEC cppVar_35673 = (cppVar_35672 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_35674 = (cppVar_35673 << 3) | 0;
	cppVar_35674 = (cppVar_35674 & cppMask_un_8_);
	cppVar_35666 = cppVar_35674;
	} else {
	BIT_VEC cppVar_35675 = PC + 1;
	cppVar_35675 = (cppVar_35675 & cppMask_un_16_);
	BIT_VEC cppVar_35676 = ROM.rd(cppVar_35675);
	BIT_VEC cppVar_35677 = (cppVar_35676 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_35678 = (cppVar_35677 & cppMask_un_5_);
	BIT_VEC cppVar_35679 = cppVar_35678 + 32;
	cppVar_35679 = (cppVar_35679 & cppMask_un_8_);
	cppVar_35666 = cppVar_35679;
	}
	BIT_VEC cppVar_35680 = (cppVar_35666 >> 7) & cppMask_un_1_;
	bool cppVar_35682 = (cppVar_35680 == 0);
	if (cppVar_35682) {
	BIT_VEC cppVar_35683;
	BIT_VEC cppVar_35684 = PC + 1;
	cppVar_35684 = (cppVar_35684 & cppMask_un_16_);
	BIT_VEC cppVar_35685 = ROM.rd(cppVar_35684);
	BIT_VEC cppVar_35686 = (cppVar_35685 >> 7) & cppMask_un_1_;
	bool cppVar_35687 = (cppVar_35686 == 1);
	if (cppVar_35687) {
	BIT_VEC cppVar_35688 = PC + 1;
	cppVar_35688 = (cppVar_35688 & cppMask_un_16_);
	BIT_VEC cppVar_35689 = ROM.rd(cppVar_35688);
	BIT_VEC cppVar_35690 = (cppVar_35689 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_35691 = (cppVar_35690 << 3) | 0;
	cppVar_35691 = (cppVar_35691 & cppMask_un_8_);
	cppVar_35683 = cppVar_35691;
	} else {
	BIT_VEC cppVar_35692 = PC + 1;
	cppVar_35692 = (cppVar_35692 & cppMask_un_16_);
	BIT_VEC cppVar_35693 = ROM.rd(cppVar_35692);
	BIT_VEC cppVar_35694 = (cppVar_35693 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_35695 = (cppVar_35694 & cppMask_un_5_);
	BIT_VEC cppVar_35696 = cppVar_35695 + 32;
	cppVar_35696 = (cppVar_35696 & cppMask_un_8_);
	cppVar_35683 = cppVar_35696;
	}
	BIT_VEC cppVar_35697 = IRAM.rd(cppVar_35683);
	cppVar_35665 = cppVar_35697;
	} else {
	BIT_VEC cppVar_35698;
	BIT_VEC cppVar_35699;
	BIT_VEC cppVar_35700 = PC + 1;
	cppVar_35700 = (cppVar_35700 & cppMask_un_16_);
	BIT_VEC cppVar_35701 = ROM.rd(cppVar_35700);
	BIT_VEC cppVar_35702 = (cppVar_35701 >> 7) & cppMask_un_1_;
	bool cppVar_35703 = (cppVar_35702 == 1);
	if (cppVar_35703) {
	BIT_VEC cppVar_35704 = PC + 1;
	cppVar_35704 = (cppVar_35704 & cppMask_un_16_);
	BIT_VEC cppVar_35705 = ROM.rd(cppVar_35704);
	BIT_VEC cppVar_35706 = (cppVar_35705 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_35707 = (cppVar_35706 << 3) | 0;
	cppVar_35707 = (cppVar_35707 & cppMask_un_8_);
	cppVar_35699 = cppVar_35707;
	} else {
	BIT_VEC cppVar_35708 = PC + 1;
	cppVar_35708 = (cppVar_35708 & cppMask_un_16_);
	BIT_VEC cppVar_35709 = ROM.rd(cppVar_35708);
	BIT_VEC cppVar_35710 = (cppVar_35709 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_35711 = (cppVar_35710 & cppMask_un_5_);
	BIT_VEC cppVar_35712 = cppVar_35711 + 32;
	cppVar_35712 = (cppVar_35712 & cppMask_un_8_);
	cppVar_35699 = cppVar_35712;
	}
	bool cppVar_35714 = (cppVar_35699 == 128);
	if (cppVar_35714) {
	cppVar_35698 = P0;
	} else {
	BIT_VEC cppVar_35715;
	BIT_VEC cppVar_35716;
	BIT_VEC cppVar_35717 = PC + 1;
	cppVar_35717 = (cppVar_35717 & cppMask_un_16_);
	BIT_VEC cppVar_35718 = ROM.rd(cppVar_35717);
	BIT_VEC cppVar_35719 = (cppVar_35718 >> 7) & cppMask_un_1_;
	bool cppVar_35720 = (cppVar_35719 == 1);
	if (cppVar_35720) {
	BIT_VEC cppVar_35721 = PC + 1;
	cppVar_35721 = (cppVar_35721 & cppMask_un_16_);
	BIT_VEC cppVar_35722 = ROM.rd(cppVar_35721);
	BIT_VEC cppVar_35723 = (cppVar_35722 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_35724 = (cppVar_35723 << 3) | 0;
	cppVar_35724 = (cppVar_35724 & cppMask_un_8_);
	cppVar_35716 = cppVar_35724;
	} else {
	BIT_VEC cppVar_35725 = PC + 1;
	cppVar_35725 = (cppVar_35725 & cppMask_un_16_);
	BIT_VEC cppVar_35726 = ROM.rd(cppVar_35725);
	BIT_VEC cppVar_35727 = (cppVar_35726 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_35728 = (cppVar_35727 & cppMask_un_5_);
	BIT_VEC cppVar_35729 = cppVar_35728 + 32;
	cppVar_35729 = (cppVar_35729 & cppMask_un_8_);
	cppVar_35716 = cppVar_35729;
	}
	bool cppVar_35731 = (cppVar_35716 == 129);
	if (cppVar_35731) {
	cppVar_35715 = SP;
	} else {
	BIT_VEC cppVar_35732;
	BIT_VEC cppVar_35733;
	BIT_VEC cppVar_35734 = PC + 1;
	cppVar_35734 = (cppVar_35734 & cppMask_un_16_);
	BIT_VEC cppVar_35735 = ROM.rd(cppVar_35734);
	BIT_VEC cppVar_35736 = (cppVar_35735 >> 7) & cppMask_un_1_;
	bool cppVar_35737 = (cppVar_35736 == 1);
	if (cppVar_35737) {
	BIT_VEC cppVar_35738 = PC + 1;
	cppVar_35738 = (cppVar_35738 & cppMask_un_16_);
	BIT_VEC cppVar_35739 = ROM.rd(cppVar_35738);
	BIT_VEC cppVar_35740 = (cppVar_35739 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_35741 = (cppVar_35740 << 3) | 0;
	cppVar_35741 = (cppVar_35741 & cppMask_un_8_);
	cppVar_35733 = cppVar_35741;
	} else {
	BIT_VEC cppVar_35742 = PC + 1;
	cppVar_35742 = (cppVar_35742 & cppMask_un_16_);
	BIT_VEC cppVar_35743 = ROM.rd(cppVar_35742);
	BIT_VEC cppVar_35744 = (cppVar_35743 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_35745 = (cppVar_35744 & cppMask_un_5_);
	BIT_VEC cppVar_35746 = cppVar_35745 + 32;
	cppVar_35746 = (cppVar_35746 & cppMask_un_8_);
	cppVar_35733 = cppVar_35746;
	}
	bool cppVar_35748 = (cppVar_35733 == 130);
	if (cppVar_35748) {
	cppVar_35732 = DPL;
	} else {
	BIT_VEC cppVar_35749;
	BIT_VEC cppVar_35750;
	BIT_VEC cppVar_35751 = PC + 1;
	cppVar_35751 = (cppVar_35751 & cppMask_un_16_);
	BIT_VEC cppVar_35752 = ROM.rd(cppVar_35751);
	BIT_VEC cppVar_35753 = (cppVar_35752 >> 7) & cppMask_un_1_;
	bool cppVar_35754 = (cppVar_35753 == 1);
	if (cppVar_35754) {
	BIT_VEC cppVar_35755 = PC + 1;
	cppVar_35755 = (cppVar_35755 & cppMask_un_16_);
	BIT_VEC cppVar_35756 = ROM.rd(cppVar_35755);
	BIT_VEC cppVar_35757 = (cppVar_35756 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_35758 = (cppVar_35757 << 3) | 0;
	cppVar_35758 = (cppVar_35758 & cppMask_un_8_);
	cppVar_35750 = cppVar_35758;
	} else {
	BIT_VEC cppVar_35759 = PC + 1;
	cppVar_35759 = (cppVar_35759 & cppMask_un_16_);
	BIT_VEC cppVar_35760 = ROM.rd(cppVar_35759);
	BIT_VEC cppVar_35761 = (cppVar_35760 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_35762 = (cppVar_35761 & cppMask_un_5_);
	BIT_VEC cppVar_35763 = cppVar_35762 + 32;
	cppVar_35763 = (cppVar_35763 & cppMask_un_8_);
	cppVar_35750 = cppVar_35763;
	}
	bool cppVar_35765 = (cppVar_35750 == 131);
	if (cppVar_35765) {
	cppVar_35749 = DPH;
	} else {
	BIT_VEC cppVar_35766;
	BIT_VEC cppVar_35767;
	BIT_VEC cppVar_35768 = PC + 1;
	cppVar_35768 = (cppVar_35768 & cppMask_un_16_);
	BIT_VEC cppVar_35769 = ROM.rd(cppVar_35768);
	BIT_VEC cppVar_35770 = (cppVar_35769 >> 7) & cppMask_un_1_;
	bool cppVar_35771 = (cppVar_35770 == 1);
	if (cppVar_35771) {
	BIT_VEC cppVar_35772 = PC + 1;
	cppVar_35772 = (cppVar_35772 & cppMask_un_16_);
	BIT_VEC cppVar_35773 = ROM.rd(cppVar_35772);
	BIT_VEC cppVar_35774 = (cppVar_35773 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_35775 = (cppVar_35774 << 3) | 0;
	cppVar_35775 = (cppVar_35775 & cppMask_un_8_);
	cppVar_35767 = cppVar_35775;
	} else {
	BIT_VEC cppVar_35776 = PC + 1;
	cppVar_35776 = (cppVar_35776 & cppMask_un_16_);
	BIT_VEC cppVar_35777 = ROM.rd(cppVar_35776);
	BIT_VEC cppVar_35778 = (cppVar_35777 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_35779 = (cppVar_35778 & cppMask_un_5_);
	BIT_VEC cppVar_35780 = cppVar_35779 + 32;
	cppVar_35780 = (cppVar_35780 & cppMask_un_8_);
	cppVar_35767 = cppVar_35780;
	}
	bool cppVar_35782 = (cppVar_35767 == 135);
	if (cppVar_35782) {
	cppVar_35766 = PCON;
	} else {
	BIT_VEC cppVar_35783;
	BIT_VEC cppVar_35784;
	BIT_VEC cppVar_35785 = PC + 1;
	cppVar_35785 = (cppVar_35785 & cppMask_un_16_);
	BIT_VEC cppVar_35786 = ROM.rd(cppVar_35785);
	BIT_VEC cppVar_35787 = (cppVar_35786 >> 7) & cppMask_un_1_;
	bool cppVar_35788 = (cppVar_35787 == 1);
	if (cppVar_35788) {
	BIT_VEC cppVar_35789 = PC + 1;
	cppVar_35789 = (cppVar_35789 & cppMask_un_16_);
	BIT_VEC cppVar_35790 = ROM.rd(cppVar_35789);
	BIT_VEC cppVar_35791 = (cppVar_35790 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_35792 = (cppVar_35791 << 3) | 0;
	cppVar_35792 = (cppVar_35792 & cppMask_un_8_);
	cppVar_35784 = cppVar_35792;
	} else {
	BIT_VEC cppVar_35793 = PC + 1;
	cppVar_35793 = (cppVar_35793 & cppMask_un_16_);
	BIT_VEC cppVar_35794 = ROM.rd(cppVar_35793);
	BIT_VEC cppVar_35795 = (cppVar_35794 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_35796 = (cppVar_35795 & cppMask_un_5_);
	BIT_VEC cppVar_35797 = cppVar_35796 + 32;
	cppVar_35797 = (cppVar_35797 & cppMask_un_8_);
	cppVar_35784 = cppVar_35797;
	}
	bool cppVar_35799 = (cppVar_35784 == 136);
	if (cppVar_35799) {
	cppVar_35783 = TCON;
	} else {
	BIT_VEC cppVar_35800;
	BIT_VEC cppVar_35801;
	BIT_VEC cppVar_35802 = PC + 1;
	cppVar_35802 = (cppVar_35802 & cppMask_un_16_);
	BIT_VEC cppVar_35803 = ROM.rd(cppVar_35802);
	BIT_VEC cppVar_35804 = (cppVar_35803 >> 7) & cppMask_un_1_;
	bool cppVar_35805 = (cppVar_35804 == 1);
	if (cppVar_35805) {
	BIT_VEC cppVar_35806 = PC + 1;
	cppVar_35806 = (cppVar_35806 & cppMask_un_16_);
	BIT_VEC cppVar_35807 = ROM.rd(cppVar_35806);
	BIT_VEC cppVar_35808 = (cppVar_35807 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_35809 = (cppVar_35808 << 3) | 0;
	cppVar_35809 = (cppVar_35809 & cppMask_un_8_);
	cppVar_35801 = cppVar_35809;
	} else {
	BIT_VEC cppVar_35810 = PC + 1;
	cppVar_35810 = (cppVar_35810 & cppMask_un_16_);
	BIT_VEC cppVar_35811 = ROM.rd(cppVar_35810);
	BIT_VEC cppVar_35812 = (cppVar_35811 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_35813 = (cppVar_35812 & cppMask_un_5_);
	BIT_VEC cppVar_35814 = cppVar_35813 + 32;
	cppVar_35814 = (cppVar_35814 & cppMask_un_8_);
	cppVar_35801 = cppVar_35814;
	}
	bool cppVar_35816 = (cppVar_35801 == 137);
	if (cppVar_35816) {
	cppVar_35800 = TMOD;
	} else {
	BIT_VEC cppVar_35817;
	BIT_VEC cppVar_35818;
	BIT_VEC cppVar_35819 = PC + 1;
	cppVar_35819 = (cppVar_35819 & cppMask_un_16_);
	BIT_VEC cppVar_35820 = ROM.rd(cppVar_35819);
	BIT_VEC cppVar_35821 = (cppVar_35820 >> 7) & cppMask_un_1_;
	bool cppVar_35822 = (cppVar_35821 == 1);
	if (cppVar_35822) {
	BIT_VEC cppVar_35823 = PC + 1;
	cppVar_35823 = (cppVar_35823 & cppMask_un_16_);
	BIT_VEC cppVar_35824 = ROM.rd(cppVar_35823);
	BIT_VEC cppVar_35825 = (cppVar_35824 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_35826 = (cppVar_35825 << 3) | 0;
	cppVar_35826 = (cppVar_35826 & cppMask_un_8_);
	cppVar_35818 = cppVar_35826;
	} else {
	BIT_VEC cppVar_35827 = PC + 1;
	cppVar_35827 = (cppVar_35827 & cppMask_un_16_);
	BIT_VEC cppVar_35828 = ROM.rd(cppVar_35827);
	BIT_VEC cppVar_35829 = (cppVar_35828 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_35830 = (cppVar_35829 & cppMask_un_5_);
	BIT_VEC cppVar_35831 = cppVar_35830 + 32;
	cppVar_35831 = (cppVar_35831 & cppMask_un_8_);
	cppVar_35818 = cppVar_35831;
	}
	bool cppVar_35833 = (cppVar_35818 == 138);
	if (cppVar_35833) {
	cppVar_35817 = TL0;
	} else {
	BIT_VEC cppVar_35834;
	BIT_VEC cppVar_35835;
	BIT_VEC cppVar_35836 = PC + 1;
	cppVar_35836 = (cppVar_35836 & cppMask_un_16_);
	BIT_VEC cppVar_35837 = ROM.rd(cppVar_35836);
	BIT_VEC cppVar_35838 = (cppVar_35837 >> 7) & cppMask_un_1_;
	bool cppVar_35839 = (cppVar_35838 == 1);
	if (cppVar_35839) {
	BIT_VEC cppVar_35840 = PC + 1;
	cppVar_35840 = (cppVar_35840 & cppMask_un_16_);
	BIT_VEC cppVar_35841 = ROM.rd(cppVar_35840);
	BIT_VEC cppVar_35842 = (cppVar_35841 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_35843 = (cppVar_35842 << 3) | 0;
	cppVar_35843 = (cppVar_35843 & cppMask_un_8_);
	cppVar_35835 = cppVar_35843;
	} else {
	BIT_VEC cppVar_35844 = PC + 1;
	cppVar_35844 = (cppVar_35844 & cppMask_un_16_);
	BIT_VEC cppVar_35845 = ROM.rd(cppVar_35844);
	BIT_VEC cppVar_35846 = (cppVar_35845 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_35847 = (cppVar_35846 & cppMask_un_5_);
	BIT_VEC cppVar_35848 = cppVar_35847 + 32;
	cppVar_35848 = (cppVar_35848 & cppMask_un_8_);
	cppVar_35835 = cppVar_35848;
	}
	bool cppVar_35850 = (cppVar_35835 == 140);
	if (cppVar_35850) {
	cppVar_35834 = TH0;
	} else {
	BIT_VEC cppVar_35851;
	BIT_VEC cppVar_35852;
	BIT_VEC cppVar_35853 = PC + 1;
	cppVar_35853 = (cppVar_35853 & cppMask_un_16_);
	BIT_VEC cppVar_35854 = ROM.rd(cppVar_35853);
	BIT_VEC cppVar_35855 = (cppVar_35854 >> 7) & cppMask_un_1_;
	bool cppVar_35856 = (cppVar_35855 == 1);
	if (cppVar_35856) {
	BIT_VEC cppVar_35857 = PC + 1;
	cppVar_35857 = (cppVar_35857 & cppMask_un_16_);
	BIT_VEC cppVar_35858 = ROM.rd(cppVar_35857);
	BIT_VEC cppVar_35859 = (cppVar_35858 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_35860 = (cppVar_35859 << 3) | 0;
	cppVar_35860 = (cppVar_35860 & cppMask_un_8_);
	cppVar_35852 = cppVar_35860;
	} else {
	BIT_VEC cppVar_35861 = PC + 1;
	cppVar_35861 = (cppVar_35861 & cppMask_un_16_);
	BIT_VEC cppVar_35862 = ROM.rd(cppVar_35861);
	BIT_VEC cppVar_35863 = (cppVar_35862 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_35864 = (cppVar_35863 & cppMask_un_5_);
	BIT_VEC cppVar_35865 = cppVar_35864 + 32;
	cppVar_35865 = (cppVar_35865 & cppMask_un_8_);
	cppVar_35852 = cppVar_35865;
	}
	bool cppVar_35867 = (cppVar_35852 == 139);
	if (cppVar_35867) {
	cppVar_35851 = TL1;
	} else {
	BIT_VEC cppVar_35868;
	BIT_VEC cppVar_35869;
	BIT_VEC cppVar_35870 = PC + 1;
	cppVar_35870 = (cppVar_35870 & cppMask_un_16_);
	BIT_VEC cppVar_35871 = ROM.rd(cppVar_35870);
	BIT_VEC cppVar_35872 = (cppVar_35871 >> 7) & cppMask_un_1_;
	bool cppVar_35873 = (cppVar_35872 == 1);
	if (cppVar_35873) {
	BIT_VEC cppVar_35874 = PC + 1;
	cppVar_35874 = (cppVar_35874 & cppMask_un_16_);
	BIT_VEC cppVar_35875 = ROM.rd(cppVar_35874);
	BIT_VEC cppVar_35876 = (cppVar_35875 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_35877 = (cppVar_35876 << 3) | 0;
	cppVar_35877 = (cppVar_35877 & cppMask_un_8_);
	cppVar_35869 = cppVar_35877;
	} else {
	BIT_VEC cppVar_35878 = PC + 1;
	cppVar_35878 = (cppVar_35878 & cppMask_un_16_);
	BIT_VEC cppVar_35879 = ROM.rd(cppVar_35878);
	BIT_VEC cppVar_35880 = (cppVar_35879 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_35881 = (cppVar_35880 & cppMask_un_5_);
	BIT_VEC cppVar_35882 = cppVar_35881 + 32;
	cppVar_35882 = (cppVar_35882 & cppMask_un_8_);
	cppVar_35869 = cppVar_35882;
	}
	bool cppVar_35884 = (cppVar_35869 == 141);
	if (cppVar_35884) {
	cppVar_35868 = TH1;
	} else {
	BIT_VEC cppVar_35885;
	BIT_VEC cppVar_35886;
	BIT_VEC cppVar_35887 = PC + 1;
	cppVar_35887 = (cppVar_35887 & cppMask_un_16_);
	BIT_VEC cppVar_35888 = ROM.rd(cppVar_35887);
	BIT_VEC cppVar_35889 = (cppVar_35888 >> 7) & cppMask_un_1_;
	bool cppVar_35890 = (cppVar_35889 == 1);
	if (cppVar_35890) {
	BIT_VEC cppVar_35891 = PC + 1;
	cppVar_35891 = (cppVar_35891 & cppMask_un_16_);
	BIT_VEC cppVar_35892 = ROM.rd(cppVar_35891);
	BIT_VEC cppVar_35893 = (cppVar_35892 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_35894 = (cppVar_35893 << 3) | 0;
	cppVar_35894 = (cppVar_35894 & cppMask_un_8_);
	cppVar_35886 = cppVar_35894;
	} else {
	BIT_VEC cppVar_35895 = PC + 1;
	cppVar_35895 = (cppVar_35895 & cppMask_un_16_);
	BIT_VEC cppVar_35896 = ROM.rd(cppVar_35895);
	BIT_VEC cppVar_35897 = (cppVar_35896 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_35898 = (cppVar_35897 & cppMask_un_5_);
	BIT_VEC cppVar_35899 = cppVar_35898 + 32;
	cppVar_35899 = (cppVar_35899 & cppMask_un_8_);
	cppVar_35886 = cppVar_35899;
	}
	bool cppVar_35901 = (cppVar_35886 == 144);
	if (cppVar_35901) {
	cppVar_35885 = P1;
	} else {
	BIT_VEC cppVar_35902;
	BIT_VEC cppVar_35903;
	BIT_VEC cppVar_35904 = PC + 1;
	cppVar_35904 = (cppVar_35904 & cppMask_un_16_);
	BIT_VEC cppVar_35905 = ROM.rd(cppVar_35904);
	BIT_VEC cppVar_35906 = (cppVar_35905 >> 7) & cppMask_un_1_;
	bool cppVar_35907 = (cppVar_35906 == 1);
	if (cppVar_35907) {
	BIT_VEC cppVar_35908 = PC + 1;
	cppVar_35908 = (cppVar_35908 & cppMask_un_16_);
	BIT_VEC cppVar_35909 = ROM.rd(cppVar_35908);
	BIT_VEC cppVar_35910 = (cppVar_35909 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_35911 = (cppVar_35910 << 3) | 0;
	cppVar_35911 = (cppVar_35911 & cppMask_un_8_);
	cppVar_35903 = cppVar_35911;
	} else {
	BIT_VEC cppVar_35912 = PC + 1;
	cppVar_35912 = (cppVar_35912 & cppMask_un_16_);
	BIT_VEC cppVar_35913 = ROM.rd(cppVar_35912);
	BIT_VEC cppVar_35914 = (cppVar_35913 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_35915 = (cppVar_35914 & cppMask_un_5_);
	BIT_VEC cppVar_35916 = cppVar_35915 + 32;
	cppVar_35916 = (cppVar_35916 & cppMask_un_8_);
	cppVar_35903 = cppVar_35916;
	}
	bool cppVar_35918 = (cppVar_35903 == 152);
	if (cppVar_35918) {
	cppVar_35902 = SCON;
	} else {
	BIT_VEC cppVar_35919;
	BIT_VEC cppVar_35920;
	BIT_VEC cppVar_35921 = PC + 1;
	cppVar_35921 = (cppVar_35921 & cppMask_un_16_);
	BIT_VEC cppVar_35922 = ROM.rd(cppVar_35921);
	BIT_VEC cppVar_35923 = (cppVar_35922 >> 7) & cppMask_un_1_;
	bool cppVar_35924 = (cppVar_35923 == 1);
	if (cppVar_35924) {
	BIT_VEC cppVar_35925 = PC + 1;
	cppVar_35925 = (cppVar_35925 & cppMask_un_16_);
	BIT_VEC cppVar_35926 = ROM.rd(cppVar_35925);
	BIT_VEC cppVar_35927 = (cppVar_35926 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_35928 = (cppVar_35927 << 3) | 0;
	cppVar_35928 = (cppVar_35928 & cppMask_un_8_);
	cppVar_35920 = cppVar_35928;
	} else {
	BIT_VEC cppVar_35929 = PC + 1;
	cppVar_35929 = (cppVar_35929 & cppMask_un_16_);
	BIT_VEC cppVar_35930 = ROM.rd(cppVar_35929);
	BIT_VEC cppVar_35931 = (cppVar_35930 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_35932 = (cppVar_35931 & cppMask_un_5_);
	BIT_VEC cppVar_35933 = cppVar_35932 + 32;
	cppVar_35933 = (cppVar_35933 & cppMask_un_8_);
	cppVar_35920 = cppVar_35933;
	}
	bool cppVar_35935 = (cppVar_35920 == 153);
	if (cppVar_35935) {
	cppVar_35919 = SBUF;
	} else {
	BIT_VEC cppVar_35936;
	BIT_VEC cppVar_35937;
	BIT_VEC cppVar_35938 = PC + 1;
	cppVar_35938 = (cppVar_35938 & cppMask_un_16_);
	BIT_VEC cppVar_35939 = ROM.rd(cppVar_35938);
	BIT_VEC cppVar_35940 = (cppVar_35939 >> 7) & cppMask_un_1_;
	bool cppVar_35941 = (cppVar_35940 == 1);
	if (cppVar_35941) {
	BIT_VEC cppVar_35942 = PC + 1;
	cppVar_35942 = (cppVar_35942 & cppMask_un_16_);
	BIT_VEC cppVar_35943 = ROM.rd(cppVar_35942);
	BIT_VEC cppVar_35944 = (cppVar_35943 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_35945 = (cppVar_35944 << 3) | 0;
	cppVar_35945 = (cppVar_35945 & cppMask_un_8_);
	cppVar_35937 = cppVar_35945;
	} else {
	BIT_VEC cppVar_35946 = PC + 1;
	cppVar_35946 = (cppVar_35946 & cppMask_un_16_);
	BIT_VEC cppVar_35947 = ROM.rd(cppVar_35946);
	BIT_VEC cppVar_35948 = (cppVar_35947 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_35949 = (cppVar_35948 & cppMask_un_5_);
	BIT_VEC cppVar_35950 = cppVar_35949 + 32;
	cppVar_35950 = (cppVar_35950 & cppMask_un_8_);
	cppVar_35937 = cppVar_35950;
	}
	bool cppVar_35952 = (cppVar_35937 == 160);
	if (cppVar_35952) {
	cppVar_35936 = P2;
	} else {
	BIT_VEC cppVar_35953;
	BIT_VEC cppVar_35954;
	BIT_VEC cppVar_35955 = PC + 1;
	cppVar_35955 = (cppVar_35955 & cppMask_un_16_);
	BIT_VEC cppVar_35956 = ROM.rd(cppVar_35955);
	BIT_VEC cppVar_35957 = (cppVar_35956 >> 7) & cppMask_un_1_;
	bool cppVar_35958 = (cppVar_35957 == 1);
	if (cppVar_35958) {
	BIT_VEC cppVar_35959 = PC + 1;
	cppVar_35959 = (cppVar_35959 & cppMask_un_16_);
	BIT_VEC cppVar_35960 = ROM.rd(cppVar_35959);
	BIT_VEC cppVar_35961 = (cppVar_35960 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_35962 = (cppVar_35961 << 3) | 0;
	cppVar_35962 = (cppVar_35962 & cppMask_un_8_);
	cppVar_35954 = cppVar_35962;
	} else {
	BIT_VEC cppVar_35963 = PC + 1;
	cppVar_35963 = (cppVar_35963 & cppMask_un_16_);
	BIT_VEC cppVar_35964 = ROM.rd(cppVar_35963);
	BIT_VEC cppVar_35965 = (cppVar_35964 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_35966 = (cppVar_35965 & cppMask_un_5_);
	BIT_VEC cppVar_35967 = cppVar_35966 + 32;
	cppVar_35967 = (cppVar_35967 & cppMask_un_8_);
	cppVar_35954 = cppVar_35967;
	}
	bool cppVar_35969 = (cppVar_35954 == 168);
	if (cppVar_35969) {
	cppVar_35953 = IE;
	} else {
	BIT_VEC cppVar_35970;
	BIT_VEC cppVar_35971;
	BIT_VEC cppVar_35972 = PC + 1;
	cppVar_35972 = (cppVar_35972 & cppMask_un_16_);
	BIT_VEC cppVar_35973 = ROM.rd(cppVar_35972);
	BIT_VEC cppVar_35974 = (cppVar_35973 >> 7) & cppMask_un_1_;
	bool cppVar_35975 = (cppVar_35974 == 1);
	if (cppVar_35975) {
	BIT_VEC cppVar_35976 = PC + 1;
	cppVar_35976 = (cppVar_35976 & cppMask_un_16_);
	BIT_VEC cppVar_35977 = ROM.rd(cppVar_35976);
	BIT_VEC cppVar_35978 = (cppVar_35977 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_35979 = (cppVar_35978 << 3) | 0;
	cppVar_35979 = (cppVar_35979 & cppMask_un_8_);
	cppVar_35971 = cppVar_35979;
	} else {
	BIT_VEC cppVar_35980 = PC + 1;
	cppVar_35980 = (cppVar_35980 & cppMask_un_16_);
	BIT_VEC cppVar_35981 = ROM.rd(cppVar_35980);
	BIT_VEC cppVar_35982 = (cppVar_35981 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_35983 = (cppVar_35982 & cppMask_un_5_);
	BIT_VEC cppVar_35984 = cppVar_35983 + 32;
	cppVar_35984 = (cppVar_35984 & cppMask_un_8_);
	cppVar_35971 = cppVar_35984;
	}
	bool cppVar_35986 = (cppVar_35971 == 176);
	if (cppVar_35986) {
	cppVar_35970 = P3;
	} else {
	BIT_VEC cppVar_35987;
	BIT_VEC cppVar_35988;
	BIT_VEC cppVar_35989 = PC + 1;
	cppVar_35989 = (cppVar_35989 & cppMask_un_16_);
	BIT_VEC cppVar_35990 = ROM.rd(cppVar_35989);
	BIT_VEC cppVar_35991 = (cppVar_35990 >> 7) & cppMask_un_1_;
	bool cppVar_35992 = (cppVar_35991 == 1);
	if (cppVar_35992) {
	BIT_VEC cppVar_35993 = PC + 1;
	cppVar_35993 = (cppVar_35993 & cppMask_un_16_);
	BIT_VEC cppVar_35994 = ROM.rd(cppVar_35993);
	BIT_VEC cppVar_35995 = (cppVar_35994 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_35996 = (cppVar_35995 << 3) | 0;
	cppVar_35996 = (cppVar_35996 & cppMask_un_8_);
	cppVar_35988 = cppVar_35996;
	} else {
	BIT_VEC cppVar_35997 = PC + 1;
	cppVar_35997 = (cppVar_35997 & cppMask_un_16_);
	BIT_VEC cppVar_35998 = ROM.rd(cppVar_35997);
	BIT_VEC cppVar_35999 = (cppVar_35998 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_36000 = (cppVar_35999 & cppMask_un_5_);
	BIT_VEC cppVar_36001 = cppVar_36000 + 32;
	cppVar_36001 = (cppVar_36001 & cppMask_un_8_);
	cppVar_35988 = cppVar_36001;
	}
	bool cppVar_36003 = (cppVar_35988 == 184);
	if (cppVar_36003) {
	cppVar_35987 = IP;
	} else {
	BIT_VEC cppVar_36004;
	BIT_VEC cppVar_36005;
	BIT_VEC cppVar_36006 = PC + 1;
	cppVar_36006 = (cppVar_36006 & cppMask_un_16_);
	BIT_VEC cppVar_36007 = ROM.rd(cppVar_36006);
	BIT_VEC cppVar_36008 = (cppVar_36007 >> 7) & cppMask_un_1_;
	bool cppVar_36009 = (cppVar_36008 == 1);
	if (cppVar_36009) {
	BIT_VEC cppVar_36010 = PC + 1;
	cppVar_36010 = (cppVar_36010 & cppMask_un_16_);
	BIT_VEC cppVar_36011 = ROM.rd(cppVar_36010);
	BIT_VEC cppVar_36012 = (cppVar_36011 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_36013 = (cppVar_36012 << 3) | 0;
	cppVar_36013 = (cppVar_36013 & cppMask_un_8_);
	cppVar_36005 = cppVar_36013;
	} else {
	BIT_VEC cppVar_36014 = PC + 1;
	cppVar_36014 = (cppVar_36014 & cppMask_un_16_);
	BIT_VEC cppVar_36015 = ROM.rd(cppVar_36014);
	BIT_VEC cppVar_36016 = (cppVar_36015 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_36017 = (cppVar_36016 & cppMask_un_5_);
	BIT_VEC cppVar_36018 = cppVar_36017 + 32;
	cppVar_36018 = (cppVar_36018 & cppMask_un_8_);
	cppVar_36005 = cppVar_36018;
	}
	bool cppVar_36020 = (cppVar_36005 == 208);
	if (cppVar_36020) {
	cppVar_36004 = PSW;
	} else {
	BIT_VEC cppVar_36021;
	BIT_VEC cppVar_36022;
	BIT_VEC cppVar_36023 = PC + 1;
	cppVar_36023 = (cppVar_36023 & cppMask_un_16_);
	BIT_VEC cppVar_36024 = ROM.rd(cppVar_36023);
	BIT_VEC cppVar_36025 = (cppVar_36024 >> 7) & cppMask_un_1_;
	bool cppVar_36026 = (cppVar_36025 == 1);
	if (cppVar_36026) {
	BIT_VEC cppVar_36027 = PC + 1;
	cppVar_36027 = (cppVar_36027 & cppMask_un_16_);
	BIT_VEC cppVar_36028 = ROM.rd(cppVar_36027);
	BIT_VEC cppVar_36029 = (cppVar_36028 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_36030 = (cppVar_36029 << 3) | 0;
	cppVar_36030 = (cppVar_36030 & cppMask_un_8_);
	cppVar_36022 = cppVar_36030;
	} else {
	BIT_VEC cppVar_36031 = PC + 1;
	cppVar_36031 = (cppVar_36031 & cppMask_un_16_);
	BIT_VEC cppVar_36032 = ROM.rd(cppVar_36031);
	BIT_VEC cppVar_36033 = (cppVar_36032 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_36034 = (cppVar_36033 & cppMask_un_5_);
	BIT_VEC cppVar_36035 = cppVar_36034 + 32;
	cppVar_36035 = (cppVar_36035 & cppMask_un_8_);
	cppVar_36022 = cppVar_36035;
	}
	bool cppVar_36037 = (cppVar_36022 == 224);
	if (cppVar_36037) {
	cppVar_36021 = ACC;
	} else {
	BIT_VEC cppVar_36038;
	BIT_VEC cppVar_36039;
	BIT_VEC cppVar_36040 = PC + 1;
	cppVar_36040 = (cppVar_36040 & cppMask_un_16_);
	BIT_VEC cppVar_36041 = ROM.rd(cppVar_36040);
	BIT_VEC cppVar_36042 = (cppVar_36041 >> 7) & cppMask_un_1_;
	bool cppVar_36043 = (cppVar_36042 == 1);
	if (cppVar_36043) {
	BIT_VEC cppVar_36044 = PC + 1;
	cppVar_36044 = (cppVar_36044 & cppMask_un_16_);
	BIT_VEC cppVar_36045 = ROM.rd(cppVar_36044);
	BIT_VEC cppVar_36046 = (cppVar_36045 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_36047 = (cppVar_36046 << 3) | 0;
	cppVar_36047 = (cppVar_36047 & cppMask_un_8_);
	cppVar_36039 = cppVar_36047;
	} else {
	BIT_VEC cppVar_36048 = PC + 1;
	cppVar_36048 = (cppVar_36048 & cppMask_un_16_);
	BIT_VEC cppVar_36049 = ROM.rd(cppVar_36048);
	BIT_VEC cppVar_36050 = (cppVar_36049 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_36051 = (cppVar_36050 & cppMask_un_5_);
	BIT_VEC cppVar_36052 = cppVar_36051 + 32;
	cppVar_36052 = (cppVar_36052 & cppMask_un_8_);
	cppVar_36039 = cppVar_36052;
	}
	bool cppVar_36054 = (cppVar_36039 == 240);
	if (cppVar_36054) {
	cppVar_36038 = B;
	} else {
	cppVar_36038 = 0;
	}
	cppVar_36021 = cppVar_36038;
	}
	cppVar_36004 = cppVar_36021;
	}
	cppVar_35987 = cppVar_36004;
	}
	cppVar_35970 = cppVar_35987;
	}
	cppVar_35953 = cppVar_35970;
	}
	cppVar_35936 = cppVar_35953;
	}
	cppVar_35919 = cppVar_35936;
	}
	cppVar_35902 = cppVar_35919;
	}
	cppVar_35885 = cppVar_35902;
	}
	cppVar_35868 = cppVar_35885;
	}
	cppVar_35851 = cppVar_35868;
	}
	cppVar_35834 = cppVar_35851;
	}
	cppVar_35817 = cppVar_35834;
	}
	cppVar_35800 = cppVar_35817;
	}
	cppVar_35783 = cppVar_35800;
	}
	cppVar_35766 = cppVar_35783;
	}
	cppVar_35749 = cppVar_35766;
	}
	cppVar_35732 = cppVar_35749;
	}
	cppVar_35715 = cppVar_35732;
	}
	cppVar_35698 = cppVar_35715;
	}
	cppVar_35665 = cppVar_35698;
	}
	BIT_VEC cppVar_36056 = cppVar_35664 & cppVar_35665;
	BIT_VEC cppVar_36058 = 0;
	BIT_VEC cppVar_36059 = PC + 1;
	cppVar_36059 = (cppVar_36059 & cppMask_un_16_);
	BIT_VEC cppVar_36060 = ROM.rd(cppVar_36059);
	BIT_VEC cppVar_36061 = (cppVar_36060 >> 0) & cppMask_un_3_;
	BIT_VEC cppVar_36062 = (cppVar_36061 & cppMask_un_3_);
	BIT_VEC cppVar_36063 = cppVar_36058 << static_cast<unsigned>(cppVar_36062);
	cppVar_36063 = (cppVar_36063 & cppMask_un_8_);
	BIT_VEC cppVar_36064 = cppVar_36056 | cppVar_36063;
	cppVar_35637 = cppVar_36064;
	} else {
	cppVar_35637 = P2;
	}
	cppVar_35629 = cppVar_35637;
	} else {
	BIT_VEC cppVar_36065;
	BIT_VEC cppVar_36066 = ROM.rd(PC);
	bool cppVar_36068 = (cppVar_36066 == 5);
	if (cppVar_36068) {
	BIT_VEC cppVar_36069;
	BIT_VEC cppVar_36071 = PC + 1;
	cppVar_36071 = (cppVar_36071 & cppMask_un_16_);
	BIT_VEC cppVar_36072 = ROM.rd(cppVar_36071);
	bool cppVar_36074 = (cppVar_36072 == 160);
	if (cppVar_36074) {
	BIT_VEC cppVar_36075;
	BIT_VEC cppVar_36076 = PC + 1;
	cppVar_36076 = (cppVar_36076 & cppMask_un_16_);
	BIT_VEC cppVar_36077 = ROM.rd(cppVar_36076);
	BIT_VEC cppVar_36078 = (cppVar_36077 >> 7) & cppMask_un_1_;
	bool cppVar_36080 = (cppVar_36078 == 0);
	if (cppVar_36080) {
	BIT_VEC cppVar_36081 = PC + 1;
	cppVar_36081 = (cppVar_36081 & cppMask_un_16_);
	BIT_VEC cppVar_36082 = ROM.rd(cppVar_36081);
	BIT_VEC cppVar_36083 = IRAM.rd(cppVar_36082);
	cppVar_36075 = cppVar_36083;
	} else {
	BIT_VEC cppVar_36084;
	BIT_VEC cppVar_36085 = PC + 1;
	cppVar_36085 = (cppVar_36085 & cppMask_un_16_);
	BIT_VEC cppVar_36086 = ROM.rd(cppVar_36085);
	bool cppVar_36088 = (cppVar_36086 == 128);
	if (cppVar_36088) {
	cppVar_36084 = P0;
	} else {
	BIT_VEC cppVar_36089;
	BIT_VEC cppVar_36090 = PC + 1;
	cppVar_36090 = (cppVar_36090 & cppMask_un_16_);
	BIT_VEC cppVar_36091 = ROM.rd(cppVar_36090);
	bool cppVar_36093 = (cppVar_36091 == 129);
	if (cppVar_36093) {
	cppVar_36089 = SP;
	} else {
	BIT_VEC cppVar_36094;
	BIT_VEC cppVar_36095 = PC + 1;
	cppVar_36095 = (cppVar_36095 & cppMask_un_16_);
	BIT_VEC cppVar_36096 = ROM.rd(cppVar_36095);
	bool cppVar_36098 = (cppVar_36096 == 130);
	if (cppVar_36098) {
	cppVar_36094 = DPL;
	} else {
	BIT_VEC cppVar_36099;
	BIT_VEC cppVar_36100 = PC + 1;
	cppVar_36100 = (cppVar_36100 & cppMask_un_16_);
	BIT_VEC cppVar_36101 = ROM.rd(cppVar_36100);
	bool cppVar_36103 = (cppVar_36101 == 131);
	if (cppVar_36103) {
	cppVar_36099 = DPH;
	} else {
	BIT_VEC cppVar_36104;
	BIT_VEC cppVar_36105 = PC + 1;
	cppVar_36105 = (cppVar_36105 & cppMask_un_16_);
	BIT_VEC cppVar_36106 = ROM.rd(cppVar_36105);
	bool cppVar_36108 = (cppVar_36106 == 135);
	if (cppVar_36108) {
	cppVar_36104 = PCON;
	} else {
	BIT_VEC cppVar_36109;
	BIT_VEC cppVar_36110 = PC + 1;
	cppVar_36110 = (cppVar_36110 & cppMask_un_16_);
	BIT_VEC cppVar_36111 = ROM.rd(cppVar_36110);
	bool cppVar_36113 = (cppVar_36111 == 136);
	if (cppVar_36113) {
	cppVar_36109 = TCON;
	} else {
	BIT_VEC cppVar_36114;
	BIT_VEC cppVar_36115 = PC + 1;
	cppVar_36115 = (cppVar_36115 & cppMask_un_16_);
	BIT_VEC cppVar_36116 = ROM.rd(cppVar_36115);
	bool cppVar_36118 = (cppVar_36116 == 137);
	if (cppVar_36118) {
	cppVar_36114 = TMOD;
	} else {
	BIT_VEC cppVar_36119;
	BIT_VEC cppVar_36120 = PC + 1;
	cppVar_36120 = (cppVar_36120 & cppMask_un_16_);
	BIT_VEC cppVar_36121 = ROM.rd(cppVar_36120);
	bool cppVar_36123 = (cppVar_36121 == 138);
	if (cppVar_36123) {
	cppVar_36119 = TL0;
	} else {
	BIT_VEC cppVar_36124;
	BIT_VEC cppVar_36125 = PC + 1;
	cppVar_36125 = (cppVar_36125 & cppMask_un_16_);
	BIT_VEC cppVar_36126 = ROM.rd(cppVar_36125);
	bool cppVar_36128 = (cppVar_36126 == 140);
	if (cppVar_36128) {
	cppVar_36124 = TH0;
	} else {
	BIT_VEC cppVar_36129;
	BIT_VEC cppVar_36130 = PC + 1;
	cppVar_36130 = (cppVar_36130 & cppMask_un_16_);
	BIT_VEC cppVar_36131 = ROM.rd(cppVar_36130);
	bool cppVar_36133 = (cppVar_36131 == 139);
	if (cppVar_36133) {
	cppVar_36129 = TL1;
	} else {
	BIT_VEC cppVar_36134;
	BIT_VEC cppVar_36135 = PC + 1;
	cppVar_36135 = (cppVar_36135 & cppMask_un_16_);
	BIT_VEC cppVar_36136 = ROM.rd(cppVar_36135);
	bool cppVar_36138 = (cppVar_36136 == 141);
	if (cppVar_36138) {
	cppVar_36134 = TH1;
	} else {
	BIT_VEC cppVar_36139;
	BIT_VEC cppVar_36140 = PC + 1;
	cppVar_36140 = (cppVar_36140 & cppMask_un_16_);
	BIT_VEC cppVar_36141 = ROM.rd(cppVar_36140);
	bool cppVar_36143 = (cppVar_36141 == 144);
	if (cppVar_36143) {
	cppVar_36139 = P1;
	} else {
	BIT_VEC cppVar_36144;
	BIT_VEC cppVar_36145 = PC + 1;
	cppVar_36145 = (cppVar_36145 & cppMask_un_16_);
	BIT_VEC cppVar_36146 = ROM.rd(cppVar_36145);
	bool cppVar_36148 = (cppVar_36146 == 152);
	if (cppVar_36148) {
	cppVar_36144 = SCON;
	} else {
	BIT_VEC cppVar_36149;
	BIT_VEC cppVar_36150 = PC + 1;
	cppVar_36150 = (cppVar_36150 & cppMask_un_16_);
	BIT_VEC cppVar_36151 = ROM.rd(cppVar_36150);
	bool cppVar_36153 = (cppVar_36151 == 153);
	if (cppVar_36153) {
	cppVar_36149 = SBUF;
	} else {
	BIT_VEC cppVar_36154;
	BIT_VEC cppVar_36155 = PC + 1;
	cppVar_36155 = (cppVar_36155 & cppMask_un_16_);
	BIT_VEC cppVar_36156 = ROM.rd(cppVar_36155);
	bool cppVar_36158 = (cppVar_36156 == 160);
	if (cppVar_36158) {
	cppVar_36154 = P2;
	} else {
	BIT_VEC cppVar_36159;
	BIT_VEC cppVar_36160 = PC + 1;
	cppVar_36160 = (cppVar_36160 & cppMask_un_16_);
	BIT_VEC cppVar_36161 = ROM.rd(cppVar_36160);
	bool cppVar_36163 = (cppVar_36161 == 168);
	if (cppVar_36163) {
	cppVar_36159 = IE;
	} else {
	BIT_VEC cppVar_36164;
	BIT_VEC cppVar_36165 = PC + 1;
	cppVar_36165 = (cppVar_36165 & cppMask_un_16_);
	BIT_VEC cppVar_36166 = ROM.rd(cppVar_36165);
	bool cppVar_36168 = (cppVar_36166 == 176);
	if (cppVar_36168) {
	cppVar_36164 = P3;
	} else {
	BIT_VEC cppVar_36169;
	BIT_VEC cppVar_36170 = PC + 1;
	cppVar_36170 = (cppVar_36170 & cppMask_un_16_);
	BIT_VEC cppVar_36171 = ROM.rd(cppVar_36170);
	bool cppVar_36173 = (cppVar_36171 == 184);
	if (cppVar_36173) {
	cppVar_36169 = IP;
	} else {
	BIT_VEC cppVar_36174;
	BIT_VEC cppVar_36175 = PC + 1;
	cppVar_36175 = (cppVar_36175 & cppMask_un_16_);
	BIT_VEC cppVar_36176 = ROM.rd(cppVar_36175);
	bool cppVar_36178 = (cppVar_36176 == 208);
	if (cppVar_36178) {
	cppVar_36174 = PSW;
	} else {
	BIT_VEC cppVar_36179;
	BIT_VEC cppVar_36180 = PC + 1;
	cppVar_36180 = (cppVar_36180 & cppMask_un_16_);
	BIT_VEC cppVar_36181 = ROM.rd(cppVar_36180);
	bool cppVar_36183 = (cppVar_36181 == 224);
	if (cppVar_36183) {
	cppVar_36179 = ACC;
	} else {
	BIT_VEC cppVar_36184;
	BIT_VEC cppVar_36185 = PC + 1;
	cppVar_36185 = (cppVar_36185 & cppMask_un_16_);
	BIT_VEC cppVar_36186 = ROM.rd(cppVar_36185);
	bool cppVar_36188 = (cppVar_36186 == 240);
	if (cppVar_36188) {
	cppVar_36184 = B;
	} else {
	cppVar_36184 = 0;
	}
	cppVar_36179 = cppVar_36184;
	}
	cppVar_36174 = cppVar_36179;
	}
	cppVar_36169 = cppVar_36174;
	}
	cppVar_36164 = cppVar_36169;
	}
	cppVar_36159 = cppVar_36164;
	}
	cppVar_36154 = cppVar_36159;
	}
	cppVar_36149 = cppVar_36154;
	}
	cppVar_36144 = cppVar_36149;
	}
	cppVar_36139 = cppVar_36144;
	}
	cppVar_36134 = cppVar_36139;
	}
	cppVar_36129 = cppVar_36134;
	}
	cppVar_36124 = cppVar_36129;
	}
	cppVar_36119 = cppVar_36124;
	}
	cppVar_36114 = cppVar_36119;
	}
	cppVar_36109 = cppVar_36114;
	}
	cppVar_36104 = cppVar_36109;
	}
	cppVar_36099 = cppVar_36104;
	}
	cppVar_36094 = cppVar_36099;
	}
	cppVar_36089 = cppVar_36094;
	}
	cppVar_36084 = cppVar_36089;
	}
	cppVar_36075 = cppVar_36084;
	}
	BIT_VEC cppVar_36191 = cppVar_36075 + 1;
	cppVar_36191 = (cppVar_36191 & cppMask_un_8_);
	cppVar_36069 = cppVar_36191;
	} else {
	cppVar_36069 = P2;
	}
	cppVar_36065 = cppVar_36069;
	} else {
	cppVar_36065 = P2;
	}
	cppVar_35629 = cppVar_36065;
	}
	cppVar_35498 = cppVar_35629;
	}
	cppVar_35372 = cppVar_35498;
	}
	cppVar_35243 = cppVar_35372;
	}
	cppVar_35117 = cppVar_35243;
	}
	cppVar_34988 = cppVar_35117;
	}
	cppVar_34862 = cppVar_34988;
	}
	cppVar_34733 = cppVar_34862;
	}
	cppVar_34720 = cppVar_34733;
	}
	cppVar_34594 = cppVar_34720;
	}
	cppVar_34577 = cppVar_34594;
	}
	cppVar_34560 = cppVar_34577;
	}
	cppVar_34410 = cppVar_34560;
	}
	cppVar_34260 = cppVar_34410;
	}
	cppVar_34110 = cppVar_34260;
	}
	cppVar_33960 = cppVar_34110;
	}
	cppVar_33810 = cppVar_33960;
	}
	cppVar_33660 = cppVar_33810;
	}
	cppVar_33510 = cppVar_33660;
	}
	cppVar_33360 = cppVar_33510;
	}
	cppVar_32928 = cppVar_33360;
	}
	cppVar_32098 = cppVar_32928;
	}
	cppVar_32084 = cppVar_32098;
	}
	cppVar_32073 = cppVar_32084;
	}
	cppVar_31641 = cppVar_32073;
	}
	return cppVar_31641;
}

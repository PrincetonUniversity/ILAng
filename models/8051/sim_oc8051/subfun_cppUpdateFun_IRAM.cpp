#include "common.hpp"
#include "model_oc8051_class.hpp"

type_mem model_oc8051::cppUpdateFun_IRAM()
{
	type_mem cppVar_86605;
	BIT_VEC cppVar_86606 = ROM.rd(PC);
	bool cppVar_86608 = (cppVar_86606 == 215);
	if (cppVar_86608) {
	BIT_VEC cppVar_86610 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_86612 = (cppVar_86610 << 3) | 1;
	cppVar_86612 = (cppVar_86612 & cppMask_un_5_);
	BIT_VEC cppVar_86613 = (0 << 5) | cppVar_86612;
	cppVar_86613 = (cppVar_86613 & cppMask_un_8_);
	BIT_VEC cppVar_86614 = IRAM.rd(cppVar_86613);
	BIT_VEC cppVar_86615 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_86616 = (cppVar_86615 << 3) | 1;
	cppVar_86616 = (cppVar_86616 & cppMask_un_5_);
	BIT_VEC cppVar_86617 = (0 << 5) | cppVar_86616;
	cppVar_86617 = (cppVar_86617 & cppMask_un_8_);
	BIT_VEC cppVar_86618 = IRAM.rd(cppVar_86617);
	BIT_VEC cppVar_86619 = IRAM.rd(cppVar_86618);
	BIT_VEC cppVar_86620 = (cppVar_86619 >> 4) & cppMask_un_4_;
	BIT_VEC cppVar_86621 = (ACC >> 0) & cppMask_un_4_;
	BIT_VEC cppVar_86622 = (cppVar_86620 << 4) | cppVar_86621;
	cppVar_86622 = (cppVar_86622 & cppMask_un_8_);
	type_mem cppVar_86623 = IRAM;
	cppVar_86623.wr(cppVar_86614, cppVar_86622);
	cppVar_86605 = cppVar_86623;
	} else {
	type_mem cppVar_86624;
	BIT_VEC cppVar_86625 = ROM.rd(PC);
	bool cppVar_86627 = (cppVar_86625 == 214);
	if (cppVar_86627) {
	BIT_VEC cppVar_86629 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_86631 = (cppVar_86629 << 3) | 0;
	cppVar_86631 = (cppVar_86631 & cppMask_un_5_);
	BIT_VEC cppVar_86632 = (0 << 5) | cppVar_86631;
	cppVar_86632 = (cppVar_86632 & cppMask_un_8_);
	BIT_VEC cppVar_86633 = IRAM.rd(cppVar_86632);
	BIT_VEC cppVar_86634 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_86635 = (cppVar_86634 << 3) | 0;
	cppVar_86635 = (cppVar_86635 & cppMask_un_5_);
	BIT_VEC cppVar_86636 = (0 << 5) | cppVar_86635;
	cppVar_86636 = (cppVar_86636 & cppMask_un_8_);
	BIT_VEC cppVar_86637 = IRAM.rd(cppVar_86636);
	BIT_VEC cppVar_86638 = IRAM.rd(cppVar_86637);
	BIT_VEC cppVar_86639 = (cppVar_86638 >> 4) & cppMask_un_4_;
	BIT_VEC cppVar_86640 = (ACC >> 0) & cppMask_un_4_;
	BIT_VEC cppVar_86641 = (cppVar_86639 << 4) | cppVar_86640;
	cppVar_86641 = (cppVar_86641 & cppMask_un_8_);
	type_mem cppVar_86642 = IRAM;
	cppVar_86642.wr(cppVar_86633, cppVar_86641);
	cppVar_86624 = cppVar_86642;
	} else {
	type_mem cppVar_86643;
	BIT_VEC cppVar_86644 = ROM.rd(PC);
	bool cppVar_86646 = (cppVar_86644 == 210);
	if (cppVar_86646) {
	type_mem cppVar_86647;
	BIT_VEC cppVar_86648;
	BIT_VEC cppVar_86650 = PC + 1;
	cppVar_86650 = (cppVar_86650 & cppMask_un_16_);
	BIT_VEC cppVar_86651 = ROM.rd(cppVar_86650);
	BIT_VEC cppVar_86652 = (cppVar_86651 >> 7) & cppMask_un_1_;
	bool cppVar_86654 = (cppVar_86652 == 1);
	if (cppVar_86654) {
	BIT_VEC cppVar_86655 = PC + 1;
	cppVar_86655 = (cppVar_86655 & cppMask_un_16_);
	BIT_VEC cppVar_86656 = ROM.rd(cppVar_86655);
	BIT_VEC cppVar_86657 = (cppVar_86656 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_86659 = (cppVar_86657 << 3) | 0;
	cppVar_86659 = (cppVar_86659 & cppMask_un_8_);
	cppVar_86648 = cppVar_86659;
	} else {
	BIT_VEC cppVar_86660 = PC + 1;
	cppVar_86660 = (cppVar_86660 & cppMask_un_16_);
	BIT_VEC cppVar_86661 = ROM.rd(cppVar_86660);
	BIT_VEC cppVar_86662 = (cppVar_86661 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_86663 = (cppVar_86662 & cppMask_un_5_);
	BIT_VEC cppVar_86665 = cppVar_86663 + 32;
	cppVar_86665 = (cppVar_86665 & cppMask_un_8_);
	cppVar_86648 = cppVar_86665;
	}
	BIT_VEC cppVar_86666 = (cppVar_86648 >> 7) & cppMask_un_1_;
	bool cppVar_86668 = (cppVar_86666 == 0);
	if (cppVar_86668) {
	BIT_VEC cppVar_86669;
	BIT_VEC cppVar_86670 = PC + 1;
	cppVar_86670 = (cppVar_86670 & cppMask_un_16_);
	BIT_VEC cppVar_86671 = ROM.rd(cppVar_86670);
	BIT_VEC cppVar_86672 = (cppVar_86671 >> 7) & cppMask_un_1_;
	bool cppVar_86673 = (cppVar_86672 == 1);
	if (cppVar_86673) {
	BIT_VEC cppVar_86674 = PC + 1;
	cppVar_86674 = (cppVar_86674 & cppMask_un_16_);
	BIT_VEC cppVar_86675 = ROM.rd(cppVar_86674);
	BIT_VEC cppVar_86676 = (cppVar_86675 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_86677 = (cppVar_86676 << 3) | 0;
	cppVar_86677 = (cppVar_86677 & cppMask_un_8_);
	cppVar_86669 = cppVar_86677;
	} else {
	BIT_VEC cppVar_86678 = PC + 1;
	cppVar_86678 = (cppVar_86678 & cppMask_un_16_);
	BIT_VEC cppVar_86679 = ROM.rd(cppVar_86678);
	BIT_VEC cppVar_86680 = (cppVar_86679 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_86681 = (cppVar_86680 & cppMask_un_5_);
	BIT_VEC cppVar_86682 = cppVar_86681 + 32;
	cppVar_86682 = (cppVar_86682 & cppMask_un_8_);
	cppVar_86669 = cppVar_86682;
	}
	BIT_VEC cppVar_86684 = PC + 1;
	cppVar_86684 = (cppVar_86684 & cppMask_un_16_);
	BIT_VEC cppVar_86685 = ROM.rd(cppVar_86684);
	BIT_VEC cppVar_86686 = (cppVar_86685 >> 0) & cppMask_un_3_;
	BIT_VEC cppVar_86687 = (cppVar_86686 & cppMask_un_3_);
	BIT_VEC cppVar_86688 = 1 << static_cast<unsigned>(cppVar_86687);
	cppVar_86688 = (cppVar_86688 & cppMask_un_8_);
	BIT_VEC cppVar_86689 = ~cppVar_86688;
	BIT_VEC cppVar_86690;
	BIT_VEC cppVar_86691;
	BIT_VEC cppVar_86692 = PC + 1;
	cppVar_86692 = (cppVar_86692 & cppMask_un_16_);
	BIT_VEC cppVar_86693 = ROM.rd(cppVar_86692);
	BIT_VEC cppVar_86694 = (cppVar_86693 >> 7) & cppMask_un_1_;
	bool cppVar_86695 = (cppVar_86694 == 1);
	if (cppVar_86695) {
	BIT_VEC cppVar_86696 = PC + 1;
	cppVar_86696 = (cppVar_86696 & cppMask_un_16_);
	BIT_VEC cppVar_86697 = ROM.rd(cppVar_86696);
	BIT_VEC cppVar_86698 = (cppVar_86697 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_86699 = (cppVar_86698 << 3) | 0;
	cppVar_86699 = (cppVar_86699 & cppMask_un_8_);
	cppVar_86691 = cppVar_86699;
	} else {
	BIT_VEC cppVar_86700 = PC + 1;
	cppVar_86700 = (cppVar_86700 & cppMask_un_16_);
	BIT_VEC cppVar_86701 = ROM.rd(cppVar_86700);
	BIT_VEC cppVar_86702 = (cppVar_86701 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_86703 = (cppVar_86702 & cppMask_un_5_);
	BIT_VEC cppVar_86704 = cppVar_86703 + 32;
	cppVar_86704 = (cppVar_86704 & cppMask_un_8_);
	cppVar_86691 = cppVar_86704;
	}
	BIT_VEC cppVar_86705 = (cppVar_86691 >> 7) & cppMask_un_1_;
	bool cppVar_86707 = (cppVar_86705 == 0);
	if (cppVar_86707) {
	BIT_VEC cppVar_86708;
	BIT_VEC cppVar_86709 = PC + 1;
	cppVar_86709 = (cppVar_86709 & cppMask_un_16_);
	BIT_VEC cppVar_86710 = ROM.rd(cppVar_86709);
	BIT_VEC cppVar_86711 = (cppVar_86710 >> 7) & cppMask_un_1_;
	bool cppVar_86712 = (cppVar_86711 == 1);
	if (cppVar_86712) {
	BIT_VEC cppVar_86713 = PC + 1;
	cppVar_86713 = (cppVar_86713 & cppMask_un_16_);
	BIT_VEC cppVar_86714 = ROM.rd(cppVar_86713);
	BIT_VEC cppVar_86715 = (cppVar_86714 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_86716 = (cppVar_86715 << 3) | 0;
	cppVar_86716 = (cppVar_86716 & cppMask_un_8_);
	cppVar_86708 = cppVar_86716;
	} else {
	BIT_VEC cppVar_86717 = PC + 1;
	cppVar_86717 = (cppVar_86717 & cppMask_un_16_);
	BIT_VEC cppVar_86718 = ROM.rd(cppVar_86717);
	BIT_VEC cppVar_86719 = (cppVar_86718 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_86720 = (cppVar_86719 & cppMask_un_5_);
	BIT_VEC cppVar_86721 = cppVar_86720 + 32;
	cppVar_86721 = (cppVar_86721 & cppMask_un_8_);
	cppVar_86708 = cppVar_86721;
	}
	BIT_VEC cppVar_86722 = IRAM.rd(cppVar_86708);
	cppVar_86690 = cppVar_86722;
	} else {
	BIT_VEC cppVar_86723;
	BIT_VEC cppVar_86724;
	BIT_VEC cppVar_86725 = PC + 1;
	cppVar_86725 = (cppVar_86725 & cppMask_un_16_);
	BIT_VEC cppVar_86726 = ROM.rd(cppVar_86725);
	BIT_VEC cppVar_86727 = (cppVar_86726 >> 7) & cppMask_un_1_;
	bool cppVar_86728 = (cppVar_86727 == 1);
	if (cppVar_86728) {
	BIT_VEC cppVar_86729 = PC + 1;
	cppVar_86729 = (cppVar_86729 & cppMask_un_16_);
	BIT_VEC cppVar_86730 = ROM.rd(cppVar_86729);
	BIT_VEC cppVar_86731 = (cppVar_86730 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_86732 = (cppVar_86731 << 3) | 0;
	cppVar_86732 = (cppVar_86732 & cppMask_un_8_);
	cppVar_86724 = cppVar_86732;
	} else {
	BIT_VEC cppVar_86733 = PC + 1;
	cppVar_86733 = (cppVar_86733 & cppMask_un_16_);
	BIT_VEC cppVar_86734 = ROM.rd(cppVar_86733);
	BIT_VEC cppVar_86735 = (cppVar_86734 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_86736 = (cppVar_86735 & cppMask_un_5_);
	BIT_VEC cppVar_86737 = cppVar_86736 + 32;
	cppVar_86737 = (cppVar_86737 & cppMask_un_8_);
	cppVar_86724 = cppVar_86737;
	}
	bool cppVar_86739 = (cppVar_86724 == 128);
	if (cppVar_86739) {
	cppVar_86723 = P0;
	} else {
	BIT_VEC cppVar_86740;
	BIT_VEC cppVar_86741;
	BIT_VEC cppVar_86742 = PC + 1;
	cppVar_86742 = (cppVar_86742 & cppMask_un_16_);
	BIT_VEC cppVar_86743 = ROM.rd(cppVar_86742);
	BIT_VEC cppVar_86744 = (cppVar_86743 >> 7) & cppMask_un_1_;
	bool cppVar_86745 = (cppVar_86744 == 1);
	if (cppVar_86745) {
	BIT_VEC cppVar_86746 = PC + 1;
	cppVar_86746 = (cppVar_86746 & cppMask_un_16_);
	BIT_VEC cppVar_86747 = ROM.rd(cppVar_86746);
	BIT_VEC cppVar_86748 = (cppVar_86747 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_86749 = (cppVar_86748 << 3) | 0;
	cppVar_86749 = (cppVar_86749 & cppMask_un_8_);
	cppVar_86741 = cppVar_86749;
	} else {
	BIT_VEC cppVar_86750 = PC + 1;
	cppVar_86750 = (cppVar_86750 & cppMask_un_16_);
	BIT_VEC cppVar_86751 = ROM.rd(cppVar_86750);
	BIT_VEC cppVar_86752 = (cppVar_86751 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_86753 = (cppVar_86752 & cppMask_un_5_);
	BIT_VEC cppVar_86754 = cppVar_86753 + 32;
	cppVar_86754 = (cppVar_86754 & cppMask_un_8_);
	cppVar_86741 = cppVar_86754;
	}
	bool cppVar_86756 = (cppVar_86741 == 129);
	if (cppVar_86756) {
	cppVar_86740 = SP;
	} else {
	BIT_VEC cppVar_86757;
	BIT_VEC cppVar_86758;
	BIT_VEC cppVar_86759 = PC + 1;
	cppVar_86759 = (cppVar_86759 & cppMask_un_16_);
	BIT_VEC cppVar_86760 = ROM.rd(cppVar_86759);
	BIT_VEC cppVar_86761 = (cppVar_86760 >> 7) & cppMask_un_1_;
	bool cppVar_86762 = (cppVar_86761 == 1);
	if (cppVar_86762) {
	BIT_VEC cppVar_86763 = PC + 1;
	cppVar_86763 = (cppVar_86763 & cppMask_un_16_);
	BIT_VEC cppVar_86764 = ROM.rd(cppVar_86763);
	BIT_VEC cppVar_86765 = (cppVar_86764 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_86766 = (cppVar_86765 << 3) | 0;
	cppVar_86766 = (cppVar_86766 & cppMask_un_8_);
	cppVar_86758 = cppVar_86766;
	} else {
	BIT_VEC cppVar_86767 = PC + 1;
	cppVar_86767 = (cppVar_86767 & cppMask_un_16_);
	BIT_VEC cppVar_86768 = ROM.rd(cppVar_86767);
	BIT_VEC cppVar_86769 = (cppVar_86768 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_86770 = (cppVar_86769 & cppMask_un_5_);
	BIT_VEC cppVar_86771 = cppVar_86770 + 32;
	cppVar_86771 = (cppVar_86771 & cppMask_un_8_);
	cppVar_86758 = cppVar_86771;
	}
	bool cppVar_86773 = (cppVar_86758 == 130);
	if (cppVar_86773) {
	cppVar_86757 = DPL;
	} else {
	BIT_VEC cppVar_86774;
	BIT_VEC cppVar_86775;
	BIT_VEC cppVar_86776 = PC + 1;
	cppVar_86776 = (cppVar_86776 & cppMask_un_16_);
	BIT_VEC cppVar_86777 = ROM.rd(cppVar_86776);
	BIT_VEC cppVar_86778 = (cppVar_86777 >> 7) & cppMask_un_1_;
	bool cppVar_86779 = (cppVar_86778 == 1);
	if (cppVar_86779) {
	BIT_VEC cppVar_86780 = PC + 1;
	cppVar_86780 = (cppVar_86780 & cppMask_un_16_);
	BIT_VEC cppVar_86781 = ROM.rd(cppVar_86780);
	BIT_VEC cppVar_86782 = (cppVar_86781 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_86783 = (cppVar_86782 << 3) | 0;
	cppVar_86783 = (cppVar_86783 & cppMask_un_8_);
	cppVar_86775 = cppVar_86783;
	} else {
	BIT_VEC cppVar_86784 = PC + 1;
	cppVar_86784 = (cppVar_86784 & cppMask_un_16_);
	BIT_VEC cppVar_86785 = ROM.rd(cppVar_86784);
	BIT_VEC cppVar_86786 = (cppVar_86785 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_86787 = (cppVar_86786 & cppMask_un_5_);
	BIT_VEC cppVar_86788 = cppVar_86787 + 32;
	cppVar_86788 = (cppVar_86788 & cppMask_un_8_);
	cppVar_86775 = cppVar_86788;
	}
	bool cppVar_86790 = (cppVar_86775 == 131);
	if (cppVar_86790) {
	cppVar_86774 = DPH;
	} else {
	BIT_VEC cppVar_86791;
	BIT_VEC cppVar_86792;
	BIT_VEC cppVar_86793 = PC + 1;
	cppVar_86793 = (cppVar_86793 & cppMask_un_16_);
	BIT_VEC cppVar_86794 = ROM.rd(cppVar_86793);
	BIT_VEC cppVar_86795 = (cppVar_86794 >> 7) & cppMask_un_1_;
	bool cppVar_86796 = (cppVar_86795 == 1);
	if (cppVar_86796) {
	BIT_VEC cppVar_86797 = PC + 1;
	cppVar_86797 = (cppVar_86797 & cppMask_un_16_);
	BIT_VEC cppVar_86798 = ROM.rd(cppVar_86797);
	BIT_VEC cppVar_86799 = (cppVar_86798 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_86800 = (cppVar_86799 << 3) | 0;
	cppVar_86800 = (cppVar_86800 & cppMask_un_8_);
	cppVar_86792 = cppVar_86800;
	} else {
	BIT_VEC cppVar_86801 = PC + 1;
	cppVar_86801 = (cppVar_86801 & cppMask_un_16_);
	BIT_VEC cppVar_86802 = ROM.rd(cppVar_86801);
	BIT_VEC cppVar_86803 = (cppVar_86802 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_86804 = (cppVar_86803 & cppMask_un_5_);
	BIT_VEC cppVar_86805 = cppVar_86804 + 32;
	cppVar_86805 = (cppVar_86805 & cppMask_un_8_);
	cppVar_86792 = cppVar_86805;
	}
	bool cppVar_86807 = (cppVar_86792 == 135);
	if (cppVar_86807) {
	cppVar_86791 = PCON;
	} else {
	BIT_VEC cppVar_86808;
	BIT_VEC cppVar_86809;
	BIT_VEC cppVar_86810 = PC + 1;
	cppVar_86810 = (cppVar_86810 & cppMask_un_16_);
	BIT_VEC cppVar_86811 = ROM.rd(cppVar_86810);
	BIT_VEC cppVar_86812 = (cppVar_86811 >> 7) & cppMask_un_1_;
	bool cppVar_86813 = (cppVar_86812 == 1);
	if (cppVar_86813) {
	BIT_VEC cppVar_86814 = PC + 1;
	cppVar_86814 = (cppVar_86814 & cppMask_un_16_);
	BIT_VEC cppVar_86815 = ROM.rd(cppVar_86814);
	BIT_VEC cppVar_86816 = (cppVar_86815 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_86817 = (cppVar_86816 << 3) | 0;
	cppVar_86817 = (cppVar_86817 & cppMask_un_8_);
	cppVar_86809 = cppVar_86817;
	} else {
	BIT_VEC cppVar_86818 = PC + 1;
	cppVar_86818 = (cppVar_86818 & cppMask_un_16_);
	BIT_VEC cppVar_86819 = ROM.rd(cppVar_86818);
	BIT_VEC cppVar_86820 = (cppVar_86819 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_86821 = (cppVar_86820 & cppMask_un_5_);
	BIT_VEC cppVar_86822 = cppVar_86821 + 32;
	cppVar_86822 = (cppVar_86822 & cppMask_un_8_);
	cppVar_86809 = cppVar_86822;
	}
	bool cppVar_86824 = (cppVar_86809 == 136);
	if (cppVar_86824) {
	cppVar_86808 = TCON;
	} else {
	BIT_VEC cppVar_86825;
	BIT_VEC cppVar_86826;
	BIT_VEC cppVar_86827 = PC + 1;
	cppVar_86827 = (cppVar_86827 & cppMask_un_16_);
	BIT_VEC cppVar_86828 = ROM.rd(cppVar_86827);
	BIT_VEC cppVar_86829 = (cppVar_86828 >> 7) & cppMask_un_1_;
	bool cppVar_86830 = (cppVar_86829 == 1);
	if (cppVar_86830) {
	BIT_VEC cppVar_86831 = PC + 1;
	cppVar_86831 = (cppVar_86831 & cppMask_un_16_);
	BIT_VEC cppVar_86832 = ROM.rd(cppVar_86831);
	BIT_VEC cppVar_86833 = (cppVar_86832 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_86834 = (cppVar_86833 << 3) | 0;
	cppVar_86834 = (cppVar_86834 & cppMask_un_8_);
	cppVar_86826 = cppVar_86834;
	} else {
	BIT_VEC cppVar_86835 = PC + 1;
	cppVar_86835 = (cppVar_86835 & cppMask_un_16_);
	BIT_VEC cppVar_86836 = ROM.rd(cppVar_86835);
	BIT_VEC cppVar_86837 = (cppVar_86836 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_86838 = (cppVar_86837 & cppMask_un_5_);
	BIT_VEC cppVar_86839 = cppVar_86838 + 32;
	cppVar_86839 = (cppVar_86839 & cppMask_un_8_);
	cppVar_86826 = cppVar_86839;
	}
	bool cppVar_86841 = (cppVar_86826 == 137);
	if (cppVar_86841) {
	cppVar_86825 = TMOD;
	} else {
	BIT_VEC cppVar_86842;
	BIT_VEC cppVar_86843;
	BIT_VEC cppVar_86844 = PC + 1;
	cppVar_86844 = (cppVar_86844 & cppMask_un_16_);
	BIT_VEC cppVar_86845 = ROM.rd(cppVar_86844);
	BIT_VEC cppVar_86846 = (cppVar_86845 >> 7) & cppMask_un_1_;
	bool cppVar_86847 = (cppVar_86846 == 1);
	if (cppVar_86847) {
	BIT_VEC cppVar_86848 = PC + 1;
	cppVar_86848 = (cppVar_86848 & cppMask_un_16_);
	BIT_VEC cppVar_86849 = ROM.rd(cppVar_86848);
	BIT_VEC cppVar_86850 = (cppVar_86849 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_86851 = (cppVar_86850 << 3) | 0;
	cppVar_86851 = (cppVar_86851 & cppMask_un_8_);
	cppVar_86843 = cppVar_86851;
	} else {
	BIT_VEC cppVar_86852 = PC + 1;
	cppVar_86852 = (cppVar_86852 & cppMask_un_16_);
	BIT_VEC cppVar_86853 = ROM.rd(cppVar_86852);
	BIT_VEC cppVar_86854 = (cppVar_86853 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_86855 = (cppVar_86854 & cppMask_un_5_);
	BIT_VEC cppVar_86856 = cppVar_86855 + 32;
	cppVar_86856 = (cppVar_86856 & cppMask_un_8_);
	cppVar_86843 = cppVar_86856;
	}
	bool cppVar_86858 = (cppVar_86843 == 138);
	if (cppVar_86858) {
	cppVar_86842 = TL0;
	} else {
	BIT_VEC cppVar_86859;
	BIT_VEC cppVar_86860;
	BIT_VEC cppVar_86861 = PC + 1;
	cppVar_86861 = (cppVar_86861 & cppMask_un_16_);
	BIT_VEC cppVar_86862 = ROM.rd(cppVar_86861);
	BIT_VEC cppVar_86863 = (cppVar_86862 >> 7) & cppMask_un_1_;
	bool cppVar_86864 = (cppVar_86863 == 1);
	if (cppVar_86864) {
	BIT_VEC cppVar_86865 = PC + 1;
	cppVar_86865 = (cppVar_86865 & cppMask_un_16_);
	BIT_VEC cppVar_86866 = ROM.rd(cppVar_86865);
	BIT_VEC cppVar_86867 = (cppVar_86866 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_86868 = (cppVar_86867 << 3) | 0;
	cppVar_86868 = (cppVar_86868 & cppMask_un_8_);
	cppVar_86860 = cppVar_86868;
	} else {
	BIT_VEC cppVar_86869 = PC + 1;
	cppVar_86869 = (cppVar_86869 & cppMask_un_16_);
	BIT_VEC cppVar_86870 = ROM.rd(cppVar_86869);
	BIT_VEC cppVar_86871 = (cppVar_86870 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_86872 = (cppVar_86871 & cppMask_un_5_);
	BIT_VEC cppVar_86873 = cppVar_86872 + 32;
	cppVar_86873 = (cppVar_86873 & cppMask_un_8_);
	cppVar_86860 = cppVar_86873;
	}
	bool cppVar_86875 = (cppVar_86860 == 140);
	if (cppVar_86875) {
	cppVar_86859 = TH0;
	} else {
	BIT_VEC cppVar_86876;
	BIT_VEC cppVar_86877;
	BIT_VEC cppVar_86878 = PC + 1;
	cppVar_86878 = (cppVar_86878 & cppMask_un_16_);
	BIT_VEC cppVar_86879 = ROM.rd(cppVar_86878);
	BIT_VEC cppVar_86880 = (cppVar_86879 >> 7) & cppMask_un_1_;
	bool cppVar_86881 = (cppVar_86880 == 1);
	if (cppVar_86881) {
	BIT_VEC cppVar_86882 = PC + 1;
	cppVar_86882 = (cppVar_86882 & cppMask_un_16_);
	BIT_VEC cppVar_86883 = ROM.rd(cppVar_86882);
	BIT_VEC cppVar_86884 = (cppVar_86883 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_86885 = (cppVar_86884 << 3) | 0;
	cppVar_86885 = (cppVar_86885 & cppMask_un_8_);
	cppVar_86877 = cppVar_86885;
	} else {
	BIT_VEC cppVar_86886 = PC + 1;
	cppVar_86886 = (cppVar_86886 & cppMask_un_16_);
	BIT_VEC cppVar_86887 = ROM.rd(cppVar_86886);
	BIT_VEC cppVar_86888 = (cppVar_86887 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_86889 = (cppVar_86888 & cppMask_un_5_);
	BIT_VEC cppVar_86890 = cppVar_86889 + 32;
	cppVar_86890 = (cppVar_86890 & cppMask_un_8_);
	cppVar_86877 = cppVar_86890;
	}
	bool cppVar_86892 = (cppVar_86877 == 139);
	if (cppVar_86892) {
	cppVar_86876 = TL1;
	} else {
	BIT_VEC cppVar_86893;
	BIT_VEC cppVar_86894;
	BIT_VEC cppVar_86895 = PC + 1;
	cppVar_86895 = (cppVar_86895 & cppMask_un_16_);
	BIT_VEC cppVar_86896 = ROM.rd(cppVar_86895);
	BIT_VEC cppVar_86897 = (cppVar_86896 >> 7) & cppMask_un_1_;
	bool cppVar_86898 = (cppVar_86897 == 1);
	if (cppVar_86898) {
	BIT_VEC cppVar_86899 = PC + 1;
	cppVar_86899 = (cppVar_86899 & cppMask_un_16_);
	BIT_VEC cppVar_86900 = ROM.rd(cppVar_86899);
	BIT_VEC cppVar_86901 = (cppVar_86900 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_86902 = (cppVar_86901 << 3) | 0;
	cppVar_86902 = (cppVar_86902 & cppMask_un_8_);
	cppVar_86894 = cppVar_86902;
	} else {
	BIT_VEC cppVar_86903 = PC + 1;
	cppVar_86903 = (cppVar_86903 & cppMask_un_16_);
	BIT_VEC cppVar_86904 = ROM.rd(cppVar_86903);
	BIT_VEC cppVar_86905 = (cppVar_86904 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_86906 = (cppVar_86905 & cppMask_un_5_);
	BIT_VEC cppVar_86907 = cppVar_86906 + 32;
	cppVar_86907 = (cppVar_86907 & cppMask_un_8_);
	cppVar_86894 = cppVar_86907;
	}
	bool cppVar_86909 = (cppVar_86894 == 141);
	if (cppVar_86909) {
	cppVar_86893 = TH1;
	} else {
	BIT_VEC cppVar_86910;
	BIT_VEC cppVar_86911;
	BIT_VEC cppVar_86912 = PC + 1;
	cppVar_86912 = (cppVar_86912 & cppMask_un_16_);
	BIT_VEC cppVar_86913 = ROM.rd(cppVar_86912);
	BIT_VEC cppVar_86914 = (cppVar_86913 >> 7) & cppMask_un_1_;
	bool cppVar_86915 = (cppVar_86914 == 1);
	if (cppVar_86915) {
	BIT_VEC cppVar_86916 = PC + 1;
	cppVar_86916 = (cppVar_86916 & cppMask_un_16_);
	BIT_VEC cppVar_86917 = ROM.rd(cppVar_86916);
	BIT_VEC cppVar_86918 = (cppVar_86917 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_86919 = (cppVar_86918 << 3) | 0;
	cppVar_86919 = (cppVar_86919 & cppMask_un_8_);
	cppVar_86911 = cppVar_86919;
	} else {
	BIT_VEC cppVar_86920 = PC + 1;
	cppVar_86920 = (cppVar_86920 & cppMask_un_16_);
	BIT_VEC cppVar_86921 = ROM.rd(cppVar_86920);
	BIT_VEC cppVar_86922 = (cppVar_86921 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_86923 = (cppVar_86922 & cppMask_un_5_);
	BIT_VEC cppVar_86924 = cppVar_86923 + 32;
	cppVar_86924 = (cppVar_86924 & cppMask_un_8_);
	cppVar_86911 = cppVar_86924;
	}
	bool cppVar_86926 = (cppVar_86911 == 144);
	if (cppVar_86926) {
	cppVar_86910 = P1;
	} else {
	BIT_VEC cppVar_86927;
	BIT_VEC cppVar_86928;
	BIT_VEC cppVar_86929 = PC + 1;
	cppVar_86929 = (cppVar_86929 & cppMask_un_16_);
	BIT_VEC cppVar_86930 = ROM.rd(cppVar_86929);
	BIT_VEC cppVar_86931 = (cppVar_86930 >> 7) & cppMask_un_1_;
	bool cppVar_86932 = (cppVar_86931 == 1);
	if (cppVar_86932) {
	BIT_VEC cppVar_86933 = PC + 1;
	cppVar_86933 = (cppVar_86933 & cppMask_un_16_);
	BIT_VEC cppVar_86934 = ROM.rd(cppVar_86933);
	BIT_VEC cppVar_86935 = (cppVar_86934 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_86936 = (cppVar_86935 << 3) | 0;
	cppVar_86936 = (cppVar_86936 & cppMask_un_8_);
	cppVar_86928 = cppVar_86936;
	} else {
	BIT_VEC cppVar_86937 = PC + 1;
	cppVar_86937 = (cppVar_86937 & cppMask_un_16_);
	BIT_VEC cppVar_86938 = ROM.rd(cppVar_86937);
	BIT_VEC cppVar_86939 = (cppVar_86938 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_86940 = (cppVar_86939 & cppMask_un_5_);
	BIT_VEC cppVar_86941 = cppVar_86940 + 32;
	cppVar_86941 = (cppVar_86941 & cppMask_un_8_);
	cppVar_86928 = cppVar_86941;
	}
	bool cppVar_86943 = (cppVar_86928 == 152);
	if (cppVar_86943) {
	cppVar_86927 = SCON;
	} else {
	BIT_VEC cppVar_86944;
	BIT_VEC cppVar_86945;
	BIT_VEC cppVar_86946 = PC + 1;
	cppVar_86946 = (cppVar_86946 & cppMask_un_16_);
	BIT_VEC cppVar_86947 = ROM.rd(cppVar_86946);
	BIT_VEC cppVar_86948 = (cppVar_86947 >> 7) & cppMask_un_1_;
	bool cppVar_86949 = (cppVar_86948 == 1);
	if (cppVar_86949) {
	BIT_VEC cppVar_86950 = PC + 1;
	cppVar_86950 = (cppVar_86950 & cppMask_un_16_);
	BIT_VEC cppVar_86951 = ROM.rd(cppVar_86950);
	BIT_VEC cppVar_86952 = (cppVar_86951 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_86953 = (cppVar_86952 << 3) | 0;
	cppVar_86953 = (cppVar_86953 & cppMask_un_8_);
	cppVar_86945 = cppVar_86953;
	} else {
	BIT_VEC cppVar_86954 = PC + 1;
	cppVar_86954 = (cppVar_86954 & cppMask_un_16_);
	BIT_VEC cppVar_86955 = ROM.rd(cppVar_86954);
	BIT_VEC cppVar_86956 = (cppVar_86955 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_86957 = (cppVar_86956 & cppMask_un_5_);
	BIT_VEC cppVar_86958 = cppVar_86957 + 32;
	cppVar_86958 = (cppVar_86958 & cppMask_un_8_);
	cppVar_86945 = cppVar_86958;
	}
	bool cppVar_86960 = (cppVar_86945 == 153);
	if (cppVar_86960) {
	cppVar_86944 = SBUF;
	} else {
	BIT_VEC cppVar_86961;
	BIT_VEC cppVar_86962;
	BIT_VEC cppVar_86963 = PC + 1;
	cppVar_86963 = (cppVar_86963 & cppMask_un_16_);
	BIT_VEC cppVar_86964 = ROM.rd(cppVar_86963);
	BIT_VEC cppVar_86965 = (cppVar_86964 >> 7) & cppMask_un_1_;
	bool cppVar_86966 = (cppVar_86965 == 1);
	if (cppVar_86966) {
	BIT_VEC cppVar_86967 = PC + 1;
	cppVar_86967 = (cppVar_86967 & cppMask_un_16_);
	BIT_VEC cppVar_86968 = ROM.rd(cppVar_86967);
	BIT_VEC cppVar_86969 = (cppVar_86968 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_86970 = (cppVar_86969 << 3) | 0;
	cppVar_86970 = (cppVar_86970 & cppMask_un_8_);
	cppVar_86962 = cppVar_86970;
	} else {
	BIT_VEC cppVar_86971 = PC + 1;
	cppVar_86971 = (cppVar_86971 & cppMask_un_16_);
	BIT_VEC cppVar_86972 = ROM.rd(cppVar_86971);
	BIT_VEC cppVar_86973 = (cppVar_86972 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_86974 = (cppVar_86973 & cppMask_un_5_);
	BIT_VEC cppVar_86975 = cppVar_86974 + 32;
	cppVar_86975 = (cppVar_86975 & cppMask_un_8_);
	cppVar_86962 = cppVar_86975;
	}
	bool cppVar_86977 = (cppVar_86962 == 160);
	if (cppVar_86977) {
	cppVar_86961 = P2;
	} else {
	BIT_VEC cppVar_86978;
	BIT_VEC cppVar_86979;
	BIT_VEC cppVar_86980 = PC + 1;
	cppVar_86980 = (cppVar_86980 & cppMask_un_16_);
	BIT_VEC cppVar_86981 = ROM.rd(cppVar_86980);
	BIT_VEC cppVar_86982 = (cppVar_86981 >> 7) & cppMask_un_1_;
	bool cppVar_86983 = (cppVar_86982 == 1);
	if (cppVar_86983) {
	BIT_VEC cppVar_86984 = PC + 1;
	cppVar_86984 = (cppVar_86984 & cppMask_un_16_);
	BIT_VEC cppVar_86985 = ROM.rd(cppVar_86984);
	BIT_VEC cppVar_86986 = (cppVar_86985 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_86987 = (cppVar_86986 << 3) | 0;
	cppVar_86987 = (cppVar_86987 & cppMask_un_8_);
	cppVar_86979 = cppVar_86987;
	} else {
	BIT_VEC cppVar_86988 = PC + 1;
	cppVar_86988 = (cppVar_86988 & cppMask_un_16_);
	BIT_VEC cppVar_86989 = ROM.rd(cppVar_86988);
	BIT_VEC cppVar_86990 = (cppVar_86989 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_86991 = (cppVar_86990 & cppMask_un_5_);
	BIT_VEC cppVar_86992 = cppVar_86991 + 32;
	cppVar_86992 = (cppVar_86992 & cppMask_un_8_);
	cppVar_86979 = cppVar_86992;
	}
	bool cppVar_86994 = (cppVar_86979 == 168);
	if (cppVar_86994) {
	cppVar_86978 = IE;
	} else {
	BIT_VEC cppVar_86995;
	BIT_VEC cppVar_86996;
	BIT_VEC cppVar_86997 = PC + 1;
	cppVar_86997 = (cppVar_86997 & cppMask_un_16_);
	BIT_VEC cppVar_86998 = ROM.rd(cppVar_86997);
	BIT_VEC cppVar_86999 = (cppVar_86998 >> 7) & cppMask_un_1_;
	bool cppVar_87000 = (cppVar_86999 == 1);
	if (cppVar_87000) {
	BIT_VEC cppVar_87001 = PC + 1;
	cppVar_87001 = (cppVar_87001 & cppMask_un_16_);
	BIT_VEC cppVar_87002 = ROM.rd(cppVar_87001);
	BIT_VEC cppVar_87003 = (cppVar_87002 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_87004 = (cppVar_87003 << 3) | 0;
	cppVar_87004 = (cppVar_87004 & cppMask_un_8_);
	cppVar_86996 = cppVar_87004;
	} else {
	BIT_VEC cppVar_87005 = PC + 1;
	cppVar_87005 = (cppVar_87005 & cppMask_un_16_);
	BIT_VEC cppVar_87006 = ROM.rd(cppVar_87005);
	BIT_VEC cppVar_87007 = (cppVar_87006 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_87008 = (cppVar_87007 & cppMask_un_5_);
	BIT_VEC cppVar_87009 = cppVar_87008 + 32;
	cppVar_87009 = (cppVar_87009 & cppMask_un_8_);
	cppVar_86996 = cppVar_87009;
	}
	bool cppVar_87011 = (cppVar_86996 == 176);
	if (cppVar_87011) {
	cppVar_86995 = P3;
	} else {
	BIT_VEC cppVar_87012;
	BIT_VEC cppVar_87013;
	BIT_VEC cppVar_87014 = PC + 1;
	cppVar_87014 = (cppVar_87014 & cppMask_un_16_);
	BIT_VEC cppVar_87015 = ROM.rd(cppVar_87014);
	BIT_VEC cppVar_87016 = (cppVar_87015 >> 7) & cppMask_un_1_;
	bool cppVar_87017 = (cppVar_87016 == 1);
	if (cppVar_87017) {
	BIT_VEC cppVar_87018 = PC + 1;
	cppVar_87018 = (cppVar_87018 & cppMask_un_16_);
	BIT_VEC cppVar_87019 = ROM.rd(cppVar_87018);
	BIT_VEC cppVar_87020 = (cppVar_87019 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_87021 = (cppVar_87020 << 3) | 0;
	cppVar_87021 = (cppVar_87021 & cppMask_un_8_);
	cppVar_87013 = cppVar_87021;
	} else {
	BIT_VEC cppVar_87022 = PC + 1;
	cppVar_87022 = (cppVar_87022 & cppMask_un_16_);
	BIT_VEC cppVar_87023 = ROM.rd(cppVar_87022);
	BIT_VEC cppVar_87024 = (cppVar_87023 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_87025 = (cppVar_87024 & cppMask_un_5_);
	BIT_VEC cppVar_87026 = cppVar_87025 + 32;
	cppVar_87026 = (cppVar_87026 & cppMask_un_8_);
	cppVar_87013 = cppVar_87026;
	}
	bool cppVar_87028 = (cppVar_87013 == 184);
	if (cppVar_87028) {
	cppVar_87012 = IP;
	} else {
	BIT_VEC cppVar_87029;
	BIT_VEC cppVar_87030;
	BIT_VEC cppVar_87031 = PC + 1;
	cppVar_87031 = (cppVar_87031 & cppMask_un_16_);
	BIT_VEC cppVar_87032 = ROM.rd(cppVar_87031);
	BIT_VEC cppVar_87033 = (cppVar_87032 >> 7) & cppMask_un_1_;
	bool cppVar_87034 = (cppVar_87033 == 1);
	if (cppVar_87034) {
	BIT_VEC cppVar_87035 = PC + 1;
	cppVar_87035 = (cppVar_87035 & cppMask_un_16_);
	BIT_VEC cppVar_87036 = ROM.rd(cppVar_87035);
	BIT_VEC cppVar_87037 = (cppVar_87036 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_87038 = (cppVar_87037 << 3) | 0;
	cppVar_87038 = (cppVar_87038 & cppMask_un_8_);
	cppVar_87030 = cppVar_87038;
	} else {
	BIT_VEC cppVar_87039 = PC + 1;
	cppVar_87039 = (cppVar_87039 & cppMask_un_16_);
	BIT_VEC cppVar_87040 = ROM.rd(cppVar_87039);
	BIT_VEC cppVar_87041 = (cppVar_87040 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_87042 = (cppVar_87041 & cppMask_un_5_);
	BIT_VEC cppVar_87043 = cppVar_87042 + 32;
	cppVar_87043 = (cppVar_87043 & cppMask_un_8_);
	cppVar_87030 = cppVar_87043;
	}
	bool cppVar_87045 = (cppVar_87030 == 208);
	if (cppVar_87045) {
	cppVar_87029 = PSW;
	} else {
	BIT_VEC cppVar_87046;
	BIT_VEC cppVar_87047;
	BIT_VEC cppVar_87048 = PC + 1;
	cppVar_87048 = (cppVar_87048 & cppMask_un_16_);
	BIT_VEC cppVar_87049 = ROM.rd(cppVar_87048);
	BIT_VEC cppVar_87050 = (cppVar_87049 >> 7) & cppMask_un_1_;
	bool cppVar_87051 = (cppVar_87050 == 1);
	if (cppVar_87051) {
	BIT_VEC cppVar_87052 = PC + 1;
	cppVar_87052 = (cppVar_87052 & cppMask_un_16_);
	BIT_VEC cppVar_87053 = ROM.rd(cppVar_87052);
	BIT_VEC cppVar_87054 = (cppVar_87053 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_87055 = (cppVar_87054 << 3) | 0;
	cppVar_87055 = (cppVar_87055 & cppMask_un_8_);
	cppVar_87047 = cppVar_87055;
	} else {
	BIT_VEC cppVar_87056 = PC + 1;
	cppVar_87056 = (cppVar_87056 & cppMask_un_16_);
	BIT_VEC cppVar_87057 = ROM.rd(cppVar_87056);
	BIT_VEC cppVar_87058 = (cppVar_87057 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_87059 = (cppVar_87058 & cppMask_un_5_);
	BIT_VEC cppVar_87060 = cppVar_87059 + 32;
	cppVar_87060 = (cppVar_87060 & cppMask_un_8_);
	cppVar_87047 = cppVar_87060;
	}
	bool cppVar_87062 = (cppVar_87047 == 224);
	if (cppVar_87062) {
	cppVar_87046 = ACC;
	} else {
	BIT_VEC cppVar_87063;
	BIT_VEC cppVar_87064;
	BIT_VEC cppVar_87065 = PC + 1;
	cppVar_87065 = (cppVar_87065 & cppMask_un_16_);
	BIT_VEC cppVar_87066 = ROM.rd(cppVar_87065);
	BIT_VEC cppVar_87067 = (cppVar_87066 >> 7) & cppMask_un_1_;
	bool cppVar_87068 = (cppVar_87067 == 1);
	if (cppVar_87068) {
	BIT_VEC cppVar_87069 = PC + 1;
	cppVar_87069 = (cppVar_87069 & cppMask_un_16_);
	BIT_VEC cppVar_87070 = ROM.rd(cppVar_87069);
	BIT_VEC cppVar_87071 = (cppVar_87070 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_87072 = (cppVar_87071 << 3) | 0;
	cppVar_87072 = (cppVar_87072 & cppMask_un_8_);
	cppVar_87064 = cppVar_87072;
	} else {
	BIT_VEC cppVar_87073 = PC + 1;
	cppVar_87073 = (cppVar_87073 & cppMask_un_16_);
	BIT_VEC cppVar_87074 = ROM.rd(cppVar_87073);
	BIT_VEC cppVar_87075 = (cppVar_87074 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_87076 = (cppVar_87075 & cppMask_un_5_);
	BIT_VEC cppVar_87077 = cppVar_87076 + 32;
	cppVar_87077 = (cppVar_87077 & cppMask_un_8_);
	cppVar_87064 = cppVar_87077;
	}
	bool cppVar_87079 = (cppVar_87064 == 240);
	if (cppVar_87079) {
	cppVar_87063 = B;
	} else {
	cppVar_87063 = 0;
	}
	cppVar_87046 = cppVar_87063;
	}
	cppVar_87029 = cppVar_87046;
	}
	cppVar_87012 = cppVar_87029;
	}
	cppVar_86995 = cppVar_87012;
	}
	cppVar_86978 = cppVar_86995;
	}
	cppVar_86961 = cppVar_86978;
	}
	cppVar_86944 = cppVar_86961;
	}
	cppVar_86927 = cppVar_86944;
	}
	cppVar_86910 = cppVar_86927;
	}
	cppVar_86893 = cppVar_86910;
	}
	cppVar_86876 = cppVar_86893;
	}
	cppVar_86859 = cppVar_86876;
	}
	cppVar_86842 = cppVar_86859;
	}
	cppVar_86825 = cppVar_86842;
	}
	cppVar_86808 = cppVar_86825;
	}
	cppVar_86791 = cppVar_86808;
	}
	cppVar_86774 = cppVar_86791;
	}
	cppVar_86757 = cppVar_86774;
	}
	cppVar_86740 = cppVar_86757;
	}
	cppVar_86723 = cppVar_86740;
	}
	cppVar_86690 = cppVar_86723;
	}
	BIT_VEC cppVar_87081 = cppVar_86689 & cppVar_86690;
	BIT_VEC cppVar_87083 = 1;
	BIT_VEC cppVar_87084 = PC + 1;
	cppVar_87084 = (cppVar_87084 & cppMask_un_16_);
	BIT_VEC cppVar_87085 = ROM.rd(cppVar_87084);
	BIT_VEC cppVar_87086 = (cppVar_87085 >> 0) & cppMask_un_3_;
	BIT_VEC cppVar_87087 = (cppVar_87086 & cppMask_un_3_);
	BIT_VEC cppVar_87088 = cppVar_87083 << static_cast<unsigned>(cppVar_87087);
	cppVar_87088 = (cppVar_87088 & cppMask_un_8_);
	BIT_VEC cppVar_87089 = cppVar_87081 | cppVar_87088;
	type_mem cppVar_87090 = IRAM;
	cppVar_87090.wr(cppVar_86669, cppVar_87089);
	cppVar_86647 = cppVar_87090;
	} else {
	cppVar_86647 = IRAM;
	}
	cppVar_86643 = cppVar_86647;
	} else {
	type_mem cppVar_87091;
	BIT_VEC cppVar_87092 = ROM.rd(PC);
	bool cppVar_87094 = (cppVar_87092 == 208);
	if (cppVar_87094) {
	type_mem cppVar_87095;
	BIT_VEC cppVar_87097 = PC + 1;
	cppVar_87097 = (cppVar_87097 & cppMask_un_16_);
	BIT_VEC cppVar_87098 = ROM.rd(cppVar_87097);
	BIT_VEC cppVar_87099 = (cppVar_87098 >> 7) & cppMask_un_1_;
	bool cppVar_87101 = (cppVar_87099 == 0);
	if (cppVar_87101) {
	BIT_VEC cppVar_87102 = PC + 1;
	cppVar_87102 = (cppVar_87102 & cppMask_un_16_);
	BIT_VEC cppVar_87103 = ROM.rd(cppVar_87102);
	BIT_VEC cppVar_87104 = IRAM.rd(SP);
	type_mem cppVar_87105 = IRAM;
	cppVar_87105.wr(cppVar_87103, cppVar_87104);
	cppVar_87095 = cppVar_87105;
	} else {
	cppVar_87095 = IRAM;
	}
	cppVar_87091 = cppVar_87095;
	} else {
	type_mem cppVar_87106;
	BIT_VEC cppVar_87107 = ROM.rd(PC);
	bool cppVar_87109 = (cppVar_87107 == 255);
	BIT_VEC cppVar_87110 = ROM.rd(PC);
	bool cppVar_87112 = (cppVar_87110 == 207);
	bool cppVar_87113 = cppVar_87109 || cppVar_87112;
	if (cppVar_87113) {
	type_mem cppVar_87114;
	BIT_VEC cppVar_87116 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_87118 = (cppVar_87116 << 3) | 7;
	cppVar_87118 = (cppVar_87118 & cppMask_un_5_);
	BIT_VEC cppVar_87119 = (0 << 5) | cppVar_87118;
	cppVar_87119 = (cppVar_87119 & cppMask_un_8_);
	BIT_VEC cppVar_87120 = (cppVar_87119 >> 7) & cppMask_un_1_;
	bool cppVar_87122 = (cppVar_87120 == 0);
	if (cppVar_87122) {
	BIT_VEC cppVar_87123 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_87124 = (cppVar_87123 << 3) | 7;
	cppVar_87124 = (cppVar_87124 & cppMask_un_5_);
	BIT_VEC cppVar_87125 = (0 << 5) | cppVar_87124;
	cppVar_87125 = (cppVar_87125 & cppMask_un_8_);
	type_mem cppVar_87126 = IRAM;
	cppVar_87126.wr(cppVar_87125, ACC);
	cppVar_87114 = cppVar_87126;
	} else {
	cppVar_87114 = IRAM;
	}
	cppVar_87106 = cppVar_87114;
	} else {
	type_mem cppVar_87127;
	BIT_VEC cppVar_87128 = ROM.rd(PC);
	bool cppVar_87130 = (cppVar_87128 == 254);
	BIT_VEC cppVar_87131 = ROM.rd(PC);
	bool cppVar_87133 = (cppVar_87131 == 206);
	bool cppVar_87134 = cppVar_87130 || cppVar_87133;
	if (cppVar_87134) {
	type_mem cppVar_87135;
	BIT_VEC cppVar_87137 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_87139 = (cppVar_87137 << 3) | 6;
	cppVar_87139 = (cppVar_87139 & cppMask_un_5_);
	BIT_VEC cppVar_87140 = (0 << 5) | cppVar_87139;
	cppVar_87140 = (cppVar_87140 & cppMask_un_8_);
	BIT_VEC cppVar_87141 = (cppVar_87140 >> 7) & cppMask_un_1_;
	bool cppVar_87143 = (cppVar_87141 == 0);
	if (cppVar_87143) {
	BIT_VEC cppVar_87144 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_87145 = (cppVar_87144 << 3) | 6;
	cppVar_87145 = (cppVar_87145 & cppMask_un_5_);
	BIT_VEC cppVar_87146 = (0 << 5) | cppVar_87145;
	cppVar_87146 = (cppVar_87146 & cppMask_un_8_);
	type_mem cppVar_87147 = IRAM;
	cppVar_87147.wr(cppVar_87146, ACC);
	cppVar_87135 = cppVar_87147;
	} else {
	cppVar_87135 = IRAM;
	}
	cppVar_87127 = cppVar_87135;
	} else {
	type_mem cppVar_87148;
	BIT_VEC cppVar_87149 = ROM.rd(PC);
	bool cppVar_87151 = (cppVar_87149 == 253);
	BIT_VEC cppVar_87152 = ROM.rd(PC);
	bool cppVar_87154 = (cppVar_87152 == 205);
	bool cppVar_87155 = cppVar_87151 || cppVar_87154;
	if (cppVar_87155) {
	type_mem cppVar_87156;
	BIT_VEC cppVar_87158 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_87160 = (cppVar_87158 << 3) | 5;
	cppVar_87160 = (cppVar_87160 & cppMask_un_5_);
	BIT_VEC cppVar_87161 = (0 << 5) | cppVar_87160;
	cppVar_87161 = (cppVar_87161 & cppMask_un_8_);
	BIT_VEC cppVar_87162 = (cppVar_87161 >> 7) & cppMask_un_1_;
	bool cppVar_87164 = (cppVar_87162 == 0);
	if (cppVar_87164) {
	BIT_VEC cppVar_87165 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_87166 = (cppVar_87165 << 3) | 5;
	cppVar_87166 = (cppVar_87166 & cppMask_un_5_);
	BIT_VEC cppVar_87167 = (0 << 5) | cppVar_87166;
	cppVar_87167 = (cppVar_87167 & cppMask_un_8_);
	type_mem cppVar_87168 = IRAM;
	cppVar_87168.wr(cppVar_87167, ACC);
	cppVar_87156 = cppVar_87168;
	} else {
	cppVar_87156 = IRAM;
	}
	cppVar_87148 = cppVar_87156;
	} else {
	type_mem cppVar_87169;
	BIT_VEC cppVar_87170 = ROM.rd(PC);
	bool cppVar_87172 = (cppVar_87170 == 252);
	BIT_VEC cppVar_87173 = ROM.rd(PC);
	bool cppVar_87175 = (cppVar_87173 == 204);
	bool cppVar_87176 = cppVar_87172 || cppVar_87175;
	if (cppVar_87176) {
	type_mem cppVar_87177;
	BIT_VEC cppVar_87179 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_87181 = (cppVar_87179 << 3) | 4;
	cppVar_87181 = (cppVar_87181 & cppMask_un_5_);
	BIT_VEC cppVar_87182 = (0 << 5) | cppVar_87181;
	cppVar_87182 = (cppVar_87182 & cppMask_un_8_);
	BIT_VEC cppVar_87183 = (cppVar_87182 >> 7) & cppMask_un_1_;
	bool cppVar_87185 = (cppVar_87183 == 0);
	if (cppVar_87185) {
	BIT_VEC cppVar_87186 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_87187 = (cppVar_87186 << 3) | 4;
	cppVar_87187 = (cppVar_87187 & cppMask_un_5_);
	BIT_VEC cppVar_87188 = (0 << 5) | cppVar_87187;
	cppVar_87188 = (cppVar_87188 & cppMask_un_8_);
	type_mem cppVar_87189 = IRAM;
	cppVar_87189.wr(cppVar_87188, ACC);
	cppVar_87177 = cppVar_87189;
	} else {
	cppVar_87177 = IRAM;
	}
	cppVar_87169 = cppVar_87177;
	} else {
	type_mem cppVar_87190;
	BIT_VEC cppVar_87191 = ROM.rd(PC);
	bool cppVar_87193 = (cppVar_87191 == 251);
	BIT_VEC cppVar_87194 = ROM.rd(PC);
	bool cppVar_87196 = (cppVar_87194 == 203);
	bool cppVar_87197 = cppVar_87193 || cppVar_87196;
	if (cppVar_87197) {
	type_mem cppVar_87198;
	BIT_VEC cppVar_87200 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_87202 = (cppVar_87200 << 3) | 3;
	cppVar_87202 = (cppVar_87202 & cppMask_un_5_);
	BIT_VEC cppVar_87203 = (0 << 5) | cppVar_87202;
	cppVar_87203 = (cppVar_87203 & cppMask_un_8_);
	BIT_VEC cppVar_87204 = (cppVar_87203 >> 7) & cppMask_un_1_;
	bool cppVar_87206 = (cppVar_87204 == 0);
	if (cppVar_87206) {
	BIT_VEC cppVar_87207 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_87208 = (cppVar_87207 << 3) | 3;
	cppVar_87208 = (cppVar_87208 & cppMask_un_5_);
	BIT_VEC cppVar_87209 = (0 << 5) | cppVar_87208;
	cppVar_87209 = (cppVar_87209 & cppMask_un_8_);
	type_mem cppVar_87210 = IRAM;
	cppVar_87210.wr(cppVar_87209, ACC);
	cppVar_87198 = cppVar_87210;
	} else {
	cppVar_87198 = IRAM;
	}
	cppVar_87190 = cppVar_87198;
	} else {
	type_mem cppVar_87211;
	BIT_VEC cppVar_87212 = ROM.rd(PC);
	bool cppVar_87214 = (cppVar_87212 == 250);
	BIT_VEC cppVar_87215 = ROM.rd(PC);
	bool cppVar_87217 = (cppVar_87215 == 202);
	bool cppVar_87218 = cppVar_87214 || cppVar_87217;
	if (cppVar_87218) {
	type_mem cppVar_87219;
	BIT_VEC cppVar_87221 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_87223 = (cppVar_87221 << 3) | 2;
	cppVar_87223 = (cppVar_87223 & cppMask_un_5_);
	BIT_VEC cppVar_87224 = (0 << 5) | cppVar_87223;
	cppVar_87224 = (cppVar_87224 & cppMask_un_8_);
	BIT_VEC cppVar_87225 = (cppVar_87224 >> 7) & cppMask_un_1_;
	bool cppVar_87227 = (cppVar_87225 == 0);
	if (cppVar_87227) {
	BIT_VEC cppVar_87228 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_87229 = (cppVar_87228 << 3) | 2;
	cppVar_87229 = (cppVar_87229 & cppMask_un_5_);
	BIT_VEC cppVar_87230 = (0 << 5) | cppVar_87229;
	cppVar_87230 = (cppVar_87230 & cppMask_un_8_);
	type_mem cppVar_87231 = IRAM;
	cppVar_87231.wr(cppVar_87230, ACC);
	cppVar_87219 = cppVar_87231;
	} else {
	cppVar_87219 = IRAM;
	}
	cppVar_87211 = cppVar_87219;
	} else {
	type_mem cppVar_87232;
	BIT_VEC cppVar_87233 = ROM.rd(PC);
	bool cppVar_87235 = (cppVar_87233 == 249);
	BIT_VEC cppVar_87236 = ROM.rd(PC);
	bool cppVar_87238 = (cppVar_87236 == 201);
	bool cppVar_87239 = cppVar_87235 || cppVar_87238;
	if (cppVar_87239) {
	type_mem cppVar_87240;
	BIT_VEC cppVar_87242 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_87244 = (cppVar_87242 << 3) | 1;
	cppVar_87244 = (cppVar_87244 & cppMask_un_5_);
	BIT_VEC cppVar_87245 = (0 << 5) | cppVar_87244;
	cppVar_87245 = (cppVar_87245 & cppMask_un_8_);
	BIT_VEC cppVar_87246 = (cppVar_87245 >> 7) & cppMask_un_1_;
	bool cppVar_87248 = (cppVar_87246 == 0);
	if (cppVar_87248) {
	BIT_VEC cppVar_87249 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_87250 = (cppVar_87249 << 3) | 1;
	cppVar_87250 = (cppVar_87250 & cppMask_un_5_);
	BIT_VEC cppVar_87251 = (0 << 5) | cppVar_87250;
	cppVar_87251 = (cppVar_87251 & cppMask_un_8_);
	type_mem cppVar_87252 = IRAM;
	cppVar_87252.wr(cppVar_87251, ACC);
	cppVar_87240 = cppVar_87252;
	} else {
	cppVar_87240 = IRAM;
	}
	cppVar_87232 = cppVar_87240;
	} else {
	type_mem cppVar_87253;
	BIT_VEC cppVar_87254 = ROM.rd(PC);
	bool cppVar_87256 = (cppVar_87254 == 248);
	BIT_VEC cppVar_87257 = ROM.rd(PC);
	bool cppVar_87259 = (cppVar_87257 == 200);
	bool cppVar_87260 = cppVar_87256 || cppVar_87259;
	if (cppVar_87260) {
	type_mem cppVar_87261;
	BIT_VEC cppVar_87263 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_87265 = (cppVar_87263 << 3) | 0;
	cppVar_87265 = (cppVar_87265 & cppMask_un_5_);
	BIT_VEC cppVar_87266 = (0 << 5) | cppVar_87265;
	cppVar_87266 = (cppVar_87266 & cppMask_un_8_);
	BIT_VEC cppVar_87267 = (cppVar_87266 >> 7) & cppMask_un_1_;
	bool cppVar_87269 = (cppVar_87267 == 0);
	if (cppVar_87269) {
	BIT_VEC cppVar_87270 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_87271 = (cppVar_87270 << 3) | 0;
	cppVar_87271 = (cppVar_87271 & cppMask_un_5_);
	BIT_VEC cppVar_87272 = (0 << 5) | cppVar_87271;
	cppVar_87272 = (cppVar_87272 & cppMask_un_8_);
	type_mem cppVar_87273 = IRAM;
	cppVar_87273.wr(cppVar_87272, ACC);
	cppVar_87261 = cppVar_87273;
	} else {
	cppVar_87261 = IRAM;
	}
	cppVar_87253 = cppVar_87261;
	} else {
	type_mem cppVar_87274;
	BIT_VEC cppVar_87275 = ROM.rd(PC);
	bool cppVar_87277 = (cppVar_87275 == 247);
	BIT_VEC cppVar_87278 = ROM.rd(PC);
	bool cppVar_87280 = (cppVar_87278 == 199);
	bool cppVar_87281 = cppVar_87277 || cppVar_87280;
	if (cppVar_87281) {
	BIT_VEC cppVar_87283 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_87285 = (cppVar_87283 << 3) | 1;
	cppVar_87285 = (cppVar_87285 & cppMask_un_5_);
	BIT_VEC cppVar_87286 = (0 << 5) | cppVar_87285;
	cppVar_87286 = (cppVar_87286 & cppMask_un_8_);
	BIT_VEC cppVar_87287 = IRAM.rd(cppVar_87286);
	type_mem cppVar_87288 = IRAM;
	cppVar_87288.wr(cppVar_87287, ACC);
	cppVar_87274 = cppVar_87288;
	} else {
	type_mem cppVar_87289;
	BIT_VEC cppVar_87290 = ROM.rd(PC);
	bool cppVar_87292 = (cppVar_87290 == 246);
	BIT_VEC cppVar_87293 = ROM.rd(PC);
	bool cppVar_87295 = (cppVar_87293 == 198);
	bool cppVar_87296 = cppVar_87292 || cppVar_87295;
	if (cppVar_87296) {
	BIT_VEC cppVar_87298 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_87300 = (cppVar_87298 << 3) | 0;
	cppVar_87300 = (cppVar_87300 & cppMask_un_5_);
	BIT_VEC cppVar_87301 = (0 << 5) | cppVar_87300;
	cppVar_87301 = (cppVar_87301 & cppMask_un_8_);
	BIT_VEC cppVar_87302 = IRAM.rd(cppVar_87301);
	type_mem cppVar_87303 = IRAM;
	cppVar_87303.wr(cppVar_87302, ACC);
	cppVar_87289 = cppVar_87303;
	} else {
	type_mem cppVar_87304;
	BIT_VEC cppVar_87305 = ROM.rd(PC);
	bool cppVar_87307 = (cppVar_87305 == 245);
	BIT_VEC cppVar_87308 = ROM.rd(PC);
	bool cppVar_87310 = (cppVar_87308 == 197);
	bool cppVar_87311 = cppVar_87307 || cppVar_87310;
	if (cppVar_87311) {
	type_mem cppVar_87312;
	BIT_VEC cppVar_87314 = PC + 1;
	cppVar_87314 = (cppVar_87314 & cppMask_un_16_);
	BIT_VEC cppVar_87315 = ROM.rd(cppVar_87314);
	BIT_VEC cppVar_87316 = (cppVar_87315 >> 7) & cppMask_un_1_;
	bool cppVar_87318 = (cppVar_87316 == 0);
	if (cppVar_87318) {
	BIT_VEC cppVar_87319 = PC + 1;
	cppVar_87319 = (cppVar_87319 & cppMask_un_16_);
	BIT_VEC cppVar_87320 = ROM.rd(cppVar_87319);
	type_mem cppVar_87321 = IRAM;
	cppVar_87321.wr(cppVar_87320, ACC);
	cppVar_87312 = cppVar_87321;
	} else {
	cppVar_87312 = IRAM;
	}
	cppVar_87304 = cppVar_87312;
	} else {
	type_mem cppVar_87322;
	BIT_VEC cppVar_87323 = ROM.rd(PC);
	bool cppVar_87325 = (cppVar_87323 == 192);
	if (cppVar_87325) {
	BIT_VEC cppVar_87327 = SP + 1;
	cppVar_87327 = (cppVar_87327 & cppMask_un_8_);
	BIT_VEC cppVar_87328;
	BIT_VEC cppVar_87330 = PC + 1;
	cppVar_87330 = (cppVar_87330 & cppMask_un_16_);
	BIT_VEC cppVar_87331 = ROM.rd(cppVar_87330);
	BIT_VEC cppVar_87332 = (cppVar_87331 >> 7) & cppMask_un_1_;
	bool cppVar_87334 = (cppVar_87332 == 0);
	if (cppVar_87334) {
	BIT_VEC cppVar_87335 = PC + 1;
	cppVar_87335 = (cppVar_87335 & cppMask_un_16_);
	BIT_VEC cppVar_87336 = ROM.rd(cppVar_87335);
	BIT_VEC cppVar_87337 = IRAM.rd(cppVar_87336);
	cppVar_87328 = cppVar_87337;
	} else {
	BIT_VEC cppVar_87338;
	BIT_VEC cppVar_87339 = PC + 1;
	cppVar_87339 = (cppVar_87339 & cppMask_un_16_);
	BIT_VEC cppVar_87340 = ROM.rd(cppVar_87339);
	bool cppVar_87342 = (cppVar_87340 == 128);
	if (cppVar_87342) {
	cppVar_87338 = P0;
	} else {
	BIT_VEC cppVar_87343;
	BIT_VEC cppVar_87344 = PC + 1;
	cppVar_87344 = (cppVar_87344 & cppMask_un_16_);
	BIT_VEC cppVar_87345 = ROM.rd(cppVar_87344);
	bool cppVar_87347 = (cppVar_87345 == 129);
	if (cppVar_87347) {
	cppVar_87343 = SP;
	} else {
	BIT_VEC cppVar_87348;
	BIT_VEC cppVar_87349 = PC + 1;
	cppVar_87349 = (cppVar_87349 & cppMask_un_16_);
	BIT_VEC cppVar_87350 = ROM.rd(cppVar_87349);
	bool cppVar_87352 = (cppVar_87350 == 130);
	if (cppVar_87352) {
	cppVar_87348 = DPL;
	} else {
	BIT_VEC cppVar_87353;
	BIT_VEC cppVar_87354 = PC + 1;
	cppVar_87354 = (cppVar_87354 & cppMask_un_16_);
	BIT_VEC cppVar_87355 = ROM.rd(cppVar_87354);
	bool cppVar_87357 = (cppVar_87355 == 131);
	if (cppVar_87357) {
	cppVar_87353 = DPH;
	} else {
	BIT_VEC cppVar_87358;
	BIT_VEC cppVar_87359 = PC + 1;
	cppVar_87359 = (cppVar_87359 & cppMask_un_16_);
	BIT_VEC cppVar_87360 = ROM.rd(cppVar_87359);
	bool cppVar_87362 = (cppVar_87360 == 135);
	if (cppVar_87362) {
	cppVar_87358 = PCON;
	} else {
	BIT_VEC cppVar_87363;
	BIT_VEC cppVar_87364 = PC + 1;
	cppVar_87364 = (cppVar_87364 & cppMask_un_16_);
	BIT_VEC cppVar_87365 = ROM.rd(cppVar_87364);
	bool cppVar_87367 = (cppVar_87365 == 136);
	if (cppVar_87367) {
	cppVar_87363 = TCON;
	} else {
	BIT_VEC cppVar_87368;
	BIT_VEC cppVar_87369 = PC + 1;
	cppVar_87369 = (cppVar_87369 & cppMask_un_16_);
	BIT_VEC cppVar_87370 = ROM.rd(cppVar_87369);
	bool cppVar_87372 = (cppVar_87370 == 137);
	if (cppVar_87372) {
	cppVar_87368 = TMOD;
	} else {
	BIT_VEC cppVar_87373;
	BIT_VEC cppVar_87374 = PC + 1;
	cppVar_87374 = (cppVar_87374 & cppMask_un_16_);
	BIT_VEC cppVar_87375 = ROM.rd(cppVar_87374);
	bool cppVar_87377 = (cppVar_87375 == 138);
	if (cppVar_87377) {
	cppVar_87373 = TL0;
	} else {
	BIT_VEC cppVar_87378;
	BIT_VEC cppVar_87379 = PC + 1;
	cppVar_87379 = (cppVar_87379 & cppMask_un_16_);
	BIT_VEC cppVar_87380 = ROM.rd(cppVar_87379);
	bool cppVar_87382 = (cppVar_87380 == 140);
	if (cppVar_87382) {
	cppVar_87378 = TH0;
	} else {
	BIT_VEC cppVar_87383;
	BIT_VEC cppVar_87384 = PC + 1;
	cppVar_87384 = (cppVar_87384 & cppMask_un_16_);
	BIT_VEC cppVar_87385 = ROM.rd(cppVar_87384);
	bool cppVar_87387 = (cppVar_87385 == 139);
	if (cppVar_87387) {
	cppVar_87383 = TL1;
	} else {
	BIT_VEC cppVar_87388;
	BIT_VEC cppVar_87389 = PC + 1;
	cppVar_87389 = (cppVar_87389 & cppMask_un_16_);
	BIT_VEC cppVar_87390 = ROM.rd(cppVar_87389);
	bool cppVar_87392 = (cppVar_87390 == 141);
	if (cppVar_87392) {
	cppVar_87388 = TH1;
	} else {
	BIT_VEC cppVar_87393;
	BIT_VEC cppVar_87394 = PC + 1;
	cppVar_87394 = (cppVar_87394 & cppMask_un_16_);
	BIT_VEC cppVar_87395 = ROM.rd(cppVar_87394);
	bool cppVar_87397 = (cppVar_87395 == 144);
	if (cppVar_87397) {
	cppVar_87393 = P1;
	} else {
	BIT_VEC cppVar_87398;
	BIT_VEC cppVar_87399 = PC + 1;
	cppVar_87399 = (cppVar_87399 & cppMask_un_16_);
	BIT_VEC cppVar_87400 = ROM.rd(cppVar_87399);
	bool cppVar_87402 = (cppVar_87400 == 152);
	if (cppVar_87402) {
	cppVar_87398 = SCON;
	} else {
	BIT_VEC cppVar_87403;
	BIT_VEC cppVar_87404 = PC + 1;
	cppVar_87404 = (cppVar_87404 & cppMask_un_16_);
	BIT_VEC cppVar_87405 = ROM.rd(cppVar_87404);
	bool cppVar_87407 = (cppVar_87405 == 153);
	if (cppVar_87407) {
	cppVar_87403 = SBUF;
	} else {
	BIT_VEC cppVar_87408;
	BIT_VEC cppVar_87409 = PC + 1;
	cppVar_87409 = (cppVar_87409 & cppMask_un_16_);
	BIT_VEC cppVar_87410 = ROM.rd(cppVar_87409);
	bool cppVar_87412 = (cppVar_87410 == 160);
	if (cppVar_87412) {
	cppVar_87408 = P2;
	} else {
	BIT_VEC cppVar_87413;
	BIT_VEC cppVar_87414 = PC + 1;
	cppVar_87414 = (cppVar_87414 & cppMask_un_16_);
	BIT_VEC cppVar_87415 = ROM.rd(cppVar_87414);
	bool cppVar_87417 = (cppVar_87415 == 168);
	if (cppVar_87417) {
	cppVar_87413 = IE;
	} else {
	BIT_VEC cppVar_87418;
	BIT_VEC cppVar_87419 = PC + 1;
	cppVar_87419 = (cppVar_87419 & cppMask_un_16_);
	BIT_VEC cppVar_87420 = ROM.rd(cppVar_87419);
	bool cppVar_87422 = (cppVar_87420 == 176);
	if (cppVar_87422) {
	cppVar_87418 = P3;
	} else {
	BIT_VEC cppVar_87423;
	BIT_VEC cppVar_87424 = PC + 1;
	cppVar_87424 = (cppVar_87424 & cppMask_un_16_);
	BIT_VEC cppVar_87425 = ROM.rd(cppVar_87424);
	bool cppVar_87427 = (cppVar_87425 == 184);
	if (cppVar_87427) {
	cppVar_87423 = IP;
	} else {
	BIT_VEC cppVar_87428;
	BIT_VEC cppVar_87429 = PC + 1;
	cppVar_87429 = (cppVar_87429 & cppMask_un_16_);
	BIT_VEC cppVar_87430 = ROM.rd(cppVar_87429);
	bool cppVar_87432 = (cppVar_87430 == 208);
	if (cppVar_87432) {
	cppVar_87428 = PSW;
	} else {
	BIT_VEC cppVar_87433;
	BIT_VEC cppVar_87434 = PC + 1;
	cppVar_87434 = (cppVar_87434 & cppMask_un_16_);
	BIT_VEC cppVar_87435 = ROM.rd(cppVar_87434);
	bool cppVar_87437 = (cppVar_87435 == 224);
	if (cppVar_87437) {
	cppVar_87433 = ACC;
	} else {
	BIT_VEC cppVar_87438;
	BIT_VEC cppVar_87439 = PC + 1;
	cppVar_87439 = (cppVar_87439 & cppMask_un_16_);
	BIT_VEC cppVar_87440 = ROM.rd(cppVar_87439);
	bool cppVar_87442 = (cppVar_87440 == 240);
	if (cppVar_87442) {
	cppVar_87438 = B;
	} else {
	cppVar_87438 = 0;
	}
	cppVar_87433 = cppVar_87438;
	}
	cppVar_87428 = cppVar_87433;
	}
	cppVar_87423 = cppVar_87428;
	}
	cppVar_87418 = cppVar_87423;
	}
	cppVar_87413 = cppVar_87418;
	}
	cppVar_87408 = cppVar_87413;
	}
	cppVar_87403 = cppVar_87408;
	}
	cppVar_87398 = cppVar_87403;
	}
	cppVar_87393 = cppVar_87398;
	}
	cppVar_87388 = cppVar_87393;
	}
	cppVar_87383 = cppVar_87388;
	}
	cppVar_87378 = cppVar_87383;
	}
	cppVar_87373 = cppVar_87378;
	}
	cppVar_87368 = cppVar_87373;
	}
	cppVar_87363 = cppVar_87368;
	}
	cppVar_87358 = cppVar_87363;
	}
	cppVar_87353 = cppVar_87358;
	}
	cppVar_87348 = cppVar_87353;
	}
	cppVar_87343 = cppVar_87348;
	}
	cppVar_87338 = cppVar_87343;
	}
	cppVar_87328 = cppVar_87338;
	}
	type_mem cppVar_87444 = IRAM;
	cppVar_87444.wr(cppVar_87327, cppVar_87328);
	cppVar_87322 = cppVar_87444;
	} else {
	type_mem cppVar_87445;
	BIT_VEC cppVar_87446 = ROM.rd(PC);
	bool cppVar_87448 = (cppVar_87446 == 178);
	if (cppVar_87448) {
	type_mem cppVar_87449;
	BIT_VEC cppVar_87450;
	BIT_VEC cppVar_87452 = PC + 1;
	cppVar_87452 = (cppVar_87452 & cppMask_un_16_);
	BIT_VEC cppVar_87453 = ROM.rd(cppVar_87452);
	BIT_VEC cppVar_87454 = (cppVar_87453 >> 7) & cppMask_un_1_;
	bool cppVar_87456 = (cppVar_87454 == 1);
	if (cppVar_87456) {
	BIT_VEC cppVar_87457 = PC + 1;
	cppVar_87457 = (cppVar_87457 & cppMask_un_16_);
	BIT_VEC cppVar_87458 = ROM.rd(cppVar_87457);
	BIT_VEC cppVar_87459 = (cppVar_87458 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_87461 = (cppVar_87459 << 3) | 0;
	cppVar_87461 = (cppVar_87461 & cppMask_un_8_);
	cppVar_87450 = cppVar_87461;
	} else {
	BIT_VEC cppVar_87462 = PC + 1;
	cppVar_87462 = (cppVar_87462 & cppMask_un_16_);
	BIT_VEC cppVar_87463 = ROM.rd(cppVar_87462);
	BIT_VEC cppVar_87464 = (cppVar_87463 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_87465 = (cppVar_87464 & cppMask_un_5_);
	BIT_VEC cppVar_87467 = cppVar_87465 + 32;
	cppVar_87467 = (cppVar_87467 & cppMask_un_8_);
	cppVar_87450 = cppVar_87467;
	}
	BIT_VEC cppVar_87468 = (cppVar_87450 >> 7) & cppMask_un_1_;
	bool cppVar_87470 = (cppVar_87468 == 0);
	if (cppVar_87470) {
	BIT_VEC cppVar_87471;
	BIT_VEC cppVar_87472 = PC + 1;
	cppVar_87472 = (cppVar_87472 & cppMask_un_16_);
	BIT_VEC cppVar_87473 = ROM.rd(cppVar_87472);
	BIT_VEC cppVar_87474 = (cppVar_87473 >> 7) & cppMask_un_1_;
	bool cppVar_87475 = (cppVar_87474 == 1);
	if (cppVar_87475) {
	BIT_VEC cppVar_87476 = PC + 1;
	cppVar_87476 = (cppVar_87476 & cppMask_un_16_);
	BIT_VEC cppVar_87477 = ROM.rd(cppVar_87476);
	BIT_VEC cppVar_87478 = (cppVar_87477 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_87479 = (cppVar_87478 << 3) | 0;
	cppVar_87479 = (cppVar_87479 & cppMask_un_8_);
	cppVar_87471 = cppVar_87479;
	} else {
	BIT_VEC cppVar_87480 = PC + 1;
	cppVar_87480 = (cppVar_87480 & cppMask_un_16_);
	BIT_VEC cppVar_87481 = ROM.rd(cppVar_87480);
	BIT_VEC cppVar_87482 = (cppVar_87481 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_87483 = (cppVar_87482 & cppMask_un_5_);
	BIT_VEC cppVar_87484 = cppVar_87483 + 32;
	cppVar_87484 = (cppVar_87484 & cppMask_un_8_);
	cppVar_87471 = cppVar_87484;
	}
	BIT_VEC cppVar_87486 = PC + 1;
	cppVar_87486 = (cppVar_87486 & cppMask_un_16_);
	BIT_VEC cppVar_87487 = ROM.rd(cppVar_87486);
	BIT_VEC cppVar_87488 = (cppVar_87487 >> 0) & cppMask_un_3_;
	BIT_VEC cppVar_87489 = (cppVar_87488 & cppMask_un_3_);
	BIT_VEC cppVar_87490 = 1 << static_cast<unsigned>(cppVar_87489);
	cppVar_87490 = (cppVar_87490 & cppMask_un_8_);
	BIT_VEC cppVar_87491 = ~cppVar_87490;
	BIT_VEC cppVar_87492;
	BIT_VEC cppVar_87493;
	BIT_VEC cppVar_87494 = PC + 1;
	cppVar_87494 = (cppVar_87494 & cppMask_un_16_);
	BIT_VEC cppVar_87495 = ROM.rd(cppVar_87494);
	BIT_VEC cppVar_87496 = (cppVar_87495 >> 7) & cppMask_un_1_;
	bool cppVar_87497 = (cppVar_87496 == 1);
	if (cppVar_87497) {
	BIT_VEC cppVar_87498 = PC + 1;
	cppVar_87498 = (cppVar_87498 & cppMask_un_16_);
	BIT_VEC cppVar_87499 = ROM.rd(cppVar_87498);
	BIT_VEC cppVar_87500 = (cppVar_87499 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_87501 = (cppVar_87500 << 3) | 0;
	cppVar_87501 = (cppVar_87501 & cppMask_un_8_);
	cppVar_87493 = cppVar_87501;
	} else {
	BIT_VEC cppVar_87502 = PC + 1;
	cppVar_87502 = (cppVar_87502 & cppMask_un_16_);
	BIT_VEC cppVar_87503 = ROM.rd(cppVar_87502);
	BIT_VEC cppVar_87504 = (cppVar_87503 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_87505 = (cppVar_87504 & cppMask_un_5_);
	BIT_VEC cppVar_87506 = cppVar_87505 + 32;
	cppVar_87506 = (cppVar_87506 & cppMask_un_8_);
	cppVar_87493 = cppVar_87506;
	}
	BIT_VEC cppVar_87507 = (cppVar_87493 >> 7) & cppMask_un_1_;
	bool cppVar_87509 = (cppVar_87507 == 0);
	if (cppVar_87509) {
	BIT_VEC cppVar_87510;
	BIT_VEC cppVar_87511 = PC + 1;
	cppVar_87511 = (cppVar_87511 & cppMask_un_16_);
	BIT_VEC cppVar_87512 = ROM.rd(cppVar_87511);
	BIT_VEC cppVar_87513 = (cppVar_87512 >> 7) & cppMask_un_1_;
	bool cppVar_87514 = (cppVar_87513 == 1);
	if (cppVar_87514) {
	BIT_VEC cppVar_87515 = PC + 1;
	cppVar_87515 = (cppVar_87515 & cppMask_un_16_);
	BIT_VEC cppVar_87516 = ROM.rd(cppVar_87515);
	BIT_VEC cppVar_87517 = (cppVar_87516 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_87518 = (cppVar_87517 << 3) | 0;
	cppVar_87518 = (cppVar_87518 & cppMask_un_8_);
	cppVar_87510 = cppVar_87518;
	} else {
	BIT_VEC cppVar_87519 = PC + 1;
	cppVar_87519 = (cppVar_87519 & cppMask_un_16_);
	BIT_VEC cppVar_87520 = ROM.rd(cppVar_87519);
	BIT_VEC cppVar_87521 = (cppVar_87520 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_87522 = (cppVar_87521 & cppMask_un_5_);
	BIT_VEC cppVar_87523 = cppVar_87522 + 32;
	cppVar_87523 = (cppVar_87523 & cppMask_un_8_);
	cppVar_87510 = cppVar_87523;
	}
	BIT_VEC cppVar_87524 = IRAM.rd(cppVar_87510);
	cppVar_87492 = cppVar_87524;
	} else {
	BIT_VEC cppVar_87525;
	BIT_VEC cppVar_87526;
	BIT_VEC cppVar_87527 = PC + 1;
	cppVar_87527 = (cppVar_87527 & cppMask_un_16_);
	BIT_VEC cppVar_87528 = ROM.rd(cppVar_87527);
	BIT_VEC cppVar_87529 = (cppVar_87528 >> 7) & cppMask_un_1_;
	bool cppVar_87530 = (cppVar_87529 == 1);
	if (cppVar_87530) {
	BIT_VEC cppVar_87531 = PC + 1;
	cppVar_87531 = (cppVar_87531 & cppMask_un_16_);
	BIT_VEC cppVar_87532 = ROM.rd(cppVar_87531);
	BIT_VEC cppVar_87533 = (cppVar_87532 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_87534 = (cppVar_87533 << 3) | 0;
	cppVar_87534 = (cppVar_87534 & cppMask_un_8_);
	cppVar_87526 = cppVar_87534;
	} else {
	BIT_VEC cppVar_87535 = PC + 1;
	cppVar_87535 = (cppVar_87535 & cppMask_un_16_);
	BIT_VEC cppVar_87536 = ROM.rd(cppVar_87535);
	BIT_VEC cppVar_87537 = (cppVar_87536 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_87538 = (cppVar_87537 & cppMask_un_5_);
	BIT_VEC cppVar_87539 = cppVar_87538 + 32;
	cppVar_87539 = (cppVar_87539 & cppMask_un_8_);
	cppVar_87526 = cppVar_87539;
	}
	bool cppVar_87541 = (cppVar_87526 == 128);
	if (cppVar_87541) {
	cppVar_87525 = P0;
	} else {
	BIT_VEC cppVar_87542;
	BIT_VEC cppVar_87543;
	BIT_VEC cppVar_87544 = PC + 1;
	cppVar_87544 = (cppVar_87544 & cppMask_un_16_);
	BIT_VEC cppVar_87545 = ROM.rd(cppVar_87544);
	BIT_VEC cppVar_87546 = (cppVar_87545 >> 7) & cppMask_un_1_;
	bool cppVar_87547 = (cppVar_87546 == 1);
	if (cppVar_87547) {
	BIT_VEC cppVar_87548 = PC + 1;
	cppVar_87548 = (cppVar_87548 & cppMask_un_16_);
	BIT_VEC cppVar_87549 = ROM.rd(cppVar_87548);
	BIT_VEC cppVar_87550 = (cppVar_87549 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_87551 = (cppVar_87550 << 3) | 0;
	cppVar_87551 = (cppVar_87551 & cppMask_un_8_);
	cppVar_87543 = cppVar_87551;
	} else {
	BIT_VEC cppVar_87552 = PC + 1;
	cppVar_87552 = (cppVar_87552 & cppMask_un_16_);
	BIT_VEC cppVar_87553 = ROM.rd(cppVar_87552);
	BIT_VEC cppVar_87554 = (cppVar_87553 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_87555 = (cppVar_87554 & cppMask_un_5_);
	BIT_VEC cppVar_87556 = cppVar_87555 + 32;
	cppVar_87556 = (cppVar_87556 & cppMask_un_8_);
	cppVar_87543 = cppVar_87556;
	}
	bool cppVar_87558 = (cppVar_87543 == 129);
	if (cppVar_87558) {
	cppVar_87542 = SP;
	} else {
	BIT_VEC cppVar_87559;
	BIT_VEC cppVar_87560;
	BIT_VEC cppVar_87561 = PC + 1;
	cppVar_87561 = (cppVar_87561 & cppMask_un_16_);
	BIT_VEC cppVar_87562 = ROM.rd(cppVar_87561);
	BIT_VEC cppVar_87563 = (cppVar_87562 >> 7) & cppMask_un_1_;
	bool cppVar_87564 = (cppVar_87563 == 1);
	if (cppVar_87564) {
	BIT_VEC cppVar_87565 = PC + 1;
	cppVar_87565 = (cppVar_87565 & cppMask_un_16_);
	BIT_VEC cppVar_87566 = ROM.rd(cppVar_87565);
	BIT_VEC cppVar_87567 = (cppVar_87566 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_87568 = (cppVar_87567 << 3) | 0;
	cppVar_87568 = (cppVar_87568 & cppMask_un_8_);
	cppVar_87560 = cppVar_87568;
	} else {
	BIT_VEC cppVar_87569 = PC + 1;
	cppVar_87569 = (cppVar_87569 & cppMask_un_16_);
	BIT_VEC cppVar_87570 = ROM.rd(cppVar_87569);
	BIT_VEC cppVar_87571 = (cppVar_87570 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_87572 = (cppVar_87571 & cppMask_un_5_);
	BIT_VEC cppVar_87573 = cppVar_87572 + 32;
	cppVar_87573 = (cppVar_87573 & cppMask_un_8_);
	cppVar_87560 = cppVar_87573;
	}
	bool cppVar_87575 = (cppVar_87560 == 130);
	if (cppVar_87575) {
	cppVar_87559 = DPL;
	} else {
	BIT_VEC cppVar_87576;
	BIT_VEC cppVar_87577;
	BIT_VEC cppVar_87578 = PC + 1;
	cppVar_87578 = (cppVar_87578 & cppMask_un_16_);
	BIT_VEC cppVar_87579 = ROM.rd(cppVar_87578);
	BIT_VEC cppVar_87580 = (cppVar_87579 >> 7) & cppMask_un_1_;
	bool cppVar_87581 = (cppVar_87580 == 1);
	if (cppVar_87581) {
	BIT_VEC cppVar_87582 = PC + 1;
	cppVar_87582 = (cppVar_87582 & cppMask_un_16_);
	BIT_VEC cppVar_87583 = ROM.rd(cppVar_87582);
	BIT_VEC cppVar_87584 = (cppVar_87583 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_87585 = (cppVar_87584 << 3) | 0;
	cppVar_87585 = (cppVar_87585 & cppMask_un_8_);
	cppVar_87577 = cppVar_87585;
	} else {
	BIT_VEC cppVar_87586 = PC + 1;
	cppVar_87586 = (cppVar_87586 & cppMask_un_16_);
	BIT_VEC cppVar_87587 = ROM.rd(cppVar_87586);
	BIT_VEC cppVar_87588 = (cppVar_87587 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_87589 = (cppVar_87588 & cppMask_un_5_);
	BIT_VEC cppVar_87590 = cppVar_87589 + 32;
	cppVar_87590 = (cppVar_87590 & cppMask_un_8_);
	cppVar_87577 = cppVar_87590;
	}
	bool cppVar_87592 = (cppVar_87577 == 131);
	if (cppVar_87592) {
	cppVar_87576 = DPH;
	} else {
	BIT_VEC cppVar_87593;
	BIT_VEC cppVar_87594;
	BIT_VEC cppVar_87595 = PC + 1;
	cppVar_87595 = (cppVar_87595 & cppMask_un_16_);
	BIT_VEC cppVar_87596 = ROM.rd(cppVar_87595);
	BIT_VEC cppVar_87597 = (cppVar_87596 >> 7) & cppMask_un_1_;
	bool cppVar_87598 = (cppVar_87597 == 1);
	if (cppVar_87598) {
	BIT_VEC cppVar_87599 = PC + 1;
	cppVar_87599 = (cppVar_87599 & cppMask_un_16_);
	BIT_VEC cppVar_87600 = ROM.rd(cppVar_87599);
	BIT_VEC cppVar_87601 = (cppVar_87600 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_87602 = (cppVar_87601 << 3) | 0;
	cppVar_87602 = (cppVar_87602 & cppMask_un_8_);
	cppVar_87594 = cppVar_87602;
	} else {
	BIT_VEC cppVar_87603 = PC + 1;
	cppVar_87603 = (cppVar_87603 & cppMask_un_16_);
	BIT_VEC cppVar_87604 = ROM.rd(cppVar_87603);
	BIT_VEC cppVar_87605 = (cppVar_87604 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_87606 = (cppVar_87605 & cppMask_un_5_);
	BIT_VEC cppVar_87607 = cppVar_87606 + 32;
	cppVar_87607 = (cppVar_87607 & cppMask_un_8_);
	cppVar_87594 = cppVar_87607;
	}
	bool cppVar_87609 = (cppVar_87594 == 135);
	if (cppVar_87609) {
	cppVar_87593 = PCON;
	} else {
	BIT_VEC cppVar_87610;
	BIT_VEC cppVar_87611;
	BIT_VEC cppVar_87612 = PC + 1;
	cppVar_87612 = (cppVar_87612 & cppMask_un_16_);
	BIT_VEC cppVar_87613 = ROM.rd(cppVar_87612);
	BIT_VEC cppVar_87614 = (cppVar_87613 >> 7) & cppMask_un_1_;
	bool cppVar_87615 = (cppVar_87614 == 1);
	if (cppVar_87615) {
	BIT_VEC cppVar_87616 = PC + 1;
	cppVar_87616 = (cppVar_87616 & cppMask_un_16_);
	BIT_VEC cppVar_87617 = ROM.rd(cppVar_87616);
	BIT_VEC cppVar_87618 = (cppVar_87617 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_87619 = (cppVar_87618 << 3) | 0;
	cppVar_87619 = (cppVar_87619 & cppMask_un_8_);
	cppVar_87611 = cppVar_87619;
	} else {
	BIT_VEC cppVar_87620 = PC + 1;
	cppVar_87620 = (cppVar_87620 & cppMask_un_16_);
	BIT_VEC cppVar_87621 = ROM.rd(cppVar_87620);
	BIT_VEC cppVar_87622 = (cppVar_87621 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_87623 = (cppVar_87622 & cppMask_un_5_);
	BIT_VEC cppVar_87624 = cppVar_87623 + 32;
	cppVar_87624 = (cppVar_87624 & cppMask_un_8_);
	cppVar_87611 = cppVar_87624;
	}
	bool cppVar_87626 = (cppVar_87611 == 136);
	if (cppVar_87626) {
	cppVar_87610 = TCON;
	} else {
	BIT_VEC cppVar_87627;
	BIT_VEC cppVar_87628;
	BIT_VEC cppVar_87629 = PC + 1;
	cppVar_87629 = (cppVar_87629 & cppMask_un_16_);
	BIT_VEC cppVar_87630 = ROM.rd(cppVar_87629);
	BIT_VEC cppVar_87631 = (cppVar_87630 >> 7) & cppMask_un_1_;
	bool cppVar_87632 = (cppVar_87631 == 1);
	if (cppVar_87632) {
	BIT_VEC cppVar_87633 = PC + 1;
	cppVar_87633 = (cppVar_87633 & cppMask_un_16_);
	BIT_VEC cppVar_87634 = ROM.rd(cppVar_87633);
	BIT_VEC cppVar_87635 = (cppVar_87634 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_87636 = (cppVar_87635 << 3) | 0;
	cppVar_87636 = (cppVar_87636 & cppMask_un_8_);
	cppVar_87628 = cppVar_87636;
	} else {
	BIT_VEC cppVar_87637 = PC + 1;
	cppVar_87637 = (cppVar_87637 & cppMask_un_16_);
	BIT_VEC cppVar_87638 = ROM.rd(cppVar_87637);
	BIT_VEC cppVar_87639 = (cppVar_87638 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_87640 = (cppVar_87639 & cppMask_un_5_);
	BIT_VEC cppVar_87641 = cppVar_87640 + 32;
	cppVar_87641 = (cppVar_87641 & cppMask_un_8_);
	cppVar_87628 = cppVar_87641;
	}
	bool cppVar_87643 = (cppVar_87628 == 137);
	if (cppVar_87643) {
	cppVar_87627 = TMOD;
	} else {
	BIT_VEC cppVar_87644;
	BIT_VEC cppVar_87645;
	BIT_VEC cppVar_87646 = PC + 1;
	cppVar_87646 = (cppVar_87646 & cppMask_un_16_);
	BIT_VEC cppVar_87647 = ROM.rd(cppVar_87646);
	BIT_VEC cppVar_87648 = (cppVar_87647 >> 7) & cppMask_un_1_;
	bool cppVar_87649 = (cppVar_87648 == 1);
	if (cppVar_87649) {
	BIT_VEC cppVar_87650 = PC + 1;
	cppVar_87650 = (cppVar_87650 & cppMask_un_16_);
	BIT_VEC cppVar_87651 = ROM.rd(cppVar_87650);
	BIT_VEC cppVar_87652 = (cppVar_87651 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_87653 = (cppVar_87652 << 3) | 0;
	cppVar_87653 = (cppVar_87653 & cppMask_un_8_);
	cppVar_87645 = cppVar_87653;
	} else {
	BIT_VEC cppVar_87654 = PC + 1;
	cppVar_87654 = (cppVar_87654 & cppMask_un_16_);
	BIT_VEC cppVar_87655 = ROM.rd(cppVar_87654);
	BIT_VEC cppVar_87656 = (cppVar_87655 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_87657 = (cppVar_87656 & cppMask_un_5_);
	BIT_VEC cppVar_87658 = cppVar_87657 + 32;
	cppVar_87658 = (cppVar_87658 & cppMask_un_8_);
	cppVar_87645 = cppVar_87658;
	}
	bool cppVar_87660 = (cppVar_87645 == 138);
	if (cppVar_87660) {
	cppVar_87644 = TL0;
	} else {
	BIT_VEC cppVar_87661;
	BIT_VEC cppVar_87662;
	BIT_VEC cppVar_87663 = PC + 1;
	cppVar_87663 = (cppVar_87663 & cppMask_un_16_);
	BIT_VEC cppVar_87664 = ROM.rd(cppVar_87663);
	BIT_VEC cppVar_87665 = (cppVar_87664 >> 7) & cppMask_un_1_;
	bool cppVar_87666 = (cppVar_87665 == 1);
	if (cppVar_87666) {
	BIT_VEC cppVar_87667 = PC + 1;
	cppVar_87667 = (cppVar_87667 & cppMask_un_16_);
	BIT_VEC cppVar_87668 = ROM.rd(cppVar_87667);
	BIT_VEC cppVar_87669 = (cppVar_87668 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_87670 = (cppVar_87669 << 3) | 0;
	cppVar_87670 = (cppVar_87670 & cppMask_un_8_);
	cppVar_87662 = cppVar_87670;
	} else {
	BIT_VEC cppVar_87671 = PC + 1;
	cppVar_87671 = (cppVar_87671 & cppMask_un_16_);
	BIT_VEC cppVar_87672 = ROM.rd(cppVar_87671);
	BIT_VEC cppVar_87673 = (cppVar_87672 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_87674 = (cppVar_87673 & cppMask_un_5_);
	BIT_VEC cppVar_87675 = cppVar_87674 + 32;
	cppVar_87675 = (cppVar_87675 & cppMask_un_8_);
	cppVar_87662 = cppVar_87675;
	}
	bool cppVar_87677 = (cppVar_87662 == 140);
	if (cppVar_87677) {
	cppVar_87661 = TH0;
	} else {
	BIT_VEC cppVar_87678;
	BIT_VEC cppVar_87679;
	BIT_VEC cppVar_87680 = PC + 1;
	cppVar_87680 = (cppVar_87680 & cppMask_un_16_);
	BIT_VEC cppVar_87681 = ROM.rd(cppVar_87680);
	BIT_VEC cppVar_87682 = (cppVar_87681 >> 7) & cppMask_un_1_;
	bool cppVar_87683 = (cppVar_87682 == 1);
	if (cppVar_87683) {
	BIT_VEC cppVar_87684 = PC + 1;
	cppVar_87684 = (cppVar_87684 & cppMask_un_16_);
	BIT_VEC cppVar_87685 = ROM.rd(cppVar_87684);
	BIT_VEC cppVar_87686 = (cppVar_87685 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_87687 = (cppVar_87686 << 3) | 0;
	cppVar_87687 = (cppVar_87687 & cppMask_un_8_);
	cppVar_87679 = cppVar_87687;
	} else {
	BIT_VEC cppVar_87688 = PC + 1;
	cppVar_87688 = (cppVar_87688 & cppMask_un_16_);
	BIT_VEC cppVar_87689 = ROM.rd(cppVar_87688);
	BIT_VEC cppVar_87690 = (cppVar_87689 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_87691 = (cppVar_87690 & cppMask_un_5_);
	BIT_VEC cppVar_87692 = cppVar_87691 + 32;
	cppVar_87692 = (cppVar_87692 & cppMask_un_8_);
	cppVar_87679 = cppVar_87692;
	}
	bool cppVar_87694 = (cppVar_87679 == 139);
	if (cppVar_87694) {
	cppVar_87678 = TL1;
	} else {
	BIT_VEC cppVar_87695;
	BIT_VEC cppVar_87696;
	BIT_VEC cppVar_87697 = PC + 1;
	cppVar_87697 = (cppVar_87697 & cppMask_un_16_);
	BIT_VEC cppVar_87698 = ROM.rd(cppVar_87697);
	BIT_VEC cppVar_87699 = (cppVar_87698 >> 7) & cppMask_un_1_;
	bool cppVar_87700 = (cppVar_87699 == 1);
	if (cppVar_87700) {
	BIT_VEC cppVar_87701 = PC + 1;
	cppVar_87701 = (cppVar_87701 & cppMask_un_16_);
	BIT_VEC cppVar_87702 = ROM.rd(cppVar_87701);
	BIT_VEC cppVar_87703 = (cppVar_87702 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_87704 = (cppVar_87703 << 3) | 0;
	cppVar_87704 = (cppVar_87704 & cppMask_un_8_);
	cppVar_87696 = cppVar_87704;
	} else {
	BIT_VEC cppVar_87705 = PC + 1;
	cppVar_87705 = (cppVar_87705 & cppMask_un_16_);
	BIT_VEC cppVar_87706 = ROM.rd(cppVar_87705);
	BIT_VEC cppVar_87707 = (cppVar_87706 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_87708 = (cppVar_87707 & cppMask_un_5_);
	BIT_VEC cppVar_87709 = cppVar_87708 + 32;
	cppVar_87709 = (cppVar_87709 & cppMask_un_8_);
	cppVar_87696 = cppVar_87709;
	}
	bool cppVar_87711 = (cppVar_87696 == 141);
	if (cppVar_87711) {
	cppVar_87695 = TH1;
	} else {
	BIT_VEC cppVar_87712;
	BIT_VEC cppVar_87713;
	BIT_VEC cppVar_87714 = PC + 1;
	cppVar_87714 = (cppVar_87714 & cppMask_un_16_);
	BIT_VEC cppVar_87715 = ROM.rd(cppVar_87714);
	BIT_VEC cppVar_87716 = (cppVar_87715 >> 7) & cppMask_un_1_;
	bool cppVar_87717 = (cppVar_87716 == 1);
	if (cppVar_87717) {
	BIT_VEC cppVar_87718 = PC + 1;
	cppVar_87718 = (cppVar_87718 & cppMask_un_16_);
	BIT_VEC cppVar_87719 = ROM.rd(cppVar_87718);
	BIT_VEC cppVar_87720 = (cppVar_87719 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_87721 = (cppVar_87720 << 3) | 0;
	cppVar_87721 = (cppVar_87721 & cppMask_un_8_);
	cppVar_87713 = cppVar_87721;
	} else {
	BIT_VEC cppVar_87722 = PC + 1;
	cppVar_87722 = (cppVar_87722 & cppMask_un_16_);
	BIT_VEC cppVar_87723 = ROM.rd(cppVar_87722);
	BIT_VEC cppVar_87724 = (cppVar_87723 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_87725 = (cppVar_87724 & cppMask_un_5_);
	BIT_VEC cppVar_87726 = cppVar_87725 + 32;
	cppVar_87726 = (cppVar_87726 & cppMask_un_8_);
	cppVar_87713 = cppVar_87726;
	}
	bool cppVar_87728 = (cppVar_87713 == 144);
	if (cppVar_87728) {
	cppVar_87712 = P1;
	} else {
	BIT_VEC cppVar_87729;
	BIT_VEC cppVar_87730;
	BIT_VEC cppVar_87731 = PC + 1;
	cppVar_87731 = (cppVar_87731 & cppMask_un_16_);
	BIT_VEC cppVar_87732 = ROM.rd(cppVar_87731);
	BIT_VEC cppVar_87733 = (cppVar_87732 >> 7) & cppMask_un_1_;
	bool cppVar_87734 = (cppVar_87733 == 1);
	if (cppVar_87734) {
	BIT_VEC cppVar_87735 = PC + 1;
	cppVar_87735 = (cppVar_87735 & cppMask_un_16_);
	BIT_VEC cppVar_87736 = ROM.rd(cppVar_87735);
	BIT_VEC cppVar_87737 = (cppVar_87736 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_87738 = (cppVar_87737 << 3) | 0;
	cppVar_87738 = (cppVar_87738 & cppMask_un_8_);
	cppVar_87730 = cppVar_87738;
	} else {
	BIT_VEC cppVar_87739 = PC + 1;
	cppVar_87739 = (cppVar_87739 & cppMask_un_16_);
	BIT_VEC cppVar_87740 = ROM.rd(cppVar_87739);
	BIT_VEC cppVar_87741 = (cppVar_87740 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_87742 = (cppVar_87741 & cppMask_un_5_);
	BIT_VEC cppVar_87743 = cppVar_87742 + 32;
	cppVar_87743 = (cppVar_87743 & cppMask_un_8_);
	cppVar_87730 = cppVar_87743;
	}
	bool cppVar_87745 = (cppVar_87730 == 152);
	if (cppVar_87745) {
	cppVar_87729 = SCON;
	} else {
	BIT_VEC cppVar_87746;
	BIT_VEC cppVar_87747;
	BIT_VEC cppVar_87748 = PC + 1;
	cppVar_87748 = (cppVar_87748 & cppMask_un_16_);
	BIT_VEC cppVar_87749 = ROM.rd(cppVar_87748);
	BIT_VEC cppVar_87750 = (cppVar_87749 >> 7) & cppMask_un_1_;
	bool cppVar_87751 = (cppVar_87750 == 1);
	if (cppVar_87751) {
	BIT_VEC cppVar_87752 = PC + 1;
	cppVar_87752 = (cppVar_87752 & cppMask_un_16_);
	BIT_VEC cppVar_87753 = ROM.rd(cppVar_87752);
	BIT_VEC cppVar_87754 = (cppVar_87753 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_87755 = (cppVar_87754 << 3) | 0;
	cppVar_87755 = (cppVar_87755 & cppMask_un_8_);
	cppVar_87747 = cppVar_87755;
	} else {
	BIT_VEC cppVar_87756 = PC + 1;
	cppVar_87756 = (cppVar_87756 & cppMask_un_16_);
	BIT_VEC cppVar_87757 = ROM.rd(cppVar_87756);
	BIT_VEC cppVar_87758 = (cppVar_87757 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_87759 = (cppVar_87758 & cppMask_un_5_);
	BIT_VEC cppVar_87760 = cppVar_87759 + 32;
	cppVar_87760 = (cppVar_87760 & cppMask_un_8_);
	cppVar_87747 = cppVar_87760;
	}
	bool cppVar_87762 = (cppVar_87747 == 153);
	if (cppVar_87762) {
	cppVar_87746 = SBUF;
	} else {
	BIT_VEC cppVar_87763;
	BIT_VEC cppVar_87764;
	BIT_VEC cppVar_87765 = PC + 1;
	cppVar_87765 = (cppVar_87765 & cppMask_un_16_);
	BIT_VEC cppVar_87766 = ROM.rd(cppVar_87765);
	BIT_VEC cppVar_87767 = (cppVar_87766 >> 7) & cppMask_un_1_;
	bool cppVar_87768 = (cppVar_87767 == 1);
	if (cppVar_87768) {
	BIT_VEC cppVar_87769 = PC + 1;
	cppVar_87769 = (cppVar_87769 & cppMask_un_16_);
	BIT_VEC cppVar_87770 = ROM.rd(cppVar_87769);
	BIT_VEC cppVar_87771 = (cppVar_87770 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_87772 = (cppVar_87771 << 3) | 0;
	cppVar_87772 = (cppVar_87772 & cppMask_un_8_);
	cppVar_87764 = cppVar_87772;
	} else {
	BIT_VEC cppVar_87773 = PC + 1;
	cppVar_87773 = (cppVar_87773 & cppMask_un_16_);
	BIT_VEC cppVar_87774 = ROM.rd(cppVar_87773);
	BIT_VEC cppVar_87775 = (cppVar_87774 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_87776 = (cppVar_87775 & cppMask_un_5_);
	BIT_VEC cppVar_87777 = cppVar_87776 + 32;
	cppVar_87777 = (cppVar_87777 & cppMask_un_8_);
	cppVar_87764 = cppVar_87777;
	}
	bool cppVar_87779 = (cppVar_87764 == 160);
	if (cppVar_87779) {
	cppVar_87763 = P2;
	} else {
	BIT_VEC cppVar_87780;
	BIT_VEC cppVar_87781;
	BIT_VEC cppVar_87782 = PC + 1;
	cppVar_87782 = (cppVar_87782 & cppMask_un_16_);
	BIT_VEC cppVar_87783 = ROM.rd(cppVar_87782);
	BIT_VEC cppVar_87784 = (cppVar_87783 >> 7) & cppMask_un_1_;
	bool cppVar_87785 = (cppVar_87784 == 1);
	if (cppVar_87785) {
	BIT_VEC cppVar_87786 = PC + 1;
	cppVar_87786 = (cppVar_87786 & cppMask_un_16_);
	BIT_VEC cppVar_87787 = ROM.rd(cppVar_87786);
	BIT_VEC cppVar_87788 = (cppVar_87787 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_87789 = (cppVar_87788 << 3) | 0;
	cppVar_87789 = (cppVar_87789 & cppMask_un_8_);
	cppVar_87781 = cppVar_87789;
	} else {
	BIT_VEC cppVar_87790 = PC + 1;
	cppVar_87790 = (cppVar_87790 & cppMask_un_16_);
	BIT_VEC cppVar_87791 = ROM.rd(cppVar_87790);
	BIT_VEC cppVar_87792 = (cppVar_87791 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_87793 = (cppVar_87792 & cppMask_un_5_);
	BIT_VEC cppVar_87794 = cppVar_87793 + 32;
	cppVar_87794 = (cppVar_87794 & cppMask_un_8_);
	cppVar_87781 = cppVar_87794;
	}
	bool cppVar_87796 = (cppVar_87781 == 168);
	if (cppVar_87796) {
	cppVar_87780 = IE;
	} else {
	BIT_VEC cppVar_87797;
	BIT_VEC cppVar_87798;
	BIT_VEC cppVar_87799 = PC + 1;
	cppVar_87799 = (cppVar_87799 & cppMask_un_16_);
	BIT_VEC cppVar_87800 = ROM.rd(cppVar_87799);
	BIT_VEC cppVar_87801 = (cppVar_87800 >> 7) & cppMask_un_1_;
	bool cppVar_87802 = (cppVar_87801 == 1);
	if (cppVar_87802) {
	BIT_VEC cppVar_87803 = PC + 1;
	cppVar_87803 = (cppVar_87803 & cppMask_un_16_);
	BIT_VEC cppVar_87804 = ROM.rd(cppVar_87803);
	BIT_VEC cppVar_87805 = (cppVar_87804 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_87806 = (cppVar_87805 << 3) | 0;
	cppVar_87806 = (cppVar_87806 & cppMask_un_8_);
	cppVar_87798 = cppVar_87806;
	} else {
	BIT_VEC cppVar_87807 = PC + 1;
	cppVar_87807 = (cppVar_87807 & cppMask_un_16_);
	BIT_VEC cppVar_87808 = ROM.rd(cppVar_87807);
	BIT_VEC cppVar_87809 = (cppVar_87808 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_87810 = (cppVar_87809 & cppMask_un_5_);
	BIT_VEC cppVar_87811 = cppVar_87810 + 32;
	cppVar_87811 = (cppVar_87811 & cppMask_un_8_);
	cppVar_87798 = cppVar_87811;
	}
	bool cppVar_87813 = (cppVar_87798 == 176);
	if (cppVar_87813) {
	cppVar_87797 = P3;
	} else {
	BIT_VEC cppVar_87814;
	BIT_VEC cppVar_87815;
	BIT_VEC cppVar_87816 = PC + 1;
	cppVar_87816 = (cppVar_87816 & cppMask_un_16_);
	BIT_VEC cppVar_87817 = ROM.rd(cppVar_87816);
	BIT_VEC cppVar_87818 = (cppVar_87817 >> 7) & cppMask_un_1_;
	bool cppVar_87819 = (cppVar_87818 == 1);
	if (cppVar_87819) {
	BIT_VEC cppVar_87820 = PC + 1;
	cppVar_87820 = (cppVar_87820 & cppMask_un_16_);
	BIT_VEC cppVar_87821 = ROM.rd(cppVar_87820);
	BIT_VEC cppVar_87822 = (cppVar_87821 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_87823 = (cppVar_87822 << 3) | 0;
	cppVar_87823 = (cppVar_87823 & cppMask_un_8_);
	cppVar_87815 = cppVar_87823;
	} else {
	BIT_VEC cppVar_87824 = PC + 1;
	cppVar_87824 = (cppVar_87824 & cppMask_un_16_);
	BIT_VEC cppVar_87825 = ROM.rd(cppVar_87824);
	BIT_VEC cppVar_87826 = (cppVar_87825 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_87827 = (cppVar_87826 & cppMask_un_5_);
	BIT_VEC cppVar_87828 = cppVar_87827 + 32;
	cppVar_87828 = (cppVar_87828 & cppMask_un_8_);
	cppVar_87815 = cppVar_87828;
	}
	bool cppVar_87830 = (cppVar_87815 == 184);
	if (cppVar_87830) {
	cppVar_87814 = IP;
	} else {
	BIT_VEC cppVar_87831;
	BIT_VEC cppVar_87832;
	BIT_VEC cppVar_87833 = PC + 1;
	cppVar_87833 = (cppVar_87833 & cppMask_un_16_);
	BIT_VEC cppVar_87834 = ROM.rd(cppVar_87833);
	BIT_VEC cppVar_87835 = (cppVar_87834 >> 7) & cppMask_un_1_;
	bool cppVar_87836 = (cppVar_87835 == 1);
	if (cppVar_87836) {
	BIT_VEC cppVar_87837 = PC + 1;
	cppVar_87837 = (cppVar_87837 & cppMask_un_16_);
	BIT_VEC cppVar_87838 = ROM.rd(cppVar_87837);
	BIT_VEC cppVar_87839 = (cppVar_87838 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_87840 = (cppVar_87839 << 3) | 0;
	cppVar_87840 = (cppVar_87840 & cppMask_un_8_);
	cppVar_87832 = cppVar_87840;
	} else {
	BIT_VEC cppVar_87841 = PC + 1;
	cppVar_87841 = (cppVar_87841 & cppMask_un_16_);
	BIT_VEC cppVar_87842 = ROM.rd(cppVar_87841);
	BIT_VEC cppVar_87843 = (cppVar_87842 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_87844 = (cppVar_87843 & cppMask_un_5_);
	BIT_VEC cppVar_87845 = cppVar_87844 + 32;
	cppVar_87845 = (cppVar_87845 & cppMask_un_8_);
	cppVar_87832 = cppVar_87845;
	}
	bool cppVar_87847 = (cppVar_87832 == 208);
	if (cppVar_87847) {
	cppVar_87831 = PSW;
	} else {
	BIT_VEC cppVar_87848;
	BIT_VEC cppVar_87849;
	BIT_VEC cppVar_87850 = PC + 1;
	cppVar_87850 = (cppVar_87850 & cppMask_un_16_);
	BIT_VEC cppVar_87851 = ROM.rd(cppVar_87850);
	BIT_VEC cppVar_87852 = (cppVar_87851 >> 7) & cppMask_un_1_;
	bool cppVar_87853 = (cppVar_87852 == 1);
	if (cppVar_87853) {
	BIT_VEC cppVar_87854 = PC + 1;
	cppVar_87854 = (cppVar_87854 & cppMask_un_16_);
	BIT_VEC cppVar_87855 = ROM.rd(cppVar_87854);
	BIT_VEC cppVar_87856 = (cppVar_87855 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_87857 = (cppVar_87856 << 3) | 0;
	cppVar_87857 = (cppVar_87857 & cppMask_un_8_);
	cppVar_87849 = cppVar_87857;
	} else {
	BIT_VEC cppVar_87858 = PC + 1;
	cppVar_87858 = (cppVar_87858 & cppMask_un_16_);
	BIT_VEC cppVar_87859 = ROM.rd(cppVar_87858);
	BIT_VEC cppVar_87860 = (cppVar_87859 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_87861 = (cppVar_87860 & cppMask_un_5_);
	BIT_VEC cppVar_87862 = cppVar_87861 + 32;
	cppVar_87862 = (cppVar_87862 & cppMask_un_8_);
	cppVar_87849 = cppVar_87862;
	}
	bool cppVar_87864 = (cppVar_87849 == 224);
	if (cppVar_87864) {
	cppVar_87848 = ACC;
	} else {
	BIT_VEC cppVar_87865;
	BIT_VEC cppVar_87866;
	BIT_VEC cppVar_87867 = PC + 1;
	cppVar_87867 = (cppVar_87867 & cppMask_un_16_);
	BIT_VEC cppVar_87868 = ROM.rd(cppVar_87867);
	BIT_VEC cppVar_87869 = (cppVar_87868 >> 7) & cppMask_un_1_;
	bool cppVar_87870 = (cppVar_87869 == 1);
	if (cppVar_87870) {
	BIT_VEC cppVar_87871 = PC + 1;
	cppVar_87871 = (cppVar_87871 & cppMask_un_16_);
	BIT_VEC cppVar_87872 = ROM.rd(cppVar_87871);
	BIT_VEC cppVar_87873 = (cppVar_87872 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_87874 = (cppVar_87873 << 3) | 0;
	cppVar_87874 = (cppVar_87874 & cppMask_un_8_);
	cppVar_87866 = cppVar_87874;
	} else {
	BIT_VEC cppVar_87875 = PC + 1;
	cppVar_87875 = (cppVar_87875 & cppMask_un_16_);
	BIT_VEC cppVar_87876 = ROM.rd(cppVar_87875);
	BIT_VEC cppVar_87877 = (cppVar_87876 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_87878 = (cppVar_87877 & cppMask_un_5_);
	BIT_VEC cppVar_87879 = cppVar_87878 + 32;
	cppVar_87879 = (cppVar_87879 & cppMask_un_8_);
	cppVar_87866 = cppVar_87879;
	}
	bool cppVar_87881 = (cppVar_87866 == 240);
	if (cppVar_87881) {
	cppVar_87865 = B;
	} else {
	cppVar_87865 = 0;
	}
	cppVar_87848 = cppVar_87865;
	}
	cppVar_87831 = cppVar_87848;
	}
	cppVar_87814 = cppVar_87831;
	}
	cppVar_87797 = cppVar_87814;
	}
	cppVar_87780 = cppVar_87797;
	}
	cppVar_87763 = cppVar_87780;
	}
	cppVar_87746 = cppVar_87763;
	}
	cppVar_87729 = cppVar_87746;
	}
	cppVar_87712 = cppVar_87729;
	}
	cppVar_87695 = cppVar_87712;
	}
	cppVar_87678 = cppVar_87695;
	}
	cppVar_87661 = cppVar_87678;
	}
	cppVar_87644 = cppVar_87661;
	}
	cppVar_87627 = cppVar_87644;
	}
	cppVar_87610 = cppVar_87627;
	}
	cppVar_87593 = cppVar_87610;
	}
	cppVar_87576 = cppVar_87593;
	}
	cppVar_87559 = cppVar_87576;
	}
	cppVar_87542 = cppVar_87559;
	}
	cppVar_87525 = cppVar_87542;
	}
	cppVar_87492 = cppVar_87525;
	}
	BIT_VEC cppVar_87883 = cppVar_87491 & cppVar_87492;
	BIT_VEC cppVar_87884;
	BIT_VEC cppVar_87885;
	BIT_VEC cppVar_87886 = PC + 1;
	cppVar_87886 = (cppVar_87886 & cppMask_un_16_);
	BIT_VEC cppVar_87887 = ROM.rd(cppVar_87886);
	BIT_VEC cppVar_87888 = (cppVar_87887 >> 7) & cppMask_un_1_;
	bool cppVar_87890 = (cppVar_87888 == 1);
	if (cppVar_87890) {
	BIT_VEC cppVar_87891 = PC + 1;
	cppVar_87891 = (cppVar_87891 & cppMask_un_16_);
	BIT_VEC cppVar_87892 = ROM.rd(cppVar_87891);
	BIT_VEC cppVar_87893 = (cppVar_87892 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_87895 = (cppVar_87893 << 3) | 0;
	cppVar_87895 = (cppVar_87895 & cppMask_un_8_);
	cppVar_87885 = cppVar_87895;
	} else {
	BIT_VEC cppVar_87896 = PC + 1;
	cppVar_87896 = (cppVar_87896 & cppMask_un_16_);
	BIT_VEC cppVar_87897 = ROM.rd(cppVar_87896);
	BIT_VEC cppVar_87898 = (cppVar_87897 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_87899 = (cppVar_87898 & cppMask_un_5_);
	BIT_VEC cppVar_87901 = cppVar_87899 + 32;
	cppVar_87901 = (cppVar_87901 & cppMask_un_8_);
	cppVar_87885 = cppVar_87901;
	}
	BIT_VEC cppVar_87902 = (cppVar_87885 >> 7) & cppMask_un_1_;
	bool cppVar_87904 = (cppVar_87902 == 0);
	if (cppVar_87904) {
	BIT_VEC cppVar_87905;
	BIT_VEC cppVar_87906 = PC + 1;
	cppVar_87906 = (cppVar_87906 & cppMask_un_16_);
	BIT_VEC cppVar_87907 = ROM.rd(cppVar_87906);
	BIT_VEC cppVar_87908 = (cppVar_87907 >> 7) & cppMask_un_1_;
	bool cppVar_87909 = (cppVar_87908 == 1);
	if (cppVar_87909) {
	BIT_VEC cppVar_87910 = PC + 1;
	cppVar_87910 = (cppVar_87910 & cppMask_un_16_);
	BIT_VEC cppVar_87911 = ROM.rd(cppVar_87910);
	BIT_VEC cppVar_87912 = (cppVar_87911 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_87913 = (cppVar_87912 << 3) | 0;
	cppVar_87913 = (cppVar_87913 & cppMask_un_8_);
	cppVar_87905 = cppVar_87913;
	} else {
	BIT_VEC cppVar_87914 = PC + 1;
	cppVar_87914 = (cppVar_87914 & cppMask_un_16_);
	BIT_VEC cppVar_87915 = ROM.rd(cppVar_87914);
	BIT_VEC cppVar_87916 = (cppVar_87915 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_87917 = (cppVar_87916 & cppMask_un_5_);
	BIT_VEC cppVar_87918 = cppVar_87917 + 32;
	cppVar_87918 = (cppVar_87918 & cppMask_un_8_);
	cppVar_87905 = cppVar_87918;
	}
	BIT_VEC cppVar_87919 = IRAM.rd(cppVar_87905);
	cppVar_87884 = cppVar_87919;
	} else {
	BIT_VEC cppVar_87920;
	BIT_VEC cppVar_87921;
	BIT_VEC cppVar_87922 = PC + 1;
	cppVar_87922 = (cppVar_87922 & cppMask_un_16_);
	BIT_VEC cppVar_87923 = ROM.rd(cppVar_87922);
	BIT_VEC cppVar_87924 = (cppVar_87923 >> 7) & cppMask_un_1_;
	bool cppVar_87925 = (cppVar_87924 == 1);
	if (cppVar_87925) {
	BIT_VEC cppVar_87926 = PC + 1;
	cppVar_87926 = (cppVar_87926 & cppMask_un_16_);
	BIT_VEC cppVar_87927 = ROM.rd(cppVar_87926);
	BIT_VEC cppVar_87928 = (cppVar_87927 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_87929 = (cppVar_87928 << 3) | 0;
	cppVar_87929 = (cppVar_87929 & cppMask_un_8_);
	cppVar_87921 = cppVar_87929;
	} else {
	BIT_VEC cppVar_87930 = PC + 1;
	cppVar_87930 = (cppVar_87930 & cppMask_un_16_);
	BIT_VEC cppVar_87931 = ROM.rd(cppVar_87930);
	BIT_VEC cppVar_87932 = (cppVar_87931 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_87933 = (cppVar_87932 & cppMask_un_5_);
	BIT_VEC cppVar_87934 = cppVar_87933 + 32;
	cppVar_87934 = (cppVar_87934 & cppMask_un_8_);
	cppVar_87921 = cppVar_87934;
	}
	bool cppVar_87936 = (cppVar_87921 == 128);
	if (cppVar_87936) {
	cppVar_87920 = P0;
	} else {
	BIT_VEC cppVar_87937;
	BIT_VEC cppVar_87938;
	BIT_VEC cppVar_87939 = PC + 1;
	cppVar_87939 = (cppVar_87939 & cppMask_un_16_);
	BIT_VEC cppVar_87940 = ROM.rd(cppVar_87939);
	BIT_VEC cppVar_87941 = (cppVar_87940 >> 7) & cppMask_un_1_;
	bool cppVar_87942 = (cppVar_87941 == 1);
	if (cppVar_87942) {
	BIT_VEC cppVar_87943 = PC + 1;
	cppVar_87943 = (cppVar_87943 & cppMask_un_16_);
	BIT_VEC cppVar_87944 = ROM.rd(cppVar_87943);
	BIT_VEC cppVar_87945 = (cppVar_87944 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_87946 = (cppVar_87945 << 3) | 0;
	cppVar_87946 = (cppVar_87946 & cppMask_un_8_);
	cppVar_87938 = cppVar_87946;
	} else {
	BIT_VEC cppVar_87947 = PC + 1;
	cppVar_87947 = (cppVar_87947 & cppMask_un_16_);
	BIT_VEC cppVar_87948 = ROM.rd(cppVar_87947);
	BIT_VEC cppVar_87949 = (cppVar_87948 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_87950 = (cppVar_87949 & cppMask_un_5_);
	BIT_VEC cppVar_87951 = cppVar_87950 + 32;
	cppVar_87951 = (cppVar_87951 & cppMask_un_8_);
	cppVar_87938 = cppVar_87951;
	}
	bool cppVar_87953 = (cppVar_87938 == 129);
	if (cppVar_87953) {
	cppVar_87937 = SP;
	} else {
	BIT_VEC cppVar_87954;
	BIT_VEC cppVar_87955;
	BIT_VEC cppVar_87956 = PC + 1;
	cppVar_87956 = (cppVar_87956 & cppMask_un_16_);
	BIT_VEC cppVar_87957 = ROM.rd(cppVar_87956);
	BIT_VEC cppVar_87958 = (cppVar_87957 >> 7) & cppMask_un_1_;
	bool cppVar_87959 = (cppVar_87958 == 1);
	if (cppVar_87959) {
	BIT_VEC cppVar_87960 = PC + 1;
	cppVar_87960 = (cppVar_87960 & cppMask_un_16_);
	BIT_VEC cppVar_87961 = ROM.rd(cppVar_87960);
	BIT_VEC cppVar_87962 = (cppVar_87961 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_87963 = (cppVar_87962 << 3) | 0;
	cppVar_87963 = (cppVar_87963 & cppMask_un_8_);
	cppVar_87955 = cppVar_87963;
	} else {
	BIT_VEC cppVar_87964 = PC + 1;
	cppVar_87964 = (cppVar_87964 & cppMask_un_16_);
	BIT_VEC cppVar_87965 = ROM.rd(cppVar_87964);
	BIT_VEC cppVar_87966 = (cppVar_87965 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_87967 = (cppVar_87966 & cppMask_un_5_);
	BIT_VEC cppVar_87968 = cppVar_87967 + 32;
	cppVar_87968 = (cppVar_87968 & cppMask_un_8_);
	cppVar_87955 = cppVar_87968;
	}
	bool cppVar_87970 = (cppVar_87955 == 130);
	if (cppVar_87970) {
	cppVar_87954 = DPL;
	} else {
	BIT_VEC cppVar_87971;
	BIT_VEC cppVar_87972;
	BIT_VEC cppVar_87973 = PC + 1;
	cppVar_87973 = (cppVar_87973 & cppMask_un_16_);
	BIT_VEC cppVar_87974 = ROM.rd(cppVar_87973);
	BIT_VEC cppVar_87975 = (cppVar_87974 >> 7) & cppMask_un_1_;
	bool cppVar_87976 = (cppVar_87975 == 1);
	if (cppVar_87976) {
	BIT_VEC cppVar_87977 = PC + 1;
	cppVar_87977 = (cppVar_87977 & cppMask_un_16_);
	BIT_VEC cppVar_87978 = ROM.rd(cppVar_87977);
	BIT_VEC cppVar_87979 = (cppVar_87978 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_87980 = (cppVar_87979 << 3) | 0;
	cppVar_87980 = (cppVar_87980 & cppMask_un_8_);
	cppVar_87972 = cppVar_87980;
	} else {
	BIT_VEC cppVar_87981 = PC + 1;
	cppVar_87981 = (cppVar_87981 & cppMask_un_16_);
	BIT_VEC cppVar_87982 = ROM.rd(cppVar_87981);
	BIT_VEC cppVar_87983 = (cppVar_87982 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_87984 = (cppVar_87983 & cppMask_un_5_);
	BIT_VEC cppVar_87985 = cppVar_87984 + 32;
	cppVar_87985 = (cppVar_87985 & cppMask_un_8_);
	cppVar_87972 = cppVar_87985;
	}
	bool cppVar_87987 = (cppVar_87972 == 131);
	if (cppVar_87987) {
	cppVar_87971 = DPH;
	} else {
	BIT_VEC cppVar_87988;
	BIT_VEC cppVar_87989;
	BIT_VEC cppVar_87990 = PC + 1;
	cppVar_87990 = (cppVar_87990 & cppMask_un_16_);
	BIT_VEC cppVar_87991 = ROM.rd(cppVar_87990);
	BIT_VEC cppVar_87992 = (cppVar_87991 >> 7) & cppMask_un_1_;
	bool cppVar_87993 = (cppVar_87992 == 1);
	if (cppVar_87993) {
	BIT_VEC cppVar_87994 = PC + 1;
	cppVar_87994 = (cppVar_87994 & cppMask_un_16_);
	BIT_VEC cppVar_87995 = ROM.rd(cppVar_87994);
	BIT_VEC cppVar_87996 = (cppVar_87995 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_87997 = (cppVar_87996 << 3) | 0;
	cppVar_87997 = (cppVar_87997 & cppMask_un_8_);
	cppVar_87989 = cppVar_87997;
	} else {
	BIT_VEC cppVar_87998 = PC + 1;
	cppVar_87998 = (cppVar_87998 & cppMask_un_16_);
	BIT_VEC cppVar_87999 = ROM.rd(cppVar_87998);
	BIT_VEC cppVar_88000 = (cppVar_87999 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_88001 = (cppVar_88000 & cppMask_un_5_);
	BIT_VEC cppVar_88002 = cppVar_88001 + 32;
	cppVar_88002 = (cppVar_88002 & cppMask_un_8_);
	cppVar_87989 = cppVar_88002;
	}
	bool cppVar_88004 = (cppVar_87989 == 135);
	if (cppVar_88004) {
	cppVar_87988 = PCON;
	} else {
	BIT_VEC cppVar_88005;
	BIT_VEC cppVar_88006;
	BIT_VEC cppVar_88007 = PC + 1;
	cppVar_88007 = (cppVar_88007 & cppMask_un_16_);
	BIT_VEC cppVar_88008 = ROM.rd(cppVar_88007);
	BIT_VEC cppVar_88009 = (cppVar_88008 >> 7) & cppMask_un_1_;
	bool cppVar_88010 = (cppVar_88009 == 1);
	if (cppVar_88010) {
	BIT_VEC cppVar_88011 = PC + 1;
	cppVar_88011 = (cppVar_88011 & cppMask_un_16_);
	BIT_VEC cppVar_88012 = ROM.rd(cppVar_88011);
	BIT_VEC cppVar_88013 = (cppVar_88012 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_88014 = (cppVar_88013 << 3) | 0;
	cppVar_88014 = (cppVar_88014 & cppMask_un_8_);
	cppVar_88006 = cppVar_88014;
	} else {
	BIT_VEC cppVar_88015 = PC + 1;
	cppVar_88015 = (cppVar_88015 & cppMask_un_16_);
	BIT_VEC cppVar_88016 = ROM.rd(cppVar_88015);
	BIT_VEC cppVar_88017 = (cppVar_88016 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_88018 = (cppVar_88017 & cppMask_un_5_);
	BIT_VEC cppVar_88019 = cppVar_88018 + 32;
	cppVar_88019 = (cppVar_88019 & cppMask_un_8_);
	cppVar_88006 = cppVar_88019;
	}
	bool cppVar_88021 = (cppVar_88006 == 136);
	if (cppVar_88021) {
	cppVar_88005 = TCON;
	} else {
	BIT_VEC cppVar_88022;
	BIT_VEC cppVar_88023;
	BIT_VEC cppVar_88024 = PC + 1;
	cppVar_88024 = (cppVar_88024 & cppMask_un_16_);
	BIT_VEC cppVar_88025 = ROM.rd(cppVar_88024);
	BIT_VEC cppVar_88026 = (cppVar_88025 >> 7) & cppMask_un_1_;
	bool cppVar_88027 = (cppVar_88026 == 1);
	if (cppVar_88027) {
	BIT_VEC cppVar_88028 = PC + 1;
	cppVar_88028 = (cppVar_88028 & cppMask_un_16_);
	BIT_VEC cppVar_88029 = ROM.rd(cppVar_88028);
	BIT_VEC cppVar_88030 = (cppVar_88029 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_88031 = (cppVar_88030 << 3) | 0;
	cppVar_88031 = (cppVar_88031 & cppMask_un_8_);
	cppVar_88023 = cppVar_88031;
	} else {
	BIT_VEC cppVar_88032 = PC + 1;
	cppVar_88032 = (cppVar_88032 & cppMask_un_16_);
	BIT_VEC cppVar_88033 = ROM.rd(cppVar_88032);
	BIT_VEC cppVar_88034 = (cppVar_88033 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_88035 = (cppVar_88034 & cppMask_un_5_);
	BIT_VEC cppVar_88036 = cppVar_88035 + 32;
	cppVar_88036 = (cppVar_88036 & cppMask_un_8_);
	cppVar_88023 = cppVar_88036;
	}
	bool cppVar_88038 = (cppVar_88023 == 137);
	if (cppVar_88038) {
	cppVar_88022 = TMOD;
	} else {
	BIT_VEC cppVar_88039;
	BIT_VEC cppVar_88040;
	BIT_VEC cppVar_88041 = PC + 1;
	cppVar_88041 = (cppVar_88041 & cppMask_un_16_);
	BIT_VEC cppVar_88042 = ROM.rd(cppVar_88041);
	BIT_VEC cppVar_88043 = (cppVar_88042 >> 7) & cppMask_un_1_;
	bool cppVar_88044 = (cppVar_88043 == 1);
	if (cppVar_88044) {
	BIT_VEC cppVar_88045 = PC + 1;
	cppVar_88045 = (cppVar_88045 & cppMask_un_16_);
	BIT_VEC cppVar_88046 = ROM.rd(cppVar_88045);
	BIT_VEC cppVar_88047 = (cppVar_88046 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_88048 = (cppVar_88047 << 3) | 0;
	cppVar_88048 = (cppVar_88048 & cppMask_un_8_);
	cppVar_88040 = cppVar_88048;
	} else {
	BIT_VEC cppVar_88049 = PC + 1;
	cppVar_88049 = (cppVar_88049 & cppMask_un_16_);
	BIT_VEC cppVar_88050 = ROM.rd(cppVar_88049);
	BIT_VEC cppVar_88051 = (cppVar_88050 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_88052 = (cppVar_88051 & cppMask_un_5_);
	BIT_VEC cppVar_88053 = cppVar_88052 + 32;
	cppVar_88053 = (cppVar_88053 & cppMask_un_8_);
	cppVar_88040 = cppVar_88053;
	}
	bool cppVar_88055 = (cppVar_88040 == 138);
	if (cppVar_88055) {
	cppVar_88039 = TL0;
	} else {
	BIT_VEC cppVar_88056;
	BIT_VEC cppVar_88057;
	BIT_VEC cppVar_88058 = PC + 1;
	cppVar_88058 = (cppVar_88058 & cppMask_un_16_);
	BIT_VEC cppVar_88059 = ROM.rd(cppVar_88058);
	BIT_VEC cppVar_88060 = (cppVar_88059 >> 7) & cppMask_un_1_;
	bool cppVar_88061 = (cppVar_88060 == 1);
	if (cppVar_88061) {
	BIT_VEC cppVar_88062 = PC + 1;
	cppVar_88062 = (cppVar_88062 & cppMask_un_16_);
	BIT_VEC cppVar_88063 = ROM.rd(cppVar_88062);
	BIT_VEC cppVar_88064 = (cppVar_88063 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_88065 = (cppVar_88064 << 3) | 0;
	cppVar_88065 = (cppVar_88065 & cppMask_un_8_);
	cppVar_88057 = cppVar_88065;
	} else {
	BIT_VEC cppVar_88066 = PC + 1;
	cppVar_88066 = (cppVar_88066 & cppMask_un_16_);
	BIT_VEC cppVar_88067 = ROM.rd(cppVar_88066);
	BIT_VEC cppVar_88068 = (cppVar_88067 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_88069 = (cppVar_88068 & cppMask_un_5_);
	BIT_VEC cppVar_88070 = cppVar_88069 + 32;
	cppVar_88070 = (cppVar_88070 & cppMask_un_8_);
	cppVar_88057 = cppVar_88070;
	}
	bool cppVar_88072 = (cppVar_88057 == 140);
	if (cppVar_88072) {
	cppVar_88056 = TH0;
	} else {
	BIT_VEC cppVar_88073;
	BIT_VEC cppVar_88074;
	BIT_VEC cppVar_88075 = PC + 1;
	cppVar_88075 = (cppVar_88075 & cppMask_un_16_);
	BIT_VEC cppVar_88076 = ROM.rd(cppVar_88075);
	BIT_VEC cppVar_88077 = (cppVar_88076 >> 7) & cppMask_un_1_;
	bool cppVar_88078 = (cppVar_88077 == 1);
	if (cppVar_88078) {
	BIT_VEC cppVar_88079 = PC + 1;
	cppVar_88079 = (cppVar_88079 & cppMask_un_16_);
	BIT_VEC cppVar_88080 = ROM.rd(cppVar_88079);
	BIT_VEC cppVar_88081 = (cppVar_88080 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_88082 = (cppVar_88081 << 3) | 0;
	cppVar_88082 = (cppVar_88082 & cppMask_un_8_);
	cppVar_88074 = cppVar_88082;
	} else {
	BIT_VEC cppVar_88083 = PC + 1;
	cppVar_88083 = (cppVar_88083 & cppMask_un_16_);
	BIT_VEC cppVar_88084 = ROM.rd(cppVar_88083);
	BIT_VEC cppVar_88085 = (cppVar_88084 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_88086 = (cppVar_88085 & cppMask_un_5_);
	BIT_VEC cppVar_88087 = cppVar_88086 + 32;
	cppVar_88087 = (cppVar_88087 & cppMask_un_8_);
	cppVar_88074 = cppVar_88087;
	}
	bool cppVar_88089 = (cppVar_88074 == 139);
	if (cppVar_88089) {
	cppVar_88073 = TL1;
	} else {
	BIT_VEC cppVar_88090;
	BIT_VEC cppVar_88091;
	BIT_VEC cppVar_88092 = PC + 1;
	cppVar_88092 = (cppVar_88092 & cppMask_un_16_);
	BIT_VEC cppVar_88093 = ROM.rd(cppVar_88092);
	BIT_VEC cppVar_88094 = (cppVar_88093 >> 7) & cppMask_un_1_;
	bool cppVar_88095 = (cppVar_88094 == 1);
	if (cppVar_88095) {
	BIT_VEC cppVar_88096 = PC + 1;
	cppVar_88096 = (cppVar_88096 & cppMask_un_16_);
	BIT_VEC cppVar_88097 = ROM.rd(cppVar_88096);
	BIT_VEC cppVar_88098 = (cppVar_88097 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_88099 = (cppVar_88098 << 3) | 0;
	cppVar_88099 = (cppVar_88099 & cppMask_un_8_);
	cppVar_88091 = cppVar_88099;
	} else {
	BIT_VEC cppVar_88100 = PC + 1;
	cppVar_88100 = (cppVar_88100 & cppMask_un_16_);
	BIT_VEC cppVar_88101 = ROM.rd(cppVar_88100);
	BIT_VEC cppVar_88102 = (cppVar_88101 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_88103 = (cppVar_88102 & cppMask_un_5_);
	BIT_VEC cppVar_88104 = cppVar_88103 + 32;
	cppVar_88104 = (cppVar_88104 & cppMask_un_8_);
	cppVar_88091 = cppVar_88104;
	}
	bool cppVar_88106 = (cppVar_88091 == 141);
	if (cppVar_88106) {
	cppVar_88090 = TH1;
	} else {
	BIT_VEC cppVar_88107;
	BIT_VEC cppVar_88108;
	BIT_VEC cppVar_88109 = PC + 1;
	cppVar_88109 = (cppVar_88109 & cppMask_un_16_);
	BIT_VEC cppVar_88110 = ROM.rd(cppVar_88109);
	BIT_VEC cppVar_88111 = (cppVar_88110 >> 7) & cppMask_un_1_;
	bool cppVar_88112 = (cppVar_88111 == 1);
	if (cppVar_88112) {
	BIT_VEC cppVar_88113 = PC + 1;
	cppVar_88113 = (cppVar_88113 & cppMask_un_16_);
	BIT_VEC cppVar_88114 = ROM.rd(cppVar_88113);
	BIT_VEC cppVar_88115 = (cppVar_88114 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_88116 = (cppVar_88115 << 3) | 0;
	cppVar_88116 = (cppVar_88116 & cppMask_un_8_);
	cppVar_88108 = cppVar_88116;
	} else {
	BIT_VEC cppVar_88117 = PC + 1;
	cppVar_88117 = (cppVar_88117 & cppMask_un_16_);
	BIT_VEC cppVar_88118 = ROM.rd(cppVar_88117);
	BIT_VEC cppVar_88119 = (cppVar_88118 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_88120 = (cppVar_88119 & cppMask_un_5_);
	BIT_VEC cppVar_88121 = cppVar_88120 + 32;
	cppVar_88121 = (cppVar_88121 & cppMask_un_8_);
	cppVar_88108 = cppVar_88121;
	}
	bool cppVar_88123 = (cppVar_88108 == 144);
	if (cppVar_88123) {
	cppVar_88107 = P1;
	} else {
	BIT_VEC cppVar_88124;
	BIT_VEC cppVar_88125;
	BIT_VEC cppVar_88126 = PC + 1;
	cppVar_88126 = (cppVar_88126 & cppMask_un_16_);
	BIT_VEC cppVar_88127 = ROM.rd(cppVar_88126);
	BIT_VEC cppVar_88128 = (cppVar_88127 >> 7) & cppMask_un_1_;
	bool cppVar_88129 = (cppVar_88128 == 1);
	if (cppVar_88129) {
	BIT_VEC cppVar_88130 = PC + 1;
	cppVar_88130 = (cppVar_88130 & cppMask_un_16_);
	BIT_VEC cppVar_88131 = ROM.rd(cppVar_88130);
	BIT_VEC cppVar_88132 = (cppVar_88131 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_88133 = (cppVar_88132 << 3) | 0;
	cppVar_88133 = (cppVar_88133 & cppMask_un_8_);
	cppVar_88125 = cppVar_88133;
	} else {
	BIT_VEC cppVar_88134 = PC + 1;
	cppVar_88134 = (cppVar_88134 & cppMask_un_16_);
	BIT_VEC cppVar_88135 = ROM.rd(cppVar_88134);
	BIT_VEC cppVar_88136 = (cppVar_88135 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_88137 = (cppVar_88136 & cppMask_un_5_);
	BIT_VEC cppVar_88138 = cppVar_88137 + 32;
	cppVar_88138 = (cppVar_88138 & cppMask_un_8_);
	cppVar_88125 = cppVar_88138;
	}
	bool cppVar_88140 = (cppVar_88125 == 152);
	if (cppVar_88140) {
	cppVar_88124 = SCON;
	} else {
	BIT_VEC cppVar_88141;
	BIT_VEC cppVar_88142;
	BIT_VEC cppVar_88143 = PC + 1;
	cppVar_88143 = (cppVar_88143 & cppMask_un_16_);
	BIT_VEC cppVar_88144 = ROM.rd(cppVar_88143);
	BIT_VEC cppVar_88145 = (cppVar_88144 >> 7) & cppMask_un_1_;
	bool cppVar_88146 = (cppVar_88145 == 1);
	if (cppVar_88146) {
	BIT_VEC cppVar_88147 = PC + 1;
	cppVar_88147 = (cppVar_88147 & cppMask_un_16_);
	BIT_VEC cppVar_88148 = ROM.rd(cppVar_88147);
	BIT_VEC cppVar_88149 = (cppVar_88148 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_88150 = (cppVar_88149 << 3) | 0;
	cppVar_88150 = (cppVar_88150 & cppMask_un_8_);
	cppVar_88142 = cppVar_88150;
	} else {
	BIT_VEC cppVar_88151 = PC + 1;
	cppVar_88151 = (cppVar_88151 & cppMask_un_16_);
	BIT_VEC cppVar_88152 = ROM.rd(cppVar_88151);
	BIT_VEC cppVar_88153 = (cppVar_88152 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_88154 = (cppVar_88153 & cppMask_un_5_);
	BIT_VEC cppVar_88155 = cppVar_88154 + 32;
	cppVar_88155 = (cppVar_88155 & cppMask_un_8_);
	cppVar_88142 = cppVar_88155;
	}
	bool cppVar_88157 = (cppVar_88142 == 153);
	if (cppVar_88157) {
	cppVar_88141 = SBUF;
	} else {
	BIT_VEC cppVar_88158;
	BIT_VEC cppVar_88159;
	BIT_VEC cppVar_88160 = PC + 1;
	cppVar_88160 = (cppVar_88160 & cppMask_un_16_);
	BIT_VEC cppVar_88161 = ROM.rd(cppVar_88160);
	BIT_VEC cppVar_88162 = (cppVar_88161 >> 7) & cppMask_un_1_;
	bool cppVar_88163 = (cppVar_88162 == 1);
	if (cppVar_88163) {
	BIT_VEC cppVar_88164 = PC + 1;
	cppVar_88164 = (cppVar_88164 & cppMask_un_16_);
	BIT_VEC cppVar_88165 = ROM.rd(cppVar_88164);
	BIT_VEC cppVar_88166 = (cppVar_88165 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_88167 = (cppVar_88166 << 3) | 0;
	cppVar_88167 = (cppVar_88167 & cppMask_un_8_);
	cppVar_88159 = cppVar_88167;
	} else {
	BIT_VEC cppVar_88168 = PC + 1;
	cppVar_88168 = (cppVar_88168 & cppMask_un_16_);
	BIT_VEC cppVar_88169 = ROM.rd(cppVar_88168);
	BIT_VEC cppVar_88170 = (cppVar_88169 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_88171 = (cppVar_88170 & cppMask_un_5_);
	BIT_VEC cppVar_88172 = cppVar_88171 + 32;
	cppVar_88172 = (cppVar_88172 & cppMask_un_8_);
	cppVar_88159 = cppVar_88172;
	}
	bool cppVar_88174 = (cppVar_88159 == 160);
	if (cppVar_88174) {
	cppVar_88158 = P2;
	} else {
	BIT_VEC cppVar_88175;
	BIT_VEC cppVar_88176;
	BIT_VEC cppVar_88177 = PC + 1;
	cppVar_88177 = (cppVar_88177 & cppMask_un_16_);
	BIT_VEC cppVar_88178 = ROM.rd(cppVar_88177);
	BIT_VEC cppVar_88179 = (cppVar_88178 >> 7) & cppMask_un_1_;
	bool cppVar_88180 = (cppVar_88179 == 1);
	if (cppVar_88180) {
	BIT_VEC cppVar_88181 = PC + 1;
	cppVar_88181 = (cppVar_88181 & cppMask_un_16_);
	BIT_VEC cppVar_88182 = ROM.rd(cppVar_88181);
	BIT_VEC cppVar_88183 = (cppVar_88182 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_88184 = (cppVar_88183 << 3) | 0;
	cppVar_88184 = (cppVar_88184 & cppMask_un_8_);
	cppVar_88176 = cppVar_88184;
	} else {
	BIT_VEC cppVar_88185 = PC + 1;
	cppVar_88185 = (cppVar_88185 & cppMask_un_16_);
	BIT_VEC cppVar_88186 = ROM.rd(cppVar_88185);
	BIT_VEC cppVar_88187 = (cppVar_88186 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_88188 = (cppVar_88187 & cppMask_un_5_);
	BIT_VEC cppVar_88189 = cppVar_88188 + 32;
	cppVar_88189 = (cppVar_88189 & cppMask_un_8_);
	cppVar_88176 = cppVar_88189;
	}
	bool cppVar_88191 = (cppVar_88176 == 168);
	if (cppVar_88191) {
	cppVar_88175 = IE;
	} else {
	BIT_VEC cppVar_88192;
	BIT_VEC cppVar_88193;
	BIT_VEC cppVar_88194 = PC + 1;
	cppVar_88194 = (cppVar_88194 & cppMask_un_16_);
	BIT_VEC cppVar_88195 = ROM.rd(cppVar_88194);
	BIT_VEC cppVar_88196 = (cppVar_88195 >> 7) & cppMask_un_1_;
	bool cppVar_88197 = (cppVar_88196 == 1);
	if (cppVar_88197) {
	BIT_VEC cppVar_88198 = PC + 1;
	cppVar_88198 = (cppVar_88198 & cppMask_un_16_);
	BIT_VEC cppVar_88199 = ROM.rd(cppVar_88198);
	BIT_VEC cppVar_88200 = (cppVar_88199 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_88201 = (cppVar_88200 << 3) | 0;
	cppVar_88201 = (cppVar_88201 & cppMask_un_8_);
	cppVar_88193 = cppVar_88201;
	} else {
	BIT_VEC cppVar_88202 = PC + 1;
	cppVar_88202 = (cppVar_88202 & cppMask_un_16_);
	BIT_VEC cppVar_88203 = ROM.rd(cppVar_88202);
	BIT_VEC cppVar_88204 = (cppVar_88203 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_88205 = (cppVar_88204 & cppMask_un_5_);
	BIT_VEC cppVar_88206 = cppVar_88205 + 32;
	cppVar_88206 = (cppVar_88206 & cppMask_un_8_);
	cppVar_88193 = cppVar_88206;
	}
	bool cppVar_88208 = (cppVar_88193 == 176);
	if (cppVar_88208) {
	cppVar_88192 = P3;
	} else {
	BIT_VEC cppVar_88209;
	BIT_VEC cppVar_88210;
	BIT_VEC cppVar_88211 = PC + 1;
	cppVar_88211 = (cppVar_88211 & cppMask_un_16_);
	BIT_VEC cppVar_88212 = ROM.rd(cppVar_88211);
	BIT_VEC cppVar_88213 = (cppVar_88212 >> 7) & cppMask_un_1_;
	bool cppVar_88214 = (cppVar_88213 == 1);
	if (cppVar_88214) {
	BIT_VEC cppVar_88215 = PC + 1;
	cppVar_88215 = (cppVar_88215 & cppMask_un_16_);
	BIT_VEC cppVar_88216 = ROM.rd(cppVar_88215);
	BIT_VEC cppVar_88217 = (cppVar_88216 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_88218 = (cppVar_88217 << 3) | 0;
	cppVar_88218 = (cppVar_88218 & cppMask_un_8_);
	cppVar_88210 = cppVar_88218;
	} else {
	BIT_VEC cppVar_88219 = PC + 1;
	cppVar_88219 = (cppVar_88219 & cppMask_un_16_);
	BIT_VEC cppVar_88220 = ROM.rd(cppVar_88219);
	BIT_VEC cppVar_88221 = (cppVar_88220 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_88222 = (cppVar_88221 & cppMask_un_5_);
	BIT_VEC cppVar_88223 = cppVar_88222 + 32;
	cppVar_88223 = (cppVar_88223 & cppMask_un_8_);
	cppVar_88210 = cppVar_88223;
	}
	bool cppVar_88225 = (cppVar_88210 == 184);
	if (cppVar_88225) {
	cppVar_88209 = IP;
	} else {
	BIT_VEC cppVar_88226;
	BIT_VEC cppVar_88227;
	BIT_VEC cppVar_88228 = PC + 1;
	cppVar_88228 = (cppVar_88228 & cppMask_un_16_);
	BIT_VEC cppVar_88229 = ROM.rd(cppVar_88228);
	BIT_VEC cppVar_88230 = (cppVar_88229 >> 7) & cppMask_un_1_;
	bool cppVar_88231 = (cppVar_88230 == 1);
	if (cppVar_88231) {
	BIT_VEC cppVar_88232 = PC + 1;
	cppVar_88232 = (cppVar_88232 & cppMask_un_16_);
	BIT_VEC cppVar_88233 = ROM.rd(cppVar_88232);
	BIT_VEC cppVar_88234 = (cppVar_88233 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_88235 = (cppVar_88234 << 3) | 0;
	cppVar_88235 = (cppVar_88235 & cppMask_un_8_);
	cppVar_88227 = cppVar_88235;
	} else {
	BIT_VEC cppVar_88236 = PC + 1;
	cppVar_88236 = (cppVar_88236 & cppMask_un_16_);
	BIT_VEC cppVar_88237 = ROM.rd(cppVar_88236);
	BIT_VEC cppVar_88238 = (cppVar_88237 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_88239 = (cppVar_88238 & cppMask_un_5_);
	BIT_VEC cppVar_88240 = cppVar_88239 + 32;
	cppVar_88240 = (cppVar_88240 & cppMask_un_8_);
	cppVar_88227 = cppVar_88240;
	}
	bool cppVar_88242 = (cppVar_88227 == 208);
	if (cppVar_88242) {
	cppVar_88226 = PSW;
	} else {
	BIT_VEC cppVar_88243;
	BIT_VEC cppVar_88244;
	BIT_VEC cppVar_88245 = PC + 1;
	cppVar_88245 = (cppVar_88245 & cppMask_un_16_);
	BIT_VEC cppVar_88246 = ROM.rd(cppVar_88245);
	BIT_VEC cppVar_88247 = (cppVar_88246 >> 7) & cppMask_un_1_;
	bool cppVar_88248 = (cppVar_88247 == 1);
	if (cppVar_88248) {
	BIT_VEC cppVar_88249 = PC + 1;
	cppVar_88249 = (cppVar_88249 & cppMask_un_16_);
	BIT_VEC cppVar_88250 = ROM.rd(cppVar_88249);
	BIT_VEC cppVar_88251 = (cppVar_88250 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_88252 = (cppVar_88251 << 3) | 0;
	cppVar_88252 = (cppVar_88252 & cppMask_un_8_);
	cppVar_88244 = cppVar_88252;
	} else {
	BIT_VEC cppVar_88253 = PC + 1;
	cppVar_88253 = (cppVar_88253 & cppMask_un_16_);
	BIT_VEC cppVar_88254 = ROM.rd(cppVar_88253);
	BIT_VEC cppVar_88255 = (cppVar_88254 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_88256 = (cppVar_88255 & cppMask_un_5_);
	BIT_VEC cppVar_88257 = cppVar_88256 + 32;
	cppVar_88257 = (cppVar_88257 & cppMask_un_8_);
	cppVar_88244 = cppVar_88257;
	}
	bool cppVar_88259 = (cppVar_88244 == 224);
	if (cppVar_88259) {
	cppVar_88243 = ACC;
	} else {
	BIT_VEC cppVar_88260;
	BIT_VEC cppVar_88261;
	BIT_VEC cppVar_88262 = PC + 1;
	cppVar_88262 = (cppVar_88262 & cppMask_un_16_);
	BIT_VEC cppVar_88263 = ROM.rd(cppVar_88262);
	BIT_VEC cppVar_88264 = (cppVar_88263 >> 7) & cppMask_un_1_;
	bool cppVar_88265 = (cppVar_88264 == 1);
	if (cppVar_88265) {
	BIT_VEC cppVar_88266 = PC + 1;
	cppVar_88266 = (cppVar_88266 & cppMask_un_16_);
	BIT_VEC cppVar_88267 = ROM.rd(cppVar_88266);
	BIT_VEC cppVar_88268 = (cppVar_88267 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_88269 = (cppVar_88268 << 3) | 0;
	cppVar_88269 = (cppVar_88269 & cppMask_un_8_);
	cppVar_88261 = cppVar_88269;
	} else {
	BIT_VEC cppVar_88270 = PC + 1;
	cppVar_88270 = (cppVar_88270 & cppMask_un_16_);
	BIT_VEC cppVar_88271 = ROM.rd(cppVar_88270);
	BIT_VEC cppVar_88272 = (cppVar_88271 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_88273 = (cppVar_88272 & cppMask_un_5_);
	BIT_VEC cppVar_88274 = cppVar_88273 + 32;
	cppVar_88274 = (cppVar_88274 & cppMask_un_8_);
	cppVar_88261 = cppVar_88274;
	}
	bool cppVar_88276 = (cppVar_88261 == 240);
	if (cppVar_88276) {
	cppVar_88260 = B;
	} else {
	cppVar_88260 = 0;
	}
	cppVar_88243 = cppVar_88260;
	}
	cppVar_88226 = cppVar_88243;
	}
	cppVar_88209 = cppVar_88226;
	}
	cppVar_88192 = cppVar_88209;
	}
	cppVar_88175 = cppVar_88192;
	}
	cppVar_88158 = cppVar_88175;
	}
	cppVar_88141 = cppVar_88158;
	}
	cppVar_88124 = cppVar_88141;
	}
	cppVar_88107 = cppVar_88124;
	}
	cppVar_88090 = cppVar_88107;
	}
	cppVar_88073 = cppVar_88090;
	}
	cppVar_88056 = cppVar_88073;
	}
	cppVar_88039 = cppVar_88056;
	}
	cppVar_88022 = cppVar_88039;
	}
	cppVar_88005 = cppVar_88022;
	}
	cppVar_87988 = cppVar_88005;
	}
	cppVar_87971 = cppVar_87988;
	}
	cppVar_87954 = cppVar_87971;
	}
	cppVar_87937 = cppVar_87954;
	}
	cppVar_87920 = cppVar_87937;
	}
	cppVar_87884 = cppVar_87920;
	}
	BIT_VEC cppVar_88278 = PC + 1;
	cppVar_88278 = (cppVar_88278 & cppMask_un_16_);
	BIT_VEC cppVar_88279 = ROM.rd(cppVar_88278);
	BIT_VEC cppVar_88280 = (cppVar_88279 >> 0) & cppMask_un_3_;
	BIT_VEC cppVar_88281 = (cppVar_87884 >> static_cast<unsigned>(cppVar_88280)) & 0x1;
	BIT_VEC cppVar_88282 = ~cppVar_88281;
	BIT_VEC cppVar_88283 = (cppVar_88282 & cppMask_un_1_);
	BIT_VEC cppVar_88284 = PC + 1;
	cppVar_88284 = (cppVar_88284 & cppMask_un_16_);
	BIT_VEC cppVar_88285 = ROM.rd(cppVar_88284);
	BIT_VEC cppVar_88286 = (cppVar_88285 >> 0) & cppMask_un_3_;
	BIT_VEC cppVar_88287 = (cppVar_88286 & cppMask_un_3_);
	BIT_VEC cppVar_88288 = cppVar_88283 << static_cast<unsigned>(cppVar_88287);
	cppVar_88288 = (cppVar_88288 & cppMask_un_8_);
	BIT_VEC cppVar_88289 = cppVar_87883 | cppVar_88288;
	type_mem cppVar_88290 = IRAM;
	cppVar_88290.wr(cppVar_87471, cppVar_88289);
	cppVar_87449 = cppVar_88290;
	} else {
	cppVar_87449 = IRAM;
	}
	cppVar_87445 = cppVar_87449;
	} else {
	type_mem cppVar_88291;
	BIT_VEC cppVar_88292 = ROM.rd(PC);
	bool cppVar_88294 = (cppVar_88292 == 175);
	if (cppVar_88294) {
	type_mem cppVar_88295;
	BIT_VEC cppVar_88297 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_88299 = (cppVar_88297 << 3) | 7;
	cppVar_88299 = (cppVar_88299 & cppMask_un_5_);
	BIT_VEC cppVar_88300 = (0 << 5) | cppVar_88299;
	cppVar_88300 = (cppVar_88300 & cppMask_un_8_);
	BIT_VEC cppVar_88301 = (cppVar_88300 >> 7) & cppMask_un_1_;
	bool cppVar_88303 = (cppVar_88301 == 0);
	if (cppVar_88303) {
	BIT_VEC cppVar_88304 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_88305 = (cppVar_88304 << 3) | 7;
	cppVar_88305 = (cppVar_88305 & cppMask_un_5_);
	BIT_VEC cppVar_88306 = (0 << 5) | cppVar_88305;
	cppVar_88306 = (cppVar_88306 & cppMask_un_8_);
	BIT_VEC cppVar_88307;
	BIT_VEC cppVar_88309 = PC + 1;
	cppVar_88309 = (cppVar_88309 & cppMask_un_16_);
	BIT_VEC cppVar_88310 = ROM.rd(cppVar_88309);
	BIT_VEC cppVar_88311 = (cppVar_88310 >> 7) & cppMask_un_1_;
	bool cppVar_88313 = (cppVar_88311 == 0);
	if (cppVar_88313) {
	BIT_VEC cppVar_88314 = PC + 1;
	cppVar_88314 = (cppVar_88314 & cppMask_un_16_);
	BIT_VEC cppVar_88315 = ROM.rd(cppVar_88314);
	BIT_VEC cppVar_88316 = IRAM.rd(cppVar_88315);
	cppVar_88307 = cppVar_88316;
	} else {
	BIT_VEC cppVar_88317;
	BIT_VEC cppVar_88318 = PC + 1;
	cppVar_88318 = (cppVar_88318 & cppMask_un_16_);
	BIT_VEC cppVar_88319 = ROM.rd(cppVar_88318);
	bool cppVar_88321 = (cppVar_88319 == 128);
	if (cppVar_88321) {
	cppVar_88317 = P0;
	} else {
	BIT_VEC cppVar_88322;
	BIT_VEC cppVar_88323 = PC + 1;
	cppVar_88323 = (cppVar_88323 & cppMask_un_16_);
	BIT_VEC cppVar_88324 = ROM.rd(cppVar_88323);
	bool cppVar_88326 = (cppVar_88324 == 129);
	if (cppVar_88326) {
	cppVar_88322 = SP;
	} else {
	BIT_VEC cppVar_88327;
	BIT_VEC cppVar_88328 = PC + 1;
	cppVar_88328 = (cppVar_88328 & cppMask_un_16_);
	BIT_VEC cppVar_88329 = ROM.rd(cppVar_88328);
	bool cppVar_88331 = (cppVar_88329 == 130);
	if (cppVar_88331) {
	cppVar_88327 = DPL;
	} else {
	BIT_VEC cppVar_88332;
	BIT_VEC cppVar_88333 = PC + 1;
	cppVar_88333 = (cppVar_88333 & cppMask_un_16_);
	BIT_VEC cppVar_88334 = ROM.rd(cppVar_88333);
	bool cppVar_88336 = (cppVar_88334 == 131);
	if (cppVar_88336) {
	cppVar_88332 = DPH;
	} else {
	BIT_VEC cppVar_88337;
	BIT_VEC cppVar_88338 = PC + 1;
	cppVar_88338 = (cppVar_88338 & cppMask_un_16_);
	BIT_VEC cppVar_88339 = ROM.rd(cppVar_88338);
	bool cppVar_88341 = (cppVar_88339 == 135);
	if (cppVar_88341) {
	cppVar_88337 = PCON;
	} else {
	BIT_VEC cppVar_88342;
	BIT_VEC cppVar_88343 = PC + 1;
	cppVar_88343 = (cppVar_88343 & cppMask_un_16_);
	BIT_VEC cppVar_88344 = ROM.rd(cppVar_88343);
	bool cppVar_88346 = (cppVar_88344 == 136);
	if (cppVar_88346) {
	cppVar_88342 = TCON;
	} else {
	BIT_VEC cppVar_88347;
	BIT_VEC cppVar_88348 = PC + 1;
	cppVar_88348 = (cppVar_88348 & cppMask_un_16_);
	BIT_VEC cppVar_88349 = ROM.rd(cppVar_88348);
	bool cppVar_88351 = (cppVar_88349 == 137);
	if (cppVar_88351) {
	cppVar_88347 = TMOD;
	} else {
	BIT_VEC cppVar_88352;
	BIT_VEC cppVar_88353 = PC + 1;
	cppVar_88353 = (cppVar_88353 & cppMask_un_16_);
	BIT_VEC cppVar_88354 = ROM.rd(cppVar_88353);
	bool cppVar_88356 = (cppVar_88354 == 138);
	if (cppVar_88356) {
	cppVar_88352 = TL0;
	} else {
	BIT_VEC cppVar_88357;
	BIT_VEC cppVar_88358 = PC + 1;
	cppVar_88358 = (cppVar_88358 & cppMask_un_16_);
	BIT_VEC cppVar_88359 = ROM.rd(cppVar_88358);
	bool cppVar_88361 = (cppVar_88359 == 140);
	if (cppVar_88361) {
	cppVar_88357 = TH0;
	} else {
	BIT_VEC cppVar_88362;
	BIT_VEC cppVar_88363 = PC + 1;
	cppVar_88363 = (cppVar_88363 & cppMask_un_16_);
	BIT_VEC cppVar_88364 = ROM.rd(cppVar_88363);
	bool cppVar_88366 = (cppVar_88364 == 139);
	if (cppVar_88366) {
	cppVar_88362 = TL1;
	} else {
	BIT_VEC cppVar_88367;
	BIT_VEC cppVar_88368 = PC + 1;
	cppVar_88368 = (cppVar_88368 & cppMask_un_16_);
	BIT_VEC cppVar_88369 = ROM.rd(cppVar_88368);
	bool cppVar_88371 = (cppVar_88369 == 141);
	if (cppVar_88371) {
	cppVar_88367 = TH1;
	} else {
	BIT_VEC cppVar_88372;
	BIT_VEC cppVar_88373 = PC + 1;
	cppVar_88373 = (cppVar_88373 & cppMask_un_16_);
	BIT_VEC cppVar_88374 = ROM.rd(cppVar_88373);
	bool cppVar_88376 = (cppVar_88374 == 144);
	if (cppVar_88376) {
	cppVar_88372 = P1;
	} else {
	BIT_VEC cppVar_88377;
	BIT_VEC cppVar_88378 = PC + 1;
	cppVar_88378 = (cppVar_88378 & cppMask_un_16_);
	BIT_VEC cppVar_88379 = ROM.rd(cppVar_88378);
	bool cppVar_88381 = (cppVar_88379 == 152);
	if (cppVar_88381) {
	cppVar_88377 = SCON;
	} else {
	BIT_VEC cppVar_88382;
	BIT_VEC cppVar_88383 = PC + 1;
	cppVar_88383 = (cppVar_88383 & cppMask_un_16_);
	BIT_VEC cppVar_88384 = ROM.rd(cppVar_88383);
	bool cppVar_88386 = (cppVar_88384 == 153);
	if (cppVar_88386) {
	cppVar_88382 = SBUF;
	} else {
	BIT_VEC cppVar_88387;
	BIT_VEC cppVar_88388 = PC + 1;
	cppVar_88388 = (cppVar_88388 & cppMask_un_16_);
	BIT_VEC cppVar_88389 = ROM.rd(cppVar_88388);
	bool cppVar_88391 = (cppVar_88389 == 160);
	if (cppVar_88391) {
	cppVar_88387 = P2;
	} else {
	BIT_VEC cppVar_88392;
	BIT_VEC cppVar_88393 = PC + 1;
	cppVar_88393 = (cppVar_88393 & cppMask_un_16_);
	BIT_VEC cppVar_88394 = ROM.rd(cppVar_88393);
	bool cppVar_88396 = (cppVar_88394 == 168);
	if (cppVar_88396) {
	cppVar_88392 = IE;
	} else {
	BIT_VEC cppVar_88397;
	BIT_VEC cppVar_88398 = PC + 1;
	cppVar_88398 = (cppVar_88398 & cppMask_un_16_);
	BIT_VEC cppVar_88399 = ROM.rd(cppVar_88398);
	bool cppVar_88401 = (cppVar_88399 == 176);
	if (cppVar_88401) {
	cppVar_88397 = P3;
	} else {
	BIT_VEC cppVar_88402;
	BIT_VEC cppVar_88403 = PC + 1;
	cppVar_88403 = (cppVar_88403 & cppMask_un_16_);
	BIT_VEC cppVar_88404 = ROM.rd(cppVar_88403);
	bool cppVar_88406 = (cppVar_88404 == 184);
	if (cppVar_88406) {
	cppVar_88402 = IP;
	} else {
	BIT_VEC cppVar_88407;
	BIT_VEC cppVar_88408 = PC + 1;
	cppVar_88408 = (cppVar_88408 & cppMask_un_16_);
	BIT_VEC cppVar_88409 = ROM.rd(cppVar_88408);
	bool cppVar_88411 = (cppVar_88409 == 208);
	if (cppVar_88411) {
	cppVar_88407 = PSW;
	} else {
	BIT_VEC cppVar_88412;
	BIT_VEC cppVar_88413 = PC + 1;
	cppVar_88413 = (cppVar_88413 & cppMask_un_16_);
	BIT_VEC cppVar_88414 = ROM.rd(cppVar_88413);
	bool cppVar_88416 = (cppVar_88414 == 224);
	if (cppVar_88416) {
	cppVar_88412 = ACC;
	} else {
	BIT_VEC cppVar_88417;
	BIT_VEC cppVar_88418 = PC + 1;
	cppVar_88418 = (cppVar_88418 & cppMask_un_16_);
	BIT_VEC cppVar_88419 = ROM.rd(cppVar_88418);
	bool cppVar_88421 = (cppVar_88419 == 240);
	if (cppVar_88421) {
	cppVar_88417 = B;
	} else {
	cppVar_88417 = 0;
	}
	cppVar_88412 = cppVar_88417;
	}
	cppVar_88407 = cppVar_88412;
	}
	cppVar_88402 = cppVar_88407;
	}
	cppVar_88397 = cppVar_88402;
	}
	cppVar_88392 = cppVar_88397;
	}
	cppVar_88387 = cppVar_88392;
	}
	cppVar_88382 = cppVar_88387;
	}
	cppVar_88377 = cppVar_88382;
	}
	cppVar_88372 = cppVar_88377;
	}
	cppVar_88367 = cppVar_88372;
	}
	cppVar_88362 = cppVar_88367;
	}
	cppVar_88357 = cppVar_88362;
	}
	cppVar_88352 = cppVar_88357;
	}
	cppVar_88347 = cppVar_88352;
	}
	cppVar_88342 = cppVar_88347;
	}
	cppVar_88337 = cppVar_88342;
	}
	cppVar_88332 = cppVar_88337;
	}
	cppVar_88327 = cppVar_88332;
	}
	cppVar_88322 = cppVar_88327;
	}
	cppVar_88317 = cppVar_88322;
	}
	cppVar_88307 = cppVar_88317;
	}
	type_mem cppVar_88423 = IRAM;
	cppVar_88423.wr(cppVar_88306, cppVar_88307);
	cppVar_88295 = cppVar_88423;
	} else {
	cppVar_88295 = IRAM;
	}
	cppVar_88291 = cppVar_88295;
	} else {
	type_mem cppVar_88424;
	BIT_VEC cppVar_88425 = ROM.rd(PC);
	bool cppVar_88427 = (cppVar_88425 == 174);
	if (cppVar_88427) {
	type_mem cppVar_88428;
	BIT_VEC cppVar_88430 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_88432 = (cppVar_88430 << 3) | 6;
	cppVar_88432 = (cppVar_88432 & cppMask_un_5_);
	BIT_VEC cppVar_88433 = (0 << 5) | cppVar_88432;
	cppVar_88433 = (cppVar_88433 & cppMask_un_8_);
	BIT_VEC cppVar_88434 = (cppVar_88433 >> 7) & cppMask_un_1_;
	bool cppVar_88436 = (cppVar_88434 == 0);
	if (cppVar_88436) {
	BIT_VEC cppVar_88437 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_88438 = (cppVar_88437 << 3) | 6;
	cppVar_88438 = (cppVar_88438 & cppMask_un_5_);
	BIT_VEC cppVar_88439 = (0 << 5) | cppVar_88438;
	cppVar_88439 = (cppVar_88439 & cppMask_un_8_);
	BIT_VEC cppVar_88440;
	BIT_VEC cppVar_88442 = PC + 1;
	cppVar_88442 = (cppVar_88442 & cppMask_un_16_);
	BIT_VEC cppVar_88443 = ROM.rd(cppVar_88442);
	BIT_VEC cppVar_88444 = (cppVar_88443 >> 7) & cppMask_un_1_;
	bool cppVar_88446 = (cppVar_88444 == 0);
	if (cppVar_88446) {
	BIT_VEC cppVar_88447 = PC + 1;
	cppVar_88447 = (cppVar_88447 & cppMask_un_16_);
	BIT_VEC cppVar_88448 = ROM.rd(cppVar_88447);
	BIT_VEC cppVar_88449 = IRAM.rd(cppVar_88448);
	cppVar_88440 = cppVar_88449;
	} else {
	BIT_VEC cppVar_88450;
	BIT_VEC cppVar_88451 = PC + 1;
	cppVar_88451 = (cppVar_88451 & cppMask_un_16_);
	BIT_VEC cppVar_88452 = ROM.rd(cppVar_88451);
	bool cppVar_88454 = (cppVar_88452 == 128);
	if (cppVar_88454) {
	cppVar_88450 = P0;
	} else {
	BIT_VEC cppVar_88455;
	BIT_VEC cppVar_88456 = PC + 1;
	cppVar_88456 = (cppVar_88456 & cppMask_un_16_);
	BIT_VEC cppVar_88457 = ROM.rd(cppVar_88456);
	bool cppVar_88459 = (cppVar_88457 == 129);
	if (cppVar_88459) {
	cppVar_88455 = SP;
	} else {
	BIT_VEC cppVar_88460;
	BIT_VEC cppVar_88461 = PC + 1;
	cppVar_88461 = (cppVar_88461 & cppMask_un_16_);
	BIT_VEC cppVar_88462 = ROM.rd(cppVar_88461);
	bool cppVar_88464 = (cppVar_88462 == 130);
	if (cppVar_88464) {
	cppVar_88460 = DPL;
	} else {
	BIT_VEC cppVar_88465;
	BIT_VEC cppVar_88466 = PC + 1;
	cppVar_88466 = (cppVar_88466 & cppMask_un_16_);
	BIT_VEC cppVar_88467 = ROM.rd(cppVar_88466);
	bool cppVar_88469 = (cppVar_88467 == 131);
	if (cppVar_88469) {
	cppVar_88465 = DPH;
	} else {
	BIT_VEC cppVar_88470;
	BIT_VEC cppVar_88471 = PC + 1;
	cppVar_88471 = (cppVar_88471 & cppMask_un_16_);
	BIT_VEC cppVar_88472 = ROM.rd(cppVar_88471);
	bool cppVar_88474 = (cppVar_88472 == 135);
	if (cppVar_88474) {
	cppVar_88470 = PCON;
	} else {
	BIT_VEC cppVar_88475;
	BIT_VEC cppVar_88476 = PC + 1;
	cppVar_88476 = (cppVar_88476 & cppMask_un_16_);
	BIT_VEC cppVar_88477 = ROM.rd(cppVar_88476);
	bool cppVar_88479 = (cppVar_88477 == 136);
	if (cppVar_88479) {
	cppVar_88475 = TCON;
	} else {
	BIT_VEC cppVar_88480;
	BIT_VEC cppVar_88481 = PC + 1;
	cppVar_88481 = (cppVar_88481 & cppMask_un_16_);
	BIT_VEC cppVar_88482 = ROM.rd(cppVar_88481);
	bool cppVar_88484 = (cppVar_88482 == 137);
	if (cppVar_88484) {
	cppVar_88480 = TMOD;
	} else {
	BIT_VEC cppVar_88485;
	BIT_VEC cppVar_88486 = PC + 1;
	cppVar_88486 = (cppVar_88486 & cppMask_un_16_);
	BIT_VEC cppVar_88487 = ROM.rd(cppVar_88486);
	bool cppVar_88489 = (cppVar_88487 == 138);
	if (cppVar_88489) {
	cppVar_88485 = TL0;
	} else {
	BIT_VEC cppVar_88490;
	BIT_VEC cppVar_88491 = PC + 1;
	cppVar_88491 = (cppVar_88491 & cppMask_un_16_);
	BIT_VEC cppVar_88492 = ROM.rd(cppVar_88491);
	bool cppVar_88494 = (cppVar_88492 == 140);
	if (cppVar_88494) {
	cppVar_88490 = TH0;
	} else {
	BIT_VEC cppVar_88495;
	BIT_VEC cppVar_88496 = PC + 1;
	cppVar_88496 = (cppVar_88496 & cppMask_un_16_);
	BIT_VEC cppVar_88497 = ROM.rd(cppVar_88496);
	bool cppVar_88499 = (cppVar_88497 == 139);
	if (cppVar_88499) {
	cppVar_88495 = TL1;
	} else {
	BIT_VEC cppVar_88500;
	BIT_VEC cppVar_88501 = PC + 1;
	cppVar_88501 = (cppVar_88501 & cppMask_un_16_);
	BIT_VEC cppVar_88502 = ROM.rd(cppVar_88501);
	bool cppVar_88504 = (cppVar_88502 == 141);
	if (cppVar_88504) {
	cppVar_88500 = TH1;
	} else {
	BIT_VEC cppVar_88505;
	BIT_VEC cppVar_88506 = PC + 1;
	cppVar_88506 = (cppVar_88506 & cppMask_un_16_);
	BIT_VEC cppVar_88507 = ROM.rd(cppVar_88506);
	bool cppVar_88509 = (cppVar_88507 == 144);
	if (cppVar_88509) {
	cppVar_88505 = P1;
	} else {
	BIT_VEC cppVar_88510;
	BIT_VEC cppVar_88511 = PC + 1;
	cppVar_88511 = (cppVar_88511 & cppMask_un_16_);
	BIT_VEC cppVar_88512 = ROM.rd(cppVar_88511);
	bool cppVar_88514 = (cppVar_88512 == 152);
	if (cppVar_88514) {
	cppVar_88510 = SCON;
	} else {
	BIT_VEC cppVar_88515;
	BIT_VEC cppVar_88516 = PC + 1;
	cppVar_88516 = (cppVar_88516 & cppMask_un_16_);
	BIT_VEC cppVar_88517 = ROM.rd(cppVar_88516);
	bool cppVar_88519 = (cppVar_88517 == 153);
	if (cppVar_88519) {
	cppVar_88515 = SBUF;
	} else {
	BIT_VEC cppVar_88520;
	BIT_VEC cppVar_88521 = PC + 1;
	cppVar_88521 = (cppVar_88521 & cppMask_un_16_);
	BIT_VEC cppVar_88522 = ROM.rd(cppVar_88521);
	bool cppVar_88524 = (cppVar_88522 == 160);
	if (cppVar_88524) {
	cppVar_88520 = P2;
	} else {
	BIT_VEC cppVar_88525;
	BIT_VEC cppVar_88526 = PC + 1;
	cppVar_88526 = (cppVar_88526 & cppMask_un_16_);
	BIT_VEC cppVar_88527 = ROM.rd(cppVar_88526);
	bool cppVar_88529 = (cppVar_88527 == 168);
	if (cppVar_88529) {
	cppVar_88525 = IE;
	} else {
	BIT_VEC cppVar_88530;
	BIT_VEC cppVar_88531 = PC + 1;
	cppVar_88531 = (cppVar_88531 & cppMask_un_16_);
	BIT_VEC cppVar_88532 = ROM.rd(cppVar_88531);
	bool cppVar_88534 = (cppVar_88532 == 176);
	if (cppVar_88534) {
	cppVar_88530 = P3;
	} else {
	BIT_VEC cppVar_88535;
	BIT_VEC cppVar_88536 = PC + 1;
	cppVar_88536 = (cppVar_88536 & cppMask_un_16_);
	BIT_VEC cppVar_88537 = ROM.rd(cppVar_88536);
	bool cppVar_88539 = (cppVar_88537 == 184);
	if (cppVar_88539) {
	cppVar_88535 = IP;
	} else {
	BIT_VEC cppVar_88540;
	BIT_VEC cppVar_88541 = PC + 1;
	cppVar_88541 = (cppVar_88541 & cppMask_un_16_);
	BIT_VEC cppVar_88542 = ROM.rd(cppVar_88541);
	bool cppVar_88544 = (cppVar_88542 == 208);
	if (cppVar_88544) {
	cppVar_88540 = PSW;
	} else {
	BIT_VEC cppVar_88545;
	BIT_VEC cppVar_88546 = PC + 1;
	cppVar_88546 = (cppVar_88546 & cppMask_un_16_);
	BIT_VEC cppVar_88547 = ROM.rd(cppVar_88546);
	bool cppVar_88549 = (cppVar_88547 == 224);
	if (cppVar_88549) {
	cppVar_88545 = ACC;
	} else {
	BIT_VEC cppVar_88550;
	BIT_VEC cppVar_88551 = PC + 1;
	cppVar_88551 = (cppVar_88551 & cppMask_un_16_);
	BIT_VEC cppVar_88552 = ROM.rd(cppVar_88551);
	bool cppVar_88554 = (cppVar_88552 == 240);
	if (cppVar_88554) {
	cppVar_88550 = B;
	} else {
	cppVar_88550 = 0;
	}
	cppVar_88545 = cppVar_88550;
	}
	cppVar_88540 = cppVar_88545;
	}
	cppVar_88535 = cppVar_88540;
	}
	cppVar_88530 = cppVar_88535;
	}
	cppVar_88525 = cppVar_88530;
	}
	cppVar_88520 = cppVar_88525;
	}
	cppVar_88515 = cppVar_88520;
	}
	cppVar_88510 = cppVar_88515;
	}
	cppVar_88505 = cppVar_88510;
	}
	cppVar_88500 = cppVar_88505;
	}
	cppVar_88495 = cppVar_88500;
	}
	cppVar_88490 = cppVar_88495;
	}
	cppVar_88485 = cppVar_88490;
	}
	cppVar_88480 = cppVar_88485;
	}
	cppVar_88475 = cppVar_88480;
	}
	cppVar_88470 = cppVar_88475;
	}
	cppVar_88465 = cppVar_88470;
	}
	cppVar_88460 = cppVar_88465;
	}
	cppVar_88455 = cppVar_88460;
	}
	cppVar_88450 = cppVar_88455;
	}
	cppVar_88440 = cppVar_88450;
	}
	type_mem cppVar_88556 = IRAM;
	cppVar_88556.wr(cppVar_88439, cppVar_88440);
	cppVar_88428 = cppVar_88556;
	} else {
	cppVar_88428 = IRAM;
	}
	cppVar_88424 = cppVar_88428;
	} else {
	type_mem cppVar_88557;
	BIT_VEC cppVar_88558 = ROM.rd(PC);
	bool cppVar_88560 = (cppVar_88558 == 173);
	if (cppVar_88560) {
	type_mem cppVar_88561;
	BIT_VEC cppVar_88563 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_88565 = (cppVar_88563 << 3) | 5;
	cppVar_88565 = (cppVar_88565 & cppMask_un_5_);
	BIT_VEC cppVar_88566 = (0 << 5) | cppVar_88565;
	cppVar_88566 = (cppVar_88566 & cppMask_un_8_);
	BIT_VEC cppVar_88567 = (cppVar_88566 >> 7) & cppMask_un_1_;
	bool cppVar_88569 = (cppVar_88567 == 0);
	if (cppVar_88569) {
	BIT_VEC cppVar_88570 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_88571 = (cppVar_88570 << 3) | 5;
	cppVar_88571 = (cppVar_88571 & cppMask_un_5_);
	BIT_VEC cppVar_88572 = (0 << 5) | cppVar_88571;
	cppVar_88572 = (cppVar_88572 & cppMask_un_8_);
	BIT_VEC cppVar_88573;
	BIT_VEC cppVar_88575 = PC + 1;
	cppVar_88575 = (cppVar_88575 & cppMask_un_16_);
	BIT_VEC cppVar_88576 = ROM.rd(cppVar_88575);
	BIT_VEC cppVar_88577 = (cppVar_88576 >> 7) & cppMask_un_1_;
	bool cppVar_88579 = (cppVar_88577 == 0);
	if (cppVar_88579) {
	BIT_VEC cppVar_88580 = PC + 1;
	cppVar_88580 = (cppVar_88580 & cppMask_un_16_);
	BIT_VEC cppVar_88581 = ROM.rd(cppVar_88580);
	BIT_VEC cppVar_88582 = IRAM.rd(cppVar_88581);
	cppVar_88573 = cppVar_88582;
	} else {
	BIT_VEC cppVar_88583;
	BIT_VEC cppVar_88584 = PC + 1;
	cppVar_88584 = (cppVar_88584 & cppMask_un_16_);
	BIT_VEC cppVar_88585 = ROM.rd(cppVar_88584);
	bool cppVar_88587 = (cppVar_88585 == 128);
	if (cppVar_88587) {
	cppVar_88583 = P0;
	} else {
	BIT_VEC cppVar_88588;
	BIT_VEC cppVar_88589 = PC + 1;
	cppVar_88589 = (cppVar_88589 & cppMask_un_16_);
	BIT_VEC cppVar_88590 = ROM.rd(cppVar_88589);
	bool cppVar_88592 = (cppVar_88590 == 129);
	if (cppVar_88592) {
	cppVar_88588 = SP;
	} else {
	BIT_VEC cppVar_88593;
	BIT_VEC cppVar_88594 = PC + 1;
	cppVar_88594 = (cppVar_88594 & cppMask_un_16_);
	BIT_VEC cppVar_88595 = ROM.rd(cppVar_88594);
	bool cppVar_88597 = (cppVar_88595 == 130);
	if (cppVar_88597) {
	cppVar_88593 = DPL;
	} else {
	BIT_VEC cppVar_88598;
	BIT_VEC cppVar_88599 = PC + 1;
	cppVar_88599 = (cppVar_88599 & cppMask_un_16_);
	BIT_VEC cppVar_88600 = ROM.rd(cppVar_88599);
	bool cppVar_88602 = (cppVar_88600 == 131);
	if (cppVar_88602) {
	cppVar_88598 = DPH;
	} else {
	BIT_VEC cppVar_88603;
	BIT_VEC cppVar_88604 = PC + 1;
	cppVar_88604 = (cppVar_88604 & cppMask_un_16_);
	BIT_VEC cppVar_88605 = ROM.rd(cppVar_88604);
	bool cppVar_88607 = (cppVar_88605 == 135);
	if (cppVar_88607) {
	cppVar_88603 = PCON;
	} else {
	BIT_VEC cppVar_88608;
	BIT_VEC cppVar_88609 = PC + 1;
	cppVar_88609 = (cppVar_88609 & cppMask_un_16_);
	BIT_VEC cppVar_88610 = ROM.rd(cppVar_88609);
	bool cppVar_88612 = (cppVar_88610 == 136);
	if (cppVar_88612) {
	cppVar_88608 = TCON;
	} else {
	BIT_VEC cppVar_88613;
	BIT_VEC cppVar_88614 = PC + 1;
	cppVar_88614 = (cppVar_88614 & cppMask_un_16_);
	BIT_VEC cppVar_88615 = ROM.rd(cppVar_88614);
	bool cppVar_88617 = (cppVar_88615 == 137);
	if (cppVar_88617) {
	cppVar_88613 = TMOD;
	} else {
	BIT_VEC cppVar_88618;
	BIT_VEC cppVar_88619 = PC + 1;
	cppVar_88619 = (cppVar_88619 & cppMask_un_16_);
	BIT_VEC cppVar_88620 = ROM.rd(cppVar_88619);
	bool cppVar_88622 = (cppVar_88620 == 138);
	if (cppVar_88622) {
	cppVar_88618 = TL0;
	} else {
	BIT_VEC cppVar_88623;
	BIT_VEC cppVar_88624 = PC + 1;
	cppVar_88624 = (cppVar_88624 & cppMask_un_16_);
	BIT_VEC cppVar_88625 = ROM.rd(cppVar_88624);
	bool cppVar_88627 = (cppVar_88625 == 140);
	if (cppVar_88627) {
	cppVar_88623 = TH0;
	} else {
	BIT_VEC cppVar_88628;
	BIT_VEC cppVar_88629 = PC + 1;
	cppVar_88629 = (cppVar_88629 & cppMask_un_16_);
	BIT_VEC cppVar_88630 = ROM.rd(cppVar_88629);
	bool cppVar_88632 = (cppVar_88630 == 139);
	if (cppVar_88632) {
	cppVar_88628 = TL1;
	} else {
	BIT_VEC cppVar_88633;
	BIT_VEC cppVar_88634 = PC + 1;
	cppVar_88634 = (cppVar_88634 & cppMask_un_16_);
	BIT_VEC cppVar_88635 = ROM.rd(cppVar_88634);
	bool cppVar_88637 = (cppVar_88635 == 141);
	if (cppVar_88637) {
	cppVar_88633 = TH1;
	} else {
	BIT_VEC cppVar_88638;
	BIT_VEC cppVar_88639 = PC + 1;
	cppVar_88639 = (cppVar_88639 & cppMask_un_16_);
	BIT_VEC cppVar_88640 = ROM.rd(cppVar_88639);
	bool cppVar_88642 = (cppVar_88640 == 144);
	if (cppVar_88642) {
	cppVar_88638 = P1;
	} else {
	BIT_VEC cppVar_88643;
	BIT_VEC cppVar_88644 = PC + 1;
	cppVar_88644 = (cppVar_88644 & cppMask_un_16_);
	BIT_VEC cppVar_88645 = ROM.rd(cppVar_88644);
	bool cppVar_88647 = (cppVar_88645 == 152);
	if (cppVar_88647) {
	cppVar_88643 = SCON;
	} else {
	BIT_VEC cppVar_88648;
	BIT_VEC cppVar_88649 = PC + 1;
	cppVar_88649 = (cppVar_88649 & cppMask_un_16_);
	BIT_VEC cppVar_88650 = ROM.rd(cppVar_88649);
	bool cppVar_88652 = (cppVar_88650 == 153);
	if (cppVar_88652) {
	cppVar_88648 = SBUF;
	} else {
	BIT_VEC cppVar_88653;
	BIT_VEC cppVar_88654 = PC + 1;
	cppVar_88654 = (cppVar_88654 & cppMask_un_16_);
	BIT_VEC cppVar_88655 = ROM.rd(cppVar_88654);
	bool cppVar_88657 = (cppVar_88655 == 160);
	if (cppVar_88657) {
	cppVar_88653 = P2;
	} else {
	BIT_VEC cppVar_88658;
	BIT_VEC cppVar_88659 = PC + 1;
	cppVar_88659 = (cppVar_88659 & cppMask_un_16_);
	BIT_VEC cppVar_88660 = ROM.rd(cppVar_88659);
	bool cppVar_88662 = (cppVar_88660 == 168);
	if (cppVar_88662) {
	cppVar_88658 = IE;
	} else {
	BIT_VEC cppVar_88663;
	BIT_VEC cppVar_88664 = PC + 1;
	cppVar_88664 = (cppVar_88664 & cppMask_un_16_);
	BIT_VEC cppVar_88665 = ROM.rd(cppVar_88664);
	bool cppVar_88667 = (cppVar_88665 == 176);
	if (cppVar_88667) {
	cppVar_88663 = P3;
	} else {
	BIT_VEC cppVar_88668;
	BIT_VEC cppVar_88669 = PC + 1;
	cppVar_88669 = (cppVar_88669 & cppMask_un_16_);
	BIT_VEC cppVar_88670 = ROM.rd(cppVar_88669);
	bool cppVar_88672 = (cppVar_88670 == 184);
	if (cppVar_88672) {
	cppVar_88668 = IP;
	} else {
	BIT_VEC cppVar_88673;
	BIT_VEC cppVar_88674 = PC + 1;
	cppVar_88674 = (cppVar_88674 & cppMask_un_16_);
	BIT_VEC cppVar_88675 = ROM.rd(cppVar_88674);
	bool cppVar_88677 = (cppVar_88675 == 208);
	if (cppVar_88677) {
	cppVar_88673 = PSW;
	} else {
	BIT_VEC cppVar_88678;
	BIT_VEC cppVar_88679 = PC + 1;
	cppVar_88679 = (cppVar_88679 & cppMask_un_16_);
	BIT_VEC cppVar_88680 = ROM.rd(cppVar_88679);
	bool cppVar_88682 = (cppVar_88680 == 224);
	if (cppVar_88682) {
	cppVar_88678 = ACC;
	} else {
	BIT_VEC cppVar_88683;
	BIT_VEC cppVar_88684 = PC + 1;
	cppVar_88684 = (cppVar_88684 & cppMask_un_16_);
	BIT_VEC cppVar_88685 = ROM.rd(cppVar_88684);
	bool cppVar_88687 = (cppVar_88685 == 240);
	if (cppVar_88687) {
	cppVar_88683 = B;
	} else {
	cppVar_88683 = 0;
	}
	cppVar_88678 = cppVar_88683;
	}
	cppVar_88673 = cppVar_88678;
	}
	cppVar_88668 = cppVar_88673;
	}
	cppVar_88663 = cppVar_88668;
	}
	cppVar_88658 = cppVar_88663;
	}
	cppVar_88653 = cppVar_88658;
	}
	cppVar_88648 = cppVar_88653;
	}
	cppVar_88643 = cppVar_88648;
	}
	cppVar_88638 = cppVar_88643;
	}
	cppVar_88633 = cppVar_88638;
	}
	cppVar_88628 = cppVar_88633;
	}
	cppVar_88623 = cppVar_88628;
	}
	cppVar_88618 = cppVar_88623;
	}
	cppVar_88613 = cppVar_88618;
	}
	cppVar_88608 = cppVar_88613;
	}
	cppVar_88603 = cppVar_88608;
	}
	cppVar_88598 = cppVar_88603;
	}
	cppVar_88593 = cppVar_88598;
	}
	cppVar_88588 = cppVar_88593;
	}
	cppVar_88583 = cppVar_88588;
	}
	cppVar_88573 = cppVar_88583;
	}
	type_mem cppVar_88689 = IRAM;
	cppVar_88689.wr(cppVar_88572, cppVar_88573);
	cppVar_88561 = cppVar_88689;
	} else {
	cppVar_88561 = IRAM;
	}
	cppVar_88557 = cppVar_88561;
	} else {
	type_mem cppVar_88690;
	BIT_VEC cppVar_88691 = ROM.rd(PC);
	bool cppVar_88693 = (cppVar_88691 == 172);
	if (cppVar_88693) {
	type_mem cppVar_88694;
	BIT_VEC cppVar_88696 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_88698 = (cppVar_88696 << 3) | 4;
	cppVar_88698 = (cppVar_88698 & cppMask_un_5_);
	BIT_VEC cppVar_88699 = (0 << 5) | cppVar_88698;
	cppVar_88699 = (cppVar_88699 & cppMask_un_8_);
	BIT_VEC cppVar_88700 = (cppVar_88699 >> 7) & cppMask_un_1_;
	bool cppVar_88702 = (cppVar_88700 == 0);
	if (cppVar_88702) {
	BIT_VEC cppVar_88703 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_88704 = (cppVar_88703 << 3) | 4;
	cppVar_88704 = (cppVar_88704 & cppMask_un_5_);
	BIT_VEC cppVar_88705 = (0 << 5) | cppVar_88704;
	cppVar_88705 = (cppVar_88705 & cppMask_un_8_);
	BIT_VEC cppVar_88706;
	BIT_VEC cppVar_88708 = PC + 1;
	cppVar_88708 = (cppVar_88708 & cppMask_un_16_);
	BIT_VEC cppVar_88709 = ROM.rd(cppVar_88708);
	BIT_VEC cppVar_88710 = (cppVar_88709 >> 7) & cppMask_un_1_;
	bool cppVar_88712 = (cppVar_88710 == 0);
	if (cppVar_88712) {
	BIT_VEC cppVar_88713 = PC + 1;
	cppVar_88713 = (cppVar_88713 & cppMask_un_16_);
	BIT_VEC cppVar_88714 = ROM.rd(cppVar_88713);
	BIT_VEC cppVar_88715 = IRAM.rd(cppVar_88714);
	cppVar_88706 = cppVar_88715;
	} else {
	BIT_VEC cppVar_88716;
	BIT_VEC cppVar_88717 = PC + 1;
	cppVar_88717 = (cppVar_88717 & cppMask_un_16_);
	BIT_VEC cppVar_88718 = ROM.rd(cppVar_88717);
	bool cppVar_88720 = (cppVar_88718 == 128);
	if (cppVar_88720) {
	cppVar_88716 = P0;
	} else {
	BIT_VEC cppVar_88721;
	BIT_VEC cppVar_88722 = PC + 1;
	cppVar_88722 = (cppVar_88722 & cppMask_un_16_);
	BIT_VEC cppVar_88723 = ROM.rd(cppVar_88722);
	bool cppVar_88725 = (cppVar_88723 == 129);
	if (cppVar_88725) {
	cppVar_88721 = SP;
	} else {
	BIT_VEC cppVar_88726;
	BIT_VEC cppVar_88727 = PC + 1;
	cppVar_88727 = (cppVar_88727 & cppMask_un_16_);
	BIT_VEC cppVar_88728 = ROM.rd(cppVar_88727);
	bool cppVar_88730 = (cppVar_88728 == 130);
	if (cppVar_88730) {
	cppVar_88726 = DPL;
	} else {
	BIT_VEC cppVar_88731;
	BIT_VEC cppVar_88732 = PC + 1;
	cppVar_88732 = (cppVar_88732 & cppMask_un_16_);
	BIT_VEC cppVar_88733 = ROM.rd(cppVar_88732);
	bool cppVar_88735 = (cppVar_88733 == 131);
	if (cppVar_88735) {
	cppVar_88731 = DPH;
	} else {
	BIT_VEC cppVar_88736;
	BIT_VEC cppVar_88737 = PC + 1;
	cppVar_88737 = (cppVar_88737 & cppMask_un_16_);
	BIT_VEC cppVar_88738 = ROM.rd(cppVar_88737);
	bool cppVar_88740 = (cppVar_88738 == 135);
	if (cppVar_88740) {
	cppVar_88736 = PCON;
	} else {
	BIT_VEC cppVar_88741;
	BIT_VEC cppVar_88742 = PC + 1;
	cppVar_88742 = (cppVar_88742 & cppMask_un_16_);
	BIT_VEC cppVar_88743 = ROM.rd(cppVar_88742);
	bool cppVar_88745 = (cppVar_88743 == 136);
	if (cppVar_88745) {
	cppVar_88741 = TCON;
	} else {
	BIT_VEC cppVar_88746;
	BIT_VEC cppVar_88747 = PC + 1;
	cppVar_88747 = (cppVar_88747 & cppMask_un_16_);
	BIT_VEC cppVar_88748 = ROM.rd(cppVar_88747);
	bool cppVar_88750 = (cppVar_88748 == 137);
	if (cppVar_88750) {
	cppVar_88746 = TMOD;
	} else {
	BIT_VEC cppVar_88751;
	BIT_VEC cppVar_88752 = PC + 1;
	cppVar_88752 = (cppVar_88752 & cppMask_un_16_);
	BIT_VEC cppVar_88753 = ROM.rd(cppVar_88752);
	bool cppVar_88755 = (cppVar_88753 == 138);
	if (cppVar_88755) {
	cppVar_88751 = TL0;
	} else {
	BIT_VEC cppVar_88756;
	BIT_VEC cppVar_88757 = PC + 1;
	cppVar_88757 = (cppVar_88757 & cppMask_un_16_);
	BIT_VEC cppVar_88758 = ROM.rd(cppVar_88757);
	bool cppVar_88760 = (cppVar_88758 == 140);
	if (cppVar_88760) {
	cppVar_88756 = TH0;
	} else {
	BIT_VEC cppVar_88761;
	BIT_VEC cppVar_88762 = PC + 1;
	cppVar_88762 = (cppVar_88762 & cppMask_un_16_);
	BIT_VEC cppVar_88763 = ROM.rd(cppVar_88762);
	bool cppVar_88765 = (cppVar_88763 == 139);
	if (cppVar_88765) {
	cppVar_88761 = TL1;
	} else {
	BIT_VEC cppVar_88766;
	BIT_VEC cppVar_88767 = PC + 1;
	cppVar_88767 = (cppVar_88767 & cppMask_un_16_);
	BIT_VEC cppVar_88768 = ROM.rd(cppVar_88767);
	bool cppVar_88770 = (cppVar_88768 == 141);
	if (cppVar_88770) {
	cppVar_88766 = TH1;
	} else {
	BIT_VEC cppVar_88771;
	BIT_VEC cppVar_88772 = PC + 1;
	cppVar_88772 = (cppVar_88772 & cppMask_un_16_);
	BIT_VEC cppVar_88773 = ROM.rd(cppVar_88772);
	bool cppVar_88775 = (cppVar_88773 == 144);
	if (cppVar_88775) {
	cppVar_88771 = P1;
	} else {
	BIT_VEC cppVar_88776;
	BIT_VEC cppVar_88777 = PC + 1;
	cppVar_88777 = (cppVar_88777 & cppMask_un_16_);
	BIT_VEC cppVar_88778 = ROM.rd(cppVar_88777);
	bool cppVar_88780 = (cppVar_88778 == 152);
	if (cppVar_88780) {
	cppVar_88776 = SCON;
	} else {
	BIT_VEC cppVar_88781;
	BIT_VEC cppVar_88782 = PC + 1;
	cppVar_88782 = (cppVar_88782 & cppMask_un_16_);
	BIT_VEC cppVar_88783 = ROM.rd(cppVar_88782);
	bool cppVar_88785 = (cppVar_88783 == 153);
	if (cppVar_88785) {
	cppVar_88781 = SBUF;
	} else {
	BIT_VEC cppVar_88786;
	BIT_VEC cppVar_88787 = PC + 1;
	cppVar_88787 = (cppVar_88787 & cppMask_un_16_);
	BIT_VEC cppVar_88788 = ROM.rd(cppVar_88787);
	bool cppVar_88790 = (cppVar_88788 == 160);
	if (cppVar_88790) {
	cppVar_88786 = P2;
	} else {
	BIT_VEC cppVar_88791;
	BIT_VEC cppVar_88792 = PC + 1;
	cppVar_88792 = (cppVar_88792 & cppMask_un_16_);
	BIT_VEC cppVar_88793 = ROM.rd(cppVar_88792);
	bool cppVar_88795 = (cppVar_88793 == 168);
	if (cppVar_88795) {
	cppVar_88791 = IE;
	} else {
	BIT_VEC cppVar_88796;
	BIT_VEC cppVar_88797 = PC + 1;
	cppVar_88797 = (cppVar_88797 & cppMask_un_16_);
	BIT_VEC cppVar_88798 = ROM.rd(cppVar_88797);
	bool cppVar_88800 = (cppVar_88798 == 176);
	if (cppVar_88800) {
	cppVar_88796 = P3;
	} else {
	BIT_VEC cppVar_88801;
	BIT_VEC cppVar_88802 = PC + 1;
	cppVar_88802 = (cppVar_88802 & cppMask_un_16_);
	BIT_VEC cppVar_88803 = ROM.rd(cppVar_88802);
	bool cppVar_88805 = (cppVar_88803 == 184);
	if (cppVar_88805) {
	cppVar_88801 = IP;
	} else {
	BIT_VEC cppVar_88806;
	BIT_VEC cppVar_88807 = PC + 1;
	cppVar_88807 = (cppVar_88807 & cppMask_un_16_);
	BIT_VEC cppVar_88808 = ROM.rd(cppVar_88807);
	bool cppVar_88810 = (cppVar_88808 == 208);
	if (cppVar_88810) {
	cppVar_88806 = PSW;
	} else {
	BIT_VEC cppVar_88811;
	BIT_VEC cppVar_88812 = PC + 1;
	cppVar_88812 = (cppVar_88812 & cppMask_un_16_);
	BIT_VEC cppVar_88813 = ROM.rd(cppVar_88812);
	bool cppVar_88815 = (cppVar_88813 == 224);
	if (cppVar_88815) {
	cppVar_88811 = ACC;
	} else {
	BIT_VEC cppVar_88816;
	BIT_VEC cppVar_88817 = PC + 1;
	cppVar_88817 = (cppVar_88817 & cppMask_un_16_);
	BIT_VEC cppVar_88818 = ROM.rd(cppVar_88817);
	bool cppVar_88820 = (cppVar_88818 == 240);
	if (cppVar_88820) {
	cppVar_88816 = B;
	} else {
	cppVar_88816 = 0;
	}
	cppVar_88811 = cppVar_88816;
	}
	cppVar_88806 = cppVar_88811;
	}
	cppVar_88801 = cppVar_88806;
	}
	cppVar_88796 = cppVar_88801;
	}
	cppVar_88791 = cppVar_88796;
	}
	cppVar_88786 = cppVar_88791;
	}
	cppVar_88781 = cppVar_88786;
	}
	cppVar_88776 = cppVar_88781;
	}
	cppVar_88771 = cppVar_88776;
	}
	cppVar_88766 = cppVar_88771;
	}
	cppVar_88761 = cppVar_88766;
	}
	cppVar_88756 = cppVar_88761;
	}
	cppVar_88751 = cppVar_88756;
	}
	cppVar_88746 = cppVar_88751;
	}
	cppVar_88741 = cppVar_88746;
	}
	cppVar_88736 = cppVar_88741;
	}
	cppVar_88731 = cppVar_88736;
	}
	cppVar_88726 = cppVar_88731;
	}
	cppVar_88721 = cppVar_88726;
	}
	cppVar_88716 = cppVar_88721;
	}
	cppVar_88706 = cppVar_88716;
	}
	type_mem cppVar_88822 = IRAM;
	cppVar_88822.wr(cppVar_88705, cppVar_88706);
	cppVar_88694 = cppVar_88822;
	} else {
	cppVar_88694 = IRAM;
	}
	cppVar_88690 = cppVar_88694;
	} else {
	type_mem cppVar_88823;
	BIT_VEC cppVar_88824 = ROM.rd(PC);
	bool cppVar_88826 = (cppVar_88824 == 171);
	if (cppVar_88826) {
	type_mem cppVar_88827;
	BIT_VEC cppVar_88829 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_88831 = (cppVar_88829 << 3) | 3;
	cppVar_88831 = (cppVar_88831 & cppMask_un_5_);
	BIT_VEC cppVar_88832 = (0 << 5) | cppVar_88831;
	cppVar_88832 = (cppVar_88832 & cppMask_un_8_);
	BIT_VEC cppVar_88833 = (cppVar_88832 >> 7) & cppMask_un_1_;
	bool cppVar_88835 = (cppVar_88833 == 0);
	if (cppVar_88835) {
	BIT_VEC cppVar_88836 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_88837 = (cppVar_88836 << 3) | 3;
	cppVar_88837 = (cppVar_88837 & cppMask_un_5_);
	BIT_VEC cppVar_88838 = (0 << 5) | cppVar_88837;
	cppVar_88838 = (cppVar_88838 & cppMask_un_8_);
	BIT_VEC cppVar_88839;
	BIT_VEC cppVar_88841 = PC + 1;
	cppVar_88841 = (cppVar_88841 & cppMask_un_16_);
	BIT_VEC cppVar_88842 = ROM.rd(cppVar_88841);
	BIT_VEC cppVar_88843 = (cppVar_88842 >> 7) & cppMask_un_1_;
	bool cppVar_88845 = (cppVar_88843 == 0);
	if (cppVar_88845) {
	BIT_VEC cppVar_88846 = PC + 1;
	cppVar_88846 = (cppVar_88846 & cppMask_un_16_);
	BIT_VEC cppVar_88847 = ROM.rd(cppVar_88846);
	BIT_VEC cppVar_88848 = IRAM.rd(cppVar_88847);
	cppVar_88839 = cppVar_88848;
	} else {
	BIT_VEC cppVar_88849;
	BIT_VEC cppVar_88850 = PC + 1;
	cppVar_88850 = (cppVar_88850 & cppMask_un_16_);
	BIT_VEC cppVar_88851 = ROM.rd(cppVar_88850);
	bool cppVar_88853 = (cppVar_88851 == 128);
	if (cppVar_88853) {
	cppVar_88849 = P0;
	} else {
	BIT_VEC cppVar_88854;
	BIT_VEC cppVar_88855 = PC + 1;
	cppVar_88855 = (cppVar_88855 & cppMask_un_16_);
	BIT_VEC cppVar_88856 = ROM.rd(cppVar_88855);
	bool cppVar_88858 = (cppVar_88856 == 129);
	if (cppVar_88858) {
	cppVar_88854 = SP;
	} else {
	BIT_VEC cppVar_88859;
	BIT_VEC cppVar_88860 = PC + 1;
	cppVar_88860 = (cppVar_88860 & cppMask_un_16_);
	BIT_VEC cppVar_88861 = ROM.rd(cppVar_88860);
	bool cppVar_88863 = (cppVar_88861 == 130);
	if (cppVar_88863) {
	cppVar_88859 = DPL;
	} else {
	BIT_VEC cppVar_88864;
	BIT_VEC cppVar_88865 = PC + 1;
	cppVar_88865 = (cppVar_88865 & cppMask_un_16_);
	BIT_VEC cppVar_88866 = ROM.rd(cppVar_88865);
	bool cppVar_88868 = (cppVar_88866 == 131);
	if (cppVar_88868) {
	cppVar_88864 = DPH;
	} else {
	BIT_VEC cppVar_88869;
	BIT_VEC cppVar_88870 = PC + 1;
	cppVar_88870 = (cppVar_88870 & cppMask_un_16_);
	BIT_VEC cppVar_88871 = ROM.rd(cppVar_88870);
	bool cppVar_88873 = (cppVar_88871 == 135);
	if (cppVar_88873) {
	cppVar_88869 = PCON;
	} else {
	BIT_VEC cppVar_88874;
	BIT_VEC cppVar_88875 = PC + 1;
	cppVar_88875 = (cppVar_88875 & cppMask_un_16_);
	BIT_VEC cppVar_88876 = ROM.rd(cppVar_88875);
	bool cppVar_88878 = (cppVar_88876 == 136);
	if (cppVar_88878) {
	cppVar_88874 = TCON;
	} else {
	BIT_VEC cppVar_88879;
	BIT_VEC cppVar_88880 = PC + 1;
	cppVar_88880 = (cppVar_88880 & cppMask_un_16_);
	BIT_VEC cppVar_88881 = ROM.rd(cppVar_88880);
	bool cppVar_88883 = (cppVar_88881 == 137);
	if (cppVar_88883) {
	cppVar_88879 = TMOD;
	} else {
	BIT_VEC cppVar_88884;
	BIT_VEC cppVar_88885 = PC + 1;
	cppVar_88885 = (cppVar_88885 & cppMask_un_16_);
	BIT_VEC cppVar_88886 = ROM.rd(cppVar_88885);
	bool cppVar_88888 = (cppVar_88886 == 138);
	if (cppVar_88888) {
	cppVar_88884 = TL0;
	} else {
	BIT_VEC cppVar_88889;
	BIT_VEC cppVar_88890 = PC + 1;
	cppVar_88890 = (cppVar_88890 & cppMask_un_16_);
	BIT_VEC cppVar_88891 = ROM.rd(cppVar_88890);
	bool cppVar_88893 = (cppVar_88891 == 140);
	if (cppVar_88893) {
	cppVar_88889 = TH0;
	} else {
	BIT_VEC cppVar_88894;
	BIT_VEC cppVar_88895 = PC + 1;
	cppVar_88895 = (cppVar_88895 & cppMask_un_16_);
	BIT_VEC cppVar_88896 = ROM.rd(cppVar_88895);
	bool cppVar_88898 = (cppVar_88896 == 139);
	if (cppVar_88898) {
	cppVar_88894 = TL1;
	} else {
	BIT_VEC cppVar_88899;
	BIT_VEC cppVar_88900 = PC + 1;
	cppVar_88900 = (cppVar_88900 & cppMask_un_16_);
	BIT_VEC cppVar_88901 = ROM.rd(cppVar_88900);
	bool cppVar_88903 = (cppVar_88901 == 141);
	if (cppVar_88903) {
	cppVar_88899 = TH1;
	} else {
	BIT_VEC cppVar_88904;
	BIT_VEC cppVar_88905 = PC + 1;
	cppVar_88905 = (cppVar_88905 & cppMask_un_16_);
	BIT_VEC cppVar_88906 = ROM.rd(cppVar_88905);
	bool cppVar_88908 = (cppVar_88906 == 144);
	if (cppVar_88908) {
	cppVar_88904 = P1;
	} else {
	BIT_VEC cppVar_88909;
	BIT_VEC cppVar_88910 = PC + 1;
	cppVar_88910 = (cppVar_88910 & cppMask_un_16_);
	BIT_VEC cppVar_88911 = ROM.rd(cppVar_88910);
	bool cppVar_88913 = (cppVar_88911 == 152);
	if (cppVar_88913) {
	cppVar_88909 = SCON;
	} else {
	BIT_VEC cppVar_88914;
	BIT_VEC cppVar_88915 = PC + 1;
	cppVar_88915 = (cppVar_88915 & cppMask_un_16_);
	BIT_VEC cppVar_88916 = ROM.rd(cppVar_88915);
	bool cppVar_88918 = (cppVar_88916 == 153);
	if (cppVar_88918) {
	cppVar_88914 = SBUF;
	} else {
	BIT_VEC cppVar_88919;
	BIT_VEC cppVar_88920 = PC + 1;
	cppVar_88920 = (cppVar_88920 & cppMask_un_16_);
	BIT_VEC cppVar_88921 = ROM.rd(cppVar_88920);
	bool cppVar_88923 = (cppVar_88921 == 160);
	if (cppVar_88923) {
	cppVar_88919 = P2;
	} else {
	BIT_VEC cppVar_88924;
	BIT_VEC cppVar_88925 = PC + 1;
	cppVar_88925 = (cppVar_88925 & cppMask_un_16_);
	BIT_VEC cppVar_88926 = ROM.rd(cppVar_88925);
	bool cppVar_88928 = (cppVar_88926 == 168);
	if (cppVar_88928) {
	cppVar_88924 = IE;
	} else {
	BIT_VEC cppVar_88929;
	BIT_VEC cppVar_88930 = PC + 1;
	cppVar_88930 = (cppVar_88930 & cppMask_un_16_);
	BIT_VEC cppVar_88931 = ROM.rd(cppVar_88930);
	bool cppVar_88933 = (cppVar_88931 == 176);
	if (cppVar_88933) {
	cppVar_88929 = P3;
	} else {
	BIT_VEC cppVar_88934;
	BIT_VEC cppVar_88935 = PC + 1;
	cppVar_88935 = (cppVar_88935 & cppMask_un_16_);
	BIT_VEC cppVar_88936 = ROM.rd(cppVar_88935);
	bool cppVar_88938 = (cppVar_88936 == 184);
	if (cppVar_88938) {
	cppVar_88934 = IP;
	} else {
	BIT_VEC cppVar_88939;
	BIT_VEC cppVar_88940 = PC + 1;
	cppVar_88940 = (cppVar_88940 & cppMask_un_16_);
	BIT_VEC cppVar_88941 = ROM.rd(cppVar_88940);
	bool cppVar_88943 = (cppVar_88941 == 208);
	if (cppVar_88943) {
	cppVar_88939 = PSW;
	} else {
	BIT_VEC cppVar_88944;
	BIT_VEC cppVar_88945 = PC + 1;
	cppVar_88945 = (cppVar_88945 & cppMask_un_16_);
	BIT_VEC cppVar_88946 = ROM.rd(cppVar_88945);
	bool cppVar_88948 = (cppVar_88946 == 224);
	if (cppVar_88948) {
	cppVar_88944 = ACC;
	} else {
	BIT_VEC cppVar_88949;
	BIT_VEC cppVar_88950 = PC + 1;
	cppVar_88950 = (cppVar_88950 & cppMask_un_16_);
	BIT_VEC cppVar_88951 = ROM.rd(cppVar_88950);
	bool cppVar_88953 = (cppVar_88951 == 240);
	if (cppVar_88953) {
	cppVar_88949 = B;
	} else {
	cppVar_88949 = 0;
	}
	cppVar_88944 = cppVar_88949;
	}
	cppVar_88939 = cppVar_88944;
	}
	cppVar_88934 = cppVar_88939;
	}
	cppVar_88929 = cppVar_88934;
	}
	cppVar_88924 = cppVar_88929;
	}
	cppVar_88919 = cppVar_88924;
	}
	cppVar_88914 = cppVar_88919;
	}
	cppVar_88909 = cppVar_88914;
	}
	cppVar_88904 = cppVar_88909;
	}
	cppVar_88899 = cppVar_88904;
	}
	cppVar_88894 = cppVar_88899;
	}
	cppVar_88889 = cppVar_88894;
	}
	cppVar_88884 = cppVar_88889;
	}
	cppVar_88879 = cppVar_88884;
	}
	cppVar_88874 = cppVar_88879;
	}
	cppVar_88869 = cppVar_88874;
	}
	cppVar_88864 = cppVar_88869;
	}
	cppVar_88859 = cppVar_88864;
	}
	cppVar_88854 = cppVar_88859;
	}
	cppVar_88849 = cppVar_88854;
	}
	cppVar_88839 = cppVar_88849;
	}
	type_mem cppVar_88955 = IRAM;
	cppVar_88955.wr(cppVar_88838, cppVar_88839);
	cppVar_88827 = cppVar_88955;
	} else {
	cppVar_88827 = IRAM;
	}
	cppVar_88823 = cppVar_88827;
	} else {
	type_mem cppVar_88956;
	BIT_VEC cppVar_88957 = ROM.rd(PC);
	bool cppVar_88959 = (cppVar_88957 == 170);
	if (cppVar_88959) {
	type_mem cppVar_88960;
	BIT_VEC cppVar_88962 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_88964 = (cppVar_88962 << 3) | 2;
	cppVar_88964 = (cppVar_88964 & cppMask_un_5_);
	BIT_VEC cppVar_88965 = (0 << 5) | cppVar_88964;
	cppVar_88965 = (cppVar_88965 & cppMask_un_8_);
	BIT_VEC cppVar_88966 = (cppVar_88965 >> 7) & cppMask_un_1_;
	bool cppVar_88968 = (cppVar_88966 == 0);
	if (cppVar_88968) {
	BIT_VEC cppVar_88969 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_88970 = (cppVar_88969 << 3) | 2;
	cppVar_88970 = (cppVar_88970 & cppMask_un_5_);
	BIT_VEC cppVar_88971 = (0 << 5) | cppVar_88970;
	cppVar_88971 = (cppVar_88971 & cppMask_un_8_);
	BIT_VEC cppVar_88972;
	BIT_VEC cppVar_88974 = PC + 1;
	cppVar_88974 = (cppVar_88974 & cppMask_un_16_);
	BIT_VEC cppVar_88975 = ROM.rd(cppVar_88974);
	BIT_VEC cppVar_88976 = (cppVar_88975 >> 7) & cppMask_un_1_;
	bool cppVar_88978 = (cppVar_88976 == 0);
	if (cppVar_88978) {
	BIT_VEC cppVar_88979 = PC + 1;
	cppVar_88979 = (cppVar_88979 & cppMask_un_16_);
	BIT_VEC cppVar_88980 = ROM.rd(cppVar_88979);
	BIT_VEC cppVar_88981 = IRAM.rd(cppVar_88980);
	cppVar_88972 = cppVar_88981;
	} else {
	BIT_VEC cppVar_88982;
	BIT_VEC cppVar_88983 = PC + 1;
	cppVar_88983 = (cppVar_88983 & cppMask_un_16_);
	BIT_VEC cppVar_88984 = ROM.rd(cppVar_88983);
	bool cppVar_88986 = (cppVar_88984 == 128);
	if (cppVar_88986) {
	cppVar_88982 = P0;
	} else {
	BIT_VEC cppVar_88987;
	BIT_VEC cppVar_88988 = PC + 1;
	cppVar_88988 = (cppVar_88988 & cppMask_un_16_);
	BIT_VEC cppVar_88989 = ROM.rd(cppVar_88988);
	bool cppVar_88991 = (cppVar_88989 == 129);
	if (cppVar_88991) {
	cppVar_88987 = SP;
	} else {
	BIT_VEC cppVar_88992;
	BIT_VEC cppVar_88993 = PC + 1;
	cppVar_88993 = (cppVar_88993 & cppMask_un_16_);
	BIT_VEC cppVar_88994 = ROM.rd(cppVar_88993);
	bool cppVar_88996 = (cppVar_88994 == 130);
	if (cppVar_88996) {
	cppVar_88992 = DPL;
	} else {
	BIT_VEC cppVar_88997;
	BIT_VEC cppVar_88998 = PC + 1;
	cppVar_88998 = (cppVar_88998 & cppMask_un_16_);
	BIT_VEC cppVar_88999 = ROM.rd(cppVar_88998);
	bool cppVar_89001 = (cppVar_88999 == 131);
	if (cppVar_89001) {
	cppVar_88997 = DPH;
	} else {
	BIT_VEC cppVar_89002;
	BIT_VEC cppVar_89003 = PC + 1;
	cppVar_89003 = (cppVar_89003 & cppMask_un_16_);
	BIT_VEC cppVar_89004 = ROM.rd(cppVar_89003);
	bool cppVar_89006 = (cppVar_89004 == 135);
	if (cppVar_89006) {
	cppVar_89002 = PCON;
	} else {
	BIT_VEC cppVar_89007;
	BIT_VEC cppVar_89008 = PC + 1;
	cppVar_89008 = (cppVar_89008 & cppMask_un_16_);
	BIT_VEC cppVar_89009 = ROM.rd(cppVar_89008);
	bool cppVar_89011 = (cppVar_89009 == 136);
	if (cppVar_89011) {
	cppVar_89007 = TCON;
	} else {
	BIT_VEC cppVar_89012;
	BIT_VEC cppVar_89013 = PC + 1;
	cppVar_89013 = (cppVar_89013 & cppMask_un_16_);
	BIT_VEC cppVar_89014 = ROM.rd(cppVar_89013);
	bool cppVar_89016 = (cppVar_89014 == 137);
	if (cppVar_89016) {
	cppVar_89012 = TMOD;
	} else {
	BIT_VEC cppVar_89017;
	BIT_VEC cppVar_89018 = PC + 1;
	cppVar_89018 = (cppVar_89018 & cppMask_un_16_);
	BIT_VEC cppVar_89019 = ROM.rd(cppVar_89018);
	bool cppVar_89021 = (cppVar_89019 == 138);
	if (cppVar_89021) {
	cppVar_89017 = TL0;
	} else {
	BIT_VEC cppVar_89022;
	BIT_VEC cppVar_89023 = PC + 1;
	cppVar_89023 = (cppVar_89023 & cppMask_un_16_);
	BIT_VEC cppVar_89024 = ROM.rd(cppVar_89023);
	bool cppVar_89026 = (cppVar_89024 == 140);
	if (cppVar_89026) {
	cppVar_89022 = TH0;
	} else {
	BIT_VEC cppVar_89027;
	BIT_VEC cppVar_89028 = PC + 1;
	cppVar_89028 = (cppVar_89028 & cppMask_un_16_);
	BIT_VEC cppVar_89029 = ROM.rd(cppVar_89028);
	bool cppVar_89031 = (cppVar_89029 == 139);
	if (cppVar_89031) {
	cppVar_89027 = TL1;
	} else {
	BIT_VEC cppVar_89032;
	BIT_VEC cppVar_89033 = PC + 1;
	cppVar_89033 = (cppVar_89033 & cppMask_un_16_);
	BIT_VEC cppVar_89034 = ROM.rd(cppVar_89033);
	bool cppVar_89036 = (cppVar_89034 == 141);
	if (cppVar_89036) {
	cppVar_89032 = TH1;
	} else {
	BIT_VEC cppVar_89037;
	BIT_VEC cppVar_89038 = PC + 1;
	cppVar_89038 = (cppVar_89038 & cppMask_un_16_);
	BIT_VEC cppVar_89039 = ROM.rd(cppVar_89038);
	bool cppVar_89041 = (cppVar_89039 == 144);
	if (cppVar_89041) {
	cppVar_89037 = P1;
	} else {
	BIT_VEC cppVar_89042;
	BIT_VEC cppVar_89043 = PC + 1;
	cppVar_89043 = (cppVar_89043 & cppMask_un_16_);
	BIT_VEC cppVar_89044 = ROM.rd(cppVar_89043);
	bool cppVar_89046 = (cppVar_89044 == 152);
	if (cppVar_89046) {
	cppVar_89042 = SCON;
	} else {
	BIT_VEC cppVar_89047;
	BIT_VEC cppVar_89048 = PC + 1;
	cppVar_89048 = (cppVar_89048 & cppMask_un_16_);
	BIT_VEC cppVar_89049 = ROM.rd(cppVar_89048);
	bool cppVar_89051 = (cppVar_89049 == 153);
	if (cppVar_89051) {
	cppVar_89047 = SBUF;
	} else {
	BIT_VEC cppVar_89052;
	BIT_VEC cppVar_89053 = PC + 1;
	cppVar_89053 = (cppVar_89053 & cppMask_un_16_);
	BIT_VEC cppVar_89054 = ROM.rd(cppVar_89053);
	bool cppVar_89056 = (cppVar_89054 == 160);
	if (cppVar_89056) {
	cppVar_89052 = P2;
	} else {
	BIT_VEC cppVar_89057;
	BIT_VEC cppVar_89058 = PC + 1;
	cppVar_89058 = (cppVar_89058 & cppMask_un_16_);
	BIT_VEC cppVar_89059 = ROM.rd(cppVar_89058);
	bool cppVar_89061 = (cppVar_89059 == 168);
	if (cppVar_89061) {
	cppVar_89057 = IE;
	} else {
	BIT_VEC cppVar_89062;
	BIT_VEC cppVar_89063 = PC + 1;
	cppVar_89063 = (cppVar_89063 & cppMask_un_16_);
	BIT_VEC cppVar_89064 = ROM.rd(cppVar_89063);
	bool cppVar_89066 = (cppVar_89064 == 176);
	if (cppVar_89066) {
	cppVar_89062 = P3;
	} else {
	BIT_VEC cppVar_89067;
	BIT_VEC cppVar_89068 = PC + 1;
	cppVar_89068 = (cppVar_89068 & cppMask_un_16_);
	BIT_VEC cppVar_89069 = ROM.rd(cppVar_89068);
	bool cppVar_89071 = (cppVar_89069 == 184);
	if (cppVar_89071) {
	cppVar_89067 = IP;
	} else {
	BIT_VEC cppVar_89072;
	BIT_VEC cppVar_89073 = PC + 1;
	cppVar_89073 = (cppVar_89073 & cppMask_un_16_);
	BIT_VEC cppVar_89074 = ROM.rd(cppVar_89073);
	bool cppVar_89076 = (cppVar_89074 == 208);
	if (cppVar_89076) {
	cppVar_89072 = PSW;
	} else {
	BIT_VEC cppVar_89077;
	BIT_VEC cppVar_89078 = PC + 1;
	cppVar_89078 = (cppVar_89078 & cppMask_un_16_);
	BIT_VEC cppVar_89079 = ROM.rd(cppVar_89078);
	bool cppVar_89081 = (cppVar_89079 == 224);
	if (cppVar_89081) {
	cppVar_89077 = ACC;
	} else {
	BIT_VEC cppVar_89082;
	BIT_VEC cppVar_89083 = PC + 1;
	cppVar_89083 = (cppVar_89083 & cppMask_un_16_);
	BIT_VEC cppVar_89084 = ROM.rd(cppVar_89083);
	bool cppVar_89086 = (cppVar_89084 == 240);
	if (cppVar_89086) {
	cppVar_89082 = B;
	} else {
	cppVar_89082 = 0;
	}
	cppVar_89077 = cppVar_89082;
	}
	cppVar_89072 = cppVar_89077;
	}
	cppVar_89067 = cppVar_89072;
	}
	cppVar_89062 = cppVar_89067;
	}
	cppVar_89057 = cppVar_89062;
	}
	cppVar_89052 = cppVar_89057;
	}
	cppVar_89047 = cppVar_89052;
	}
	cppVar_89042 = cppVar_89047;
	}
	cppVar_89037 = cppVar_89042;
	}
	cppVar_89032 = cppVar_89037;
	}
	cppVar_89027 = cppVar_89032;
	}
	cppVar_89022 = cppVar_89027;
	}
	cppVar_89017 = cppVar_89022;
	}
	cppVar_89012 = cppVar_89017;
	}
	cppVar_89007 = cppVar_89012;
	}
	cppVar_89002 = cppVar_89007;
	}
	cppVar_88997 = cppVar_89002;
	}
	cppVar_88992 = cppVar_88997;
	}
	cppVar_88987 = cppVar_88992;
	}
	cppVar_88982 = cppVar_88987;
	}
	cppVar_88972 = cppVar_88982;
	}
	type_mem cppVar_89088 = IRAM;
	cppVar_89088.wr(cppVar_88971, cppVar_88972);
	cppVar_88960 = cppVar_89088;
	} else {
	cppVar_88960 = IRAM;
	}
	cppVar_88956 = cppVar_88960;
	} else {
	type_mem cppVar_89089;
	BIT_VEC cppVar_89090 = ROM.rd(PC);
	bool cppVar_89092 = (cppVar_89090 == 169);
	if (cppVar_89092) {
	type_mem cppVar_89093;
	BIT_VEC cppVar_89095 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_89097 = (cppVar_89095 << 3) | 1;
	cppVar_89097 = (cppVar_89097 & cppMask_un_5_);
	BIT_VEC cppVar_89098 = (0 << 5) | cppVar_89097;
	cppVar_89098 = (cppVar_89098 & cppMask_un_8_);
	BIT_VEC cppVar_89099 = (cppVar_89098 >> 7) & cppMask_un_1_;
	bool cppVar_89101 = (cppVar_89099 == 0);
	if (cppVar_89101) {
	BIT_VEC cppVar_89102 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_89103 = (cppVar_89102 << 3) | 1;
	cppVar_89103 = (cppVar_89103 & cppMask_un_5_);
	BIT_VEC cppVar_89104 = (0 << 5) | cppVar_89103;
	cppVar_89104 = (cppVar_89104 & cppMask_un_8_);
	BIT_VEC cppVar_89105;
	BIT_VEC cppVar_89107 = PC + 1;
	cppVar_89107 = (cppVar_89107 & cppMask_un_16_);
	BIT_VEC cppVar_89108 = ROM.rd(cppVar_89107);
	BIT_VEC cppVar_89109 = (cppVar_89108 >> 7) & cppMask_un_1_;
	bool cppVar_89111 = (cppVar_89109 == 0);
	if (cppVar_89111) {
	BIT_VEC cppVar_89112 = PC + 1;
	cppVar_89112 = (cppVar_89112 & cppMask_un_16_);
	BIT_VEC cppVar_89113 = ROM.rd(cppVar_89112);
	BIT_VEC cppVar_89114 = IRAM.rd(cppVar_89113);
	cppVar_89105 = cppVar_89114;
	} else {
	BIT_VEC cppVar_89115;
	BIT_VEC cppVar_89116 = PC + 1;
	cppVar_89116 = (cppVar_89116 & cppMask_un_16_);
	BIT_VEC cppVar_89117 = ROM.rd(cppVar_89116);
	bool cppVar_89119 = (cppVar_89117 == 128);
	if (cppVar_89119) {
	cppVar_89115 = P0;
	} else {
	BIT_VEC cppVar_89120;
	BIT_VEC cppVar_89121 = PC + 1;
	cppVar_89121 = (cppVar_89121 & cppMask_un_16_);
	BIT_VEC cppVar_89122 = ROM.rd(cppVar_89121);
	bool cppVar_89124 = (cppVar_89122 == 129);
	if (cppVar_89124) {
	cppVar_89120 = SP;
	} else {
	BIT_VEC cppVar_89125;
	BIT_VEC cppVar_89126 = PC + 1;
	cppVar_89126 = (cppVar_89126 & cppMask_un_16_);
	BIT_VEC cppVar_89127 = ROM.rd(cppVar_89126);
	bool cppVar_89129 = (cppVar_89127 == 130);
	if (cppVar_89129) {
	cppVar_89125 = DPL;
	} else {
	BIT_VEC cppVar_89130;
	BIT_VEC cppVar_89131 = PC + 1;
	cppVar_89131 = (cppVar_89131 & cppMask_un_16_);
	BIT_VEC cppVar_89132 = ROM.rd(cppVar_89131);
	bool cppVar_89134 = (cppVar_89132 == 131);
	if (cppVar_89134) {
	cppVar_89130 = DPH;
	} else {
	BIT_VEC cppVar_89135;
	BIT_VEC cppVar_89136 = PC + 1;
	cppVar_89136 = (cppVar_89136 & cppMask_un_16_);
	BIT_VEC cppVar_89137 = ROM.rd(cppVar_89136);
	bool cppVar_89139 = (cppVar_89137 == 135);
	if (cppVar_89139) {
	cppVar_89135 = PCON;
	} else {
	BIT_VEC cppVar_89140;
	BIT_VEC cppVar_89141 = PC + 1;
	cppVar_89141 = (cppVar_89141 & cppMask_un_16_);
	BIT_VEC cppVar_89142 = ROM.rd(cppVar_89141);
	bool cppVar_89144 = (cppVar_89142 == 136);
	if (cppVar_89144) {
	cppVar_89140 = TCON;
	} else {
	BIT_VEC cppVar_89145;
	BIT_VEC cppVar_89146 = PC + 1;
	cppVar_89146 = (cppVar_89146 & cppMask_un_16_);
	BIT_VEC cppVar_89147 = ROM.rd(cppVar_89146);
	bool cppVar_89149 = (cppVar_89147 == 137);
	if (cppVar_89149) {
	cppVar_89145 = TMOD;
	} else {
	BIT_VEC cppVar_89150;
	BIT_VEC cppVar_89151 = PC + 1;
	cppVar_89151 = (cppVar_89151 & cppMask_un_16_);
	BIT_VEC cppVar_89152 = ROM.rd(cppVar_89151);
	bool cppVar_89154 = (cppVar_89152 == 138);
	if (cppVar_89154) {
	cppVar_89150 = TL0;
	} else {
	BIT_VEC cppVar_89155;
	BIT_VEC cppVar_89156 = PC + 1;
	cppVar_89156 = (cppVar_89156 & cppMask_un_16_);
	BIT_VEC cppVar_89157 = ROM.rd(cppVar_89156);
	bool cppVar_89159 = (cppVar_89157 == 140);
	if (cppVar_89159) {
	cppVar_89155 = TH0;
	} else {
	BIT_VEC cppVar_89160;
	BIT_VEC cppVar_89161 = PC + 1;
	cppVar_89161 = (cppVar_89161 & cppMask_un_16_);
	BIT_VEC cppVar_89162 = ROM.rd(cppVar_89161);
	bool cppVar_89164 = (cppVar_89162 == 139);
	if (cppVar_89164) {
	cppVar_89160 = TL1;
	} else {
	BIT_VEC cppVar_89165;
	BIT_VEC cppVar_89166 = PC + 1;
	cppVar_89166 = (cppVar_89166 & cppMask_un_16_);
	BIT_VEC cppVar_89167 = ROM.rd(cppVar_89166);
	bool cppVar_89169 = (cppVar_89167 == 141);
	if (cppVar_89169) {
	cppVar_89165 = TH1;
	} else {
	BIT_VEC cppVar_89170;
	BIT_VEC cppVar_89171 = PC + 1;
	cppVar_89171 = (cppVar_89171 & cppMask_un_16_);
	BIT_VEC cppVar_89172 = ROM.rd(cppVar_89171);
	bool cppVar_89174 = (cppVar_89172 == 144);
	if (cppVar_89174) {
	cppVar_89170 = P1;
	} else {
	BIT_VEC cppVar_89175;
	BIT_VEC cppVar_89176 = PC + 1;
	cppVar_89176 = (cppVar_89176 & cppMask_un_16_);
	BIT_VEC cppVar_89177 = ROM.rd(cppVar_89176);
	bool cppVar_89179 = (cppVar_89177 == 152);
	if (cppVar_89179) {
	cppVar_89175 = SCON;
	} else {
	BIT_VEC cppVar_89180;
	BIT_VEC cppVar_89181 = PC + 1;
	cppVar_89181 = (cppVar_89181 & cppMask_un_16_);
	BIT_VEC cppVar_89182 = ROM.rd(cppVar_89181);
	bool cppVar_89184 = (cppVar_89182 == 153);
	if (cppVar_89184) {
	cppVar_89180 = SBUF;
	} else {
	BIT_VEC cppVar_89185;
	BIT_VEC cppVar_89186 = PC + 1;
	cppVar_89186 = (cppVar_89186 & cppMask_un_16_);
	BIT_VEC cppVar_89187 = ROM.rd(cppVar_89186);
	bool cppVar_89189 = (cppVar_89187 == 160);
	if (cppVar_89189) {
	cppVar_89185 = P2;
	} else {
	BIT_VEC cppVar_89190;
	BIT_VEC cppVar_89191 = PC + 1;
	cppVar_89191 = (cppVar_89191 & cppMask_un_16_);
	BIT_VEC cppVar_89192 = ROM.rd(cppVar_89191);
	bool cppVar_89194 = (cppVar_89192 == 168);
	if (cppVar_89194) {
	cppVar_89190 = IE;
	} else {
	BIT_VEC cppVar_89195;
	BIT_VEC cppVar_89196 = PC + 1;
	cppVar_89196 = (cppVar_89196 & cppMask_un_16_);
	BIT_VEC cppVar_89197 = ROM.rd(cppVar_89196);
	bool cppVar_89199 = (cppVar_89197 == 176);
	if (cppVar_89199) {
	cppVar_89195 = P3;
	} else {
	BIT_VEC cppVar_89200;
	BIT_VEC cppVar_89201 = PC + 1;
	cppVar_89201 = (cppVar_89201 & cppMask_un_16_);
	BIT_VEC cppVar_89202 = ROM.rd(cppVar_89201);
	bool cppVar_89204 = (cppVar_89202 == 184);
	if (cppVar_89204) {
	cppVar_89200 = IP;
	} else {
	BIT_VEC cppVar_89205;
	BIT_VEC cppVar_89206 = PC + 1;
	cppVar_89206 = (cppVar_89206 & cppMask_un_16_);
	BIT_VEC cppVar_89207 = ROM.rd(cppVar_89206);
	bool cppVar_89209 = (cppVar_89207 == 208);
	if (cppVar_89209) {
	cppVar_89205 = PSW;
	} else {
	BIT_VEC cppVar_89210;
	BIT_VEC cppVar_89211 = PC + 1;
	cppVar_89211 = (cppVar_89211 & cppMask_un_16_);
	BIT_VEC cppVar_89212 = ROM.rd(cppVar_89211);
	bool cppVar_89214 = (cppVar_89212 == 224);
	if (cppVar_89214) {
	cppVar_89210 = ACC;
	} else {
	BIT_VEC cppVar_89215;
	BIT_VEC cppVar_89216 = PC + 1;
	cppVar_89216 = (cppVar_89216 & cppMask_un_16_);
	BIT_VEC cppVar_89217 = ROM.rd(cppVar_89216);
	bool cppVar_89219 = (cppVar_89217 == 240);
	if (cppVar_89219) {
	cppVar_89215 = B;
	} else {
	cppVar_89215 = 0;
	}
	cppVar_89210 = cppVar_89215;
	}
	cppVar_89205 = cppVar_89210;
	}
	cppVar_89200 = cppVar_89205;
	}
	cppVar_89195 = cppVar_89200;
	}
	cppVar_89190 = cppVar_89195;
	}
	cppVar_89185 = cppVar_89190;
	}
	cppVar_89180 = cppVar_89185;
	}
	cppVar_89175 = cppVar_89180;
	}
	cppVar_89170 = cppVar_89175;
	}
	cppVar_89165 = cppVar_89170;
	}
	cppVar_89160 = cppVar_89165;
	}
	cppVar_89155 = cppVar_89160;
	}
	cppVar_89150 = cppVar_89155;
	}
	cppVar_89145 = cppVar_89150;
	}
	cppVar_89140 = cppVar_89145;
	}
	cppVar_89135 = cppVar_89140;
	}
	cppVar_89130 = cppVar_89135;
	}
	cppVar_89125 = cppVar_89130;
	}
	cppVar_89120 = cppVar_89125;
	}
	cppVar_89115 = cppVar_89120;
	}
	cppVar_89105 = cppVar_89115;
	}
	type_mem cppVar_89221 = IRAM;
	cppVar_89221.wr(cppVar_89104, cppVar_89105);
	cppVar_89093 = cppVar_89221;
	} else {
	cppVar_89093 = IRAM;
	}
	cppVar_89089 = cppVar_89093;
	} else {
	type_mem cppVar_89222;
	BIT_VEC cppVar_89223 = ROM.rd(PC);
	bool cppVar_89225 = (cppVar_89223 == 168);
	if (cppVar_89225) {
	type_mem cppVar_89226;
	BIT_VEC cppVar_89228 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_89230 = (cppVar_89228 << 3) | 0;
	cppVar_89230 = (cppVar_89230 & cppMask_un_5_);
	BIT_VEC cppVar_89231 = (0 << 5) | cppVar_89230;
	cppVar_89231 = (cppVar_89231 & cppMask_un_8_);
	BIT_VEC cppVar_89232 = (cppVar_89231 >> 7) & cppMask_un_1_;
	bool cppVar_89234 = (cppVar_89232 == 0);
	if (cppVar_89234) {
	BIT_VEC cppVar_89235 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_89236 = (cppVar_89235 << 3) | 0;
	cppVar_89236 = (cppVar_89236 & cppMask_un_5_);
	BIT_VEC cppVar_89237 = (0 << 5) | cppVar_89236;
	cppVar_89237 = (cppVar_89237 & cppMask_un_8_);
	BIT_VEC cppVar_89238;
	BIT_VEC cppVar_89240 = PC + 1;
	cppVar_89240 = (cppVar_89240 & cppMask_un_16_);
	BIT_VEC cppVar_89241 = ROM.rd(cppVar_89240);
	BIT_VEC cppVar_89242 = (cppVar_89241 >> 7) & cppMask_un_1_;
	bool cppVar_89244 = (cppVar_89242 == 0);
	if (cppVar_89244) {
	BIT_VEC cppVar_89245 = PC + 1;
	cppVar_89245 = (cppVar_89245 & cppMask_un_16_);
	BIT_VEC cppVar_89246 = ROM.rd(cppVar_89245);
	BIT_VEC cppVar_89247 = IRAM.rd(cppVar_89246);
	cppVar_89238 = cppVar_89247;
	} else {
	BIT_VEC cppVar_89248;
	BIT_VEC cppVar_89249 = PC + 1;
	cppVar_89249 = (cppVar_89249 & cppMask_un_16_);
	BIT_VEC cppVar_89250 = ROM.rd(cppVar_89249);
	bool cppVar_89252 = (cppVar_89250 == 128);
	if (cppVar_89252) {
	cppVar_89248 = P0;
	} else {
	BIT_VEC cppVar_89253;
	BIT_VEC cppVar_89254 = PC + 1;
	cppVar_89254 = (cppVar_89254 & cppMask_un_16_);
	BIT_VEC cppVar_89255 = ROM.rd(cppVar_89254);
	bool cppVar_89257 = (cppVar_89255 == 129);
	if (cppVar_89257) {
	cppVar_89253 = SP;
	} else {
	BIT_VEC cppVar_89258;
	BIT_VEC cppVar_89259 = PC + 1;
	cppVar_89259 = (cppVar_89259 & cppMask_un_16_);
	BIT_VEC cppVar_89260 = ROM.rd(cppVar_89259);
	bool cppVar_89262 = (cppVar_89260 == 130);
	if (cppVar_89262) {
	cppVar_89258 = DPL;
	} else {
	BIT_VEC cppVar_89263;
	BIT_VEC cppVar_89264 = PC + 1;
	cppVar_89264 = (cppVar_89264 & cppMask_un_16_);
	BIT_VEC cppVar_89265 = ROM.rd(cppVar_89264);
	bool cppVar_89267 = (cppVar_89265 == 131);
	if (cppVar_89267) {
	cppVar_89263 = DPH;
	} else {
	BIT_VEC cppVar_89268;
	BIT_VEC cppVar_89269 = PC + 1;
	cppVar_89269 = (cppVar_89269 & cppMask_un_16_);
	BIT_VEC cppVar_89270 = ROM.rd(cppVar_89269);
	bool cppVar_89272 = (cppVar_89270 == 135);
	if (cppVar_89272) {
	cppVar_89268 = PCON;
	} else {
	BIT_VEC cppVar_89273;
	BIT_VEC cppVar_89274 = PC + 1;
	cppVar_89274 = (cppVar_89274 & cppMask_un_16_);
	BIT_VEC cppVar_89275 = ROM.rd(cppVar_89274);
	bool cppVar_89277 = (cppVar_89275 == 136);
	if (cppVar_89277) {
	cppVar_89273 = TCON;
	} else {
	BIT_VEC cppVar_89278;
	BIT_VEC cppVar_89279 = PC + 1;
	cppVar_89279 = (cppVar_89279 & cppMask_un_16_);
	BIT_VEC cppVar_89280 = ROM.rd(cppVar_89279);
	bool cppVar_89282 = (cppVar_89280 == 137);
	if (cppVar_89282) {
	cppVar_89278 = TMOD;
	} else {
	BIT_VEC cppVar_89283;
	BIT_VEC cppVar_89284 = PC + 1;
	cppVar_89284 = (cppVar_89284 & cppMask_un_16_);
	BIT_VEC cppVar_89285 = ROM.rd(cppVar_89284);
	bool cppVar_89287 = (cppVar_89285 == 138);
	if (cppVar_89287) {
	cppVar_89283 = TL0;
	} else {
	BIT_VEC cppVar_89288;
	BIT_VEC cppVar_89289 = PC + 1;
	cppVar_89289 = (cppVar_89289 & cppMask_un_16_);
	BIT_VEC cppVar_89290 = ROM.rd(cppVar_89289);
	bool cppVar_89292 = (cppVar_89290 == 140);
	if (cppVar_89292) {
	cppVar_89288 = TH0;
	} else {
	BIT_VEC cppVar_89293;
	BIT_VEC cppVar_89294 = PC + 1;
	cppVar_89294 = (cppVar_89294 & cppMask_un_16_);
	BIT_VEC cppVar_89295 = ROM.rd(cppVar_89294);
	bool cppVar_89297 = (cppVar_89295 == 139);
	if (cppVar_89297) {
	cppVar_89293 = TL1;
	} else {
	BIT_VEC cppVar_89298;
	BIT_VEC cppVar_89299 = PC + 1;
	cppVar_89299 = (cppVar_89299 & cppMask_un_16_);
	BIT_VEC cppVar_89300 = ROM.rd(cppVar_89299);
	bool cppVar_89302 = (cppVar_89300 == 141);
	if (cppVar_89302) {
	cppVar_89298 = TH1;
	} else {
	BIT_VEC cppVar_89303;
	BIT_VEC cppVar_89304 = PC + 1;
	cppVar_89304 = (cppVar_89304 & cppMask_un_16_);
	BIT_VEC cppVar_89305 = ROM.rd(cppVar_89304);
	bool cppVar_89307 = (cppVar_89305 == 144);
	if (cppVar_89307) {
	cppVar_89303 = P1;
	} else {
	BIT_VEC cppVar_89308;
	BIT_VEC cppVar_89309 = PC + 1;
	cppVar_89309 = (cppVar_89309 & cppMask_un_16_);
	BIT_VEC cppVar_89310 = ROM.rd(cppVar_89309);
	bool cppVar_89312 = (cppVar_89310 == 152);
	if (cppVar_89312) {
	cppVar_89308 = SCON;
	} else {
	BIT_VEC cppVar_89313;
	BIT_VEC cppVar_89314 = PC + 1;
	cppVar_89314 = (cppVar_89314 & cppMask_un_16_);
	BIT_VEC cppVar_89315 = ROM.rd(cppVar_89314);
	bool cppVar_89317 = (cppVar_89315 == 153);
	if (cppVar_89317) {
	cppVar_89313 = SBUF;
	} else {
	BIT_VEC cppVar_89318;
	BIT_VEC cppVar_89319 = PC + 1;
	cppVar_89319 = (cppVar_89319 & cppMask_un_16_);
	BIT_VEC cppVar_89320 = ROM.rd(cppVar_89319);
	bool cppVar_89322 = (cppVar_89320 == 160);
	if (cppVar_89322) {
	cppVar_89318 = P2;
	} else {
	BIT_VEC cppVar_89323;
	BIT_VEC cppVar_89324 = PC + 1;
	cppVar_89324 = (cppVar_89324 & cppMask_un_16_);
	BIT_VEC cppVar_89325 = ROM.rd(cppVar_89324);
	bool cppVar_89327 = (cppVar_89325 == 168);
	if (cppVar_89327) {
	cppVar_89323 = IE;
	} else {
	BIT_VEC cppVar_89328;
	BIT_VEC cppVar_89329 = PC + 1;
	cppVar_89329 = (cppVar_89329 & cppMask_un_16_);
	BIT_VEC cppVar_89330 = ROM.rd(cppVar_89329);
	bool cppVar_89332 = (cppVar_89330 == 176);
	if (cppVar_89332) {
	cppVar_89328 = P3;
	} else {
	BIT_VEC cppVar_89333;
	BIT_VEC cppVar_89334 = PC + 1;
	cppVar_89334 = (cppVar_89334 & cppMask_un_16_);
	BIT_VEC cppVar_89335 = ROM.rd(cppVar_89334);
	bool cppVar_89337 = (cppVar_89335 == 184);
	if (cppVar_89337) {
	cppVar_89333 = IP;
	} else {
	BIT_VEC cppVar_89338;
	BIT_VEC cppVar_89339 = PC + 1;
	cppVar_89339 = (cppVar_89339 & cppMask_un_16_);
	BIT_VEC cppVar_89340 = ROM.rd(cppVar_89339);
	bool cppVar_89342 = (cppVar_89340 == 208);
	if (cppVar_89342) {
	cppVar_89338 = PSW;
	} else {
	BIT_VEC cppVar_89343;
	BIT_VEC cppVar_89344 = PC + 1;
	cppVar_89344 = (cppVar_89344 & cppMask_un_16_);
	BIT_VEC cppVar_89345 = ROM.rd(cppVar_89344);
	bool cppVar_89347 = (cppVar_89345 == 224);
	if (cppVar_89347) {
	cppVar_89343 = ACC;
	} else {
	BIT_VEC cppVar_89348;
	BIT_VEC cppVar_89349 = PC + 1;
	cppVar_89349 = (cppVar_89349 & cppMask_un_16_);
	BIT_VEC cppVar_89350 = ROM.rd(cppVar_89349);
	bool cppVar_89352 = (cppVar_89350 == 240);
	if (cppVar_89352) {
	cppVar_89348 = B;
	} else {
	cppVar_89348 = 0;
	}
	cppVar_89343 = cppVar_89348;
	}
	cppVar_89338 = cppVar_89343;
	}
	cppVar_89333 = cppVar_89338;
	}
	cppVar_89328 = cppVar_89333;
	}
	cppVar_89323 = cppVar_89328;
	}
	cppVar_89318 = cppVar_89323;
	}
	cppVar_89313 = cppVar_89318;
	}
	cppVar_89308 = cppVar_89313;
	}
	cppVar_89303 = cppVar_89308;
	}
	cppVar_89298 = cppVar_89303;
	}
	cppVar_89293 = cppVar_89298;
	}
	cppVar_89288 = cppVar_89293;
	}
	cppVar_89283 = cppVar_89288;
	}
	cppVar_89278 = cppVar_89283;
	}
	cppVar_89273 = cppVar_89278;
	}
	cppVar_89268 = cppVar_89273;
	}
	cppVar_89263 = cppVar_89268;
	}
	cppVar_89258 = cppVar_89263;
	}
	cppVar_89253 = cppVar_89258;
	}
	cppVar_89248 = cppVar_89253;
	}
	cppVar_89238 = cppVar_89248;
	}
	type_mem cppVar_89354 = IRAM;
	cppVar_89354.wr(cppVar_89237, cppVar_89238);
	cppVar_89226 = cppVar_89354;
	} else {
	cppVar_89226 = IRAM;
	}
	cppVar_89222 = cppVar_89226;
	} else {
	type_mem cppVar_89355;
	BIT_VEC cppVar_89356 = ROM.rd(PC);
	bool cppVar_89358 = (cppVar_89356 == 167);
	if (cppVar_89358) {
	BIT_VEC cppVar_89360 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_89362 = (cppVar_89360 << 3) | 1;
	cppVar_89362 = (cppVar_89362 & cppMask_un_5_);
	BIT_VEC cppVar_89363 = (0 << 5) | cppVar_89362;
	cppVar_89363 = (cppVar_89363 & cppMask_un_8_);
	BIT_VEC cppVar_89364 = IRAM.rd(cppVar_89363);
	BIT_VEC cppVar_89365;
	BIT_VEC cppVar_89367 = PC + 1;
	cppVar_89367 = (cppVar_89367 & cppMask_un_16_);
	BIT_VEC cppVar_89368 = ROM.rd(cppVar_89367);
	BIT_VEC cppVar_89369 = (cppVar_89368 >> 7) & cppMask_un_1_;
	bool cppVar_89371 = (cppVar_89369 == 0);
	if (cppVar_89371) {
	BIT_VEC cppVar_89372 = PC + 1;
	cppVar_89372 = (cppVar_89372 & cppMask_un_16_);
	BIT_VEC cppVar_89373 = ROM.rd(cppVar_89372);
	BIT_VEC cppVar_89374 = IRAM.rd(cppVar_89373);
	cppVar_89365 = cppVar_89374;
	} else {
	BIT_VEC cppVar_89375;
	BIT_VEC cppVar_89376 = PC + 1;
	cppVar_89376 = (cppVar_89376 & cppMask_un_16_);
	BIT_VEC cppVar_89377 = ROM.rd(cppVar_89376);
	bool cppVar_89379 = (cppVar_89377 == 128);
	if (cppVar_89379) {
	cppVar_89375 = P0;
	} else {
	BIT_VEC cppVar_89380;
	BIT_VEC cppVar_89381 = PC + 1;
	cppVar_89381 = (cppVar_89381 & cppMask_un_16_);
	BIT_VEC cppVar_89382 = ROM.rd(cppVar_89381);
	bool cppVar_89384 = (cppVar_89382 == 129);
	if (cppVar_89384) {
	cppVar_89380 = SP;
	} else {
	BIT_VEC cppVar_89385;
	BIT_VEC cppVar_89386 = PC + 1;
	cppVar_89386 = (cppVar_89386 & cppMask_un_16_);
	BIT_VEC cppVar_89387 = ROM.rd(cppVar_89386);
	bool cppVar_89389 = (cppVar_89387 == 130);
	if (cppVar_89389) {
	cppVar_89385 = DPL;
	} else {
	BIT_VEC cppVar_89390;
	BIT_VEC cppVar_89391 = PC + 1;
	cppVar_89391 = (cppVar_89391 & cppMask_un_16_);
	BIT_VEC cppVar_89392 = ROM.rd(cppVar_89391);
	bool cppVar_89394 = (cppVar_89392 == 131);
	if (cppVar_89394) {
	cppVar_89390 = DPH;
	} else {
	BIT_VEC cppVar_89395;
	BIT_VEC cppVar_89396 = PC + 1;
	cppVar_89396 = (cppVar_89396 & cppMask_un_16_);
	BIT_VEC cppVar_89397 = ROM.rd(cppVar_89396);
	bool cppVar_89399 = (cppVar_89397 == 135);
	if (cppVar_89399) {
	cppVar_89395 = PCON;
	} else {
	BIT_VEC cppVar_89400;
	BIT_VEC cppVar_89401 = PC + 1;
	cppVar_89401 = (cppVar_89401 & cppMask_un_16_);
	BIT_VEC cppVar_89402 = ROM.rd(cppVar_89401);
	bool cppVar_89404 = (cppVar_89402 == 136);
	if (cppVar_89404) {
	cppVar_89400 = TCON;
	} else {
	BIT_VEC cppVar_89405;
	BIT_VEC cppVar_89406 = PC + 1;
	cppVar_89406 = (cppVar_89406 & cppMask_un_16_);
	BIT_VEC cppVar_89407 = ROM.rd(cppVar_89406);
	bool cppVar_89409 = (cppVar_89407 == 137);
	if (cppVar_89409) {
	cppVar_89405 = TMOD;
	} else {
	BIT_VEC cppVar_89410;
	BIT_VEC cppVar_89411 = PC + 1;
	cppVar_89411 = (cppVar_89411 & cppMask_un_16_);
	BIT_VEC cppVar_89412 = ROM.rd(cppVar_89411);
	bool cppVar_89414 = (cppVar_89412 == 138);
	if (cppVar_89414) {
	cppVar_89410 = TL0;
	} else {
	BIT_VEC cppVar_89415;
	BIT_VEC cppVar_89416 = PC + 1;
	cppVar_89416 = (cppVar_89416 & cppMask_un_16_);
	BIT_VEC cppVar_89417 = ROM.rd(cppVar_89416);
	bool cppVar_89419 = (cppVar_89417 == 140);
	if (cppVar_89419) {
	cppVar_89415 = TH0;
	} else {
	BIT_VEC cppVar_89420;
	BIT_VEC cppVar_89421 = PC + 1;
	cppVar_89421 = (cppVar_89421 & cppMask_un_16_);
	BIT_VEC cppVar_89422 = ROM.rd(cppVar_89421);
	bool cppVar_89424 = (cppVar_89422 == 139);
	if (cppVar_89424) {
	cppVar_89420 = TL1;
	} else {
	BIT_VEC cppVar_89425;
	BIT_VEC cppVar_89426 = PC + 1;
	cppVar_89426 = (cppVar_89426 & cppMask_un_16_);
	BIT_VEC cppVar_89427 = ROM.rd(cppVar_89426);
	bool cppVar_89429 = (cppVar_89427 == 141);
	if (cppVar_89429) {
	cppVar_89425 = TH1;
	} else {
	BIT_VEC cppVar_89430;
	BIT_VEC cppVar_89431 = PC + 1;
	cppVar_89431 = (cppVar_89431 & cppMask_un_16_);
	BIT_VEC cppVar_89432 = ROM.rd(cppVar_89431);
	bool cppVar_89434 = (cppVar_89432 == 144);
	if (cppVar_89434) {
	cppVar_89430 = P1;
	} else {
	BIT_VEC cppVar_89435;
	BIT_VEC cppVar_89436 = PC + 1;
	cppVar_89436 = (cppVar_89436 & cppMask_un_16_);
	BIT_VEC cppVar_89437 = ROM.rd(cppVar_89436);
	bool cppVar_89439 = (cppVar_89437 == 152);
	if (cppVar_89439) {
	cppVar_89435 = SCON;
	} else {
	BIT_VEC cppVar_89440;
	BIT_VEC cppVar_89441 = PC + 1;
	cppVar_89441 = (cppVar_89441 & cppMask_un_16_);
	BIT_VEC cppVar_89442 = ROM.rd(cppVar_89441);
	bool cppVar_89444 = (cppVar_89442 == 153);
	if (cppVar_89444) {
	cppVar_89440 = SBUF;
	} else {
	BIT_VEC cppVar_89445;
	BIT_VEC cppVar_89446 = PC + 1;
	cppVar_89446 = (cppVar_89446 & cppMask_un_16_);
	BIT_VEC cppVar_89447 = ROM.rd(cppVar_89446);
	bool cppVar_89449 = (cppVar_89447 == 160);
	if (cppVar_89449) {
	cppVar_89445 = P2;
	} else {
	BIT_VEC cppVar_89450;
	BIT_VEC cppVar_89451 = PC + 1;
	cppVar_89451 = (cppVar_89451 & cppMask_un_16_);
	BIT_VEC cppVar_89452 = ROM.rd(cppVar_89451);
	bool cppVar_89454 = (cppVar_89452 == 168);
	if (cppVar_89454) {
	cppVar_89450 = IE;
	} else {
	BIT_VEC cppVar_89455;
	BIT_VEC cppVar_89456 = PC + 1;
	cppVar_89456 = (cppVar_89456 & cppMask_un_16_);
	BIT_VEC cppVar_89457 = ROM.rd(cppVar_89456);
	bool cppVar_89459 = (cppVar_89457 == 176);
	if (cppVar_89459) {
	cppVar_89455 = P3;
	} else {
	BIT_VEC cppVar_89460;
	BIT_VEC cppVar_89461 = PC + 1;
	cppVar_89461 = (cppVar_89461 & cppMask_un_16_);
	BIT_VEC cppVar_89462 = ROM.rd(cppVar_89461);
	bool cppVar_89464 = (cppVar_89462 == 184);
	if (cppVar_89464) {
	cppVar_89460 = IP;
	} else {
	BIT_VEC cppVar_89465;
	BIT_VEC cppVar_89466 = PC + 1;
	cppVar_89466 = (cppVar_89466 & cppMask_un_16_);
	BIT_VEC cppVar_89467 = ROM.rd(cppVar_89466);
	bool cppVar_89469 = (cppVar_89467 == 208);
	if (cppVar_89469) {
	cppVar_89465 = PSW;
	} else {
	BIT_VEC cppVar_89470;
	BIT_VEC cppVar_89471 = PC + 1;
	cppVar_89471 = (cppVar_89471 & cppMask_un_16_);
	BIT_VEC cppVar_89472 = ROM.rd(cppVar_89471);
	bool cppVar_89474 = (cppVar_89472 == 224);
	if (cppVar_89474) {
	cppVar_89470 = ACC;
	} else {
	BIT_VEC cppVar_89475;
	BIT_VEC cppVar_89476 = PC + 1;
	cppVar_89476 = (cppVar_89476 & cppMask_un_16_);
	BIT_VEC cppVar_89477 = ROM.rd(cppVar_89476);
	bool cppVar_89479 = (cppVar_89477 == 240);
	if (cppVar_89479) {
	cppVar_89475 = B;
	} else {
	cppVar_89475 = 0;
	}
	cppVar_89470 = cppVar_89475;
	}
	cppVar_89465 = cppVar_89470;
	}
	cppVar_89460 = cppVar_89465;
	}
	cppVar_89455 = cppVar_89460;
	}
	cppVar_89450 = cppVar_89455;
	}
	cppVar_89445 = cppVar_89450;
	}
	cppVar_89440 = cppVar_89445;
	}
	cppVar_89435 = cppVar_89440;
	}
	cppVar_89430 = cppVar_89435;
	}
	cppVar_89425 = cppVar_89430;
	}
	cppVar_89420 = cppVar_89425;
	}
	cppVar_89415 = cppVar_89420;
	}
	cppVar_89410 = cppVar_89415;
	}
	cppVar_89405 = cppVar_89410;
	}
	cppVar_89400 = cppVar_89405;
	}
	cppVar_89395 = cppVar_89400;
	}
	cppVar_89390 = cppVar_89395;
	}
	cppVar_89385 = cppVar_89390;
	}
	cppVar_89380 = cppVar_89385;
	}
	cppVar_89375 = cppVar_89380;
	}
	cppVar_89365 = cppVar_89375;
	}
	type_mem cppVar_89481 = IRAM;
	cppVar_89481.wr(cppVar_89364, cppVar_89365);
	cppVar_89355 = cppVar_89481;
	} else {
	type_mem cppVar_89482;
	BIT_VEC cppVar_89483 = ROM.rd(PC);
	bool cppVar_89485 = (cppVar_89483 == 166);
	if (cppVar_89485) {
	BIT_VEC cppVar_89487 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_89489 = (cppVar_89487 << 3) | 0;
	cppVar_89489 = (cppVar_89489 & cppMask_un_5_);
	BIT_VEC cppVar_89490 = (0 << 5) | cppVar_89489;
	cppVar_89490 = (cppVar_89490 & cppMask_un_8_);
	BIT_VEC cppVar_89491 = IRAM.rd(cppVar_89490);
	BIT_VEC cppVar_89492;
	BIT_VEC cppVar_89494 = PC + 1;
	cppVar_89494 = (cppVar_89494 & cppMask_un_16_);
	BIT_VEC cppVar_89495 = ROM.rd(cppVar_89494);
	BIT_VEC cppVar_89496 = (cppVar_89495 >> 7) & cppMask_un_1_;
	bool cppVar_89498 = (cppVar_89496 == 0);
	if (cppVar_89498) {
	BIT_VEC cppVar_89499 = PC + 1;
	cppVar_89499 = (cppVar_89499 & cppMask_un_16_);
	BIT_VEC cppVar_89500 = ROM.rd(cppVar_89499);
	BIT_VEC cppVar_89501 = IRAM.rd(cppVar_89500);
	cppVar_89492 = cppVar_89501;
	} else {
	BIT_VEC cppVar_89502;
	BIT_VEC cppVar_89503 = PC + 1;
	cppVar_89503 = (cppVar_89503 & cppMask_un_16_);
	BIT_VEC cppVar_89504 = ROM.rd(cppVar_89503);
	bool cppVar_89506 = (cppVar_89504 == 128);
	if (cppVar_89506) {
	cppVar_89502 = P0;
	} else {
	BIT_VEC cppVar_89507;
	BIT_VEC cppVar_89508 = PC + 1;
	cppVar_89508 = (cppVar_89508 & cppMask_un_16_);
	BIT_VEC cppVar_89509 = ROM.rd(cppVar_89508);
	bool cppVar_89511 = (cppVar_89509 == 129);
	if (cppVar_89511) {
	cppVar_89507 = SP;
	} else {
	BIT_VEC cppVar_89512;
	BIT_VEC cppVar_89513 = PC + 1;
	cppVar_89513 = (cppVar_89513 & cppMask_un_16_);
	BIT_VEC cppVar_89514 = ROM.rd(cppVar_89513);
	bool cppVar_89516 = (cppVar_89514 == 130);
	if (cppVar_89516) {
	cppVar_89512 = DPL;
	} else {
	BIT_VEC cppVar_89517;
	BIT_VEC cppVar_89518 = PC + 1;
	cppVar_89518 = (cppVar_89518 & cppMask_un_16_);
	BIT_VEC cppVar_89519 = ROM.rd(cppVar_89518);
	bool cppVar_89521 = (cppVar_89519 == 131);
	if (cppVar_89521) {
	cppVar_89517 = DPH;
	} else {
	BIT_VEC cppVar_89522;
	BIT_VEC cppVar_89523 = PC + 1;
	cppVar_89523 = (cppVar_89523 & cppMask_un_16_);
	BIT_VEC cppVar_89524 = ROM.rd(cppVar_89523);
	bool cppVar_89526 = (cppVar_89524 == 135);
	if (cppVar_89526) {
	cppVar_89522 = PCON;
	} else {
	BIT_VEC cppVar_89527;
	BIT_VEC cppVar_89528 = PC + 1;
	cppVar_89528 = (cppVar_89528 & cppMask_un_16_);
	BIT_VEC cppVar_89529 = ROM.rd(cppVar_89528);
	bool cppVar_89531 = (cppVar_89529 == 136);
	if (cppVar_89531) {
	cppVar_89527 = TCON;
	} else {
	BIT_VEC cppVar_89532;
	BIT_VEC cppVar_89533 = PC + 1;
	cppVar_89533 = (cppVar_89533 & cppMask_un_16_);
	BIT_VEC cppVar_89534 = ROM.rd(cppVar_89533);
	bool cppVar_89536 = (cppVar_89534 == 137);
	if (cppVar_89536) {
	cppVar_89532 = TMOD;
	} else {
	BIT_VEC cppVar_89537;
	BIT_VEC cppVar_89538 = PC + 1;
	cppVar_89538 = (cppVar_89538 & cppMask_un_16_);
	BIT_VEC cppVar_89539 = ROM.rd(cppVar_89538);
	bool cppVar_89541 = (cppVar_89539 == 138);
	if (cppVar_89541) {
	cppVar_89537 = TL0;
	} else {
	BIT_VEC cppVar_89542;
	BIT_VEC cppVar_89543 = PC + 1;
	cppVar_89543 = (cppVar_89543 & cppMask_un_16_);
	BIT_VEC cppVar_89544 = ROM.rd(cppVar_89543);
	bool cppVar_89546 = (cppVar_89544 == 140);
	if (cppVar_89546) {
	cppVar_89542 = TH0;
	} else {
	BIT_VEC cppVar_89547;
	BIT_VEC cppVar_89548 = PC + 1;
	cppVar_89548 = (cppVar_89548 & cppMask_un_16_);
	BIT_VEC cppVar_89549 = ROM.rd(cppVar_89548);
	bool cppVar_89551 = (cppVar_89549 == 139);
	if (cppVar_89551) {
	cppVar_89547 = TL1;
	} else {
	BIT_VEC cppVar_89552;
	BIT_VEC cppVar_89553 = PC + 1;
	cppVar_89553 = (cppVar_89553 & cppMask_un_16_);
	BIT_VEC cppVar_89554 = ROM.rd(cppVar_89553);
	bool cppVar_89556 = (cppVar_89554 == 141);
	if (cppVar_89556) {
	cppVar_89552 = TH1;
	} else {
	BIT_VEC cppVar_89557;
	BIT_VEC cppVar_89558 = PC + 1;
	cppVar_89558 = (cppVar_89558 & cppMask_un_16_);
	BIT_VEC cppVar_89559 = ROM.rd(cppVar_89558);
	bool cppVar_89561 = (cppVar_89559 == 144);
	if (cppVar_89561) {
	cppVar_89557 = P1;
	} else {
	BIT_VEC cppVar_89562;
	BIT_VEC cppVar_89563 = PC + 1;
	cppVar_89563 = (cppVar_89563 & cppMask_un_16_);
	BIT_VEC cppVar_89564 = ROM.rd(cppVar_89563);
	bool cppVar_89566 = (cppVar_89564 == 152);
	if (cppVar_89566) {
	cppVar_89562 = SCON;
	} else {
	BIT_VEC cppVar_89567;
	BIT_VEC cppVar_89568 = PC + 1;
	cppVar_89568 = (cppVar_89568 & cppMask_un_16_);
	BIT_VEC cppVar_89569 = ROM.rd(cppVar_89568);
	bool cppVar_89571 = (cppVar_89569 == 153);
	if (cppVar_89571) {
	cppVar_89567 = SBUF;
	} else {
	BIT_VEC cppVar_89572;
	BIT_VEC cppVar_89573 = PC + 1;
	cppVar_89573 = (cppVar_89573 & cppMask_un_16_);
	BIT_VEC cppVar_89574 = ROM.rd(cppVar_89573);
	bool cppVar_89576 = (cppVar_89574 == 160);
	if (cppVar_89576) {
	cppVar_89572 = P2;
	} else {
	BIT_VEC cppVar_89577;
	BIT_VEC cppVar_89578 = PC + 1;
	cppVar_89578 = (cppVar_89578 & cppMask_un_16_);
	BIT_VEC cppVar_89579 = ROM.rd(cppVar_89578);
	bool cppVar_89581 = (cppVar_89579 == 168);
	if (cppVar_89581) {
	cppVar_89577 = IE;
	} else {
	BIT_VEC cppVar_89582;
	BIT_VEC cppVar_89583 = PC + 1;
	cppVar_89583 = (cppVar_89583 & cppMask_un_16_);
	BIT_VEC cppVar_89584 = ROM.rd(cppVar_89583);
	bool cppVar_89586 = (cppVar_89584 == 176);
	if (cppVar_89586) {
	cppVar_89582 = P3;
	} else {
	BIT_VEC cppVar_89587;
	BIT_VEC cppVar_89588 = PC + 1;
	cppVar_89588 = (cppVar_89588 & cppMask_un_16_);
	BIT_VEC cppVar_89589 = ROM.rd(cppVar_89588);
	bool cppVar_89591 = (cppVar_89589 == 184);
	if (cppVar_89591) {
	cppVar_89587 = IP;
	} else {
	BIT_VEC cppVar_89592;
	BIT_VEC cppVar_89593 = PC + 1;
	cppVar_89593 = (cppVar_89593 & cppMask_un_16_);
	BIT_VEC cppVar_89594 = ROM.rd(cppVar_89593);
	bool cppVar_89596 = (cppVar_89594 == 208);
	if (cppVar_89596) {
	cppVar_89592 = PSW;
	} else {
	BIT_VEC cppVar_89597;
	BIT_VEC cppVar_89598 = PC + 1;
	cppVar_89598 = (cppVar_89598 & cppMask_un_16_);
	BIT_VEC cppVar_89599 = ROM.rd(cppVar_89598);
	bool cppVar_89601 = (cppVar_89599 == 224);
	if (cppVar_89601) {
	cppVar_89597 = ACC;
	} else {
	BIT_VEC cppVar_89602;
	BIT_VEC cppVar_89603 = PC + 1;
	cppVar_89603 = (cppVar_89603 & cppMask_un_16_);
	BIT_VEC cppVar_89604 = ROM.rd(cppVar_89603);
	bool cppVar_89606 = (cppVar_89604 == 240);
	if (cppVar_89606) {
	cppVar_89602 = B;
	} else {
	cppVar_89602 = 0;
	}
	cppVar_89597 = cppVar_89602;
	}
	cppVar_89592 = cppVar_89597;
	}
	cppVar_89587 = cppVar_89592;
	}
	cppVar_89582 = cppVar_89587;
	}
	cppVar_89577 = cppVar_89582;
	}
	cppVar_89572 = cppVar_89577;
	}
	cppVar_89567 = cppVar_89572;
	}
	cppVar_89562 = cppVar_89567;
	}
	cppVar_89557 = cppVar_89562;
	}
	cppVar_89552 = cppVar_89557;
	}
	cppVar_89547 = cppVar_89552;
	}
	cppVar_89542 = cppVar_89547;
	}
	cppVar_89537 = cppVar_89542;
	}
	cppVar_89532 = cppVar_89537;
	}
	cppVar_89527 = cppVar_89532;
	}
	cppVar_89522 = cppVar_89527;
	}
	cppVar_89517 = cppVar_89522;
	}
	cppVar_89512 = cppVar_89517;
	}
	cppVar_89507 = cppVar_89512;
	}
	cppVar_89502 = cppVar_89507;
	}
	cppVar_89492 = cppVar_89502;
	}
	type_mem cppVar_89608 = IRAM;
	cppVar_89608.wr(cppVar_89491, cppVar_89492);
	cppVar_89482 = cppVar_89608;
	} else {
	type_mem cppVar_89609;
	BIT_VEC cppVar_89610 = ROM.rd(PC);
	bool cppVar_89612 = (cppVar_89610 == 146);
	if (cppVar_89612) {
	type_mem cppVar_89613;
	BIT_VEC cppVar_89614;
	BIT_VEC cppVar_89616 = PC + 1;
	cppVar_89616 = (cppVar_89616 & cppMask_un_16_);
	BIT_VEC cppVar_89617 = ROM.rd(cppVar_89616);
	BIT_VEC cppVar_89618 = (cppVar_89617 >> 7) & cppMask_un_1_;
	bool cppVar_89620 = (cppVar_89618 == 1);
	if (cppVar_89620) {
	BIT_VEC cppVar_89621 = PC + 1;
	cppVar_89621 = (cppVar_89621 & cppMask_un_16_);
	BIT_VEC cppVar_89622 = ROM.rd(cppVar_89621);
	BIT_VEC cppVar_89623 = (cppVar_89622 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_89625 = (cppVar_89623 << 3) | 0;
	cppVar_89625 = (cppVar_89625 & cppMask_un_8_);
	cppVar_89614 = cppVar_89625;
	} else {
	BIT_VEC cppVar_89626 = PC + 1;
	cppVar_89626 = (cppVar_89626 & cppMask_un_16_);
	BIT_VEC cppVar_89627 = ROM.rd(cppVar_89626);
	BIT_VEC cppVar_89628 = (cppVar_89627 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_89629 = (cppVar_89628 & cppMask_un_5_);
	BIT_VEC cppVar_89631 = cppVar_89629 + 32;
	cppVar_89631 = (cppVar_89631 & cppMask_un_8_);
	cppVar_89614 = cppVar_89631;
	}
	BIT_VEC cppVar_89632 = (cppVar_89614 >> 7) & cppMask_un_1_;
	bool cppVar_89634 = (cppVar_89632 == 0);
	if (cppVar_89634) {
	BIT_VEC cppVar_89635;
	BIT_VEC cppVar_89636 = PC + 1;
	cppVar_89636 = (cppVar_89636 & cppMask_un_16_);
	BIT_VEC cppVar_89637 = ROM.rd(cppVar_89636);
	BIT_VEC cppVar_89638 = (cppVar_89637 >> 7) & cppMask_un_1_;
	bool cppVar_89639 = (cppVar_89638 == 1);
	if (cppVar_89639) {
	BIT_VEC cppVar_89640 = PC + 1;
	cppVar_89640 = (cppVar_89640 & cppMask_un_16_);
	BIT_VEC cppVar_89641 = ROM.rd(cppVar_89640);
	BIT_VEC cppVar_89642 = (cppVar_89641 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_89643 = (cppVar_89642 << 3) | 0;
	cppVar_89643 = (cppVar_89643 & cppMask_un_8_);
	cppVar_89635 = cppVar_89643;
	} else {
	BIT_VEC cppVar_89644 = PC + 1;
	cppVar_89644 = (cppVar_89644 & cppMask_un_16_);
	BIT_VEC cppVar_89645 = ROM.rd(cppVar_89644);
	BIT_VEC cppVar_89646 = (cppVar_89645 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_89647 = (cppVar_89646 & cppMask_un_5_);
	BIT_VEC cppVar_89648 = cppVar_89647 + 32;
	cppVar_89648 = (cppVar_89648 & cppMask_un_8_);
	cppVar_89635 = cppVar_89648;
	}
	BIT_VEC cppVar_89650 = PC + 1;
	cppVar_89650 = (cppVar_89650 & cppMask_un_16_);
	BIT_VEC cppVar_89651 = ROM.rd(cppVar_89650);
	BIT_VEC cppVar_89652 = (cppVar_89651 >> 0) & cppMask_un_3_;
	BIT_VEC cppVar_89653 = (cppVar_89652 & cppMask_un_3_);
	BIT_VEC cppVar_89654 = 1 << static_cast<unsigned>(cppVar_89653);
	cppVar_89654 = (cppVar_89654 & cppMask_un_8_);
	BIT_VEC cppVar_89655 = ~cppVar_89654;
	BIT_VEC cppVar_89656;
	BIT_VEC cppVar_89657;
	BIT_VEC cppVar_89658 = PC + 1;
	cppVar_89658 = (cppVar_89658 & cppMask_un_16_);
	BIT_VEC cppVar_89659 = ROM.rd(cppVar_89658);
	BIT_VEC cppVar_89660 = (cppVar_89659 >> 7) & cppMask_un_1_;
	bool cppVar_89661 = (cppVar_89660 == 1);
	if (cppVar_89661) {
	BIT_VEC cppVar_89662 = PC + 1;
	cppVar_89662 = (cppVar_89662 & cppMask_un_16_);
	BIT_VEC cppVar_89663 = ROM.rd(cppVar_89662);
	BIT_VEC cppVar_89664 = (cppVar_89663 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_89665 = (cppVar_89664 << 3) | 0;
	cppVar_89665 = (cppVar_89665 & cppMask_un_8_);
	cppVar_89657 = cppVar_89665;
	} else {
	BIT_VEC cppVar_89666 = PC + 1;
	cppVar_89666 = (cppVar_89666 & cppMask_un_16_);
	BIT_VEC cppVar_89667 = ROM.rd(cppVar_89666);
	BIT_VEC cppVar_89668 = (cppVar_89667 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_89669 = (cppVar_89668 & cppMask_un_5_);
	BIT_VEC cppVar_89670 = cppVar_89669 + 32;
	cppVar_89670 = (cppVar_89670 & cppMask_un_8_);
	cppVar_89657 = cppVar_89670;
	}
	BIT_VEC cppVar_89671 = (cppVar_89657 >> 7) & cppMask_un_1_;
	bool cppVar_89673 = (cppVar_89671 == 0);
	if (cppVar_89673) {
	BIT_VEC cppVar_89674;
	BIT_VEC cppVar_89675 = PC + 1;
	cppVar_89675 = (cppVar_89675 & cppMask_un_16_);
	BIT_VEC cppVar_89676 = ROM.rd(cppVar_89675);
	BIT_VEC cppVar_89677 = (cppVar_89676 >> 7) & cppMask_un_1_;
	bool cppVar_89678 = (cppVar_89677 == 1);
	if (cppVar_89678) {
	BIT_VEC cppVar_89679 = PC + 1;
	cppVar_89679 = (cppVar_89679 & cppMask_un_16_);
	BIT_VEC cppVar_89680 = ROM.rd(cppVar_89679);
	BIT_VEC cppVar_89681 = (cppVar_89680 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_89682 = (cppVar_89681 << 3) | 0;
	cppVar_89682 = (cppVar_89682 & cppMask_un_8_);
	cppVar_89674 = cppVar_89682;
	} else {
	BIT_VEC cppVar_89683 = PC + 1;
	cppVar_89683 = (cppVar_89683 & cppMask_un_16_);
	BIT_VEC cppVar_89684 = ROM.rd(cppVar_89683);
	BIT_VEC cppVar_89685 = (cppVar_89684 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_89686 = (cppVar_89685 & cppMask_un_5_);
	BIT_VEC cppVar_89687 = cppVar_89686 + 32;
	cppVar_89687 = (cppVar_89687 & cppMask_un_8_);
	cppVar_89674 = cppVar_89687;
	}
	BIT_VEC cppVar_89688 = IRAM.rd(cppVar_89674);
	cppVar_89656 = cppVar_89688;
	} else {
	BIT_VEC cppVar_89689;
	BIT_VEC cppVar_89690;
	BIT_VEC cppVar_89691 = PC + 1;
	cppVar_89691 = (cppVar_89691 & cppMask_un_16_);
	BIT_VEC cppVar_89692 = ROM.rd(cppVar_89691);
	BIT_VEC cppVar_89693 = (cppVar_89692 >> 7) & cppMask_un_1_;
	bool cppVar_89694 = (cppVar_89693 == 1);
	if (cppVar_89694) {
	BIT_VEC cppVar_89695 = PC + 1;
	cppVar_89695 = (cppVar_89695 & cppMask_un_16_);
	BIT_VEC cppVar_89696 = ROM.rd(cppVar_89695);
	BIT_VEC cppVar_89697 = (cppVar_89696 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_89698 = (cppVar_89697 << 3) | 0;
	cppVar_89698 = (cppVar_89698 & cppMask_un_8_);
	cppVar_89690 = cppVar_89698;
	} else {
	BIT_VEC cppVar_89699 = PC + 1;
	cppVar_89699 = (cppVar_89699 & cppMask_un_16_);
	BIT_VEC cppVar_89700 = ROM.rd(cppVar_89699);
	BIT_VEC cppVar_89701 = (cppVar_89700 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_89702 = (cppVar_89701 & cppMask_un_5_);
	BIT_VEC cppVar_89703 = cppVar_89702 + 32;
	cppVar_89703 = (cppVar_89703 & cppMask_un_8_);
	cppVar_89690 = cppVar_89703;
	}
	bool cppVar_89705 = (cppVar_89690 == 128);
	if (cppVar_89705) {
	cppVar_89689 = P0;
	} else {
	BIT_VEC cppVar_89706;
	BIT_VEC cppVar_89707;
	BIT_VEC cppVar_89708 = PC + 1;
	cppVar_89708 = (cppVar_89708 & cppMask_un_16_);
	BIT_VEC cppVar_89709 = ROM.rd(cppVar_89708);
	BIT_VEC cppVar_89710 = (cppVar_89709 >> 7) & cppMask_un_1_;
	bool cppVar_89711 = (cppVar_89710 == 1);
	if (cppVar_89711) {
	BIT_VEC cppVar_89712 = PC + 1;
	cppVar_89712 = (cppVar_89712 & cppMask_un_16_);
	BIT_VEC cppVar_89713 = ROM.rd(cppVar_89712);
	BIT_VEC cppVar_89714 = (cppVar_89713 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_89715 = (cppVar_89714 << 3) | 0;
	cppVar_89715 = (cppVar_89715 & cppMask_un_8_);
	cppVar_89707 = cppVar_89715;
	} else {
	BIT_VEC cppVar_89716 = PC + 1;
	cppVar_89716 = (cppVar_89716 & cppMask_un_16_);
	BIT_VEC cppVar_89717 = ROM.rd(cppVar_89716);
	BIT_VEC cppVar_89718 = (cppVar_89717 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_89719 = (cppVar_89718 & cppMask_un_5_);
	BIT_VEC cppVar_89720 = cppVar_89719 + 32;
	cppVar_89720 = (cppVar_89720 & cppMask_un_8_);
	cppVar_89707 = cppVar_89720;
	}
	bool cppVar_89722 = (cppVar_89707 == 129);
	if (cppVar_89722) {
	cppVar_89706 = SP;
	} else {
	BIT_VEC cppVar_89723;
	BIT_VEC cppVar_89724;
	BIT_VEC cppVar_89725 = PC + 1;
	cppVar_89725 = (cppVar_89725 & cppMask_un_16_);
	BIT_VEC cppVar_89726 = ROM.rd(cppVar_89725);
	BIT_VEC cppVar_89727 = (cppVar_89726 >> 7) & cppMask_un_1_;
	bool cppVar_89728 = (cppVar_89727 == 1);
	if (cppVar_89728) {
	BIT_VEC cppVar_89729 = PC + 1;
	cppVar_89729 = (cppVar_89729 & cppMask_un_16_);
	BIT_VEC cppVar_89730 = ROM.rd(cppVar_89729);
	BIT_VEC cppVar_89731 = (cppVar_89730 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_89732 = (cppVar_89731 << 3) | 0;
	cppVar_89732 = (cppVar_89732 & cppMask_un_8_);
	cppVar_89724 = cppVar_89732;
	} else {
	BIT_VEC cppVar_89733 = PC + 1;
	cppVar_89733 = (cppVar_89733 & cppMask_un_16_);
	BIT_VEC cppVar_89734 = ROM.rd(cppVar_89733);
	BIT_VEC cppVar_89735 = (cppVar_89734 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_89736 = (cppVar_89735 & cppMask_un_5_);
	BIT_VEC cppVar_89737 = cppVar_89736 + 32;
	cppVar_89737 = (cppVar_89737 & cppMask_un_8_);
	cppVar_89724 = cppVar_89737;
	}
	bool cppVar_89739 = (cppVar_89724 == 130);
	if (cppVar_89739) {
	cppVar_89723 = DPL;
	} else {
	BIT_VEC cppVar_89740;
	BIT_VEC cppVar_89741;
	BIT_VEC cppVar_89742 = PC + 1;
	cppVar_89742 = (cppVar_89742 & cppMask_un_16_);
	BIT_VEC cppVar_89743 = ROM.rd(cppVar_89742);
	BIT_VEC cppVar_89744 = (cppVar_89743 >> 7) & cppMask_un_1_;
	bool cppVar_89745 = (cppVar_89744 == 1);
	if (cppVar_89745) {
	BIT_VEC cppVar_89746 = PC + 1;
	cppVar_89746 = (cppVar_89746 & cppMask_un_16_);
	BIT_VEC cppVar_89747 = ROM.rd(cppVar_89746);
	BIT_VEC cppVar_89748 = (cppVar_89747 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_89749 = (cppVar_89748 << 3) | 0;
	cppVar_89749 = (cppVar_89749 & cppMask_un_8_);
	cppVar_89741 = cppVar_89749;
	} else {
	BIT_VEC cppVar_89750 = PC + 1;
	cppVar_89750 = (cppVar_89750 & cppMask_un_16_);
	BIT_VEC cppVar_89751 = ROM.rd(cppVar_89750);
	BIT_VEC cppVar_89752 = (cppVar_89751 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_89753 = (cppVar_89752 & cppMask_un_5_);
	BIT_VEC cppVar_89754 = cppVar_89753 + 32;
	cppVar_89754 = (cppVar_89754 & cppMask_un_8_);
	cppVar_89741 = cppVar_89754;
	}
	bool cppVar_89756 = (cppVar_89741 == 131);
	if (cppVar_89756) {
	cppVar_89740 = DPH;
	} else {
	BIT_VEC cppVar_89757;
	BIT_VEC cppVar_89758;
	BIT_VEC cppVar_89759 = PC + 1;
	cppVar_89759 = (cppVar_89759 & cppMask_un_16_);
	BIT_VEC cppVar_89760 = ROM.rd(cppVar_89759);
	BIT_VEC cppVar_89761 = (cppVar_89760 >> 7) & cppMask_un_1_;
	bool cppVar_89762 = (cppVar_89761 == 1);
	if (cppVar_89762) {
	BIT_VEC cppVar_89763 = PC + 1;
	cppVar_89763 = (cppVar_89763 & cppMask_un_16_);
	BIT_VEC cppVar_89764 = ROM.rd(cppVar_89763);
	BIT_VEC cppVar_89765 = (cppVar_89764 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_89766 = (cppVar_89765 << 3) | 0;
	cppVar_89766 = (cppVar_89766 & cppMask_un_8_);
	cppVar_89758 = cppVar_89766;
	} else {
	BIT_VEC cppVar_89767 = PC + 1;
	cppVar_89767 = (cppVar_89767 & cppMask_un_16_);
	BIT_VEC cppVar_89768 = ROM.rd(cppVar_89767);
	BIT_VEC cppVar_89769 = (cppVar_89768 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_89770 = (cppVar_89769 & cppMask_un_5_);
	BIT_VEC cppVar_89771 = cppVar_89770 + 32;
	cppVar_89771 = (cppVar_89771 & cppMask_un_8_);
	cppVar_89758 = cppVar_89771;
	}
	bool cppVar_89773 = (cppVar_89758 == 135);
	if (cppVar_89773) {
	cppVar_89757 = PCON;
	} else {
	BIT_VEC cppVar_89774;
	BIT_VEC cppVar_89775;
	BIT_VEC cppVar_89776 = PC + 1;
	cppVar_89776 = (cppVar_89776 & cppMask_un_16_);
	BIT_VEC cppVar_89777 = ROM.rd(cppVar_89776);
	BIT_VEC cppVar_89778 = (cppVar_89777 >> 7) & cppMask_un_1_;
	bool cppVar_89779 = (cppVar_89778 == 1);
	if (cppVar_89779) {
	BIT_VEC cppVar_89780 = PC + 1;
	cppVar_89780 = (cppVar_89780 & cppMask_un_16_);
	BIT_VEC cppVar_89781 = ROM.rd(cppVar_89780);
	BIT_VEC cppVar_89782 = (cppVar_89781 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_89783 = (cppVar_89782 << 3) | 0;
	cppVar_89783 = (cppVar_89783 & cppMask_un_8_);
	cppVar_89775 = cppVar_89783;
	} else {
	BIT_VEC cppVar_89784 = PC + 1;
	cppVar_89784 = (cppVar_89784 & cppMask_un_16_);
	BIT_VEC cppVar_89785 = ROM.rd(cppVar_89784);
	BIT_VEC cppVar_89786 = (cppVar_89785 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_89787 = (cppVar_89786 & cppMask_un_5_);
	BIT_VEC cppVar_89788 = cppVar_89787 + 32;
	cppVar_89788 = (cppVar_89788 & cppMask_un_8_);
	cppVar_89775 = cppVar_89788;
	}
	bool cppVar_89790 = (cppVar_89775 == 136);
	if (cppVar_89790) {
	cppVar_89774 = TCON;
	} else {
	BIT_VEC cppVar_89791;
	BIT_VEC cppVar_89792;
	BIT_VEC cppVar_89793 = PC + 1;
	cppVar_89793 = (cppVar_89793 & cppMask_un_16_);
	BIT_VEC cppVar_89794 = ROM.rd(cppVar_89793);
	BIT_VEC cppVar_89795 = (cppVar_89794 >> 7) & cppMask_un_1_;
	bool cppVar_89796 = (cppVar_89795 == 1);
	if (cppVar_89796) {
	BIT_VEC cppVar_89797 = PC + 1;
	cppVar_89797 = (cppVar_89797 & cppMask_un_16_);
	BIT_VEC cppVar_89798 = ROM.rd(cppVar_89797);
	BIT_VEC cppVar_89799 = (cppVar_89798 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_89800 = (cppVar_89799 << 3) | 0;
	cppVar_89800 = (cppVar_89800 & cppMask_un_8_);
	cppVar_89792 = cppVar_89800;
	} else {
	BIT_VEC cppVar_89801 = PC + 1;
	cppVar_89801 = (cppVar_89801 & cppMask_un_16_);
	BIT_VEC cppVar_89802 = ROM.rd(cppVar_89801);
	BIT_VEC cppVar_89803 = (cppVar_89802 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_89804 = (cppVar_89803 & cppMask_un_5_);
	BIT_VEC cppVar_89805 = cppVar_89804 + 32;
	cppVar_89805 = (cppVar_89805 & cppMask_un_8_);
	cppVar_89792 = cppVar_89805;
	}
	bool cppVar_89807 = (cppVar_89792 == 137);
	if (cppVar_89807) {
	cppVar_89791 = TMOD;
	} else {
	BIT_VEC cppVar_89808;
	BIT_VEC cppVar_89809;
	BIT_VEC cppVar_89810 = PC + 1;
	cppVar_89810 = (cppVar_89810 & cppMask_un_16_);
	BIT_VEC cppVar_89811 = ROM.rd(cppVar_89810);
	BIT_VEC cppVar_89812 = (cppVar_89811 >> 7) & cppMask_un_1_;
	bool cppVar_89813 = (cppVar_89812 == 1);
	if (cppVar_89813) {
	BIT_VEC cppVar_89814 = PC + 1;
	cppVar_89814 = (cppVar_89814 & cppMask_un_16_);
	BIT_VEC cppVar_89815 = ROM.rd(cppVar_89814);
	BIT_VEC cppVar_89816 = (cppVar_89815 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_89817 = (cppVar_89816 << 3) | 0;
	cppVar_89817 = (cppVar_89817 & cppMask_un_8_);
	cppVar_89809 = cppVar_89817;
	} else {
	BIT_VEC cppVar_89818 = PC + 1;
	cppVar_89818 = (cppVar_89818 & cppMask_un_16_);
	BIT_VEC cppVar_89819 = ROM.rd(cppVar_89818);
	BIT_VEC cppVar_89820 = (cppVar_89819 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_89821 = (cppVar_89820 & cppMask_un_5_);
	BIT_VEC cppVar_89822 = cppVar_89821 + 32;
	cppVar_89822 = (cppVar_89822 & cppMask_un_8_);
	cppVar_89809 = cppVar_89822;
	}
	bool cppVar_89824 = (cppVar_89809 == 138);
	if (cppVar_89824) {
	cppVar_89808 = TL0;
	} else {
	BIT_VEC cppVar_89825;
	BIT_VEC cppVar_89826;
	BIT_VEC cppVar_89827 = PC + 1;
	cppVar_89827 = (cppVar_89827 & cppMask_un_16_);
	BIT_VEC cppVar_89828 = ROM.rd(cppVar_89827);
	BIT_VEC cppVar_89829 = (cppVar_89828 >> 7) & cppMask_un_1_;
	bool cppVar_89830 = (cppVar_89829 == 1);
	if (cppVar_89830) {
	BIT_VEC cppVar_89831 = PC + 1;
	cppVar_89831 = (cppVar_89831 & cppMask_un_16_);
	BIT_VEC cppVar_89832 = ROM.rd(cppVar_89831);
	BIT_VEC cppVar_89833 = (cppVar_89832 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_89834 = (cppVar_89833 << 3) | 0;
	cppVar_89834 = (cppVar_89834 & cppMask_un_8_);
	cppVar_89826 = cppVar_89834;
	} else {
	BIT_VEC cppVar_89835 = PC + 1;
	cppVar_89835 = (cppVar_89835 & cppMask_un_16_);
	BIT_VEC cppVar_89836 = ROM.rd(cppVar_89835);
	BIT_VEC cppVar_89837 = (cppVar_89836 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_89838 = (cppVar_89837 & cppMask_un_5_);
	BIT_VEC cppVar_89839 = cppVar_89838 + 32;
	cppVar_89839 = (cppVar_89839 & cppMask_un_8_);
	cppVar_89826 = cppVar_89839;
	}
	bool cppVar_89841 = (cppVar_89826 == 140);
	if (cppVar_89841) {
	cppVar_89825 = TH0;
	} else {
	BIT_VEC cppVar_89842;
	BIT_VEC cppVar_89843;
	BIT_VEC cppVar_89844 = PC + 1;
	cppVar_89844 = (cppVar_89844 & cppMask_un_16_);
	BIT_VEC cppVar_89845 = ROM.rd(cppVar_89844);
	BIT_VEC cppVar_89846 = (cppVar_89845 >> 7) & cppMask_un_1_;
	bool cppVar_89847 = (cppVar_89846 == 1);
	if (cppVar_89847) {
	BIT_VEC cppVar_89848 = PC + 1;
	cppVar_89848 = (cppVar_89848 & cppMask_un_16_);
	BIT_VEC cppVar_89849 = ROM.rd(cppVar_89848);
	BIT_VEC cppVar_89850 = (cppVar_89849 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_89851 = (cppVar_89850 << 3) | 0;
	cppVar_89851 = (cppVar_89851 & cppMask_un_8_);
	cppVar_89843 = cppVar_89851;
	} else {
	BIT_VEC cppVar_89852 = PC + 1;
	cppVar_89852 = (cppVar_89852 & cppMask_un_16_);
	BIT_VEC cppVar_89853 = ROM.rd(cppVar_89852);
	BIT_VEC cppVar_89854 = (cppVar_89853 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_89855 = (cppVar_89854 & cppMask_un_5_);
	BIT_VEC cppVar_89856 = cppVar_89855 + 32;
	cppVar_89856 = (cppVar_89856 & cppMask_un_8_);
	cppVar_89843 = cppVar_89856;
	}
	bool cppVar_89858 = (cppVar_89843 == 139);
	if (cppVar_89858) {
	cppVar_89842 = TL1;
	} else {
	BIT_VEC cppVar_89859;
	BIT_VEC cppVar_89860;
	BIT_VEC cppVar_89861 = PC + 1;
	cppVar_89861 = (cppVar_89861 & cppMask_un_16_);
	BIT_VEC cppVar_89862 = ROM.rd(cppVar_89861);
	BIT_VEC cppVar_89863 = (cppVar_89862 >> 7) & cppMask_un_1_;
	bool cppVar_89864 = (cppVar_89863 == 1);
	if (cppVar_89864) {
	BIT_VEC cppVar_89865 = PC + 1;
	cppVar_89865 = (cppVar_89865 & cppMask_un_16_);
	BIT_VEC cppVar_89866 = ROM.rd(cppVar_89865);
	BIT_VEC cppVar_89867 = (cppVar_89866 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_89868 = (cppVar_89867 << 3) | 0;
	cppVar_89868 = (cppVar_89868 & cppMask_un_8_);
	cppVar_89860 = cppVar_89868;
	} else {
	BIT_VEC cppVar_89869 = PC + 1;
	cppVar_89869 = (cppVar_89869 & cppMask_un_16_);
	BIT_VEC cppVar_89870 = ROM.rd(cppVar_89869);
	BIT_VEC cppVar_89871 = (cppVar_89870 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_89872 = (cppVar_89871 & cppMask_un_5_);
	BIT_VEC cppVar_89873 = cppVar_89872 + 32;
	cppVar_89873 = (cppVar_89873 & cppMask_un_8_);
	cppVar_89860 = cppVar_89873;
	}
	bool cppVar_89875 = (cppVar_89860 == 141);
	if (cppVar_89875) {
	cppVar_89859 = TH1;
	} else {
	BIT_VEC cppVar_89876;
	BIT_VEC cppVar_89877;
	BIT_VEC cppVar_89878 = PC + 1;
	cppVar_89878 = (cppVar_89878 & cppMask_un_16_);
	BIT_VEC cppVar_89879 = ROM.rd(cppVar_89878);
	BIT_VEC cppVar_89880 = (cppVar_89879 >> 7) & cppMask_un_1_;
	bool cppVar_89881 = (cppVar_89880 == 1);
	if (cppVar_89881) {
	BIT_VEC cppVar_89882 = PC + 1;
	cppVar_89882 = (cppVar_89882 & cppMask_un_16_);
	BIT_VEC cppVar_89883 = ROM.rd(cppVar_89882);
	BIT_VEC cppVar_89884 = (cppVar_89883 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_89885 = (cppVar_89884 << 3) | 0;
	cppVar_89885 = (cppVar_89885 & cppMask_un_8_);
	cppVar_89877 = cppVar_89885;
	} else {
	BIT_VEC cppVar_89886 = PC + 1;
	cppVar_89886 = (cppVar_89886 & cppMask_un_16_);
	BIT_VEC cppVar_89887 = ROM.rd(cppVar_89886);
	BIT_VEC cppVar_89888 = (cppVar_89887 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_89889 = (cppVar_89888 & cppMask_un_5_);
	BIT_VEC cppVar_89890 = cppVar_89889 + 32;
	cppVar_89890 = (cppVar_89890 & cppMask_un_8_);
	cppVar_89877 = cppVar_89890;
	}
	bool cppVar_89892 = (cppVar_89877 == 144);
	if (cppVar_89892) {
	cppVar_89876 = P1;
	} else {
	BIT_VEC cppVar_89893;
	BIT_VEC cppVar_89894;
	BIT_VEC cppVar_89895 = PC + 1;
	cppVar_89895 = (cppVar_89895 & cppMask_un_16_);
	BIT_VEC cppVar_89896 = ROM.rd(cppVar_89895);
	BIT_VEC cppVar_89897 = (cppVar_89896 >> 7) & cppMask_un_1_;
	bool cppVar_89898 = (cppVar_89897 == 1);
	if (cppVar_89898) {
	BIT_VEC cppVar_89899 = PC + 1;
	cppVar_89899 = (cppVar_89899 & cppMask_un_16_);
	BIT_VEC cppVar_89900 = ROM.rd(cppVar_89899);
	BIT_VEC cppVar_89901 = (cppVar_89900 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_89902 = (cppVar_89901 << 3) | 0;
	cppVar_89902 = (cppVar_89902 & cppMask_un_8_);
	cppVar_89894 = cppVar_89902;
	} else {
	BIT_VEC cppVar_89903 = PC + 1;
	cppVar_89903 = (cppVar_89903 & cppMask_un_16_);
	BIT_VEC cppVar_89904 = ROM.rd(cppVar_89903);
	BIT_VEC cppVar_89905 = (cppVar_89904 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_89906 = (cppVar_89905 & cppMask_un_5_);
	BIT_VEC cppVar_89907 = cppVar_89906 + 32;
	cppVar_89907 = (cppVar_89907 & cppMask_un_8_);
	cppVar_89894 = cppVar_89907;
	}
	bool cppVar_89909 = (cppVar_89894 == 152);
	if (cppVar_89909) {
	cppVar_89893 = SCON;
	} else {
	BIT_VEC cppVar_89910;
	BIT_VEC cppVar_89911;
	BIT_VEC cppVar_89912 = PC + 1;
	cppVar_89912 = (cppVar_89912 & cppMask_un_16_);
	BIT_VEC cppVar_89913 = ROM.rd(cppVar_89912);
	BIT_VEC cppVar_89914 = (cppVar_89913 >> 7) & cppMask_un_1_;
	bool cppVar_89915 = (cppVar_89914 == 1);
	if (cppVar_89915) {
	BIT_VEC cppVar_89916 = PC + 1;
	cppVar_89916 = (cppVar_89916 & cppMask_un_16_);
	BIT_VEC cppVar_89917 = ROM.rd(cppVar_89916);
	BIT_VEC cppVar_89918 = (cppVar_89917 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_89919 = (cppVar_89918 << 3) | 0;
	cppVar_89919 = (cppVar_89919 & cppMask_un_8_);
	cppVar_89911 = cppVar_89919;
	} else {
	BIT_VEC cppVar_89920 = PC + 1;
	cppVar_89920 = (cppVar_89920 & cppMask_un_16_);
	BIT_VEC cppVar_89921 = ROM.rd(cppVar_89920);
	BIT_VEC cppVar_89922 = (cppVar_89921 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_89923 = (cppVar_89922 & cppMask_un_5_);
	BIT_VEC cppVar_89924 = cppVar_89923 + 32;
	cppVar_89924 = (cppVar_89924 & cppMask_un_8_);
	cppVar_89911 = cppVar_89924;
	}
	bool cppVar_89926 = (cppVar_89911 == 153);
	if (cppVar_89926) {
	cppVar_89910 = SBUF;
	} else {
	BIT_VEC cppVar_89927;
	BIT_VEC cppVar_89928;
	BIT_VEC cppVar_89929 = PC + 1;
	cppVar_89929 = (cppVar_89929 & cppMask_un_16_);
	BIT_VEC cppVar_89930 = ROM.rd(cppVar_89929);
	BIT_VEC cppVar_89931 = (cppVar_89930 >> 7) & cppMask_un_1_;
	bool cppVar_89932 = (cppVar_89931 == 1);
	if (cppVar_89932) {
	BIT_VEC cppVar_89933 = PC + 1;
	cppVar_89933 = (cppVar_89933 & cppMask_un_16_);
	BIT_VEC cppVar_89934 = ROM.rd(cppVar_89933);
	BIT_VEC cppVar_89935 = (cppVar_89934 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_89936 = (cppVar_89935 << 3) | 0;
	cppVar_89936 = (cppVar_89936 & cppMask_un_8_);
	cppVar_89928 = cppVar_89936;
	} else {
	BIT_VEC cppVar_89937 = PC + 1;
	cppVar_89937 = (cppVar_89937 & cppMask_un_16_);
	BIT_VEC cppVar_89938 = ROM.rd(cppVar_89937);
	BIT_VEC cppVar_89939 = (cppVar_89938 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_89940 = (cppVar_89939 & cppMask_un_5_);
	BIT_VEC cppVar_89941 = cppVar_89940 + 32;
	cppVar_89941 = (cppVar_89941 & cppMask_un_8_);
	cppVar_89928 = cppVar_89941;
	}
	bool cppVar_89943 = (cppVar_89928 == 160);
	if (cppVar_89943) {
	cppVar_89927 = P2;
	} else {
	BIT_VEC cppVar_89944;
	BIT_VEC cppVar_89945;
	BIT_VEC cppVar_89946 = PC + 1;
	cppVar_89946 = (cppVar_89946 & cppMask_un_16_);
	BIT_VEC cppVar_89947 = ROM.rd(cppVar_89946);
	BIT_VEC cppVar_89948 = (cppVar_89947 >> 7) & cppMask_un_1_;
	bool cppVar_89949 = (cppVar_89948 == 1);
	if (cppVar_89949) {
	BIT_VEC cppVar_89950 = PC + 1;
	cppVar_89950 = (cppVar_89950 & cppMask_un_16_);
	BIT_VEC cppVar_89951 = ROM.rd(cppVar_89950);
	BIT_VEC cppVar_89952 = (cppVar_89951 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_89953 = (cppVar_89952 << 3) | 0;
	cppVar_89953 = (cppVar_89953 & cppMask_un_8_);
	cppVar_89945 = cppVar_89953;
	} else {
	BIT_VEC cppVar_89954 = PC + 1;
	cppVar_89954 = (cppVar_89954 & cppMask_un_16_);
	BIT_VEC cppVar_89955 = ROM.rd(cppVar_89954);
	BIT_VEC cppVar_89956 = (cppVar_89955 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_89957 = (cppVar_89956 & cppMask_un_5_);
	BIT_VEC cppVar_89958 = cppVar_89957 + 32;
	cppVar_89958 = (cppVar_89958 & cppMask_un_8_);
	cppVar_89945 = cppVar_89958;
	}
	bool cppVar_89960 = (cppVar_89945 == 168);
	if (cppVar_89960) {
	cppVar_89944 = IE;
	} else {
	BIT_VEC cppVar_89961;
	BIT_VEC cppVar_89962;
	BIT_VEC cppVar_89963 = PC + 1;
	cppVar_89963 = (cppVar_89963 & cppMask_un_16_);
	BIT_VEC cppVar_89964 = ROM.rd(cppVar_89963);
	BIT_VEC cppVar_89965 = (cppVar_89964 >> 7) & cppMask_un_1_;
	bool cppVar_89966 = (cppVar_89965 == 1);
	if (cppVar_89966) {
	BIT_VEC cppVar_89967 = PC + 1;
	cppVar_89967 = (cppVar_89967 & cppMask_un_16_);
	BIT_VEC cppVar_89968 = ROM.rd(cppVar_89967);
	BIT_VEC cppVar_89969 = (cppVar_89968 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_89970 = (cppVar_89969 << 3) | 0;
	cppVar_89970 = (cppVar_89970 & cppMask_un_8_);
	cppVar_89962 = cppVar_89970;
	} else {
	BIT_VEC cppVar_89971 = PC + 1;
	cppVar_89971 = (cppVar_89971 & cppMask_un_16_);
	BIT_VEC cppVar_89972 = ROM.rd(cppVar_89971);
	BIT_VEC cppVar_89973 = (cppVar_89972 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_89974 = (cppVar_89973 & cppMask_un_5_);
	BIT_VEC cppVar_89975 = cppVar_89974 + 32;
	cppVar_89975 = (cppVar_89975 & cppMask_un_8_);
	cppVar_89962 = cppVar_89975;
	}
	bool cppVar_89977 = (cppVar_89962 == 176);
	if (cppVar_89977) {
	cppVar_89961 = P3;
	} else {
	BIT_VEC cppVar_89978;
	BIT_VEC cppVar_89979;
	BIT_VEC cppVar_89980 = PC + 1;
	cppVar_89980 = (cppVar_89980 & cppMask_un_16_);
	BIT_VEC cppVar_89981 = ROM.rd(cppVar_89980);
	BIT_VEC cppVar_89982 = (cppVar_89981 >> 7) & cppMask_un_1_;
	bool cppVar_89983 = (cppVar_89982 == 1);
	if (cppVar_89983) {
	BIT_VEC cppVar_89984 = PC + 1;
	cppVar_89984 = (cppVar_89984 & cppMask_un_16_);
	BIT_VEC cppVar_89985 = ROM.rd(cppVar_89984);
	BIT_VEC cppVar_89986 = (cppVar_89985 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_89987 = (cppVar_89986 << 3) | 0;
	cppVar_89987 = (cppVar_89987 & cppMask_un_8_);
	cppVar_89979 = cppVar_89987;
	} else {
	BIT_VEC cppVar_89988 = PC + 1;
	cppVar_89988 = (cppVar_89988 & cppMask_un_16_);
	BIT_VEC cppVar_89989 = ROM.rd(cppVar_89988);
	BIT_VEC cppVar_89990 = (cppVar_89989 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_89991 = (cppVar_89990 & cppMask_un_5_);
	BIT_VEC cppVar_89992 = cppVar_89991 + 32;
	cppVar_89992 = (cppVar_89992 & cppMask_un_8_);
	cppVar_89979 = cppVar_89992;
	}
	bool cppVar_89994 = (cppVar_89979 == 184);
	if (cppVar_89994) {
	cppVar_89978 = IP;
	} else {
	BIT_VEC cppVar_89995;
	BIT_VEC cppVar_89996;
	BIT_VEC cppVar_89997 = PC + 1;
	cppVar_89997 = (cppVar_89997 & cppMask_un_16_);
	BIT_VEC cppVar_89998 = ROM.rd(cppVar_89997);
	BIT_VEC cppVar_89999 = (cppVar_89998 >> 7) & cppMask_un_1_;
	bool cppVar_90000 = (cppVar_89999 == 1);
	if (cppVar_90000) {
	BIT_VEC cppVar_90001 = PC + 1;
	cppVar_90001 = (cppVar_90001 & cppMask_un_16_);
	BIT_VEC cppVar_90002 = ROM.rd(cppVar_90001);
	BIT_VEC cppVar_90003 = (cppVar_90002 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_90004 = (cppVar_90003 << 3) | 0;
	cppVar_90004 = (cppVar_90004 & cppMask_un_8_);
	cppVar_89996 = cppVar_90004;
	} else {
	BIT_VEC cppVar_90005 = PC + 1;
	cppVar_90005 = (cppVar_90005 & cppMask_un_16_);
	BIT_VEC cppVar_90006 = ROM.rd(cppVar_90005);
	BIT_VEC cppVar_90007 = (cppVar_90006 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_90008 = (cppVar_90007 & cppMask_un_5_);
	BIT_VEC cppVar_90009 = cppVar_90008 + 32;
	cppVar_90009 = (cppVar_90009 & cppMask_un_8_);
	cppVar_89996 = cppVar_90009;
	}
	bool cppVar_90011 = (cppVar_89996 == 208);
	if (cppVar_90011) {
	cppVar_89995 = PSW;
	} else {
	BIT_VEC cppVar_90012;
	BIT_VEC cppVar_90013;
	BIT_VEC cppVar_90014 = PC + 1;
	cppVar_90014 = (cppVar_90014 & cppMask_un_16_);
	BIT_VEC cppVar_90015 = ROM.rd(cppVar_90014);
	BIT_VEC cppVar_90016 = (cppVar_90015 >> 7) & cppMask_un_1_;
	bool cppVar_90017 = (cppVar_90016 == 1);
	if (cppVar_90017) {
	BIT_VEC cppVar_90018 = PC + 1;
	cppVar_90018 = (cppVar_90018 & cppMask_un_16_);
	BIT_VEC cppVar_90019 = ROM.rd(cppVar_90018);
	BIT_VEC cppVar_90020 = (cppVar_90019 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_90021 = (cppVar_90020 << 3) | 0;
	cppVar_90021 = (cppVar_90021 & cppMask_un_8_);
	cppVar_90013 = cppVar_90021;
	} else {
	BIT_VEC cppVar_90022 = PC + 1;
	cppVar_90022 = (cppVar_90022 & cppMask_un_16_);
	BIT_VEC cppVar_90023 = ROM.rd(cppVar_90022);
	BIT_VEC cppVar_90024 = (cppVar_90023 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_90025 = (cppVar_90024 & cppMask_un_5_);
	BIT_VEC cppVar_90026 = cppVar_90025 + 32;
	cppVar_90026 = (cppVar_90026 & cppMask_un_8_);
	cppVar_90013 = cppVar_90026;
	}
	bool cppVar_90028 = (cppVar_90013 == 224);
	if (cppVar_90028) {
	cppVar_90012 = ACC;
	} else {
	BIT_VEC cppVar_90029;
	BIT_VEC cppVar_90030;
	BIT_VEC cppVar_90031 = PC + 1;
	cppVar_90031 = (cppVar_90031 & cppMask_un_16_);
	BIT_VEC cppVar_90032 = ROM.rd(cppVar_90031);
	BIT_VEC cppVar_90033 = (cppVar_90032 >> 7) & cppMask_un_1_;
	bool cppVar_90034 = (cppVar_90033 == 1);
	if (cppVar_90034) {
	BIT_VEC cppVar_90035 = PC + 1;
	cppVar_90035 = (cppVar_90035 & cppMask_un_16_);
	BIT_VEC cppVar_90036 = ROM.rd(cppVar_90035);
	BIT_VEC cppVar_90037 = (cppVar_90036 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_90038 = (cppVar_90037 << 3) | 0;
	cppVar_90038 = (cppVar_90038 & cppMask_un_8_);
	cppVar_90030 = cppVar_90038;
	} else {
	BIT_VEC cppVar_90039 = PC + 1;
	cppVar_90039 = (cppVar_90039 & cppMask_un_16_);
	BIT_VEC cppVar_90040 = ROM.rd(cppVar_90039);
	BIT_VEC cppVar_90041 = (cppVar_90040 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_90042 = (cppVar_90041 & cppMask_un_5_);
	BIT_VEC cppVar_90043 = cppVar_90042 + 32;
	cppVar_90043 = (cppVar_90043 & cppMask_un_8_);
	cppVar_90030 = cppVar_90043;
	}
	bool cppVar_90045 = (cppVar_90030 == 240);
	if (cppVar_90045) {
	cppVar_90029 = B;
	} else {
	cppVar_90029 = 0;
	}
	cppVar_90012 = cppVar_90029;
	}
	cppVar_89995 = cppVar_90012;
	}
	cppVar_89978 = cppVar_89995;
	}
	cppVar_89961 = cppVar_89978;
	}
	cppVar_89944 = cppVar_89961;
	}
	cppVar_89927 = cppVar_89944;
	}
	cppVar_89910 = cppVar_89927;
	}
	cppVar_89893 = cppVar_89910;
	}
	cppVar_89876 = cppVar_89893;
	}
	cppVar_89859 = cppVar_89876;
	}
	cppVar_89842 = cppVar_89859;
	}
	cppVar_89825 = cppVar_89842;
	}
	cppVar_89808 = cppVar_89825;
	}
	cppVar_89791 = cppVar_89808;
	}
	cppVar_89774 = cppVar_89791;
	}
	cppVar_89757 = cppVar_89774;
	}
	cppVar_89740 = cppVar_89757;
	}
	cppVar_89723 = cppVar_89740;
	}
	cppVar_89706 = cppVar_89723;
	}
	cppVar_89689 = cppVar_89706;
	}
	cppVar_89656 = cppVar_89689;
	}
	BIT_VEC cppVar_90047 = cppVar_89655 & cppVar_89656;
	BIT_VEC cppVar_90048 = (PSW >> 7) & cppMask_un_1_;
	BIT_VEC cppVar_90049 = (cppVar_90048 & cppMask_un_1_);
	BIT_VEC cppVar_90050 = PC + 1;
	cppVar_90050 = (cppVar_90050 & cppMask_un_16_);
	BIT_VEC cppVar_90051 = ROM.rd(cppVar_90050);
	BIT_VEC cppVar_90052 = (cppVar_90051 >> 0) & cppMask_un_3_;
	BIT_VEC cppVar_90053 = (cppVar_90052 & cppMask_un_3_);
	BIT_VEC cppVar_90054 = cppVar_90049 << static_cast<unsigned>(cppVar_90053);
	cppVar_90054 = (cppVar_90054 & cppMask_un_8_);
	BIT_VEC cppVar_90055 = cppVar_90047 | cppVar_90054;
	type_mem cppVar_90056 = IRAM;
	cppVar_90056.wr(cppVar_89635, cppVar_90055);
	cppVar_89613 = cppVar_90056;
	} else {
	cppVar_89613 = IRAM;
	}
	cppVar_89609 = cppVar_89613;
	} else {
	type_mem cppVar_90057;
	BIT_VEC cppVar_90058 = ROM.rd(PC);
	bool cppVar_90060 = (cppVar_90058 == 143);
	if (cppVar_90060) {
	type_mem cppVar_90061;
	BIT_VEC cppVar_90063 = PC + 1;
	cppVar_90063 = (cppVar_90063 & cppMask_un_16_);
	BIT_VEC cppVar_90064 = ROM.rd(cppVar_90063);
	BIT_VEC cppVar_90065 = (cppVar_90064 >> 7) & cppMask_un_1_;
	bool cppVar_90067 = (cppVar_90065 == 0);
	if (cppVar_90067) {
	BIT_VEC cppVar_90068 = PC + 1;
	cppVar_90068 = (cppVar_90068 & cppMask_un_16_);
	BIT_VEC cppVar_90069 = ROM.rd(cppVar_90068);
	BIT_VEC cppVar_90070;
	BIT_VEC cppVar_90072 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_90074 = (cppVar_90072 << 3) | 7;
	cppVar_90074 = (cppVar_90074 & cppMask_un_5_);
	BIT_VEC cppVar_90075 = (0 << 5) | cppVar_90074;
	cppVar_90075 = (cppVar_90075 & cppMask_un_8_);
	BIT_VEC cppVar_90076 = (cppVar_90075 >> 7) & cppMask_un_1_;
	bool cppVar_90078 = (cppVar_90076 == 0);
	if (cppVar_90078) {
	BIT_VEC cppVar_90079 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_90080 = (cppVar_90079 << 3) | 7;
	cppVar_90080 = (cppVar_90080 & cppMask_un_5_);
	BIT_VEC cppVar_90081 = (0 << 5) | cppVar_90080;
	cppVar_90081 = (cppVar_90081 & cppMask_un_8_);
	BIT_VEC cppVar_90082 = IRAM.rd(cppVar_90081);
	cppVar_90070 = cppVar_90082;
	} else {
	BIT_VEC cppVar_90083;
	BIT_VEC cppVar_90084 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_90085 = (cppVar_90084 << 3) | 7;
	cppVar_90085 = (cppVar_90085 & cppMask_un_5_);
	BIT_VEC cppVar_90086 = (0 << 5) | cppVar_90085;
	cppVar_90086 = (cppVar_90086 & cppMask_un_8_);
	bool cppVar_90088 = (cppVar_90086 == 128);
	if (cppVar_90088) {
	cppVar_90083 = P0;
	} else {
	BIT_VEC cppVar_90089;
	BIT_VEC cppVar_90090 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_90091 = (cppVar_90090 << 3) | 7;
	cppVar_90091 = (cppVar_90091 & cppMask_un_5_);
	BIT_VEC cppVar_90092 = (0 << 5) | cppVar_90091;
	cppVar_90092 = (cppVar_90092 & cppMask_un_8_);
	bool cppVar_90094 = (cppVar_90092 == 129);
	if (cppVar_90094) {
	cppVar_90089 = SP;
	} else {
	BIT_VEC cppVar_90095;
	BIT_VEC cppVar_90096 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_90097 = (cppVar_90096 << 3) | 7;
	cppVar_90097 = (cppVar_90097 & cppMask_un_5_);
	BIT_VEC cppVar_90098 = (0 << 5) | cppVar_90097;
	cppVar_90098 = (cppVar_90098 & cppMask_un_8_);
	bool cppVar_90100 = (cppVar_90098 == 130);
	if (cppVar_90100) {
	cppVar_90095 = DPL;
	} else {
	BIT_VEC cppVar_90101;
	BIT_VEC cppVar_90102 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_90103 = (cppVar_90102 << 3) | 7;
	cppVar_90103 = (cppVar_90103 & cppMask_un_5_);
	BIT_VEC cppVar_90104 = (0 << 5) | cppVar_90103;
	cppVar_90104 = (cppVar_90104 & cppMask_un_8_);
	bool cppVar_90106 = (cppVar_90104 == 131);
	if (cppVar_90106) {
	cppVar_90101 = DPH;
	} else {
	BIT_VEC cppVar_90107;
	BIT_VEC cppVar_90108 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_90109 = (cppVar_90108 << 3) | 7;
	cppVar_90109 = (cppVar_90109 & cppMask_un_5_);
	BIT_VEC cppVar_90110 = (0 << 5) | cppVar_90109;
	cppVar_90110 = (cppVar_90110 & cppMask_un_8_);
	bool cppVar_90112 = (cppVar_90110 == 135);
	if (cppVar_90112) {
	cppVar_90107 = PCON;
	} else {
	BIT_VEC cppVar_90113;
	BIT_VEC cppVar_90114 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_90115 = (cppVar_90114 << 3) | 7;
	cppVar_90115 = (cppVar_90115 & cppMask_un_5_);
	BIT_VEC cppVar_90116 = (0 << 5) | cppVar_90115;
	cppVar_90116 = (cppVar_90116 & cppMask_un_8_);
	bool cppVar_90118 = (cppVar_90116 == 136);
	if (cppVar_90118) {
	cppVar_90113 = TCON;
	} else {
	BIT_VEC cppVar_90119;
	BIT_VEC cppVar_90120 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_90121 = (cppVar_90120 << 3) | 7;
	cppVar_90121 = (cppVar_90121 & cppMask_un_5_);
	BIT_VEC cppVar_90122 = (0 << 5) | cppVar_90121;
	cppVar_90122 = (cppVar_90122 & cppMask_un_8_);
	bool cppVar_90124 = (cppVar_90122 == 137);
	if (cppVar_90124) {
	cppVar_90119 = TMOD;
	} else {
	BIT_VEC cppVar_90125;
	BIT_VEC cppVar_90126 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_90127 = (cppVar_90126 << 3) | 7;
	cppVar_90127 = (cppVar_90127 & cppMask_un_5_);
	BIT_VEC cppVar_90128 = (0 << 5) | cppVar_90127;
	cppVar_90128 = (cppVar_90128 & cppMask_un_8_);
	bool cppVar_90130 = (cppVar_90128 == 138);
	if (cppVar_90130) {
	cppVar_90125 = TL0;
	} else {
	BIT_VEC cppVar_90131;
	BIT_VEC cppVar_90132 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_90133 = (cppVar_90132 << 3) | 7;
	cppVar_90133 = (cppVar_90133 & cppMask_un_5_);
	BIT_VEC cppVar_90134 = (0 << 5) | cppVar_90133;
	cppVar_90134 = (cppVar_90134 & cppMask_un_8_);
	bool cppVar_90136 = (cppVar_90134 == 140);
	if (cppVar_90136) {
	cppVar_90131 = TH0;
	} else {
	BIT_VEC cppVar_90137;
	BIT_VEC cppVar_90138 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_90139 = (cppVar_90138 << 3) | 7;
	cppVar_90139 = (cppVar_90139 & cppMask_un_5_);
	BIT_VEC cppVar_90140 = (0 << 5) | cppVar_90139;
	cppVar_90140 = (cppVar_90140 & cppMask_un_8_);
	bool cppVar_90142 = (cppVar_90140 == 139);
	if (cppVar_90142) {
	cppVar_90137 = TL1;
	} else {
	BIT_VEC cppVar_90143;
	BIT_VEC cppVar_90144 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_90145 = (cppVar_90144 << 3) | 7;
	cppVar_90145 = (cppVar_90145 & cppMask_un_5_);
	BIT_VEC cppVar_90146 = (0 << 5) | cppVar_90145;
	cppVar_90146 = (cppVar_90146 & cppMask_un_8_);
	bool cppVar_90148 = (cppVar_90146 == 141);
	if (cppVar_90148) {
	cppVar_90143 = TH1;
	} else {
	BIT_VEC cppVar_90149;
	BIT_VEC cppVar_90150 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_90151 = (cppVar_90150 << 3) | 7;
	cppVar_90151 = (cppVar_90151 & cppMask_un_5_);
	BIT_VEC cppVar_90152 = (0 << 5) | cppVar_90151;
	cppVar_90152 = (cppVar_90152 & cppMask_un_8_);
	bool cppVar_90154 = (cppVar_90152 == 144);
	if (cppVar_90154) {
	cppVar_90149 = P1;
	} else {
	BIT_VEC cppVar_90155;
	BIT_VEC cppVar_90156 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_90157 = (cppVar_90156 << 3) | 7;
	cppVar_90157 = (cppVar_90157 & cppMask_un_5_);
	BIT_VEC cppVar_90158 = (0 << 5) | cppVar_90157;
	cppVar_90158 = (cppVar_90158 & cppMask_un_8_);
	bool cppVar_90160 = (cppVar_90158 == 152);
	if (cppVar_90160) {
	cppVar_90155 = SCON;
	} else {
	BIT_VEC cppVar_90161;
	BIT_VEC cppVar_90162 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_90163 = (cppVar_90162 << 3) | 7;
	cppVar_90163 = (cppVar_90163 & cppMask_un_5_);
	BIT_VEC cppVar_90164 = (0 << 5) | cppVar_90163;
	cppVar_90164 = (cppVar_90164 & cppMask_un_8_);
	bool cppVar_90166 = (cppVar_90164 == 153);
	if (cppVar_90166) {
	cppVar_90161 = SBUF;
	} else {
	BIT_VEC cppVar_90167;
	BIT_VEC cppVar_90168 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_90169 = (cppVar_90168 << 3) | 7;
	cppVar_90169 = (cppVar_90169 & cppMask_un_5_);
	BIT_VEC cppVar_90170 = (0 << 5) | cppVar_90169;
	cppVar_90170 = (cppVar_90170 & cppMask_un_8_);
	bool cppVar_90172 = (cppVar_90170 == 160);
	if (cppVar_90172) {
	cppVar_90167 = P2;
	} else {
	BIT_VEC cppVar_90173;
	BIT_VEC cppVar_90174 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_90175 = (cppVar_90174 << 3) | 7;
	cppVar_90175 = (cppVar_90175 & cppMask_un_5_);
	BIT_VEC cppVar_90176 = (0 << 5) | cppVar_90175;
	cppVar_90176 = (cppVar_90176 & cppMask_un_8_);
	bool cppVar_90178 = (cppVar_90176 == 168);
	if (cppVar_90178) {
	cppVar_90173 = IE;
	} else {
	BIT_VEC cppVar_90179;
	BIT_VEC cppVar_90180 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_90181 = (cppVar_90180 << 3) | 7;
	cppVar_90181 = (cppVar_90181 & cppMask_un_5_);
	BIT_VEC cppVar_90182 = (0 << 5) | cppVar_90181;
	cppVar_90182 = (cppVar_90182 & cppMask_un_8_);
	bool cppVar_90184 = (cppVar_90182 == 176);
	if (cppVar_90184) {
	cppVar_90179 = P3;
	} else {
	BIT_VEC cppVar_90185;
	BIT_VEC cppVar_90186 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_90187 = (cppVar_90186 << 3) | 7;
	cppVar_90187 = (cppVar_90187 & cppMask_un_5_);
	BIT_VEC cppVar_90188 = (0 << 5) | cppVar_90187;
	cppVar_90188 = (cppVar_90188 & cppMask_un_8_);
	bool cppVar_90190 = (cppVar_90188 == 184);
	if (cppVar_90190) {
	cppVar_90185 = IP;
	} else {
	BIT_VEC cppVar_90191;
	BIT_VEC cppVar_90192 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_90193 = (cppVar_90192 << 3) | 7;
	cppVar_90193 = (cppVar_90193 & cppMask_un_5_);
	BIT_VEC cppVar_90194 = (0 << 5) | cppVar_90193;
	cppVar_90194 = (cppVar_90194 & cppMask_un_8_);
	bool cppVar_90196 = (cppVar_90194 == 208);
	if (cppVar_90196) {
	cppVar_90191 = PSW;
	} else {
	BIT_VEC cppVar_90197;
	BIT_VEC cppVar_90198 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_90199 = (cppVar_90198 << 3) | 7;
	cppVar_90199 = (cppVar_90199 & cppMask_un_5_);
	BIT_VEC cppVar_90200 = (0 << 5) | cppVar_90199;
	cppVar_90200 = (cppVar_90200 & cppMask_un_8_);
	bool cppVar_90202 = (cppVar_90200 == 224);
	if (cppVar_90202) {
	cppVar_90197 = ACC;
	} else {
	BIT_VEC cppVar_90203;
	BIT_VEC cppVar_90204 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_90205 = (cppVar_90204 << 3) | 7;
	cppVar_90205 = (cppVar_90205 & cppMask_un_5_);
	BIT_VEC cppVar_90206 = (0 << 5) | cppVar_90205;
	cppVar_90206 = (cppVar_90206 & cppMask_un_8_);
	bool cppVar_90208 = (cppVar_90206 == 240);
	if (cppVar_90208) {
	cppVar_90203 = B;
	} else {
	cppVar_90203 = 0;
	}
	cppVar_90197 = cppVar_90203;
	}
	cppVar_90191 = cppVar_90197;
	}
	cppVar_90185 = cppVar_90191;
	}
	cppVar_90179 = cppVar_90185;
	}
	cppVar_90173 = cppVar_90179;
	}
	cppVar_90167 = cppVar_90173;
	}
	cppVar_90161 = cppVar_90167;
	}
	cppVar_90155 = cppVar_90161;
	}
	cppVar_90149 = cppVar_90155;
	}
	cppVar_90143 = cppVar_90149;
	}
	cppVar_90137 = cppVar_90143;
	}
	cppVar_90131 = cppVar_90137;
	}
	cppVar_90125 = cppVar_90131;
	}
	cppVar_90119 = cppVar_90125;
	}
	cppVar_90113 = cppVar_90119;
	}
	cppVar_90107 = cppVar_90113;
	}
	cppVar_90101 = cppVar_90107;
	}
	cppVar_90095 = cppVar_90101;
	}
	cppVar_90089 = cppVar_90095;
	}
	cppVar_90083 = cppVar_90089;
	}
	cppVar_90070 = cppVar_90083;
	}
	type_mem cppVar_90210 = IRAM;
	cppVar_90210.wr(cppVar_90069, cppVar_90070);
	cppVar_90061 = cppVar_90210;
	} else {
	cppVar_90061 = IRAM;
	}
	cppVar_90057 = cppVar_90061;
	} else {
	type_mem cppVar_90211;
	BIT_VEC cppVar_90212 = ROM.rd(PC);
	bool cppVar_90214 = (cppVar_90212 == 142);
	if (cppVar_90214) {
	type_mem cppVar_90215;
	BIT_VEC cppVar_90217 = PC + 1;
	cppVar_90217 = (cppVar_90217 & cppMask_un_16_);
	BIT_VEC cppVar_90218 = ROM.rd(cppVar_90217);
	BIT_VEC cppVar_90219 = (cppVar_90218 >> 7) & cppMask_un_1_;
	bool cppVar_90221 = (cppVar_90219 == 0);
	if (cppVar_90221) {
	BIT_VEC cppVar_90222 = PC + 1;
	cppVar_90222 = (cppVar_90222 & cppMask_un_16_);
	BIT_VEC cppVar_90223 = ROM.rd(cppVar_90222);
	BIT_VEC cppVar_90224;
	BIT_VEC cppVar_90226 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_90228 = (cppVar_90226 << 3) | 6;
	cppVar_90228 = (cppVar_90228 & cppMask_un_5_);
	BIT_VEC cppVar_90229 = (0 << 5) | cppVar_90228;
	cppVar_90229 = (cppVar_90229 & cppMask_un_8_);
	BIT_VEC cppVar_90230 = (cppVar_90229 >> 7) & cppMask_un_1_;
	bool cppVar_90232 = (cppVar_90230 == 0);
	if (cppVar_90232) {
	BIT_VEC cppVar_90233 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_90234 = (cppVar_90233 << 3) | 6;
	cppVar_90234 = (cppVar_90234 & cppMask_un_5_);
	BIT_VEC cppVar_90235 = (0 << 5) | cppVar_90234;
	cppVar_90235 = (cppVar_90235 & cppMask_un_8_);
	BIT_VEC cppVar_90236 = IRAM.rd(cppVar_90235);
	cppVar_90224 = cppVar_90236;
	} else {
	BIT_VEC cppVar_90237;
	BIT_VEC cppVar_90238 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_90239 = (cppVar_90238 << 3) | 6;
	cppVar_90239 = (cppVar_90239 & cppMask_un_5_);
	BIT_VEC cppVar_90240 = (0 << 5) | cppVar_90239;
	cppVar_90240 = (cppVar_90240 & cppMask_un_8_);
	bool cppVar_90242 = (cppVar_90240 == 128);
	if (cppVar_90242) {
	cppVar_90237 = P0;
	} else {
	BIT_VEC cppVar_90243;
	BIT_VEC cppVar_90244 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_90245 = (cppVar_90244 << 3) | 6;
	cppVar_90245 = (cppVar_90245 & cppMask_un_5_);
	BIT_VEC cppVar_90246 = (0 << 5) | cppVar_90245;
	cppVar_90246 = (cppVar_90246 & cppMask_un_8_);
	bool cppVar_90248 = (cppVar_90246 == 129);
	if (cppVar_90248) {
	cppVar_90243 = SP;
	} else {
	BIT_VEC cppVar_90249;
	BIT_VEC cppVar_90250 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_90251 = (cppVar_90250 << 3) | 6;
	cppVar_90251 = (cppVar_90251 & cppMask_un_5_);
	BIT_VEC cppVar_90252 = (0 << 5) | cppVar_90251;
	cppVar_90252 = (cppVar_90252 & cppMask_un_8_);
	bool cppVar_90254 = (cppVar_90252 == 130);
	if (cppVar_90254) {
	cppVar_90249 = DPL;
	} else {
	BIT_VEC cppVar_90255;
	BIT_VEC cppVar_90256 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_90257 = (cppVar_90256 << 3) | 6;
	cppVar_90257 = (cppVar_90257 & cppMask_un_5_);
	BIT_VEC cppVar_90258 = (0 << 5) | cppVar_90257;
	cppVar_90258 = (cppVar_90258 & cppMask_un_8_);
	bool cppVar_90260 = (cppVar_90258 == 131);
	if (cppVar_90260) {
	cppVar_90255 = DPH;
	} else {
	BIT_VEC cppVar_90261;
	BIT_VEC cppVar_90262 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_90263 = (cppVar_90262 << 3) | 6;
	cppVar_90263 = (cppVar_90263 & cppMask_un_5_);
	BIT_VEC cppVar_90264 = (0 << 5) | cppVar_90263;
	cppVar_90264 = (cppVar_90264 & cppMask_un_8_);
	bool cppVar_90266 = (cppVar_90264 == 135);
	if (cppVar_90266) {
	cppVar_90261 = PCON;
	} else {
	BIT_VEC cppVar_90267;
	BIT_VEC cppVar_90268 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_90269 = (cppVar_90268 << 3) | 6;
	cppVar_90269 = (cppVar_90269 & cppMask_un_5_);
	BIT_VEC cppVar_90270 = (0 << 5) | cppVar_90269;
	cppVar_90270 = (cppVar_90270 & cppMask_un_8_);
	bool cppVar_90272 = (cppVar_90270 == 136);
	if (cppVar_90272) {
	cppVar_90267 = TCON;
	} else {
	BIT_VEC cppVar_90273;
	BIT_VEC cppVar_90274 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_90275 = (cppVar_90274 << 3) | 6;
	cppVar_90275 = (cppVar_90275 & cppMask_un_5_);
	BIT_VEC cppVar_90276 = (0 << 5) | cppVar_90275;
	cppVar_90276 = (cppVar_90276 & cppMask_un_8_);
	bool cppVar_90278 = (cppVar_90276 == 137);
	if (cppVar_90278) {
	cppVar_90273 = TMOD;
	} else {
	BIT_VEC cppVar_90279;
	BIT_VEC cppVar_90280 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_90281 = (cppVar_90280 << 3) | 6;
	cppVar_90281 = (cppVar_90281 & cppMask_un_5_);
	BIT_VEC cppVar_90282 = (0 << 5) | cppVar_90281;
	cppVar_90282 = (cppVar_90282 & cppMask_un_8_);
	bool cppVar_90284 = (cppVar_90282 == 138);
	if (cppVar_90284) {
	cppVar_90279 = TL0;
	} else {
	BIT_VEC cppVar_90285;
	BIT_VEC cppVar_90286 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_90287 = (cppVar_90286 << 3) | 6;
	cppVar_90287 = (cppVar_90287 & cppMask_un_5_);
	BIT_VEC cppVar_90288 = (0 << 5) | cppVar_90287;
	cppVar_90288 = (cppVar_90288 & cppMask_un_8_);
	bool cppVar_90290 = (cppVar_90288 == 140);
	if (cppVar_90290) {
	cppVar_90285 = TH0;
	} else {
	BIT_VEC cppVar_90291;
	BIT_VEC cppVar_90292 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_90293 = (cppVar_90292 << 3) | 6;
	cppVar_90293 = (cppVar_90293 & cppMask_un_5_);
	BIT_VEC cppVar_90294 = (0 << 5) | cppVar_90293;
	cppVar_90294 = (cppVar_90294 & cppMask_un_8_);
	bool cppVar_90296 = (cppVar_90294 == 139);
	if (cppVar_90296) {
	cppVar_90291 = TL1;
	} else {
	BIT_VEC cppVar_90297;
	BIT_VEC cppVar_90298 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_90299 = (cppVar_90298 << 3) | 6;
	cppVar_90299 = (cppVar_90299 & cppMask_un_5_);
	BIT_VEC cppVar_90300 = (0 << 5) | cppVar_90299;
	cppVar_90300 = (cppVar_90300 & cppMask_un_8_);
	bool cppVar_90302 = (cppVar_90300 == 141);
	if (cppVar_90302) {
	cppVar_90297 = TH1;
	} else {
	BIT_VEC cppVar_90303;
	BIT_VEC cppVar_90304 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_90305 = (cppVar_90304 << 3) | 6;
	cppVar_90305 = (cppVar_90305 & cppMask_un_5_);
	BIT_VEC cppVar_90306 = (0 << 5) | cppVar_90305;
	cppVar_90306 = (cppVar_90306 & cppMask_un_8_);
	bool cppVar_90308 = (cppVar_90306 == 144);
	if (cppVar_90308) {
	cppVar_90303 = P1;
	} else {
	BIT_VEC cppVar_90309;
	BIT_VEC cppVar_90310 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_90311 = (cppVar_90310 << 3) | 6;
	cppVar_90311 = (cppVar_90311 & cppMask_un_5_);
	BIT_VEC cppVar_90312 = (0 << 5) | cppVar_90311;
	cppVar_90312 = (cppVar_90312 & cppMask_un_8_);
	bool cppVar_90314 = (cppVar_90312 == 152);
	if (cppVar_90314) {
	cppVar_90309 = SCON;
	} else {
	BIT_VEC cppVar_90315;
	BIT_VEC cppVar_90316 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_90317 = (cppVar_90316 << 3) | 6;
	cppVar_90317 = (cppVar_90317 & cppMask_un_5_);
	BIT_VEC cppVar_90318 = (0 << 5) | cppVar_90317;
	cppVar_90318 = (cppVar_90318 & cppMask_un_8_);
	bool cppVar_90320 = (cppVar_90318 == 153);
	if (cppVar_90320) {
	cppVar_90315 = SBUF;
	} else {
	BIT_VEC cppVar_90321;
	BIT_VEC cppVar_90322 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_90323 = (cppVar_90322 << 3) | 6;
	cppVar_90323 = (cppVar_90323 & cppMask_un_5_);
	BIT_VEC cppVar_90324 = (0 << 5) | cppVar_90323;
	cppVar_90324 = (cppVar_90324 & cppMask_un_8_);
	bool cppVar_90326 = (cppVar_90324 == 160);
	if (cppVar_90326) {
	cppVar_90321 = P2;
	} else {
	BIT_VEC cppVar_90327;
	BIT_VEC cppVar_90328 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_90329 = (cppVar_90328 << 3) | 6;
	cppVar_90329 = (cppVar_90329 & cppMask_un_5_);
	BIT_VEC cppVar_90330 = (0 << 5) | cppVar_90329;
	cppVar_90330 = (cppVar_90330 & cppMask_un_8_);
	bool cppVar_90332 = (cppVar_90330 == 168);
	if (cppVar_90332) {
	cppVar_90327 = IE;
	} else {
	BIT_VEC cppVar_90333;
	BIT_VEC cppVar_90334 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_90335 = (cppVar_90334 << 3) | 6;
	cppVar_90335 = (cppVar_90335 & cppMask_un_5_);
	BIT_VEC cppVar_90336 = (0 << 5) | cppVar_90335;
	cppVar_90336 = (cppVar_90336 & cppMask_un_8_);
	bool cppVar_90338 = (cppVar_90336 == 176);
	if (cppVar_90338) {
	cppVar_90333 = P3;
	} else {
	BIT_VEC cppVar_90339;
	BIT_VEC cppVar_90340 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_90341 = (cppVar_90340 << 3) | 6;
	cppVar_90341 = (cppVar_90341 & cppMask_un_5_);
	BIT_VEC cppVar_90342 = (0 << 5) | cppVar_90341;
	cppVar_90342 = (cppVar_90342 & cppMask_un_8_);
	bool cppVar_90344 = (cppVar_90342 == 184);
	if (cppVar_90344) {
	cppVar_90339 = IP;
	} else {
	BIT_VEC cppVar_90345;
	BIT_VEC cppVar_90346 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_90347 = (cppVar_90346 << 3) | 6;
	cppVar_90347 = (cppVar_90347 & cppMask_un_5_);
	BIT_VEC cppVar_90348 = (0 << 5) | cppVar_90347;
	cppVar_90348 = (cppVar_90348 & cppMask_un_8_);
	bool cppVar_90350 = (cppVar_90348 == 208);
	if (cppVar_90350) {
	cppVar_90345 = PSW;
	} else {
	BIT_VEC cppVar_90351;
	BIT_VEC cppVar_90352 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_90353 = (cppVar_90352 << 3) | 6;
	cppVar_90353 = (cppVar_90353 & cppMask_un_5_);
	BIT_VEC cppVar_90354 = (0 << 5) | cppVar_90353;
	cppVar_90354 = (cppVar_90354 & cppMask_un_8_);
	bool cppVar_90356 = (cppVar_90354 == 224);
	if (cppVar_90356) {
	cppVar_90351 = ACC;
	} else {
	BIT_VEC cppVar_90357;
	BIT_VEC cppVar_90358 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_90359 = (cppVar_90358 << 3) | 6;
	cppVar_90359 = (cppVar_90359 & cppMask_un_5_);
	BIT_VEC cppVar_90360 = (0 << 5) | cppVar_90359;
	cppVar_90360 = (cppVar_90360 & cppMask_un_8_);
	bool cppVar_90362 = (cppVar_90360 == 240);
	if (cppVar_90362) {
	cppVar_90357 = B;
	} else {
	cppVar_90357 = 0;
	}
	cppVar_90351 = cppVar_90357;
	}
	cppVar_90345 = cppVar_90351;
	}
	cppVar_90339 = cppVar_90345;
	}
	cppVar_90333 = cppVar_90339;
	}
	cppVar_90327 = cppVar_90333;
	}
	cppVar_90321 = cppVar_90327;
	}
	cppVar_90315 = cppVar_90321;
	}
	cppVar_90309 = cppVar_90315;
	}
	cppVar_90303 = cppVar_90309;
	}
	cppVar_90297 = cppVar_90303;
	}
	cppVar_90291 = cppVar_90297;
	}
	cppVar_90285 = cppVar_90291;
	}
	cppVar_90279 = cppVar_90285;
	}
	cppVar_90273 = cppVar_90279;
	}
	cppVar_90267 = cppVar_90273;
	}
	cppVar_90261 = cppVar_90267;
	}
	cppVar_90255 = cppVar_90261;
	}
	cppVar_90249 = cppVar_90255;
	}
	cppVar_90243 = cppVar_90249;
	}
	cppVar_90237 = cppVar_90243;
	}
	cppVar_90224 = cppVar_90237;
	}
	type_mem cppVar_90364 = IRAM;
	cppVar_90364.wr(cppVar_90223, cppVar_90224);
	cppVar_90215 = cppVar_90364;
	} else {
	cppVar_90215 = IRAM;
	}
	cppVar_90211 = cppVar_90215;
	} else {
	type_mem cppVar_90365;
	BIT_VEC cppVar_90366 = ROM.rd(PC);
	bool cppVar_90368 = (cppVar_90366 == 141);
	if (cppVar_90368) {
	type_mem cppVar_90369;
	BIT_VEC cppVar_90371 = PC + 1;
	cppVar_90371 = (cppVar_90371 & cppMask_un_16_);
	BIT_VEC cppVar_90372 = ROM.rd(cppVar_90371);
	BIT_VEC cppVar_90373 = (cppVar_90372 >> 7) & cppMask_un_1_;
	bool cppVar_90375 = (cppVar_90373 == 0);
	if (cppVar_90375) {
	BIT_VEC cppVar_90376 = PC + 1;
	cppVar_90376 = (cppVar_90376 & cppMask_un_16_);
	BIT_VEC cppVar_90377 = ROM.rd(cppVar_90376);
	BIT_VEC cppVar_90378;
	BIT_VEC cppVar_90380 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_90382 = (cppVar_90380 << 3) | 5;
	cppVar_90382 = (cppVar_90382 & cppMask_un_5_);
	BIT_VEC cppVar_90383 = (0 << 5) | cppVar_90382;
	cppVar_90383 = (cppVar_90383 & cppMask_un_8_);
	BIT_VEC cppVar_90384 = (cppVar_90383 >> 7) & cppMask_un_1_;
	bool cppVar_90386 = (cppVar_90384 == 0);
	if (cppVar_90386) {
	BIT_VEC cppVar_90387 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_90388 = (cppVar_90387 << 3) | 5;
	cppVar_90388 = (cppVar_90388 & cppMask_un_5_);
	BIT_VEC cppVar_90389 = (0 << 5) | cppVar_90388;
	cppVar_90389 = (cppVar_90389 & cppMask_un_8_);
	BIT_VEC cppVar_90390 = IRAM.rd(cppVar_90389);
	cppVar_90378 = cppVar_90390;
	} else {
	BIT_VEC cppVar_90391;
	BIT_VEC cppVar_90392 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_90393 = (cppVar_90392 << 3) | 5;
	cppVar_90393 = (cppVar_90393 & cppMask_un_5_);
	BIT_VEC cppVar_90394 = (0 << 5) | cppVar_90393;
	cppVar_90394 = (cppVar_90394 & cppMask_un_8_);
	bool cppVar_90396 = (cppVar_90394 == 128);
	if (cppVar_90396) {
	cppVar_90391 = P0;
	} else {
	BIT_VEC cppVar_90397;
	BIT_VEC cppVar_90398 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_90399 = (cppVar_90398 << 3) | 5;
	cppVar_90399 = (cppVar_90399 & cppMask_un_5_);
	BIT_VEC cppVar_90400 = (0 << 5) | cppVar_90399;
	cppVar_90400 = (cppVar_90400 & cppMask_un_8_);
	bool cppVar_90402 = (cppVar_90400 == 129);
	if (cppVar_90402) {
	cppVar_90397 = SP;
	} else {
	BIT_VEC cppVar_90403;
	BIT_VEC cppVar_90404 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_90405 = (cppVar_90404 << 3) | 5;
	cppVar_90405 = (cppVar_90405 & cppMask_un_5_);
	BIT_VEC cppVar_90406 = (0 << 5) | cppVar_90405;
	cppVar_90406 = (cppVar_90406 & cppMask_un_8_);
	bool cppVar_90408 = (cppVar_90406 == 130);
	if (cppVar_90408) {
	cppVar_90403 = DPL;
	} else {
	BIT_VEC cppVar_90409;
	BIT_VEC cppVar_90410 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_90411 = (cppVar_90410 << 3) | 5;
	cppVar_90411 = (cppVar_90411 & cppMask_un_5_);
	BIT_VEC cppVar_90412 = (0 << 5) | cppVar_90411;
	cppVar_90412 = (cppVar_90412 & cppMask_un_8_);
	bool cppVar_90414 = (cppVar_90412 == 131);
	if (cppVar_90414) {
	cppVar_90409 = DPH;
	} else {
	BIT_VEC cppVar_90415;
	BIT_VEC cppVar_90416 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_90417 = (cppVar_90416 << 3) | 5;
	cppVar_90417 = (cppVar_90417 & cppMask_un_5_);
	BIT_VEC cppVar_90418 = (0 << 5) | cppVar_90417;
	cppVar_90418 = (cppVar_90418 & cppMask_un_8_);
	bool cppVar_90420 = (cppVar_90418 == 135);
	if (cppVar_90420) {
	cppVar_90415 = PCON;
	} else {
	BIT_VEC cppVar_90421;
	BIT_VEC cppVar_90422 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_90423 = (cppVar_90422 << 3) | 5;
	cppVar_90423 = (cppVar_90423 & cppMask_un_5_);
	BIT_VEC cppVar_90424 = (0 << 5) | cppVar_90423;
	cppVar_90424 = (cppVar_90424 & cppMask_un_8_);
	bool cppVar_90426 = (cppVar_90424 == 136);
	if (cppVar_90426) {
	cppVar_90421 = TCON;
	} else {
	BIT_VEC cppVar_90427;
	BIT_VEC cppVar_90428 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_90429 = (cppVar_90428 << 3) | 5;
	cppVar_90429 = (cppVar_90429 & cppMask_un_5_);
	BIT_VEC cppVar_90430 = (0 << 5) | cppVar_90429;
	cppVar_90430 = (cppVar_90430 & cppMask_un_8_);
	bool cppVar_90432 = (cppVar_90430 == 137);
	if (cppVar_90432) {
	cppVar_90427 = TMOD;
	} else {
	BIT_VEC cppVar_90433;
	BIT_VEC cppVar_90434 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_90435 = (cppVar_90434 << 3) | 5;
	cppVar_90435 = (cppVar_90435 & cppMask_un_5_);
	BIT_VEC cppVar_90436 = (0 << 5) | cppVar_90435;
	cppVar_90436 = (cppVar_90436 & cppMask_un_8_);
	bool cppVar_90438 = (cppVar_90436 == 138);
	if (cppVar_90438) {
	cppVar_90433 = TL0;
	} else {
	BIT_VEC cppVar_90439;
	BIT_VEC cppVar_90440 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_90441 = (cppVar_90440 << 3) | 5;
	cppVar_90441 = (cppVar_90441 & cppMask_un_5_);
	BIT_VEC cppVar_90442 = (0 << 5) | cppVar_90441;
	cppVar_90442 = (cppVar_90442 & cppMask_un_8_);
	bool cppVar_90444 = (cppVar_90442 == 140);
	if (cppVar_90444) {
	cppVar_90439 = TH0;
	} else {
	BIT_VEC cppVar_90445;
	BIT_VEC cppVar_90446 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_90447 = (cppVar_90446 << 3) | 5;
	cppVar_90447 = (cppVar_90447 & cppMask_un_5_);
	BIT_VEC cppVar_90448 = (0 << 5) | cppVar_90447;
	cppVar_90448 = (cppVar_90448 & cppMask_un_8_);
	bool cppVar_90450 = (cppVar_90448 == 139);
	if (cppVar_90450) {
	cppVar_90445 = TL1;
	} else {
	BIT_VEC cppVar_90451;
	BIT_VEC cppVar_90452 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_90453 = (cppVar_90452 << 3) | 5;
	cppVar_90453 = (cppVar_90453 & cppMask_un_5_);
	BIT_VEC cppVar_90454 = (0 << 5) | cppVar_90453;
	cppVar_90454 = (cppVar_90454 & cppMask_un_8_);
	bool cppVar_90456 = (cppVar_90454 == 141);
	if (cppVar_90456) {
	cppVar_90451 = TH1;
	} else {
	BIT_VEC cppVar_90457;
	BIT_VEC cppVar_90458 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_90459 = (cppVar_90458 << 3) | 5;
	cppVar_90459 = (cppVar_90459 & cppMask_un_5_);
	BIT_VEC cppVar_90460 = (0 << 5) | cppVar_90459;
	cppVar_90460 = (cppVar_90460 & cppMask_un_8_);
	bool cppVar_90462 = (cppVar_90460 == 144);
	if (cppVar_90462) {
	cppVar_90457 = P1;
	} else {
	BIT_VEC cppVar_90463;
	BIT_VEC cppVar_90464 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_90465 = (cppVar_90464 << 3) | 5;
	cppVar_90465 = (cppVar_90465 & cppMask_un_5_);
	BIT_VEC cppVar_90466 = (0 << 5) | cppVar_90465;
	cppVar_90466 = (cppVar_90466 & cppMask_un_8_);
	bool cppVar_90468 = (cppVar_90466 == 152);
	if (cppVar_90468) {
	cppVar_90463 = SCON;
	} else {
	BIT_VEC cppVar_90469;
	BIT_VEC cppVar_90470 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_90471 = (cppVar_90470 << 3) | 5;
	cppVar_90471 = (cppVar_90471 & cppMask_un_5_);
	BIT_VEC cppVar_90472 = (0 << 5) | cppVar_90471;
	cppVar_90472 = (cppVar_90472 & cppMask_un_8_);
	bool cppVar_90474 = (cppVar_90472 == 153);
	if (cppVar_90474) {
	cppVar_90469 = SBUF;
	} else {
	BIT_VEC cppVar_90475;
	BIT_VEC cppVar_90476 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_90477 = (cppVar_90476 << 3) | 5;
	cppVar_90477 = (cppVar_90477 & cppMask_un_5_);
	BIT_VEC cppVar_90478 = (0 << 5) | cppVar_90477;
	cppVar_90478 = (cppVar_90478 & cppMask_un_8_);
	bool cppVar_90480 = (cppVar_90478 == 160);
	if (cppVar_90480) {
	cppVar_90475 = P2;
	} else {
	BIT_VEC cppVar_90481;
	BIT_VEC cppVar_90482 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_90483 = (cppVar_90482 << 3) | 5;
	cppVar_90483 = (cppVar_90483 & cppMask_un_5_);
	BIT_VEC cppVar_90484 = (0 << 5) | cppVar_90483;
	cppVar_90484 = (cppVar_90484 & cppMask_un_8_);
	bool cppVar_90486 = (cppVar_90484 == 168);
	if (cppVar_90486) {
	cppVar_90481 = IE;
	} else {
	BIT_VEC cppVar_90487;
	BIT_VEC cppVar_90488 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_90489 = (cppVar_90488 << 3) | 5;
	cppVar_90489 = (cppVar_90489 & cppMask_un_5_);
	BIT_VEC cppVar_90490 = (0 << 5) | cppVar_90489;
	cppVar_90490 = (cppVar_90490 & cppMask_un_8_);
	bool cppVar_90492 = (cppVar_90490 == 176);
	if (cppVar_90492) {
	cppVar_90487 = P3;
	} else {
	BIT_VEC cppVar_90493;
	BIT_VEC cppVar_90494 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_90495 = (cppVar_90494 << 3) | 5;
	cppVar_90495 = (cppVar_90495 & cppMask_un_5_);
	BIT_VEC cppVar_90496 = (0 << 5) | cppVar_90495;
	cppVar_90496 = (cppVar_90496 & cppMask_un_8_);
	bool cppVar_90498 = (cppVar_90496 == 184);
	if (cppVar_90498) {
	cppVar_90493 = IP;
	} else {
	BIT_VEC cppVar_90499;
	BIT_VEC cppVar_90500 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_90501 = (cppVar_90500 << 3) | 5;
	cppVar_90501 = (cppVar_90501 & cppMask_un_5_);
	BIT_VEC cppVar_90502 = (0 << 5) | cppVar_90501;
	cppVar_90502 = (cppVar_90502 & cppMask_un_8_);
	bool cppVar_90504 = (cppVar_90502 == 208);
	if (cppVar_90504) {
	cppVar_90499 = PSW;
	} else {
	BIT_VEC cppVar_90505;
	BIT_VEC cppVar_90506 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_90507 = (cppVar_90506 << 3) | 5;
	cppVar_90507 = (cppVar_90507 & cppMask_un_5_);
	BIT_VEC cppVar_90508 = (0 << 5) | cppVar_90507;
	cppVar_90508 = (cppVar_90508 & cppMask_un_8_);
	bool cppVar_90510 = (cppVar_90508 == 224);
	if (cppVar_90510) {
	cppVar_90505 = ACC;
	} else {
	BIT_VEC cppVar_90511;
	BIT_VEC cppVar_90512 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_90513 = (cppVar_90512 << 3) | 5;
	cppVar_90513 = (cppVar_90513 & cppMask_un_5_);
	BIT_VEC cppVar_90514 = (0 << 5) | cppVar_90513;
	cppVar_90514 = (cppVar_90514 & cppMask_un_8_);
	bool cppVar_90516 = (cppVar_90514 == 240);
	if (cppVar_90516) {
	cppVar_90511 = B;
	} else {
	cppVar_90511 = 0;
	}
	cppVar_90505 = cppVar_90511;
	}
	cppVar_90499 = cppVar_90505;
	}
	cppVar_90493 = cppVar_90499;
	}
	cppVar_90487 = cppVar_90493;
	}
	cppVar_90481 = cppVar_90487;
	}
	cppVar_90475 = cppVar_90481;
	}
	cppVar_90469 = cppVar_90475;
	}
	cppVar_90463 = cppVar_90469;
	}
	cppVar_90457 = cppVar_90463;
	}
	cppVar_90451 = cppVar_90457;
	}
	cppVar_90445 = cppVar_90451;
	}
	cppVar_90439 = cppVar_90445;
	}
	cppVar_90433 = cppVar_90439;
	}
	cppVar_90427 = cppVar_90433;
	}
	cppVar_90421 = cppVar_90427;
	}
	cppVar_90415 = cppVar_90421;
	}
	cppVar_90409 = cppVar_90415;
	}
	cppVar_90403 = cppVar_90409;
	}
	cppVar_90397 = cppVar_90403;
	}
	cppVar_90391 = cppVar_90397;
	}
	cppVar_90378 = cppVar_90391;
	}
	type_mem cppVar_90518 = IRAM;
	cppVar_90518.wr(cppVar_90377, cppVar_90378);
	cppVar_90369 = cppVar_90518;
	} else {
	cppVar_90369 = IRAM;
	}
	cppVar_90365 = cppVar_90369;
	} else {
	type_mem cppVar_90519;
	BIT_VEC cppVar_90520 = ROM.rd(PC);
	bool cppVar_90522 = (cppVar_90520 == 140);
	if (cppVar_90522) {
	type_mem cppVar_90523;
	BIT_VEC cppVar_90525 = PC + 1;
	cppVar_90525 = (cppVar_90525 & cppMask_un_16_);
	BIT_VEC cppVar_90526 = ROM.rd(cppVar_90525);
	BIT_VEC cppVar_90527 = (cppVar_90526 >> 7) & cppMask_un_1_;
	bool cppVar_90529 = (cppVar_90527 == 0);
	if (cppVar_90529) {
	BIT_VEC cppVar_90530 = PC + 1;
	cppVar_90530 = (cppVar_90530 & cppMask_un_16_);
	BIT_VEC cppVar_90531 = ROM.rd(cppVar_90530);
	BIT_VEC cppVar_90532;
	BIT_VEC cppVar_90534 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_90536 = (cppVar_90534 << 3) | 4;
	cppVar_90536 = (cppVar_90536 & cppMask_un_5_);
	BIT_VEC cppVar_90537 = (0 << 5) | cppVar_90536;
	cppVar_90537 = (cppVar_90537 & cppMask_un_8_);
	BIT_VEC cppVar_90538 = (cppVar_90537 >> 7) & cppMask_un_1_;
	bool cppVar_90540 = (cppVar_90538 == 0);
	if (cppVar_90540) {
	BIT_VEC cppVar_90541 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_90542 = (cppVar_90541 << 3) | 4;
	cppVar_90542 = (cppVar_90542 & cppMask_un_5_);
	BIT_VEC cppVar_90543 = (0 << 5) | cppVar_90542;
	cppVar_90543 = (cppVar_90543 & cppMask_un_8_);
	BIT_VEC cppVar_90544 = IRAM.rd(cppVar_90543);
	cppVar_90532 = cppVar_90544;
	} else {
	BIT_VEC cppVar_90545;
	BIT_VEC cppVar_90546 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_90547 = (cppVar_90546 << 3) | 4;
	cppVar_90547 = (cppVar_90547 & cppMask_un_5_);
	BIT_VEC cppVar_90548 = (0 << 5) | cppVar_90547;
	cppVar_90548 = (cppVar_90548 & cppMask_un_8_);
	bool cppVar_90550 = (cppVar_90548 == 128);
	if (cppVar_90550) {
	cppVar_90545 = P0;
	} else {
	BIT_VEC cppVar_90551;
	BIT_VEC cppVar_90552 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_90553 = (cppVar_90552 << 3) | 4;
	cppVar_90553 = (cppVar_90553 & cppMask_un_5_);
	BIT_VEC cppVar_90554 = (0 << 5) | cppVar_90553;
	cppVar_90554 = (cppVar_90554 & cppMask_un_8_);
	bool cppVar_90556 = (cppVar_90554 == 129);
	if (cppVar_90556) {
	cppVar_90551 = SP;
	} else {
	BIT_VEC cppVar_90557;
	BIT_VEC cppVar_90558 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_90559 = (cppVar_90558 << 3) | 4;
	cppVar_90559 = (cppVar_90559 & cppMask_un_5_);
	BIT_VEC cppVar_90560 = (0 << 5) | cppVar_90559;
	cppVar_90560 = (cppVar_90560 & cppMask_un_8_);
	bool cppVar_90562 = (cppVar_90560 == 130);
	if (cppVar_90562) {
	cppVar_90557 = DPL;
	} else {
	BIT_VEC cppVar_90563;
	BIT_VEC cppVar_90564 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_90565 = (cppVar_90564 << 3) | 4;
	cppVar_90565 = (cppVar_90565 & cppMask_un_5_);
	BIT_VEC cppVar_90566 = (0 << 5) | cppVar_90565;
	cppVar_90566 = (cppVar_90566 & cppMask_un_8_);
	bool cppVar_90568 = (cppVar_90566 == 131);
	if (cppVar_90568) {
	cppVar_90563 = DPH;
	} else {
	BIT_VEC cppVar_90569;
	BIT_VEC cppVar_90570 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_90571 = (cppVar_90570 << 3) | 4;
	cppVar_90571 = (cppVar_90571 & cppMask_un_5_);
	BIT_VEC cppVar_90572 = (0 << 5) | cppVar_90571;
	cppVar_90572 = (cppVar_90572 & cppMask_un_8_);
	bool cppVar_90574 = (cppVar_90572 == 135);
	if (cppVar_90574) {
	cppVar_90569 = PCON;
	} else {
	BIT_VEC cppVar_90575;
	BIT_VEC cppVar_90576 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_90577 = (cppVar_90576 << 3) | 4;
	cppVar_90577 = (cppVar_90577 & cppMask_un_5_);
	BIT_VEC cppVar_90578 = (0 << 5) | cppVar_90577;
	cppVar_90578 = (cppVar_90578 & cppMask_un_8_);
	bool cppVar_90580 = (cppVar_90578 == 136);
	if (cppVar_90580) {
	cppVar_90575 = TCON;
	} else {
	BIT_VEC cppVar_90581;
	BIT_VEC cppVar_90582 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_90583 = (cppVar_90582 << 3) | 4;
	cppVar_90583 = (cppVar_90583 & cppMask_un_5_);
	BIT_VEC cppVar_90584 = (0 << 5) | cppVar_90583;
	cppVar_90584 = (cppVar_90584 & cppMask_un_8_);
	bool cppVar_90586 = (cppVar_90584 == 137);
	if (cppVar_90586) {
	cppVar_90581 = TMOD;
	} else {
	BIT_VEC cppVar_90587;
	BIT_VEC cppVar_90588 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_90589 = (cppVar_90588 << 3) | 4;
	cppVar_90589 = (cppVar_90589 & cppMask_un_5_);
	BIT_VEC cppVar_90590 = (0 << 5) | cppVar_90589;
	cppVar_90590 = (cppVar_90590 & cppMask_un_8_);
	bool cppVar_90592 = (cppVar_90590 == 138);
	if (cppVar_90592) {
	cppVar_90587 = TL0;
	} else {
	BIT_VEC cppVar_90593;
	BIT_VEC cppVar_90594 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_90595 = (cppVar_90594 << 3) | 4;
	cppVar_90595 = (cppVar_90595 & cppMask_un_5_);
	BIT_VEC cppVar_90596 = (0 << 5) | cppVar_90595;
	cppVar_90596 = (cppVar_90596 & cppMask_un_8_);
	bool cppVar_90598 = (cppVar_90596 == 140);
	if (cppVar_90598) {
	cppVar_90593 = TH0;
	} else {
	BIT_VEC cppVar_90599;
	BIT_VEC cppVar_90600 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_90601 = (cppVar_90600 << 3) | 4;
	cppVar_90601 = (cppVar_90601 & cppMask_un_5_);
	BIT_VEC cppVar_90602 = (0 << 5) | cppVar_90601;
	cppVar_90602 = (cppVar_90602 & cppMask_un_8_);
	bool cppVar_90604 = (cppVar_90602 == 139);
	if (cppVar_90604) {
	cppVar_90599 = TL1;
	} else {
	BIT_VEC cppVar_90605;
	BIT_VEC cppVar_90606 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_90607 = (cppVar_90606 << 3) | 4;
	cppVar_90607 = (cppVar_90607 & cppMask_un_5_);
	BIT_VEC cppVar_90608 = (0 << 5) | cppVar_90607;
	cppVar_90608 = (cppVar_90608 & cppMask_un_8_);
	bool cppVar_90610 = (cppVar_90608 == 141);
	if (cppVar_90610) {
	cppVar_90605 = TH1;
	} else {
	BIT_VEC cppVar_90611;
	BIT_VEC cppVar_90612 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_90613 = (cppVar_90612 << 3) | 4;
	cppVar_90613 = (cppVar_90613 & cppMask_un_5_);
	BIT_VEC cppVar_90614 = (0 << 5) | cppVar_90613;
	cppVar_90614 = (cppVar_90614 & cppMask_un_8_);
	bool cppVar_90616 = (cppVar_90614 == 144);
	if (cppVar_90616) {
	cppVar_90611 = P1;
	} else {
	BIT_VEC cppVar_90617;
	BIT_VEC cppVar_90618 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_90619 = (cppVar_90618 << 3) | 4;
	cppVar_90619 = (cppVar_90619 & cppMask_un_5_);
	BIT_VEC cppVar_90620 = (0 << 5) | cppVar_90619;
	cppVar_90620 = (cppVar_90620 & cppMask_un_8_);
	bool cppVar_90622 = (cppVar_90620 == 152);
	if (cppVar_90622) {
	cppVar_90617 = SCON;
	} else {
	BIT_VEC cppVar_90623;
	BIT_VEC cppVar_90624 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_90625 = (cppVar_90624 << 3) | 4;
	cppVar_90625 = (cppVar_90625 & cppMask_un_5_);
	BIT_VEC cppVar_90626 = (0 << 5) | cppVar_90625;
	cppVar_90626 = (cppVar_90626 & cppMask_un_8_);
	bool cppVar_90628 = (cppVar_90626 == 153);
	if (cppVar_90628) {
	cppVar_90623 = SBUF;
	} else {
	BIT_VEC cppVar_90629;
	BIT_VEC cppVar_90630 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_90631 = (cppVar_90630 << 3) | 4;
	cppVar_90631 = (cppVar_90631 & cppMask_un_5_);
	BIT_VEC cppVar_90632 = (0 << 5) | cppVar_90631;
	cppVar_90632 = (cppVar_90632 & cppMask_un_8_);
	bool cppVar_90634 = (cppVar_90632 == 160);
	if (cppVar_90634) {
	cppVar_90629 = P2;
	} else {
	BIT_VEC cppVar_90635;
	BIT_VEC cppVar_90636 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_90637 = (cppVar_90636 << 3) | 4;
	cppVar_90637 = (cppVar_90637 & cppMask_un_5_);
	BIT_VEC cppVar_90638 = (0 << 5) | cppVar_90637;
	cppVar_90638 = (cppVar_90638 & cppMask_un_8_);
	bool cppVar_90640 = (cppVar_90638 == 168);
	if (cppVar_90640) {
	cppVar_90635 = IE;
	} else {
	BIT_VEC cppVar_90641;
	BIT_VEC cppVar_90642 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_90643 = (cppVar_90642 << 3) | 4;
	cppVar_90643 = (cppVar_90643 & cppMask_un_5_);
	BIT_VEC cppVar_90644 = (0 << 5) | cppVar_90643;
	cppVar_90644 = (cppVar_90644 & cppMask_un_8_);
	bool cppVar_90646 = (cppVar_90644 == 176);
	if (cppVar_90646) {
	cppVar_90641 = P3;
	} else {
	BIT_VEC cppVar_90647;
	BIT_VEC cppVar_90648 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_90649 = (cppVar_90648 << 3) | 4;
	cppVar_90649 = (cppVar_90649 & cppMask_un_5_);
	BIT_VEC cppVar_90650 = (0 << 5) | cppVar_90649;
	cppVar_90650 = (cppVar_90650 & cppMask_un_8_);
	bool cppVar_90652 = (cppVar_90650 == 184);
	if (cppVar_90652) {
	cppVar_90647 = IP;
	} else {
	BIT_VEC cppVar_90653;
	BIT_VEC cppVar_90654 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_90655 = (cppVar_90654 << 3) | 4;
	cppVar_90655 = (cppVar_90655 & cppMask_un_5_);
	BIT_VEC cppVar_90656 = (0 << 5) | cppVar_90655;
	cppVar_90656 = (cppVar_90656 & cppMask_un_8_);
	bool cppVar_90658 = (cppVar_90656 == 208);
	if (cppVar_90658) {
	cppVar_90653 = PSW;
	} else {
	BIT_VEC cppVar_90659;
	BIT_VEC cppVar_90660 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_90661 = (cppVar_90660 << 3) | 4;
	cppVar_90661 = (cppVar_90661 & cppMask_un_5_);
	BIT_VEC cppVar_90662 = (0 << 5) | cppVar_90661;
	cppVar_90662 = (cppVar_90662 & cppMask_un_8_);
	bool cppVar_90664 = (cppVar_90662 == 224);
	if (cppVar_90664) {
	cppVar_90659 = ACC;
	} else {
	BIT_VEC cppVar_90665;
	BIT_VEC cppVar_90666 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_90667 = (cppVar_90666 << 3) | 4;
	cppVar_90667 = (cppVar_90667 & cppMask_un_5_);
	BIT_VEC cppVar_90668 = (0 << 5) | cppVar_90667;
	cppVar_90668 = (cppVar_90668 & cppMask_un_8_);
	bool cppVar_90670 = (cppVar_90668 == 240);
	if (cppVar_90670) {
	cppVar_90665 = B;
	} else {
	cppVar_90665 = 0;
	}
	cppVar_90659 = cppVar_90665;
	}
	cppVar_90653 = cppVar_90659;
	}
	cppVar_90647 = cppVar_90653;
	}
	cppVar_90641 = cppVar_90647;
	}
	cppVar_90635 = cppVar_90641;
	}
	cppVar_90629 = cppVar_90635;
	}
	cppVar_90623 = cppVar_90629;
	}
	cppVar_90617 = cppVar_90623;
	}
	cppVar_90611 = cppVar_90617;
	}
	cppVar_90605 = cppVar_90611;
	}
	cppVar_90599 = cppVar_90605;
	}
	cppVar_90593 = cppVar_90599;
	}
	cppVar_90587 = cppVar_90593;
	}
	cppVar_90581 = cppVar_90587;
	}
	cppVar_90575 = cppVar_90581;
	}
	cppVar_90569 = cppVar_90575;
	}
	cppVar_90563 = cppVar_90569;
	}
	cppVar_90557 = cppVar_90563;
	}
	cppVar_90551 = cppVar_90557;
	}
	cppVar_90545 = cppVar_90551;
	}
	cppVar_90532 = cppVar_90545;
	}
	type_mem cppVar_90672 = IRAM;
	cppVar_90672.wr(cppVar_90531, cppVar_90532);
	cppVar_90523 = cppVar_90672;
	} else {
	cppVar_90523 = IRAM;
	}
	cppVar_90519 = cppVar_90523;
	} else {
	type_mem cppVar_90673;
	BIT_VEC cppVar_90674 = ROM.rd(PC);
	bool cppVar_90676 = (cppVar_90674 == 139);
	if (cppVar_90676) {
	type_mem cppVar_90677;
	BIT_VEC cppVar_90679 = PC + 1;
	cppVar_90679 = (cppVar_90679 & cppMask_un_16_);
	BIT_VEC cppVar_90680 = ROM.rd(cppVar_90679);
	BIT_VEC cppVar_90681 = (cppVar_90680 >> 7) & cppMask_un_1_;
	bool cppVar_90683 = (cppVar_90681 == 0);
	if (cppVar_90683) {
	BIT_VEC cppVar_90684 = PC + 1;
	cppVar_90684 = (cppVar_90684 & cppMask_un_16_);
	BIT_VEC cppVar_90685 = ROM.rd(cppVar_90684);
	BIT_VEC cppVar_90686;
	BIT_VEC cppVar_90688 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_90690 = (cppVar_90688 << 3) | 3;
	cppVar_90690 = (cppVar_90690 & cppMask_un_5_);
	BIT_VEC cppVar_90691 = (0 << 5) | cppVar_90690;
	cppVar_90691 = (cppVar_90691 & cppMask_un_8_);
	BIT_VEC cppVar_90692 = (cppVar_90691 >> 7) & cppMask_un_1_;
	bool cppVar_90694 = (cppVar_90692 == 0);
	if (cppVar_90694) {
	BIT_VEC cppVar_90695 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_90696 = (cppVar_90695 << 3) | 3;
	cppVar_90696 = (cppVar_90696 & cppMask_un_5_);
	BIT_VEC cppVar_90697 = (0 << 5) | cppVar_90696;
	cppVar_90697 = (cppVar_90697 & cppMask_un_8_);
	BIT_VEC cppVar_90698 = IRAM.rd(cppVar_90697);
	cppVar_90686 = cppVar_90698;
	} else {
	BIT_VEC cppVar_90699;
	BIT_VEC cppVar_90700 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_90701 = (cppVar_90700 << 3) | 3;
	cppVar_90701 = (cppVar_90701 & cppMask_un_5_);
	BIT_VEC cppVar_90702 = (0 << 5) | cppVar_90701;
	cppVar_90702 = (cppVar_90702 & cppMask_un_8_);
	bool cppVar_90704 = (cppVar_90702 == 128);
	if (cppVar_90704) {
	cppVar_90699 = P0;
	} else {
	BIT_VEC cppVar_90705;
	BIT_VEC cppVar_90706 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_90707 = (cppVar_90706 << 3) | 3;
	cppVar_90707 = (cppVar_90707 & cppMask_un_5_);
	BIT_VEC cppVar_90708 = (0 << 5) | cppVar_90707;
	cppVar_90708 = (cppVar_90708 & cppMask_un_8_);
	bool cppVar_90710 = (cppVar_90708 == 129);
	if (cppVar_90710) {
	cppVar_90705 = SP;
	} else {
	BIT_VEC cppVar_90711;
	BIT_VEC cppVar_90712 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_90713 = (cppVar_90712 << 3) | 3;
	cppVar_90713 = (cppVar_90713 & cppMask_un_5_);
	BIT_VEC cppVar_90714 = (0 << 5) | cppVar_90713;
	cppVar_90714 = (cppVar_90714 & cppMask_un_8_);
	bool cppVar_90716 = (cppVar_90714 == 130);
	if (cppVar_90716) {
	cppVar_90711 = DPL;
	} else {
	BIT_VEC cppVar_90717;
	BIT_VEC cppVar_90718 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_90719 = (cppVar_90718 << 3) | 3;
	cppVar_90719 = (cppVar_90719 & cppMask_un_5_);
	BIT_VEC cppVar_90720 = (0 << 5) | cppVar_90719;
	cppVar_90720 = (cppVar_90720 & cppMask_un_8_);
	bool cppVar_90722 = (cppVar_90720 == 131);
	if (cppVar_90722) {
	cppVar_90717 = DPH;
	} else {
	BIT_VEC cppVar_90723;
	BIT_VEC cppVar_90724 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_90725 = (cppVar_90724 << 3) | 3;
	cppVar_90725 = (cppVar_90725 & cppMask_un_5_);
	BIT_VEC cppVar_90726 = (0 << 5) | cppVar_90725;
	cppVar_90726 = (cppVar_90726 & cppMask_un_8_);
	bool cppVar_90728 = (cppVar_90726 == 135);
	if (cppVar_90728) {
	cppVar_90723 = PCON;
	} else {
	BIT_VEC cppVar_90729;
	BIT_VEC cppVar_90730 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_90731 = (cppVar_90730 << 3) | 3;
	cppVar_90731 = (cppVar_90731 & cppMask_un_5_);
	BIT_VEC cppVar_90732 = (0 << 5) | cppVar_90731;
	cppVar_90732 = (cppVar_90732 & cppMask_un_8_);
	bool cppVar_90734 = (cppVar_90732 == 136);
	if (cppVar_90734) {
	cppVar_90729 = TCON;
	} else {
	BIT_VEC cppVar_90735;
	BIT_VEC cppVar_90736 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_90737 = (cppVar_90736 << 3) | 3;
	cppVar_90737 = (cppVar_90737 & cppMask_un_5_);
	BIT_VEC cppVar_90738 = (0 << 5) | cppVar_90737;
	cppVar_90738 = (cppVar_90738 & cppMask_un_8_);
	bool cppVar_90740 = (cppVar_90738 == 137);
	if (cppVar_90740) {
	cppVar_90735 = TMOD;
	} else {
	BIT_VEC cppVar_90741;
	BIT_VEC cppVar_90742 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_90743 = (cppVar_90742 << 3) | 3;
	cppVar_90743 = (cppVar_90743 & cppMask_un_5_);
	BIT_VEC cppVar_90744 = (0 << 5) | cppVar_90743;
	cppVar_90744 = (cppVar_90744 & cppMask_un_8_);
	bool cppVar_90746 = (cppVar_90744 == 138);
	if (cppVar_90746) {
	cppVar_90741 = TL0;
	} else {
	BIT_VEC cppVar_90747;
	BIT_VEC cppVar_90748 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_90749 = (cppVar_90748 << 3) | 3;
	cppVar_90749 = (cppVar_90749 & cppMask_un_5_);
	BIT_VEC cppVar_90750 = (0 << 5) | cppVar_90749;
	cppVar_90750 = (cppVar_90750 & cppMask_un_8_);
	bool cppVar_90752 = (cppVar_90750 == 140);
	if (cppVar_90752) {
	cppVar_90747 = TH0;
	} else {
	BIT_VEC cppVar_90753;
	BIT_VEC cppVar_90754 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_90755 = (cppVar_90754 << 3) | 3;
	cppVar_90755 = (cppVar_90755 & cppMask_un_5_);
	BIT_VEC cppVar_90756 = (0 << 5) | cppVar_90755;
	cppVar_90756 = (cppVar_90756 & cppMask_un_8_);
	bool cppVar_90758 = (cppVar_90756 == 139);
	if (cppVar_90758) {
	cppVar_90753 = TL1;
	} else {
	BIT_VEC cppVar_90759;
	BIT_VEC cppVar_90760 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_90761 = (cppVar_90760 << 3) | 3;
	cppVar_90761 = (cppVar_90761 & cppMask_un_5_);
	BIT_VEC cppVar_90762 = (0 << 5) | cppVar_90761;
	cppVar_90762 = (cppVar_90762 & cppMask_un_8_);
	bool cppVar_90764 = (cppVar_90762 == 141);
	if (cppVar_90764) {
	cppVar_90759 = TH1;
	} else {
	BIT_VEC cppVar_90765;
	BIT_VEC cppVar_90766 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_90767 = (cppVar_90766 << 3) | 3;
	cppVar_90767 = (cppVar_90767 & cppMask_un_5_);
	BIT_VEC cppVar_90768 = (0 << 5) | cppVar_90767;
	cppVar_90768 = (cppVar_90768 & cppMask_un_8_);
	bool cppVar_90770 = (cppVar_90768 == 144);
	if (cppVar_90770) {
	cppVar_90765 = P1;
	} else {
	BIT_VEC cppVar_90771;
	BIT_VEC cppVar_90772 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_90773 = (cppVar_90772 << 3) | 3;
	cppVar_90773 = (cppVar_90773 & cppMask_un_5_);
	BIT_VEC cppVar_90774 = (0 << 5) | cppVar_90773;
	cppVar_90774 = (cppVar_90774 & cppMask_un_8_);
	bool cppVar_90776 = (cppVar_90774 == 152);
	if (cppVar_90776) {
	cppVar_90771 = SCON;
	} else {
	BIT_VEC cppVar_90777;
	BIT_VEC cppVar_90778 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_90779 = (cppVar_90778 << 3) | 3;
	cppVar_90779 = (cppVar_90779 & cppMask_un_5_);
	BIT_VEC cppVar_90780 = (0 << 5) | cppVar_90779;
	cppVar_90780 = (cppVar_90780 & cppMask_un_8_);
	bool cppVar_90782 = (cppVar_90780 == 153);
	if (cppVar_90782) {
	cppVar_90777 = SBUF;
	} else {
	BIT_VEC cppVar_90783;
	BIT_VEC cppVar_90784 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_90785 = (cppVar_90784 << 3) | 3;
	cppVar_90785 = (cppVar_90785 & cppMask_un_5_);
	BIT_VEC cppVar_90786 = (0 << 5) | cppVar_90785;
	cppVar_90786 = (cppVar_90786 & cppMask_un_8_);
	bool cppVar_90788 = (cppVar_90786 == 160);
	if (cppVar_90788) {
	cppVar_90783 = P2;
	} else {
	BIT_VEC cppVar_90789;
	BIT_VEC cppVar_90790 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_90791 = (cppVar_90790 << 3) | 3;
	cppVar_90791 = (cppVar_90791 & cppMask_un_5_);
	BIT_VEC cppVar_90792 = (0 << 5) | cppVar_90791;
	cppVar_90792 = (cppVar_90792 & cppMask_un_8_);
	bool cppVar_90794 = (cppVar_90792 == 168);
	if (cppVar_90794) {
	cppVar_90789 = IE;
	} else {
	BIT_VEC cppVar_90795;
	BIT_VEC cppVar_90796 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_90797 = (cppVar_90796 << 3) | 3;
	cppVar_90797 = (cppVar_90797 & cppMask_un_5_);
	BIT_VEC cppVar_90798 = (0 << 5) | cppVar_90797;
	cppVar_90798 = (cppVar_90798 & cppMask_un_8_);
	bool cppVar_90800 = (cppVar_90798 == 176);
	if (cppVar_90800) {
	cppVar_90795 = P3;
	} else {
	BIT_VEC cppVar_90801;
	BIT_VEC cppVar_90802 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_90803 = (cppVar_90802 << 3) | 3;
	cppVar_90803 = (cppVar_90803 & cppMask_un_5_);
	BIT_VEC cppVar_90804 = (0 << 5) | cppVar_90803;
	cppVar_90804 = (cppVar_90804 & cppMask_un_8_);
	bool cppVar_90806 = (cppVar_90804 == 184);
	if (cppVar_90806) {
	cppVar_90801 = IP;
	} else {
	BIT_VEC cppVar_90807;
	BIT_VEC cppVar_90808 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_90809 = (cppVar_90808 << 3) | 3;
	cppVar_90809 = (cppVar_90809 & cppMask_un_5_);
	BIT_VEC cppVar_90810 = (0 << 5) | cppVar_90809;
	cppVar_90810 = (cppVar_90810 & cppMask_un_8_);
	bool cppVar_90812 = (cppVar_90810 == 208);
	if (cppVar_90812) {
	cppVar_90807 = PSW;
	} else {
	BIT_VEC cppVar_90813;
	BIT_VEC cppVar_90814 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_90815 = (cppVar_90814 << 3) | 3;
	cppVar_90815 = (cppVar_90815 & cppMask_un_5_);
	BIT_VEC cppVar_90816 = (0 << 5) | cppVar_90815;
	cppVar_90816 = (cppVar_90816 & cppMask_un_8_);
	bool cppVar_90818 = (cppVar_90816 == 224);
	if (cppVar_90818) {
	cppVar_90813 = ACC;
	} else {
	BIT_VEC cppVar_90819;
	BIT_VEC cppVar_90820 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_90821 = (cppVar_90820 << 3) | 3;
	cppVar_90821 = (cppVar_90821 & cppMask_un_5_);
	BIT_VEC cppVar_90822 = (0 << 5) | cppVar_90821;
	cppVar_90822 = (cppVar_90822 & cppMask_un_8_);
	bool cppVar_90824 = (cppVar_90822 == 240);
	if (cppVar_90824) {
	cppVar_90819 = B;
	} else {
	cppVar_90819 = 0;
	}
	cppVar_90813 = cppVar_90819;
	}
	cppVar_90807 = cppVar_90813;
	}
	cppVar_90801 = cppVar_90807;
	}
	cppVar_90795 = cppVar_90801;
	}
	cppVar_90789 = cppVar_90795;
	}
	cppVar_90783 = cppVar_90789;
	}
	cppVar_90777 = cppVar_90783;
	}
	cppVar_90771 = cppVar_90777;
	}
	cppVar_90765 = cppVar_90771;
	}
	cppVar_90759 = cppVar_90765;
	}
	cppVar_90753 = cppVar_90759;
	}
	cppVar_90747 = cppVar_90753;
	}
	cppVar_90741 = cppVar_90747;
	}
	cppVar_90735 = cppVar_90741;
	}
	cppVar_90729 = cppVar_90735;
	}
	cppVar_90723 = cppVar_90729;
	}
	cppVar_90717 = cppVar_90723;
	}
	cppVar_90711 = cppVar_90717;
	}
	cppVar_90705 = cppVar_90711;
	}
	cppVar_90699 = cppVar_90705;
	}
	cppVar_90686 = cppVar_90699;
	}
	type_mem cppVar_90826 = IRAM;
	cppVar_90826.wr(cppVar_90685, cppVar_90686);
	cppVar_90677 = cppVar_90826;
	} else {
	cppVar_90677 = IRAM;
	}
	cppVar_90673 = cppVar_90677;
	} else {
	type_mem cppVar_90827;
	BIT_VEC cppVar_90828 = ROM.rd(PC);
	bool cppVar_90830 = (cppVar_90828 == 138);
	if (cppVar_90830) {
	type_mem cppVar_90831;
	BIT_VEC cppVar_90833 = PC + 1;
	cppVar_90833 = (cppVar_90833 & cppMask_un_16_);
	BIT_VEC cppVar_90834 = ROM.rd(cppVar_90833);
	BIT_VEC cppVar_90835 = (cppVar_90834 >> 7) & cppMask_un_1_;
	bool cppVar_90837 = (cppVar_90835 == 0);
	if (cppVar_90837) {
	BIT_VEC cppVar_90838 = PC + 1;
	cppVar_90838 = (cppVar_90838 & cppMask_un_16_);
	BIT_VEC cppVar_90839 = ROM.rd(cppVar_90838);
	BIT_VEC cppVar_90840;
	BIT_VEC cppVar_90842 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_90844 = (cppVar_90842 << 3) | 2;
	cppVar_90844 = (cppVar_90844 & cppMask_un_5_);
	BIT_VEC cppVar_90845 = (0 << 5) | cppVar_90844;
	cppVar_90845 = (cppVar_90845 & cppMask_un_8_);
	BIT_VEC cppVar_90846 = (cppVar_90845 >> 7) & cppMask_un_1_;
	bool cppVar_90848 = (cppVar_90846 == 0);
	if (cppVar_90848) {
	BIT_VEC cppVar_90849 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_90850 = (cppVar_90849 << 3) | 2;
	cppVar_90850 = (cppVar_90850 & cppMask_un_5_);
	BIT_VEC cppVar_90851 = (0 << 5) | cppVar_90850;
	cppVar_90851 = (cppVar_90851 & cppMask_un_8_);
	BIT_VEC cppVar_90852 = IRAM.rd(cppVar_90851);
	cppVar_90840 = cppVar_90852;
	} else {
	BIT_VEC cppVar_90853;
	BIT_VEC cppVar_90854 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_90855 = (cppVar_90854 << 3) | 2;
	cppVar_90855 = (cppVar_90855 & cppMask_un_5_);
	BIT_VEC cppVar_90856 = (0 << 5) | cppVar_90855;
	cppVar_90856 = (cppVar_90856 & cppMask_un_8_);
	bool cppVar_90858 = (cppVar_90856 == 128);
	if (cppVar_90858) {
	cppVar_90853 = P0;
	} else {
	BIT_VEC cppVar_90859;
	BIT_VEC cppVar_90860 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_90861 = (cppVar_90860 << 3) | 2;
	cppVar_90861 = (cppVar_90861 & cppMask_un_5_);
	BIT_VEC cppVar_90862 = (0 << 5) | cppVar_90861;
	cppVar_90862 = (cppVar_90862 & cppMask_un_8_);
	bool cppVar_90864 = (cppVar_90862 == 129);
	if (cppVar_90864) {
	cppVar_90859 = SP;
	} else {
	BIT_VEC cppVar_90865;
	BIT_VEC cppVar_90866 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_90867 = (cppVar_90866 << 3) | 2;
	cppVar_90867 = (cppVar_90867 & cppMask_un_5_);
	BIT_VEC cppVar_90868 = (0 << 5) | cppVar_90867;
	cppVar_90868 = (cppVar_90868 & cppMask_un_8_);
	bool cppVar_90870 = (cppVar_90868 == 130);
	if (cppVar_90870) {
	cppVar_90865 = DPL;
	} else {
	BIT_VEC cppVar_90871;
	BIT_VEC cppVar_90872 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_90873 = (cppVar_90872 << 3) | 2;
	cppVar_90873 = (cppVar_90873 & cppMask_un_5_);
	BIT_VEC cppVar_90874 = (0 << 5) | cppVar_90873;
	cppVar_90874 = (cppVar_90874 & cppMask_un_8_);
	bool cppVar_90876 = (cppVar_90874 == 131);
	if (cppVar_90876) {
	cppVar_90871 = DPH;
	} else {
	BIT_VEC cppVar_90877;
	BIT_VEC cppVar_90878 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_90879 = (cppVar_90878 << 3) | 2;
	cppVar_90879 = (cppVar_90879 & cppMask_un_5_);
	BIT_VEC cppVar_90880 = (0 << 5) | cppVar_90879;
	cppVar_90880 = (cppVar_90880 & cppMask_un_8_);
	bool cppVar_90882 = (cppVar_90880 == 135);
	if (cppVar_90882) {
	cppVar_90877 = PCON;
	} else {
	BIT_VEC cppVar_90883;
	BIT_VEC cppVar_90884 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_90885 = (cppVar_90884 << 3) | 2;
	cppVar_90885 = (cppVar_90885 & cppMask_un_5_);
	BIT_VEC cppVar_90886 = (0 << 5) | cppVar_90885;
	cppVar_90886 = (cppVar_90886 & cppMask_un_8_);
	bool cppVar_90888 = (cppVar_90886 == 136);
	if (cppVar_90888) {
	cppVar_90883 = TCON;
	} else {
	BIT_VEC cppVar_90889;
	BIT_VEC cppVar_90890 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_90891 = (cppVar_90890 << 3) | 2;
	cppVar_90891 = (cppVar_90891 & cppMask_un_5_);
	BIT_VEC cppVar_90892 = (0 << 5) | cppVar_90891;
	cppVar_90892 = (cppVar_90892 & cppMask_un_8_);
	bool cppVar_90894 = (cppVar_90892 == 137);
	if (cppVar_90894) {
	cppVar_90889 = TMOD;
	} else {
	BIT_VEC cppVar_90895;
	BIT_VEC cppVar_90896 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_90897 = (cppVar_90896 << 3) | 2;
	cppVar_90897 = (cppVar_90897 & cppMask_un_5_);
	BIT_VEC cppVar_90898 = (0 << 5) | cppVar_90897;
	cppVar_90898 = (cppVar_90898 & cppMask_un_8_);
	bool cppVar_90900 = (cppVar_90898 == 138);
	if (cppVar_90900) {
	cppVar_90895 = TL0;
	} else {
	BIT_VEC cppVar_90901;
	BIT_VEC cppVar_90902 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_90903 = (cppVar_90902 << 3) | 2;
	cppVar_90903 = (cppVar_90903 & cppMask_un_5_);
	BIT_VEC cppVar_90904 = (0 << 5) | cppVar_90903;
	cppVar_90904 = (cppVar_90904 & cppMask_un_8_);
	bool cppVar_90906 = (cppVar_90904 == 140);
	if (cppVar_90906) {
	cppVar_90901 = TH0;
	} else {
	BIT_VEC cppVar_90907;
	BIT_VEC cppVar_90908 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_90909 = (cppVar_90908 << 3) | 2;
	cppVar_90909 = (cppVar_90909 & cppMask_un_5_);
	BIT_VEC cppVar_90910 = (0 << 5) | cppVar_90909;
	cppVar_90910 = (cppVar_90910 & cppMask_un_8_);
	bool cppVar_90912 = (cppVar_90910 == 139);
	if (cppVar_90912) {
	cppVar_90907 = TL1;
	} else {
	BIT_VEC cppVar_90913;
	BIT_VEC cppVar_90914 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_90915 = (cppVar_90914 << 3) | 2;
	cppVar_90915 = (cppVar_90915 & cppMask_un_5_);
	BIT_VEC cppVar_90916 = (0 << 5) | cppVar_90915;
	cppVar_90916 = (cppVar_90916 & cppMask_un_8_);
	bool cppVar_90918 = (cppVar_90916 == 141);
	if (cppVar_90918) {
	cppVar_90913 = TH1;
	} else {
	BIT_VEC cppVar_90919;
	BIT_VEC cppVar_90920 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_90921 = (cppVar_90920 << 3) | 2;
	cppVar_90921 = (cppVar_90921 & cppMask_un_5_);
	BIT_VEC cppVar_90922 = (0 << 5) | cppVar_90921;
	cppVar_90922 = (cppVar_90922 & cppMask_un_8_);
	bool cppVar_90924 = (cppVar_90922 == 144);
	if (cppVar_90924) {
	cppVar_90919 = P1;
	} else {
	BIT_VEC cppVar_90925;
	BIT_VEC cppVar_90926 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_90927 = (cppVar_90926 << 3) | 2;
	cppVar_90927 = (cppVar_90927 & cppMask_un_5_);
	BIT_VEC cppVar_90928 = (0 << 5) | cppVar_90927;
	cppVar_90928 = (cppVar_90928 & cppMask_un_8_);
	bool cppVar_90930 = (cppVar_90928 == 152);
	if (cppVar_90930) {
	cppVar_90925 = SCON;
	} else {
	BIT_VEC cppVar_90931;
	BIT_VEC cppVar_90932 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_90933 = (cppVar_90932 << 3) | 2;
	cppVar_90933 = (cppVar_90933 & cppMask_un_5_);
	BIT_VEC cppVar_90934 = (0 << 5) | cppVar_90933;
	cppVar_90934 = (cppVar_90934 & cppMask_un_8_);
	bool cppVar_90936 = (cppVar_90934 == 153);
	if (cppVar_90936) {
	cppVar_90931 = SBUF;
	} else {
	BIT_VEC cppVar_90937;
	BIT_VEC cppVar_90938 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_90939 = (cppVar_90938 << 3) | 2;
	cppVar_90939 = (cppVar_90939 & cppMask_un_5_);
	BIT_VEC cppVar_90940 = (0 << 5) | cppVar_90939;
	cppVar_90940 = (cppVar_90940 & cppMask_un_8_);
	bool cppVar_90942 = (cppVar_90940 == 160);
	if (cppVar_90942) {
	cppVar_90937 = P2;
	} else {
	BIT_VEC cppVar_90943;
	BIT_VEC cppVar_90944 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_90945 = (cppVar_90944 << 3) | 2;
	cppVar_90945 = (cppVar_90945 & cppMask_un_5_);
	BIT_VEC cppVar_90946 = (0 << 5) | cppVar_90945;
	cppVar_90946 = (cppVar_90946 & cppMask_un_8_);
	bool cppVar_90948 = (cppVar_90946 == 168);
	if (cppVar_90948) {
	cppVar_90943 = IE;
	} else {
	BIT_VEC cppVar_90949;
	BIT_VEC cppVar_90950 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_90951 = (cppVar_90950 << 3) | 2;
	cppVar_90951 = (cppVar_90951 & cppMask_un_5_);
	BIT_VEC cppVar_90952 = (0 << 5) | cppVar_90951;
	cppVar_90952 = (cppVar_90952 & cppMask_un_8_);
	bool cppVar_90954 = (cppVar_90952 == 176);
	if (cppVar_90954) {
	cppVar_90949 = P3;
	} else {
	BIT_VEC cppVar_90955;
	BIT_VEC cppVar_90956 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_90957 = (cppVar_90956 << 3) | 2;
	cppVar_90957 = (cppVar_90957 & cppMask_un_5_);
	BIT_VEC cppVar_90958 = (0 << 5) | cppVar_90957;
	cppVar_90958 = (cppVar_90958 & cppMask_un_8_);
	bool cppVar_90960 = (cppVar_90958 == 184);
	if (cppVar_90960) {
	cppVar_90955 = IP;
	} else {
	BIT_VEC cppVar_90961;
	BIT_VEC cppVar_90962 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_90963 = (cppVar_90962 << 3) | 2;
	cppVar_90963 = (cppVar_90963 & cppMask_un_5_);
	BIT_VEC cppVar_90964 = (0 << 5) | cppVar_90963;
	cppVar_90964 = (cppVar_90964 & cppMask_un_8_);
	bool cppVar_90966 = (cppVar_90964 == 208);
	if (cppVar_90966) {
	cppVar_90961 = PSW;
	} else {
	BIT_VEC cppVar_90967;
	BIT_VEC cppVar_90968 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_90969 = (cppVar_90968 << 3) | 2;
	cppVar_90969 = (cppVar_90969 & cppMask_un_5_);
	BIT_VEC cppVar_90970 = (0 << 5) | cppVar_90969;
	cppVar_90970 = (cppVar_90970 & cppMask_un_8_);
	bool cppVar_90972 = (cppVar_90970 == 224);
	if (cppVar_90972) {
	cppVar_90967 = ACC;
	} else {
	BIT_VEC cppVar_90973;
	BIT_VEC cppVar_90974 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_90975 = (cppVar_90974 << 3) | 2;
	cppVar_90975 = (cppVar_90975 & cppMask_un_5_);
	BIT_VEC cppVar_90976 = (0 << 5) | cppVar_90975;
	cppVar_90976 = (cppVar_90976 & cppMask_un_8_);
	bool cppVar_90978 = (cppVar_90976 == 240);
	if (cppVar_90978) {
	cppVar_90973 = B;
	} else {
	cppVar_90973 = 0;
	}
	cppVar_90967 = cppVar_90973;
	}
	cppVar_90961 = cppVar_90967;
	}
	cppVar_90955 = cppVar_90961;
	}
	cppVar_90949 = cppVar_90955;
	}
	cppVar_90943 = cppVar_90949;
	}
	cppVar_90937 = cppVar_90943;
	}
	cppVar_90931 = cppVar_90937;
	}
	cppVar_90925 = cppVar_90931;
	}
	cppVar_90919 = cppVar_90925;
	}
	cppVar_90913 = cppVar_90919;
	}
	cppVar_90907 = cppVar_90913;
	}
	cppVar_90901 = cppVar_90907;
	}
	cppVar_90895 = cppVar_90901;
	}
	cppVar_90889 = cppVar_90895;
	}
	cppVar_90883 = cppVar_90889;
	}
	cppVar_90877 = cppVar_90883;
	}
	cppVar_90871 = cppVar_90877;
	}
	cppVar_90865 = cppVar_90871;
	}
	cppVar_90859 = cppVar_90865;
	}
	cppVar_90853 = cppVar_90859;
	}
	cppVar_90840 = cppVar_90853;
	}
	type_mem cppVar_90980 = IRAM;
	cppVar_90980.wr(cppVar_90839, cppVar_90840);
	cppVar_90831 = cppVar_90980;
	} else {
	cppVar_90831 = IRAM;
	}
	cppVar_90827 = cppVar_90831;
	} else {
	type_mem cppVar_90981;
	BIT_VEC cppVar_90982 = ROM.rd(PC);
	bool cppVar_90984 = (cppVar_90982 == 137);
	if (cppVar_90984) {
	type_mem cppVar_90985;
	BIT_VEC cppVar_90987 = PC + 1;
	cppVar_90987 = (cppVar_90987 & cppMask_un_16_);
	BIT_VEC cppVar_90988 = ROM.rd(cppVar_90987);
	BIT_VEC cppVar_90989 = (cppVar_90988 >> 7) & cppMask_un_1_;
	bool cppVar_90991 = (cppVar_90989 == 0);
	if (cppVar_90991) {
	BIT_VEC cppVar_90992 = PC + 1;
	cppVar_90992 = (cppVar_90992 & cppMask_un_16_);
	BIT_VEC cppVar_90993 = ROM.rd(cppVar_90992);
	BIT_VEC cppVar_90994;
	BIT_VEC cppVar_90996 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_90998 = (cppVar_90996 << 3) | 1;
	cppVar_90998 = (cppVar_90998 & cppMask_un_5_);
	BIT_VEC cppVar_90999 = (0 << 5) | cppVar_90998;
	cppVar_90999 = (cppVar_90999 & cppMask_un_8_);
	BIT_VEC cppVar_91000 = (cppVar_90999 >> 7) & cppMask_un_1_;
	bool cppVar_91002 = (cppVar_91000 == 0);
	if (cppVar_91002) {
	BIT_VEC cppVar_91003 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_91004 = (cppVar_91003 << 3) | 1;
	cppVar_91004 = (cppVar_91004 & cppMask_un_5_);
	BIT_VEC cppVar_91005 = (0 << 5) | cppVar_91004;
	cppVar_91005 = (cppVar_91005 & cppMask_un_8_);
	BIT_VEC cppVar_91006 = IRAM.rd(cppVar_91005);
	cppVar_90994 = cppVar_91006;
	} else {
	BIT_VEC cppVar_91007;
	BIT_VEC cppVar_91008 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_91009 = (cppVar_91008 << 3) | 1;
	cppVar_91009 = (cppVar_91009 & cppMask_un_5_);
	BIT_VEC cppVar_91010 = (0 << 5) | cppVar_91009;
	cppVar_91010 = (cppVar_91010 & cppMask_un_8_);
	bool cppVar_91012 = (cppVar_91010 == 128);
	if (cppVar_91012) {
	cppVar_91007 = P0;
	} else {
	BIT_VEC cppVar_91013;
	BIT_VEC cppVar_91014 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_91015 = (cppVar_91014 << 3) | 1;
	cppVar_91015 = (cppVar_91015 & cppMask_un_5_);
	BIT_VEC cppVar_91016 = (0 << 5) | cppVar_91015;
	cppVar_91016 = (cppVar_91016 & cppMask_un_8_);
	bool cppVar_91018 = (cppVar_91016 == 129);
	if (cppVar_91018) {
	cppVar_91013 = SP;
	} else {
	BIT_VEC cppVar_91019;
	BIT_VEC cppVar_91020 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_91021 = (cppVar_91020 << 3) | 1;
	cppVar_91021 = (cppVar_91021 & cppMask_un_5_);
	BIT_VEC cppVar_91022 = (0 << 5) | cppVar_91021;
	cppVar_91022 = (cppVar_91022 & cppMask_un_8_);
	bool cppVar_91024 = (cppVar_91022 == 130);
	if (cppVar_91024) {
	cppVar_91019 = DPL;
	} else {
	BIT_VEC cppVar_91025;
	BIT_VEC cppVar_91026 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_91027 = (cppVar_91026 << 3) | 1;
	cppVar_91027 = (cppVar_91027 & cppMask_un_5_);
	BIT_VEC cppVar_91028 = (0 << 5) | cppVar_91027;
	cppVar_91028 = (cppVar_91028 & cppMask_un_8_);
	bool cppVar_91030 = (cppVar_91028 == 131);
	if (cppVar_91030) {
	cppVar_91025 = DPH;
	} else {
	BIT_VEC cppVar_91031;
	BIT_VEC cppVar_91032 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_91033 = (cppVar_91032 << 3) | 1;
	cppVar_91033 = (cppVar_91033 & cppMask_un_5_);
	BIT_VEC cppVar_91034 = (0 << 5) | cppVar_91033;
	cppVar_91034 = (cppVar_91034 & cppMask_un_8_);
	bool cppVar_91036 = (cppVar_91034 == 135);
	if (cppVar_91036) {
	cppVar_91031 = PCON;
	} else {
	BIT_VEC cppVar_91037;
	BIT_VEC cppVar_91038 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_91039 = (cppVar_91038 << 3) | 1;
	cppVar_91039 = (cppVar_91039 & cppMask_un_5_);
	BIT_VEC cppVar_91040 = (0 << 5) | cppVar_91039;
	cppVar_91040 = (cppVar_91040 & cppMask_un_8_);
	bool cppVar_91042 = (cppVar_91040 == 136);
	if (cppVar_91042) {
	cppVar_91037 = TCON;
	} else {
	BIT_VEC cppVar_91043;
	BIT_VEC cppVar_91044 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_91045 = (cppVar_91044 << 3) | 1;
	cppVar_91045 = (cppVar_91045 & cppMask_un_5_);
	BIT_VEC cppVar_91046 = (0 << 5) | cppVar_91045;
	cppVar_91046 = (cppVar_91046 & cppMask_un_8_);
	bool cppVar_91048 = (cppVar_91046 == 137);
	if (cppVar_91048) {
	cppVar_91043 = TMOD;
	} else {
	BIT_VEC cppVar_91049;
	BIT_VEC cppVar_91050 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_91051 = (cppVar_91050 << 3) | 1;
	cppVar_91051 = (cppVar_91051 & cppMask_un_5_);
	BIT_VEC cppVar_91052 = (0 << 5) | cppVar_91051;
	cppVar_91052 = (cppVar_91052 & cppMask_un_8_);
	bool cppVar_91054 = (cppVar_91052 == 138);
	if (cppVar_91054) {
	cppVar_91049 = TL0;
	} else {
	BIT_VEC cppVar_91055;
	BIT_VEC cppVar_91056 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_91057 = (cppVar_91056 << 3) | 1;
	cppVar_91057 = (cppVar_91057 & cppMask_un_5_);
	BIT_VEC cppVar_91058 = (0 << 5) | cppVar_91057;
	cppVar_91058 = (cppVar_91058 & cppMask_un_8_);
	bool cppVar_91060 = (cppVar_91058 == 140);
	if (cppVar_91060) {
	cppVar_91055 = TH0;
	} else {
	BIT_VEC cppVar_91061;
	BIT_VEC cppVar_91062 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_91063 = (cppVar_91062 << 3) | 1;
	cppVar_91063 = (cppVar_91063 & cppMask_un_5_);
	BIT_VEC cppVar_91064 = (0 << 5) | cppVar_91063;
	cppVar_91064 = (cppVar_91064 & cppMask_un_8_);
	bool cppVar_91066 = (cppVar_91064 == 139);
	if (cppVar_91066) {
	cppVar_91061 = TL1;
	} else {
	BIT_VEC cppVar_91067;
	BIT_VEC cppVar_91068 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_91069 = (cppVar_91068 << 3) | 1;
	cppVar_91069 = (cppVar_91069 & cppMask_un_5_);
	BIT_VEC cppVar_91070 = (0 << 5) | cppVar_91069;
	cppVar_91070 = (cppVar_91070 & cppMask_un_8_);
	bool cppVar_91072 = (cppVar_91070 == 141);
	if (cppVar_91072) {
	cppVar_91067 = TH1;
	} else {
	BIT_VEC cppVar_91073;
	BIT_VEC cppVar_91074 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_91075 = (cppVar_91074 << 3) | 1;
	cppVar_91075 = (cppVar_91075 & cppMask_un_5_);
	BIT_VEC cppVar_91076 = (0 << 5) | cppVar_91075;
	cppVar_91076 = (cppVar_91076 & cppMask_un_8_);
	bool cppVar_91078 = (cppVar_91076 == 144);
	if (cppVar_91078) {
	cppVar_91073 = P1;
	} else {
	BIT_VEC cppVar_91079;
	BIT_VEC cppVar_91080 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_91081 = (cppVar_91080 << 3) | 1;
	cppVar_91081 = (cppVar_91081 & cppMask_un_5_);
	BIT_VEC cppVar_91082 = (0 << 5) | cppVar_91081;
	cppVar_91082 = (cppVar_91082 & cppMask_un_8_);
	bool cppVar_91084 = (cppVar_91082 == 152);
	if (cppVar_91084) {
	cppVar_91079 = SCON;
	} else {
	BIT_VEC cppVar_91085;
	BIT_VEC cppVar_91086 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_91087 = (cppVar_91086 << 3) | 1;
	cppVar_91087 = (cppVar_91087 & cppMask_un_5_);
	BIT_VEC cppVar_91088 = (0 << 5) | cppVar_91087;
	cppVar_91088 = (cppVar_91088 & cppMask_un_8_);
	bool cppVar_91090 = (cppVar_91088 == 153);
	if (cppVar_91090) {
	cppVar_91085 = SBUF;
	} else {
	BIT_VEC cppVar_91091;
	BIT_VEC cppVar_91092 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_91093 = (cppVar_91092 << 3) | 1;
	cppVar_91093 = (cppVar_91093 & cppMask_un_5_);
	BIT_VEC cppVar_91094 = (0 << 5) | cppVar_91093;
	cppVar_91094 = (cppVar_91094 & cppMask_un_8_);
	bool cppVar_91096 = (cppVar_91094 == 160);
	if (cppVar_91096) {
	cppVar_91091 = P2;
	} else {
	BIT_VEC cppVar_91097;
	BIT_VEC cppVar_91098 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_91099 = (cppVar_91098 << 3) | 1;
	cppVar_91099 = (cppVar_91099 & cppMask_un_5_);
	BIT_VEC cppVar_91100 = (0 << 5) | cppVar_91099;
	cppVar_91100 = (cppVar_91100 & cppMask_un_8_);
	bool cppVar_91102 = (cppVar_91100 == 168);
	if (cppVar_91102) {
	cppVar_91097 = IE;
	} else {
	BIT_VEC cppVar_91103;
	BIT_VEC cppVar_91104 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_91105 = (cppVar_91104 << 3) | 1;
	cppVar_91105 = (cppVar_91105 & cppMask_un_5_);
	BIT_VEC cppVar_91106 = (0 << 5) | cppVar_91105;
	cppVar_91106 = (cppVar_91106 & cppMask_un_8_);
	bool cppVar_91108 = (cppVar_91106 == 176);
	if (cppVar_91108) {
	cppVar_91103 = P3;
	} else {
	BIT_VEC cppVar_91109;
	BIT_VEC cppVar_91110 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_91111 = (cppVar_91110 << 3) | 1;
	cppVar_91111 = (cppVar_91111 & cppMask_un_5_);
	BIT_VEC cppVar_91112 = (0 << 5) | cppVar_91111;
	cppVar_91112 = (cppVar_91112 & cppMask_un_8_);
	bool cppVar_91114 = (cppVar_91112 == 184);
	if (cppVar_91114) {
	cppVar_91109 = IP;
	} else {
	BIT_VEC cppVar_91115;
	BIT_VEC cppVar_91116 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_91117 = (cppVar_91116 << 3) | 1;
	cppVar_91117 = (cppVar_91117 & cppMask_un_5_);
	BIT_VEC cppVar_91118 = (0 << 5) | cppVar_91117;
	cppVar_91118 = (cppVar_91118 & cppMask_un_8_);
	bool cppVar_91120 = (cppVar_91118 == 208);
	if (cppVar_91120) {
	cppVar_91115 = PSW;
	} else {
	BIT_VEC cppVar_91121;
	BIT_VEC cppVar_91122 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_91123 = (cppVar_91122 << 3) | 1;
	cppVar_91123 = (cppVar_91123 & cppMask_un_5_);
	BIT_VEC cppVar_91124 = (0 << 5) | cppVar_91123;
	cppVar_91124 = (cppVar_91124 & cppMask_un_8_);
	bool cppVar_91126 = (cppVar_91124 == 224);
	if (cppVar_91126) {
	cppVar_91121 = ACC;
	} else {
	BIT_VEC cppVar_91127;
	BIT_VEC cppVar_91128 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_91129 = (cppVar_91128 << 3) | 1;
	cppVar_91129 = (cppVar_91129 & cppMask_un_5_);
	BIT_VEC cppVar_91130 = (0 << 5) | cppVar_91129;
	cppVar_91130 = (cppVar_91130 & cppMask_un_8_);
	bool cppVar_91132 = (cppVar_91130 == 240);
	if (cppVar_91132) {
	cppVar_91127 = B;
	} else {
	cppVar_91127 = 0;
	}
	cppVar_91121 = cppVar_91127;
	}
	cppVar_91115 = cppVar_91121;
	}
	cppVar_91109 = cppVar_91115;
	}
	cppVar_91103 = cppVar_91109;
	}
	cppVar_91097 = cppVar_91103;
	}
	cppVar_91091 = cppVar_91097;
	}
	cppVar_91085 = cppVar_91091;
	}
	cppVar_91079 = cppVar_91085;
	}
	cppVar_91073 = cppVar_91079;
	}
	cppVar_91067 = cppVar_91073;
	}
	cppVar_91061 = cppVar_91067;
	}
	cppVar_91055 = cppVar_91061;
	}
	cppVar_91049 = cppVar_91055;
	}
	cppVar_91043 = cppVar_91049;
	}
	cppVar_91037 = cppVar_91043;
	}
	cppVar_91031 = cppVar_91037;
	}
	cppVar_91025 = cppVar_91031;
	}
	cppVar_91019 = cppVar_91025;
	}
	cppVar_91013 = cppVar_91019;
	}
	cppVar_91007 = cppVar_91013;
	}
	cppVar_90994 = cppVar_91007;
	}
	type_mem cppVar_91134 = IRAM;
	cppVar_91134.wr(cppVar_90993, cppVar_90994);
	cppVar_90985 = cppVar_91134;
	} else {
	cppVar_90985 = IRAM;
	}
	cppVar_90981 = cppVar_90985;
	} else {
	type_mem cppVar_91135;
	BIT_VEC cppVar_91136 = ROM.rd(PC);
	bool cppVar_91138 = (cppVar_91136 == 136);
	if (cppVar_91138) {
	type_mem cppVar_91139;
	BIT_VEC cppVar_91141 = PC + 1;
	cppVar_91141 = (cppVar_91141 & cppMask_un_16_);
	BIT_VEC cppVar_91142 = ROM.rd(cppVar_91141);
	BIT_VEC cppVar_91143 = (cppVar_91142 >> 7) & cppMask_un_1_;
	bool cppVar_91145 = (cppVar_91143 == 0);
	if (cppVar_91145) {
	BIT_VEC cppVar_91146 = PC + 1;
	cppVar_91146 = (cppVar_91146 & cppMask_un_16_);
	BIT_VEC cppVar_91147 = ROM.rd(cppVar_91146);
	BIT_VEC cppVar_91148;
	BIT_VEC cppVar_91150 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_91152 = (cppVar_91150 << 3) | 0;
	cppVar_91152 = (cppVar_91152 & cppMask_un_5_);
	BIT_VEC cppVar_91153 = (0 << 5) | cppVar_91152;
	cppVar_91153 = (cppVar_91153 & cppMask_un_8_);
	BIT_VEC cppVar_91154 = (cppVar_91153 >> 7) & cppMask_un_1_;
	bool cppVar_91156 = (cppVar_91154 == 0);
	if (cppVar_91156) {
	BIT_VEC cppVar_91157 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_91158 = (cppVar_91157 << 3) | 0;
	cppVar_91158 = (cppVar_91158 & cppMask_un_5_);
	BIT_VEC cppVar_91159 = (0 << 5) | cppVar_91158;
	cppVar_91159 = (cppVar_91159 & cppMask_un_8_);
	BIT_VEC cppVar_91160 = IRAM.rd(cppVar_91159);
	cppVar_91148 = cppVar_91160;
	} else {
	BIT_VEC cppVar_91161;
	BIT_VEC cppVar_91162 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_91163 = (cppVar_91162 << 3) | 0;
	cppVar_91163 = (cppVar_91163 & cppMask_un_5_);
	BIT_VEC cppVar_91164 = (0 << 5) | cppVar_91163;
	cppVar_91164 = (cppVar_91164 & cppMask_un_8_);
	bool cppVar_91166 = (cppVar_91164 == 128);
	if (cppVar_91166) {
	cppVar_91161 = P0;
	} else {
	BIT_VEC cppVar_91167;
	BIT_VEC cppVar_91168 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_91169 = (cppVar_91168 << 3) | 0;
	cppVar_91169 = (cppVar_91169 & cppMask_un_5_);
	BIT_VEC cppVar_91170 = (0 << 5) | cppVar_91169;
	cppVar_91170 = (cppVar_91170 & cppMask_un_8_);
	bool cppVar_91172 = (cppVar_91170 == 129);
	if (cppVar_91172) {
	cppVar_91167 = SP;
	} else {
	BIT_VEC cppVar_91173;
	BIT_VEC cppVar_91174 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_91175 = (cppVar_91174 << 3) | 0;
	cppVar_91175 = (cppVar_91175 & cppMask_un_5_);
	BIT_VEC cppVar_91176 = (0 << 5) | cppVar_91175;
	cppVar_91176 = (cppVar_91176 & cppMask_un_8_);
	bool cppVar_91178 = (cppVar_91176 == 130);
	if (cppVar_91178) {
	cppVar_91173 = DPL;
	} else {
	BIT_VEC cppVar_91179;
	BIT_VEC cppVar_91180 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_91181 = (cppVar_91180 << 3) | 0;
	cppVar_91181 = (cppVar_91181 & cppMask_un_5_);
	BIT_VEC cppVar_91182 = (0 << 5) | cppVar_91181;
	cppVar_91182 = (cppVar_91182 & cppMask_un_8_);
	bool cppVar_91184 = (cppVar_91182 == 131);
	if (cppVar_91184) {
	cppVar_91179 = DPH;
	} else {
	BIT_VEC cppVar_91185;
	BIT_VEC cppVar_91186 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_91187 = (cppVar_91186 << 3) | 0;
	cppVar_91187 = (cppVar_91187 & cppMask_un_5_);
	BIT_VEC cppVar_91188 = (0 << 5) | cppVar_91187;
	cppVar_91188 = (cppVar_91188 & cppMask_un_8_);
	bool cppVar_91190 = (cppVar_91188 == 135);
	if (cppVar_91190) {
	cppVar_91185 = PCON;
	} else {
	BIT_VEC cppVar_91191;
	BIT_VEC cppVar_91192 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_91193 = (cppVar_91192 << 3) | 0;
	cppVar_91193 = (cppVar_91193 & cppMask_un_5_);
	BIT_VEC cppVar_91194 = (0 << 5) | cppVar_91193;
	cppVar_91194 = (cppVar_91194 & cppMask_un_8_);
	bool cppVar_91196 = (cppVar_91194 == 136);
	if (cppVar_91196) {
	cppVar_91191 = TCON;
	} else {
	BIT_VEC cppVar_91197;
	BIT_VEC cppVar_91198 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_91199 = (cppVar_91198 << 3) | 0;
	cppVar_91199 = (cppVar_91199 & cppMask_un_5_);
	BIT_VEC cppVar_91200 = (0 << 5) | cppVar_91199;
	cppVar_91200 = (cppVar_91200 & cppMask_un_8_);
	bool cppVar_91202 = (cppVar_91200 == 137);
	if (cppVar_91202) {
	cppVar_91197 = TMOD;
	} else {
	BIT_VEC cppVar_91203;
	BIT_VEC cppVar_91204 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_91205 = (cppVar_91204 << 3) | 0;
	cppVar_91205 = (cppVar_91205 & cppMask_un_5_);
	BIT_VEC cppVar_91206 = (0 << 5) | cppVar_91205;
	cppVar_91206 = (cppVar_91206 & cppMask_un_8_);
	bool cppVar_91208 = (cppVar_91206 == 138);
	if (cppVar_91208) {
	cppVar_91203 = TL0;
	} else {
	BIT_VEC cppVar_91209;
	BIT_VEC cppVar_91210 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_91211 = (cppVar_91210 << 3) | 0;
	cppVar_91211 = (cppVar_91211 & cppMask_un_5_);
	BIT_VEC cppVar_91212 = (0 << 5) | cppVar_91211;
	cppVar_91212 = (cppVar_91212 & cppMask_un_8_);
	bool cppVar_91214 = (cppVar_91212 == 140);
	if (cppVar_91214) {
	cppVar_91209 = TH0;
	} else {
	BIT_VEC cppVar_91215;
	BIT_VEC cppVar_91216 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_91217 = (cppVar_91216 << 3) | 0;
	cppVar_91217 = (cppVar_91217 & cppMask_un_5_);
	BIT_VEC cppVar_91218 = (0 << 5) | cppVar_91217;
	cppVar_91218 = (cppVar_91218 & cppMask_un_8_);
	bool cppVar_91220 = (cppVar_91218 == 139);
	if (cppVar_91220) {
	cppVar_91215 = TL1;
	} else {
	BIT_VEC cppVar_91221;
	BIT_VEC cppVar_91222 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_91223 = (cppVar_91222 << 3) | 0;
	cppVar_91223 = (cppVar_91223 & cppMask_un_5_);
	BIT_VEC cppVar_91224 = (0 << 5) | cppVar_91223;
	cppVar_91224 = (cppVar_91224 & cppMask_un_8_);
	bool cppVar_91226 = (cppVar_91224 == 141);
	if (cppVar_91226) {
	cppVar_91221 = TH1;
	} else {
	BIT_VEC cppVar_91227;
	BIT_VEC cppVar_91228 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_91229 = (cppVar_91228 << 3) | 0;
	cppVar_91229 = (cppVar_91229 & cppMask_un_5_);
	BIT_VEC cppVar_91230 = (0 << 5) | cppVar_91229;
	cppVar_91230 = (cppVar_91230 & cppMask_un_8_);
	bool cppVar_91232 = (cppVar_91230 == 144);
	if (cppVar_91232) {
	cppVar_91227 = P1;
	} else {
	BIT_VEC cppVar_91233;
	BIT_VEC cppVar_91234 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_91235 = (cppVar_91234 << 3) | 0;
	cppVar_91235 = (cppVar_91235 & cppMask_un_5_);
	BIT_VEC cppVar_91236 = (0 << 5) | cppVar_91235;
	cppVar_91236 = (cppVar_91236 & cppMask_un_8_);
	bool cppVar_91238 = (cppVar_91236 == 152);
	if (cppVar_91238) {
	cppVar_91233 = SCON;
	} else {
	BIT_VEC cppVar_91239;
	BIT_VEC cppVar_91240 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_91241 = (cppVar_91240 << 3) | 0;
	cppVar_91241 = (cppVar_91241 & cppMask_un_5_);
	BIT_VEC cppVar_91242 = (0 << 5) | cppVar_91241;
	cppVar_91242 = (cppVar_91242 & cppMask_un_8_);
	bool cppVar_91244 = (cppVar_91242 == 153);
	if (cppVar_91244) {
	cppVar_91239 = SBUF;
	} else {
	BIT_VEC cppVar_91245;
	BIT_VEC cppVar_91246 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_91247 = (cppVar_91246 << 3) | 0;
	cppVar_91247 = (cppVar_91247 & cppMask_un_5_);
	BIT_VEC cppVar_91248 = (0 << 5) | cppVar_91247;
	cppVar_91248 = (cppVar_91248 & cppMask_un_8_);
	bool cppVar_91250 = (cppVar_91248 == 160);
	if (cppVar_91250) {
	cppVar_91245 = P2;
	} else {
	BIT_VEC cppVar_91251;
	BIT_VEC cppVar_91252 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_91253 = (cppVar_91252 << 3) | 0;
	cppVar_91253 = (cppVar_91253 & cppMask_un_5_);
	BIT_VEC cppVar_91254 = (0 << 5) | cppVar_91253;
	cppVar_91254 = (cppVar_91254 & cppMask_un_8_);
	bool cppVar_91256 = (cppVar_91254 == 168);
	if (cppVar_91256) {
	cppVar_91251 = IE;
	} else {
	BIT_VEC cppVar_91257;
	BIT_VEC cppVar_91258 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_91259 = (cppVar_91258 << 3) | 0;
	cppVar_91259 = (cppVar_91259 & cppMask_un_5_);
	BIT_VEC cppVar_91260 = (0 << 5) | cppVar_91259;
	cppVar_91260 = (cppVar_91260 & cppMask_un_8_);
	bool cppVar_91262 = (cppVar_91260 == 176);
	if (cppVar_91262) {
	cppVar_91257 = P3;
	} else {
	BIT_VEC cppVar_91263;
	BIT_VEC cppVar_91264 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_91265 = (cppVar_91264 << 3) | 0;
	cppVar_91265 = (cppVar_91265 & cppMask_un_5_);
	BIT_VEC cppVar_91266 = (0 << 5) | cppVar_91265;
	cppVar_91266 = (cppVar_91266 & cppMask_un_8_);
	bool cppVar_91268 = (cppVar_91266 == 184);
	if (cppVar_91268) {
	cppVar_91263 = IP;
	} else {
	BIT_VEC cppVar_91269;
	BIT_VEC cppVar_91270 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_91271 = (cppVar_91270 << 3) | 0;
	cppVar_91271 = (cppVar_91271 & cppMask_un_5_);
	BIT_VEC cppVar_91272 = (0 << 5) | cppVar_91271;
	cppVar_91272 = (cppVar_91272 & cppMask_un_8_);
	bool cppVar_91274 = (cppVar_91272 == 208);
	if (cppVar_91274) {
	cppVar_91269 = PSW;
	} else {
	BIT_VEC cppVar_91275;
	BIT_VEC cppVar_91276 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_91277 = (cppVar_91276 << 3) | 0;
	cppVar_91277 = (cppVar_91277 & cppMask_un_5_);
	BIT_VEC cppVar_91278 = (0 << 5) | cppVar_91277;
	cppVar_91278 = (cppVar_91278 & cppMask_un_8_);
	bool cppVar_91280 = (cppVar_91278 == 224);
	if (cppVar_91280) {
	cppVar_91275 = ACC;
	} else {
	BIT_VEC cppVar_91281;
	BIT_VEC cppVar_91282 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_91283 = (cppVar_91282 << 3) | 0;
	cppVar_91283 = (cppVar_91283 & cppMask_un_5_);
	BIT_VEC cppVar_91284 = (0 << 5) | cppVar_91283;
	cppVar_91284 = (cppVar_91284 & cppMask_un_8_);
	bool cppVar_91286 = (cppVar_91284 == 240);
	if (cppVar_91286) {
	cppVar_91281 = B;
	} else {
	cppVar_91281 = 0;
	}
	cppVar_91275 = cppVar_91281;
	}
	cppVar_91269 = cppVar_91275;
	}
	cppVar_91263 = cppVar_91269;
	}
	cppVar_91257 = cppVar_91263;
	}
	cppVar_91251 = cppVar_91257;
	}
	cppVar_91245 = cppVar_91251;
	}
	cppVar_91239 = cppVar_91245;
	}
	cppVar_91233 = cppVar_91239;
	}
	cppVar_91227 = cppVar_91233;
	}
	cppVar_91221 = cppVar_91227;
	}
	cppVar_91215 = cppVar_91221;
	}
	cppVar_91209 = cppVar_91215;
	}
	cppVar_91203 = cppVar_91209;
	}
	cppVar_91197 = cppVar_91203;
	}
	cppVar_91191 = cppVar_91197;
	}
	cppVar_91185 = cppVar_91191;
	}
	cppVar_91179 = cppVar_91185;
	}
	cppVar_91173 = cppVar_91179;
	}
	cppVar_91167 = cppVar_91173;
	}
	cppVar_91161 = cppVar_91167;
	}
	cppVar_91148 = cppVar_91161;
	}
	type_mem cppVar_91288 = IRAM;
	cppVar_91288.wr(cppVar_91147, cppVar_91148);
	cppVar_91139 = cppVar_91288;
	} else {
	cppVar_91139 = IRAM;
	}
	cppVar_91135 = cppVar_91139;
	} else {
	type_mem cppVar_91289;
	BIT_VEC cppVar_91290 = ROM.rd(PC);
	bool cppVar_91292 = (cppVar_91290 == 135);
	if (cppVar_91292) {
	type_mem cppVar_91293;
	BIT_VEC cppVar_91295 = PC + 1;
	cppVar_91295 = (cppVar_91295 & cppMask_un_16_);
	BIT_VEC cppVar_91296 = ROM.rd(cppVar_91295);
	BIT_VEC cppVar_91297 = (cppVar_91296 >> 7) & cppMask_un_1_;
	bool cppVar_91299 = (cppVar_91297 == 0);
	if (cppVar_91299) {
	BIT_VEC cppVar_91300 = PC + 1;
	cppVar_91300 = (cppVar_91300 & cppMask_un_16_);
	BIT_VEC cppVar_91301 = ROM.rd(cppVar_91300);
	BIT_VEC cppVar_91303 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_91305 = (cppVar_91303 << 3) | 1;
	cppVar_91305 = (cppVar_91305 & cppMask_un_5_);
	BIT_VEC cppVar_91306 = (0 << 5) | cppVar_91305;
	cppVar_91306 = (cppVar_91306 & cppMask_un_8_);
	BIT_VEC cppVar_91307 = IRAM.rd(cppVar_91306);
	BIT_VEC cppVar_91308 = IRAM.rd(cppVar_91307);
	type_mem cppVar_91309 = IRAM;
	cppVar_91309.wr(cppVar_91301, cppVar_91308);
	cppVar_91293 = cppVar_91309;
	} else {
	cppVar_91293 = IRAM;
	}
	cppVar_91289 = cppVar_91293;
	} else {
	type_mem cppVar_91310;
	BIT_VEC cppVar_91311 = ROM.rd(PC);
	bool cppVar_91313 = (cppVar_91311 == 134);
	if (cppVar_91313) {
	type_mem cppVar_91314;
	BIT_VEC cppVar_91316 = PC + 1;
	cppVar_91316 = (cppVar_91316 & cppMask_un_16_);
	BIT_VEC cppVar_91317 = ROM.rd(cppVar_91316);
	BIT_VEC cppVar_91318 = (cppVar_91317 >> 7) & cppMask_un_1_;
	bool cppVar_91320 = (cppVar_91318 == 0);
	if (cppVar_91320) {
	BIT_VEC cppVar_91321 = PC + 1;
	cppVar_91321 = (cppVar_91321 & cppMask_un_16_);
	BIT_VEC cppVar_91322 = ROM.rd(cppVar_91321);
	BIT_VEC cppVar_91324 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_91326 = (cppVar_91324 << 3) | 0;
	cppVar_91326 = (cppVar_91326 & cppMask_un_5_);
	BIT_VEC cppVar_91327 = (0 << 5) | cppVar_91326;
	cppVar_91327 = (cppVar_91327 & cppMask_un_8_);
	BIT_VEC cppVar_91328 = IRAM.rd(cppVar_91327);
	BIT_VEC cppVar_91329 = IRAM.rd(cppVar_91328);
	type_mem cppVar_91330 = IRAM;
	cppVar_91330.wr(cppVar_91322, cppVar_91329);
	cppVar_91314 = cppVar_91330;
	} else {
	cppVar_91314 = IRAM;
	}
	cppVar_91310 = cppVar_91314;
	} else {
	type_mem cppVar_91331;
	BIT_VEC cppVar_91332 = ROM.rd(PC);
	bool cppVar_91334 = (cppVar_91332 == 133);
	if (cppVar_91334) {
	type_mem cppVar_91335;
	BIT_VEC cppVar_91337 = PC + 2;
	cppVar_91337 = (cppVar_91337 & cppMask_un_16_);
	BIT_VEC cppVar_91338 = ROM.rd(cppVar_91337);
	BIT_VEC cppVar_91339 = (cppVar_91338 >> 7) & cppMask_un_1_;
	bool cppVar_91341 = (cppVar_91339 == 0);
	if (cppVar_91341) {
	BIT_VEC cppVar_91342 = PC + 2;
	cppVar_91342 = (cppVar_91342 & cppMask_un_16_);
	BIT_VEC cppVar_91343 = ROM.rd(cppVar_91342);
	BIT_VEC cppVar_91344;
	BIT_VEC cppVar_91346 = PC + 1;
	cppVar_91346 = (cppVar_91346 & cppMask_un_16_);
	BIT_VEC cppVar_91347 = ROM.rd(cppVar_91346);
	BIT_VEC cppVar_91348 = (cppVar_91347 >> 7) & cppMask_un_1_;
	bool cppVar_91350 = (cppVar_91348 == 0);
	if (cppVar_91350) {
	BIT_VEC cppVar_91351 = PC + 1;
	cppVar_91351 = (cppVar_91351 & cppMask_un_16_);
	BIT_VEC cppVar_91352 = ROM.rd(cppVar_91351);
	BIT_VEC cppVar_91353 = IRAM.rd(cppVar_91352);
	cppVar_91344 = cppVar_91353;
	} else {
	BIT_VEC cppVar_91354;
	BIT_VEC cppVar_91355 = PC + 1;
	cppVar_91355 = (cppVar_91355 & cppMask_un_16_);
	BIT_VEC cppVar_91356 = ROM.rd(cppVar_91355);
	bool cppVar_91358 = (cppVar_91356 == 128);
	if (cppVar_91358) {
	cppVar_91354 = P0;
	} else {
	BIT_VEC cppVar_91359;
	BIT_VEC cppVar_91360 = PC + 1;
	cppVar_91360 = (cppVar_91360 & cppMask_un_16_);
	BIT_VEC cppVar_91361 = ROM.rd(cppVar_91360);
	bool cppVar_91363 = (cppVar_91361 == 129);
	if (cppVar_91363) {
	cppVar_91359 = SP;
	} else {
	BIT_VEC cppVar_91364;
	BIT_VEC cppVar_91365 = PC + 1;
	cppVar_91365 = (cppVar_91365 & cppMask_un_16_);
	BIT_VEC cppVar_91366 = ROM.rd(cppVar_91365);
	bool cppVar_91368 = (cppVar_91366 == 130);
	if (cppVar_91368) {
	cppVar_91364 = DPL;
	} else {
	BIT_VEC cppVar_91369;
	BIT_VEC cppVar_91370 = PC + 1;
	cppVar_91370 = (cppVar_91370 & cppMask_un_16_);
	BIT_VEC cppVar_91371 = ROM.rd(cppVar_91370);
	bool cppVar_91373 = (cppVar_91371 == 131);
	if (cppVar_91373) {
	cppVar_91369 = DPH;
	} else {
	BIT_VEC cppVar_91374;
	BIT_VEC cppVar_91375 = PC + 1;
	cppVar_91375 = (cppVar_91375 & cppMask_un_16_);
	BIT_VEC cppVar_91376 = ROM.rd(cppVar_91375);
	bool cppVar_91378 = (cppVar_91376 == 135);
	if (cppVar_91378) {
	cppVar_91374 = PCON;
	} else {
	BIT_VEC cppVar_91379;
	BIT_VEC cppVar_91380 = PC + 1;
	cppVar_91380 = (cppVar_91380 & cppMask_un_16_);
	BIT_VEC cppVar_91381 = ROM.rd(cppVar_91380);
	bool cppVar_91383 = (cppVar_91381 == 136);
	if (cppVar_91383) {
	cppVar_91379 = TCON;
	} else {
	BIT_VEC cppVar_91384;
	BIT_VEC cppVar_91385 = PC + 1;
	cppVar_91385 = (cppVar_91385 & cppMask_un_16_);
	BIT_VEC cppVar_91386 = ROM.rd(cppVar_91385);
	bool cppVar_91388 = (cppVar_91386 == 137);
	if (cppVar_91388) {
	cppVar_91384 = TMOD;
	} else {
	BIT_VEC cppVar_91389;
	BIT_VEC cppVar_91390 = PC + 1;
	cppVar_91390 = (cppVar_91390 & cppMask_un_16_);
	BIT_VEC cppVar_91391 = ROM.rd(cppVar_91390);
	bool cppVar_91393 = (cppVar_91391 == 138);
	if (cppVar_91393) {
	cppVar_91389 = TL0;
	} else {
	BIT_VEC cppVar_91394;
	BIT_VEC cppVar_91395 = PC + 1;
	cppVar_91395 = (cppVar_91395 & cppMask_un_16_);
	BIT_VEC cppVar_91396 = ROM.rd(cppVar_91395);
	bool cppVar_91398 = (cppVar_91396 == 140);
	if (cppVar_91398) {
	cppVar_91394 = TH0;
	} else {
	BIT_VEC cppVar_91399;
	BIT_VEC cppVar_91400 = PC + 1;
	cppVar_91400 = (cppVar_91400 & cppMask_un_16_);
	BIT_VEC cppVar_91401 = ROM.rd(cppVar_91400);
	bool cppVar_91403 = (cppVar_91401 == 139);
	if (cppVar_91403) {
	cppVar_91399 = TL1;
	} else {
	BIT_VEC cppVar_91404;
	BIT_VEC cppVar_91405 = PC + 1;
	cppVar_91405 = (cppVar_91405 & cppMask_un_16_);
	BIT_VEC cppVar_91406 = ROM.rd(cppVar_91405);
	bool cppVar_91408 = (cppVar_91406 == 141);
	if (cppVar_91408) {
	cppVar_91404 = TH1;
	} else {
	BIT_VEC cppVar_91409;
	BIT_VEC cppVar_91410 = PC + 1;
	cppVar_91410 = (cppVar_91410 & cppMask_un_16_);
	BIT_VEC cppVar_91411 = ROM.rd(cppVar_91410);
	bool cppVar_91413 = (cppVar_91411 == 144);
	if (cppVar_91413) {
	cppVar_91409 = P1;
	} else {
	BIT_VEC cppVar_91414;
	BIT_VEC cppVar_91415 = PC + 1;
	cppVar_91415 = (cppVar_91415 & cppMask_un_16_);
	BIT_VEC cppVar_91416 = ROM.rd(cppVar_91415);
	bool cppVar_91418 = (cppVar_91416 == 152);
	if (cppVar_91418) {
	cppVar_91414 = SCON;
	} else {
	BIT_VEC cppVar_91419;
	BIT_VEC cppVar_91420 = PC + 1;
	cppVar_91420 = (cppVar_91420 & cppMask_un_16_);
	BIT_VEC cppVar_91421 = ROM.rd(cppVar_91420);
	bool cppVar_91423 = (cppVar_91421 == 153);
	if (cppVar_91423) {
	cppVar_91419 = SBUF;
	} else {
	BIT_VEC cppVar_91424;
	BIT_VEC cppVar_91425 = PC + 1;
	cppVar_91425 = (cppVar_91425 & cppMask_un_16_);
	BIT_VEC cppVar_91426 = ROM.rd(cppVar_91425);
	bool cppVar_91428 = (cppVar_91426 == 160);
	if (cppVar_91428) {
	cppVar_91424 = P2;
	} else {
	BIT_VEC cppVar_91429;
	BIT_VEC cppVar_91430 = PC + 1;
	cppVar_91430 = (cppVar_91430 & cppMask_un_16_);
	BIT_VEC cppVar_91431 = ROM.rd(cppVar_91430);
	bool cppVar_91433 = (cppVar_91431 == 168);
	if (cppVar_91433) {
	cppVar_91429 = IE;
	} else {
	BIT_VEC cppVar_91434;
	BIT_VEC cppVar_91435 = PC + 1;
	cppVar_91435 = (cppVar_91435 & cppMask_un_16_);
	BIT_VEC cppVar_91436 = ROM.rd(cppVar_91435);
	bool cppVar_91438 = (cppVar_91436 == 176);
	if (cppVar_91438) {
	cppVar_91434 = P3;
	} else {
	BIT_VEC cppVar_91439;
	BIT_VEC cppVar_91440 = PC + 1;
	cppVar_91440 = (cppVar_91440 & cppMask_un_16_);
	BIT_VEC cppVar_91441 = ROM.rd(cppVar_91440);
	bool cppVar_91443 = (cppVar_91441 == 184);
	if (cppVar_91443) {
	cppVar_91439 = IP;
	} else {
	BIT_VEC cppVar_91444;
	BIT_VEC cppVar_91445 = PC + 1;
	cppVar_91445 = (cppVar_91445 & cppMask_un_16_);
	BIT_VEC cppVar_91446 = ROM.rd(cppVar_91445);
	bool cppVar_91448 = (cppVar_91446 == 208);
	if (cppVar_91448) {
	cppVar_91444 = PSW;
	} else {
	BIT_VEC cppVar_91449;
	BIT_VEC cppVar_91450 = PC + 1;
	cppVar_91450 = (cppVar_91450 & cppMask_un_16_);
	BIT_VEC cppVar_91451 = ROM.rd(cppVar_91450);
	bool cppVar_91453 = (cppVar_91451 == 224);
	if (cppVar_91453) {
	cppVar_91449 = ACC;
	} else {
	BIT_VEC cppVar_91454;
	BIT_VEC cppVar_91455 = PC + 1;
	cppVar_91455 = (cppVar_91455 & cppMask_un_16_);
	BIT_VEC cppVar_91456 = ROM.rd(cppVar_91455);
	bool cppVar_91458 = (cppVar_91456 == 240);
	if (cppVar_91458) {
	cppVar_91454 = B;
	} else {
	cppVar_91454 = 0;
	}
	cppVar_91449 = cppVar_91454;
	}
	cppVar_91444 = cppVar_91449;
	}
	cppVar_91439 = cppVar_91444;
	}
	cppVar_91434 = cppVar_91439;
	}
	cppVar_91429 = cppVar_91434;
	}
	cppVar_91424 = cppVar_91429;
	}
	cppVar_91419 = cppVar_91424;
	}
	cppVar_91414 = cppVar_91419;
	}
	cppVar_91409 = cppVar_91414;
	}
	cppVar_91404 = cppVar_91409;
	}
	cppVar_91399 = cppVar_91404;
	}
	cppVar_91394 = cppVar_91399;
	}
	cppVar_91389 = cppVar_91394;
	}
	cppVar_91384 = cppVar_91389;
	}
	cppVar_91379 = cppVar_91384;
	}
	cppVar_91374 = cppVar_91379;
	}
	cppVar_91369 = cppVar_91374;
	}
	cppVar_91364 = cppVar_91369;
	}
	cppVar_91359 = cppVar_91364;
	}
	cppVar_91354 = cppVar_91359;
	}
	cppVar_91344 = cppVar_91354;
	}
	type_mem cppVar_91460 = IRAM;
	cppVar_91460.wr(cppVar_91343, cppVar_91344);
	cppVar_91335 = cppVar_91460;
	} else {
	cppVar_91335 = IRAM;
	}
	cppVar_91331 = cppVar_91335;
	} else {
	type_mem cppVar_91461;
	BIT_VEC cppVar_91462 = ROM.rd(PC);
	bool cppVar_91464 = (cppVar_91462 == 127);
	if (cppVar_91464) {
	type_mem cppVar_91465;
	BIT_VEC cppVar_91467 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_91469 = (cppVar_91467 << 3) | 7;
	cppVar_91469 = (cppVar_91469 & cppMask_un_5_);
	BIT_VEC cppVar_91470 = (0 << 5) | cppVar_91469;
	cppVar_91470 = (cppVar_91470 & cppMask_un_8_);
	BIT_VEC cppVar_91471 = (cppVar_91470 >> 7) & cppMask_un_1_;
	bool cppVar_91473 = (cppVar_91471 == 0);
	if (cppVar_91473) {
	BIT_VEC cppVar_91474 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_91475 = (cppVar_91474 << 3) | 7;
	cppVar_91475 = (cppVar_91475 & cppMask_un_5_);
	BIT_VEC cppVar_91476 = (0 << 5) | cppVar_91475;
	cppVar_91476 = (cppVar_91476 & cppMask_un_8_);
	BIT_VEC cppVar_91478 = PC + 1;
	cppVar_91478 = (cppVar_91478 & cppMask_un_16_);
	BIT_VEC cppVar_91479 = ROM.rd(cppVar_91478);
	type_mem cppVar_91480 = IRAM;
	cppVar_91480.wr(cppVar_91476, cppVar_91479);
	cppVar_91465 = cppVar_91480;
	} else {
	cppVar_91465 = IRAM;
	}
	cppVar_91461 = cppVar_91465;
	} else {
	type_mem cppVar_91481;
	BIT_VEC cppVar_91482 = ROM.rd(PC);
	bool cppVar_91484 = (cppVar_91482 == 126);
	if (cppVar_91484) {
	type_mem cppVar_91485;
	BIT_VEC cppVar_91487 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_91489 = (cppVar_91487 << 3) | 6;
	cppVar_91489 = (cppVar_91489 & cppMask_un_5_);
	BIT_VEC cppVar_91490 = (0 << 5) | cppVar_91489;
	cppVar_91490 = (cppVar_91490 & cppMask_un_8_);
	BIT_VEC cppVar_91491 = (cppVar_91490 >> 7) & cppMask_un_1_;
	bool cppVar_91493 = (cppVar_91491 == 0);
	if (cppVar_91493) {
	BIT_VEC cppVar_91494 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_91495 = (cppVar_91494 << 3) | 6;
	cppVar_91495 = (cppVar_91495 & cppMask_un_5_);
	BIT_VEC cppVar_91496 = (0 << 5) | cppVar_91495;
	cppVar_91496 = (cppVar_91496 & cppMask_un_8_);
	BIT_VEC cppVar_91498 = PC + 1;
	cppVar_91498 = (cppVar_91498 & cppMask_un_16_);
	BIT_VEC cppVar_91499 = ROM.rd(cppVar_91498);
	type_mem cppVar_91500 = IRAM;
	cppVar_91500.wr(cppVar_91496, cppVar_91499);
	cppVar_91485 = cppVar_91500;
	} else {
	cppVar_91485 = IRAM;
	}
	cppVar_91481 = cppVar_91485;
	} else {
	type_mem cppVar_91501;
	BIT_VEC cppVar_91502 = ROM.rd(PC);
	bool cppVar_91504 = (cppVar_91502 == 125);
	if (cppVar_91504) {
	type_mem cppVar_91505;
	BIT_VEC cppVar_91507 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_91509 = (cppVar_91507 << 3) | 5;
	cppVar_91509 = (cppVar_91509 & cppMask_un_5_);
	BIT_VEC cppVar_91510 = (0 << 5) | cppVar_91509;
	cppVar_91510 = (cppVar_91510 & cppMask_un_8_);
	BIT_VEC cppVar_91511 = (cppVar_91510 >> 7) & cppMask_un_1_;
	bool cppVar_91513 = (cppVar_91511 == 0);
	if (cppVar_91513) {
	BIT_VEC cppVar_91514 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_91515 = (cppVar_91514 << 3) | 5;
	cppVar_91515 = (cppVar_91515 & cppMask_un_5_);
	BIT_VEC cppVar_91516 = (0 << 5) | cppVar_91515;
	cppVar_91516 = (cppVar_91516 & cppMask_un_8_);
	BIT_VEC cppVar_91518 = PC + 1;
	cppVar_91518 = (cppVar_91518 & cppMask_un_16_);
	BIT_VEC cppVar_91519 = ROM.rd(cppVar_91518);
	type_mem cppVar_91520 = IRAM;
	cppVar_91520.wr(cppVar_91516, cppVar_91519);
	cppVar_91505 = cppVar_91520;
	} else {
	cppVar_91505 = IRAM;
	}
	cppVar_91501 = cppVar_91505;
	} else {
	type_mem cppVar_91521;
	BIT_VEC cppVar_91522 = ROM.rd(PC);
	bool cppVar_91524 = (cppVar_91522 == 124);
	if (cppVar_91524) {
	type_mem cppVar_91525;
	BIT_VEC cppVar_91527 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_91529 = (cppVar_91527 << 3) | 4;
	cppVar_91529 = (cppVar_91529 & cppMask_un_5_);
	BIT_VEC cppVar_91530 = (0 << 5) | cppVar_91529;
	cppVar_91530 = (cppVar_91530 & cppMask_un_8_);
	BIT_VEC cppVar_91531 = (cppVar_91530 >> 7) & cppMask_un_1_;
	bool cppVar_91533 = (cppVar_91531 == 0);
	if (cppVar_91533) {
	BIT_VEC cppVar_91534 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_91535 = (cppVar_91534 << 3) | 4;
	cppVar_91535 = (cppVar_91535 & cppMask_un_5_);
	BIT_VEC cppVar_91536 = (0 << 5) | cppVar_91535;
	cppVar_91536 = (cppVar_91536 & cppMask_un_8_);
	BIT_VEC cppVar_91538 = PC + 1;
	cppVar_91538 = (cppVar_91538 & cppMask_un_16_);
	BIT_VEC cppVar_91539 = ROM.rd(cppVar_91538);
	type_mem cppVar_91540 = IRAM;
	cppVar_91540.wr(cppVar_91536, cppVar_91539);
	cppVar_91525 = cppVar_91540;
	} else {
	cppVar_91525 = IRAM;
	}
	cppVar_91521 = cppVar_91525;
	} else {
	type_mem cppVar_91541;
	BIT_VEC cppVar_91542 = ROM.rd(PC);
	bool cppVar_91544 = (cppVar_91542 == 123);
	if (cppVar_91544) {
	type_mem cppVar_91545;
	BIT_VEC cppVar_91547 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_91549 = (cppVar_91547 << 3) | 3;
	cppVar_91549 = (cppVar_91549 & cppMask_un_5_);
	BIT_VEC cppVar_91550 = (0 << 5) | cppVar_91549;
	cppVar_91550 = (cppVar_91550 & cppMask_un_8_);
	BIT_VEC cppVar_91551 = (cppVar_91550 >> 7) & cppMask_un_1_;
	bool cppVar_91553 = (cppVar_91551 == 0);
	if (cppVar_91553) {
	BIT_VEC cppVar_91554 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_91555 = (cppVar_91554 << 3) | 3;
	cppVar_91555 = (cppVar_91555 & cppMask_un_5_);
	BIT_VEC cppVar_91556 = (0 << 5) | cppVar_91555;
	cppVar_91556 = (cppVar_91556 & cppMask_un_8_);
	BIT_VEC cppVar_91558 = PC + 1;
	cppVar_91558 = (cppVar_91558 & cppMask_un_16_);
	BIT_VEC cppVar_91559 = ROM.rd(cppVar_91558);
	type_mem cppVar_91560 = IRAM;
	cppVar_91560.wr(cppVar_91556, cppVar_91559);
	cppVar_91545 = cppVar_91560;
	} else {
	cppVar_91545 = IRAM;
	}
	cppVar_91541 = cppVar_91545;
	} else {
	type_mem cppVar_91561;
	BIT_VEC cppVar_91562 = ROM.rd(PC);
	bool cppVar_91564 = (cppVar_91562 == 122);
	if (cppVar_91564) {
	type_mem cppVar_91565;
	BIT_VEC cppVar_91567 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_91569 = (cppVar_91567 << 3) | 2;
	cppVar_91569 = (cppVar_91569 & cppMask_un_5_);
	BIT_VEC cppVar_91570 = (0 << 5) | cppVar_91569;
	cppVar_91570 = (cppVar_91570 & cppMask_un_8_);
	BIT_VEC cppVar_91571 = (cppVar_91570 >> 7) & cppMask_un_1_;
	bool cppVar_91573 = (cppVar_91571 == 0);
	if (cppVar_91573) {
	BIT_VEC cppVar_91574 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_91575 = (cppVar_91574 << 3) | 2;
	cppVar_91575 = (cppVar_91575 & cppMask_un_5_);
	BIT_VEC cppVar_91576 = (0 << 5) | cppVar_91575;
	cppVar_91576 = (cppVar_91576 & cppMask_un_8_);
	BIT_VEC cppVar_91578 = PC + 1;
	cppVar_91578 = (cppVar_91578 & cppMask_un_16_);
	BIT_VEC cppVar_91579 = ROM.rd(cppVar_91578);
	type_mem cppVar_91580 = IRAM;
	cppVar_91580.wr(cppVar_91576, cppVar_91579);
	cppVar_91565 = cppVar_91580;
	} else {
	cppVar_91565 = IRAM;
	}
	cppVar_91561 = cppVar_91565;
	} else {
	type_mem cppVar_91581;
	BIT_VEC cppVar_91582 = ROM.rd(PC);
	bool cppVar_91584 = (cppVar_91582 == 121);
	if (cppVar_91584) {
	type_mem cppVar_91585;
	BIT_VEC cppVar_91587 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_91589 = (cppVar_91587 << 3) | 1;
	cppVar_91589 = (cppVar_91589 & cppMask_un_5_);
	BIT_VEC cppVar_91590 = (0 << 5) | cppVar_91589;
	cppVar_91590 = (cppVar_91590 & cppMask_un_8_);
	BIT_VEC cppVar_91591 = (cppVar_91590 >> 7) & cppMask_un_1_;
	bool cppVar_91593 = (cppVar_91591 == 0);
	if (cppVar_91593) {
	BIT_VEC cppVar_91594 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_91595 = (cppVar_91594 << 3) | 1;
	cppVar_91595 = (cppVar_91595 & cppMask_un_5_);
	BIT_VEC cppVar_91596 = (0 << 5) | cppVar_91595;
	cppVar_91596 = (cppVar_91596 & cppMask_un_8_);
	BIT_VEC cppVar_91598 = PC + 1;
	cppVar_91598 = (cppVar_91598 & cppMask_un_16_);
	BIT_VEC cppVar_91599 = ROM.rd(cppVar_91598);
	type_mem cppVar_91600 = IRAM;
	cppVar_91600.wr(cppVar_91596, cppVar_91599);
	cppVar_91585 = cppVar_91600;
	} else {
	cppVar_91585 = IRAM;
	}
	cppVar_91581 = cppVar_91585;
	} else {
	type_mem cppVar_91601;
	BIT_VEC cppVar_91602 = ROM.rd(PC);
	bool cppVar_91604 = (cppVar_91602 == 120);
	if (cppVar_91604) {
	type_mem cppVar_91605;
	BIT_VEC cppVar_91607 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_91609 = (cppVar_91607 << 3) | 0;
	cppVar_91609 = (cppVar_91609 & cppMask_un_5_);
	BIT_VEC cppVar_91610 = (0 << 5) | cppVar_91609;
	cppVar_91610 = (cppVar_91610 & cppMask_un_8_);
	BIT_VEC cppVar_91611 = (cppVar_91610 >> 7) & cppMask_un_1_;
	bool cppVar_91613 = (cppVar_91611 == 0);
	if (cppVar_91613) {
	BIT_VEC cppVar_91614 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_91615 = (cppVar_91614 << 3) | 0;
	cppVar_91615 = (cppVar_91615 & cppMask_un_5_);
	BIT_VEC cppVar_91616 = (0 << 5) | cppVar_91615;
	cppVar_91616 = (cppVar_91616 & cppMask_un_8_);
	BIT_VEC cppVar_91618 = PC + 1;
	cppVar_91618 = (cppVar_91618 & cppMask_un_16_);
	BIT_VEC cppVar_91619 = ROM.rd(cppVar_91618);
	type_mem cppVar_91620 = IRAM;
	cppVar_91620.wr(cppVar_91616, cppVar_91619);
	cppVar_91605 = cppVar_91620;
	} else {
	cppVar_91605 = IRAM;
	}
	cppVar_91601 = cppVar_91605;
	} else {
	type_mem cppVar_91621;
	BIT_VEC cppVar_91622 = ROM.rd(PC);
	bool cppVar_91624 = (cppVar_91622 == 119);
	if (cppVar_91624) {
	BIT_VEC cppVar_91626 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_91628 = (cppVar_91626 << 3) | 1;
	cppVar_91628 = (cppVar_91628 & cppMask_un_5_);
	BIT_VEC cppVar_91629 = (0 << 5) | cppVar_91628;
	cppVar_91629 = (cppVar_91629 & cppMask_un_8_);
	BIT_VEC cppVar_91630 = IRAM.rd(cppVar_91629);
	BIT_VEC cppVar_91632 = PC + 1;
	cppVar_91632 = (cppVar_91632 & cppMask_un_16_);
	BIT_VEC cppVar_91633 = ROM.rd(cppVar_91632);
	type_mem cppVar_91634 = IRAM;
	cppVar_91634.wr(cppVar_91630, cppVar_91633);
	cppVar_91621 = cppVar_91634;
	} else {
	type_mem cppVar_91635;
	BIT_VEC cppVar_91636 = ROM.rd(PC);
	bool cppVar_91638 = (cppVar_91636 == 118);
	if (cppVar_91638) {
	BIT_VEC cppVar_91640 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_91642 = (cppVar_91640 << 3) | 0;
	cppVar_91642 = (cppVar_91642 & cppMask_un_5_);
	BIT_VEC cppVar_91643 = (0 << 5) | cppVar_91642;
	cppVar_91643 = (cppVar_91643 & cppMask_un_8_);
	BIT_VEC cppVar_91644 = IRAM.rd(cppVar_91643);
	BIT_VEC cppVar_91646 = PC + 1;
	cppVar_91646 = (cppVar_91646 & cppMask_un_16_);
	BIT_VEC cppVar_91647 = ROM.rd(cppVar_91646);
	type_mem cppVar_91648 = IRAM;
	cppVar_91648.wr(cppVar_91644, cppVar_91647);
	cppVar_91635 = cppVar_91648;
	} else {
	type_mem cppVar_91649;
	BIT_VEC cppVar_91650 = ROM.rd(PC);
	bool cppVar_91652 = (cppVar_91650 == 117);
	if (cppVar_91652) {
	type_mem cppVar_91653;
	BIT_VEC cppVar_91655 = PC + 1;
	cppVar_91655 = (cppVar_91655 & cppMask_un_16_);
	BIT_VEC cppVar_91656 = ROM.rd(cppVar_91655);
	BIT_VEC cppVar_91657 = (cppVar_91656 >> 7) & cppMask_un_1_;
	bool cppVar_91659 = (cppVar_91657 == 0);
	if (cppVar_91659) {
	BIT_VEC cppVar_91660 = PC + 1;
	cppVar_91660 = (cppVar_91660 & cppMask_un_16_);
	BIT_VEC cppVar_91661 = ROM.rd(cppVar_91660);
	BIT_VEC cppVar_91663 = PC + 2;
	cppVar_91663 = (cppVar_91663 & cppMask_un_16_);
	BIT_VEC cppVar_91664 = ROM.rd(cppVar_91663);
	type_mem cppVar_91665 = IRAM;
	cppVar_91665.wr(cppVar_91661, cppVar_91664);
	cppVar_91653 = cppVar_91665;
	} else {
	cppVar_91653 = IRAM;
	}
	cppVar_91649 = cppVar_91653;
	} else {
	type_mem cppVar_91666;
	BIT_VEC cppVar_91667 = ROM.rd(PC);
	bool cppVar_91669 = (cppVar_91667 == 99);
	if (cppVar_91669) {
	type_mem cppVar_91670;
	BIT_VEC cppVar_91672 = PC + 1;
	cppVar_91672 = (cppVar_91672 & cppMask_un_16_);
	BIT_VEC cppVar_91673 = ROM.rd(cppVar_91672);
	BIT_VEC cppVar_91674 = (cppVar_91673 >> 7) & cppMask_un_1_;
	bool cppVar_91676 = (cppVar_91674 == 0);
	if (cppVar_91676) {
	BIT_VEC cppVar_91677 = PC + 1;
	cppVar_91677 = (cppVar_91677 & cppMask_un_16_);
	BIT_VEC cppVar_91678 = ROM.rd(cppVar_91677);
	BIT_VEC cppVar_91679;
	BIT_VEC cppVar_91680 = PC + 1;
	cppVar_91680 = (cppVar_91680 & cppMask_un_16_);
	BIT_VEC cppVar_91681 = ROM.rd(cppVar_91680);
	BIT_VEC cppVar_91682 = (cppVar_91681 >> 7) & cppMask_un_1_;
	bool cppVar_91684 = (cppVar_91682 == 0);
	if (cppVar_91684) {
	BIT_VEC cppVar_91685 = PC + 1;
	cppVar_91685 = (cppVar_91685 & cppMask_un_16_);
	BIT_VEC cppVar_91686 = ROM.rd(cppVar_91685);
	BIT_VEC cppVar_91687 = IRAM.rd(cppVar_91686);
	cppVar_91679 = cppVar_91687;
	} else {
	BIT_VEC cppVar_91688;
	BIT_VEC cppVar_91689 = PC + 1;
	cppVar_91689 = (cppVar_91689 & cppMask_un_16_);
	BIT_VEC cppVar_91690 = ROM.rd(cppVar_91689);
	bool cppVar_91692 = (cppVar_91690 == 128);
	if (cppVar_91692) {
	cppVar_91688 = P0;
	} else {
	BIT_VEC cppVar_91693;
	BIT_VEC cppVar_91694 = PC + 1;
	cppVar_91694 = (cppVar_91694 & cppMask_un_16_);
	BIT_VEC cppVar_91695 = ROM.rd(cppVar_91694);
	bool cppVar_91697 = (cppVar_91695 == 129);
	if (cppVar_91697) {
	cppVar_91693 = SP;
	} else {
	BIT_VEC cppVar_91698;
	BIT_VEC cppVar_91699 = PC + 1;
	cppVar_91699 = (cppVar_91699 & cppMask_un_16_);
	BIT_VEC cppVar_91700 = ROM.rd(cppVar_91699);
	bool cppVar_91702 = (cppVar_91700 == 130);
	if (cppVar_91702) {
	cppVar_91698 = DPL;
	} else {
	BIT_VEC cppVar_91703;
	BIT_VEC cppVar_91704 = PC + 1;
	cppVar_91704 = (cppVar_91704 & cppMask_un_16_);
	BIT_VEC cppVar_91705 = ROM.rd(cppVar_91704);
	bool cppVar_91707 = (cppVar_91705 == 131);
	if (cppVar_91707) {
	cppVar_91703 = DPH;
	} else {
	BIT_VEC cppVar_91708;
	BIT_VEC cppVar_91709 = PC + 1;
	cppVar_91709 = (cppVar_91709 & cppMask_un_16_);
	BIT_VEC cppVar_91710 = ROM.rd(cppVar_91709);
	bool cppVar_91712 = (cppVar_91710 == 135);
	if (cppVar_91712) {
	cppVar_91708 = PCON;
	} else {
	BIT_VEC cppVar_91713;
	BIT_VEC cppVar_91714 = PC + 1;
	cppVar_91714 = (cppVar_91714 & cppMask_un_16_);
	BIT_VEC cppVar_91715 = ROM.rd(cppVar_91714);
	bool cppVar_91717 = (cppVar_91715 == 136);
	if (cppVar_91717) {
	cppVar_91713 = TCON;
	} else {
	BIT_VEC cppVar_91718;
	BIT_VEC cppVar_91719 = PC + 1;
	cppVar_91719 = (cppVar_91719 & cppMask_un_16_);
	BIT_VEC cppVar_91720 = ROM.rd(cppVar_91719);
	bool cppVar_91722 = (cppVar_91720 == 137);
	if (cppVar_91722) {
	cppVar_91718 = TMOD;
	} else {
	BIT_VEC cppVar_91723;
	BIT_VEC cppVar_91724 = PC + 1;
	cppVar_91724 = (cppVar_91724 & cppMask_un_16_);
	BIT_VEC cppVar_91725 = ROM.rd(cppVar_91724);
	bool cppVar_91727 = (cppVar_91725 == 138);
	if (cppVar_91727) {
	cppVar_91723 = TL0;
	} else {
	BIT_VEC cppVar_91728;
	BIT_VEC cppVar_91729 = PC + 1;
	cppVar_91729 = (cppVar_91729 & cppMask_un_16_);
	BIT_VEC cppVar_91730 = ROM.rd(cppVar_91729);
	bool cppVar_91732 = (cppVar_91730 == 140);
	if (cppVar_91732) {
	cppVar_91728 = TH0;
	} else {
	BIT_VEC cppVar_91733;
	BIT_VEC cppVar_91734 = PC + 1;
	cppVar_91734 = (cppVar_91734 & cppMask_un_16_);
	BIT_VEC cppVar_91735 = ROM.rd(cppVar_91734);
	bool cppVar_91737 = (cppVar_91735 == 139);
	if (cppVar_91737) {
	cppVar_91733 = TL1;
	} else {
	BIT_VEC cppVar_91738;
	BIT_VEC cppVar_91739 = PC + 1;
	cppVar_91739 = (cppVar_91739 & cppMask_un_16_);
	BIT_VEC cppVar_91740 = ROM.rd(cppVar_91739);
	bool cppVar_91742 = (cppVar_91740 == 141);
	if (cppVar_91742) {
	cppVar_91738 = TH1;
	} else {
	BIT_VEC cppVar_91743;
	BIT_VEC cppVar_91744 = PC + 1;
	cppVar_91744 = (cppVar_91744 & cppMask_un_16_);
	BIT_VEC cppVar_91745 = ROM.rd(cppVar_91744);
	bool cppVar_91747 = (cppVar_91745 == 144);
	if (cppVar_91747) {
	cppVar_91743 = P1;
	} else {
	BIT_VEC cppVar_91748;
	BIT_VEC cppVar_91749 = PC + 1;
	cppVar_91749 = (cppVar_91749 & cppMask_un_16_);
	BIT_VEC cppVar_91750 = ROM.rd(cppVar_91749);
	bool cppVar_91752 = (cppVar_91750 == 152);
	if (cppVar_91752) {
	cppVar_91748 = SCON;
	} else {
	BIT_VEC cppVar_91753;
	BIT_VEC cppVar_91754 = PC + 1;
	cppVar_91754 = (cppVar_91754 & cppMask_un_16_);
	BIT_VEC cppVar_91755 = ROM.rd(cppVar_91754);
	bool cppVar_91757 = (cppVar_91755 == 153);
	if (cppVar_91757) {
	cppVar_91753 = SBUF;
	} else {
	BIT_VEC cppVar_91758;
	BIT_VEC cppVar_91759 = PC + 1;
	cppVar_91759 = (cppVar_91759 & cppMask_un_16_);
	BIT_VEC cppVar_91760 = ROM.rd(cppVar_91759);
	bool cppVar_91762 = (cppVar_91760 == 160);
	if (cppVar_91762) {
	cppVar_91758 = P2;
	} else {
	BIT_VEC cppVar_91763;
	BIT_VEC cppVar_91764 = PC + 1;
	cppVar_91764 = (cppVar_91764 & cppMask_un_16_);
	BIT_VEC cppVar_91765 = ROM.rd(cppVar_91764);
	bool cppVar_91767 = (cppVar_91765 == 168);
	if (cppVar_91767) {
	cppVar_91763 = IE;
	} else {
	BIT_VEC cppVar_91768;
	BIT_VEC cppVar_91769 = PC + 1;
	cppVar_91769 = (cppVar_91769 & cppMask_un_16_);
	BIT_VEC cppVar_91770 = ROM.rd(cppVar_91769);
	bool cppVar_91772 = (cppVar_91770 == 176);
	if (cppVar_91772) {
	cppVar_91768 = P3;
	} else {
	BIT_VEC cppVar_91773;
	BIT_VEC cppVar_91774 = PC + 1;
	cppVar_91774 = (cppVar_91774 & cppMask_un_16_);
	BIT_VEC cppVar_91775 = ROM.rd(cppVar_91774);
	bool cppVar_91777 = (cppVar_91775 == 184);
	if (cppVar_91777) {
	cppVar_91773 = IP;
	} else {
	BIT_VEC cppVar_91778;
	BIT_VEC cppVar_91779 = PC + 1;
	cppVar_91779 = (cppVar_91779 & cppMask_un_16_);
	BIT_VEC cppVar_91780 = ROM.rd(cppVar_91779);
	bool cppVar_91782 = (cppVar_91780 == 208);
	if (cppVar_91782) {
	cppVar_91778 = PSW;
	} else {
	BIT_VEC cppVar_91783;
	BIT_VEC cppVar_91784 = PC + 1;
	cppVar_91784 = (cppVar_91784 & cppMask_un_16_);
	BIT_VEC cppVar_91785 = ROM.rd(cppVar_91784);
	bool cppVar_91787 = (cppVar_91785 == 224);
	if (cppVar_91787) {
	cppVar_91783 = ACC;
	} else {
	BIT_VEC cppVar_91788;
	BIT_VEC cppVar_91789 = PC + 1;
	cppVar_91789 = (cppVar_91789 & cppMask_un_16_);
	BIT_VEC cppVar_91790 = ROM.rd(cppVar_91789);
	bool cppVar_91792 = (cppVar_91790 == 240);
	if (cppVar_91792) {
	cppVar_91788 = B;
	} else {
	cppVar_91788 = 0;
	}
	cppVar_91783 = cppVar_91788;
	}
	cppVar_91778 = cppVar_91783;
	}
	cppVar_91773 = cppVar_91778;
	}
	cppVar_91768 = cppVar_91773;
	}
	cppVar_91763 = cppVar_91768;
	}
	cppVar_91758 = cppVar_91763;
	}
	cppVar_91753 = cppVar_91758;
	}
	cppVar_91748 = cppVar_91753;
	}
	cppVar_91743 = cppVar_91748;
	}
	cppVar_91738 = cppVar_91743;
	}
	cppVar_91733 = cppVar_91738;
	}
	cppVar_91728 = cppVar_91733;
	}
	cppVar_91723 = cppVar_91728;
	}
	cppVar_91718 = cppVar_91723;
	}
	cppVar_91713 = cppVar_91718;
	}
	cppVar_91708 = cppVar_91713;
	}
	cppVar_91703 = cppVar_91708;
	}
	cppVar_91698 = cppVar_91703;
	}
	cppVar_91693 = cppVar_91698;
	}
	cppVar_91688 = cppVar_91693;
	}
	cppVar_91679 = cppVar_91688;
	}
	BIT_VEC cppVar_91795 = PC + 2;
	cppVar_91795 = (cppVar_91795 & cppMask_un_16_);
	BIT_VEC cppVar_91796 = ROM.rd(cppVar_91795);
	BIT_VEC cppVar_91797 = cppVar_91679 ^ cppVar_91796;
	type_mem cppVar_91798 = IRAM;
	cppVar_91798.wr(cppVar_91678, cppVar_91797);
	cppVar_91670 = cppVar_91798;
	} else {
	cppVar_91670 = IRAM;
	}
	cppVar_91666 = cppVar_91670;
	} else {
	type_mem cppVar_91799;
	BIT_VEC cppVar_91800 = ROM.rd(PC);
	bool cppVar_91802 = (cppVar_91800 == 98);
	if (cppVar_91802) {
	type_mem cppVar_91803;
	BIT_VEC cppVar_91805 = PC + 1;
	cppVar_91805 = (cppVar_91805 & cppMask_un_16_);
	BIT_VEC cppVar_91806 = ROM.rd(cppVar_91805);
	BIT_VEC cppVar_91807 = (cppVar_91806 >> 7) & cppMask_un_1_;
	bool cppVar_91809 = (cppVar_91807 == 0);
	if (cppVar_91809) {
	BIT_VEC cppVar_91810 = PC + 1;
	cppVar_91810 = (cppVar_91810 & cppMask_un_16_);
	BIT_VEC cppVar_91811 = ROM.rd(cppVar_91810);
	BIT_VEC cppVar_91812;
	BIT_VEC cppVar_91813 = PC + 1;
	cppVar_91813 = (cppVar_91813 & cppMask_un_16_);
	BIT_VEC cppVar_91814 = ROM.rd(cppVar_91813);
	BIT_VEC cppVar_91815 = (cppVar_91814 >> 7) & cppMask_un_1_;
	bool cppVar_91817 = (cppVar_91815 == 0);
	if (cppVar_91817) {
	BIT_VEC cppVar_91818 = PC + 1;
	cppVar_91818 = (cppVar_91818 & cppMask_un_16_);
	BIT_VEC cppVar_91819 = ROM.rd(cppVar_91818);
	BIT_VEC cppVar_91820 = IRAM.rd(cppVar_91819);
	cppVar_91812 = cppVar_91820;
	} else {
	BIT_VEC cppVar_91821;
	BIT_VEC cppVar_91822 = PC + 1;
	cppVar_91822 = (cppVar_91822 & cppMask_un_16_);
	BIT_VEC cppVar_91823 = ROM.rd(cppVar_91822);
	bool cppVar_91825 = (cppVar_91823 == 128);
	if (cppVar_91825) {
	cppVar_91821 = P0;
	} else {
	BIT_VEC cppVar_91826;
	BIT_VEC cppVar_91827 = PC + 1;
	cppVar_91827 = (cppVar_91827 & cppMask_un_16_);
	BIT_VEC cppVar_91828 = ROM.rd(cppVar_91827);
	bool cppVar_91830 = (cppVar_91828 == 129);
	if (cppVar_91830) {
	cppVar_91826 = SP;
	} else {
	BIT_VEC cppVar_91831;
	BIT_VEC cppVar_91832 = PC + 1;
	cppVar_91832 = (cppVar_91832 & cppMask_un_16_);
	BIT_VEC cppVar_91833 = ROM.rd(cppVar_91832);
	bool cppVar_91835 = (cppVar_91833 == 130);
	if (cppVar_91835) {
	cppVar_91831 = DPL;
	} else {
	BIT_VEC cppVar_91836;
	BIT_VEC cppVar_91837 = PC + 1;
	cppVar_91837 = (cppVar_91837 & cppMask_un_16_);
	BIT_VEC cppVar_91838 = ROM.rd(cppVar_91837);
	bool cppVar_91840 = (cppVar_91838 == 131);
	if (cppVar_91840) {
	cppVar_91836 = DPH;
	} else {
	BIT_VEC cppVar_91841;
	BIT_VEC cppVar_91842 = PC + 1;
	cppVar_91842 = (cppVar_91842 & cppMask_un_16_);
	BIT_VEC cppVar_91843 = ROM.rd(cppVar_91842);
	bool cppVar_91845 = (cppVar_91843 == 135);
	if (cppVar_91845) {
	cppVar_91841 = PCON;
	} else {
	BIT_VEC cppVar_91846;
	BIT_VEC cppVar_91847 = PC + 1;
	cppVar_91847 = (cppVar_91847 & cppMask_un_16_);
	BIT_VEC cppVar_91848 = ROM.rd(cppVar_91847);
	bool cppVar_91850 = (cppVar_91848 == 136);
	if (cppVar_91850) {
	cppVar_91846 = TCON;
	} else {
	BIT_VEC cppVar_91851;
	BIT_VEC cppVar_91852 = PC + 1;
	cppVar_91852 = (cppVar_91852 & cppMask_un_16_);
	BIT_VEC cppVar_91853 = ROM.rd(cppVar_91852);
	bool cppVar_91855 = (cppVar_91853 == 137);
	if (cppVar_91855) {
	cppVar_91851 = TMOD;
	} else {
	BIT_VEC cppVar_91856;
	BIT_VEC cppVar_91857 = PC + 1;
	cppVar_91857 = (cppVar_91857 & cppMask_un_16_);
	BIT_VEC cppVar_91858 = ROM.rd(cppVar_91857);
	bool cppVar_91860 = (cppVar_91858 == 138);
	if (cppVar_91860) {
	cppVar_91856 = TL0;
	} else {
	BIT_VEC cppVar_91861;
	BIT_VEC cppVar_91862 = PC + 1;
	cppVar_91862 = (cppVar_91862 & cppMask_un_16_);
	BIT_VEC cppVar_91863 = ROM.rd(cppVar_91862);
	bool cppVar_91865 = (cppVar_91863 == 140);
	if (cppVar_91865) {
	cppVar_91861 = TH0;
	} else {
	BIT_VEC cppVar_91866;
	BIT_VEC cppVar_91867 = PC + 1;
	cppVar_91867 = (cppVar_91867 & cppMask_un_16_);
	BIT_VEC cppVar_91868 = ROM.rd(cppVar_91867);
	bool cppVar_91870 = (cppVar_91868 == 139);
	if (cppVar_91870) {
	cppVar_91866 = TL1;
	} else {
	BIT_VEC cppVar_91871;
	BIT_VEC cppVar_91872 = PC + 1;
	cppVar_91872 = (cppVar_91872 & cppMask_un_16_);
	BIT_VEC cppVar_91873 = ROM.rd(cppVar_91872);
	bool cppVar_91875 = (cppVar_91873 == 141);
	if (cppVar_91875) {
	cppVar_91871 = TH1;
	} else {
	BIT_VEC cppVar_91876;
	BIT_VEC cppVar_91877 = PC + 1;
	cppVar_91877 = (cppVar_91877 & cppMask_un_16_);
	BIT_VEC cppVar_91878 = ROM.rd(cppVar_91877);
	bool cppVar_91880 = (cppVar_91878 == 144);
	if (cppVar_91880) {
	cppVar_91876 = P1;
	} else {
	BIT_VEC cppVar_91881;
	BIT_VEC cppVar_91882 = PC + 1;
	cppVar_91882 = (cppVar_91882 & cppMask_un_16_);
	BIT_VEC cppVar_91883 = ROM.rd(cppVar_91882);
	bool cppVar_91885 = (cppVar_91883 == 152);
	if (cppVar_91885) {
	cppVar_91881 = SCON;
	} else {
	BIT_VEC cppVar_91886;
	BIT_VEC cppVar_91887 = PC + 1;
	cppVar_91887 = (cppVar_91887 & cppMask_un_16_);
	BIT_VEC cppVar_91888 = ROM.rd(cppVar_91887);
	bool cppVar_91890 = (cppVar_91888 == 153);
	if (cppVar_91890) {
	cppVar_91886 = SBUF;
	} else {
	BIT_VEC cppVar_91891;
	BIT_VEC cppVar_91892 = PC + 1;
	cppVar_91892 = (cppVar_91892 & cppMask_un_16_);
	BIT_VEC cppVar_91893 = ROM.rd(cppVar_91892);
	bool cppVar_91895 = (cppVar_91893 == 160);
	if (cppVar_91895) {
	cppVar_91891 = P2;
	} else {
	BIT_VEC cppVar_91896;
	BIT_VEC cppVar_91897 = PC + 1;
	cppVar_91897 = (cppVar_91897 & cppMask_un_16_);
	BIT_VEC cppVar_91898 = ROM.rd(cppVar_91897);
	bool cppVar_91900 = (cppVar_91898 == 168);
	if (cppVar_91900) {
	cppVar_91896 = IE;
	} else {
	BIT_VEC cppVar_91901;
	BIT_VEC cppVar_91902 = PC + 1;
	cppVar_91902 = (cppVar_91902 & cppMask_un_16_);
	BIT_VEC cppVar_91903 = ROM.rd(cppVar_91902);
	bool cppVar_91905 = (cppVar_91903 == 176);
	if (cppVar_91905) {
	cppVar_91901 = P3;
	} else {
	BIT_VEC cppVar_91906;
	BIT_VEC cppVar_91907 = PC + 1;
	cppVar_91907 = (cppVar_91907 & cppMask_un_16_);
	BIT_VEC cppVar_91908 = ROM.rd(cppVar_91907);
	bool cppVar_91910 = (cppVar_91908 == 184);
	if (cppVar_91910) {
	cppVar_91906 = IP;
	} else {
	BIT_VEC cppVar_91911;
	BIT_VEC cppVar_91912 = PC + 1;
	cppVar_91912 = (cppVar_91912 & cppMask_un_16_);
	BIT_VEC cppVar_91913 = ROM.rd(cppVar_91912);
	bool cppVar_91915 = (cppVar_91913 == 208);
	if (cppVar_91915) {
	cppVar_91911 = PSW;
	} else {
	BIT_VEC cppVar_91916;
	BIT_VEC cppVar_91917 = PC + 1;
	cppVar_91917 = (cppVar_91917 & cppMask_un_16_);
	BIT_VEC cppVar_91918 = ROM.rd(cppVar_91917);
	bool cppVar_91920 = (cppVar_91918 == 224);
	if (cppVar_91920) {
	cppVar_91916 = ACC;
	} else {
	BIT_VEC cppVar_91921;
	BIT_VEC cppVar_91922 = PC + 1;
	cppVar_91922 = (cppVar_91922 & cppMask_un_16_);
	BIT_VEC cppVar_91923 = ROM.rd(cppVar_91922);
	bool cppVar_91925 = (cppVar_91923 == 240);
	if (cppVar_91925) {
	cppVar_91921 = B;
	} else {
	cppVar_91921 = 0;
	}
	cppVar_91916 = cppVar_91921;
	}
	cppVar_91911 = cppVar_91916;
	}
	cppVar_91906 = cppVar_91911;
	}
	cppVar_91901 = cppVar_91906;
	}
	cppVar_91896 = cppVar_91901;
	}
	cppVar_91891 = cppVar_91896;
	}
	cppVar_91886 = cppVar_91891;
	}
	cppVar_91881 = cppVar_91886;
	}
	cppVar_91876 = cppVar_91881;
	}
	cppVar_91871 = cppVar_91876;
	}
	cppVar_91866 = cppVar_91871;
	}
	cppVar_91861 = cppVar_91866;
	}
	cppVar_91856 = cppVar_91861;
	}
	cppVar_91851 = cppVar_91856;
	}
	cppVar_91846 = cppVar_91851;
	}
	cppVar_91841 = cppVar_91846;
	}
	cppVar_91836 = cppVar_91841;
	}
	cppVar_91831 = cppVar_91836;
	}
	cppVar_91826 = cppVar_91831;
	}
	cppVar_91821 = cppVar_91826;
	}
	cppVar_91812 = cppVar_91821;
	}
	BIT_VEC cppVar_91927 = cppVar_91812 ^ ACC;
	type_mem cppVar_91928 = IRAM;
	cppVar_91928.wr(cppVar_91811, cppVar_91927);
	cppVar_91803 = cppVar_91928;
	} else {
	cppVar_91803 = IRAM;
	}
	cppVar_91799 = cppVar_91803;
	} else {
	type_mem cppVar_91929;
	BIT_VEC cppVar_91930 = ROM.rd(PC);
	bool cppVar_91932 = (cppVar_91930 == 83);
	if (cppVar_91932) {
	type_mem cppVar_91933;
	BIT_VEC cppVar_91935 = PC + 1;
	cppVar_91935 = (cppVar_91935 & cppMask_un_16_);
	BIT_VEC cppVar_91936 = ROM.rd(cppVar_91935);
	BIT_VEC cppVar_91937 = (cppVar_91936 >> 7) & cppMask_un_1_;
	bool cppVar_91939 = (cppVar_91937 == 0);
	if (cppVar_91939) {
	BIT_VEC cppVar_91940 = PC + 1;
	cppVar_91940 = (cppVar_91940 & cppMask_un_16_);
	BIT_VEC cppVar_91941 = ROM.rd(cppVar_91940);
	BIT_VEC cppVar_91942;
	BIT_VEC cppVar_91943 = PC + 1;
	cppVar_91943 = (cppVar_91943 & cppMask_un_16_);
	BIT_VEC cppVar_91944 = ROM.rd(cppVar_91943);
	BIT_VEC cppVar_91945 = (cppVar_91944 >> 7) & cppMask_un_1_;
	bool cppVar_91947 = (cppVar_91945 == 0);
	if (cppVar_91947) {
	BIT_VEC cppVar_91948 = PC + 1;
	cppVar_91948 = (cppVar_91948 & cppMask_un_16_);
	BIT_VEC cppVar_91949 = ROM.rd(cppVar_91948);
	BIT_VEC cppVar_91950 = IRAM.rd(cppVar_91949);
	cppVar_91942 = cppVar_91950;
	} else {
	BIT_VEC cppVar_91951;
	BIT_VEC cppVar_91952 = PC + 1;
	cppVar_91952 = (cppVar_91952 & cppMask_un_16_);
	BIT_VEC cppVar_91953 = ROM.rd(cppVar_91952);
	bool cppVar_91955 = (cppVar_91953 == 128);
	if (cppVar_91955) {
	cppVar_91951 = P0;
	} else {
	BIT_VEC cppVar_91956;
	BIT_VEC cppVar_91957 = PC + 1;
	cppVar_91957 = (cppVar_91957 & cppMask_un_16_);
	BIT_VEC cppVar_91958 = ROM.rd(cppVar_91957);
	bool cppVar_91960 = (cppVar_91958 == 129);
	if (cppVar_91960) {
	cppVar_91956 = SP;
	} else {
	BIT_VEC cppVar_91961;
	BIT_VEC cppVar_91962 = PC + 1;
	cppVar_91962 = (cppVar_91962 & cppMask_un_16_);
	BIT_VEC cppVar_91963 = ROM.rd(cppVar_91962);
	bool cppVar_91965 = (cppVar_91963 == 130);
	if (cppVar_91965) {
	cppVar_91961 = DPL;
	} else {
	BIT_VEC cppVar_91966;
	BIT_VEC cppVar_91967 = PC + 1;
	cppVar_91967 = (cppVar_91967 & cppMask_un_16_);
	BIT_VEC cppVar_91968 = ROM.rd(cppVar_91967);
	bool cppVar_91970 = (cppVar_91968 == 131);
	if (cppVar_91970) {
	cppVar_91966 = DPH;
	} else {
	BIT_VEC cppVar_91971;
	BIT_VEC cppVar_91972 = PC + 1;
	cppVar_91972 = (cppVar_91972 & cppMask_un_16_);
	BIT_VEC cppVar_91973 = ROM.rd(cppVar_91972);
	bool cppVar_91975 = (cppVar_91973 == 135);
	if (cppVar_91975) {
	cppVar_91971 = PCON;
	} else {
	BIT_VEC cppVar_91976;
	BIT_VEC cppVar_91977 = PC + 1;
	cppVar_91977 = (cppVar_91977 & cppMask_un_16_);
	BIT_VEC cppVar_91978 = ROM.rd(cppVar_91977);
	bool cppVar_91980 = (cppVar_91978 == 136);
	if (cppVar_91980) {
	cppVar_91976 = TCON;
	} else {
	BIT_VEC cppVar_91981;
	BIT_VEC cppVar_91982 = PC + 1;
	cppVar_91982 = (cppVar_91982 & cppMask_un_16_);
	BIT_VEC cppVar_91983 = ROM.rd(cppVar_91982);
	bool cppVar_91985 = (cppVar_91983 == 137);
	if (cppVar_91985) {
	cppVar_91981 = TMOD;
	} else {
	BIT_VEC cppVar_91986;
	BIT_VEC cppVar_91987 = PC + 1;
	cppVar_91987 = (cppVar_91987 & cppMask_un_16_);
	BIT_VEC cppVar_91988 = ROM.rd(cppVar_91987);
	bool cppVar_91990 = (cppVar_91988 == 138);
	if (cppVar_91990) {
	cppVar_91986 = TL0;
	} else {
	BIT_VEC cppVar_91991;
	BIT_VEC cppVar_91992 = PC + 1;
	cppVar_91992 = (cppVar_91992 & cppMask_un_16_);
	BIT_VEC cppVar_91993 = ROM.rd(cppVar_91992);
	bool cppVar_91995 = (cppVar_91993 == 140);
	if (cppVar_91995) {
	cppVar_91991 = TH0;
	} else {
	BIT_VEC cppVar_91996;
	BIT_VEC cppVar_91997 = PC + 1;
	cppVar_91997 = (cppVar_91997 & cppMask_un_16_);
	BIT_VEC cppVar_91998 = ROM.rd(cppVar_91997);
	bool cppVar_92000 = (cppVar_91998 == 139);
	if (cppVar_92000) {
	cppVar_91996 = TL1;
	} else {
	BIT_VEC cppVar_92001;
	BIT_VEC cppVar_92002 = PC + 1;
	cppVar_92002 = (cppVar_92002 & cppMask_un_16_);
	BIT_VEC cppVar_92003 = ROM.rd(cppVar_92002);
	bool cppVar_92005 = (cppVar_92003 == 141);
	if (cppVar_92005) {
	cppVar_92001 = TH1;
	} else {
	BIT_VEC cppVar_92006;
	BIT_VEC cppVar_92007 = PC + 1;
	cppVar_92007 = (cppVar_92007 & cppMask_un_16_);
	BIT_VEC cppVar_92008 = ROM.rd(cppVar_92007);
	bool cppVar_92010 = (cppVar_92008 == 144);
	if (cppVar_92010) {
	cppVar_92006 = P1;
	} else {
	BIT_VEC cppVar_92011;
	BIT_VEC cppVar_92012 = PC + 1;
	cppVar_92012 = (cppVar_92012 & cppMask_un_16_);
	BIT_VEC cppVar_92013 = ROM.rd(cppVar_92012);
	bool cppVar_92015 = (cppVar_92013 == 152);
	if (cppVar_92015) {
	cppVar_92011 = SCON;
	} else {
	BIT_VEC cppVar_92016;
	BIT_VEC cppVar_92017 = PC + 1;
	cppVar_92017 = (cppVar_92017 & cppMask_un_16_);
	BIT_VEC cppVar_92018 = ROM.rd(cppVar_92017);
	bool cppVar_92020 = (cppVar_92018 == 153);
	if (cppVar_92020) {
	cppVar_92016 = SBUF;
	} else {
	BIT_VEC cppVar_92021;
	BIT_VEC cppVar_92022 = PC + 1;
	cppVar_92022 = (cppVar_92022 & cppMask_un_16_);
	BIT_VEC cppVar_92023 = ROM.rd(cppVar_92022);
	bool cppVar_92025 = (cppVar_92023 == 160);
	if (cppVar_92025) {
	cppVar_92021 = P2;
	} else {
	BIT_VEC cppVar_92026;
	BIT_VEC cppVar_92027 = PC + 1;
	cppVar_92027 = (cppVar_92027 & cppMask_un_16_);
	BIT_VEC cppVar_92028 = ROM.rd(cppVar_92027);
	bool cppVar_92030 = (cppVar_92028 == 168);
	if (cppVar_92030) {
	cppVar_92026 = IE;
	} else {
	BIT_VEC cppVar_92031;
	BIT_VEC cppVar_92032 = PC + 1;
	cppVar_92032 = (cppVar_92032 & cppMask_un_16_);
	BIT_VEC cppVar_92033 = ROM.rd(cppVar_92032);
	bool cppVar_92035 = (cppVar_92033 == 176);
	if (cppVar_92035) {
	cppVar_92031 = P3;
	} else {
	BIT_VEC cppVar_92036;
	BIT_VEC cppVar_92037 = PC + 1;
	cppVar_92037 = (cppVar_92037 & cppMask_un_16_);
	BIT_VEC cppVar_92038 = ROM.rd(cppVar_92037);
	bool cppVar_92040 = (cppVar_92038 == 184);
	if (cppVar_92040) {
	cppVar_92036 = IP;
	} else {
	BIT_VEC cppVar_92041;
	BIT_VEC cppVar_92042 = PC + 1;
	cppVar_92042 = (cppVar_92042 & cppMask_un_16_);
	BIT_VEC cppVar_92043 = ROM.rd(cppVar_92042);
	bool cppVar_92045 = (cppVar_92043 == 208);
	if (cppVar_92045) {
	cppVar_92041 = PSW;
	} else {
	BIT_VEC cppVar_92046;
	BIT_VEC cppVar_92047 = PC + 1;
	cppVar_92047 = (cppVar_92047 & cppMask_un_16_);
	BIT_VEC cppVar_92048 = ROM.rd(cppVar_92047);
	bool cppVar_92050 = (cppVar_92048 == 224);
	if (cppVar_92050) {
	cppVar_92046 = ACC;
	} else {
	BIT_VEC cppVar_92051;
	BIT_VEC cppVar_92052 = PC + 1;
	cppVar_92052 = (cppVar_92052 & cppMask_un_16_);
	BIT_VEC cppVar_92053 = ROM.rd(cppVar_92052);
	bool cppVar_92055 = (cppVar_92053 == 240);
	if (cppVar_92055) {
	cppVar_92051 = B;
	} else {
	cppVar_92051 = 0;
	}
	cppVar_92046 = cppVar_92051;
	}
	cppVar_92041 = cppVar_92046;
	}
	cppVar_92036 = cppVar_92041;
	}
	cppVar_92031 = cppVar_92036;
	}
	cppVar_92026 = cppVar_92031;
	}
	cppVar_92021 = cppVar_92026;
	}
	cppVar_92016 = cppVar_92021;
	}
	cppVar_92011 = cppVar_92016;
	}
	cppVar_92006 = cppVar_92011;
	}
	cppVar_92001 = cppVar_92006;
	}
	cppVar_91996 = cppVar_92001;
	}
	cppVar_91991 = cppVar_91996;
	}
	cppVar_91986 = cppVar_91991;
	}
	cppVar_91981 = cppVar_91986;
	}
	cppVar_91976 = cppVar_91981;
	}
	cppVar_91971 = cppVar_91976;
	}
	cppVar_91966 = cppVar_91971;
	}
	cppVar_91961 = cppVar_91966;
	}
	cppVar_91956 = cppVar_91961;
	}
	cppVar_91951 = cppVar_91956;
	}
	cppVar_91942 = cppVar_91951;
	}
	BIT_VEC cppVar_92058 = PC + 2;
	cppVar_92058 = (cppVar_92058 & cppMask_un_16_);
	BIT_VEC cppVar_92059 = ROM.rd(cppVar_92058);
	BIT_VEC cppVar_92060 = cppVar_91942 & cppVar_92059;
	type_mem cppVar_92061 = IRAM;
	cppVar_92061.wr(cppVar_91941, cppVar_92060);
	cppVar_91933 = cppVar_92061;
	} else {
	cppVar_91933 = IRAM;
	}
	cppVar_91929 = cppVar_91933;
	} else {
	type_mem cppVar_92062;
	BIT_VEC cppVar_92063 = ROM.rd(PC);
	bool cppVar_92065 = (cppVar_92063 == 82);
	if (cppVar_92065) {
	type_mem cppVar_92066;
	BIT_VEC cppVar_92068 = PC + 1;
	cppVar_92068 = (cppVar_92068 & cppMask_un_16_);
	BIT_VEC cppVar_92069 = ROM.rd(cppVar_92068);
	BIT_VEC cppVar_92070 = (cppVar_92069 >> 7) & cppMask_un_1_;
	bool cppVar_92072 = (cppVar_92070 == 0);
	if (cppVar_92072) {
	BIT_VEC cppVar_92073 = PC + 1;
	cppVar_92073 = (cppVar_92073 & cppMask_un_16_);
	BIT_VEC cppVar_92074 = ROM.rd(cppVar_92073);
	BIT_VEC cppVar_92075;
	BIT_VEC cppVar_92076 = PC + 1;
	cppVar_92076 = (cppVar_92076 & cppMask_un_16_);
	BIT_VEC cppVar_92077 = ROM.rd(cppVar_92076);
	BIT_VEC cppVar_92078 = (cppVar_92077 >> 7) & cppMask_un_1_;
	bool cppVar_92080 = (cppVar_92078 == 0);
	if (cppVar_92080) {
	BIT_VEC cppVar_92081 = PC + 1;
	cppVar_92081 = (cppVar_92081 & cppMask_un_16_);
	BIT_VEC cppVar_92082 = ROM.rd(cppVar_92081);
	BIT_VEC cppVar_92083 = IRAM.rd(cppVar_92082);
	cppVar_92075 = cppVar_92083;
	} else {
	BIT_VEC cppVar_92084;
	BIT_VEC cppVar_92085 = PC + 1;
	cppVar_92085 = (cppVar_92085 & cppMask_un_16_);
	BIT_VEC cppVar_92086 = ROM.rd(cppVar_92085);
	bool cppVar_92088 = (cppVar_92086 == 128);
	if (cppVar_92088) {
	cppVar_92084 = P0;
	} else {
	BIT_VEC cppVar_92089;
	BIT_VEC cppVar_92090 = PC + 1;
	cppVar_92090 = (cppVar_92090 & cppMask_un_16_);
	BIT_VEC cppVar_92091 = ROM.rd(cppVar_92090);
	bool cppVar_92093 = (cppVar_92091 == 129);
	if (cppVar_92093) {
	cppVar_92089 = SP;
	} else {
	BIT_VEC cppVar_92094;
	BIT_VEC cppVar_92095 = PC + 1;
	cppVar_92095 = (cppVar_92095 & cppMask_un_16_);
	BIT_VEC cppVar_92096 = ROM.rd(cppVar_92095);
	bool cppVar_92098 = (cppVar_92096 == 130);
	if (cppVar_92098) {
	cppVar_92094 = DPL;
	} else {
	BIT_VEC cppVar_92099;
	BIT_VEC cppVar_92100 = PC + 1;
	cppVar_92100 = (cppVar_92100 & cppMask_un_16_);
	BIT_VEC cppVar_92101 = ROM.rd(cppVar_92100);
	bool cppVar_92103 = (cppVar_92101 == 131);
	if (cppVar_92103) {
	cppVar_92099 = DPH;
	} else {
	BIT_VEC cppVar_92104;
	BIT_VEC cppVar_92105 = PC + 1;
	cppVar_92105 = (cppVar_92105 & cppMask_un_16_);
	BIT_VEC cppVar_92106 = ROM.rd(cppVar_92105);
	bool cppVar_92108 = (cppVar_92106 == 135);
	if (cppVar_92108) {
	cppVar_92104 = PCON;
	} else {
	BIT_VEC cppVar_92109;
	BIT_VEC cppVar_92110 = PC + 1;
	cppVar_92110 = (cppVar_92110 & cppMask_un_16_);
	BIT_VEC cppVar_92111 = ROM.rd(cppVar_92110);
	bool cppVar_92113 = (cppVar_92111 == 136);
	if (cppVar_92113) {
	cppVar_92109 = TCON;
	} else {
	BIT_VEC cppVar_92114;
	BIT_VEC cppVar_92115 = PC + 1;
	cppVar_92115 = (cppVar_92115 & cppMask_un_16_);
	BIT_VEC cppVar_92116 = ROM.rd(cppVar_92115);
	bool cppVar_92118 = (cppVar_92116 == 137);
	if (cppVar_92118) {
	cppVar_92114 = TMOD;
	} else {
	BIT_VEC cppVar_92119;
	BIT_VEC cppVar_92120 = PC + 1;
	cppVar_92120 = (cppVar_92120 & cppMask_un_16_);
	BIT_VEC cppVar_92121 = ROM.rd(cppVar_92120);
	bool cppVar_92123 = (cppVar_92121 == 138);
	if (cppVar_92123) {
	cppVar_92119 = TL0;
	} else {
	BIT_VEC cppVar_92124;
	BIT_VEC cppVar_92125 = PC + 1;
	cppVar_92125 = (cppVar_92125 & cppMask_un_16_);
	BIT_VEC cppVar_92126 = ROM.rd(cppVar_92125);
	bool cppVar_92128 = (cppVar_92126 == 140);
	if (cppVar_92128) {
	cppVar_92124 = TH0;
	} else {
	BIT_VEC cppVar_92129;
	BIT_VEC cppVar_92130 = PC + 1;
	cppVar_92130 = (cppVar_92130 & cppMask_un_16_);
	BIT_VEC cppVar_92131 = ROM.rd(cppVar_92130);
	bool cppVar_92133 = (cppVar_92131 == 139);
	if (cppVar_92133) {
	cppVar_92129 = TL1;
	} else {
	BIT_VEC cppVar_92134;
	BIT_VEC cppVar_92135 = PC + 1;
	cppVar_92135 = (cppVar_92135 & cppMask_un_16_);
	BIT_VEC cppVar_92136 = ROM.rd(cppVar_92135);
	bool cppVar_92138 = (cppVar_92136 == 141);
	if (cppVar_92138) {
	cppVar_92134 = TH1;
	} else {
	BIT_VEC cppVar_92139;
	BIT_VEC cppVar_92140 = PC + 1;
	cppVar_92140 = (cppVar_92140 & cppMask_un_16_);
	BIT_VEC cppVar_92141 = ROM.rd(cppVar_92140);
	bool cppVar_92143 = (cppVar_92141 == 144);
	if (cppVar_92143) {
	cppVar_92139 = P1;
	} else {
	BIT_VEC cppVar_92144;
	BIT_VEC cppVar_92145 = PC + 1;
	cppVar_92145 = (cppVar_92145 & cppMask_un_16_);
	BIT_VEC cppVar_92146 = ROM.rd(cppVar_92145);
	bool cppVar_92148 = (cppVar_92146 == 152);
	if (cppVar_92148) {
	cppVar_92144 = SCON;
	} else {
	BIT_VEC cppVar_92149;
	BIT_VEC cppVar_92150 = PC + 1;
	cppVar_92150 = (cppVar_92150 & cppMask_un_16_);
	BIT_VEC cppVar_92151 = ROM.rd(cppVar_92150);
	bool cppVar_92153 = (cppVar_92151 == 153);
	if (cppVar_92153) {
	cppVar_92149 = SBUF;
	} else {
	BIT_VEC cppVar_92154;
	BIT_VEC cppVar_92155 = PC + 1;
	cppVar_92155 = (cppVar_92155 & cppMask_un_16_);
	BIT_VEC cppVar_92156 = ROM.rd(cppVar_92155);
	bool cppVar_92158 = (cppVar_92156 == 160);
	if (cppVar_92158) {
	cppVar_92154 = P2;
	} else {
	BIT_VEC cppVar_92159;
	BIT_VEC cppVar_92160 = PC + 1;
	cppVar_92160 = (cppVar_92160 & cppMask_un_16_);
	BIT_VEC cppVar_92161 = ROM.rd(cppVar_92160);
	bool cppVar_92163 = (cppVar_92161 == 168);
	if (cppVar_92163) {
	cppVar_92159 = IE;
	} else {
	BIT_VEC cppVar_92164;
	BIT_VEC cppVar_92165 = PC + 1;
	cppVar_92165 = (cppVar_92165 & cppMask_un_16_);
	BIT_VEC cppVar_92166 = ROM.rd(cppVar_92165);
	bool cppVar_92168 = (cppVar_92166 == 176);
	if (cppVar_92168) {
	cppVar_92164 = P3;
	} else {
	BIT_VEC cppVar_92169;
	BIT_VEC cppVar_92170 = PC + 1;
	cppVar_92170 = (cppVar_92170 & cppMask_un_16_);
	BIT_VEC cppVar_92171 = ROM.rd(cppVar_92170);
	bool cppVar_92173 = (cppVar_92171 == 184);
	if (cppVar_92173) {
	cppVar_92169 = IP;
	} else {
	BIT_VEC cppVar_92174;
	BIT_VEC cppVar_92175 = PC + 1;
	cppVar_92175 = (cppVar_92175 & cppMask_un_16_);
	BIT_VEC cppVar_92176 = ROM.rd(cppVar_92175);
	bool cppVar_92178 = (cppVar_92176 == 208);
	if (cppVar_92178) {
	cppVar_92174 = PSW;
	} else {
	BIT_VEC cppVar_92179;
	BIT_VEC cppVar_92180 = PC + 1;
	cppVar_92180 = (cppVar_92180 & cppMask_un_16_);
	BIT_VEC cppVar_92181 = ROM.rd(cppVar_92180);
	bool cppVar_92183 = (cppVar_92181 == 224);
	if (cppVar_92183) {
	cppVar_92179 = ACC;
	} else {
	BIT_VEC cppVar_92184;
	BIT_VEC cppVar_92185 = PC + 1;
	cppVar_92185 = (cppVar_92185 & cppMask_un_16_);
	BIT_VEC cppVar_92186 = ROM.rd(cppVar_92185);
	bool cppVar_92188 = (cppVar_92186 == 240);
	if (cppVar_92188) {
	cppVar_92184 = B;
	} else {
	cppVar_92184 = 0;
	}
	cppVar_92179 = cppVar_92184;
	}
	cppVar_92174 = cppVar_92179;
	}
	cppVar_92169 = cppVar_92174;
	}
	cppVar_92164 = cppVar_92169;
	}
	cppVar_92159 = cppVar_92164;
	}
	cppVar_92154 = cppVar_92159;
	}
	cppVar_92149 = cppVar_92154;
	}
	cppVar_92144 = cppVar_92149;
	}
	cppVar_92139 = cppVar_92144;
	}
	cppVar_92134 = cppVar_92139;
	}
	cppVar_92129 = cppVar_92134;
	}
	cppVar_92124 = cppVar_92129;
	}
	cppVar_92119 = cppVar_92124;
	}
	cppVar_92114 = cppVar_92119;
	}
	cppVar_92109 = cppVar_92114;
	}
	cppVar_92104 = cppVar_92109;
	}
	cppVar_92099 = cppVar_92104;
	}
	cppVar_92094 = cppVar_92099;
	}
	cppVar_92089 = cppVar_92094;
	}
	cppVar_92084 = cppVar_92089;
	}
	cppVar_92075 = cppVar_92084;
	}
	BIT_VEC cppVar_92190 = cppVar_92075 & ACC;
	type_mem cppVar_92191 = IRAM;
	cppVar_92191.wr(cppVar_92074, cppVar_92190);
	cppVar_92066 = cppVar_92191;
	} else {
	cppVar_92066 = IRAM;
	}
	cppVar_92062 = cppVar_92066;
	} else {
	type_mem cppVar_92192;
	BIT_VEC cppVar_92193 = ROM.rd(PC);
	bool cppVar_92195 = (cppVar_92193 == 67);
	if (cppVar_92195) {
	type_mem cppVar_92196;
	BIT_VEC cppVar_92198 = PC + 1;
	cppVar_92198 = (cppVar_92198 & cppMask_un_16_);
	BIT_VEC cppVar_92199 = ROM.rd(cppVar_92198);
	BIT_VEC cppVar_92200 = (cppVar_92199 >> 7) & cppMask_un_1_;
	bool cppVar_92202 = (cppVar_92200 == 0);
	if (cppVar_92202) {
	BIT_VEC cppVar_92203 = PC + 1;
	cppVar_92203 = (cppVar_92203 & cppMask_un_16_);
	BIT_VEC cppVar_92204 = ROM.rd(cppVar_92203);
	BIT_VEC cppVar_92205;
	BIT_VEC cppVar_92206 = PC + 1;
	cppVar_92206 = (cppVar_92206 & cppMask_un_16_);
	BIT_VEC cppVar_92207 = ROM.rd(cppVar_92206);
	BIT_VEC cppVar_92208 = (cppVar_92207 >> 7) & cppMask_un_1_;
	bool cppVar_92210 = (cppVar_92208 == 0);
	if (cppVar_92210) {
	BIT_VEC cppVar_92211 = PC + 1;
	cppVar_92211 = (cppVar_92211 & cppMask_un_16_);
	BIT_VEC cppVar_92212 = ROM.rd(cppVar_92211);
	BIT_VEC cppVar_92213 = IRAM.rd(cppVar_92212);
	cppVar_92205 = cppVar_92213;
	} else {
	BIT_VEC cppVar_92214;
	BIT_VEC cppVar_92215 = PC + 1;
	cppVar_92215 = (cppVar_92215 & cppMask_un_16_);
	BIT_VEC cppVar_92216 = ROM.rd(cppVar_92215);
	bool cppVar_92218 = (cppVar_92216 == 128);
	if (cppVar_92218) {
	cppVar_92214 = P0;
	} else {
	BIT_VEC cppVar_92219;
	BIT_VEC cppVar_92220 = PC + 1;
	cppVar_92220 = (cppVar_92220 & cppMask_un_16_);
	BIT_VEC cppVar_92221 = ROM.rd(cppVar_92220);
	bool cppVar_92223 = (cppVar_92221 == 129);
	if (cppVar_92223) {
	cppVar_92219 = SP;
	} else {
	BIT_VEC cppVar_92224;
	BIT_VEC cppVar_92225 = PC + 1;
	cppVar_92225 = (cppVar_92225 & cppMask_un_16_);
	BIT_VEC cppVar_92226 = ROM.rd(cppVar_92225);
	bool cppVar_92228 = (cppVar_92226 == 130);
	if (cppVar_92228) {
	cppVar_92224 = DPL;
	} else {
	BIT_VEC cppVar_92229;
	BIT_VEC cppVar_92230 = PC + 1;
	cppVar_92230 = (cppVar_92230 & cppMask_un_16_);
	BIT_VEC cppVar_92231 = ROM.rd(cppVar_92230);
	bool cppVar_92233 = (cppVar_92231 == 131);
	if (cppVar_92233) {
	cppVar_92229 = DPH;
	} else {
	BIT_VEC cppVar_92234;
	BIT_VEC cppVar_92235 = PC + 1;
	cppVar_92235 = (cppVar_92235 & cppMask_un_16_);
	BIT_VEC cppVar_92236 = ROM.rd(cppVar_92235);
	bool cppVar_92238 = (cppVar_92236 == 135);
	if (cppVar_92238) {
	cppVar_92234 = PCON;
	} else {
	BIT_VEC cppVar_92239;
	BIT_VEC cppVar_92240 = PC + 1;
	cppVar_92240 = (cppVar_92240 & cppMask_un_16_);
	BIT_VEC cppVar_92241 = ROM.rd(cppVar_92240);
	bool cppVar_92243 = (cppVar_92241 == 136);
	if (cppVar_92243) {
	cppVar_92239 = TCON;
	} else {
	BIT_VEC cppVar_92244;
	BIT_VEC cppVar_92245 = PC + 1;
	cppVar_92245 = (cppVar_92245 & cppMask_un_16_);
	BIT_VEC cppVar_92246 = ROM.rd(cppVar_92245);
	bool cppVar_92248 = (cppVar_92246 == 137);
	if (cppVar_92248) {
	cppVar_92244 = TMOD;
	} else {
	BIT_VEC cppVar_92249;
	BIT_VEC cppVar_92250 = PC + 1;
	cppVar_92250 = (cppVar_92250 & cppMask_un_16_);
	BIT_VEC cppVar_92251 = ROM.rd(cppVar_92250);
	bool cppVar_92253 = (cppVar_92251 == 138);
	if (cppVar_92253) {
	cppVar_92249 = TL0;
	} else {
	BIT_VEC cppVar_92254;
	BIT_VEC cppVar_92255 = PC + 1;
	cppVar_92255 = (cppVar_92255 & cppMask_un_16_);
	BIT_VEC cppVar_92256 = ROM.rd(cppVar_92255);
	bool cppVar_92258 = (cppVar_92256 == 140);
	if (cppVar_92258) {
	cppVar_92254 = TH0;
	} else {
	BIT_VEC cppVar_92259;
	BIT_VEC cppVar_92260 = PC + 1;
	cppVar_92260 = (cppVar_92260 & cppMask_un_16_);
	BIT_VEC cppVar_92261 = ROM.rd(cppVar_92260);
	bool cppVar_92263 = (cppVar_92261 == 139);
	if (cppVar_92263) {
	cppVar_92259 = TL1;
	} else {
	BIT_VEC cppVar_92264;
	BIT_VEC cppVar_92265 = PC + 1;
	cppVar_92265 = (cppVar_92265 & cppMask_un_16_);
	BIT_VEC cppVar_92266 = ROM.rd(cppVar_92265);
	bool cppVar_92268 = (cppVar_92266 == 141);
	if (cppVar_92268) {
	cppVar_92264 = TH1;
	} else {
	BIT_VEC cppVar_92269;
	BIT_VEC cppVar_92270 = PC + 1;
	cppVar_92270 = (cppVar_92270 & cppMask_un_16_);
	BIT_VEC cppVar_92271 = ROM.rd(cppVar_92270);
	bool cppVar_92273 = (cppVar_92271 == 144);
	if (cppVar_92273) {
	cppVar_92269 = P1;
	} else {
	BIT_VEC cppVar_92274;
	BIT_VEC cppVar_92275 = PC + 1;
	cppVar_92275 = (cppVar_92275 & cppMask_un_16_);
	BIT_VEC cppVar_92276 = ROM.rd(cppVar_92275);
	bool cppVar_92278 = (cppVar_92276 == 152);
	if (cppVar_92278) {
	cppVar_92274 = SCON;
	} else {
	BIT_VEC cppVar_92279;
	BIT_VEC cppVar_92280 = PC + 1;
	cppVar_92280 = (cppVar_92280 & cppMask_un_16_);
	BIT_VEC cppVar_92281 = ROM.rd(cppVar_92280);
	bool cppVar_92283 = (cppVar_92281 == 153);
	if (cppVar_92283) {
	cppVar_92279 = SBUF;
	} else {
	BIT_VEC cppVar_92284;
	BIT_VEC cppVar_92285 = PC + 1;
	cppVar_92285 = (cppVar_92285 & cppMask_un_16_);
	BIT_VEC cppVar_92286 = ROM.rd(cppVar_92285);
	bool cppVar_92288 = (cppVar_92286 == 160);
	if (cppVar_92288) {
	cppVar_92284 = P2;
	} else {
	BIT_VEC cppVar_92289;
	BIT_VEC cppVar_92290 = PC + 1;
	cppVar_92290 = (cppVar_92290 & cppMask_un_16_);
	BIT_VEC cppVar_92291 = ROM.rd(cppVar_92290);
	bool cppVar_92293 = (cppVar_92291 == 168);
	if (cppVar_92293) {
	cppVar_92289 = IE;
	} else {
	BIT_VEC cppVar_92294;
	BIT_VEC cppVar_92295 = PC + 1;
	cppVar_92295 = (cppVar_92295 & cppMask_un_16_);
	BIT_VEC cppVar_92296 = ROM.rd(cppVar_92295);
	bool cppVar_92298 = (cppVar_92296 == 176);
	if (cppVar_92298) {
	cppVar_92294 = P3;
	} else {
	BIT_VEC cppVar_92299;
	BIT_VEC cppVar_92300 = PC + 1;
	cppVar_92300 = (cppVar_92300 & cppMask_un_16_);
	BIT_VEC cppVar_92301 = ROM.rd(cppVar_92300);
	bool cppVar_92303 = (cppVar_92301 == 184);
	if (cppVar_92303) {
	cppVar_92299 = IP;
	} else {
	BIT_VEC cppVar_92304;
	BIT_VEC cppVar_92305 = PC + 1;
	cppVar_92305 = (cppVar_92305 & cppMask_un_16_);
	BIT_VEC cppVar_92306 = ROM.rd(cppVar_92305);
	bool cppVar_92308 = (cppVar_92306 == 208);
	if (cppVar_92308) {
	cppVar_92304 = PSW;
	} else {
	BIT_VEC cppVar_92309;
	BIT_VEC cppVar_92310 = PC + 1;
	cppVar_92310 = (cppVar_92310 & cppMask_un_16_);
	BIT_VEC cppVar_92311 = ROM.rd(cppVar_92310);
	bool cppVar_92313 = (cppVar_92311 == 224);
	if (cppVar_92313) {
	cppVar_92309 = ACC;
	} else {
	BIT_VEC cppVar_92314;
	BIT_VEC cppVar_92315 = PC + 1;
	cppVar_92315 = (cppVar_92315 & cppMask_un_16_);
	BIT_VEC cppVar_92316 = ROM.rd(cppVar_92315);
	bool cppVar_92318 = (cppVar_92316 == 240);
	if (cppVar_92318) {
	cppVar_92314 = B;
	} else {
	cppVar_92314 = 0;
	}
	cppVar_92309 = cppVar_92314;
	}
	cppVar_92304 = cppVar_92309;
	}
	cppVar_92299 = cppVar_92304;
	}
	cppVar_92294 = cppVar_92299;
	}
	cppVar_92289 = cppVar_92294;
	}
	cppVar_92284 = cppVar_92289;
	}
	cppVar_92279 = cppVar_92284;
	}
	cppVar_92274 = cppVar_92279;
	}
	cppVar_92269 = cppVar_92274;
	}
	cppVar_92264 = cppVar_92269;
	}
	cppVar_92259 = cppVar_92264;
	}
	cppVar_92254 = cppVar_92259;
	}
	cppVar_92249 = cppVar_92254;
	}
	cppVar_92244 = cppVar_92249;
	}
	cppVar_92239 = cppVar_92244;
	}
	cppVar_92234 = cppVar_92239;
	}
	cppVar_92229 = cppVar_92234;
	}
	cppVar_92224 = cppVar_92229;
	}
	cppVar_92219 = cppVar_92224;
	}
	cppVar_92214 = cppVar_92219;
	}
	cppVar_92205 = cppVar_92214;
	}
	BIT_VEC cppVar_92321 = PC + 2;
	cppVar_92321 = (cppVar_92321 & cppMask_un_16_);
	BIT_VEC cppVar_92322 = ROM.rd(cppVar_92321);
	BIT_VEC cppVar_92323 = cppVar_92205 | cppVar_92322;
	type_mem cppVar_92324 = IRAM;
	cppVar_92324.wr(cppVar_92204, cppVar_92323);
	cppVar_92196 = cppVar_92324;
	} else {
	cppVar_92196 = IRAM;
	}
	cppVar_92192 = cppVar_92196;
	} else {
	type_mem cppVar_92325;
	BIT_VEC cppVar_92326 = ROM.rd(PC);
	bool cppVar_92328 = (cppVar_92326 == 66);
	if (cppVar_92328) {
	type_mem cppVar_92329;
	BIT_VEC cppVar_92331 = PC + 1;
	cppVar_92331 = (cppVar_92331 & cppMask_un_16_);
	BIT_VEC cppVar_92332 = ROM.rd(cppVar_92331);
	BIT_VEC cppVar_92333 = (cppVar_92332 >> 7) & cppMask_un_1_;
	bool cppVar_92335 = (cppVar_92333 == 0);
	if (cppVar_92335) {
	BIT_VEC cppVar_92336 = PC + 1;
	cppVar_92336 = (cppVar_92336 & cppMask_un_16_);
	BIT_VEC cppVar_92337 = ROM.rd(cppVar_92336);
	BIT_VEC cppVar_92338;
	BIT_VEC cppVar_92339 = PC + 1;
	cppVar_92339 = (cppVar_92339 & cppMask_un_16_);
	BIT_VEC cppVar_92340 = ROM.rd(cppVar_92339);
	BIT_VEC cppVar_92341 = (cppVar_92340 >> 7) & cppMask_un_1_;
	bool cppVar_92343 = (cppVar_92341 == 0);
	if (cppVar_92343) {
	BIT_VEC cppVar_92344 = PC + 1;
	cppVar_92344 = (cppVar_92344 & cppMask_un_16_);
	BIT_VEC cppVar_92345 = ROM.rd(cppVar_92344);
	BIT_VEC cppVar_92346 = IRAM.rd(cppVar_92345);
	cppVar_92338 = cppVar_92346;
	} else {
	BIT_VEC cppVar_92347;
	BIT_VEC cppVar_92348 = PC + 1;
	cppVar_92348 = (cppVar_92348 & cppMask_un_16_);
	BIT_VEC cppVar_92349 = ROM.rd(cppVar_92348);
	bool cppVar_92351 = (cppVar_92349 == 128);
	if (cppVar_92351) {
	cppVar_92347 = P0;
	} else {
	BIT_VEC cppVar_92352;
	BIT_VEC cppVar_92353 = PC + 1;
	cppVar_92353 = (cppVar_92353 & cppMask_un_16_);
	BIT_VEC cppVar_92354 = ROM.rd(cppVar_92353);
	bool cppVar_92356 = (cppVar_92354 == 129);
	if (cppVar_92356) {
	cppVar_92352 = SP;
	} else {
	BIT_VEC cppVar_92357;
	BIT_VEC cppVar_92358 = PC + 1;
	cppVar_92358 = (cppVar_92358 & cppMask_un_16_);
	BIT_VEC cppVar_92359 = ROM.rd(cppVar_92358);
	bool cppVar_92361 = (cppVar_92359 == 130);
	if (cppVar_92361) {
	cppVar_92357 = DPL;
	} else {
	BIT_VEC cppVar_92362;
	BIT_VEC cppVar_92363 = PC + 1;
	cppVar_92363 = (cppVar_92363 & cppMask_un_16_);
	BIT_VEC cppVar_92364 = ROM.rd(cppVar_92363);
	bool cppVar_92366 = (cppVar_92364 == 131);
	if (cppVar_92366) {
	cppVar_92362 = DPH;
	} else {
	BIT_VEC cppVar_92367;
	BIT_VEC cppVar_92368 = PC + 1;
	cppVar_92368 = (cppVar_92368 & cppMask_un_16_);
	BIT_VEC cppVar_92369 = ROM.rd(cppVar_92368);
	bool cppVar_92371 = (cppVar_92369 == 135);
	if (cppVar_92371) {
	cppVar_92367 = PCON;
	} else {
	BIT_VEC cppVar_92372;
	BIT_VEC cppVar_92373 = PC + 1;
	cppVar_92373 = (cppVar_92373 & cppMask_un_16_);
	BIT_VEC cppVar_92374 = ROM.rd(cppVar_92373);
	bool cppVar_92376 = (cppVar_92374 == 136);
	if (cppVar_92376) {
	cppVar_92372 = TCON;
	} else {
	BIT_VEC cppVar_92377;
	BIT_VEC cppVar_92378 = PC + 1;
	cppVar_92378 = (cppVar_92378 & cppMask_un_16_);
	BIT_VEC cppVar_92379 = ROM.rd(cppVar_92378);
	bool cppVar_92381 = (cppVar_92379 == 137);
	if (cppVar_92381) {
	cppVar_92377 = TMOD;
	} else {
	BIT_VEC cppVar_92382;
	BIT_VEC cppVar_92383 = PC + 1;
	cppVar_92383 = (cppVar_92383 & cppMask_un_16_);
	BIT_VEC cppVar_92384 = ROM.rd(cppVar_92383);
	bool cppVar_92386 = (cppVar_92384 == 138);
	if (cppVar_92386) {
	cppVar_92382 = TL0;
	} else {
	BIT_VEC cppVar_92387;
	BIT_VEC cppVar_92388 = PC + 1;
	cppVar_92388 = (cppVar_92388 & cppMask_un_16_);
	BIT_VEC cppVar_92389 = ROM.rd(cppVar_92388);
	bool cppVar_92391 = (cppVar_92389 == 140);
	if (cppVar_92391) {
	cppVar_92387 = TH0;
	} else {
	BIT_VEC cppVar_92392;
	BIT_VEC cppVar_92393 = PC + 1;
	cppVar_92393 = (cppVar_92393 & cppMask_un_16_);
	BIT_VEC cppVar_92394 = ROM.rd(cppVar_92393);
	bool cppVar_92396 = (cppVar_92394 == 139);
	if (cppVar_92396) {
	cppVar_92392 = TL1;
	} else {
	BIT_VEC cppVar_92397;
	BIT_VEC cppVar_92398 = PC + 1;
	cppVar_92398 = (cppVar_92398 & cppMask_un_16_);
	BIT_VEC cppVar_92399 = ROM.rd(cppVar_92398);
	bool cppVar_92401 = (cppVar_92399 == 141);
	if (cppVar_92401) {
	cppVar_92397 = TH1;
	} else {
	BIT_VEC cppVar_92402;
	BIT_VEC cppVar_92403 = PC + 1;
	cppVar_92403 = (cppVar_92403 & cppMask_un_16_);
	BIT_VEC cppVar_92404 = ROM.rd(cppVar_92403);
	bool cppVar_92406 = (cppVar_92404 == 144);
	if (cppVar_92406) {
	cppVar_92402 = P1;
	} else {
	BIT_VEC cppVar_92407;
	BIT_VEC cppVar_92408 = PC + 1;
	cppVar_92408 = (cppVar_92408 & cppMask_un_16_);
	BIT_VEC cppVar_92409 = ROM.rd(cppVar_92408);
	bool cppVar_92411 = (cppVar_92409 == 152);
	if (cppVar_92411) {
	cppVar_92407 = SCON;
	} else {
	BIT_VEC cppVar_92412;
	BIT_VEC cppVar_92413 = PC + 1;
	cppVar_92413 = (cppVar_92413 & cppMask_un_16_);
	BIT_VEC cppVar_92414 = ROM.rd(cppVar_92413);
	bool cppVar_92416 = (cppVar_92414 == 153);
	if (cppVar_92416) {
	cppVar_92412 = SBUF;
	} else {
	BIT_VEC cppVar_92417;
	BIT_VEC cppVar_92418 = PC + 1;
	cppVar_92418 = (cppVar_92418 & cppMask_un_16_);
	BIT_VEC cppVar_92419 = ROM.rd(cppVar_92418);
	bool cppVar_92421 = (cppVar_92419 == 160);
	if (cppVar_92421) {
	cppVar_92417 = P2;
	} else {
	BIT_VEC cppVar_92422;
	BIT_VEC cppVar_92423 = PC + 1;
	cppVar_92423 = (cppVar_92423 & cppMask_un_16_);
	BIT_VEC cppVar_92424 = ROM.rd(cppVar_92423);
	bool cppVar_92426 = (cppVar_92424 == 168);
	if (cppVar_92426) {
	cppVar_92422 = IE;
	} else {
	BIT_VEC cppVar_92427;
	BIT_VEC cppVar_92428 = PC + 1;
	cppVar_92428 = (cppVar_92428 & cppMask_un_16_);
	BIT_VEC cppVar_92429 = ROM.rd(cppVar_92428);
	bool cppVar_92431 = (cppVar_92429 == 176);
	if (cppVar_92431) {
	cppVar_92427 = P3;
	} else {
	BIT_VEC cppVar_92432;
	BIT_VEC cppVar_92433 = PC + 1;
	cppVar_92433 = (cppVar_92433 & cppMask_un_16_);
	BIT_VEC cppVar_92434 = ROM.rd(cppVar_92433);
	bool cppVar_92436 = (cppVar_92434 == 184);
	if (cppVar_92436) {
	cppVar_92432 = IP;
	} else {
	BIT_VEC cppVar_92437;
	BIT_VEC cppVar_92438 = PC + 1;
	cppVar_92438 = (cppVar_92438 & cppMask_un_16_);
	BIT_VEC cppVar_92439 = ROM.rd(cppVar_92438);
	bool cppVar_92441 = (cppVar_92439 == 208);
	if (cppVar_92441) {
	cppVar_92437 = PSW;
	} else {
	BIT_VEC cppVar_92442;
	BIT_VEC cppVar_92443 = PC + 1;
	cppVar_92443 = (cppVar_92443 & cppMask_un_16_);
	BIT_VEC cppVar_92444 = ROM.rd(cppVar_92443);
	bool cppVar_92446 = (cppVar_92444 == 224);
	if (cppVar_92446) {
	cppVar_92442 = ACC;
	} else {
	BIT_VEC cppVar_92447;
	BIT_VEC cppVar_92448 = PC + 1;
	cppVar_92448 = (cppVar_92448 & cppMask_un_16_);
	BIT_VEC cppVar_92449 = ROM.rd(cppVar_92448);
	bool cppVar_92451 = (cppVar_92449 == 240);
	if (cppVar_92451) {
	cppVar_92447 = B;
	} else {
	cppVar_92447 = 0;
	}
	cppVar_92442 = cppVar_92447;
	}
	cppVar_92437 = cppVar_92442;
	}
	cppVar_92432 = cppVar_92437;
	}
	cppVar_92427 = cppVar_92432;
	}
	cppVar_92422 = cppVar_92427;
	}
	cppVar_92417 = cppVar_92422;
	}
	cppVar_92412 = cppVar_92417;
	}
	cppVar_92407 = cppVar_92412;
	}
	cppVar_92402 = cppVar_92407;
	}
	cppVar_92397 = cppVar_92402;
	}
	cppVar_92392 = cppVar_92397;
	}
	cppVar_92387 = cppVar_92392;
	}
	cppVar_92382 = cppVar_92387;
	}
	cppVar_92377 = cppVar_92382;
	}
	cppVar_92372 = cppVar_92377;
	}
	cppVar_92367 = cppVar_92372;
	}
	cppVar_92362 = cppVar_92367;
	}
	cppVar_92357 = cppVar_92362;
	}
	cppVar_92352 = cppVar_92357;
	}
	cppVar_92347 = cppVar_92352;
	}
	cppVar_92338 = cppVar_92347;
	}
	BIT_VEC cppVar_92453 = cppVar_92338 | ACC;
	type_mem cppVar_92454 = IRAM;
	cppVar_92454.wr(cppVar_92337, cppVar_92453);
	cppVar_92329 = cppVar_92454;
	} else {
	cppVar_92329 = IRAM;
	}
	cppVar_92325 = cppVar_92329;
	} else {
	type_mem cppVar_92455;
	BIT_VEC cppVar_92456 = ROM.rd(PC);
	bool cppVar_92458 = (cppVar_92456 == 223);
	BIT_VEC cppVar_92459 = ROM.rd(PC);
	bool cppVar_92461 = (cppVar_92459 == 31);
	bool cppVar_92462 = cppVar_92458 || cppVar_92461;
	if (cppVar_92462) {
	type_mem cppVar_92463;
	BIT_VEC cppVar_92465 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_92467 = (cppVar_92465 << 3) | 7;
	cppVar_92467 = (cppVar_92467 & cppMask_un_5_);
	BIT_VEC cppVar_92468 = (0 << 5) | cppVar_92467;
	cppVar_92468 = (cppVar_92468 & cppMask_un_8_);
	BIT_VEC cppVar_92469 = (cppVar_92468 >> 7) & cppMask_un_1_;
	bool cppVar_92471 = (cppVar_92469 == 0);
	if (cppVar_92471) {
	BIT_VEC cppVar_92472 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_92473 = (cppVar_92472 << 3) | 7;
	cppVar_92473 = (cppVar_92473 & cppMask_un_5_);
	BIT_VEC cppVar_92474 = (0 << 5) | cppVar_92473;
	cppVar_92474 = (cppVar_92474 & cppMask_un_8_);
	BIT_VEC cppVar_92475;
	BIT_VEC cppVar_92476 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_92477 = (cppVar_92476 << 3) | 7;
	cppVar_92477 = (cppVar_92477 & cppMask_un_5_);
	BIT_VEC cppVar_92478 = (0 << 5) | cppVar_92477;
	cppVar_92478 = (cppVar_92478 & cppMask_un_8_);
	BIT_VEC cppVar_92479 = (cppVar_92478 >> 7) & cppMask_un_1_;
	bool cppVar_92481 = (cppVar_92479 == 0);
	if (cppVar_92481) {
	BIT_VEC cppVar_92482 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_92483 = (cppVar_92482 << 3) | 7;
	cppVar_92483 = (cppVar_92483 & cppMask_un_5_);
	BIT_VEC cppVar_92484 = (0 << 5) | cppVar_92483;
	cppVar_92484 = (cppVar_92484 & cppMask_un_8_);
	BIT_VEC cppVar_92485 = IRAM.rd(cppVar_92484);
	cppVar_92475 = cppVar_92485;
	} else {
	BIT_VEC cppVar_92486;
	BIT_VEC cppVar_92487 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_92488 = (cppVar_92487 << 3) | 7;
	cppVar_92488 = (cppVar_92488 & cppMask_un_5_);
	BIT_VEC cppVar_92489 = (0 << 5) | cppVar_92488;
	cppVar_92489 = (cppVar_92489 & cppMask_un_8_);
	bool cppVar_92491 = (cppVar_92489 == 128);
	if (cppVar_92491) {
	cppVar_92486 = P0;
	} else {
	BIT_VEC cppVar_92492;
	BIT_VEC cppVar_92493 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_92494 = (cppVar_92493 << 3) | 7;
	cppVar_92494 = (cppVar_92494 & cppMask_un_5_);
	BIT_VEC cppVar_92495 = (0 << 5) | cppVar_92494;
	cppVar_92495 = (cppVar_92495 & cppMask_un_8_);
	bool cppVar_92497 = (cppVar_92495 == 129);
	if (cppVar_92497) {
	cppVar_92492 = SP;
	} else {
	BIT_VEC cppVar_92498;
	BIT_VEC cppVar_92499 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_92500 = (cppVar_92499 << 3) | 7;
	cppVar_92500 = (cppVar_92500 & cppMask_un_5_);
	BIT_VEC cppVar_92501 = (0 << 5) | cppVar_92500;
	cppVar_92501 = (cppVar_92501 & cppMask_un_8_);
	bool cppVar_92503 = (cppVar_92501 == 130);
	if (cppVar_92503) {
	cppVar_92498 = DPL;
	} else {
	BIT_VEC cppVar_92504;
	BIT_VEC cppVar_92505 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_92506 = (cppVar_92505 << 3) | 7;
	cppVar_92506 = (cppVar_92506 & cppMask_un_5_);
	BIT_VEC cppVar_92507 = (0 << 5) | cppVar_92506;
	cppVar_92507 = (cppVar_92507 & cppMask_un_8_);
	bool cppVar_92509 = (cppVar_92507 == 131);
	if (cppVar_92509) {
	cppVar_92504 = DPH;
	} else {
	BIT_VEC cppVar_92510;
	BIT_VEC cppVar_92511 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_92512 = (cppVar_92511 << 3) | 7;
	cppVar_92512 = (cppVar_92512 & cppMask_un_5_);
	BIT_VEC cppVar_92513 = (0 << 5) | cppVar_92512;
	cppVar_92513 = (cppVar_92513 & cppMask_un_8_);
	bool cppVar_92515 = (cppVar_92513 == 135);
	if (cppVar_92515) {
	cppVar_92510 = PCON;
	} else {
	BIT_VEC cppVar_92516;
	BIT_VEC cppVar_92517 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_92518 = (cppVar_92517 << 3) | 7;
	cppVar_92518 = (cppVar_92518 & cppMask_un_5_);
	BIT_VEC cppVar_92519 = (0 << 5) | cppVar_92518;
	cppVar_92519 = (cppVar_92519 & cppMask_un_8_);
	bool cppVar_92521 = (cppVar_92519 == 136);
	if (cppVar_92521) {
	cppVar_92516 = TCON;
	} else {
	BIT_VEC cppVar_92522;
	BIT_VEC cppVar_92523 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_92524 = (cppVar_92523 << 3) | 7;
	cppVar_92524 = (cppVar_92524 & cppMask_un_5_);
	BIT_VEC cppVar_92525 = (0 << 5) | cppVar_92524;
	cppVar_92525 = (cppVar_92525 & cppMask_un_8_);
	bool cppVar_92527 = (cppVar_92525 == 137);
	if (cppVar_92527) {
	cppVar_92522 = TMOD;
	} else {
	BIT_VEC cppVar_92528;
	BIT_VEC cppVar_92529 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_92530 = (cppVar_92529 << 3) | 7;
	cppVar_92530 = (cppVar_92530 & cppMask_un_5_);
	BIT_VEC cppVar_92531 = (0 << 5) | cppVar_92530;
	cppVar_92531 = (cppVar_92531 & cppMask_un_8_);
	bool cppVar_92533 = (cppVar_92531 == 138);
	if (cppVar_92533) {
	cppVar_92528 = TL0;
	} else {
	BIT_VEC cppVar_92534;
	BIT_VEC cppVar_92535 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_92536 = (cppVar_92535 << 3) | 7;
	cppVar_92536 = (cppVar_92536 & cppMask_un_5_);
	BIT_VEC cppVar_92537 = (0 << 5) | cppVar_92536;
	cppVar_92537 = (cppVar_92537 & cppMask_un_8_);
	bool cppVar_92539 = (cppVar_92537 == 140);
	if (cppVar_92539) {
	cppVar_92534 = TH0;
	} else {
	BIT_VEC cppVar_92540;
	BIT_VEC cppVar_92541 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_92542 = (cppVar_92541 << 3) | 7;
	cppVar_92542 = (cppVar_92542 & cppMask_un_5_);
	BIT_VEC cppVar_92543 = (0 << 5) | cppVar_92542;
	cppVar_92543 = (cppVar_92543 & cppMask_un_8_);
	bool cppVar_92545 = (cppVar_92543 == 139);
	if (cppVar_92545) {
	cppVar_92540 = TL1;
	} else {
	BIT_VEC cppVar_92546;
	BIT_VEC cppVar_92547 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_92548 = (cppVar_92547 << 3) | 7;
	cppVar_92548 = (cppVar_92548 & cppMask_un_5_);
	BIT_VEC cppVar_92549 = (0 << 5) | cppVar_92548;
	cppVar_92549 = (cppVar_92549 & cppMask_un_8_);
	bool cppVar_92551 = (cppVar_92549 == 141);
	if (cppVar_92551) {
	cppVar_92546 = TH1;
	} else {
	BIT_VEC cppVar_92552;
	BIT_VEC cppVar_92553 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_92554 = (cppVar_92553 << 3) | 7;
	cppVar_92554 = (cppVar_92554 & cppMask_un_5_);
	BIT_VEC cppVar_92555 = (0 << 5) | cppVar_92554;
	cppVar_92555 = (cppVar_92555 & cppMask_un_8_);
	bool cppVar_92557 = (cppVar_92555 == 144);
	if (cppVar_92557) {
	cppVar_92552 = P1;
	} else {
	BIT_VEC cppVar_92558;
	BIT_VEC cppVar_92559 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_92560 = (cppVar_92559 << 3) | 7;
	cppVar_92560 = (cppVar_92560 & cppMask_un_5_);
	BIT_VEC cppVar_92561 = (0 << 5) | cppVar_92560;
	cppVar_92561 = (cppVar_92561 & cppMask_un_8_);
	bool cppVar_92563 = (cppVar_92561 == 152);
	if (cppVar_92563) {
	cppVar_92558 = SCON;
	} else {
	BIT_VEC cppVar_92564;
	BIT_VEC cppVar_92565 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_92566 = (cppVar_92565 << 3) | 7;
	cppVar_92566 = (cppVar_92566 & cppMask_un_5_);
	BIT_VEC cppVar_92567 = (0 << 5) | cppVar_92566;
	cppVar_92567 = (cppVar_92567 & cppMask_un_8_);
	bool cppVar_92569 = (cppVar_92567 == 153);
	if (cppVar_92569) {
	cppVar_92564 = SBUF;
	} else {
	BIT_VEC cppVar_92570;
	BIT_VEC cppVar_92571 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_92572 = (cppVar_92571 << 3) | 7;
	cppVar_92572 = (cppVar_92572 & cppMask_un_5_);
	BIT_VEC cppVar_92573 = (0 << 5) | cppVar_92572;
	cppVar_92573 = (cppVar_92573 & cppMask_un_8_);
	bool cppVar_92575 = (cppVar_92573 == 160);
	if (cppVar_92575) {
	cppVar_92570 = P2;
	} else {
	BIT_VEC cppVar_92576;
	BIT_VEC cppVar_92577 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_92578 = (cppVar_92577 << 3) | 7;
	cppVar_92578 = (cppVar_92578 & cppMask_un_5_);
	BIT_VEC cppVar_92579 = (0 << 5) | cppVar_92578;
	cppVar_92579 = (cppVar_92579 & cppMask_un_8_);
	bool cppVar_92581 = (cppVar_92579 == 168);
	if (cppVar_92581) {
	cppVar_92576 = IE;
	} else {
	BIT_VEC cppVar_92582;
	BIT_VEC cppVar_92583 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_92584 = (cppVar_92583 << 3) | 7;
	cppVar_92584 = (cppVar_92584 & cppMask_un_5_);
	BIT_VEC cppVar_92585 = (0 << 5) | cppVar_92584;
	cppVar_92585 = (cppVar_92585 & cppMask_un_8_);
	bool cppVar_92587 = (cppVar_92585 == 176);
	if (cppVar_92587) {
	cppVar_92582 = P3;
	} else {
	BIT_VEC cppVar_92588;
	BIT_VEC cppVar_92589 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_92590 = (cppVar_92589 << 3) | 7;
	cppVar_92590 = (cppVar_92590 & cppMask_un_5_);
	BIT_VEC cppVar_92591 = (0 << 5) | cppVar_92590;
	cppVar_92591 = (cppVar_92591 & cppMask_un_8_);
	bool cppVar_92593 = (cppVar_92591 == 184);
	if (cppVar_92593) {
	cppVar_92588 = IP;
	} else {
	BIT_VEC cppVar_92594;
	BIT_VEC cppVar_92595 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_92596 = (cppVar_92595 << 3) | 7;
	cppVar_92596 = (cppVar_92596 & cppMask_un_5_);
	BIT_VEC cppVar_92597 = (0 << 5) | cppVar_92596;
	cppVar_92597 = (cppVar_92597 & cppMask_un_8_);
	bool cppVar_92599 = (cppVar_92597 == 208);
	if (cppVar_92599) {
	cppVar_92594 = PSW;
	} else {
	BIT_VEC cppVar_92600;
	BIT_VEC cppVar_92601 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_92602 = (cppVar_92601 << 3) | 7;
	cppVar_92602 = (cppVar_92602 & cppMask_un_5_);
	BIT_VEC cppVar_92603 = (0 << 5) | cppVar_92602;
	cppVar_92603 = (cppVar_92603 & cppMask_un_8_);
	bool cppVar_92605 = (cppVar_92603 == 224);
	if (cppVar_92605) {
	cppVar_92600 = ACC;
	} else {
	BIT_VEC cppVar_92606;
	BIT_VEC cppVar_92607 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_92608 = (cppVar_92607 << 3) | 7;
	cppVar_92608 = (cppVar_92608 & cppMask_un_5_);
	BIT_VEC cppVar_92609 = (0 << 5) | cppVar_92608;
	cppVar_92609 = (cppVar_92609 & cppMask_un_8_);
	bool cppVar_92611 = (cppVar_92609 == 240);
	if (cppVar_92611) {
	cppVar_92606 = B;
	} else {
	cppVar_92606 = 0;
	}
	cppVar_92600 = cppVar_92606;
	}
	cppVar_92594 = cppVar_92600;
	}
	cppVar_92588 = cppVar_92594;
	}
	cppVar_92582 = cppVar_92588;
	}
	cppVar_92576 = cppVar_92582;
	}
	cppVar_92570 = cppVar_92576;
	}
	cppVar_92564 = cppVar_92570;
	}
	cppVar_92558 = cppVar_92564;
	}
	cppVar_92552 = cppVar_92558;
	}
	cppVar_92546 = cppVar_92552;
	}
	cppVar_92540 = cppVar_92546;
	}
	cppVar_92534 = cppVar_92540;
	}
	cppVar_92528 = cppVar_92534;
	}
	cppVar_92522 = cppVar_92528;
	}
	cppVar_92516 = cppVar_92522;
	}
	cppVar_92510 = cppVar_92516;
	}
	cppVar_92504 = cppVar_92510;
	}
	cppVar_92498 = cppVar_92504;
	}
	cppVar_92492 = cppVar_92498;
	}
	cppVar_92486 = cppVar_92492;
	}
	cppVar_92475 = cppVar_92486;
	}
	BIT_VEC cppVar_92614 = cppVar_92475 - 1;
	cppVar_92614 = (cppVar_92614 & cppMask_un_8_);
	type_mem cppVar_92615 = IRAM;
	cppVar_92615.wr(cppVar_92474, cppVar_92614);
	cppVar_92463 = cppVar_92615;
	} else {
	cppVar_92463 = IRAM;
	}
	cppVar_92455 = cppVar_92463;
	} else {
	type_mem cppVar_92616;
	BIT_VEC cppVar_92617 = ROM.rd(PC);
	bool cppVar_92619 = (cppVar_92617 == 222);
	BIT_VEC cppVar_92620 = ROM.rd(PC);
	bool cppVar_92622 = (cppVar_92620 == 30);
	bool cppVar_92623 = cppVar_92619 || cppVar_92622;
	if (cppVar_92623) {
	type_mem cppVar_92624;
	BIT_VEC cppVar_92626 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_92628 = (cppVar_92626 << 3) | 6;
	cppVar_92628 = (cppVar_92628 & cppMask_un_5_);
	BIT_VEC cppVar_92629 = (0 << 5) | cppVar_92628;
	cppVar_92629 = (cppVar_92629 & cppMask_un_8_);
	BIT_VEC cppVar_92630 = (cppVar_92629 >> 7) & cppMask_un_1_;
	bool cppVar_92632 = (cppVar_92630 == 0);
	if (cppVar_92632) {
	BIT_VEC cppVar_92633 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_92634 = (cppVar_92633 << 3) | 6;
	cppVar_92634 = (cppVar_92634 & cppMask_un_5_);
	BIT_VEC cppVar_92635 = (0 << 5) | cppVar_92634;
	cppVar_92635 = (cppVar_92635 & cppMask_un_8_);
	BIT_VEC cppVar_92636;
	BIT_VEC cppVar_92637 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_92638 = (cppVar_92637 << 3) | 6;
	cppVar_92638 = (cppVar_92638 & cppMask_un_5_);
	BIT_VEC cppVar_92639 = (0 << 5) | cppVar_92638;
	cppVar_92639 = (cppVar_92639 & cppMask_un_8_);
	BIT_VEC cppVar_92640 = (cppVar_92639 >> 7) & cppMask_un_1_;
	bool cppVar_92642 = (cppVar_92640 == 0);
	if (cppVar_92642) {
	BIT_VEC cppVar_92643 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_92644 = (cppVar_92643 << 3) | 6;
	cppVar_92644 = (cppVar_92644 & cppMask_un_5_);
	BIT_VEC cppVar_92645 = (0 << 5) | cppVar_92644;
	cppVar_92645 = (cppVar_92645 & cppMask_un_8_);
	BIT_VEC cppVar_92646 = IRAM.rd(cppVar_92645);
	cppVar_92636 = cppVar_92646;
	} else {
	BIT_VEC cppVar_92647;
	BIT_VEC cppVar_92648 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_92649 = (cppVar_92648 << 3) | 6;
	cppVar_92649 = (cppVar_92649 & cppMask_un_5_);
	BIT_VEC cppVar_92650 = (0 << 5) | cppVar_92649;
	cppVar_92650 = (cppVar_92650 & cppMask_un_8_);
	bool cppVar_92652 = (cppVar_92650 == 128);
	if (cppVar_92652) {
	cppVar_92647 = P0;
	} else {
	BIT_VEC cppVar_92653;
	BIT_VEC cppVar_92654 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_92655 = (cppVar_92654 << 3) | 6;
	cppVar_92655 = (cppVar_92655 & cppMask_un_5_);
	BIT_VEC cppVar_92656 = (0 << 5) | cppVar_92655;
	cppVar_92656 = (cppVar_92656 & cppMask_un_8_);
	bool cppVar_92658 = (cppVar_92656 == 129);
	if (cppVar_92658) {
	cppVar_92653 = SP;
	} else {
	BIT_VEC cppVar_92659;
	BIT_VEC cppVar_92660 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_92661 = (cppVar_92660 << 3) | 6;
	cppVar_92661 = (cppVar_92661 & cppMask_un_5_);
	BIT_VEC cppVar_92662 = (0 << 5) | cppVar_92661;
	cppVar_92662 = (cppVar_92662 & cppMask_un_8_);
	bool cppVar_92664 = (cppVar_92662 == 130);
	if (cppVar_92664) {
	cppVar_92659 = DPL;
	} else {
	BIT_VEC cppVar_92665;
	BIT_VEC cppVar_92666 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_92667 = (cppVar_92666 << 3) | 6;
	cppVar_92667 = (cppVar_92667 & cppMask_un_5_);
	BIT_VEC cppVar_92668 = (0 << 5) | cppVar_92667;
	cppVar_92668 = (cppVar_92668 & cppMask_un_8_);
	bool cppVar_92670 = (cppVar_92668 == 131);
	if (cppVar_92670) {
	cppVar_92665 = DPH;
	} else {
	BIT_VEC cppVar_92671;
	BIT_VEC cppVar_92672 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_92673 = (cppVar_92672 << 3) | 6;
	cppVar_92673 = (cppVar_92673 & cppMask_un_5_);
	BIT_VEC cppVar_92674 = (0 << 5) | cppVar_92673;
	cppVar_92674 = (cppVar_92674 & cppMask_un_8_);
	bool cppVar_92676 = (cppVar_92674 == 135);
	if (cppVar_92676) {
	cppVar_92671 = PCON;
	} else {
	BIT_VEC cppVar_92677;
	BIT_VEC cppVar_92678 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_92679 = (cppVar_92678 << 3) | 6;
	cppVar_92679 = (cppVar_92679 & cppMask_un_5_);
	BIT_VEC cppVar_92680 = (0 << 5) | cppVar_92679;
	cppVar_92680 = (cppVar_92680 & cppMask_un_8_);
	bool cppVar_92682 = (cppVar_92680 == 136);
	if (cppVar_92682) {
	cppVar_92677 = TCON;
	} else {
	BIT_VEC cppVar_92683;
	BIT_VEC cppVar_92684 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_92685 = (cppVar_92684 << 3) | 6;
	cppVar_92685 = (cppVar_92685 & cppMask_un_5_);
	BIT_VEC cppVar_92686 = (0 << 5) | cppVar_92685;
	cppVar_92686 = (cppVar_92686 & cppMask_un_8_);
	bool cppVar_92688 = (cppVar_92686 == 137);
	if (cppVar_92688) {
	cppVar_92683 = TMOD;
	} else {
	BIT_VEC cppVar_92689;
	BIT_VEC cppVar_92690 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_92691 = (cppVar_92690 << 3) | 6;
	cppVar_92691 = (cppVar_92691 & cppMask_un_5_);
	BIT_VEC cppVar_92692 = (0 << 5) | cppVar_92691;
	cppVar_92692 = (cppVar_92692 & cppMask_un_8_);
	bool cppVar_92694 = (cppVar_92692 == 138);
	if (cppVar_92694) {
	cppVar_92689 = TL0;
	} else {
	BIT_VEC cppVar_92695;
	BIT_VEC cppVar_92696 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_92697 = (cppVar_92696 << 3) | 6;
	cppVar_92697 = (cppVar_92697 & cppMask_un_5_);
	BIT_VEC cppVar_92698 = (0 << 5) | cppVar_92697;
	cppVar_92698 = (cppVar_92698 & cppMask_un_8_);
	bool cppVar_92700 = (cppVar_92698 == 140);
	if (cppVar_92700) {
	cppVar_92695 = TH0;
	} else {
	BIT_VEC cppVar_92701;
	BIT_VEC cppVar_92702 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_92703 = (cppVar_92702 << 3) | 6;
	cppVar_92703 = (cppVar_92703 & cppMask_un_5_);
	BIT_VEC cppVar_92704 = (0 << 5) | cppVar_92703;
	cppVar_92704 = (cppVar_92704 & cppMask_un_8_);
	bool cppVar_92706 = (cppVar_92704 == 139);
	if (cppVar_92706) {
	cppVar_92701 = TL1;
	} else {
	BIT_VEC cppVar_92707;
	BIT_VEC cppVar_92708 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_92709 = (cppVar_92708 << 3) | 6;
	cppVar_92709 = (cppVar_92709 & cppMask_un_5_);
	BIT_VEC cppVar_92710 = (0 << 5) | cppVar_92709;
	cppVar_92710 = (cppVar_92710 & cppMask_un_8_);
	bool cppVar_92712 = (cppVar_92710 == 141);
	if (cppVar_92712) {
	cppVar_92707 = TH1;
	} else {
	BIT_VEC cppVar_92713;
	BIT_VEC cppVar_92714 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_92715 = (cppVar_92714 << 3) | 6;
	cppVar_92715 = (cppVar_92715 & cppMask_un_5_);
	BIT_VEC cppVar_92716 = (0 << 5) | cppVar_92715;
	cppVar_92716 = (cppVar_92716 & cppMask_un_8_);
	bool cppVar_92718 = (cppVar_92716 == 144);
	if (cppVar_92718) {
	cppVar_92713 = P1;
	} else {
	BIT_VEC cppVar_92719;
	BIT_VEC cppVar_92720 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_92721 = (cppVar_92720 << 3) | 6;
	cppVar_92721 = (cppVar_92721 & cppMask_un_5_);
	BIT_VEC cppVar_92722 = (0 << 5) | cppVar_92721;
	cppVar_92722 = (cppVar_92722 & cppMask_un_8_);
	bool cppVar_92724 = (cppVar_92722 == 152);
	if (cppVar_92724) {
	cppVar_92719 = SCON;
	} else {
	BIT_VEC cppVar_92725;
	BIT_VEC cppVar_92726 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_92727 = (cppVar_92726 << 3) | 6;
	cppVar_92727 = (cppVar_92727 & cppMask_un_5_);
	BIT_VEC cppVar_92728 = (0 << 5) | cppVar_92727;
	cppVar_92728 = (cppVar_92728 & cppMask_un_8_);
	bool cppVar_92730 = (cppVar_92728 == 153);
	if (cppVar_92730) {
	cppVar_92725 = SBUF;
	} else {
	BIT_VEC cppVar_92731;
	BIT_VEC cppVar_92732 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_92733 = (cppVar_92732 << 3) | 6;
	cppVar_92733 = (cppVar_92733 & cppMask_un_5_);
	BIT_VEC cppVar_92734 = (0 << 5) | cppVar_92733;
	cppVar_92734 = (cppVar_92734 & cppMask_un_8_);
	bool cppVar_92736 = (cppVar_92734 == 160);
	if (cppVar_92736) {
	cppVar_92731 = P2;
	} else {
	BIT_VEC cppVar_92737;
	BIT_VEC cppVar_92738 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_92739 = (cppVar_92738 << 3) | 6;
	cppVar_92739 = (cppVar_92739 & cppMask_un_5_);
	BIT_VEC cppVar_92740 = (0 << 5) | cppVar_92739;
	cppVar_92740 = (cppVar_92740 & cppMask_un_8_);
	bool cppVar_92742 = (cppVar_92740 == 168);
	if (cppVar_92742) {
	cppVar_92737 = IE;
	} else {
	BIT_VEC cppVar_92743;
	BIT_VEC cppVar_92744 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_92745 = (cppVar_92744 << 3) | 6;
	cppVar_92745 = (cppVar_92745 & cppMask_un_5_);
	BIT_VEC cppVar_92746 = (0 << 5) | cppVar_92745;
	cppVar_92746 = (cppVar_92746 & cppMask_un_8_);
	bool cppVar_92748 = (cppVar_92746 == 176);
	if (cppVar_92748) {
	cppVar_92743 = P3;
	} else {
	BIT_VEC cppVar_92749;
	BIT_VEC cppVar_92750 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_92751 = (cppVar_92750 << 3) | 6;
	cppVar_92751 = (cppVar_92751 & cppMask_un_5_);
	BIT_VEC cppVar_92752 = (0 << 5) | cppVar_92751;
	cppVar_92752 = (cppVar_92752 & cppMask_un_8_);
	bool cppVar_92754 = (cppVar_92752 == 184);
	if (cppVar_92754) {
	cppVar_92749 = IP;
	} else {
	BIT_VEC cppVar_92755;
	BIT_VEC cppVar_92756 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_92757 = (cppVar_92756 << 3) | 6;
	cppVar_92757 = (cppVar_92757 & cppMask_un_5_);
	BIT_VEC cppVar_92758 = (0 << 5) | cppVar_92757;
	cppVar_92758 = (cppVar_92758 & cppMask_un_8_);
	bool cppVar_92760 = (cppVar_92758 == 208);
	if (cppVar_92760) {
	cppVar_92755 = PSW;
	} else {
	BIT_VEC cppVar_92761;
	BIT_VEC cppVar_92762 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_92763 = (cppVar_92762 << 3) | 6;
	cppVar_92763 = (cppVar_92763 & cppMask_un_5_);
	BIT_VEC cppVar_92764 = (0 << 5) | cppVar_92763;
	cppVar_92764 = (cppVar_92764 & cppMask_un_8_);
	bool cppVar_92766 = (cppVar_92764 == 224);
	if (cppVar_92766) {
	cppVar_92761 = ACC;
	} else {
	BIT_VEC cppVar_92767;
	BIT_VEC cppVar_92768 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_92769 = (cppVar_92768 << 3) | 6;
	cppVar_92769 = (cppVar_92769 & cppMask_un_5_);
	BIT_VEC cppVar_92770 = (0 << 5) | cppVar_92769;
	cppVar_92770 = (cppVar_92770 & cppMask_un_8_);
	bool cppVar_92772 = (cppVar_92770 == 240);
	if (cppVar_92772) {
	cppVar_92767 = B;
	} else {
	cppVar_92767 = 0;
	}
	cppVar_92761 = cppVar_92767;
	}
	cppVar_92755 = cppVar_92761;
	}
	cppVar_92749 = cppVar_92755;
	}
	cppVar_92743 = cppVar_92749;
	}
	cppVar_92737 = cppVar_92743;
	}
	cppVar_92731 = cppVar_92737;
	}
	cppVar_92725 = cppVar_92731;
	}
	cppVar_92719 = cppVar_92725;
	}
	cppVar_92713 = cppVar_92719;
	}
	cppVar_92707 = cppVar_92713;
	}
	cppVar_92701 = cppVar_92707;
	}
	cppVar_92695 = cppVar_92701;
	}
	cppVar_92689 = cppVar_92695;
	}
	cppVar_92683 = cppVar_92689;
	}
	cppVar_92677 = cppVar_92683;
	}
	cppVar_92671 = cppVar_92677;
	}
	cppVar_92665 = cppVar_92671;
	}
	cppVar_92659 = cppVar_92665;
	}
	cppVar_92653 = cppVar_92659;
	}
	cppVar_92647 = cppVar_92653;
	}
	cppVar_92636 = cppVar_92647;
	}
	BIT_VEC cppVar_92775 = cppVar_92636 - 1;
	cppVar_92775 = (cppVar_92775 & cppMask_un_8_);
	type_mem cppVar_92776 = IRAM;
	cppVar_92776.wr(cppVar_92635, cppVar_92775);
	cppVar_92624 = cppVar_92776;
	} else {
	cppVar_92624 = IRAM;
	}
	cppVar_92616 = cppVar_92624;
	} else {
	type_mem cppVar_92777;
	BIT_VEC cppVar_92778 = ROM.rd(PC);
	bool cppVar_92780 = (cppVar_92778 == 221);
	BIT_VEC cppVar_92781 = ROM.rd(PC);
	bool cppVar_92783 = (cppVar_92781 == 29);
	bool cppVar_92784 = cppVar_92780 || cppVar_92783;
	if (cppVar_92784) {
	type_mem cppVar_92785;
	BIT_VEC cppVar_92787 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_92789 = (cppVar_92787 << 3) | 5;
	cppVar_92789 = (cppVar_92789 & cppMask_un_5_);
	BIT_VEC cppVar_92790 = (0 << 5) | cppVar_92789;
	cppVar_92790 = (cppVar_92790 & cppMask_un_8_);
	BIT_VEC cppVar_92791 = (cppVar_92790 >> 7) & cppMask_un_1_;
	bool cppVar_92793 = (cppVar_92791 == 0);
	if (cppVar_92793) {
	BIT_VEC cppVar_92794 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_92795 = (cppVar_92794 << 3) | 5;
	cppVar_92795 = (cppVar_92795 & cppMask_un_5_);
	BIT_VEC cppVar_92796 = (0 << 5) | cppVar_92795;
	cppVar_92796 = (cppVar_92796 & cppMask_un_8_);
	BIT_VEC cppVar_92797;
	BIT_VEC cppVar_92798 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_92799 = (cppVar_92798 << 3) | 5;
	cppVar_92799 = (cppVar_92799 & cppMask_un_5_);
	BIT_VEC cppVar_92800 = (0 << 5) | cppVar_92799;
	cppVar_92800 = (cppVar_92800 & cppMask_un_8_);
	BIT_VEC cppVar_92801 = (cppVar_92800 >> 7) & cppMask_un_1_;
	bool cppVar_92803 = (cppVar_92801 == 0);
	if (cppVar_92803) {
	BIT_VEC cppVar_92804 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_92805 = (cppVar_92804 << 3) | 5;
	cppVar_92805 = (cppVar_92805 & cppMask_un_5_);
	BIT_VEC cppVar_92806 = (0 << 5) | cppVar_92805;
	cppVar_92806 = (cppVar_92806 & cppMask_un_8_);
	BIT_VEC cppVar_92807 = IRAM.rd(cppVar_92806);
	cppVar_92797 = cppVar_92807;
	} else {
	BIT_VEC cppVar_92808;
	BIT_VEC cppVar_92809 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_92810 = (cppVar_92809 << 3) | 5;
	cppVar_92810 = (cppVar_92810 & cppMask_un_5_);
	BIT_VEC cppVar_92811 = (0 << 5) | cppVar_92810;
	cppVar_92811 = (cppVar_92811 & cppMask_un_8_);
	bool cppVar_92813 = (cppVar_92811 == 128);
	if (cppVar_92813) {
	cppVar_92808 = P0;
	} else {
	BIT_VEC cppVar_92814;
	BIT_VEC cppVar_92815 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_92816 = (cppVar_92815 << 3) | 5;
	cppVar_92816 = (cppVar_92816 & cppMask_un_5_);
	BIT_VEC cppVar_92817 = (0 << 5) | cppVar_92816;
	cppVar_92817 = (cppVar_92817 & cppMask_un_8_);
	bool cppVar_92819 = (cppVar_92817 == 129);
	if (cppVar_92819) {
	cppVar_92814 = SP;
	} else {
	BIT_VEC cppVar_92820;
	BIT_VEC cppVar_92821 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_92822 = (cppVar_92821 << 3) | 5;
	cppVar_92822 = (cppVar_92822 & cppMask_un_5_);
	BIT_VEC cppVar_92823 = (0 << 5) | cppVar_92822;
	cppVar_92823 = (cppVar_92823 & cppMask_un_8_);
	bool cppVar_92825 = (cppVar_92823 == 130);
	if (cppVar_92825) {
	cppVar_92820 = DPL;
	} else {
	BIT_VEC cppVar_92826;
	BIT_VEC cppVar_92827 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_92828 = (cppVar_92827 << 3) | 5;
	cppVar_92828 = (cppVar_92828 & cppMask_un_5_);
	BIT_VEC cppVar_92829 = (0 << 5) | cppVar_92828;
	cppVar_92829 = (cppVar_92829 & cppMask_un_8_);
	bool cppVar_92831 = (cppVar_92829 == 131);
	if (cppVar_92831) {
	cppVar_92826 = DPH;
	} else {
	BIT_VEC cppVar_92832;
	BIT_VEC cppVar_92833 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_92834 = (cppVar_92833 << 3) | 5;
	cppVar_92834 = (cppVar_92834 & cppMask_un_5_);
	BIT_VEC cppVar_92835 = (0 << 5) | cppVar_92834;
	cppVar_92835 = (cppVar_92835 & cppMask_un_8_);
	bool cppVar_92837 = (cppVar_92835 == 135);
	if (cppVar_92837) {
	cppVar_92832 = PCON;
	} else {
	BIT_VEC cppVar_92838;
	BIT_VEC cppVar_92839 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_92840 = (cppVar_92839 << 3) | 5;
	cppVar_92840 = (cppVar_92840 & cppMask_un_5_);
	BIT_VEC cppVar_92841 = (0 << 5) | cppVar_92840;
	cppVar_92841 = (cppVar_92841 & cppMask_un_8_);
	bool cppVar_92843 = (cppVar_92841 == 136);
	if (cppVar_92843) {
	cppVar_92838 = TCON;
	} else {
	BIT_VEC cppVar_92844;
	BIT_VEC cppVar_92845 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_92846 = (cppVar_92845 << 3) | 5;
	cppVar_92846 = (cppVar_92846 & cppMask_un_5_);
	BIT_VEC cppVar_92847 = (0 << 5) | cppVar_92846;
	cppVar_92847 = (cppVar_92847 & cppMask_un_8_);
	bool cppVar_92849 = (cppVar_92847 == 137);
	if (cppVar_92849) {
	cppVar_92844 = TMOD;
	} else {
	BIT_VEC cppVar_92850;
	BIT_VEC cppVar_92851 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_92852 = (cppVar_92851 << 3) | 5;
	cppVar_92852 = (cppVar_92852 & cppMask_un_5_);
	BIT_VEC cppVar_92853 = (0 << 5) | cppVar_92852;
	cppVar_92853 = (cppVar_92853 & cppMask_un_8_);
	bool cppVar_92855 = (cppVar_92853 == 138);
	if (cppVar_92855) {
	cppVar_92850 = TL0;
	} else {
	BIT_VEC cppVar_92856;
	BIT_VEC cppVar_92857 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_92858 = (cppVar_92857 << 3) | 5;
	cppVar_92858 = (cppVar_92858 & cppMask_un_5_);
	BIT_VEC cppVar_92859 = (0 << 5) | cppVar_92858;
	cppVar_92859 = (cppVar_92859 & cppMask_un_8_);
	bool cppVar_92861 = (cppVar_92859 == 140);
	if (cppVar_92861) {
	cppVar_92856 = TH0;
	} else {
	BIT_VEC cppVar_92862;
	BIT_VEC cppVar_92863 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_92864 = (cppVar_92863 << 3) | 5;
	cppVar_92864 = (cppVar_92864 & cppMask_un_5_);
	BIT_VEC cppVar_92865 = (0 << 5) | cppVar_92864;
	cppVar_92865 = (cppVar_92865 & cppMask_un_8_);
	bool cppVar_92867 = (cppVar_92865 == 139);
	if (cppVar_92867) {
	cppVar_92862 = TL1;
	} else {
	BIT_VEC cppVar_92868;
	BIT_VEC cppVar_92869 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_92870 = (cppVar_92869 << 3) | 5;
	cppVar_92870 = (cppVar_92870 & cppMask_un_5_);
	BIT_VEC cppVar_92871 = (0 << 5) | cppVar_92870;
	cppVar_92871 = (cppVar_92871 & cppMask_un_8_);
	bool cppVar_92873 = (cppVar_92871 == 141);
	if (cppVar_92873) {
	cppVar_92868 = TH1;
	} else {
	BIT_VEC cppVar_92874;
	BIT_VEC cppVar_92875 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_92876 = (cppVar_92875 << 3) | 5;
	cppVar_92876 = (cppVar_92876 & cppMask_un_5_);
	BIT_VEC cppVar_92877 = (0 << 5) | cppVar_92876;
	cppVar_92877 = (cppVar_92877 & cppMask_un_8_);
	bool cppVar_92879 = (cppVar_92877 == 144);
	if (cppVar_92879) {
	cppVar_92874 = P1;
	} else {
	BIT_VEC cppVar_92880;
	BIT_VEC cppVar_92881 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_92882 = (cppVar_92881 << 3) | 5;
	cppVar_92882 = (cppVar_92882 & cppMask_un_5_);
	BIT_VEC cppVar_92883 = (0 << 5) | cppVar_92882;
	cppVar_92883 = (cppVar_92883 & cppMask_un_8_);
	bool cppVar_92885 = (cppVar_92883 == 152);
	if (cppVar_92885) {
	cppVar_92880 = SCON;
	} else {
	BIT_VEC cppVar_92886;
	BIT_VEC cppVar_92887 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_92888 = (cppVar_92887 << 3) | 5;
	cppVar_92888 = (cppVar_92888 & cppMask_un_5_);
	BIT_VEC cppVar_92889 = (0 << 5) | cppVar_92888;
	cppVar_92889 = (cppVar_92889 & cppMask_un_8_);
	bool cppVar_92891 = (cppVar_92889 == 153);
	if (cppVar_92891) {
	cppVar_92886 = SBUF;
	} else {
	BIT_VEC cppVar_92892;
	BIT_VEC cppVar_92893 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_92894 = (cppVar_92893 << 3) | 5;
	cppVar_92894 = (cppVar_92894 & cppMask_un_5_);
	BIT_VEC cppVar_92895 = (0 << 5) | cppVar_92894;
	cppVar_92895 = (cppVar_92895 & cppMask_un_8_);
	bool cppVar_92897 = (cppVar_92895 == 160);
	if (cppVar_92897) {
	cppVar_92892 = P2;
	} else {
	BIT_VEC cppVar_92898;
	BIT_VEC cppVar_92899 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_92900 = (cppVar_92899 << 3) | 5;
	cppVar_92900 = (cppVar_92900 & cppMask_un_5_);
	BIT_VEC cppVar_92901 = (0 << 5) | cppVar_92900;
	cppVar_92901 = (cppVar_92901 & cppMask_un_8_);
	bool cppVar_92903 = (cppVar_92901 == 168);
	if (cppVar_92903) {
	cppVar_92898 = IE;
	} else {
	BIT_VEC cppVar_92904;
	BIT_VEC cppVar_92905 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_92906 = (cppVar_92905 << 3) | 5;
	cppVar_92906 = (cppVar_92906 & cppMask_un_5_);
	BIT_VEC cppVar_92907 = (0 << 5) | cppVar_92906;
	cppVar_92907 = (cppVar_92907 & cppMask_un_8_);
	bool cppVar_92909 = (cppVar_92907 == 176);
	if (cppVar_92909) {
	cppVar_92904 = P3;
	} else {
	BIT_VEC cppVar_92910;
	BIT_VEC cppVar_92911 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_92912 = (cppVar_92911 << 3) | 5;
	cppVar_92912 = (cppVar_92912 & cppMask_un_5_);
	BIT_VEC cppVar_92913 = (0 << 5) | cppVar_92912;
	cppVar_92913 = (cppVar_92913 & cppMask_un_8_);
	bool cppVar_92915 = (cppVar_92913 == 184);
	if (cppVar_92915) {
	cppVar_92910 = IP;
	} else {
	BIT_VEC cppVar_92916;
	BIT_VEC cppVar_92917 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_92918 = (cppVar_92917 << 3) | 5;
	cppVar_92918 = (cppVar_92918 & cppMask_un_5_);
	BIT_VEC cppVar_92919 = (0 << 5) | cppVar_92918;
	cppVar_92919 = (cppVar_92919 & cppMask_un_8_);
	bool cppVar_92921 = (cppVar_92919 == 208);
	if (cppVar_92921) {
	cppVar_92916 = PSW;
	} else {
	BIT_VEC cppVar_92922;
	BIT_VEC cppVar_92923 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_92924 = (cppVar_92923 << 3) | 5;
	cppVar_92924 = (cppVar_92924 & cppMask_un_5_);
	BIT_VEC cppVar_92925 = (0 << 5) | cppVar_92924;
	cppVar_92925 = (cppVar_92925 & cppMask_un_8_);
	bool cppVar_92927 = (cppVar_92925 == 224);
	if (cppVar_92927) {
	cppVar_92922 = ACC;
	} else {
	BIT_VEC cppVar_92928;
	BIT_VEC cppVar_92929 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_92930 = (cppVar_92929 << 3) | 5;
	cppVar_92930 = (cppVar_92930 & cppMask_un_5_);
	BIT_VEC cppVar_92931 = (0 << 5) | cppVar_92930;
	cppVar_92931 = (cppVar_92931 & cppMask_un_8_);
	bool cppVar_92933 = (cppVar_92931 == 240);
	if (cppVar_92933) {
	cppVar_92928 = B;
	} else {
	cppVar_92928 = 0;
	}
	cppVar_92922 = cppVar_92928;
	}
	cppVar_92916 = cppVar_92922;
	}
	cppVar_92910 = cppVar_92916;
	}
	cppVar_92904 = cppVar_92910;
	}
	cppVar_92898 = cppVar_92904;
	}
	cppVar_92892 = cppVar_92898;
	}
	cppVar_92886 = cppVar_92892;
	}
	cppVar_92880 = cppVar_92886;
	}
	cppVar_92874 = cppVar_92880;
	}
	cppVar_92868 = cppVar_92874;
	}
	cppVar_92862 = cppVar_92868;
	}
	cppVar_92856 = cppVar_92862;
	}
	cppVar_92850 = cppVar_92856;
	}
	cppVar_92844 = cppVar_92850;
	}
	cppVar_92838 = cppVar_92844;
	}
	cppVar_92832 = cppVar_92838;
	}
	cppVar_92826 = cppVar_92832;
	}
	cppVar_92820 = cppVar_92826;
	}
	cppVar_92814 = cppVar_92820;
	}
	cppVar_92808 = cppVar_92814;
	}
	cppVar_92797 = cppVar_92808;
	}
	BIT_VEC cppVar_92936 = cppVar_92797 - 1;
	cppVar_92936 = (cppVar_92936 & cppMask_un_8_);
	type_mem cppVar_92937 = IRAM;
	cppVar_92937.wr(cppVar_92796, cppVar_92936);
	cppVar_92785 = cppVar_92937;
	} else {
	cppVar_92785 = IRAM;
	}
	cppVar_92777 = cppVar_92785;
	} else {
	type_mem cppVar_92938;
	BIT_VEC cppVar_92939 = ROM.rd(PC);
	bool cppVar_92941 = (cppVar_92939 == 220);
	BIT_VEC cppVar_92942 = ROM.rd(PC);
	bool cppVar_92944 = (cppVar_92942 == 28);
	bool cppVar_92945 = cppVar_92941 || cppVar_92944;
	if (cppVar_92945) {
	type_mem cppVar_92946;
	BIT_VEC cppVar_92948 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_92950 = (cppVar_92948 << 3) | 4;
	cppVar_92950 = (cppVar_92950 & cppMask_un_5_);
	BIT_VEC cppVar_92951 = (0 << 5) | cppVar_92950;
	cppVar_92951 = (cppVar_92951 & cppMask_un_8_);
	BIT_VEC cppVar_92952 = (cppVar_92951 >> 7) & cppMask_un_1_;
	bool cppVar_92954 = (cppVar_92952 == 0);
	if (cppVar_92954) {
	BIT_VEC cppVar_92955 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_92956 = (cppVar_92955 << 3) | 4;
	cppVar_92956 = (cppVar_92956 & cppMask_un_5_);
	BIT_VEC cppVar_92957 = (0 << 5) | cppVar_92956;
	cppVar_92957 = (cppVar_92957 & cppMask_un_8_);
	BIT_VEC cppVar_92958;
	BIT_VEC cppVar_92959 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_92960 = (cppVar_92959 << 3) | 4;
	cppVar_92960 = (cppVar_92960 & cppMask_un_5_);
	BIT_VEC cppVar_92961 = (0 << 5) | cppVar_92960;
	cppVar_92961 = (cppVar_92961 & cppMask_un_8_);
	BIT_VEC cppVar_92962 = (cppVar_92961 >> 7) & cppMask_un_1_;
	bool cppVar_92964 = (cppVar_92962 == 0);
	if (cppVar_92964) {
	BIT_VEC cppVar_92965 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_92966 = (cppVar_92965 << 3) | 4;
	cppVar_92966 = (cppVar_92966 & cppMask_un_5_);
	BIT_VEC cppVar_92967 = (0 << 5) | cppVar_92966;
	cppVar_92967 = (cppVar_92967 & cppMask_un_8_);
	BIT_VEC cppVar_92968 = IRAM.rd(cppVar_92967);
	cppVar_92958 = cppVar_92968;
	} else {
	BIT_VEC cppVar_92969;
	BIT_VEC cppVar_92970 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_92971 = (cppVar_92970 << 3) | 4;
	cppVar_92971 = (cppVar_92971 & cppMask_un_5_);
	BIT_VEC cppVar_92972 = (0 << 5) | cppVar_92971;
	cppVar_92972 = (cppVar_92972 & cppMask_un_8_);
	bool cppVar_92974 = (cppVar_92972 == 128);
	if (cppVar_92974) {
	cppVar_92969 = P0;
	} else {
	BIT_VEC cppVar_92975;
	BIT_VEC cppVar_92976 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_92977 = (cppVar_92976 << 3) | 4;
	cppVar_92977 = (cppVar_92977 & cppMask_un_5_);
	BIT_VEC cppVar_92978 = (0 << 5) | cppVar_92977;
	cppVar_92978 = (cppVar_92978 & cppMask_un_8_);
	bool cppVar_92980 = (cppVar_92978 == 129);
	if (cppVar_92980) {
	cppVar_92975 = SP;
	} else {
	BIT_VEC cppVar_92981;
	BIT_VEC cppVar_92982 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_92983 = (cppVar_92982 << 3) | 4;
	cppVar_92983 = (cppVar_92983 & cppMask_un_5_);
	BIT_VEC cppVar_92984 = (0 << 5) | cppVar_92983;
	cppVar_92984 = (cppVar_92984 & cppMask_un_8_);
	bool cppVar_92986 = (cppVar_92984 == 130);
	if (cppVar_92986) {
	cppVar_92981 = DPL;
	} else {
	BIT_VEC cppVar_92987;
	BIT_VEC cppVar_92988 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_92989 = (cppVar_92988 << 3) | 4;
	cppVar_92989 = (cppVar_92989 & cppMask_un_5_);
	BIT_VEC cppVar_92990 = (0 << 5) | cppVar_92989;
	cppVar_92990 = (cppVar_92990 & cppMask_un_8_);
	bool cppVar_92992 = (cppVar_92990 == 131);
	if (cppVar_92992) {
	cppVar_92987 = DPH;
	} else {
	BIT_VEC cppVar_92993;
	BIT_VEC cppVar_92994 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_92995 = (cppVar_92994 << 3) | 4;
	cppVar_92995 = (cppVar_92995 & cppMask_un_5_);
	BIT_VEC cppVar_92996 = (0 << 5) | cppVar_92995;
	cppVar_92996 = (cppVar_92996 & cppMask_un_8_);
	bool cppVar_92998 = (cppVar_92996 == 135);
	if (cppVar_92998) {
	cppVar_92993 = PCON;
	} else {
	BIT_VEC cppVar_92999;
	BIT_VEC cppVar_93000 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_93001 = (cppVar_93000 << 3) | 4;
	cppVar_93001 = (cppVar_93001 & cppMask_un_5_);
	BIT_VEC cppVar_93002 = (0 << 5) | cppVar_93001;
	cppVar_93002 = (cppVar_93002 & cppMask_un_8_);
	bool cppVar_93004 = (cppVar_93002 == 136);
	if (cppVar_93004) {
	cppVar_92999 = TCON;
	} else {
	BIT_VEC cppVar_93005;
	BIT_VEC cppVar_93006 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_93007 = (cppVar_93006 << 3) | 4;
	cppVar_93007 = (cppVar_93007 & cppMask_un_5_);
	BIT_VEC cppVar_93008 = (0 << 5) | cppVar_93007;
	cppVar_93008 = (cppVar_93008 & cppMask_un_8_);
	bool cppVar_93010 = (cppVar_93008 == 137);
	if (cppVar_93010) {
	cppVar_93005 = TMOD;
	} else {
	BIT_VEC cppVar_93011;
	BIT_VEC cppVar_93012 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_93013 = (cppVar_93012 << 3) | 4;
	cppVar_93013 = (cppVar_93013 & cppMask_un_5_);
	BIT_VEC cppVar_93014 = (0 << 5) | cppVar_93013;
	cppVar_93014 = (cppVar_93014 & cppMask_un_8_);
	bool cppVar_93016 = (cppVar_93014 == 138);
	if (cppVar_93016) {
	cppVar_93011 = TL0;
	} else {
	BIT_VEC cppVar_93017;
	BIT_VEC cppVar_93018 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_93019 = (cppVar_93018 << 3) | 4;
	cppVar_93019 = (cppVar_93019 & cppMask_un_5_);
	BIT_VEC cppVar_93020 = (0 << 5) | cppVar_93019;
	cppVar_93020 = (cppVar_93020 & cppMask_un_8_);
	bool cppVar_93022 = (cppVar_93020 == 140);
	if (cppVar_93022) {
	cppVar_93017 = TH0;
	} else {
	BIT_VEC cppVar_93023;
	BIT_VEC cppVar_93024 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_93025 = (cppVar_93024 << 3) | 4;
	cppVar_93025 = (cppVar_93025 & cppMask_un_5_);
	BIT_VEC cppVar_93026 = (0 << 5) | cppVar_93025;
	cppVar_93026 = (cppVar_93026 & cppMask_un_8_);
	bool cppVar_93028 = (cppVar_93026 == 139);
	if (cppVar_93028) {
	cppVar_93023 = TL1;
	} else {
	BIT_VEC cppVar_93029;
	BIT_VEC cppVar_93030 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_93031 = (cppVar_93030 << 3) | 4;
	cppVar_93031 = (cppVar_93031 & cppMask_un_5_);
	BIT_VEC cppVar_93032 = (0 << 5) | cppVar_93031;
	cppVar_93032 = (cppVar_93032 & cppMask_un_8_);
	bool cppVar_93034 = (cppVar_93032 == 141);
	if (cppVar_93034) {
	cppVar_93029 = TH1;
	} else {
	BIT_VEC cppVar_93035;
	BIT_VEC cppVar_93036 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_93037 = (cppVar_93036 << 3) | 4;
	cppVar_93037 = (cppVar_93037 & cppMask_un_5_);
	BIT_VEC cppVar_93038 = (0 << 5) | cppVar_93037;
	cppVar_93038 = (cppVar_93038 & cppMask_un_8_);
	bool cppVar_93040 = (cppVar_93038 == 144);
	if (cppVar_93040) {
	cppVar_93035 = P1;
	} else {
	BIT_VEC cppVar_93041;
	BIT_VEC cppVar_93042 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_93043 = (cppVar_93042 << 3) | 4;
	cppVar_93043 = (cppVar_93043 & cppMask_un_5_);
	BIT_VEC cppVar_93044 = (0 << 5) | cppVar_93043;
	cppVar_93044 = (cppVar_93044 & cppMask_un_8_);
	bool cppVar_93046 = (cppVar_93044 == 152);
	if (cppVar_93046) {
	cppVar_93041 = SCON;
	} else {
	BIT_VEC cppVar_93047;
	BIT_VEC cppVar_93048 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_93049 = (cppVar_93048 << 3) | 4;
	cppVar_93049 = (cppVar_93049 & cppMask_un_5_);
	BIT_VEC cppVar_93050 = (0 << 5) | cppVar_93049;
	cppVar_93050 = (cppVar_93050 & cppMask_un_8_);
	bool cppVar_93052 = (cppVar_93050 == 153);
	if (cppVar_93052) {
	cppVar_93047 = SBUF;
	} else {
	BIT_VEC cppVar_93053;
	BIT_VEC cppVar_93054 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_93055 = (cppVar_93054 << 3) | 4;
	cppVar_93055 = (cppVar_93055 & cppMask_un_5_);
	BIT_VEC cppVar_93056 = (0 << 5) | cppVar_93055;
	cppVar_93056 = (cppVar_93056 & cppMask_un_8_);
	bool cppVar_93058 = (cppVar_93056 == 160);
	if (cppVar_93058) {
	cppVar_93053 = P2;
	} else {
	BIT_VEC cppVar_93059;
	BIT_VEC cppVar_93060 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_93061 = (cppVar_93060 << 3) | 4;
	cppVar_93061 = (cppVar_93061 & cppMask_un_5_);
	BIT_VEC cppVar_93062 = (0 << 5) | cppVar_93061;
	cppVar_93062 = (cppVar_93062 & cppMask_un_8_);
	bool cppVar_93064 = (cppVar_93062 == 168);
	if (cppVar_93064) {
	cppVar_93059 = IE;
	} else {
	BIT_VEC cppVar_93065;
	BIT_VEC cppVar_93066 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_93067 = (cppVar_93066 << 3) | 4;
	cppVar_93067 = (cppVar_93067 & cppMask_un_5_);
	BIT_VEC cppVar_93068 = (0 << 5) | cppVar_93067;
	cppVar_93068 = (cppVar_93068 & cppMask_un_8_);
	bool cppVar_93070 = (cppVar_93068 == 176);
	if (cppVar_93070) {
	cppVar_93065 = P3;
	} else {
	BIT_VEC cppVar_93071;
	BIT_VEC cppVar_93072 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_93073 = (cppVar_93072 << 3) | 4;
	cppVar_93073 = (cppVar_93073 & cppMask_un_5_);
	BIT_VEC cppVar_93074 = (0 << 5) | cppVar_93073;
	cppVar_93074 = (cppVar_93074 & cppMask_un_8_);
	bool cppVar_93076 = (cppVar_93074 == 184);
	if (cppVar_93076) {
	cppVar_93071 = IP;
	} else {
	BIT_VEC cppVar_93077;
	BIT_VEC cppVar_93078 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_93079 = (cppVar_93078 << 3) | 4;
	cppVar_93079 = (cppVar_93079 & cppMask_un_5_);
	BIT_VEC cppVar_93080 = (0 << 5) | cppVar_93079;
	cppVar_93080 = (cppVar_93080 & cppMask_un_8_);
	bool cppVar_93082 = (cppVar_93080 == 208);
	if (cppVar_93082) {
	cppVar_93077 = PSW;
	} else {
	BIT_VEC cppVar_93083;
	BIT_VEC cppVar_93084 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_93085 = (cppVar_93084 << 3) | 4;
	cppVar_93085 = (cppVar_93085 & cppMask_un_5_);
	BIT_VEC cppVar_93086 = (0 << 5) | cppVar_93085;
	cppVar_93086 = (cppVar_93086 & cppMask_un_8_);
	bool cppVar_93088 = (cppVar_93086 == 224);
	if (cppVar_93088) {
	cppVar_93083 = ACC;
	} else {
	BIT_VEC cppVar_93089;
	BIT_VEC cppVar_93090 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_93091 = (cppVar_93090 << 3) | 4;
	cppVar_93091 = (cppVar_93091 & cppMask_un_5_);
	BIT_VEC cppVar_93092 = (0 << 5) | cppVar_93091;
	cppVar_93092 = (cppVar_93092 & cppMask_un_8_);
	bool cppVar_93094 = (cppVar_93092 == 240);
	if (cppVar_93094) {
	cppVar_93089 = B;
	} else {
	cppVar_93089 = 0;
	}
	cppVar_93083 = cppVar_93089;
	}
	cppVar_93077 = cppVar_93083;
	}
	cppVar_93071 = cppVar_93077;
	}
	cppVar_93065 = cppVar_93071;
	}
	cppVar_93059 = cppVar_93065;
	}
	cppVar_93053 = cppVar_93059;
	}
	cppVar_93047 = cppVar_93053;
	}
	cppVar_93041 = cppVar_93047;
	}
	cppVar_93035 = cppVar_93041;
	}
	cppVar_93029 = cppVar_93035;
	}
	cppVar_93023 = cppVar_93029;
	}
	cppVar_93017 = cppVar_93023;
	}
	cppVar_93011 = cppVar_93017;
	}
	cppVar_93005 = cppVar_93011;
	}
	cppVar_92999 = cppVar_93005;
	}
	cppVar_92993 = cppVar_92999;
	}
	cppVar_92987 = cppVar_92993;
	}
	cppVar_92981 = cppVar_92987;
	}
	cppVar_92975 = cppVar_92981;
	}
	cppVar_92969 = cppVar_92975;
	}
	cppVar_92958 = cppVar_92969;
	}
	BIT_VEC cppVar_93097 = cppVar_92958 - 1;
	cppVar_93097 = (cppVar_93097 & cppMask_un_8_);
	type_mem cppVar_93098 = IRAM;
	cppVar_93098.wr(cppVar_92957, cppVar_93097);
	cppVar_92946 = cppVar_93098;
	} else {
	cppVar_92946 = IRAM;
	}
	cppVar_92938 = cppVar_92946;
	} else {
	type_mem cppVar_93099;
	BIT_VEC cppVar_93100 = ROM.rd(PC);
	bool cppVar_93102 = (cppVar_93100 == 219);
	BIT_VEC cppVar_93103 = ROM.rd(PC);
	bool cppVar_93105 = (cppVar_93103 == 27);
	bool cppVar_93106 = cppVar_93102 || cppVar_93105;
	if (cppVar_93106) {
	type_mem cppVar_93107;
	BIT_VEC cppVar_93109 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_93111 = (cppVar_93109 << 3) | 3;
	cppVar_93111 = (cppVar_93111 & cppMask_un_5_);
	BIT_VEC cppVar_93112 = (0 << 5) | cppVar_93111;
	cppVar_93112 = (cppVar_93112 & cppMask_un_8_);
	BIT_VEC cppVar_93113 = (cppVar_93112 >> 7) & cppMask_un_1_;
	bool cppVar_93115 = (cppVar_93113 == 0);
	if (cppVar_93115) {
	BIT_VEC cppVar_93116 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_93117 = (cppVar_93116 << 3) | 3;
	cppVar_93117 = (cppVar_93117 & cppMask_un_5_);
	BIT_VEC cppVar_93118 = (0 << 5) | cppVar_93117;
	cppVar_93118 = (cppVar_93118 & cppMask_un_8_);
	BIT_VEC cppVar_93119;
	BIT_VEC cppVar_93120 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_93121 = (cppVar_93120 << 3) | 3;
	cppVar_93121 = (cppVar_93121 & cppMask_un_5_);
	BIT_VEC cppVar_93122 = (0 << 5) | cppVar_93121;
	cppVar_93122 = (cppVar_93122 & cppMask_un_8_);
	BIT_VEC cppVar_93123 = (cppVar_93122 >> 7) & cppMask_un_1_;
	bool cppVar_93125 = (cppVar_93123 == 0);
	if (cppVar_93125) {
	BIT_VEC cppVar_93126 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_93127 = (cppVar_93126 << 3) | 3;
	cppVar_93127 = (cppVar_93127 & cppMask_un_5_);
	BIT_VEC cppVar_93128 = (0 << 5) | cppVar_93127;
	cppVar_93128 = (cppVar_93128 & cppMask_un_8_);
	BIT_VEC cppVar_93129 = IRAM.rd(cppVar_93128);
	cppVar_93119 = cppVar_93129;
	} else {
	BIT_VEC cppVar_93130;
	BIT_VEC cppVar_93131 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_93132 = (cppVar_93131 << 3) | 3;
	cppVar_93132 = (cppVar_93132 & cppMask_un_5_);
	BIT_VEC cppVar_93133 = (0 << 5) | cppVar_93132;
	cppVar_93133 = (cppVar_93133 & cppMask_un_8_);
	bool cppVar_93135 = (cppVar_93133 == 128);
	if (cppVar_93135) {
	cppVar_93130 = P0;
	} else {
	BIT_VEC cppVar_93136;
	BIT_VEC cppVar_93137 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_93138 = (cppVar_93137 << 3) | 3;
	cppVar_93138 = (cppVar_93138 & cppMask_un_5_);
	BIT_VEC cppVar_93139 = (0 << 5) | cppVar_93138;
	cppVar_93139 = (cppVar_93139 & cppMask_un_8_);
	bool cppVar_93141 = (cppVar_93139 == 129);
	if (cppVar_93141) {
	cppVar_93136 = SP;
	} else {
	BIT_VEC cppVar_93142;
	BIT_VEC cppVar_93143 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_93144 = (cppVar_93143 << 3) | 3;
	cppVar_93144 = (cppVar_93144 & cppMask_un_5_);
	BIT_VEC cppVar_93145 = (0 << 5) | cppVar_93144;
	cppVar_93145 = (cppVar_93145 & cppMask_un_8_);
	bool cppVar_93147 = (cppVar_93145 == 130);
	if (cppVar_93147) {
	cppVar_93142 = DPL;
	} else {
	BIT_VEC cppVar_93148;
	BIT_VEC cppVar_93149 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_93150 = (cppVar_93149 << 3) | 3;
	cppVar_93150 = (cppVar_93150 & cppMask_un_5_);
	BIT_VEC cppVar_93151 = (0 << 5) | cppVar_93150;
	cppVar_93151 = (cppVar_93151 & cppMask_un_8_);
	bool cppVar_93153 = (cppVar_93151 == 131);
	if (cppVar_93153) {
	cppVar_93148 = DPH;
	} else {
	BIT_VEC cppVar_93154;
	BIT_VEC cppVar_93155 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_93156 = (cppVar_93155 << 3) | 3;
	cppVar_93156 = (cppVar_93156 & cppMask_un_5_);
	BIT_VEC cppVar_93157 = (0 << 5) | cppVar_93156;
	cppVar_93157 = (cppVar_93157 & cppMask_un_8_);
	bool cppVar_93159 = (cppVar_93157 == 135);
	if (cppVar_93159) {
	cppVar_93154 = PCON;
	} else {
	BIT_VEC cppVar_93160;
	BIT_VEC cppVar_93161 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_93162 = (cppVar_93161 << 3) | 3;
	cppVar_93162 = (cppVar_93162 & cppMask_un_5_);
	BIT_VEC cppVar_93163 = (0 << 5) | cppVar_93162;
	cppVar_93163 = (cppVar_93163 & cppMask_un_8_);
	bool cppVar_93165 = (cppVar_93163 == 136);
	if (cppVar_93165) {
	cppVar_93160 = TCON;
	} else {
	BIT_VEC cppVar_93166;
	BIT_VEC cppVar_93167 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_93168 = (cppVar_93167 << 3) | 3;
	cppVar_93168 = (cppVar_93168 & cppMask_un_5_);
	BIT_VEC cppVar_93169 = (0 << 5) | cppVar_93168;
	cppVar_93169 = (cppVar_93169 & cppMask_un_8_);
	bool cppVar_93171 = (cppVar_93169 == 137);
	if (cppVar_93171) {
	cppVar_93166 = TMOD;
	} else {
	BIT_VEC cppVar_93172;
	BIT_VEC cppVar_93173 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_93174 = (cppVar_93173 << 3) | 3;
	cppVar_93174 = (cppVar_93174 & cppMask_un_5_);
	BIT_VEC cppVar_93175 = (0 << 5) | cppVar_93174;
	cppVar_93175 = (cppVar_93175 & cppMask_un_8_);
	bool cppVar_93177 = (cppVar_93175 == 138);
	if (cppVar_93177) {
	cppVar_93172 = TL0;
	} else {
	BIT_VEC cppVar_93178;
	BIT_VEC cppVar_93179 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_93180 = (cppVar_93179 << 3) | 3;
	cppVar_93180 = (cppVar_93180 & cppMask_un_5_);
	BIT_VEC cppVar_93181 = (0 << 5) | cppVar_93180;
	cppVar_93181 = (cppVar_93181 & cppMask_un_8_);
	bool cppVar_93183 = (cppVar_93181 == 140);
	if (cppVar_93183) {
	cppVar_93178 = TH0;
	} else {
	BIT_VEC cppVar_93184;
	BIT_VEC cppVar_93185 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_93186 = (cppVar_93185 << 3) | 3;
	cppVar_93186 = (cppVar_93186 & cppMask_un_5_);
	BIT_VEC cppVar_93187 = (0 << 5) | cppVar_93186;
	cppVar_93187 = (cppVar_93187 & cppMask_un_8_);
	bool cppVar_93189 = (cppVar_93187 == 139);
	if (cppVar_93189) {
	cppVar_93184 = TL1;
	} else {
	BIT_VEC cppVar_93190;
	BIT_VEC cppVar_93191 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_93192 = (cppVar_93191 << 3) | 3;
	cppVar_93192 = (cppVar_93192 & cppMask_un_5_);
	BIT_VEC cppVar_93193 = (0 << 5) | cppVar_93192;
	cppVar_93193 = (cppVar_93193 & cppMask_un_8_);
	bool cppVar_93195 = (cppVar_93193 == 141);
	if (cppVar_93195) {
	cppVar_93190 = TH1;
	} else {
	BIT_VEC cppVar_93196;
	BIT_VEC cppVar_93197 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_93198 = (cppVar_93197 << 3) | 3;
	cppVar_93198 = (cppVar_93198 & cppMask_un_5_);
	BIT_VEC cppVar_93199 = (0 << 5) | cppVar_93198;
	cppVar_93199 = (cppVar_93199 & cppMask_un_8_);
	bool cppVar_93201 = (cppVar_93199 == 144);
	if (cppVar_93201) {
	cppVar_93196 = P1;
	} else {
	BIT_VEC cppVar_93202;
	BIT_VEC cppVar_93203 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_93204 = (cppVar_93203 << 3) | 3;
	cppVar_93204 = (cppVar_93204 & cppMask_un_5_);
	BIT_VEC cppVar_93205 = (0 << 5) | cppVar_93204;
	cppVar_93205 = (cppVar_93205 & cppMask_un_8_);
	bool cppVar_93207 = (cppVar_93205 == 152);
	if (cppVar_93207) {
	cppVar_93202 = SCON;
	} else {
	BIT_VEC cppVar_93208;
	BIT_VEC cppVar_93209 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_93210 = (cppVar_93209 << 3) | 3;
	cppVar_93210 = (cppVar_93210 & cppMask_un_5_);
	BIT_VEC cppVar_93211 = (0 << 5) | cppVar_93210;
	cppVar_93211 = (cppVar_93211 & cppMask_un_8_);
	bool cppVar_93213 = (cppVar_93211 == 153);
	if (cppVar_93213) {
	cppVar_93208 = SBUF;
	} else {
	BIT_VEC cppVar_93214;
	BIT_VEC cppVar_93215 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_93216 = (cppVar_93215 << 3) | 3;
	cppVar_93216 = (cppVar_93216 & cppMask_un_5_);
	BIT_VEC cppVar_93217 = (0 << 5) | cppVar_93216;
	cppVar_93217 = (cppVar_93217 & cppMask_un_8_);
	bool cppVar_93219 = (cppVar_93217 == 160);
	if (cppVar_93219) {
	cppVar_93214 = P2;
	} else {
	BIT_VEC cppVar_93220;
	BIT_VEC cppVar_93221 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_93222 = (cppVar_93221 << 3) | 3;
	cppVar_93222 = (cppVar_93222 & cppMask_un_5_);
	BIT_VEC cppVar_93223 = (0 << 5) | cppVar_93222;
	cppVar_93223 = (cppVar_93223 & cppMask_un_8_);
	bool cppVar_93225 = (cppVar_93223 == 168);
	if (cppVar_93225) {
	cppVar_93220 = IE;
	} else {
	BIT_VEC cppVar_93226;
	BIT_VEC cppVar_93227 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_93228 = (cppVar_93227 << 3) | 3;
	cppVar_93228 = (cppVar_93228 & cppMask_un_5_);
	BIT_VEC cppVar_93229 = (0 << 5) | cppVar_93228;
	cppVar_93229 = (cppVar_93229 & cppMask_un_8_);
	bool cppVar_93231 = (cppVar_93229 == 176);
	if (cppVar_93231) {
	cppVar_93226 = P3;
	} else {
	BIT_VEC cppVar_93232;
	BIT_VEC cppVar_93233 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_93234 = (cppVar_93233 << 3) | 3;
	cppVar_93234 = (cppVar_93234 & cppMask_un_5_);
	BIT_VEC cppVar_93235 = (0 << 5) | cppVar_93234;
	cppVar_93235 = (cppVar_93235 & cppMask_un_8_);
	bool cppVar_93237 = (cppVar_93235 == 184);
	if (cppVar_93237) {
	cppVar_93232 = IP;
	} else {
	BIT_VEC cppVar_93238;
	BIT_VEC cppVar_93239 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_93240 = (cppVar_93239 << 3) | 3;
	cppVar_93240 = (cppVar_93240 & cppMask_un_5_);
	BIT_VEC cppVar_93241 = (0 << 5) | cppVar_93240;
	cppVar_93241 = (cppVar_93241 & cppMask_un_8_);
	bool cppVar_93243 = (cppVar_93241 == 208);
	if (cppVar_93243) {
	cppVar_93238 = PSW;
	} else {
	BIT_VEC cppVar_93244;
	BIT_VEC cppVar_93245 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_93246 = (cppVar_93245 << 3) | 3;
	cppVar_93246 = (cppVar_93246 & cppMask_un_5_);
	BIT_VEC cppVar_93247 = (0 << 5) | cppVar_93246;
	cppVar_93247 = (cppVar_93247 & cppMask_un_8_);
	bool cppVar_93249 = (cppVar_93247 == 224);
	if (cppVar_93249) {
	cppVar_93244 = ACC;
	} else {
	BIT_VEC cppVar_93250;
	BIT_VEC cppVar_93251 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_93252 = (cppVar_93251 << 3) | 3;
	cppVar_93252 = (cppVar_93252 & cppMask_un_5_);
	BIT_VEC cppVar_93253 = (0 << 5) | cppVar_93252;
	cppVar_93253 = (cppVar_93253 & cppMask_un_8_);
	bool cppVar_93255 = (cppVar_93253 == 240);
	if (cppVar_93255) {
	cppVar_93250 = B;
	} else {
	cppVar_93250 = 0;
	}
	cppVar_93244 = cppVar_93250;
	}
	cppVar_93238 = cppVar_93244;
	}
	cppVar_93232 = cppVar_93238;
	}
	cppVar_93226 = cppVar_93232;
	}
	cppVar_93220 = cppVar_93226;
	}
	cppVar_93214 = cppVar_93220;
	}
	cppVar_93208 = cppVar_93214;
	}
	cppVar_93202 = cppVar_93208;
	}
	cppVar_93196 = cppVar_93202;
	}
	cppVar_93190 = cppVar_93196;
	}
	cppVar_93184 = cppVar_93190;
	}
	cppVar_93178 = cppVar_93184;
	}
	cppVar_93172 = cppVar_93178;
	}
	cppVar_93166 = cppVar_93172;
	}
	cppVar_93160 = cppVar_93166;
	}
	cppVar_93154 = cppVar_93160;
	}
	cppVar_93148 = cppVar_93154;
	}
	cppVar_93142 = cppVar_93148;
	}
	cppVar_93136 = cppVar_93142;
	}
	cppVar_93130 = cppVar_93136;
	}
	cppVar_93119 = cppVar_93130;
	}
	BIT_VEC cppVar_93258 = cppVar_93119 - 1;
	cppVar_93258 = (cppVar_93258 & cppMask_un_8_);
	type_mem cppVar_93259 = IRAM;
	cppVar_93259.wr(cppVar_93118, cppVar_93258);
	cppVar_93107 = cppVar_93259;
	} else {
	cppVar_93107 = IRAM;
	}
	cppVar_93099 = cppVar_93107;
	} else {
	type_mem cppVar_93260;
	BIT_VEC cppVar_93261 = ROM.rd(PC);
	bool cppVar_93263 = (cppVar_93261 == 218);
	BIT_VEC cppVar_93264 = ROM.rd(PC);
	bool cppVar_93266 = (cppVar_93264 == 26);
	bool cppVar_93267 = cppVar_93263 || cppVar_93266;
	if (cppVar_93267) {
	type_mem cppVar_93268;
	BIT_VEC cppVar_93270 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_93272 = (cppVar_93270 << 3) | 2;
	cppVar_93272 = (cppVar_93272 & cppMask_un_5_);
	BIT_VEC cppVar_93273 = (0 << 5) | cppVar_93272;
	cppVar_93273 = (cppVar_93273 & cppMask_un_8_);
	BIT_VEC cppVar_93274 = (cppVar_93273 >> 7) & cppMask_un_1_;
	bool cppVar_93276 = (cppVar_93274 == 0);
	if (cppVar_93276) {
	BIT_VEC cppVar_93277 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_93278 = (cppVar_93277 << 3) | 2;
	cppVar_93278 = (cppVar_93278 & cppMask_un_5_);
	BIT_VEC cppVar_93279 = (0 << 5) | cppVar_93278;
	cppVar_93279 = (cppVar_93279 & cppMask_un_8_);
	BIT_VEC cppVar_93280;
	BIT_VEC cppVar_93281 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_93282 = (cppVar_93281 << 3) | 2;
	cppVar_93282 = (cppVar_93282 & cppMask_un_5_);
	BIT_VEC cppVar_93283 = (0 << 5) | cppVar_93282;
	cppVar_93283 = (cppVar_93283 & cppMask_un_8_);
	BIT_VEC cppVar_93284 = (cppVar_93283 >> 7) & cppMask_un_1_;
	bool cppVar_93286 = (cppVar_93284 == 0);
	if (cppVar_93286) {
	BIT_VEC cppVar_93287 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_93288 = (cppVar_93287 << 3) | 2;
	cppVar_93288 = (cppVar_93288 & cppMask_un_5_);
	BIT_VEC cppVar_93289 = (0 << 5) | cppVar_93288;
	cppVar_93289 = (cppVar_93289 & cppMask_un_8_);
	BIT_VEC cppVar_93290 = IRAM.rd(cppVar_93289);
	cppVar_93280 = cppVar_93290;
	} else {
	BIT_VEC cppVar_93291;
	BIT_VEC cppVar_93292 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_93293 = (cppVar_93292 << 3) | 2;
	cppVar_93293 = (cppVar_93293 & cppMask_un_5_);
	BIT_VEC cppVar_93294 = (0 << 5) | cppVar_93293;
	cppVar_93294 = (cppVar_93294 & cppMask_un_8_);
	bool cppVar_93296 = (cppVar_93294 == 128);
	if (cppVar_93296) {
	cppVar_93291 = P0;
	} else {
	BIT_VEC cppVar_93297;
	BIT_VEC cppVar_93298 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_93299 = (cppVar_93298 << 3) | 2;
	cppVar_93299 = (cppVar_93299 & cppMask_un_5_);
	BIT_VEC cppVar_93300 = (0 << 5) | cppVar_93299;
	cppVar_93300 = (cppVar_93300 & cppMask_un_8_);
	bool cppVar_93302 = (cppVar_93300 == 129);
	if (cppVar_93302) {
	cppVar_93297 = SP;
	} else {
	BIT_VEC cppVar_93303;
	BIT_VEC cppVar_93304 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_93305 = (cppVar_93304 << 3) | 2;
	cppVar_93305 = (cppVar_93305 & cppMask_un_5_);
	BIT_VEC cppVar_93306 = (0 << 5) | cppVar_93305;
	cppVar_93306 = (cppVar_93306 & cppMask_un_8_);
	bool cppVar_93308 = (cppVar_93306 == 130);
	if (cppVar_93308) {
	cppVar_93303 = DPL;
	} else {
	BIT_VEC cppVar_93309;
	BIT_VEC cppVar_93310 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_93311 = (cppVar_93310 << 3) | 2;
	cppVar_93311 = (cppVar_93311 & cppMask_un_5_);
	BIT_VEC cppVar_93312 = (0 << 5) | cppVar_93311;
	cppVar_93312 = (cppVar_93312 & cppMask_un_8_);
	bool cppVar_93314 = (cppVar_93312 == 131);
	if (cppVar_93314) {
	cppVar_93309 = DPH;
	} else {
	BIT_VEC cppVar_93315;
	BIT_VEC cppVar_93316 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_93317 = (cppVar_93316 << 3) | 2;
	cppVar_93317 = (cppVar_93317 & cppMask_un_5_);
	BIT_VEC cppVar_93318 = (0 << 5) | cppVar_93317;
	cppVar_93318 = (cppVar_93318 & cppMask_un_8_);
	bool cppVar_93320 = (cppVar_93318 == 135);
	if (cppVar_93320) {
	cppVar_93315 = PCON;
	} else {
	BIT_VEC cppVar_93321;
	BIT_VEC cppVar_93322 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_93323 = (cppVar_93322 << 3) | 2;
	cppVar_93323 = (cppVar_93323 & cppMask_un_5_);
	BIT_VEC cppVar_93324 = (0 << 5) | cppVar_93323;
	cppVar_93324 = (cppVar_93324 & cppMask_un_8_);
	bool cppVar_93326 = (cppVar_93324 == 136);
	if (cppVar_93326) {
	cppVar_93321 = TCON;
	} else {
	BIT_VEC cppVar_93327;
	BIT_VEC cppVar_93328 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_93329 = (cppVar_93328 << 3) | 2;
	cppVar_93329 = (cppVar_93329 & cppMask_un_5_);
	BIT_VEC cppVar_93330 = (0 << 5) | cppVar_93329;
	cppVar_93330 = (cppVar_93330 & cppMask_un_8_);
	bool cppVar_93332 = (cppVar_93330 == 137);
	if (cppVar_93332) {
	cppVar_93327 = TMOD;
	} else {
	BIT_VEC cppVar_93333;
	BIT_VEC cppVar_93334 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_93335 = (cppVar_93334 << 3) | 2;
	cppVar_93335 = (cppVar_93335 & cppMask_un_5_);
	BIT_VEC cppVar_93336 = (0 << 5) | cppVar_93335;
	cppVar_93336 = (cppVar_93336 & cppMask_un_8_);
	bool cppVar_93338 = (cppVar_93336 == 138);
	if (cppVar_93338) {
	cppVar_93333 = TL0;
	} else {
	BIT_VEC cppVar_93339;
	BIT_VEC cppVar_93340 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_93341 = (cppVar_93340 << 3) | 2;
	cppVar_93341 = (cppVar_93341 & cppMask_un_5_);
	BIT_VEC cppVar_93342 = (0 << 5) | cppVar_93341;
	cppVar_93342 = (cppVar_93342 & cppMask_un_8_);
	bool cppVar_93344 = (cppVar_93342 == 140);
	if (cppVar_93344) {
	cppVar_93339 = TH0;
	} else {
	BIT_VEC cppVar_93345;
	BIT_VEC cppVar_93346 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_93347 = (cppVar_93346 << 3) | 2;
	cppVar_93347 = (cppVar_93347 & cppMask_un_5_);
	BIT_VEC cppVar_93348 = (0 << 5) | cppVar_93347;
	cppVar_93348 = (cppVar_93348 & cppMask_un_8_);
	bool cppVar_93350 = (cppVar_93348 == 139);
	if (cppVar_93350) {
	cppVar_93345 = TL1;
	} else {
	BIT_VEC cppVar_93351;
	BIT_VEC cppVar_93352 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_93353 = (cppVar_93352 << 3) | 2;
	cppVar_93353 = (cppVar_93353 & cppMask_un_5_);
	BIT_VEC cppVar_93354 = (0 << 5) | cppVar_93353;
	cppVar_93354 = (cppVar_93354 & cppMask_un_8_);
	bool cppVar_93356 = (cppVar_93354 == 141);
	if (cppVar_93356) {
	cppVar_93351 = TH1;
	} else {
	BIT_VEC cppVar_93357;
	BIT_VEC cppVar_93358 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_93359 = (cppVar_93358 << 3) | 2;
	cppVar_93359 = (cppVar_93359 & cppMask_un_5_);
	BIT_VEC cppVar_93360 = (0 << 5) | cppVar_93359;
	cppVar_93360 = (cppVar_93360 & cppMask_un_8_);
	bool cppVar_93362 = (cppVar_93360 == 144);
	if (cppVar_93362) {
	cppVar_93357 = P1;
	} else {
	BIT_VEC cppVar_93363;
	BIT_VEC cppVar_93364 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_93365 = (cppVar_93364 << 3) | 2;
	cppVar_93365 = (cppVar_93365 & cppMask_un_5_);
	BIT_VEC cppVar_93366 = (0 << 5) | cppVar_93365;
	cppVar_93366 = (cppVar_93366 & cppMask_un_8_);
	bool cppVar_93368 = (cppVar_93366 == 152);
	if (cppVar_93368) {
	cppVar_93363 = SCON;
	} else {
	BIT_VEC cppVar_93369;
	BIT_VEC cppVar_93370 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_93371 = (cppVar_93370 << 3) | 2;
	cppVar_93371 = (cppVar_93371 & cppMask_un_5_);
	BIT_VEC cppVar_93372 = (0 << 5) | cppVar_93371;
	cppVar_93372 = (cppVar_93372 & cppMask_un_8_);
	bool cppVar_93374 = (cppVar_93372 == 153);
	if (cppVar_93374) {
	cppVar_93369 = SBUF;
	} else {
	BIT_VEC cppVar_93375;
	BIT_VEC cppVar_93376 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_93377 = (cppVar_93376 << 3) | 2;
	cppVar_93377 = (cppVar_93377 & cppMask_un_5_);
	BIT_VEC cppVar_93378 = (0 << 5) | cppVar_93377;
	cppVar_93378 = (cppVar_93378 & cppMask_un_8_);
	bool cppVar_93380 = (cppVar_93378 == 160);
	if (cppVar_93380) {
	cppVar_93375 = P2;
	} else {
	BIT_VEC cppVar_93381;
	BIT_VEC cppVar_93382 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_93383 = (cppVar_93382 << 3) | 2;
	cppVar_93383 = (cppVar_93383 & cppMask_un_5_);
	BIT_VEC cppVar_93384 = (0 << 5) | cppVar_93383;
	cppVar_93384 = (cppVar_93384 & cppMask_un_8_);
	bool cppVar_93386 = (cppVar_93384 == 168);
	if (cppVar_93386) {
	cppVar_93381 = IE;
	} else {
	BIT_VEC cppVar_93387;
	BIT_VEC cppVar_93388 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_93389 = (cppVar_93388 << 3) | 2;
	cppVar_93389 = (cppVar_93389 & cppMask_un_5_);
	BIT_VEC cppVar_93390 = (0 << 5) | cppVar_93389;
	cppVar_93390 = (cppVar_93390 & cppMask_un_8_);
	bool cppVar_93392 = (cppVar_93390 == 176);
	if (cppVar_93392) {
	cppVar_93387 = P3;
	} else {
	BIT_VEC cppVar_93393;
	BIT_VEC cppVar_93394 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_93395 = (cppVar_93394 << 3) | 2;
	cppVar_93395 = (cppVar_93395 & cppMask_un_5_);
	BIT_VEC cppVar_93396 = (0 << 5) | cppVar_93395;
	cppVar_93396 = (cppVar_93396 & cppMask_un_8_);
	bool cppVar_93398 = (cppVar_93396 == 184);
	if (cppVar_93398) {
	cppVar_93393 = IP;
	} else {
	BIT_VEC cppVar_93399;
	BIT_VEC cppVar_93400 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_93401 = (cppVar_93400 << 3) | 2;
	cppVar_93401 = (cppVar_93401 & cppMask_un_5_);
	BIT_VEC cppVar_93402 = (0 << 5) | cppVar_93401;
	cppVar_93402 = (cppVar_93402 & cppMask_un_8_);
	bool cppVar_93404 = (cppVar_93402 == 208);
	if (cppVar_93404) {
	cppVar_93399 = PSW;
	} else {
	BIT_VEC cppVar_93405;
	BIT_VEC cppVar_93406 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_93407 = (cppVar_93406 << 3) | 2;
	cppVar_93407 = (cppVar_93407 & cppMask_un_5_);
	BIT_VEC cppVar_93408 = (0 << 5) | cppVar_93407;
	cppVar_93408 = (cppVar_93408 & cppMask_un_8_);
	bool cppVar_93410 = (cppVar_93408 == 224);
	if (cppVar_93410) {
	cppVar_93405 = ACC;
	} else {
	BIT_VEC cppVar_93411;
	BIT_VEC cppVar_93412 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_93413 = (cppVar_93412 << 3) | 2;
	cppVar_93413 = (cppVar_93413 & cppMask_un_5_);
	BIT_VEC cppVar_93414 = (0 << 5) | cppVar_93413;
	cppVar_93414 = (cppVar_93414 & cppMask_un_8_);
	bool cppVar_93416 = (cppVar_93414 == 240);
	if (cppVar_93416) {
	cppVar_93411 = B;
	} else {
	cppVar_93411 = 0;
	}
	cppVar_93405 = cppVar_93411;
	}
	cppVar_93399 = cppVar_93405;
	}
	cppVar_93393 = cppVar_93399;
	}
	cppVar_93387 = cppVar_93393;
	}
	cppVar_93381 = cppVar_93387;
	}
	cppVar_93375 = cppVar_93381;
	}
	cppVar_93369 = cppVar_93375;
	}
	cppVar_93363 = cppVar_93369;
	}
	cppVar_93357 = cppVar_93363;
	}
	cppVar_93351 = cppVar_93357;
	}
	cppVar_93345 = cppVar_93351;
	}
	cppVar_93339 = cppVar_93345;
	}
	cppVar_93333 = cppVar_93339;
	}
	cppVar_93327 = cppVar_93333;
	}
	cppVar_93321 = cppVar_93327;
	}
	cppVar_93315 = cppVar_93321;
	}
	cppVar_93309 = cppVar_93315;
	}
	cppVar_93303 = cppVar_93309;
	}
	cppVar_93297 = cppVar_93303;
	}
	cppVar_93291 = cppVar_93297;
	}
	cppVar_93280 = cppVar_93291;
	}
	BIT_VEC cppVar_93419 = cppVar_93280 - 1;
	cppVar_93419 = (cppVar_93419 & cppMask_un_8_);
	type_mem cppVar_93420 = IRAM;
	cppVar_93420.wr(cppVar_93279, cppVar_93419);
	cppVar_93268 = cppVar_93420;
	} else {
	cppVar_93268 = IRAM;
	}
	cppVar_93260 = cppVar_93268;
	} else {
	type_mem cppVar_93421;
	BIT_VEC cppVar_93422 = ROM.rd(PC);
	bool cppVar_93424 = (cppVar_93422 == 217);
	BIT_VEC cppVar_93425 = ROM.rd(PC);
	bool cppVar_93427 = (cppVar_93425 == 25);
	bool cppVar_93428 = cppVar_93424 || cppVar_93427;
	if (cppVar_93428) {
	type_mem cppVar_93429;
	BIT_VEC cppVar_93431 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_93433 = (cppVar_93431 << 3) | 1;
	cppVar_93433 = (cppVar_93433 & cppMask_un_5_);
	BIT_VEC cppVar_93434 = (0 << 5) | cppVar_93433;
	cppVar_93434 = (cppVar_93434 & cppMask_un_8_);
	BIT_VEC cppVar_93435 = (cppVar_93434 >> 7) & cppMask_un_1_;
	bool cppVar_93437 = (cppVar_93435 == 0);
	if (cppVar_93437) {
	BIT_VEC cppVar_93438 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_93439 = (cppVar_93438 << 3) | 1;
	cppVar_93439 = (cppVar_93439 & cppMask_un_5_);
	BIT_VEC cppVar_93440 = (0 << 5) | cppVar_93439;
	cppVar_93440 = (cppVar_93440 & cppMask_un_8_);
	BIT_VEC cppVar_93441;
	BIT_VEC cppVar_93442 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_93443 = (cppVar_93442 << 3) | 1;
	cppVar_93443 = (cppVar_93443 & cppMask_un_5_);
	BIT_VEC cppVar_93444 = (0 << 5) | cppVar_93443;
	cppVar_93444 = (cppVar_93444 & cppMask_un_8_);
	BIT_VEC cppVar_93445 = (cppVar_93444 >> 7) & cppMask_un_1_;
	bool cppVar_93447 = (cppVar_93445 == 0);
	if (cppVar_93447) {
	BIT_VEC cppVar_93448 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_93449 = (cppVar_93448 << 3) | 1;
	cppVar_93449 = (cppVar_93449 & cppMask_un_5_);
	BIT_VEC cppVar_93450 = (0 << 5) | cppVar_93449;
	cppVar_93450 = (cppVar_93450 & cppMask_un_8_);
	BIT_VEC cppVar_93451 = IRAM.rd(cppVar_93450);
	cppVar_93441 = cppVar_93451;
	} else {
	BIT_VEC cppVar_93452;
	BIT_VEC cppVar_93453 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_93454 = (cppVar_93453 << 3) | 1;
	cppVar_93454 = (cppVar_93454 & cppMask_un_5_);
	BIT_VEC cppVar_93455 = (0 << 5) | cppVar_93454;
	cppVar_93455 = (cppVar_93455 & cppMask_un_8_);
	bool cppVar_93457 = (cppVar_93455 == 128);
	if (cppVar_93457) {
	cppVar_93452 = P0;
	} else {
	BIT_VEC cppVar_93458;
	BIT_VEC cppVar_93459 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_93460 = (cppVar_93459 << 3) | 1;
	cppVar_93460 = (cppVar_93460 & cppMask_un_5_);
	BIT_VEC cppVar_93461 = (0 << 5) | cppVar_93460;
	cppVar_93461 = (cppVar_93461 & cppMask_un_8_);
	bool cppVar_93463 = (cppVar_93461 == 129);
	if (cppVar_93463) {
	cppVar_93458 = SP;
	} else {
	BIT_VEC cppVar_93464;
	BIT_VEC cppVar_93465 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_93466 = (cppVar_93465 << 3) | 1;
	cppVar_93466 = (cppVar_93466 & cppMask_un_5_);
	BIT_VEC cppVar_93467 = (0 << 5) | cppVar_93466;
	cppVar_93467 = (cppVar_93467 & cppMask_un_8_);
	bool cppVar_93469 = (cppVar_93467 == 130);
	if (cppVar_93469) {
	cppVar_93464 = DPL;
	} else {
	BIT_VEC cppVar_93470;
	BIT_VEC cppVar_93471 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_93472 = (cppVar_93471 << 3) | 1;
	cppVar_93472 = (cppVar_93472 & cppMask_un_5_);
	BIT_VEC cppVar_93473 = (0 << 5) | cppVar_93472;
	cppVar_93473 = (cppVar_93473 & cppMask_un_8_);
	bool cppVar_93475 = (cppVar_93473 == 131);
	if (cppVar_93475) {
	cppVar_93470 = DPH;
	} else {
	BIT_VEC cppVar_93476;
	BIT_VEC cppVar_93477 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_93478 = (cppVar_93477 << 3) | 1;
	cppVar_93478 = (cppVar_93478 & cppMask_un_5_);
	BIT_VEC cppVar_93479 = (0 << 5) | cppVar_93478;
	cppVar_93479 = (cppVar_93479 & cppMask_un_8_);
	bool cppVar_93481 = (cppVar_93479 == 135);
	if (cppVar_93481) {
	cppVar_93476 = PCON;
	} else {
	BIT_VEC cppVar_93482;
	BIT_VEC cppVar_93483 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_93484 = (cppVar_93483 << 3) | 1;
	cppVar_93484 = (cppVar_93484 & cppMask_un_5_);
	BIT_VEC cppVar_93485 = (0 << 5) | cppVar_93484;
	cppVar_93485 = (cppVar_93485 & cppMask_un_8_);
	bool cppVar_93487 = (cppVar_93485 == 136);
	if (cppVar_93487) {
	cppVar_93482 = TCON;
	} else {
	BIT_VEC cppVar_93488;
	BIT_VEC cppVar_93489 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_93490 = (cppVar_93489 << 3) | 1;
	cppVar_93490 = (cppVar_93490 & cppMask_un_5_);
	BIT_VEC cppVar_93491 = (0 << 5) | cppVar_93490;
	cppVar_93491 = (cppVar_93491 & cppMask_un_8_);
	bool cppVar_93493 = (cppVar_93491 == 137);
	if (cppVar_93493) {
	cppVar_93488 = TMOD;
	} else {
	BIT_VEC cppVar_93494;
	BIT_VEC cppVar_93495 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_93496 = (cppVar_93495 << 3) | 1;
	cppVar_93496 = (cppVar_93496 & cppMask_un_5_);
	BIT_VEC cppVar_93497 = (0 << 5) | cppVar_93496;
	cppVar_93497 = (cppVar_93497 & cppMask_un_8_);
	bool cppVar_93499 = (cppVar_93497 == 138);
	if (cppVar_93499) {
	cppVar_93494 = TL0;
	} else {
	BIT_VEC cppVar_93500;
	BIT_VEC cppVar_93501 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_93502 = (cppVar_93501 << 3) | 1;
	cppVar_93502 = (cppVar_93502 & cppMask_un_5_);
	BIT_VEC cppVar_93503 = (0 << 5) | cppVar_93502;
	cppVar_93503 = (cppVar_93503 & cppMask_un_8_);
	bool cppVar_93505 = (cppVar_93503 == 140);
	if (cppVar_93505) {
	cppVar_93500 = TH0;
	} else {
	BIT_VEC cppVar_93506;
	BIT_VEC cppVar_93507 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_93508 = (cppVar_93507 << 3) | 1;
	cppVar_93508 = (cppVar_93508 & cppMask_un_5_);
	BIT_VEC cppVar_93509 = (0 << 5) | cppVar_93508;
	cppVar_93509 = (cppVar_93509 & cppMask_un_8_);
	bool cppVar_93511 = (cppVar_93509 == 139);
	if (cppVar_93511) {
	cppVar_93506 = TL1;
	} else {
	BIT_VEC cppVar_93512;
	BIT_VEC cppVar_93513 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_93514 = (cppVar_93513 << 3) | 1;
	cppVar_93514 = (cppVar_93514 & cppMask_un_5_);
	BIT_VEC cppVar_93515 = (0 << 5) | cppVar_93514;
	cppVar_93515 = (cppVar_93515 & cppMask_un_8_);
	bool cppVar_93517 = (cppVar_93515 == 141);
	if (cppVar_93517) {
	cppVar_93512 = TH1;
	} else {
	BIT_VEC cppVar_93518;
	BIT_VEC cppVar_93519 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_93520 = (cppVar_93519 << 3) | 1;
	cppVar_93520 = (cppVar_93520 & cppMask_un_5_);
	BIT_VEC cppVar_93521 = (0 << 5) | cppVar_93520;
	cppVar_93521 = (cppVar_93521 & cppMask_un_8_);
	bool cppVar_93523 = (cppVar_93521 == 144);
	if (cppVar_93523) {
	cppVar_93518 = P1;
	} else {
	BIT_VEC cppVar_93524;
	BIT_VEC cppVar_93525 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_93526 = (cppVar_93525 << 3) | 1;
	cppVar_93526 = (cppVar_93526 & cppMask_un_5_);
	BIT_VEC cppVar_93527 = (0 << 5) | cppVar_93526;
	cppVar_93527 = (cppVar_93527 & cppMask_un_8_);
	bool cppVar_93529 = (cppVar_93527 == 152);
	if (cppVar_93529) {
	cppVar_93524 = SCON;
	} else {
	BIT_VEC cppVar_93530;
	BIT_VEC cppVar_93531 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_93532 = (cppVar_93531 << 3) | 1;
	cppVar_93532 = (cppVar_93532 & cppMask_un_5_);
	BIT_VEC cppVar_93533 = (0 << 5) | cppVar_93532;
	cppVar_93533 = (cppVar_93533 & cppMask_un_8_);
	bool cppVar_93535 = (cppVar_93533 == 153);
	if (cppVar_93535) {
	cppVar_93530 = SBUF;
	} else {
	BIT_VEC cppVar_93536;
	BIT_VEC cppVar_93537 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_93538 = (cppVar_93537 << 3) | 1;
	cppVar_93538 = (cppVar_93538 & cppMask_un_5_);
	BIT_VEC cppVar_93539 = (0 << 5) | cppVar_93538;
	cppVar_93539 = (cppVar_93539 & cppMask_un_8_);
	bool cppVar_93541 = (cppVar_93539 == 160);
	if (cppVar_93541) {
	cppVar_93536 = P2;
	} else {
	BIT_VEC cppVar_93542;
	BIT_VEC cppVar_93543 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_93544 = (cppVar_93543 << 3) | 1;
	cppVar_93544 = (cppVar_93544 & cppMask_un_5_);
	BIT_VEC cppVar_93545 = (0 << 5) | cppVar_93544;
	cppVar_93545 = (cppVar_93545 & cppMask_un_8_);
	bool cppVar_93547 = (cppVar_93545 == 168);
	if (cppVar_93547) {
	cppVar_93542 = IE;
	} else {
	BIT_VEC cppVar_93548;
	BIT_VEC cppVar_93549 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_93550 = (cppVar_93549 << 3) | 1;
	cppVar_93550 = (cppVar_93550 & cppMask_un_5_);
	BIT_VEC cppVar_93551 = (0 << 5) | cppVar_93550;
	cppVar_93551 = (cppVar_93551 & cppMask_un_8_);
	bool cppVar_93553 = (cppVar_93551 == 176);
	if (cppVar_93553) {
	cppVar_93548 = P3;
	} else {
	BIT_VEC cppVar_93554;
	BIT_VEC cppVar_93555 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_93556 = (cppVar_93555 << 3) | 1;
	cppVar_93556 = (cppVar_93556 & cppMask_un_5_);
	BIT_VEC cppVar_93557 = (0 << 5) | cppVar_93556;
	cppVar_93557 = (cppVar_93557 & cppMask_un_8_);
	bool cppVar_93559 = (cppVar_93557 == 184);
	if (cppVar_93559) {
	cppVar_93554 = IP;
	} else {
	BIT_VEC cppVar_93560;
	BIT_VEC cppVar_93561 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_93562 = (cppVar_93561 << 3) | 1;
	cppVar_93562 = (cppVar_93562 & cppMask_un_5_);
	BIT_VEC cppVar_93563 = (0 << 5) | cppVar_93562;
	cppVar_93563 = (cppVar_93563 & cppMask_un_8_);
	bool cppVar_93565 = (cppVar_93563 == 208);
	if (cppVar_93565) {
	cppVar_93560 = PSW;
	} else {
	BIT_VEC cppVar_93566;
	BIT_VEC cppVar_93567 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_93568 = (cppVar_93567 << 3) | 1;
	cppVar_93568 = (cppVar_93568 & cppMask_un_5_);
	BIT_VEC cppVar_93569 = (0 << 5) | cppVar_93568;
	cppVar_93569 = (cppVar_93569 & cppMask_un_8_);
	bool cppVar_93571 = (cppVar_93569 == 224);
	if (cppVar_93571) {
	cppVar_93566 = ACC;
	} else {
	BIT_VEC cppVar_93572;
	BIT_VEC cppVar_93573 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_93574 = (cppVar_93573 << 3) | 1;
	cppVar_93574 = (cppVar_93574 & cppMask_un_5_);
	BIT_VEC cppVar_93575 = (0 << 5) | cppVar_93574;
	cppVar_93575 = (cppVar_93575 & cppMask_un_8_);
	bool cppVar_93577 = (cppVar_93575 == 240);
	if (cppVar_93577) {
	cppVar_93572 = B;
	} else {
	cppVar_93572 = 0;
	}
	cppVar_93566 = cppVar_93572;
	}
	cppVar_93560 = cppVar_93566;
	}
	cppVar_93554 = cppVar_93560;
	}
	cppVar_93548 = cppVar_93554;
	}
	cppVar_93542 = cppVar_93548;
	}
	cppVar_93536 = cppVar_93542;
	}
	cppVar_93530 = cppVar_93536;
	}
	cppVar_93524 = cppVar_93530;
	}
	cppVar_93518 = cppVar_93524;
	}
	cppVar_93512 = cppVar_93518;
	}
	cppVar_93506 = cppVar_93512;
	}
	cppVar_93500 = cppVar_93506;
	}
	cppVar_93494 = cppVar_93500;
	}
	cppVar_93488 = cppVar_93494;
	}
	cppVar_93482 = cppVar_93488;
	}
	cppVar_93476 = cppVar_93482;
	}
	cppVar_93470 = cppVar_93476;
	}
	cppVar_93464 = cppVar_93470;
	}
	cppVar_93458 = cppVar_93464;
	}
	cppVar_93452 = cppVar_93458;
	}
	cppVar_93441 = cppVar_93452;
	}
	BIT_VEC cppVar_93580 = cppVar_93441 - 1;
	cppVar_93580 = (cppVar_93580 & cppMask_un_8_);
	type_mem cppVar_93581 = IRAM;
	cppVar_93581.wr(cppVar_93440, cppVar_93580);
	cppVar_93429 = cppVar_93581;
	} else {
	cppVar_93429 = IRAM;
	}
	cppVar_93421 = cppVar_93429;
	} else {
	type_mem cppVar_93582;
	BIT_VEC cppVar_93583 = ROM.rd(PC);
	bool cppVar_93585 = (cppVar_93583 == 216);
	BIT_VEC cppVar_93586 = ROM.rd(PC);
	bool cppVar_93588 = (cppVar_93586 == 24);
	bool cppVar_93589 = cppVar_93585 || cppVar_93588;
	if (cppVar_93589) {
	type_mem cppVar_93590;
	BIT_VEC cppVar_93592 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_93594 = (cppVar_93592 << 3) | 0;
	cppVar_93594 = (cppVar_93594 & cppMask_un_5_);
	BIT_VEC cppVar_93595 = (0 << 5) | cppVar_93594;
	cppVar_93595 = (cppVar_93595 & cppMask_un_8_);
	BIT_VEC cppVar_93596 = (cppVar_93595 >> 7) & cppMask_un_1_;
	bool cppVar_93598 = (cppVar_93596 == 0);
	if (cppVar_93598) {
	BIT_VEC cppVar_93599 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_93600 = (cppVar_93599 << 3) | 0;
	cppVar_93600 = (cppVar_93600 & cppMask_un_5_);
	BIT_VEC cppVar_93601 = (0 << 5) | cppVar_93600;
	cppVar_93601 = (cppVar_93601 & cppMask_un_8_);
	BIT_VEC cppVar_93602;
	BIT_VEC cppVar_93603 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_93604 = (cppVar_93603 << 3) | 0;
	cppVar_93604 = (cppVar_93604 & cppMask_un_5_);
	BIT_VEC cppVar_93605 = (0 << 5) | cppVar_93604;
	cppVar_93605 = (cppVar_93605 & cppMask_un_8_);
	BIT_VEC cppVar_93606 = (cppVar_93605 >> 7) & cppMask_un_1_;
	bool cppVar_93608 = (cppVar_93606 == 0);
	if (cppVar_93608) {
	BIT_VEC cppVar_93609 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_93610 = (cppVar_93609 << 3) | 0;
	cppVar_93610 = (cppVar_93610 & cppMask_un_5_);
	BIT_VEC cppVar_93611 = (0 << 5) | cppVar_93610;
	cppVar_93611 = (cppVar_93611 & cppMask_un_8_);
	BIT_VEC cppVar_93612 = IRAM.rd(cppVar_93611);
	cppVar_93602 = cppVar_93612;
	} else {
	BIT_VEC cppVar_93613;
	BIT_VEC cppVar_93614 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_93615 = (cppVar_93614 << 3) | 0;
	cppVar_93615 = (cppVar_93615 & cppMask_un_5_);
	BIT_VEC cppVar_93616 = (0 << 5) | cppVar_93615;
	cppVar_93616 = (cppVar_93616 & cppMask_un_8_);
	bool cppVar_93618 = (cppVar_93616 == 128);
	if (cppVar_93618) {
	cppVar_93613 = P0;
	} else {
	BIT_VEC cppVar_93619;
	BIT_VEC cppVar_93620 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_93621 = (cppVar_93620 << 3) | 0;
	cppVar_93621 = (cppVar_93621 & cppMask_un_5_);
	BIT_VEC cppVar_93622 = (0 << 5) | cppVar_93621;
	cppVar_93622 = (cppVar_93622 & cppMask_un_8_);
	bool cppVar_93624 = (cppVar_93622 == 129);
	if (cppVar_93624) {
	cppVar_93619 = SP;
	} else {
	BIT_VEC cppVar_93625;
	BIT_VEC cppVar_93626 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_93627 = (cppVar_93626 << 3) | 0;
	cppVar_93627 = (cppVar_93627 & cppMask_un_5_);
	BIT_VEC cppVar_93628 = (0 << 5) | cppVar_93627;
	cppVar_93628 = (cppVar_93628 & cppMask_un_8_);
	bool cppVar_93630 = (cppVar_93628 == 130);
	if (cppVar_93630) {
	cppVar_93625 = DPL;
	} else {
	BIT_VEC cppVar_93631;
	BIT_VEC cppVar_93632 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_93633 = (cppVar_93632 << 3) | 0;
	cppVar_93633 = (cppVar_93633 & cppMask_un_5_);
	BIT_VEC cppVar_93634 = (0 << 5) | cppVar_93633;
	cppVar_93634 = (cppVar_93634 & cppMask_un_8_);
	bool cppVar_93636 = (cppVar_93634 == 131);
	if (cppVar_93636) {
	cppVar_93631 = DPH;
	} else {
	BIT_VEC cppVar_93637;
	BIT_VEC cppVar_93638 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_93639 = (cppVar_93638 << 3) | 0;
	cppVar_93639 = (cppVar_93639 & cppMask_un_5_);
	BIT_VEC cppVar_93640 = (0 << 5) | cppVar_93639;
	cppVar_93640 = (cppVar_93640 & cppMask_un_8_);
	bool cppVar_93642 = (cppVar_93640 == 135);
	if (cppVar_93642) {
	cppVar_93637 = PCON;
	} else {
	BIT_VEC cppVar_93643;
	BIT_VEC cppVar_93644 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_93645 = (cppVar_93644 << 3) | 0;
	cppVar_93645 = (cppVar_93645 & cppMask_un_5_);
	BIT_VEC cppVar_93646 = (0 << 5) | cppVar_93645;
	cppVar_93646 = (cppVar_93646 & cppMask_un_8_);
	bool cppVar_93648 = (cppVar_93646 == 136);
	if (cppVar_93648) {
	cppVar_93643 = TCON;
	} else {
	BIT_VEC cppVar_93649;
	BIT_VEC cppVar_93650 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_93651 = (cppVar_93650 << 3) | 0;
	cppVar_93651 = (cppVar_93651 & cppMask_un_5_);
	BIT_VEC cppVar_93652 = (0 << 5) | cppVar_93651;
	cppVar_93652 = (cppVar_93652 & cppMask_un_8_);
	bool cppVar_93654 = (cppVar_93652 == 137);
	if (cppVar_93654) {
	cppVar_93649 = TMOD;
	} else {
	BIT_VEC cppVar_93655;
	BIT_VEC cppVar_93656 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_93657 = (cppVar_93656 << 3) | 0;
	cppVar_93657 = (cppVar_93657 & cppMask_un_5_);
	BIT_VEC cppVar_93658 = (0 << 5) | cppVar_93657;
	cppVar_93658 = (cppVar_93658 & cppMask_un_8_);
	bool cppVar_93660 = (cppVar_93658 == 138);
	if (cppVar_93660) {
	cppVar_93655 = TL0;
	} else {
	BIT_VEC cppVar_93661;
	BIT_VEC cppVar_93662 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_93663 = (cppVar_93662 << 3) | 0;
	cppVar_93663 = (cppVar_93663 & cppMask_un_5_);
	BIT_VEC cppVar_93664 = (0 << 5) | cppVar_93663;
	cppVar_93664 = (cppVar_93664 & cppMask_un_8_);
	bool cppVar_93666 = (cppVar_93664 == 140);
	if (cppVar_93666) {
	cppVar_93661 = TH0;
	} else {
	BIT_VEC cppVar_93667;
	BIT_VEC cppVar_93668 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_93669 = (cppVar_93668 << 3) | 0;
	cppVar_93669 = (cppVar_93669 & cppMask_un_5_);
	BIT_VEC cppVar_93670 = (0 << 5) | cppVar_93669;
	cppVar_93670 = (cppVar_93670 & cppMask_un_8_);
	bool cppVar_93672 = (cppVar_93670 == 139);
	if (cppVar_93672) {
	cppVar_93667 = TL1;
	} else {
	BIT_VEC cppVar_93673;
	BIT_VEC cppVar_93674 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_93675 = (cppVar_93674 << 3) | 0;
	cppVar_93675 = (cppVar_93675 & cppMask_un_5_);
	BIT_VEC cppVar_93676 = (0 << 5) | cppVar_93675;
	cppVar_93676 = (cppVar_93676 & cppMask_un_8_);
	bool cppVar_93678 = (cppVar_93676 == 141);
	if (cppVar_93678) {
	cppVar_93673 = TH1;
	} else {
	BIT_VEC cppVar_93679;
	BIT_VEC cppVar_93680 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_93681 = (cppVar_93680 << 3) | 0;
	cppVar_93681 = (cppVar_93681 & cppMask_un_5_);
	BIT_VEC cppVar_93682 = (0 << 5) | cppVar_93681;
	cppVar_93682 = (cppVar_93682 & cppMask_un_8_);
	bool cppVar_93684 = (cppVar_93682 == 144);
	if (cppVar_93684) {
	cppVar_93679 = P1;
	} else {
	BIT_VEC cppVar_93685;
	BIT_VEC cppVar_93686 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_93687 = (cppVar_93686 << 3) | 0;
	cppVar_93687 = (cppVar_93687 & cppMask_un_5_);
	BIT_VEC cppVar_93688 = (0 << 5) | cppVar_93687;
	cppVar_93688 = (cppVar_93688 & cppMask_un_8_);
	bool cppVar_93690 = (cppVar_93688 == 152);
	if (cppVar_93690) {
	cppVar_93685 = SCON;
	} else {
	BIT_VEC cppVar_93691;
	BIT_VEC cppVar_93692 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_93693 = (cppVar_93692 << 3) | 0;
	cppVar_93693 = (cppVar_93693 & cppMask_un_5_);
	BIT_VEC cppVar_93694 = (0 << 5) | cppVar_93693;
	cppVar_93694 = (cppVar_93694 & cppMask_un_8_);
	bool cppVar_93696 = (cppVar_93694 == 153);
	if (cppVar_93696) {
	cppVar_93691 = SBUF;
	} else {
	BIT_VEC cppVar_93697;
	BIT_VEC cppVar_93698 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_93699 = (cppVar_93698 << 3) | 0;
	cppVar_93699 = (cppVar_93699 & cppMask_un_5_);
	BIT_VEC cppVar_93700 = (0 << 5) | cppVar_93699;
	cppVar_93700 = (cppVar_93700 & cppMask_un_8_);
	bool cppVar_93702 = (cppVar_93700 == 160);
	if (cppVar_93702) {
	cppVar_93697 = P2;
	} else {
	BIT_VEC cppVar_93703;
	BIT_VEC cppVar_93704 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_93705 = (cppVar_93704 << 3) | 0;
	cppVar_93705 = (cppVar_93705 & cppMask_un_5_);
	BIT_VEC cppVar_93706 = (0 << 5) | cppVar_93705;
	cppVar_93706 = (cppVar_93706 & cppMask_un_8_);
	bool cppVar_93708 = (cppVar_93706 == 168);
	if (cppVar_93708) {
	cppVar_93703 = IE;
	} else {
	BIT_VEC cppVar_93709;
	BIT_VEC cppVar_93710 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_93711 = (cppVar_93710 << 3) | 0;
	cppVar_93711 = (cppVar_93711 & cppMask_un_5_);
	BIT_VEC cppVar_93712 = (0 << 5) | cppVar_93711;
	cppVar_93712 = (cppVar_93712 & cppMask_un_8_);
	bool cppVar_93714 = (cppVar_93712 == 176);
	if (cppVar_93714) {
	cppVar_93709 = P3;
	} else {
	BIT_VEC cppVar_93715;
	BIT_VEC cppVar_93716 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_93717 = (cppVar_93716 << 3) | 0;
	cppVar_93717 = (cppVar_93717 & cppMask_un_5_);
	BIT_VEC cppVar_93718 = (0 << 5) | cppVar_93717;
	cppVar_93718 = (cppVar_93718 & cppMask_un_8_);
	bool cppVar_93720 = (cppVar_93718 == 184);
	if (cppVar_93720) {
	cppVar_93715 = IP;
	} else {
	BIT_VEC cppVar_93721;
	BIT_VEC cppVar_93722 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_93723 = (cppVar_93722 << 3) | 0;
	cppVar_93723 = (cppVar_93723 & cppMask_un_5_);
	BIT_VEC cppVar_93724 = (0 << 5) | cppVar_93723;
	cppVar_93724 = (cppVar_93724 & cppMask_un_8_);
	bool cppVar_93726 = (cppVar_93724 == 208);
	if (cppVar_93726) {
	cppVar_93721 = PSW;
	} else {
	BIT_VEC cppVar_93727;
	BIT_VEC cppVar_93728 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_93729 = (cppVar_93728 << 3) | 0;
	cppVar_93729 = (cppVar_93729 & cppMask_un_5_);
	BIT_VEC cppVar_93730 = (0 << 5) | cppVar_93729;
	cppVar_93730 = (cppVar_93730 & cppMask_un_8_);
	bool cppVar_93732 = (cppVar_93730 == 224);
	if (cppVar_93732) {
	cppVar_93727 = ACC;
	} else {
	BIT_VEC cppVar_93733;
	BIT_VEC cppVar_93734 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_93735 = (cppVar_93734 << 3) | 0;
	cppVar_93735 = (cppVar_93735 & cppMask_un_5_);
	BIT_VEC cppVar_93736 = (0 << 5) | cppVar_93735;
	cppVar_93736 = (cppVar_93736 & cppMask_un_8_);
	bool cppVar_93738 = (cppVar_93736 == 240);
	if (cppVar_93738) {
	cppVar_93733 = B;
	} else {
	cppVar_93733 = 0;
	}
	cppVar_93727 = cppVar_93733;
	}
	cppVar_93721 = cppVar_93727;
	}
	cppVar_93715 = cppVar_93721;
	}
	cppVar_93709 = cppVar_93715;
	}
	cppVar_93703 = cppVar_93709;
	}
	cppVar_93697 = cppVar_93703;
	}
	cppVar_93691 = cppVar_93697;
	}
	cppVar_93685 = cppVar_93691;
	}
	cppVar_93679 = cppVar_93685;
	}
	cppVar_93673 = cppVar_93679;
	}
	cppVar_93667 = cppVar_93673;
	}
	cppVar_93661 = cppVar_93667;
	}
	cppVar_93655 = cppVar_93661;
	}
	cppVar_93649 = cppVar_93655;
	}
	cppVar_93643 = cppVar_93649;
	}
	cppVar_93637 = cppVar_93643;
	}
	cppVar_93631 = cppVar_93637;
	}
	cppVar_93625 = cppVar_93631;
	}
	cppVar_93619 = cppVar_93625;
	}
	cppVar_93613 = cppVar_93619;
	}
	cppVar_93602 = cppVar_93613;
	}
	BIT_VEC cppVar_93741 = cppVar_93602 - 1;
	cppVar_93741 = (cppVar_93741 & cppMask_un_8_);
	type_mem cppVar_93742 = IRAM;
	cppVar_93742.wr(cppVar_93601, cppVar_93741);
	cppVar_93590 = cppVar_93742;
	} else {
	cppVar_93590 = IRAM;
	}
	cppVar_93582 = cppVar_93590;
	} else {
	type_mem cppVar_93743;
	BIT_VEC cppVar_93744 = ROM.rd(PC);
	bool cppVar_93746 = (cppVar_93744 == 23);
	if (cppVar_93746) {
	BIT_VEC cppVar_93748 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_93750 = (cppVar_93748 << 3) | 1;
	cppVar_93750 = (cppVar_93750 & cppMask_un_5_);
	BIT_VEC cppVar_93751 = (0 << 5) | cppVar_93750;
	cppVar_93751 = (cppVar_93751 & cppMask_un_8_);
	BIT_VEC cppVar_93752 = IRAM.rd(cppVar_93751);
	BIT_VEC cppVar_93753 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_93754 = (cppVar_93753 << 3) | 1;
	cppVar_93754 = (cppVar_93754 & cppMask_un_5_);
	BIT_VEC cppVar_93755 = (0 << 5) | cppVar_93754;
	cppVar_93755 = (cppVar_93755 & cppMask_un_8_);
	BIT_VEC cppVar_93756 = IRAM.rd(cppVar_93755);
	BIT_VEC cppVar_93757 = IRAM.rd(cppVar_93756);
	BIT_VEC cppVar_93759 = cppVar_93757 - 1;
	cppVar_93759 = (cppVar_93759 & cppMask_un_8_);
	type_mem cppVar_93760 = IRAM;
	cppVar_93760.wr(cppVar_93752, cppVar_93759);
	cppVar_93743 = cppVar_93760;
	} else {
	type_mem cppVar_93761;
	BIT_VEC cppVar_93762 = ROM.rd(PC);
	bool cppVar_93764 = (cppVar_93762 == 22);
	if (cppVar_93764) {
	BIT_VEC cppVar_93766 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_93768 = (cppVar_93766 << 3) | 0;
	cppVar_93768 = (cppVar_93768 & cppMask_un_5_);
	BIT_VEC cppVar_93769 = (0 << 5) | cppVar_93768;
	cppVar_93769 = (cppVar_93769 & cppMask_un_8_);
	BIT_VEC cppVar_93770 = IRAM.rd(cppVar_93769);
	BIT_VEC cppVar_93771 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_93772 = (cppVar_93771 << 3) | 0;
	cppVar_93772 = (cppVar_93772 & cppMask_un_5_);
	BIT_VEC cppVar_93773 = (0 << 5) | cppVar_93772;
	cppVar_93773 = (cppVar_93773 & cppMask_un_8_);
	BIT_VEC cppVar_93774 = IRAM.rd(cppVar_93773);
	BIT_VEC cppVar_93775 = IRAM.rd(cppVar_93774);
	BIT_VEC cppVar_93777 = cppVar_93775 - 1;
	cppVar_93777 = (cppVar_93777 & cppMask_un_8_);
	type_mem cppVar_93778 = IRAM;
	cppVar_93778.wr(cppVar_93770, cppVar_93777);
	cppVar_93761 = cppVar_93778;
	} else {
	type_mem cppVar_93779;
	BIT_VEC cppVar_93780 = ROM.rd(PC);
	bool cppVar_93782 = (cppVar_93780 == 213);
	BIT_VEC cppVar_93783 = ROM.rd(PC);
	bool cppVar_93785 = (cppVar_93783 == 21);
	bool cppVar_93786 = cppVar_93782 || cppVar_93785;
	if (cppVar_93786) {
	type_mem cppVar_93787;
	BIT_VEC cppVar_93789 = PC + 1;
	cppVar_93789 = (cppVar_93789 & cppMask_un_16_);
	BIT_VEC cppVar_93790 = ROM.rd(cppVar_93789);
	BIT_VEC cppVar_93791 = (cppVar_93790 >> 7) & cppMask_un_1_;
	bool cppVar_93793 = (cppVar_93791 == 0);
	if (cppVar_93793) {
	BIT_VEC cppVar_93794 = PC + 1;
	cppVar_93794 = (cppVar_93794 & cppMask_un_16_);
	BIT_VEC cppVar_93795 = ROM.rd(cppVar_93794);
	BIT_VEC cppVar_93796;
	BIT_VEC cppVar_93797 = PC + 1;
	cppVar_93797 = (cppVar_93797 & cppMask_un_16_);
	BIT_VEC cppVar_93798 = ROM.rd(cppVar_93797);
	BIT_VEC cppVar_93799 = (cppVar_93798 >> 7) & cppMask_un_1_;
	bool cppVar_93801 = (cppVar_93799 == 0);
	if (cppVar_93801) {
	BIT_VEC cppVar_93802 = PC + 1;
	cppVar_93802 = (cppVar_93802 & cppMask_un_16_);
	BIT_VEC cppVar_93803 = ROM.rd(cppVar_93802);
	BIT_VEC cppVar_93804 = IRAM.rd(cppVar_93803);
	cppVar_93796 = cppVar_93804;
	} else {
	BIT_VEC cppVar_93805;
	BIT_VEC cppVar_93806 = PC + 1;
	cppVar_93806 = (cppVar_93806 & cppMask_un_16_);
	BIT_VEC cppVar_93807 = ROM.rd(cppVar_93806);
	bool cppVar_93809 = (cppVar_93807 == 128);
	if (cppVar_93809) {
	cppVar_93805 = P0;
	} else {
	BIT_VEC cppVar_93810;
	BIT_VEC cppVar_93811 = PC + 1;
	cppVar_93811 = (cppVar_93811 & cppMask_un_16_);
	BIT_VEC cppVar_93812 = ROM.rd(cppVar_93811);
	bool cppVar_93814 = (cppVar_93812 == 129);
	if (cppVar_93814) {
	cppVar_93810 = SP;
	} else {
	BIT_VEC cppVar_93815;
	BIT_VEC cppVar_93816 = PC + 1;
	cppVar_93816 = (cppVar_93816 & cppMask_un_16_);
	BIT_VEC cppVar_93817 = ROM.rd(cppVar_93816);
	bool cppVar_93819 = (cppVar_93817 == 130);
	if (cppVar_93819) {
	cppVar_93815 = DPL;
	} else {
	BIT_VEC cppVar_93820;
	BIT_VEC cppVar_93821 = PC + 1;
	cppVar_93821 = (cppVar_93821 & cppMask_un_16_);
	BIT_VEC cppVar_93822 = ROM.rd(cppVar_93821);
	bool cppVar_93824 = (cppVar_93822 == 131);
	if (cppVar_93824) {
	cppVar_93820 = DPH;
	} else {
	BIT_VEC cppVar_93825;
	BIT_VEC cppVar_93826 = PC + 1;
	cppVar_93826 = (cppVar_93826 & cppMask_un_16_);
	BIT_VEC cppVar_93827 = ROM.rd(cppVar_93826);
	bool cppVar_93829 = (cppVar_93827 == 135);
	if (cppVar_93829) {
	cppVar_93825 = PCON;
	} else {
	BIT_VEC cppVar_93830;
	BIT_VEC cppVar_93831 = PC + 1;
	cppVar_93831 = (cppVar_93831 & cppMask_un_16_);
	BIT_VEC cppVar_93832 = ROM.rd(cppVar_93831);
	bool cppVar_93834 = (cppVar_93832 == 136);
	if (cppVar_93834) {
	cppVar_93830 = TCON;
	} else {
	BIT_VEC cppVar_93835;
	BIT_VEC cppVar_93836 = PC + 1;
	cppVar_93836 = (cppVar_93836 & cppMask_un_16_);
	BIT_VEC cppVar_93837 = ROM.rd(cppVar_93836);
	bool cppVar_93839 = (cppVar_93837 == 137);
	if (cppVar_93839) {
	cppVar_93835 = TMOD;
	} else {
	BIT_VEC cppVar_93840;
	BIT_VEC cppVar_93841 = PC + 1;
	cppVar_93841 = (cppVar_93841 & cppMask_un_16_);
	BIT_VEC cppVar_93842 = ROM.rd(cppVar_93841);
	bool cppVar_93844 = (cppVar_93842 == 138);
	if (cppVar_93844) {
	cppVar_93840 = TL0;
	} else {
	BIT_VEC cppVar_93845;
	BIT_VEC cppVar_93846 = PC + 1;
	cppVar_93846 = (cppVar_93846 & cppMask_un_16_);
	BIT_VEC cppVar_93847 = ROM.rd(cppVar_93846);
	bool cppVar_93849 = (cppVar_93847 == 140);
	if (cppVar_93849) {
	cppVar_93845 = TH0;
	} else {
	BIT_VEC cppVar_93850;
	BIT_VEC cppVar_93851 = PC + 1;
	cppVar_93851 = (cppVar_93851 & cppMask_un_16_);
	BIT_VEC cppVar_93852 = ROM.rd(cppVar_93851);
	bool cppVar_93854 = (cppVar_93852 == 139);
	if (cppVar_93854) {
	cppVar_93850 = TL1;
	} else {
	BIT_VEC cppVar_93855;
	BIT_VEC cppVar_93856 = PC + 1;
	cppVar_93856 = (cppVar_93856 & cppMask_un_16_);
	BIT_VEC cppVar_93857 = ROM.rd(cppVar_93856);
	bool cppVar_93859 = (cppVar_93857 == 141);
	if (cppVar_93859) {
	cppVar_93855 = TH1;
	} else {
	BIT_VEC cppVar_93860;
	BIT_VEC cppVar_93861 = PC + 1;
	cppVar_93861 = (cppVar_93861 & cppMask_un_16_);
	BIT_VEC cppVar_93862 = ROM.rd(cppVar_93861);
	bool cppVar_93864 = (cppVar_93862 == 144);
	if (cppVar_93864) {
	cppVar_93860 = P1;
	} else {
	BIT_VEC cppVar_93865;
	BIT_VEC cppVar_93866 = PC + 1;
	cppVar_93866 = (cppVar_93866 & cppMask_un_16_);
	BIT_VEC cppVar_93867 = ROM.rd(cppVar_93866);
	bool cppVar_93869 = (cppVar_93867 == 152);
	if (cppVar_93869) {
	cppVar_93865 = SCON;
	} else {
	BIT_VEC cppVar_93870;
	BIT_VEC cppVar_93871 = PC + 1;
	cppVar_93871 = (cppVar_93871 & cppMask_un_16_);
	BIT_VEC cppVar_93872 = ROM.rd(cppVar_93871);
	bool cppVar_93874 = (cppVar_93872 == 153);
	if (cppVar_93874) {
	cppVar_93870 = SBUF;
	} else {
	BIT_VEC cppVar_93875;
	BIT_VEC cppVar_93876 = PC + 1;
	cppVar_93876 = (cppVar_93876 & cppMask_un_16_);
	BIT_VEC cppVar_93877 = ROM.rd(cppVar_93876);
	bool cppVar_93879 = (cppVar_93877 == 160);
	if (cppVar_93879) {
	cppVar_93875 = P2;
	} else {
	BIT_VEC cppVar_93880;
	BIT_VEC cppVar_93881 = PC + 1;
	cppVar_93881 = (cppVar_93881 & cppMask_un_16_);
	BIT_VEC cppVar_93882 = ROM.rd(cppVar_93881);
	bool cppVar_93884 = (cppVar_93882 == 168);
	if (cppVar_93884) {
	cppVar_93880 = IE;
	} else {
	BIT_VEC cppVar_93885;
	BIT_VEC cppVar_93886 = PC + 1;
	cppVar_93886 = (cppVar_93886 & cppMask_un_16_);
	BIT_VEC cppVar_93887 = ROM.rd(cppVar_93886);
	bool cppVar_93889 = (cppVar_93887 == 176);
	if (cppVar_93889) {
	cppVar_93885 = P3;
	} else {
	BIT_VEC cppVar_93890;
	BIT_VEC cppVar_93891 = PC + 1;
	cppVar_93891 = (cppVar_93891 & cppMask_un_16_);
	BIT_VEC cppVar_93892 = ROM.rd(cppVar_93891);
	bool cppVar_93894 = (cppVar_93892 == 184);
	if (cppVar_93894) {
	cppVar_93890 = IP;
	} else {
	BIT_VEC cppVar_93895;
	BIT_VEC cppVar_93896 = PC + 1;
	cppVar_93896 = (cppVar_93896 & cppMask_un_16_);
	BIT_VEC cppVar_93897 = ROM.rd(cppVar_93896);
	bool cppVar_93899 = (cppVar_93897 == 208);
	if (cppVar_93899) {
	cppVar_93895 = PSW;
	} else {
	BIT_VEC cppVar_93900;
	BIT_VEC cppVar_93901 = PC + 1;
	cppVar_93901 = (cppVar_93901 & cppMask_un_16_);
	BIT_VEC cppVar_93902 = ROM.rd(cppVar_93901);
	bool cppVar_93904 = (cppVar_93902 == 224);
	if (cppVar_93904) {
	cppVar_93900 = ACC;
	} else {
	BIT_VEC cppVar_93905;
	BIT_VEC cppVar_93906 = PC + 1;
	cppVar_93906 = (cppVar_93906 & cppMask_un_16_);
	BIT_VEC cppVar_93907 = ROM.rd(cppVar_93906);
	bool cppVar_93909 = (cppVar_93907 == 240);
	if (cppVar_93909) {
	cppVar_93905 = B;
	} else {
	cppVar_93905 = 0;
	}
	cppVar_93900 = cppVar_93905;
	}
	cppVar_93895 = cppVar_93900;
	}
	cppVar_93890 = cppVar_93895;
	}
	cppVar_93885 = cppVar_93890;
	}
	cppVar_93880 = cppVar_93885;
	}
	cppVar_93875 = cppVar_93880;
	}
	cppVar_93870 = cppVar_93875;
	}
	cppVar_93865 = cppVar_93870;
	}
	cppVar_93860 = cppVar_93865;
	}
	cppVar_93855 = cppVar_93860;
	}
	cppVar_93850 = cppVar_93855;
	}
	cppVar_93845 = cppVar_93850;
	}
	cppVar_93840 = cppVar_93845;
	}
	cppVar_93835 = cppVar_93840;
	}
	cppVar_93830 = cppVar_93835;
	}
	cppVar_93825 = cppVar_93830;
	}
	cppVar_93820 = cppVar_93825;
	}
	cppVar_93815 = cppVar_93820;
	}
	cppVar_93810 = cppVar_93815;
	}
	cppVar_93805 = cppVar_93810;
	}
	cppVar_93796 = cppVar_93805;
	}
	BIT_VEC cppVar_93912 = cppVar_93796 - 1;
	cppVar_93912 = (cppVar_93912 & cppMask_un_8_);
	type_mem cppVar_93913 = IRAM;
	cppVar_93913.wr(cppVar_93795, cppVar_93912);
	cppVar_93787 = cppVar_93913;
	} else {
	cppVar_93787 = IRAM;
	}
	cppVar_93779 = cppVar_93787;
	} else {
	type_mem cppVar_93914;
	BIT_VEC cppVar_93915 = ROM.rd(PC);
	bool cppVar_93917 = (cppVar_93915 == 18);
	if (cppVar_93917) {
	BIT_VEC cppVar_93919 = SP + 1;
	cppVar_93919 = (cppVar_93919 & cppMask_un_8_);
	BIT_VEC cppVar_93921 = PC + 3;
	cppVar_93921 = (cppVar_93921 & cppMask_un_16_);
	BIT_VEC cppVar_93922 = (cppVar_93921 >> 0) & cppMask_un_8_;
	type_mem cppVar_93923 = IRAM;
	cppVar_93923.wr(cppVar_93919, cppVar_93922);
	BIT_VEC cppVar_93924 = SP + 1;
	cppVar_93924 = (cppVar_93924 & cppMask_un_8_);
	BIT_VEC cppVar_93926 = cppVar_93924 + 1;
	cppVar_93926 = (cppVar_93926 & cppMask_un_8_);
	BIT_VEC cppVar_93927 = PC + 3;
	cppVar_93927 = (cppVar_93927 & cppMask_un_16_);
	BIT_VEC cppVar_93928 = (cppVar_93927 >> 8) & cppMask_un_8_;
	type_mem cppVar_93929 = cppVar_93923;
	cppVar_93929.wr(cppVar_93926, cppVar_93928);
	cppVar_93914 = cppVar_93929;
	} else {
	type_mem cppVar_93930;
	BIT_VEC cppVar_93931 = ROM.rd(PC);
	bool cppVar_93933 = (cppVar_93931 == 241);
	BIT_VEC cppVar_93934 = ROM.rd(PC);
	bool cppVar_93936 = (cppVar_93934 == 209);
	BIT_VEC cppVar_93937 = ROM.rd(PC);
	bool cppVar_93939 = (cppVar_93937 == 177);
	BIT_VEC cppVar_93940 = ROM.rd(PC);
	bool cppVar_93942 = (cppVar_93940 == 145);
	BIT_VEC cppVar_93943 = ROM.rd(PC);
	bool cppVar_93945 = (cppVar_93943 == 113);
	BIT_VEC cppVar_93946 = ROM.rd(PC);
	bool cppVar_93948 = (cppVar_93946 == 81);
	BIT_VEC cppVar_93949 = ROM.rd(PC);
	bool cppVar_93951 = (cppVar_93949 == 49);
	BIT_VEC cppVar_93952 = ROM.rd(PC);
	bool cppVar_93954 = (cppVar_93952 == 17);
	bool cppVar_93955 = cppVar_93951 || cppVar_93954;
	bool cppVar_93956 = cppVar_93948 || cppVar_93955;
	bool cppVar_93957 = cppVar_93945 || cppVar_93956;
	bool cppVar_93958 = cppVar_93942 || cppVar_93957;
	bool cppVar_93959 = cppVar_93939 || cppVar_93958;
	bool cppVar_93960 = cppVar_93936 || cppVar_93959;
	bool cppVar_93961 = cppVar_93933 || cppVar_93960;
	if (cppVar_93961) {
	BIT_VEC cppVar_93963 = SP + 1;
	cppVar_93963 = (cppVar_93963 & cppMask_un_8_);
	BIT_VEC cppVar_93965 = PC + 2;
	cppVar_93965 = (cppVar_93965 & cppMask_un_16_);
	BIT_VEC cppVar_93966 = (cppVar_93965 >> 0) & cppMask_un_8_;
	type_mem cppVar_93967 = IRAM;
	cppVar_93967.wr(cppVar_93963, cppVar_93966);
	BIT_VEC cppVar_93968 = SP + 1;
	cppVar_93968 = (cppVar_93968 & cppMask_un_8_);
	BIT_VEC cppVar_93970 = cppVar_93968 + 1;
	cppVar_93970 = (cppVar_93970 & cppMask_un_8_);
	BIT_VEC cppVar_93971 = PC + 2;
	cppVar_93971 = (cppVar_93971 & cppMask_un_16_);
	BIT_VEC cppVar_93972 = (cppVar_93971 >> 8) & cppMask_un_8_;
	type_mem cppVar_93973 = cppVar_93967;
	cppVar_93973.wr(cppVar_93970, cppVar_93972);
	cppVar_93930 = cppVar_93973;
	} else {
	type_mem cppVar_93974;
	BIT_VEC cppVar_93975 = ROM.rd(PC);
	bool cppVar_93977 = (cppVar_93975 == 194);
	BIT_VEC cppVar_93978 = ROM.rd(PC);
	bool cppVar_93980 = (cppVar_93978 == 16);
	bool cppVar_93981 = cppVar_93977 || cppVar_93980;
	if (cppVar_93981) {
	type_mem cppVar_93982;
	BIT_VEC cppVar_93983;
	BIT_VEC cppVar_93985 = PC + 1;
	cppVar_93985 = (cppVar_93985 & cppMask_un_16_);
	BIT_VEC cppVar_93986 = ROM.rd(cppVar_93985);
	BIT_VEC cppVar_93987 = (cppVar_93986 >> 7) & cppMask_un_1_;
	bool cppVar_93989 = (cppVar_93987 == 1);
	if (cppVar_93989) {
	BIT_VEC cppVar_93990 = PC + 1;
	cppVar_93990 = (cppVar_93990 & cppMask_un_16_);
	BIT_VEC cppVar_93991 = ROM.rd(cppVar_93990);
	BIT_VEC cppVar_93992 = (cppVar_93991 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_93994 = (cppVar_93992 << 3) | 0;
	cppVar_93994 = (cppVar_93994 & cppMask_un_8_);
	cppVar_93983 = cppVar_93994;
	} else {
	BIT_VEC cppVar_93995 = PC + 1;
	cppVar_93995 = (cppVar_93995 & cppMask_un_16_);
	BIT_VEC cppVar_93996 = ROM.rd(cppVar_93995);
	BIT_VEC cppVar_93997 = (cppVar_93996 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_93998 = (cppVar_93997 & cppMask_un_5_);
	BIT_VEC cppVar_94000 = cppVar_93998 + 32;
	cppVar_94000 = (cppVar_94000 & cppMask_un_8_);
	cppVar_93983 = cppVar_94000;
	}
	BIT_VEC cppVar_94001 = (cppVar_93983 >> 7) & cppMask_un_1_;
	bool cppVar_94003 = (cppVar_94001 == 0);
	if (cppVar_94003) {
	BIT_VEC cppVar_94004;
	BIT_VEC cppVar_94005 = PC + 1;
	cppVar_94005 = (cppVar_94005 & cppMask_un_16_);
	BIT_VEC cppVar_94006 = ROM.rd(cppVar_94005);
	BIT_VEC cppVar_94007 = (cppVar_94006 >> 7) & cppMask_un_1_;
	bool cppVar_94008 = (cppVar_94007 == 1);
	if (cppVar_94008) {
	BIT_VEC cppVar_94009 = PC + 1;
	cppVar_94009 = (cppVar_94009 & cppMask_un_16_);
	BIT_VEC cppVar_94010 = ROM.rd(cppVar_94009);
	BIT_VEC cppVar_94011 = (cppVar_94010 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_94012 = (cppVar_94011 << 3) | 0;
	cppVar_94012 = (cppVar_94012 & cppMask_un_8_);
	cppVar_94004 = cppVar_94012;
	} else {
	BIT_VEC cppVar_94013 = PC + 1;
	cppVar_94013 = (cppVar_94013 & cppMask_un_16_);
	BIT_VEC cppVar_94014 = ROM.rd(cppVar_94013);
	BIT_VEC cppVar_94015 = (cppVar_94014 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_94016 = (cppVar_94015 & cppMask_un_5_);
	BIT_VEC cppVar_94017 = cppVar_94016 + 32;
	cppVar_94017 = (cppVar_94017 & cppMask_un_8_);
	cppVar_94004 = cppVar_94017;
	}
	BIT_VEC cppVar_94019 = PC + 1;
	cppVar_94019 = (cppVar_94019 & cppMask_un_16_);
	BIT_VEC cppVar_94020 = ROM.rd(cppVar_94019);
	BIT_VEC cppVar_94021 = (cppVar_94020 >> 0) & cppMask_un_3_;
	BIT_VEC cppVar_94022 = (cppVar_94021 & cppMask_un_3_);
	BIT_VEC cppVar_94023 = 1 << static_cast<unsigned>(cppVar_94022);
	cppVar_94023 = (cppVar_94023 & cppMask_un_8_);
	BIT_VEC cppVar_94024 = ~cppVar_94023;
	BIT_VEC cppVar_94025;
	BIT_VEC cppVar_94026;
	BIT_VEC cppVar_94027 = PC + 1;
	cppVar_94027 = (cppVar_94027 & cppMask_un_16_);
	BIT_VEC cppVar_94028 = ROM.rd(cppVar_94027);
	BIT_VEC cppVar_94029 = (cppVar_94028 >> 7) & cppMask_un_1_;
	bool cppVar_94030 = (cppVar_94029 == 1);
	if (cppVar_94030) {
	BIT_VEC cppVar_94031 = PC + 1;
	cppVar_94031 = (cppVar_94031 & cppMask_un_16_);
	BIT_VEC cppVar_94032 = ROM.rd(cppVar_94031);
	BIT_VEC cppVar_94033 = (cppVar_94032 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_94034 = (cppVar_94033 << 3) | 0;
	cppVar_94034 = (cppVar_94034 & cppMask_un_8_);
	cppVar_94026 = cppVar_94034;
	} else {
	BIT_VEC cppVar_94035 = PC + 1;
	cppVar_94035 = (cppVar_94035 & cppMask_un_16_);
	BIT_VEC cppVar_94036 = ROM.rd(cppVar_94035);
	BIT_VEC cppVar_94037 = (cppVar_94036 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_94038 = (cppVar_94037 & cppMask_un_5_);
	BIT_VEC cppVar_94039 = cppVar_94038 + 32;
	cppVar_94039 = (cppVar_94039 & cppMask_un_8_);
	cppVar_94026 = cppVar_94039;
	}
	BIT_VEC cppVar_94040 = (cppVar_94026 >> 7) & cppMask_un_1_;
	bool cppVar_94042 = (cppVar_94040 == 0);
	if (cppVar_94042) {
	BIT_VEC cppVar_94043;
	BIT_VEC cppVar_94044 = PC + 1;
	cppVar_94044 = (cppVar_94044 & cppMask_un_16_);
	BIT_VEC cppVar_94045 = ROM.rd(cppVar_94044);
	BIT_VEC cppVar_94046 = (cppVar_94045 >> 7) & cppMask_un_1_;
	bool cppVar_94047 = (cppVar_94046 == 1);
	if (cppVar_94047) {
	BIT_VEC cppVar_94048 = PC + 1;
	cppVar_94048 = (cppVar_94048 & cppMask_un_16_);
	BIT_VEC cppVar_94049 = ROM.rd(cppVar_94048);
	BIT_VEC cppVar_94050 = (cppVar_94049 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_94051 = (cppVar_94050 << 3) | 0;
	cppVar_94051 = (cppVar_94051 & cppMask_un_8_);
	cppVar_94043 = cppVar_94051;
	} else {
	BIT_VEC cppVar_94052 = PC + 1;
	cppVar_94052 = (cppVar_94052 & cppMask_un_16_);
	BIT_VEC cppVar_94053 = ROM.rd(cppVar_94052);
	BIT_VEC cppVar_94054 = (cppVar_94053 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_94055 = (cppVar_94054 & cppMask_un_5_);
	BIT_VEC cppVar_94056 = cppVar_94055 + 32;
	cppVar_94056 = (cppVar_94056 & cppMask_un_8_);
	cppVar_94043 = cppVar_94056;
	}
	BIT_VEC cppVar_94057 = IRAM.rd(cppVar_94043);
	cppVar_94025 = cppVar_94057;
	} else {
	BIT_VEC cppVar_94058;
	BIT_VEC cppVar_94059;
	BIT_VEC cppVar_94060 = PC + 1;
	cppVar_94060 = (cppVar_94060 & cppMask_un_16_);
	BIT_VEC cppVar_94061 = ROM.rd(cppVar_94060);
	BIT_VEC cppVar_94062 = (cppVar_94061 >> 7) & cppMask_un_1_;
	bool cppVar_94063 = (cppVar_94062 == 1);
	if (cppVar_94063) {
	BIT_VEC cppVar_94064 = PC + 1;
	cppVar_94064 = (cppVar_94064 & cppMask_un_16_);
	BIT_VEC cppVar_94065 = ROM.rd(cppVar_94064);
	BIT_VEC cppVar_94066 = (cppVar_94065 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_94067 = (cppVar_94066 << 3) | 0;
	cppVar_94067 = (cppVar_94067 & cppMask_un_8_);
	cppVar_94059 = cppVar_94067;
	} else {
	BIT_VEC cppVar_94068 = PC + 1;
	cppVar_94068 = (cppVar_94068 & cppMask_un_16_);
	BIT_VEC cppVar_94069 = ROM.rd(cppVar_94068);
	BIT_VEC cppVar_94070 = (cppVar_94069 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_94071 = (cppVar_94070 & cppMask_un_5_);
	BIT_VEC cppVar_94072 = cppVar_94071 + 32;
	cppVar_94072 = (cppVar_94072 & cppMask_un_8_);
	cppVar_94059 = cppVar_94072;
	}
	bool cppVar_94074 = (cppVar_94059 == 128);
	if (cppVar_94074) {
	cppVar_94058 = P0;
	} else {
	BIT_VEC cppVar_94075;
	BIT_VEC cppVar_94076;
	BIT_VEC cppVar_94077 = PC + 1;
	cppVar_94077 = (cppVar_94077 & cppMask_un_16_);
	BIT_VEC cppVar_94078 = ROM.rd(cppVar_94077);
	BIT_VEC cppVar_94079 = (cppVar_94078 >> 7) & cppMask_un_1_;
	bool cppVar_94080 = (cppVar_94079 == 1);
	if (cppVar_94080) {
	BIT_VEC cppVar_94081 = PC + 1;
	cppVar_94081 = (cppVar_94081 & cppMask_un_16_);
	BIT_VEC cppVar_94082 = ROM.rd(cppVar_94081);
	BIT_VEC cppVar_94083 = (cppVar_94082 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_94084 = (cppVar_94083 << 3) | 0;
	cppVar_94084 = (cppVar_94084 & cppMask_un_8_);
	cppVar_94076 = cppVar_94084;
	} else {
	BIT_VEC cppVar_94085 = PC + 1;
	cppVar_94085 = (cppVar_94085 & cppMask_un_16_);
	BIT_VEC cppVar_94086 = ROM.rd(cppVar_94085);
	BIT_VEC cppVar_94087 = (cppVar_94086 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_94088 = (cppVar_94087 & cppMask_un_5_);
	BIT_VEC cppVar_94089 = cppVar_94088 + 32;
	cppVar_94089 = (cppVar_94089 & cppMask_un_8_);
	cppVar_94076 = cppVar_94089;
	}
	bool cppVar_94091 = (cppVar_94076 == 129);
	if (cppVar_94091) {
	cppVar_94075 = SP;
	} else {
	BIT_VEC cppVar_94092;
	BIT_VEC cppVar_94093;
	BIT_VEC cppVar_94094 = PC + 1;
	cppVar_94094 = (cppVar_94094 & cppMask_un_16_);
	BIT_VEC cppVar_94095 = ROM.rd(cppVar_94094);
	BIT_VEC cppVar_94096 = (cppVar_94095 >> 7) & cppMask_un_1_;
	bool cppVar_94097 = (cppVar_94096 == 1);
	if (cppVar_94097) {
	BIT_VEC cppVar_94098 = PC + 1;
	cppVar_94098 = (cppVar_94098 & cppMask_un_16_);
	BIT_VEC cppVar_94099 = ROM.rd(cppVar_94098);
	BIT_VEC cppVar_94100 = (cppVar_94099 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_94101 = (cppVar_94100 << 3) | 0;
	cppVar_94101 = (cppVar_94101 & cppMask_un_8_);
	cppVar_94093 = cppVar_94101;
	} else {
	BIT_VEC cppVar_94102 = PC + 1;
	cppVar_94102 = (cppVar_94102 & cppMask_un_16_);
	BIT_VEC cppVar_94103 = ROM.rd(cppVar_94102);
	BIT_VEC cppVar_94104 = (cppVar_94103 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_94105 = (cppVar_94104 & cppMask_un_5_);
	BIT_VEC cppVar_94106 = cppVar_94105 + 32;
	cppVar_94106 = (cppVar_94106 & cppMask_un_8_);
	cppVar_94093 = cppVar_94106;
	}
	bool cppVar_94108 = (cppVar_94093 == 130);
	if (cppVar_94108) {
	cppVar_94092 = DPL;
	} else {
	BIT_VEC cppVar_94109;
	BIT_VEC cppVar_94110;
	BIT_VEC cppVar_94111 = PC + 1;
	cppVar_94111 = (cppVar_94111 & cppMask_un_16_);
	BIT_VEC cppVar_94112 = ROM.rd(cppVar_94111);
	BIT_VEC cppVar_94113 = (cppVar_94112 >> 7) & cppMask_un_1_;
	bool cppVar_94114 = (cppVar_94113 == 1);
	if (cppVar_94114) {
	BIT_VEC cppVar_94115 = PC + 1;
	cppVar_94115 = (cppVar_94115 & cppMask_un_16_);
	BIT_VEC cppVar_94116 = ROM.rd(cppVar_94115);
	BIT_VEC cppVar_94117 = (cppVar_94116 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_94118 = (cppVar_94117 << 3) | 0;
	cppVar_94118 = (cppVar_94118 & cppMask_un_8_);
	cppVar_94110 = cppVar_94118;
	} else {
	BIT_VEC cppVar_94119 = PC + 1;
	cppVar_94119 = (cppVar_94119 & cppMask_un_16_);
	BIT_VEC cppVar_94120 = ROM.rd(cppVar_94119);
	BIT_VEC cppVar_94121 = (cppVar_94120 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_94122 = (cppVar_94121 & cppMask_un_5_);
	BIT_VEC cppVar_94123 = cppVar_94122 + 32;
	cppVar_94123 = (cppVar_94123 & cppMask_un_8_);
	cppVar_94110 = cppVar_94123;
	}
	bool cppVar_94125 = (cppVar_94110 == 131);
	if (cppVar_94125) {
	cppVar_94109 = DPH;
	} else {
	BIT_VEC cppVar_94126;
	BIT_VEC cppVar_94127;
	BIT_VEC cppVar_94128 = PC + 1;
	cppVar_94128 = (cppVar_94128 & cppMask_un_16_);
	BIT_VEC cppVar_94129 = ROM.rd(cppVar_94128);
	BIT_VEC cppVar_94130 = (cppVar_94129 >> 7) & cppMask_un_1_;
	bool cppVar_94131 = (cppVar_94130 == 1);
	if (cppVar_94131) {
	BIT_VEC cppVar_94132 = PC + 1;
	cppVar_94132 = (cppVar_94132 & cppMask_un_16_);
	BIT_VEC cppVar_94133 = ROM.rd(cppVar_94132);
	BIT_VEC cppVar_94134 = (cppVar_94133 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_94135 = (cppVar_94134 << 3) | 0;
	cppVar_94135 = (cppVar_94135 & cppMask_un_8_);
	cppVar_94127 = cppVar_94135;
	} else {
	BIT_VEC cppVar_94136 = PC + 1;
	cppVar_94136 = (cppVar_94136 & cppMask_un_16_);
	BIT_VEC cppVar_94137 = ROM.rd(cppVar_94136);
	BIT_VEC cppVar_94138 = (cppVar_94137 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_94139 = (cppVar_94138 & cppMask_un_5_);
	BIT_VEC cppVar_94140 = cppVar_94139 + 32;
	cppVar_94140 = (cppVar_94140 & cppMask_un_8_);
	cppVar_94127 = cppVar_94140;
	}
	bool cppVar_94142 = (cppVar_94127 == 135);
	if (cppVar_94142) {
	cppVar_94126 = PCON;
	} else {
	BIT_VEC cppVar_94143;
	BIT_VEC cppVar_94144;
	BIT_VEC cppVar_94145 = PC + 1;
	cppVar_94145 = (cppVar_94145 & cppMask_un_16_);
	BIT_VEC cppVar_94146 = ROM.rd(cppVar_94145);
	BIT_VEC cppVar_94147 = (cppVar_94146 >> 7) & cppMask_un_1_;
	bool cppVar_94148 = (cppVar_94147 == 1);
	if (cppVar_94148) {
	BIT_VEC cppVar_94149 = PC + 1;
	cppVar_94149 = (cppVar_94149 & cppMask_un_16_);
	BIT_VEC cppVar_94150 = ROM.rd(cppVar_94149);
	BIT_VEC cppVar_94151 = (cppVar_94150 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_94152 = (cppVar_94151 << 3) | 0;
	cppVar_94152 = (cppVar_94152 & cppMask_un_8_);
	cppVar_94144 = cppVar_94152;
	} else {
	BIT_VEC cppVar_94153 = PC + 1;
	cppVar_94153 = (cppVar_94153 & cppMask_un_16_);
	BIT_VEC cppVar_94154 = ROM.rd(cppVar_94153);
	BIT_VEC cppVar_94155 = (cppVar_94154 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_94156 = (cppVar_94155 & cppMask_un_5_);
	BIT_VEC cppVar_94157 = cppVar_94156 + 32;
	cppVar_94157 = (cppVar_94157 & cppMask_un_8_);
	cppVar_94144 = cppVar_94157;
	}
	bool cppVar_94159 = (cppVar_94144 == 136);
	if (cppVar_94159) {
	cppVar_94143 = TCON;
	} else {
	BIT_VEC cppVar_94160;
	BIT_VEC cppVar_94161;
	BIT_VEC cppVar_94162 = PC + 1;
	cppVar_94162 = (cppVar_94162 & cppMask_un_16_);
	BIT_VEC cppVar_94163 = ROM.rd(cppVar_94162);
	BIT_VEC cppVar_94164 = (cppVar_94163 >> 7) & cppMask_un_1_;
	bool cppVar_94165 = (cppVar_94164 == 1);
	if (cppVar_94165) {
	BIT_VEC cppVar_94166 = PC + 1;
	cppVar_94166 = (cppVar_94166 & cppMask_un_16_);
	BIT_VEC cppVar_94167 = ROM.rd(cppVar_94166);
	BIT_VEC cppVar_94168 = (cppVar_94167 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_94169 = (cppVar_94168 << 3) | 0;
	cppVar_94169 = (cppVar_94169 & cppMask_un_8_);
	cppVar_94161 = cppVar_94169;
	} else {
	BIT_VEC cppVar_94170 = PC + 1;
	cppVar_94170 = (cppVar_94170 & cppMask_un_16_);
	BIT_VEC cppVar_94171 = ROM.rd(cppVar_94170);
	BIT_VEC cppVar_94172 = (cppVar_94171 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_94173 = (cppVar_94172 & cppMask_un_5_);
	BIT_VEC cppVar_94174 = cppVar_94173 + 32;
	cppVar_94174 = (cppVar_94174 & cppMask_un_8_);
	cppVar_94161 = cppVar_94174;
	}
	bool cppVar_94176 = (cppVar_94161 == 137);
	if (cppVar_94176) {
	cppVar_94160 = TMOD;
	} else {
	BIT_VEC cppVar_94177;
	BIT_VEC cppVar_94178;
	BIT_VEC cppVar_94179 = PC + 1;
	cppVar_94179 = (cppVar_94179 & cppMask_un_16_);
	BIT_VEC cppVar_94180 = ROM.rd(cppVar_94179);
	BIT_VEC cppVar_94181 = (cppVar_94180 >> 7) & cppMask_un_1_;
	bool cppVar_94182 = (cppVar_94181 == 1);
	if (cppVar_94182) {
	BIT_VEC cppVar_94183 = PC + 1;
	cppVar_94183 = (cppVar_94183 & cppMask_un_16_);
	BIT_VEC cppVar_94184 = ROM.rd(cppVar_94183);
	BIT_VEC cppVar_94185 = (cppVar_94184 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_94186 = (cppVar_94185 << 3) | 0;
	cppVar_94186 = (cppVar_94186 & cppMask_un_8_);
	cppVar_94178 = cppVar_94186;
	} else {
	BIT_VEC cppVar_94187 = PC + 1;
	cppVar_94187 = (cppVar_94187 & cppMask_un_16_);
	BIT_VEC cppVar_94188 = ROM.rd(cppVar_94187);
	BIT_VEC cppVar_94189 = (cppVar_94188 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_94190 = (cppVar_94189 & cppMask_un_5_);
	BIT_VEC cppVar_94191 = cppVar_94190 + 32;
	cppVar_94191 = (cppVar_94191 & cppMask_un_8_);
	cppVar_94178 = cppVar_94191;
	}
	bool cppVar_94193 = (cppVar_94178 == 138);
	if (cppVar_94193) {
	cppVar_94177 = TL0;
	} else {
	BIT_VEC cppVar_94194;
	BIT_VEC cppVar_94195;
	BIT_VEC cppVar_94196 = PC + 1;
	cppVar_94196 = (cppVar_94196 & cppMask_un_16_);
	BIT_VEC cppVar_94197 = ROM.rd(cppVar_94196);
	BIT_VEC cppVar_94198 = (cppVar_94197 >> 7) & cppMask_un_1_;
	bool cppVar_94199 = (cppVar_94198 == 1);
	if (cppVar_94199) {
	BIT_VEC cppVar_94200 = PC + 1;
	cppVar_94200 = (cppVar_94200 & cppMask_un_16_);
	BIT_VEC cppVar_94201 = ROM.rd(cppVar_94200);
	BIT_VEC cppVar_94202 = (cppVar_94201 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_94203 = (cppVar_94202 << 3) | 0;
	cppVar_94203 = (cppVar_94203 & cppMask_un_8_);
	cppVar_94195 = cppVar_94203;
	} else {
	BIT_VEC cppVar_94204 = PC + 1;
	cppVar_94204 = (cppVar_94204 & cppMask_un_16_);
	BIT_VEC cppVar_94205 = ROM.rd(cppVar_94204);
	BIT_VEC cppVar_94206 = (cppVar_94205 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_94207 = (cppVar_94206 & cppMask_un_5_);
	BIT_VEC cppVar_94208 = cppVar_94207 + 32;
	cppVar_94208 = (cppVar_94208 & cppMask_un_8_);
	cppVar_94195 = cppVar_94208;
	}
	bool cppVar_94210 = (cppVar_94195 == 140);
	if (cppVar_94210) {
	cppVar_94194 = TH0;
	} else {
	BIT_VEC cppVar_94211;
	BIT_VEC cppVar_94212;
	BIT_VEC cppVar_94213 = PC + 1;
	cppVar_94213 = (cppVar_94213 & cppMask_un_16_);
	BIT_VEC cppVar_94214 = ROM.rd(cppVar_94213);
	BIT_VEC cppVar_94215 = (cppVar_94214 >> 7) & cppMask_un_1_;
	bool cppVar_94216 = (cppVar_94215 == 1);
	if (cppVar_94216) {
	BIT_VEC cppVar_94217 = PC + 1;
	cppVar_94217 = (cppVar_94217 & cppMask_un_16_);
	BIT_VEC cppVar_94218 = ROM.rd(cppVar_94217);
	BIT_VEC cppVar_94219 = (cppVar_94218 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_94220 = (cppVar_94219 << 3) | 0;
	cppVar_94220 = (cppVar_94220 & cppMask_un_8_);
	cppVar_94212 = cppVar_94220;
	} else {
	BIT_VEC cppVar_94221 = PC + 1;
	cppVar_94221 = (cppVar_94221 & cppMask_un_16_);
	BIT_VEC cppVar_94222 = ROM.rd(cppVar_94221);
	BIT_VEC cppVar_94223 = (cppVar_94222 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_94224 = (cppVar_94223 & cppMask_un_5_);
	BIT_VEC cppVar_94225 = cppVar_94224 + 32;
	cppVar_94225 = (cppVar_94225 & cppMask_un_8_);
	cppVar_94212 = cppVar_94225;
	}
	bool cppVar_94227 = (cppVar_94212 == 139);
	if (cppVar_94227) {
	cppVar_94211 = TL1;
	} else {
	BIT_VEC cppVar_94228;
	BIT_VEC cppVar_94229;
	BIT_VEC cppVar_94230 = PC + 1;
	cppVar_94230 = (cppVar_94230 & cppMask_un_16_);
	BIT_VEC cppVar_94231 = ROM.rd(cppVar_94230);
	BIT_VEC cppVar_94232 = (cppVar_94231 >> 7) & cppMask_un_1_;
	bool cppVar_94233 = (cppVar_94232 == 1);
	if (cppVar_94233) {
	BIT_VEC cppVar_94234 = PC + 1;
	cppVar_94234 = (cppVar_94234 & cppMask_un_16_);
	BIT_VEC cppVar_94235 = ROM.rd(cppVar_94234);
	BIT_VEC cppVar_94236 = (cppVar_94235 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_94237 = (cppVar_94236 << 3) | 0;
	cppVar_94237 = (cppVar_94237 & cppMask_un_8_);
	cppVar_94229 = cppVar_94237;
	} else {
	BIT_VEC cppVar_94238 = PC + 1;
	cppVar_94238 = (cppVar_94238 & cppMask_un_16_);
	BIT_VEC cppVar_94239 = ROM.rd(cppVar_94238);
	BIT_VEC cppVar_94240 = (cppVar_94239 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_94241 = (cppVar_94240 & cppMask_un_5_);
	BIT_VEC cppVar_94242 = cppVar_94241 + 32;
	cppVar_94242 = (cppVar_94242 & cppMask_un_8_);
	cppVar_94229 = cppVar_94242;
	}
	bool cppVar_94244 = (cppVar_94229 == 141);
	if (cppVar_94244) {
	cppVar_94228 = TH1;
	} else {
	BIT_VEC cppVar_94245;
	BIT_VEC cppVar_94246;
	BIT_VEC cppVar_94247 = PC + 1;
	cppVar_94247 = (cppVar_94247 & cppMask_un_16_);
	BIT_VEC cppVar_94248 = ROM.rd(cppVar_94247);
	BIT_VEC cppVar_94249 = (cppVar_94248 >> 7) & cppMask_un_1_;
	bool cppVar_94250 = (cppVar_94249 == 1);
	if (cppVar_94250) {
	BIT_VEC cppVar_94251 = PC + 1;
	cppVar_94251 = (cppVar_94251 & cppMask_un_16_);
	BIT_VEC cppVar_94252 = ROM.rd(cppVar_94251);
	BIT_VEC cppVar_94253 = (cppVar_94252 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_94254 = (cppVar_94253 << 3) | 0;
	cppVar_94254 = (cppVar_94254 & cppMask_un_8_);
	cppVar_94246 = cppVar_94254;
	} else {
	BIT_VEC cppVar_94255 = PC + 1;
	cppVar_94255 = (cppVar_94255 & cppMask_un_16_);
	BIT_VEC cppVar_94256 = ROM.rd(cppVar_94255);
	BIT_VEC cppVar_94257 = (cppVar_94256 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_94258 = (cppVar_94257 & cppMask_un_5_);
	BIT_VEC cppVar_94259 = cppVar_94258 + 32;
	cppVar_94259 = (cppVar_94259 & cppMask_un_8_);
	cppVar_94246 = cppVar_94259;
	}
	bool cppVar_94261 = (cppVar_94246 == 144);
	if (cppVar_94261) {
	cppVar_94245 = P1;
	} else {
	BIT_VEC cppVar_94262;
	BIT_VEC cppVar_94263;
	BIT_VEC cppVar_94264 = PC + 1;
	cppVar_94264 = (cppVar_94264 & cppMask_un_16_);
	BIT_VEC cppVar_94265 = ROM.rd(cppVar_94264);
	BIT_VEC cppVar_94266 = (cppVar_94265 >> 7) & cppMask_un_1_;
	bool cppVar_94267 = (cppVar_94266 == 1);
	if (cppVar_94267) {
	BIT_VEC cppVar_94268 = PC + 1;
	cppVar_94268 = (cppVar_94268 & cppMask_un_16_);
	BIT_VEC cppVar_94269 = ROM.rd(cppVar_94268);
	BIT_VEC cppVar_94270 = (cppVar_94269 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_94271 = (cppVar_94270 << 3) | 0;
	cppVar_94271 = (cppVar_94271 & cppMask_un_8_);
	cppVar_94263 = cppVar_94271;
	} else {
	BIT_VEC cppVar_94272 = PC + 1;
	cppVar_94272 = (cppVar_94272 & cppMask_un_16_);
	BIT_VEC cppVar_94273 = ROM.rd(cppVar_94272);
	BIT_VEC cppVar_94274 = (cppVar_94273 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_94275 = (cppVar_94274 & cppMask_un_5_);
	BIT_VEC cppVar_94276 = cppVar_94275 + 32;
	cppVar_94276 = (cppVar_94276 & cppMask_un_8_);
	cppVar_94263 = cppVar_94276;
	}
	bool cppVar_94278 = (cppVar_94263 == 152);
	if (cppVar_94278) {
	cppVar_94262 = SCON;
	} else {
	BIT_VEC cppVar_94279;
	BIT_VEC cppVar_94280;
	BIT_VEC cppVar_94281 = PC + 1;
	cppVar_94281 = (cppVar_94281 & cppMask_un_16_);
	BIT_VEC cppVar_94282 = ROM.rd(cppVar_94281);
	BIT_VEC cppVar_94283 = (cppVar_94282 >> 7) & cppMask_un_1_;
	bool cppVar_94284 = (cppVar_94283 == 1);
	if (cppVar_94284) {
	BIT_VEC cppVar_94285 = PC + 1;
	cppVar_94285 = (cppVar_94285 & cppMask_un_16_);
	BIT_VEC cppVar_94286 = ROM.rd(cppVar_94285);
	BIT_VEC cppVar_94287 = (cppVar_94286 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_94288 = (cppVar_94287 << 3) | 0;
	cppVar_94288 = (cppVar_94288 & cppMask_un_8_);
	cppVar_94280 = cppVar_94288;
	} else {
	BIT_VEC cppVar_94289 = PC + 1;
	cppVar_94289 = (cppVar_94289 & cppMask_un_16_);
	BIT_VEC cppVar_94290 = ROM.rd(cppVar_94289);
	BIT_VEC cppVar_94291 = (cppVar_94290 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_94292 = (cppVar_94291 & cppMask_un_5_);
	BIT_VEC cppVar_94293 = cppVar_94292 + 32;
	cppVar_94293 = (cppVar_94293 & cppMask_un_8_);
	cppVar_94280 = cppVar_94293;
	}
	bool cppVar_94295 = (cppVar_94280 == 153);
	if (cppVar_94295) {
	cppVar_94279 = SBUF;
	} else {
	BIT_VEC cppVar_94296;
	BIT_VEC cppVar_94297;
	BIT_VEC cppVar_94298 = PC + 1;
	cppVar_94298 = (cppVar_94298 & cppMask_un_16_);
	BIT_VEC cppVar_94299 = ROM.rd(cppVar_94298);
	BIT_VEC cppVar_94300 = (cppVar_94299 >> 7) & cppMask_un_1_;
	bool cppVar_94301 = (cppVar_94300 == 1);
	if (cppVar_94301) {
	BIT_VEC cppVar_94302 = PC + 1;
	cppVar_94302 = (cppVar_94302 & cppMask_un_16_);
	BIT_VEC cppVar_94303 = ROM.rd(cppVar_94302);
	BIT_VEC cppVar_94304 = (cppVar_94303 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_94305 = (cppVar_94304 << 3) | 0;
	cppVar_94305 = (cppVar_94305 & cppMask_un_8_);
	cppVar_94297 = cppVar_94305;
	} else {
	BIT_VEC cppVar_94306 = PC + 1;
	cppVar_94306 = (cppVar_94306 & cppMask_un_16_);
	BIT_VEC cppVar_94307 = ROM.rd(cppVar_94306);
	BIT_VEC cppVar_94308 = (cppVar_94307 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_94309 = (cppVar_94308 & cppMask_un_5_);
	BIT_VEC cppVar_94310 = cppVar_94309 + 32;
	cppVar_94310 = (cppVar_94310 & cppMask_un_8_);
	cppVar_94297 = cppVar_94310;
	}
	bool cppVar_94312 = (cppVar_94297 == 160);
	if (cppVar_94312) {
	cppVar_94296 = P2;
	} else {
	BIT_VEC cppVar_94313;
	BIT_VEC cppVar_94314;
	BIT_VEC cppVar_94315 = PC + 1;
	cppVar_94315 = (cppVar_94315 & cppMask_un_16_);
	BIT_VEC cppVar_94316 = ROM.rd(cppVar_94315);
	BIT_VEC cppVar_94317 = (cppVar_94316 >> 7) & cppMask_un_1_;
	bool cppVar_94318 = (cppVar_94317 == 1);
	if (cppVar_94318) {
	BIT_VEC cppVar_94319 = PC + 1;
	cppVar_94319 = (cppVar_94319 & cppMask_un_16_);
	BIT_VEC cppVar_94320 = ROM.rd(cppVar_94319);
	BIT_VEC cppVar_94321 = (cppVar_94320 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_94322 = (cppVar_94321 << 3) | 0;
	cppVar_94322 = (cppVar_94322 & cppMask_un_8_);
	cppVar_94314 = cppVar_94322;
	} else {
	BIT_VEC cppVar_94323 = PC + 1;
	cppVar_94323 = (cppVar_94323 & cppMask_un_16_);
	BIT_VEC cppVar_94324 = ROM.rd(cppVar_94323);
	BIT_VEC cppVar_94325 = (cppVar_94324 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_94326 = (cppVar_94325 & cppMask_un_5_);
	BIT_VEC cppVar_94327 = cppVar_94326 + 32;
	cppVar_94327 = (cppVar_94327 & cppMask_un_8_);
	cppVar_94314 = cppVar_94327;
	}
	bool cppVar_94329 = (cppVar_94314 == 168);
	if (cppVar_94329) {
	cppVar_94313 = IE;
	} else {
	BIT_VEC cppVar_94330;
	BIT_VEC cppVar_94331;
	BIT_VEC cppVar_94332 = PC + 1;
	cppVar_94332 = (cppVar_94332 & cppMask_un_16_);
	BIT_VEC cppVar_94333 = ROM.rd(cppVar_94332);
	BIT_VEC cppVar_94334 = (cppVar_94333 >> 7) & cppMask_un_1_;
	bool cppVar_94335 = (cppVar_94334 == 1);
	if (cppVar_94335) {
	BIT_VEC cppVar_94336 = PC + 1;
	cppVar_94336 = (cppVar_94336 & cppMask_un_16_);
	BIT_VEC cppVar_94337 = ROM.rd(cppVar_94336);
	BIT_VEC cppVar_94338 = (cppVar_94337 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_94339 = (cppVar_94338 << 3) | 0;
	cppVar_94339 = (cppVar_94339 & cppMask_un_8_);
	cppVar_94331 = cppVar_94339;
	} else {
	BIT_VEC cppVar_94340 = PC + 1;
	cppVar_94340 = (cppVar_94340 & cppMask_un_16_);
	BIT_VEC cppVar_94341 = ROM.rd(cppVar_94340);
	BIT_VEC cppVar_94342 = (cppVar_94341 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_94343 = (cppVar_94342 & cppMask_un_5_);
	BIT_VEC cppVar_94344 = cppVar_94343 + 32;
	cppVar_94344 = (cppVar_94344 & cppMask_un_8_);
	cppVar_94331 = cppVar_94344;
	}
	bool cppVar_94346 = (cppVar_94331 == 176);
	if (cppVar_94346) {
	cppVar_94330 = P3;
	} else {
	BIT_VEC cppVar_94347;
	BIT_VEC cppVar_94348;
	BIT_VEC cppVar_94349 = PC + 1;
	cppVar_94349 = (cppVar_94349 & cppMask_un_16_);
	BIT_VEC cppVar_94350 = ROM.rd(cppVar_94349);
	BIT_VEC cppVar_94351 = (cppVar_94350 >> 7) & cppMask_un_1_;
	bool cppVar_94352 = (cppVar_94351 == 1);
	if (cppVar_94352) {
	BIT_VEC cppVar_94353 = PC + 1;
	cppVar_94353 = (cppVar_94353 & cppMask_un_16_);
	BIT_VEC cppVar_94354 = ROM.rd(cppVar_94353);
	BIT_VEC cppVar_94355 = (cppVar_94354 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_94356 = (cppVar_94355 << 3) | 0;
	cppVar_94356 = (cppVar_94356 & cppMask_un_8_);
	cppVar_94348 = cppVar_94356;
	} else {
	BIT_VEC cppVar_94357 = PC + 1;
	cppVar_94357 = (cppVar_94357 & cppMask_un_16_);
	BIT_VEC cppVar_94358 = ROM.rd(cppVar_94357);
	BIT_VEC cppVar_94359 = (cppVar_94358 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_94360 = (cppVar_94359 & cppMask_un_5_);
	BIT_VEC cppVar_94361 = cppVar_94360 + 32;
	cppVar_94361 = (cppVar_94361 & cppMask_un_8_);
	cppVar_94348 = cppVar_94361;
	}
	bool cppVar_94363 = (cppVar_94348 == 184);
	if (cppVar_94363) {
	cppVar_94347 = IP;
	} else {
	BIT_VEC cppVar_94364;
	BIT_VEC cppVar_94365;
	BIT_VEC cppVar_94366 = PC + 1;
	cppVar_94366 = (cppVar_94366 & cppMask_un_16_);
	BIT_VEC cppVar_94367 = ROM.rd(cppVar_94366);
	BIT_VEC cppVar_94368 = (cppVar_94367 >> 7) & cppMask_un_1_;
	bool cppVar_94369 = (cppVar_94368 == 1);
	if (cppVar_94369) {
	BIT_VEC cppVar_94370 = PC + 1;
	cppVar_94370 = (cppVar_94370 & cppMask_un_16_);
	BIT_VEC cppVar_94371 = ROM.rd(cppVar_94370);
	BIT_VEC cppVar_94372 = (cppVar_94371 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_94373 = (cppVar_94372 << 3) | 0;
	cppVar_94373 = (cppVar_94373 & cppMask_un_8_);
	cppVar_94365 = cppVar_94373;
	} else {
	BIT_VEC cppVar_94374 = PC + 1;
	cppVar_94374 = (cppVar_94374 & cppMask_un_16_);
	BIT_VEC cppVar_94375 = ROM.rd(cppVar_94374);
	BIT_VEC cppVar_94376 = (cppVar_94375 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_94377 = (cppVar_94376 & cppMask_un_5_);
	BIT_VEC cppVar_94378 = cppVar_94377 + 32;
	cppVar_94378 = (cppVar_94378 & cppMask_un_8_);
	cppVar_94365 = cppVar_94378;
	}
	bool cppVar_94380 = (cppVar_94365 == 208);
	if (cppVar_94380) {
	cppVar_94364 = PSW;
	} else {
	BIT_VEC cppVar_94381;
	BIT_VEC cppVar_94382;
	BIT_VEC cppVar_94383 = PC + 1;
	cppVar_94383 = (cppVar_94383 & cppMask_un_16_);
	BIT_VEC cppVar_94384 = ROM.rd(cppVar_94383);
	BIT_VEC cppVar_94385 = (cppVar_94384 >> 7) & cppMask_un_1_;
	bool cppVar_94386 = (cppVar_94385 == 1);
	if (cppVar_94386) {
	BIT_VEC cppVar_94387 = PC + 1;
	cppVar_94387 = (cppVar_94387 & cppMask_un_16_);
	BIT_VEC cppVar_94388 = ROM.rd(cppVar_94387);
	BIT_VEC cppVar_94389 = (cppVar_94388 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_94390 = (cppVar_94389 << 3) | 0;
	cppVar_94390 = (cppVar_94390 & cppMask_un_8_);
	cppVar_94382 = cppVar_94390;
	} else {
	BIT_VEC cppVar_94391 = PC + 1;
	cppVar_94391 = (cppVar_94391 & cppMask_un_16_);
	BIT_VEC cppVar_94392 = ROM.rd(cppVar_94391);
	BIT_VEC cppVar_94393 = (cppVar_94392 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_94394 = (cppVar_94393 & cppMask_un_5_);
	BIT_VEC cppVar_94395 = cppVar_94394 + 32;
	cppVar_94395 = (cppVar_94395 & cppMask_un_8_);
	cppVar_94382 = cppVar_94395;
	}
	bool cppVar_94397 = (cppVar_94382 == 224);
	if (cppVar_94397) {
	cppVar_94381 = ACC;
	} else {
	BIT_VEC cppVar_94398;
	BIT_VEC cppVar_94399;
	BIT_VEC cppVar_94400 = PC + 1;
	cppVar_94400 = (cppVar_94400 & cppMask_un_16_);
	BIT_VEC cppVar_94401 = ROM.rd(cppVar_94400);
	BIT_VEC cppVar_94402 = (cppVar_94401 >> 7) & cppMask_un_1_;
	bool cppVar_94403 = (cppVar_94402 == 1);
	if (cppVar_94403) {
	BIT_VEC cppVar_94404 = PC + 1;
	cppVar_94404 = (cppVar_94404 & cppMask_un_16_);
	BIT_VEC cppVar_94405 = ROM.rd(cppVar_94404);
	BIT_VEC cppVar_94406 = (cppVar_94405 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_94407 = (cppVar_94406 << 3) | 0;
	cppVar_94407 = (cppVar_94407 & cppMask_un_8_);
	cppVar_94399 = cppVar_94407;
	} else {
	BIT_VEC cppVar_94408 = PC + 1;
	cppVar_94408 = (cppVar_94408 & cppMask_un_16_);
	BIT_VEC cppVar_94409 = ROM.rd(cppVar_94408);
	BIT_VEC cppVar_94410 = (cppVar_94409 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_94411 = (cppVar_94410 & cppMask_un_5_);
	BIT_VEC cppVar_94412 = cppVar_94411 + 32;
	cppVar_94412 = (cppVar_94412 & cppMask_un_8_);
	cppVar_94399 = cppVar_94412;
	}
	bool cppVar_94414 = (cppVar_94399 == 240);
	if (cppVar_94414) {
	cppVar_94398 = B;
	} else {
	cppVar_94398 = 0;
	}
	cppVar_94381 = cppVar_94398;
	}
	cppVar_94364 = cppVar_94381;
	}
	cppVar_94347 = cppVar_94364;
	}
	cppVar_94330 = cppVar_94347;
	}
	cppVar_94313 = cppVar_94330;
	}
	cppVar_94296 = cppVar_94313;
	}
	cppVar_94279 = cppVar_94296;
	}
	cppVar_94262 = cppVar_94279;
	}
	cppVar_94245 = cppVar_94262;
	}
	cppVar_94228 = cppVar_94245;
	}
	cppVar_94211 = cppVar_94228;
	}
	cppVar_94194 = cppVar_94211;
	}
	cppVar_94177 = cppVar_94194;
	}
	cppVar_94160 = cppVar_94177;
	}
	cppVar_94143 = cppVar_94160;
	}
	cppVar_94126 = cppVar_94143;
	}
	cppVar_94109 = cppVar_94126;
	}
	cppVar_94092 = cppVar_94109;
	}
	cppVar_94075 = cppVar_94092;
	}
	cppVar_94058 = cppVar_94075;
	}
	cppVar_94025 = cppVar_94058;
	}
	BIT_VEC cppVar_94416 = cppVar_94024 & cppVar_94025;
	BIT_VEC cppVar_94418 = 0;
	BIT_VEC cppVar_94419 = PC + 1;
	cppVar_94419 = (cppVar_94419 & cppMask_un_16_);
	BIT_VEC cppVar_94420 = ROM.rd(cppVar_94419);
	BIT_VEC cppVar_94421 = (cppVar_94420 >> 0) & cppMask_un_3_;
	BIT_VEC cppVar_94422 = (cppVar_94421 & cppMask_un_3_);
	BIT_VEC cppVar_94423 = cppVar_94418 << static_cast<unsigned>(cppVar_94422);
	cppVar_94423 = (cppVar_94423 & cppMask_un_8_);
	BIT_VEC cppVar_94424 = cppVar_94416 | cppVar_94423;
	type_mem cppVar_94425 = IRAM;
	cppVar_94425.wr(cppVar_94004, cppVar_94424);
	cppVar_93982 = cppVar_94425;
	} else {
	cppVar_93982 = IRAM;
	}
	cppVar_93974 = cppVar_93982;
	} else {
	type_mem cppVar_94426;
	BIT_VEC cppVar_94427 = ROM.rd(PC);
	bool cppVar_94429 = (cppVar_94427 == 15);
	if (cppVar_94429) {
	type_mem cppVar_94430;
	BIT_VEC cppVar_94432 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_94434 = (cppVar_94432 << 3) | 7;
	cppVar_94434 = (cppVar_94434 & cppMask_un_5_);
	BIT_VEC cppVar_94435 = (0 << 5) | cppVar_94434;
	cppVar_94435 = (cppVar_94435 & cppMask_un_8_);
	BIT_VEC cppVar_94436 = (cppVar_94435 >> 7) & cppMask_un_1_;
	bool cppVar_94438 = (cppVar_94436 == 0);
	if (cppVar_94438) {
	BIT_VEC cppVar_94439 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_94440 = (cppVar_94439 << 3) | 7;
	cppVar_94440 = (cppVar_94440 & cppMask_un_5_);
	BIT_VEC cppVar_94441 = (0 << 5) | cppVar_94440;
	cppVar_94441 = (cppVar_94441 & cppMask_un_8_);
	BIT_VEC cppVar_94442;
	BIT_VEC cppVar_94443 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_94444 = (cppVar_94443 << 3) | 7;
	cppVar_94444 = (cppVar_94444 & cppMask_un_5_);
	BIT_VEC cppVar_94445 = (0 << 5) | cppVar_94444;
	cppVar_94445 = (cppVar_94445 & cppMask_un_8_);
	BIT_VEC cppVar_94446 = (cppVar_94445 >> 7) & cppMask_un_1_;
	bool cppVar_94448 = (cppVar_94446 == 0);
	if (cppVar_94448) {
	BIT_VEC cppVar_94449 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_94450 = (cppVar_94449 << 3) | 7;
	cppVar_94450 = (cppVar_94450 & cppMask_un_5_);
	BIT_VEC cppVar_94451 = (0 << 5) | cppVar_94450;
	cppVar_94451 = (cppVar_94451 & cppMask_un_8_);
	BIT_VEC cppVar_94452 = IRAM.rd(cppVar_94451);
	cppVar_94442 = cppVar_94452;
	} else {
	BIT_VEC cppVar_94453;
	BIT_VEC cppVar_94454 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_94455 = (cppVar_94454 << 3) | 7;
	cppVar_94455 = (cppVar_94455 & cppMask_un_5_);
	BIT_VEC cppVar_94456 = (0 << 5) | cppVar_94455;
	cppVar_94456 = (cppVar_94456 & cppMask_un_8_);
	bool cppVar_94458 = (cppVar_94456 == 128);
	if (cppVar_94458) {
	cppVar_94453 = P0;
	} else {
	BIT_VEC cppVar_94459;
	BIT_VEC cppVar_94460 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_94461 = (cppVar_94460 << 3) | 7;
	cppVar_94461 = (cppVar_94461 & cppMask_un_5_);
	BIT_VEC cppVar_94462 = (0 << 5) | cppVar_94461;
	cppVar_94462 = (cppVar_94462 & cppMask_un_8_);
	bool cppVar_94464 = (cppVar_94462 == 129);
	if (cppVar_94464) {
	cppVar_94459 = SP;
	} else {
	BIT_VEC cppVar_94465;
	BIT_VEC cppVar_94466 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_94467 = (cppVar_94466 << 3) | 7;
	cppVar_94467 = (cppVar_94467 & cppMask_un_5_);
	BIT_VEC cppVar_94468 = (0 << 5) | cppVar_94467;
	cppVar_94468 = (cppVar_94468 & cppMask_un_8_);
	bool cppVar_94470 = (cppVar_94468 == 130);
	if (cppVar_94470) {
	cppVar_94465 = DPL;
	} else {
	BIT_VEC cppVar_94471;
	BIT_VEC cppVar_94472 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_94473 = (cppVar_94472 << 3) | 7;
	cppVar_94473 = (cppVar_94473 & cppMask_un_5_);
	BIT_VEC cppVar_94474 = (0 << 5) | cppVar_94473;
	cppVar_94474 = (cppVar_94474 & cppMask_un_8_);
	bool cppVar_94476 = (cppVar_94474 == 131);
	if (cppVar_94476) {
	cppVar_94471 = DPH;
	} else {
	BIT_VEC cppVar_94477;
	BIT_VEC cppVar_94478 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_94479 = (cppVar_94478 << 3) | 7;
	cppVar_94479 = (cppVar_94479 & cppMask_un_5_);
	BIT_VEC cppVar_94480 = (0 << 5) | cppVar_94479;
	cppVar_94480 = (cppVar_94480 & cppMask_un_8_);
	bool cppVar_94482 = (cppVar_94480 == 135);
	if (cppVar_94482) {
	cppVar_94477 = PCON;
	} else {
	BIT_VEC cppVar_94483;
	BIT_VEC cppVar_94484 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_94485 = (cppVar_94484 << 3) | 7;
	cppVar_94485 = (cppVar_94485 & cppMask_un_5_);
	BIT_VEC cppVar_94486 = (0 << 5) | cppVar_94485;
	cppVar_94486 = (cppVar_94486 & cppMask_un_8_);
	bool cppVar_94488 = (cppVar_94486 == 136);
	if (cppVar_94488) {
	cppVar_94483 = TCON;
	} else {
	BIT_VEC cppVar_94489;
	BIT_VEC cppVar_94490 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_94491 = (cppVar_94490 << 3) | 7;
	cppVar_94491 = (cppVar_94491 & cppMask_un_5_);
	BIT_VEC cppVar_94492 = (0 << 5) | cppVar_94491;
	cppVar_94492 = (cppVar_94492 & cppMask_un_8_);
	bool cppVar_94494 = (cppVar_94492 == 137);
	if (cppVar_94494) {
	cppVar_94489 = TMOD;
	} else {
	BIT_VEC cppVar_94495;
	BIT_VEC cppVar_94496 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_94497 = (cppVar_94496 << 3) | 7;
	cppVar_94497 = (cppVar_94497 & cppMask_un_5_);
	BIT_VEC cppVar_94498 = (0 << 5) | cppVar_94497;
	cppVar_94498 = (cppVar_94498 & cppMask_un_8_);
	bool cppVar_94500 = (cppVar_94498 == 138);
	if (cppVar_94500) {
	cppVar_94495 = TL0;
	} else {
	BIT_VEC cppVar_94501;
	BIT_VEC cppVar_94502 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_94503 = (cppVar_94502 << 3) | 7;
	cppVar_94503 = (cppVar_94503 & cppMask_un_5_);
	BIT_VEC cppVar_94504 = (0 << 5) | cppVar_94503;
	cppVar_94504 = (cppVar_94504 & cppMask_un_8_);
	bool cppVar_94506 = (cppVar_94504 == 140);
	if (cppVar_94506) {
	cppVar_94501 = TH0;
	} else {
	BIT_VEC cppVar_94507;
	BIT_VEC cppVar_94508 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_94509 = (cppVar_94508 << 3) | 7;
	cppVar_94509 = (cppVar_94509 & cppMask_un_5_);
	BIT_VEC cppVar_94510 = (0 << 5) | cppVar_94509;
	cppVar_94510 = (cppVar_94510 & cppMask_un_8_);
	bool cppVar_94512 = (cppVar_94510 == 139);
	if (cppVar_94512) {
	cppVar_94507 = TL1;
	} else {
	BIT_VEC cppVar_94513;
	BIT_VEC cppVar_94514 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_94515 = (cppVar_94514 << 3) | 7;
	cppVar_94515 = (cppVar_94515 & cppMask_un_5_);
	BIT_VEC cppVar_94516 = (0 << 5) | cppVar_94515;
	cppVar_94516 = (cppVar_94516 & cppMask_un_8_);
	bool cppVar_94518 = (cppVar_94516 == 141);
	if (cppVar_94518) {
	cppVar_94513 = TH1;
	} else {
	BIT_VEC cppVar_94519;
	BIT_VEC cppVar_94520 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_94521 = (cppVar_94520 << 3) | 7;
	cppVar_94521 = (cppVar_94521 & cppMask_un_5_);
	BIT_VEC cppVar_94522 = (0 << 5) | cppVar_94521;
	cppVar_94522 = (cppVar_94522 & cppMask_un_8_);
	bool cppVar_94524 = (cppVar_94522 == 144);
	if (cppVar_94524) {
	cppVar_94519 = P1;
	} else {
	BIT_VEC cppVar_94525;
	BIT_VEC cppVar_94526 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_94527 = (cppVar_94526 << 3) | 7;
	cppVar_94527 = (cppVar_94527 & cppMask_un_5_);
	BIT_VEC cppVar_94528 = (0 << 5) | cppVar_94527;
	cppVar_94528 = (cppVar_94528 & cppMask_un_8_);
	bool cppVar_94530 = (cppVar_94528 == 152);
	if (cppVar_94530) {
	cppVar_94525 = SCON;
	} else {
	BIT_VEC cppVar_94531;
	BIT_VEC cppVar_94532 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_94533 = (cppVar_94532 << 3) | 7;
	cppVar_94533 = (cppVar_94533 & cppMask_un_5_);
	BIT_VEC cppVar_94534 = (0 << 5) | cppVar_94533;
	cppVar_94534 = (cppVar_94534 & cppMask_un_8_);
	bool cppVar_94536 = (cppVar_94534 == 153);
	if (cppVar_94536) {
	cppVar_94531 = SBUF;
	} else {
	BIT_VEC cppVar_94537;
	BIT_VEC cppVar_94538 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_94539 = (cppVar_94538 << 3) | 7;
	cppVar_94539 = (cppVar_94539 & cppMask_un_5_);
	BIT_VEC cppVar_94540 = (0 << 5) | cppVar_94539;
	cppVar_94540 = (cppVar_94540 & cppMask_un_8_);
	bool cppVar_94542 = (cppVar_94540 == 160);
	if (cppVar_94542) {
	cppVar_94537 = P2;
	} else {
	BIT_VEC cppVar_94543;
	BIT_VEC cppVar_94544 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_94545 = (cppVar_94544 << 3) | 7;
	cppVar_94545 = (cppVar_94545 & cppMask_un_5_);
	BIT_VEC cppVar_94546 = (0 << 5) | cppVar_94545;
	cppVar_94546 = (cppVar_94546 & cppMask_un_8_);
	bool cppVar_94548 = (cppVar_94546 == 168);
	if (cppVar_94548) {
	cppVar_94543 = IE;
	} else {
	BIT_VEC cppVar_94549;
	BIT_VEC cppVar_94550 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_94551 = (cppVar_94550 << 3) | 7;
	cppVar_94551 = (cppVar_94551 & cppMask_un_5_);
	BIT_VEC cppVar_94552 = (0 << 5) | cppVar_94551;
	cppVar_94552 = (cppVar_94552 & cppMask_un_8_);
	bool cppVar_94554 = (cppVar_94552 == 176);
	if (cppVar_94554) {
	cppVar_94549 = P3;
	} else {
	BIT_VEC cppVar_94555;
	BIT_VEC cppVar_94556 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_94557 = (cppVar_94556 << 3) | 7;
	cppVar_94557 = (cppVar_94557 & cppMask_un_5_);
	BIT_VEC cppVar_94558 = (0 << 5) | cppVar_94557;
	cppVar_94558 = (cppVar_94558 & cppMask_un_8_);
	bool cppVar_94560 = (cppVar_94558 == 184);
	if (cppVar_94560) {
	cppVar_94555 = IP;
	} else {
	BIT_VEC cppVar_94561;
	BIT_VEC cppVar_94562 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_94563 = (cppVar_94562 << 3) | 7;
	cppVar_94563 = (cppVar_94563 & cppMask_un_5_);
	BIT_VEC cppVar_94564 = (0 << 5) | cppVar_94563;
	cppVar_94564 = (cppVar_94564 & cppMask_un_8_);
	bool cppVar_94566 = (cppVar_94564 == 208);
	if (cppVar_94566) {
	cppVar_94561 = PSW;
	} else {
	BIT_VEC cppVar_94567;
	BIT_VEC cppVar_94568 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_94569 = (cppVar_94568 << 3) | 7;
	cppVar_94569 = (cppVar_94569 & cppMask_un_5_);
	BIT_VEC cppVar_94570 = (0 << 5) | cppVar_94569;
	cppVar_94570 = (cppVar_94570 & cppMask_un_8_);
	bool cppVar_94572 = (cppVar_94570 == 224);
	if (cppVar_94572) {
	cppVar_94567 = ACC;
	} else {
	BIT_VEC cppVar_94573;
	BIT_VEC cppVar_94574 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_94575 = (cppVar_94574 << 3) | 7;
	cppVar_94575 = (cppVar_94575 & cppMask_un_5_);
	BIT_VEC cppVar_94576 = (0 << 5) | cppVar_94575;
	cppVar_94576 = (cppVar_94576 & cppMask_un_8_);
	bool cppVar_94578 = (cppVar_94576 == 240);
	if (cppVar_94578) {
	cppVar_94573 = B;
	} else {
	cppVar_94573 = 0;
	}
	cppVar_94567 = cppVar_94573;
	}
	cppVar_94561 = cppVar_94567;
	}
	cppVar_94555 = cppVar_94561;
	}
	cppVar_94549 = cppVar_94555;
	}
	cppVar_94543 = cppVar_94549;
	}
	cppVar_94537 = cppVar_94543;
	}
	cppVar_94531 = cppVar_94537;
	}
	cppVar_94525 = cppVar_94531;
	}
	cppVar_94519 = cppVar_94525;
	}
	cppVar_94513 = cppVar_94519;
	}
	cppVar_94507 = cppVar_94513;
	}
	cppVar_94501 = cppVar_94507;
	}
	cppVar_94495 = cppVar_94501;
	}
	cppVar_94489 = cppVar_94495;
	}
	cppVar_94483 = cppVar_94489;
	}
	cppVar_94477 = cppVar_94483;
	}
	cppVar_94471 = cppVar_94477;
	}
	cppVar_94465 = cppVar_94471;
	}
	cppVar_94459 = cppVar_94465;
	}
	cppVar_94453 = cppVar_94459;
	}
	cppVar_94442 = cppVar_94453;
	}
	BIT_VEC cppVar_94581 = cppVar_94442 + 1;
	cppVar_94581 = (cppVar_94581 & cppMask_un_8_);
	type_mem cppVar_94582 = IRAM;
	cppVar_94582.wr(cppVar_94441, cppVar_94581);
	cppVar_94430 = cppVar_94582;
	} else {
	cppVar_94430 = IRAM;
	}
	cppVar_94426 = cppVar_94430;
	} else {
	type_mem cppVar_94583;
	BIT_VEC cppVar_94584 = ROM.rd(PC);
	bool cppVar_94586 = (cppVar_94584 == 14);
	if (cppVar_94586) {
	type_mem cppVar_94587;
	BIT_VEC cppVar_94589 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_94591 = (cppVar_94589 << 3) | 6;
	cppVar_94591 = (cppVar_94591 & cppMask_un_5_);
	BIT_VEC cppVar_94592 = (0 << 5) | cppVar_94591;
	cppVar_94592 = (cppVar_94592 & cppMask_un_8_);
	BIT_VEC cppVar_94593 = (cppVar_94592 >> 7) & cppMask_un_1_;
	bool cppVar_94595 = (cppVar_94593 == 0);
	if (cppVar_94595) {
	BIT_VEC cppVar_94596 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_94597 = (cppVar_94596 << 3) | 6;
	cppVar_94597 = (cppVar_94597 & cppMask_un_5_);
	BIT_VEC cppVar_94598 = (0 << 5) | cppVar_94597;
	cppVar_94598 = (cppVar_94598 & cppMask_un_8_);
	BIT_VEC cppVar_94599;
	BIT_VEC cppVar_94600 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_94601 = (cppVar_94600 << 3) | 6;
	cppVar_94601 = (cppVar_94601 & cppMask_un_5_);
	BIT_VEC cppVar_94602 = (0 << 5) | cppVar_94601;
	cppVar_94602 = (cppVar_94602 & cppMask_un_8_);
	BIT_VEC cppVar_94603 = (cppVar_94602 >> 7) & cppMask_un_1_;
	bool cppVar_94605 = (cppVar_94603 == 0);
	if (cppVar_94605) {
	BIT_VEC cppVar_94606 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_94607 = (cppVar_94606 << 3) | 6;
	cppVar_94607 = (cppVar_94607 & cppMask_un_5_);
	BIT_VEC cppVar_94608 = (0 << 5) | cppVar_94607;
	cppVar_94608 = (cppVar_94608 & cppMask_un_8_);
	BIT_VEC cppVar_94609 = IRAM.rd(cppVar_94608);
	cppVar_94599 = cppVar_94609;
	} else {
	BIT_VEC cppVar_94610;
	BIT_VEC cppVar_94611 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_94612 = (cppVar_94611 << 3) | 6;
	cppVar_94612 = (cppVar_94612 & cppMask_un_5_);
	BIT_VEC cppVar_94613 = (0 << 5) | cppVar_94612;
	cppVar_94613 = (cppVar_94613 & cppMask_un_8_);
	bool cppVar_94615 = (cppVar_94613 == 128);
	if (cppVar_94615) {
	cppVar_94610 = P0;
	} else {
	BIT_VEC cppVar_94616;
	BIT_VEC cppVar_94617 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_94618 = (cppVar_94617 << 3) | 6;
	cppVar_94618 = (cppVar_94618 & cppMask_un_5_);
	BIT_VEC cppVar_94619 = (0 << 5) | cppVar_94618;
	cppVar_94619 = (cppVar_94619 & cppMask_un_8_);
	bool cppVar_94621 = (cppVar_94619 == 129);
	if (cppVar_94621) {
	cppVar_94616 = SP;
	} else {
	BIT_VEC cppVar_94622;
	BIT_VEC cppVar_94623 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_94624 = (cppVar_94623 << 3) | 6;
	cppVar_94624 = (cppVar_94624 & cppMask_un_5_);
	BIT_VEC cppVar_94625 = (0 << 5) | cppVar_94624;
	cppVar_94625 = (cppVar_94625 & cppMask_un_8_);
	bool cppVar_94627 = (cppVar_94625 == 130);
	if (cppVar_94627) {
	cppVar_94622 = DPL;
	} else {
	BIT_VEC cppVar_94628;
	BIT_VEC cppVar_94629 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_94630 = (cppVar_94629 << 3) | 6;
	cppVar_94630 = (cppVar_94630 & cppMask_un_5_);
	BIT_VEC cppVar_94631 = (0 << 5) | cppVar_94630;
	cppVar_94631 = (cppVar_94631 & cppMask_un_8_);
	bool cppVar_94633 = (cppVar_94631 == 131);
	if (cppVar_94633) {
	cppVar_94628 = DPH;
	} else {
	BIT_VEC cppVar_94634;
	BIT_VEC cppVar_94635 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_94636 = (cppVar_94635 << 3) | 6;
	cppVar_94636 = (cppVar_94636 & cppMask_un_5_);
	BIT_VEC cppVar_94637 = (0 << 5) | cppVar_94636;
	cppVar_94637 = (cppVar_94637 & cppMask_un_8_);
	bool cppVar_94639 = (cppVar_94637 == 135);
	if (cppVar_94639) {
	cppVar_94634 = PCON;
	} else {
	BIT_VEC cppVar_94640;
	BIT_VEC cppVar_94641 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_94642 = (cppVar_94641 << 3) | 6;
	cppVar_94642 = (cppVar_94642 & cppMask_un_5_);
	BIT_VEC cppVar_94643 = (0 << 5) | cppVar_94642;
	cppVar_94643 = (cppVar_94643 & cppMask_un_8_);
	bool cppVar_94645 = (cppVar_94643 == 136);
	if (cppVar_94645) {
	cppVar_94640 = TCON;
	} else {
	BIT_VEC cppVar_94646;
	BIT_VEC cppVar_94647 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_94648 = (cppVar_94647 << 3) | 6;
	cppVar_94648 = (cppVar_94648 & cppMask_un_5_);
	BIT_VEC cppVar_94649 = (0 << 5) | cppVar_94648;
	cppVar_94649 = (cppVar_94649 & cppMask_un_8_);
	bool cppVar_94651 = (cppVar_94649 == 137);
	if (cppVar_94651) {
	cppVar_94646 = TMOD;
	} else {
	BIT_VEC cppVar_94652;
	BIT_VEC cppVar_94653 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_94654 = (cppVar_94653 << 3) | 6;
	cppVar_94654 = (cppVar_94654 & cppMask_un_5_);
	BIT_VEC cppVar_94655 = (0 << 5) | cppVar_94654;
	cppVar_94655 = (cppVar_94655 & cppMask_un_8_);
	bool cppVar_94657 = (cppVar_94655 == 138);
	if (cppVar_94657) {
	cppVar_94652 = TL0;
	} else {
	BIT_VEC cppVar_94658;
	BIT_VEC cppVar_94659 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_94660 = (cppVar_94659 << 3) | 6;
	cppVar_94660 = (cppVar_94660 & cppMask_un_5_);
	BIT_VEC cppVar_94661 = (0 << 5) | cppVar_94660;
	cppVar_94661 = (cppVar_94661 & cppMask_un_8_);
	bool cppVar_94663 = (cppVar_94661 == 140);
	if (cppVar_94663) {
	cppVar_94658 = TH0;
	} else {
	BIT_VEC cppVar_94664;
	BIT_VEC cppVar_94665 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_94666 = (cppVar_94665 << 3) | 6;
	cppVar_94666 = (cppVar_94666 & cppMask_un_5_);
	BIT_VEC cppVar_94667 = (0 << 5) | cppVar_94666;
	cppVar_94667 = (cppVar_94667 & cppMask_un_8_);
	bool cppVar_94669 = (cppVar_94667 == 139);
	if (cppVar_94669) {
	cppVar_94664 = TL1;
	} else {
	BIT_VEC cppVar_94670;
	BIT_VEC cppVar_94671 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_94672 = (cppVar_94671 << 3) | 6;
	cppVar_94672 = (cppVar_94672 & cppMask_un_5_);
	BIT_VEC cppVar_94673 = (0 << 5) | cppVar_94672;
	cppVar_94673 = (cppVar_94673 & cppMask_un_8_);
	bool cppVar_94675 = (cppVar_94673 == 141);
	if (cppVar_94675) {
	cppVar_94670 = TH1;
	} else {
	BIT_VEC cppVar_94676;
	BIT_VEC cppVar_94677 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_94678 = (cppVar_94677 << 3) | 6;
	cppVar_94678 = (cppVar_94678 & cppMask_un_5_);
	BIT_VEC cppVar_94679 = (0 << 5) | cppVar_94678;
	cppVar_94679 = (cppVar_94679 & cppMask_un_8_);
	bool cppVar_94681 = (cppVar_94679 == 144);
	if (cppVar_94681) {
	cppVar_94676 = P1;
	} else {
	BIT_VEC cppVar_94682;
	BIT_VEC cppVar_94683 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_94684 = (cppVar_94683 << 3) | 6;
	cppVar_94684 = (cppVar_94684 & cppMask_un_5_);
	BIT_VEC cppVar_94685 = (0 << 5) | cppVar_94684;
	cppVar_94685 = (cppVar_94685 & cppMask_un_8_);
	bool cppVar_94687 = (cppVar_94685 == 152);
	if (cppVar_94687) {
	cppVar_94682 = SCON;
	} else {
	BIT_VEC cppVar_94688;
	BIT_VEC cppVar_94689 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_94690 = (cppVar_94689 << 3) | 6;
	cppVar_94690 = (cppVar_94690 & cppMask_un_5_);
	BIT_VEC cppVar_94691 = (0 << 5) | cppVar_94690;
	cppVar_94691 = (cppVar_94691 & cppMask_un_8_);
	bool cppVar_94693 = (cppVar_94691 == 153);
	if (cppVar_94693) {
	cppVar_94688 = SBUF;
	} else {
	BIT_VEC cppVar_94694;
	BIT_VEC cppVar_94695 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_94696 = (cppVar_94695 << 3) | 6;
	cppVar_94696 = (cppVar_94696 & cppMask_un_5_);
	BIT_VEC cppVar_94697 = (0 << 5) | cppVar_94696;
	cppVar_94697 = (cppVar_94697 & cppMask_un_8_);
	bool cppVar_94699 = (cppVar_94697 == 160);
	if (cppVar_94699) {
	cppVar_94694 = P2;
	} else {
	BIT_VEC cppVar_94700;
	BIT_VEC cppVar_94701 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_94702 = (cppVar_94701 << 3) | 6;
	cppVar_94702 = (cppVar_94702 & cppMask_un_5_);
	BIT_VEC cppVar_94703 = (0 << 5) | cppVar_94702;
	cppVar_94703 = (cppVar_94703 & cppMask_un_8_);
	bool cppVar_94705 = (cppVar_94703 == 168);
	if (cppVar_94705) {
	cppVar_94700 = IE;
	} else {
	BIT_VEC cppVar_94706;
	BIT_VEC cppVar_94707 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_94708 = (cppVar_94707 << 3) | 6;
	cppVar_94708 = (cppVar_94708 & cppMask_un_5_);
	BIT_VEC cppVar_94709 = (0 << 5) | cppVar_94708;
	cppVar_94709 = (cppVar_94709 & cppMask_un_8_);
	bool cppVar_94711 = (cppVar_94709 == 176);
	if (cppVar_94711) {
	cppVar_94706 = P3;
	} else {
	BIT_VEC cppVar_94712;
	BIT_VEC cppVar_94713 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_94714 = (cppVar_94713 << 3) | 6;
	cppVar_94714 = (cppVar_94714 & cppMask_un_5_);
	BIT_VEC cppVar_94715 = (0 << 5) | cppVar_94714;
	cppVar_94715 = (cppVar_94715 & cppMask_un_8_);
	bool cppVar_94717 = (cppVar_94715 == 184);
	if (cppVar_94717) {
	cppVar_94712 = IP;
	} else {
	BIT_VEC cppVar_94718;
	BIT_VEC cppVar_94719 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_94720 = (cppVar_94719 << 3) | 6;
	cppVar_94720 = (cppVar_94720 & cppMask_un_5_);
	BIT_VEC cppVar_94721 = (0 << 5) | cppVar_94720;
	cppVar_94721 = (cppVar_94721 & cppMask_un_8_);
	bool cppVar_94723 = (cppVar_94721 == 208);
	if (cppVar_94723) {
	cppVar_94718 = PSW;
	} else {
	BIT_VEC cppVar_94724;
	BIT_VEC cppVar_94725 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_94726 = (cppVar_94725 << 3) | 6;
	cppVar_94726 = (cppVar_94726 & cppMask_un_5_);
	BIT_VEC cppVar_94727 = (0 << 5) | cppVar_94726;
	cppVar_94727 = (cppVar_94727 & cppMask_un_8_);
	bool cppVar_94729 = (cppVar_94727 == 224);
	if (cppVar_94729) {
	cppVar_94724 = ACC;
	} else {
	BIT_VEC cppVar_94730;
	BIT_VEC cppVar_94731 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_94732 = (cppVar_94731 << 3) | 6;
	cppVar_94732 = (cppVar_94732 & cppMask_un_5_);
	BIT_VEC cppVar_94733 = (0 << 5) | cppVar_94732;
	cppVar_94733 = (cppVar_94733 & cppMask_un_8_);
	bool cppVar_94735 = (cppVar_94733 == 240);
	if (cppVar_94735) {
	cppVar_94730 = B;
	} else {
	cppVar_94730 = 0;
	}
	cppVar_94724 = cppVar_94730;
	}
	cppVar_94718 = cppVar_94724;
	}
	cppVar_94712 = cppVar_94718;
	}
	cppVar_94706 = cppVar_94712;
	}
	cppVar_94700 = cppVar_94706;
	}
	cppVar_94694 = cppVar_94700;
	}
	cppVar_94688 = cppVar_94694;
	}
	cppVar_94682 = cppVar_94688;
	}
	cppVar_94676 = cppVar_94682;
	}
	cppVar_94670 = cppVar_94676;
	}
	cppVar_94664 = cppVar_94670;
	}
	cppVar_94658 = cppVar_94664;
	}
	cppVar_94652 = cppVar_94658;
	}
	cppVar_94646 = cppVar_94652;
	}
	cppVar_94640 = cppVar_94646;
	}
	cppVar_94634 = cppVar_94640;
	}
	cppVar_94628 = cppVar_94634;
	}
	cppVar_94622 = cppVar_94628;
	}
	cppVar_94616 = cppVar_94622;
	}
	cppVar_94610 = cppVar_94616;
	}
	cppVar_94599 = cppVar_94610;
	}
	BIT_VEC cppVar_94738 = cppVar_94599 + 1;
	cppVar_94738 = (cppVar_94738 & cppMask_un_8_);
	type_mem cppVar_94739 = IRAM;
	cppVar_94739.wr(cppVar_94598, cppVar_94738);
	cppVar_94587 = cppVar_94739;
	} else {
	cppVar_94587 = IRAM;
	}
	cppVar_94583 = cppVar_94587;
	} else {
	type_mem cppVar_94740;
	BIT_VEC cppVar_94741 = ROM.rd(PC);
	bool cppVar_94743 = (cppVar_94741 == 13);
	if (cppVar_94743) {
	type_mem cppVar_94744;
	BIT_VEC cppVar_94746 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_94748 = (cppVar_94746 << 3) | 5;
	cppVar_94748 = (cppVar_94748 & cppMask_un_5_);
	BIT_VEC cppVar_94749 = (0 << 5) | cppVar_94748;
	cppVar_94749 = (cppVar_94749 & cppMask_un_8_);
	BIT_VEC cppVar_94750 = (cppVar_94749 >> 7) & cppMask_un_1_;
	bool cppVar_94752 = (cppVar_94750 == 0);
	if (cppVar_94752) {
	BIT_VEC cppVar_94753 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_94754 = (cppVar_94753 << 3) | 5;
	cppVar_94754 = (cppVar_94754 & cppMask_un_5_);
	BIT_VEC cppVar_94755 = (0 << 5) | cppVar_94754;
	cppVar_94755 = (cppVar_94755 & cppMask_un_8_);
	BIT_VEC cppVar_94756;
	BIT_VEC cppVar_94757 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_94758 = (cppVar_94757 << 3) | 5;
	cppVar_94758 = (cppVar_94758 & cppMask_un_5_);
	BIT_VEC cppVar_94759 = (0 << 5) | cppVar_94758;
	cppVar_94759 = (cppVar_94759 & cppMask_un_8_);
	BIT_VEC cppVar_94760 = (cppVar_94759 >> 7) & cppMask_un_1_;
	bool cppVar_94762 = (cppVar_94760 == 0);
	if (cppVar_94762) {
	BIT_VEC cppVar_94763 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_94764 = (cppVar_94763 << 3) | 5;
	cppVar_94764 = (cppVar_94764 & cppMask_un_5_);
	BIT_VEC cppVar_94765 = (0 << 5) | cppVar_94764;
	cppVar_94765 = (cppVar_94765 & cppMask_un_8_);
	BIT_VEC cppVar_94766 = IRAM.rd(cppVar_94765);
	cppVar_94756 = cppVar_94766;
	} else {
	BIT_VEC cppVar_94767;
	BIT_VEC cppVar_94768 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_94769 = (cppVar_94768 << 3) | 5;
	cppVar_94769 = (cppVar_94769 & cppMask_un_5_);
	BIT_VEC cppVar_94770 = (0 << 5) | cppVar_94769;
	cppVar_94770 = (cppVar_94770 & cppMask_un_8_);
	bool cppVar_94772 = (cppVar_94770 == 128);
	if (cppVar_94772) {
	cppVar_94767 = P0;
	} else {
	BIT_VEC cppVar_94773;
	BIT_VEC cppVar_94774 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_94775 = (cppVar_94774 << 3) | 5;
	cppVar_94775 = (cppVar_94775 & cppMask_un_5_);
	BIT_VEC cppVar_94776 = (0 << 5) | cppVar_94775;
	cppVar_94776 = (cppVar_94776 & cppMask_un_8_);
	bool cppVar_94778 = (cppVar_94776 == 129);
	if (cppVar_94778) {
	cppVar_94773 = SP;
	} else {
	BIT_VEC cppVar_94779;
	BIT_VEC cppVar_94780 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_94781 = (cppVar_94780 << 3) | 5;
	cppVar_94781 = (cppVar_94781 & cppMask_un_5_);
	BIT_VEC cppVar_94782 = (0 << 5) | cppVar_94781;
	cppVar_94782 = (cppVar_94782 & cppMask_un_8_);
	bool cppVar_94784 = (cppVar_94782 == 130);
	if (cppVar_94784) {
	cppVar_94779 = DPL;
	} else {
	BIT_VEC cppVar_94785;
	BIT_VEC cppVar_94786 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_94787 = (cppVar_94786 << 3) | 5;
	cppVar_94787 = (cppVar_94787 & cppMask_un_5_);
	BIT_VEC cppVar_94788 = (0 << 5) | cppVar_94787;
	cppVar_94788 = (cppVar_94788 & cppMask_un_8_);
	bool cppVar_94790 = (cppVar_94788 == 131);
	if (cppVar_94790) {
	cppVar_94785 = DPH;
	} else {
	BIT_VEC cppVar_94791;
	BIT_VEC cppVar_94792 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_94793 = (cppVar_94792 << 3) | 5;
	cppVar_94793 = (cppVar_94793 & cppMask_un_5_);
	BIT_VEC cppVar_94794 = (0 << 5) | cppVar_94793;
	cppVar_94794 = (cppVar_94794 & cppMask_un_8_);
	bool cppVar_94796 = (cppVar_94794 == 135);
	if (cppVar_94796) {
	cppVar_94791 = PCON;
	} else {
	BIT_VEC cppVar_94797;
	BIT_VEC cppVar_94798 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_94799 = (cppVar_94798 << 3) | 5;
	cppVar_94799 = (cppVar_94799 & cppMask_un_5_);
	BIT_VEC cppVar_94800 = (0 << 5) | cppVar_94799;
	cppVar_94800 = (cppVar_94800 & cppMask_un_8_);
	bool cppVar_94802 = (cppVar_94800 == 136);
	if (cppVar_94802) {
	cppVar_94797 = TCON;
	} else {
	BIT_VEC cppVar_94803;
	BIT_VEC cppVar_94804 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_94805 = (cppVar_94804 << 3) | 5;
	cppVar_94805 = (cppVar_94805 & cppMask_un_5_);
	BIT_VEC cppVar_94806 = (0 << 5) | cppVar_94805;
	cppVar_94806 = (cppVar_94806 & cppMask_un_8_);
	bool cppVar_94808 = (cppVar_94806 == 137);
	if (cppVar_94808) {
	cppVar_94803 = TMOD;
	} else {
	BIT_VEC cppVar_94809;
	BIT_VEC cppVar_94810 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_94811 = (cppVar_94810 << 3) | 5;
	cppVar_94811 = (cppVar_94811 & cppMask_un_5_);
	BIT_VEC cppVar_94812 = (0 << 5) | cppVar_94811;
	cppVar_94812 = (cppVar_94812 & cppMask_un_8_);
	bool cppVar_94814 = (cppVar_94812 == 138);
	if (cppVar_94814) {
	cppVar_94809 = TL0;
	} else {
	BIT_VEC cppVar_94815;
	BIT_VEC cppVar_94816 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_94817 = (cppVar_94816 << 3) | 5;
	cppVar_94817 = (cppVar_94817 & cppMask_un_5_);
	BIT_VEC cppVar_94818 = (0 << 5) | cppVar_94817;
	cppVar_94818 = (cppVar_94818 & cppMask_un_8_);
	bool cppVar_94820 = (cppVar_94818 == 140);
	if (cppVar_94820) {
	cppVar_94815 = TH0;
	} else {
	BIT_VEC cppVar_94821;
	BIT_VEC cppVar_94822 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_94823 = (cppVar_94822 << 3) | 5;
	cppVar_94823 = (cppVar_94823 & cppMask_un_5_);
	BIT_VEC cppVar_94824 = (0 << 5) | cppVar_94823;
	cppVar_94824 = (cppVar_94824 & cppMask_un_8_);
	bool cppVar_94826 = (cppVar_94824 == 139);
	if (cppVar_94826) {
	cppVar_94821 = TL1;
	} else {
	BIT_VEC cppVar_94827;
	BIT_VEC cppVar_94828 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_94829 = (cppVar_94828 << 3) | 5;
	cppVar_94829 = (cppVar_94829 & cppMask_un_5_);
	BIT_VEC cppVar_94830 = (0 << 5) | cppVar_94829;
	cppVar_94830 = (cppVar_94830 & cppMask_un_8_);
	bool cppVar_94832 = (cppVar_94830 == 141);
	if (cppVar_94832) {
	cppVar_94827 = TH1;
	} else {
	BIT_VEC cppVar_94833;
	BIT_VEC cppVar_94834 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_94835 = (cppVar_94834 << 3) | 5;
	cppVar_94835 = (cppVar_94835 & cppMask_un_5_);
	BIT_VEC cppVar_94836 = (0 << 5) | cppVar_94835;
	cppVar_94836 = (cppVar_94836 & cppMask_un_8_);
	bool cppVar_94838 = (cppVar_94836 == 144);
	if (cppVar_94838) {
	cppVar_94833 = P1;
	} else {
	BIT_VEC cppVar_94839;
	BIT_VEC cppVar_94840 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_94841 = (cppVar_94840 << 3) | 5;
	cppVar_94841 = (cppVar_94841 & cppMask_un_5_);
	BIT_VEC cppVar_94842 = (0 << 5) | cppVar_94841;
	cppVar_94842 = (cppVar_94842 & cppMask_un_8_);
	bool cppVar_94844 = (cppVar_94842 == 152);
	if (cppVar_94844) {
	cppVar_94839 = SCON;
	} else {
	BIT_VEC cppVar_94845;
	BIT_VEC cppVar_94846 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_94847 = (cppVar_94846 << 3) | 5;
	cppVar_94847 = (cppVar_94847 & cppMask_un_5_);
	BIT_VEC cppVar_94848 = (0 << 5) | cppVar_94847;
	cppVar_94848 = (cppVar_94848 & cppMask_un_8_);
	bool cppVar_94850 = (cppVar_94848 == 153);
	if (cppVar_94850) {
	cppVar_94845 = SBUF;
	} else {
	BIT_VEC cppVar_94851;
	BIT_VEC cppVar_94852 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_94853 = (cppVar_94852 << 3) | 5;
	cppVar_94853 = (cppVar_94853 & cppMask_un_5_);
	BIT_VEC cppVar_94854 = (0 << 5) | cppVar_94853;
	cppVar_94854 = (cppVar_94854 & cppMask_un_8_);
	bool cppVar_94856 = (cppVar_94854 == 160);
	if (cppVar_94856) {
	cppVar_94851 = P2;
	} else {
	BIT_VEC cppVar_94857;
	BIT_VEC cppVar_94858 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_94859 = (cppVar_94858 << 3) | 5;
	cppVar_94859 = (cppVar_94859 & cppMask_un_5_);
	BIT_VEC cppVar_94860 = (0 << 5) | cppVar_94859;
	cppVar_94860 = (cppVar_94860 & cppMask_un_8_);
	bool cppVar_94862 = (cppVar_94860 == 168);
	if (cppVar_94862) {
	cppVar_94857 = IE;
	} else {
	BIT_VEC cppVar_94863;
	BIT_VEC cppVar_94864 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_94865 = (cppVar_94864 << 3) | 5;
	cppVar_94865 = (cppVar_94865 & cppMask_un_5_);
	BIT_VEC cppVar_94866 = (0 << 5) | cppVar_94865;
	cppVar_94866 = (cppVar_94866 & cppMask_un_8_);
	bool cppVar_94868 = (cppVar_94866 == 176);
	if (cppVar_94868) {
	cppVar_94863 = P3;
	} else {
	BIT_VEC cppVar_94869;
	BIT_VEC cppVar_94870 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_94871 = (cppVar_94870 << 3) | 5;
	cppVar_94871 = (cppVar_94871 & cppMask_un_5_);
	BIT_VEC cppVar_94872 = (0 << 5) | cppVar_94871;
	cppVar_94872 = (cppVar_94872 & cppMask_un_8_);
	bool cppVar_94874 = (cppVar_94872 == 184);
	if (cppVar_94874) {
	cppVar_94869 = IP;
	} else {
	BIT_VEC cppVar_94875;
	BIT_VEC cppVar_94876 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_94877 = (cppVar_94876 << 3) | 5;
	cppVar_94877 = (cppVar_94877 & cppMask_un_5_);
	BIT_VEC cppVar_94878 = (0 << 5) | cppVar_94877;
	cppVar_94878 = (cppVar_94878 & cppMask_un_8_);
	bool cppVar_94880 = (cppVar_94878 == 208);
	if (cppVar_94880) {
	cppVar_94875 = PSW;
	} else {
	BIT_VEC cppVar_94881;
	BIT_VEC cppVar_94882 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_94883 = (cppVar_94882 << 3) | 5;
	cppVar_94883 = (cppVar_94883 & cppMask_un_5_);
	BIT_VEC cppVar_94884 = (0 << 5) | cppVar_94883;
	cppVar_94884 = (cppVar_94884 & cppMask_un_8_);
	bool cppVar_94886 = (cppVar_94884 == 224);
	if (cppVar_94886) {
	cppVar_94881 = ACC;
	} else {
	BIT_VEC cppVar_94887;
	BIT_VEC cppVar_94888 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_94889 = (cppVar_94888 << 3) | 5;
	cppVar_94889 = (cppVar_94889 & cppMask_un_5_);
	BIT_VEC cppVar_94890 = (0 << 5) | cppVar_94889;
	cppVar_94890 = (cppVar_94890 & cppMask_un_8_);
	bool cppVar_94892 = (cppVar_94890 == 240);
	if (cppVar_94892) {
	cppVar_94887 = B;
	} else {
	cppVar_94887 = 0;
	}
	cppVar_94881 = cppVar_94887;
	}
	cppVar_94875 = cppVar_94881;
	}
	cppVar_94869 = cppVar_94875;
	}
	cppVar_94863 = cppVar_94869;
	}
	cppVar_94857 = cppVar_94863;
	}
	cppVar_94851 = cppVar_94857;
	}
	cppVar_94845 = cppVar_94851;
	}
	cppVar_94839 = cppVar_94845;
	}
	cppVar_94833 = cppVar_94839;
	}
	cppVar_94827 = cppVar_94833;
	}
	cppVar_94821 = cppVar_94827;
	}
	cppVar_94815 = cppVar_94821;
	}
	cppVar_94809 = cppVar_94815;
	}
	cppVar_94803 = cppVar_94809;
	}
	cppVar_94797 = cppVar_94803;
	}
	cppVar_94791 = cppVar_94797;
	}
	cppVar_94785 = cppVar_94791;
	}
	cppVar_94779 = cppVar_94785;
	}
	cppVar_94773 = cppVar_94779;
	}
	cppVar_94767 = cppVar_94773;
	}
	cppVar_94756 = cppVar_94767;
	}
	BIT_VEC cppVar_94895 = cppVar_94756 + 1;
	cppVar_94895 = (cppVar_94895 & cppMask_un_8_);
	type_mem cppVar_94896 = IRAM;
	cppVar_94896.wr(cppVar_94755, cppVar_94895);
	cppVar_94744 = cppVar_94896;
	} else {
	cppVar_94744 = IRAM;
	}
	cppVar_94740 = cppVar_94744;
	} else {
	type_mem cppVar_94897;
	BIT_VEC cppVar_94898 = ROM.rd(PC);
	bool cppVar_94900 = (cppVar_94898 == 12);
	if (cppVar_94900) {
	type_mem cppVar_94901;
	BIT_VEC cppVar_94903 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_94905 = (cppVar_94903 << 3) | 4;
	cppVar_94905 = (cppVar_94905 & cppMask_un_5_);
	BIT_VEC cppVar_94906 = (0 << 5) | cppVar_94905;
	cppVar_94906 = (cppVar_94906 & cppMask_un_8_);
	BIT_VEC cppVar_94907 = (cppVar_94906 >> 7) & cppMask_un_1_;
	bool cppVar_94909 = (cppVar_94907 == 0);
	if (cppVar_94909) {
	BIT_VEC cppVar_94910 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_94911 = (cppVar_94910 << 3) | 4;
	cppVar_94911 = (cppVar_94911 & cppMask_un_5_);
	BIT_VEC cppVar_94912 = (0 << 5) | cppVar_94911;
	cppVar_94912 = (cppVar_94912 & cppMask_un_8_);
	BIT_VEC cppVar_94913;
	BIT_VEC cppVar_94914 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_94915 = (cppVar_94914 << 3) | 4;
	cppVar_94915 = (cppVar_94915 & cppMask_un_5_);
	BIT_VEC cppVar_94916 = (0 << 5) | cppVar_94915;
	cppVar_94916 = (cppVar_94916 & cppMask_un_8_);
	BIT_VEC cppVar_94917 = (cppVar_94916 >> 7) & cppMask_un_1_;
	bool cppVar_94919 = (cppVar_94917 == 0);
	if (cppVar_94919) {
	BIT_VEC cppVar_94920 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_94921 = (cppVar_94920 << 3) | 4;
	cppVar_94921 = (cppVar_94921 & cppMask_un_5_);
	BIT_VEC cppVar_94922 = (0 << 5) | cppVar_94921;
	cppVar_94922 = (cppVar_94922 & cppMask_un_8_);
	BIT_VEC cppVar_94923 = IRAM.rd(cppVar_94922);
	cppVar_94913 = cppVar_94923;
	} else {
	BIT_VEC cppVar_94924;
	BIT_VEC cppVar_94925 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_94926 = (cppVar_94925 << 3) | 4;
	cppVar_94926 = (cppVar_94926 & cppMask_un_5_);
	BIT_VEC cppVar_94927 = (0 << 5) | cppVar_94926;
	cppVar_94927 = (cppVar_94927 & cppMask_un_8_);
	bool cppVar_94929 = (cppVar_94927 == 128);
	if (cppVar_94929) {
	cppVar_94924 = P0;
	} else {
	BIT_VEC cppVar_94930;
	BIT_VEC cppVar_94931 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_94932 = (cppVar_94931 << 3) | 4;
	cppVar_94932 = (cppVar_94932 & cppMask_un_5_);
	BIT_VEC cppVar_94933 = (0 << 5) | cppVar_94932;
	cppVar_94933 = (cppVar_94933 & cppMask_un_8_);
	bool cppVar_94935 = (cppVar_94933 == 129);
	if (cppVar_94935) {
	cppVar_94930 = SP;
	} else {
	BIT_VEC cppVar_94936;
	BIT_VEC cppVar_94937 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_94938 = (cppVar_94937 << 3) | 4;
	cppVar_94938 = (cppVar_94938 & cppMask_un_5_);
	BIT_VEC cppVar_94939 = (0 << 5) | cppVar_94938;
	cppVar_94939 = (cppVar_94939 & cppMask_un_8_);
	bool cppVar_94941 = (cppVar_94939 == 130);
	if (cppVar_94941) {
	cppVar_94936 = DPL;
	} else {
	BIT_VEC cppVar_94942;
	BIT_VEC cppVar_94943 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_94944 = (cppVar_94943 << 3) | 4;
	cppVar_94944 = (cppVar_94944 & cppMask_un_5_);
	BIT_VEC cppVar_94945 = (0 << 5) | cppVar_94944;
	cppVar_94945 = (cppVar_94945 & cppMask_un_8_);
	bool cppVar_94947 = (cppVar_94945 == 131);
	if (cppVar_94947) {
	cppVar_94942 = DPH;
	} else {
	BIT_VEC cppVar_94948;
	BIT_VEC cppVar_94949 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_94950 = (cppVar_94949 << 3) | 4;
	cppVar_94950 = (cppVar_94950 & cppMask_un_5_);
	BIT_VEC cppVar_94951 = (0 << 5) | cppVar_94950;
	cppVar_94951 = (cppVar_94951 & cppMask_un_8_);
	bool cppVar_94953 = (cppVar_94951 == 135);
	if (cppVar_94953) {
	cppVar_94948 = PCON;
	} else {
	BIT_VEC cppVar_94954;
	BIT_VEC cppVar_94955 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_94956 = (cppVar_94955 << 3) | 4;
	cppVar_94956 = (cppVar_94956 & cppMask_un_5_);
	BIT_VEC cppVar_94957 = (0 << 5) | cppVar_94956;
	cppVar_94957 = (cppVar_94957 & cppMask_un_8_);
	bool cppVar_94959 = (cppVar_94957 == 136);
	if (cppVar_94959) {
	cppVar_94954 = TCON;
	} else {
	BIT_VEC cppVar_94960;
	BIT_VEC cppVar_94961 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_94962 = (cppVar_94961 << 3) | 4;
	cppVar_94962 = (cppVar_94962 & cppMask_un_5_);
	BIT_VEC cppVar_94963 = (0 << 5) | cppVar_94962;
	cppVar_94963 = (cppVar_94963 & cppMask_un_8_);
	bool cppVar_94965 = (cppVar_94963 == 137);
	if (cppVar_94965) {
	cppVar_94960 = TMOD;
	} else {
	BIT_VEC cppVar_94966;
	BIT_VEC cppVar_94967 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_94968 = (cppVar_94967 << 3) | 4;
	cppVar_94968 = (cppVar_94968 & cppMask_un_5_);
	BIT_VEC cppVar_94969 = (0 << 5) | cppVar_94968;
	cppVar_94969 = (cppVar_94969 & cppMask_un_8_);
	bool cppVar_94971 = (cppVar_94969 == 138);
	if (cppVar_94971) {
	cppVar_94966 = TL0;
	} else {
	BIT_VEC cppVar_94972;
	BIT_VEC cppVar_94973 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_94974 = (cppVar_94973 << 3) | 4;
	cppVar_94974 = (cppVar_94974 & cppMask_un_5_);
	BIT_VEC cppVar_94975 = (0 << 5) | cppVar_94974;
	cppVar_94975 = (cppVar_94975 & cppMask_un_8_);
	bool cppVar_94977 = (cppVar_94975 == 140);
	if (cppVar_94977) {
	cppVar_94972 = TH0;
	} else {
	BIT_VEC cppVar_94978;
	BIT_VEC cppVar_94979 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_94980 = (cppVar_94979 << 3) | 4;
	cppVar_94980 = (cppVar_94980 & cppMask_un_5_);
	BIT_VEC cppVar_94981 = (0 << 5) | cppVar_94980;
	cppVar_94981 = (cppVar_94981 & cppMask_un_8_);
	bool cppVar_94983 = (cppVar_94981 == 139);
	if (cppVar_94983) {
	cppVar_94978 = TL1;
	} else {
	BIT_VEC cppVar_94984;
	BIT_VEC cppVar_94985 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_94986 = (cppVar_94985 << 3) | 4;
	cppVar_94986 = (cppVar_94986 & cppMask_un_5_);
	BIT_VEC cppVar_94987 = (0 << 5) | cppVar_94986;
	cppVar_94987 = (cppVar_94987 & cppMask_un_8_);
	bool cppVar_94989 = (cppVar_94987 == 141);
	if (cppVar_94989) {
	cppVar_94984 = TH1;
	} else {
	BIT_VEC cppVar_94990;
	BIT_VEC cppVar_94991 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_94992 = (cppVar_94991 << 3) | 4;
	cppVar_94992 = (cppVar_94992 & cppMask_un_5_);
	BIT_VEC cppVar_94993 = (0 << 5) | cppVar_94992;
	cppVar_94993 = (cppVar_94993 & cppMask_un_8_);
	bool cppVar_94995 = (cppVar_94993 == 144);
	if (cppVar_94995) {
	cppVar_94990 = P1;
	} else {
	BIT_VEC cppVar_94996;
	BIT_VEC cppVar_94997 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_94998 = (cppVar_94997 << 3) | 4;
	cppVar_94998 = (cppVar_94998 & cppMask_un_5_);
	BIT_VEC cppVar_94999 = (0 << 5) | cppVar_94998;
	cppVar_94999 = (cppVar_94999 & cppMask_un_8_);
	bool cppVar_95001 = (cppVar_94999 == 152);
	if (cppVar_95001) {
	cppVar_94996 = SCON;
	} else {
	BIT_VEC cppVar_95002;
	BIT_VEC cppVar_95003 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_95004 = (cppVar_95003 << 3) | 4;
	cppVar_95004 = (cppVar_95004 & cppMask_un_5_);
	BIT_VEC cppVar_95005 = (0 << 5) | cppVar_95004;
	cppVar_95005 = (cppVar_95005 & cppMask_un_8_);
	bool cppVar_95007 = (cppVar_95005 == 153);
	if (cppVar_95007) {
	cppVar_95002 = SBUF;
	} else {
	BIT_VEC cppVar_95008;
	BIT_VEC cppVar_95009 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_95010 = (cppVar_95009 << 3) | 4;
	cppVar_95010 = (cppVar_95010 & cppMask_un_5_);
	BIT_VEC cppVar_95011 = (0 << 5) | cppVar_95010;
	cppVar_95011 = (cppVar_95011 & cppMask_un_8_);
	bool cppVar_95013 = (cppVar_95011 == 160);
	if (cppVar_95013) {
	cppVar_95008 = P2;
	} else {
	BIT_VEC cppVar_95014;
	BIT_VEC cppVar_95015 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_95016 = (cppVar_95015 << 3) | 4;
	cppVar_95016 = (cppVar_95016 & cppMask_un_5_);
	BIT_VEC cppVar_95017 = (0 << 5) | cppVar_95016;
	cppVar_95017 = (cppVar_95017 & cppMask_un_8_);
	bool cppVar_95019 = (cppVar_95017 == 168);
	if (cppVar_95019) {
	cppVar_95014 = IE;
	} else {
	BIT_VEC cppVar_95020;
	BIT_VEC cppVar_95021 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_95022 = (cppVar_95021 << 3) | 4;
	cppVar_95022 = (cppVar_95022 & cppMask_un_5_);
	BIT_VEC cppVar_95023 = (0 << 5) | cppVar_95022;
	cppVar_95023 = (cppVar_95023 & cppMask_un_8_);
	bool cppVar_95025 = (cppVar_95023 == 176);
	if (cppVar_95025) {
	cppVar_95020 = P3;
	} else {
	BIT_VEC cppVar_95026;
	BIT_VEC cppVar_95027 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_95028 = (cppVar_95027 << 3) | 4;
	cppVar_95028 = (cppVar_95028 & cppMask_un_5_);
	BIT_VEC cppVar_95029 = (0 << 5) | cppVar_95028;
	cppVar_95029 = (cppVar_95029 & cppMask_un_8_);
	bool cppVar_95031 = (cppVar_95029 == 184);
	if (cppVar_95031) {
	cppVar_95026 = IP;
	} else {
	BIT_VEC cppVar_95032;
	BIT_VEC cppVar_95033 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_95034 = (cppVar_95033 << 3) | 4;
	cppVar_95034 = (cppVar_95034 & cppMask_un_5_);
	BIT_VEC cppVar_95035 = (0 << 5) | cppVar_95034;
	cppVar_95035 = (cppVar_95035 & cppMask_un_8_);
	bool cppVar_95037 = (cppVar_95035 == 208);
	if (cppVar_95037) {
	cppVar_95032 = PSW;
	} else {
	BIT_VEC cppVar_95038;
	BIT_VEC cppVar_95039 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_95040 = (cppVar_95039 << 3) | 4;
	cppVar_95040 = (cppVar_95040 & cppMask_un_5_);
	BIT_VEC cppVar_95041 = (0 << 5) | cppVar_95040;
	cppVar_95041 = (cppVar_95041 & cppMask_un_8_);
	bool cppVar_95043 = (cppVar_95041 == 224);
	if (cppVar_95043) {
	cppVar_95038 = ACC;
	} else {
	BIT_VEC cppVar_95044;
	BIT_VEC cppVar_95045 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_95046 = (cppVar_95045 << 3) | 4;
	cppVar_95046 = (cppVar_95046 & cppMask_un_5_);
	BIT_VEC cppVar_95047 = (0 << 5) | cppVar_95046;
	cppVar_95047 = (cppVar_95047 & cppMask_un_8_);
	bool cppVar_95049 = (cppVar_95047 == 240);
	if (cppVar_95049) {
	cppVar_95044 = B;
	} else {
	cppVar_95044 = 0;
	}
	cppVar_95038 = cppVar_95044;
	}
	cppVar_95032 = cppVar_95038;
	}
	cppVar_95026 = cppVar_95032;
	}
	cppVar_95020 = cppVar_95026;
	}
	cppVar_95014 = cppVar_95020;
	}
	cppVar_95008 = cppVar_95014;
	}
	cppVar_95002 = cppVar_95008;
	}
	cppVar_94996 = cppVar_95002;
	}
	cppVar_94990 = cppVar_94996;
	}
	cppVar_94984 = cppVar_94990;
	}
	cppVar_94978 = cppVar_94984;
	}
	cppVar_94972 = cppVar_94978;
	}
	cppVar_94966 = cppVar_94972;
	}
	cppVar_94960 = cppVar_94966;
	}
	cppVar_94954 = cppVar_94960;
	}
	cppVar_94948 = cppVar_94954;
	}
	cppVar_94942 = cppVar_94948;
	}
	cppVar_94936 = cppVar_94942;
	}
	cppVar_94930 = cppVar_94936;
	}
	cppVar_94924 = cppVar_94930;
	}
	cppVar_94913 = cppVar_94924;
	}
	BIT_VEC cppVar_95052 = cppVar_94913 + 1;
	cppVar_95052 = (cppVar_95052 & cppMask_un_8_);
	type_mem cppVar_95053 = IRAM;
	cppVar_95053.wr(cppVar_94912, cppVar_95052);
	cppVar_94901 = cppVar_95053;
	} else {
	cppVar_94901 = IRAM;
	}
	cppVar_94897 = cppVar_94901;
	} else {
	type_mem cppVar_95054;
	BIT_VEC cppVar_95055 = ROM.rd(PC);
	bool cppVar_95057 = (cppVar_95055 == 11);
	if (cppVar_95057) {
	type_mem cppVar_95058;
	BIT_VEC cppVar_95060 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_95062 = (cppVar_95060 << 3) | 3;
	cppVar_95062 = (cppVar_95062 & cppMask_un_5_);
	BIT_VEC cppVar_95063 = (0 << 5) | cppVar_95062;
	cppVar_95063 = (cppVar_95063 & cppMask_un_8_);
	BIT_VEC cppVar_95064 = (cppVar_95063 >> 7) & cppMask_un_1_;
	bool cppVar_95066 = (cppVar_95064 == 0);
	if (cppVar_95066) {
	BIT_VEC cppVar_95067 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_95068 = (cppVar_95067 << 3) | 3;
	cppVar_95068 = (cppVar_95068 & cppMask_un_5_);
	BIT_VEC cppVar_95069 = (0 << 5) | cppVar_95068;
	cppVar_95069 = (cppVar_95069 & cppMask_un_8_);
	BIT_VEC cppVar_95070;
	BIT_VEC cppVar_95071 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_95072 = (cppVar_95071 << 3) | 3;
	cppVar_95072 = (cppVar_95072 & cppMask_un_5_);
	BIT_VEC cppVar_95073 = (0 << 5) | cppVar_95072;
	cppVar_95073 = (cppVar_95073 & cppMask_un_8_);
	BIT_VEC cppVar_95074 = (cppVar_95073 >> 7) & cppMask_un_1_;
	bool cppVar_95076 = (cppVar_95074 == 0);
	if (cppVar_95076) {
	BIT_VEC cppVar_95077 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_95078 = (cppVar_95077 << 3) | 3;
	cppVar_95078 = (cppVar_95078 & cppMask_un_5_);
	BIT_VEC cppVar_95079 = (0 << 5) | cppVar_95078;
	cppVar_95079 = (cppVar_95079 & cppMask_un_8_);
	BIT_VEC cppVar_95080 = IRAM.rd(cppVar_95079);
	cppVar_95070 = cppVar_95080;
	} else {
	BIT_VEC cppVar_95081;
	BIT_VEC cppVar_95082 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_95083 = (cppVar_95082 << 3) | 3;
	cppVar_95083 = (cppVar_95083 & cppMask_un_5_);
	BIT_VEC cppVar_95084 = (0 << 5) | cppVar_95083;
	cppVar_95084 = (cppVar_95084 & cppMask_un_8_);
	bool cppVar_95086 = (cppVar_95084 == 128);
	if (cppVar_95086) {
	cppVar_95081 = P0;
	} else {
	BIT_VEC cppVar_95087;
	BIT_VEC cppVar_95088 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_95089 = (cppVar_95088 << 3) | 3;
	cppVar_95089 = (cppVar_95089 & cppMask_un_5_);
	BIT_VEC cppVar_95090 = (0 << 5) | cppVar_95089;
	cppVar_95090 = (cppVar_95090 & cppMask_un_8_);
	bool cppVar_95092 = (cppVar_95090 == 129);
	if (cppVar_95092) {
	cppVar_95087 = SP;
	} else {
	BIT_VEC cppVar_95093;
	BIT_VEC cppVar_95094 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_95095 = (cppVar_95094 << 3) | 3;
	cppVar_95095 = (cppVar_95095 & cppMask_un_5_);
	BIT_VEC cppVar_95096 = (0 << 5) | cppVar_95095;
	cppVar_95096 = (cppVar_95096 & cppMask_un_8_);
	bool cppVar_95098 = (cppVar_95096 == 130);
	if (cppVar_95098) {
	cppVar_95093 = DPL;
	} else {
	BIT_VEC cppVar_95099;
	BIT_VEC cppVar_95100 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_95101 = (cppVar_95100 << 3) | 3;
	cppVar_95101 = (cppVar_95101 & cppMask_un_5_);
	BIT_VEC cppVar_95102 = (0 << 5) | cppVar_95101;
	cppVar_95102 = (cppVar_95102 & cppMask_un_8_);
	bool cppVar_95104 = (cppVar_95102 == 131);
	if (cppVar_95104) {
	cppVar_95099 = DPH;
	} else {
	BIT_VEC cppVar_95105;
	BIT_VEC cppVar_95106 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_95107 = (cppVar_95106 << 3) | 3;
	cppVar_95107 = (cppVar_95107 & cppMask_un_5_);
	BIT_VEC cppVar_95108 = (0 << 5) | cppVar_95107;
	cppVar_95108 = (cppVar_95108 & cppMask_un_8_);
	bool cppVar_95110 = (cppVar_95108 == 135);
	if (cppVar_95110) {
	cppVar_95105 = PCON;
	} else {
	BIT_VEC cppVar_95111;
	BIT_VEC cppVar_95112 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_95113 = (cppVar_95112 << 3) | 3;
	cppVar_95113 = (cppVar_95113 & cppMask_un_5_);
	BIT_VEC cppVar_95114 = (0 << 5) | cppVar_95113;
	cppVar_95114 = (cppVar_95114 & cppMask_un_8_);
	bool cppVar_95116 = (cppVar_95114 == 136);
	if (cppVar_95116) {
	cppVar_95111 = TCON;
	} else {
	BIT_VEC cppVar_95117;
	BIT_VEC cppVar_95118 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_95119 = (cppVar_95118 << 3) | 3;
	cppVar_95119 = (cppVar_95119 & cppMask_un_5_);
	BIT_VEC cppVar_95120 = (0 << 5) | cppVar_95119;
	cppVar_95120 = (cppVar_95120 & cppMask_un_8_);
	bool cppVar_95122 = (cppVar_95120 == 137);
	if (cppVar_95122) {
	cppVar_95117 = TMOD;
	} else {
	BIT_VEC cppVar_95123;
	BIT_VEC cppVar_95124 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_95125 = (cppVar_95124 << 3) | 3;
	cppVar_95125 = (cppVar_95125 & cppMask_un_5_);
	BIT_VEC cppVar_95126 = (0 << 5) | cppVar_95125;
	cppVar_95126 = (cppVar_95126 & cppMask_un_8_);
	bool cppVar_95128 = (cppVar_95126 == 138);
	if (cppVar_95128) {
	cppVar_95123 = TL0;
	} else {
	BIT_VEC cppVar_95129;
	BIT_VEC cppVar_95130 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_95131 = (cppVar_95130 << 3) | 3;
	cppVar_95131 = (cppVar_95131 & cppMask_un_5_);
	BIT_VEC cppVar_95132 = (0 << 5) | cppVar_95131;
	cppVar_95132 = (cppVar_95132 & cppMask_un_8_);
	bool cppVar_95134 = (cppVar_95132 == 140);
	if (cppVar_95134) {
	cppVar_95129 = TH0;
	} else {
	BIT_VEC cppVar_95135;
	BIT_VEC cppVar_95136 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_95137 = (cppVar_95136 << 3) | 3;
	cppVar_95137 = (cppVar_95137 & cppMask_un_5_);
	BIT_VEC cppVar_95138 = (0 << 5) | cppVar_95137;
	cppVar_95138 = (cppVar_95138 & cppMask_un_8_);
	bool cppVar_95140 = (cppVar_95138 == 139);
	if (cppVar_95140) {
	cppVar_95135 = TL1;
	} else {
	BIT_VEC cppVar_95141;
	BIT_VEC cppVar_95142 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_95143 = (cppVar_95142 << 3) | 3;
	cppVar_95143 = (cppVar_95143 & cppMask_un_5_);
	BIT_VEC cppVar_95144 = (0 << 5) | cppVar_95143;
	cppVar_95144 = (cppVar_95144 & cppMask_un_8_);
	bool cppVar_95146 = (cppVar_95144 == 141);
	if (cppVar_95146) {
	cppVar_95141 = TH1;
	} else {
	BIT_VEC cppVar_95147;
	BIT_VEC cppVar_95148 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_95149 = (cppVar_95148 << 3) | 3;
	cppVar_95149 = (cppVar_95149 & cppMask_un_5_);
	BIT_VEC cppVar_95150 = (0 << 5) | cppVar_95149;
	cppVar_95150 = (cppVar_95150 & cppMask_un_8_);
	bool cppVar_95152 = (cppVar_95150 == 144);
	if (cppVar_95152) {
	cppVar_95147 = P1;
	} else {
	BIT_VEC cppVar_95153;
	BIT_VEC cppVar_95154 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_95155 = (cppVar_95154 << 3) | 3;
	cppVar_95155 = (cppVar_95155 & cppMask_un_5_);
	BIT_VEC cppVar_95156 = (0 << 5) | cppVar_95155;
	cppVar_95156 = (cppVar_95156 & cppMask_un_8_);
	bool cppVar_95158 = (cppVar_95156 == 152);
	if (cppVar_95158) {
	cppVar_95153 = SCON;
	} else {
	BIT_VEC cppVar_95159;
	BIT_VEC cppVar_95160 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_95161 = (cppVar_95160 << 3) | 3;
	cppVar_95161 = (cppVar_95161 & cppMask_un_5_);
	BIT_VEC cppVar_95162 = (0 << 5) | cppVar_95161;
	cppVar_95162 = (cppVar_95162 & cppMask_un_8_);
	bool cppVar_95164 = (cppVar_95162 == 153);
	if (cppVar_95164) {
	cppVar_95159 = SBUF;
	} else {
	BIT_VEC cppVar_95165;
	BIT_VEC cppVar_95166 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_95167 = (cppVar_95166 << 3) | 3;
	cppVar_95167 = (cppVar_95167 & cppMask_un_5_);
	BIT_VEC cppVar_95168 = (0 << 5) | cppVar_95167;
	cppVar_95168 = (cppVar_95168 & cppMask_un_8_);
	bool cppVar_95170 = (cppVar_95168 == 160);
	if (cppVar_95170) {
	cppVar_95165 = P2;
	} else {
	BIT_VEC cppVar_95171;
	BIT_VEC cppVar_95172 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_95173 = (cppVar_95172 << 3) | 3;
	cppVar_95173 = (cppVar_95173 & cppMask_un_5_);
	BIT_VEC cppVar_95174 = (0 << 5) | cppVar_95173;
	cppVar_95174 = (cppVar_95174 & cppMask_un_8_);
	bool cppVar_95176 = (cppVar_95174 == 168);
	if (cppVar_95176) {
	cppVar_95171 = IE;
	} else {
	BIT_VEC cppVar_95177;
	BIT_VEC cppVar_95178 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_95179 = (cppVar_95178 << 3) | 3;
	cppVar_95179 = (cppVar_95179 & cppMask_un_5_);
	BIT_VEC cppVar_95180 = (0 << 5) | cppVar_95179;
	cppVar_95180 = (cppVar_95180 & cppMask_un_8_);
	bool cppVar_95182 = (cppVar_95180 == 176);
	if (cppVar_95182) {
	cppVar_95177 = P3;
	} else {
	BIT_VEC cppVar_95183;
	BIT_VEC cppVar_95184 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_95185 = (cppVar_95184 << 3) | 3;
	cppVar_95185 = (cppVar_95185 & cppMask_un_5_);
	BIT_VEC cppVar_95186 = (0 << 5) | cppVar_95185;
	cppVar_95186 = (cppVar_95186 & cppMask_un_8_);
	bool cppVar_95188 = (cppVar_95186 == 184);
	if (cppVar_95188) {
	cppVar_95183 = IP;
	} else {
	BIT_VEC cppVar_95189;
	BIT_VEC cppVar_95190 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_95191 = (cppVar_95190 << 3) | 3;
	cppVar_95191 = (cppVar_95191 & cppMask_un_5_);
	BIT_VEC cppVar_95192 = (0 << 5) | cppVar_95191;
	cppVar_95192 = (cppVar_95192 & cppMask_un_8_);
	bool cppVar_95194 = (cppVar_95192 == 208);
	if (cppVar_95194) {
	cppVar_95189 = PSW;
	} else {
	BIT_VEC cppVar_95195;
	BIT_VEC cppVar_95196 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_95197 = (cppVar_95196 << 3) | 3;
	cppVar_95197 = (cppVar_95197 & cppMask_un_5_);
	BIT_VEC cppVar_95198 = (0 << 5) | cppVar_95197;
	cppVar_95198 = (cppVar_95198 & cppMask_un_8_);
	bool cppVar_95200 = (cppVar_95198 == 224);
	if (cppVar_95200) {
	cppVar_95195 = ACC;
	} else {
	BIT_VEC cppVar_95201;
	BIT_VEC cppVar_95202 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_95203 = (cppVar_95202 << 3) | 3;
	cppVar_95203 = (cppVar_95203 & cppMask_un_5_);
	BIT_VEC cppVar_95204 = (0 << 5) | cppVar_95203;
	cppVar_95204 = (cppVar_95204 & cppMask_un_8_);
	bool cppVar_95206 = (cppVar_95204 == 240);
	if (cppVar_95206) {
	cppVar_95201 = B;
	} else {
	cppVar_95201 = 0;
	}
	cppVar_95195 = cppVar_95201;
	}
	cppVar_95189 = cppVar_95195;
	}
	cppVar_95183 = cppVar_95189;
	}
	cppVar_95177 = cppVar_95183;
	}
	cppVar_95171 = cppVar_95177;
	}
	cppVar_95165 = cppVar_95171;
	}
	cppVar_95159 = cppVar_95165;
	}
	cppVar_95153 = cppVar_95159;
	}
	cppVar_95147 = cppVar_95153;
	}
	cppVar_95141 = cppVar_95147;
	}
	cppVar_95135 = cppVar_95141;
	}
	cppVar_95129 = cppVar_95135;
	}
	cppVar_95123 = cppVar_95129;
	}
	cppVar_95117 = cppVar_95123;
	}
	cppVar_95111 = cppVar_95117;
	}
	cppVar_95105 = cppVar_95111;
	}
	cppVar_95099 = cppVar_95105;
	}
	cppVar_95093 = cppVar_95099;
	}
	cppVar_95087 = cppVar_95093;
	}
	cppVar_95081 = cppVar_95087;
	}
	cppVar_95070 = cppVar_95081;
	}
	BIT_VEC cppVar_95209 = cppVar_95070 + 1;
	cppVar_95209 = (cppVar_95209 & cppMask_un_8_);
	type_mem cppVar_95210 = IRAM;
	cppVar_95210.wr(cppVar_95069, cppVar_95209);
	cppVar_95058 = cppVar_95210;
	} else {
	cppVar_95058 = IRAM;
	}
	cppVar_95054 = cppVar_95058;
	} else {
	type_mem cppVar_95211;
	BIT_VEC cppVar_95212 = ROM.rd(PC);
	bool cppVar_95214 = (cppVar_95212 == 10);
	if (cppVar_95214) {
	type_mem cppVar_95215;
	BIT_VEC cppVar_95217 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_95219 = (cppVar_95217 << 3) | 2;
	cppVar_95219 = (cppVar_95219 & cppMask_un_5_);
	BIT_VEC cppVar_95220 = (0 << 5) | cppVar_95219;
	cppVar_95220 = (cppVar_95220 & cppMask_un_8_);
	BIT_VEC cppVar_95221 = (cppVar_95220 >> 7) & cppMask_un_1_;
	bool cppVar_95223 = (cppVar_95221 == 0);
	if (cppVar_95223) {
	BIT_VEC cppVar_95224 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_95225 = (cppVar_95224 << 3) | 2;
	cppVar_95225 = (cppVar_95225 & cppMask_un_5_);
	BIT_VEC cppVar_95226 = (0 << 5) | cppVar_95225;
	cppVar_95226 = (cppVar_95226 & cppMask_un_8_);
	BIT_VEC cppVar_95227;
	BIT_VEC cppVar_95228 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_95229 = (cppVar_95228 << 3) | 2;
	cppVar_95229 = (cppVar_95229 & cppMask_un_5_);
	BIT_VEC cppVar_95230 = (0 << 5) | cppVar_95229;
	cppVar_95230 = (cppVar_95230 & cppMask_un_8_);
	BIT_VEC cppVar_95231 = (cppVar_95230 >> 7) & cppMask_un_1_;
	bool cppVar_95233 = (cppVar_95231 == 0);
	if (cppVar_95233) {
	BIT_VEC cppVar_95234 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_95235 = (cppVar_95234 << 3) | 2;
	cppVar_95235 = (cppVar_95235 & cppMask_un_5_);
	BIT_VEC cppVar_95236 = (0 << 5) | cppVar_95235;
	cppVar_95236 = (cppVar_95236 & cppMask_un_8_);
	BIT_VEC cppVar_95237 = IRAM.rd(cppVar_95236);
	cppVar_95227 = cppVar_95237;
	} else {
	BIT_VEC cppVar_95238;
	BIT_VEC cppVar_95239 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_95240 = (cppVar_95239 << 3) | 2;
	cppVar_95240 = (cppVar_95240 & cppMask_un_5_);
	BIT_VEC cppVar_95241 = (0 << 5) | cppVar_95240;
	cppVar_95241 = (cppVar_95241 & cppMask_un_8_);
	bool cppVar_95243 = (cppVar_95241 == 128);
	if (cppVar_95243) {
	cppVar_95238 = P0;
	} else {
	BIT_VEC cppVar_95244;
	BIT_VEC cppVar_95245 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_95246 = (cppVar_95245 << 3) | 2;
	cppVar_95246 = (cppVar_95246 & cppMask_un_5_);
	BIT_VEC cppVar_95247 = (0 << 5) | cppVar_95246;
	cppVar_95247 = (cppVar_95247 & cppMask_un_8_);
	bool cppVar_95249 = (cppVar_95247 == 129);
	if (cppVar_95249) {
	cppVar_95244 = SP;
	} else {
	BIT_VEC cppVar_95250;
	BIT_VEC cppVar_95251 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_95252 = (cppVar_95251 << 3) | 2;
	cppVar_95252 = (cppVar_95252 & cppMask_un_5_);
	BIT_VEC cppVar_95253 = (0 << 5) | cppVar_95252;
	cppVar_95253 = (cppVar_95253 & cppMask_un_8_);
	bool cppVar_95255 = (cppVar_95253 == 130);
	if (cppVar_95255) {
	cppVar_95250 = DPL;
	} else {
	BIT_VEC cppVar_95256;
	BIT_VEC cppVar_95257 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_95258 = (cppVar_95257 << 3) | 2;
	cppVar_95258 = (cppVar_95258 & cppMask_un_5_);
	BIT_VEC cppVar_95259 = (0 << 5) | cppVar_95258;
	cppVar_95259 = (cppVar_95259 & cppMask_un_8_);
	bool cppVar_95261 = (cppVar_95259 == 131);
	if (cppVar_95261) {
	cppVar_95256 = DPH;
	} else {
	BIT_VEC cppVar_95262;
	BIT_VEC cppVar_95263 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_95264 = (cppVar_95263 << 3) | 2;
	cppVar_95264 = (cppVar_95264 & cppMask_un_5_);
	BIT_VEC cppVar_95265 = (0 << 5) | cppVar_95264;
	cppVar_95265 = (cppVar_95265 & cppMask_un_8_);
	bool cppVar_95267 = (cppVar_95265 == 135);
	if (cppVar_95267) {
	cppVar_95262 = PCON;
	} else {
	BIT_VEC cppVar_95268;
	BIT_VEC cppVar_95269 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_95270 = (cppVar_95269 << 3) | 2;
	cppVar_95270 = (cppVar_95270 & cppMask_un_5_);
	BIT_VEC cppVar_95271 = (0 << 5) | cppVar_95270;
	cppVar_95271 = (cppVar_95271 & cppMask_un_8_);
	bool cppVar_95273 = (cppVar_95271 == 136);
	if (cppVar_95273) {
	cppVar_95268 = TCON;
	} else {
	BIT_VEC cppVar_95274;
	BIT_VEC cppVar_95275 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_95276 = (cppVar_95275 << 3) | 2;
	cppVar_95276 = (cppVar_95276 & cppMask_un_5_);
	BIT_VEC cppVar_95277 = (0 << 5) | cppVar_95276;
	cppVar_95277 = (cppVar_95277 & cppMask_un_8_);
	bool cppVar_95279 = (cppVar_95277 == 137);
	if (cppVar_95279) {
	cppVar_95274 = TMOD;
	} else {
	BIT_VEC cppVar_95280;
	BIT_VEC cppVar_95281 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_95282 = (cppVar_95281 << 3) | 2;
	cppVar_95282 = (cppVar_95282 & cppMask_un_5_);
	BIT_VEC cppVar_95283 = (0 << 5) | cppVar_95282;
	cppVar_95283 = (cppVar_95283 & cppMask_un_8_);
	bool cppVar_95285 = (cppVar_95283 == 138);
	if (cppVar_95285) {
	cppVar_95280 = TL0;
	} else {
	BIT_VEC cppVar_95286;
	BIT_VEC cppVar_95287 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_95288 = (cppVar_95287 << 3) | 2;
	cppVar_95288 = (cppVar_95288 & cppMask_un_5_);
	BIT_VEC cppVar_95289 = (0 << 5) | cppVar_95288;
	cppVar_95289 = (cppVar_95289 & cppMask_un_8_);
	bool cppVar_95291 = (cppVar_95289 == 140);
	if (cppVar_95291) {
	cppVar_95286 = TH0;
	} else {
	BIT_VEC cppVar_95292;
	BIT_VEC cppVar_95293 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_95294 = (cppVar_95293 << 3) | 2;
	cppVar_95294 = (cppVar_95294 & cppMask_un_5_);
	BIT_VEC cppVar_95295 = (0 << 5) | cppVar_95294;
	cppVar_95295 = (cppVar_95295 & cppMask_un_8_);
	bool cppVar_95297 = (cppVar_95295 == 139);
	if (cppVar_95297) {
	cppVar_95292 = TL1;
	} else {
	BIT_VEC cppVar_95298;
	BIT_VEC cppVar_95299 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_95300 = (cppVar_95299 << 3) | 2;
	cppVar_95300 = (cppVar_95300 & cppMask_un_5_);
	BIT_VEC cppVar_95301 = (0 << 5) | cppVar_95300;
	cppVar_95301 = (cppVar_95301 & cppMask_un_8_);
	bool cppVar_95303 = (cppVar_95301 == 141);
	if (cppVar_95303) {
	cppVar_95298 = TH1;
	} else {
	BIT_VEC cppVar_95304;
	BIT_VEC cppVar_95305 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_95306 = (cppVar_95305 << 3) | 2;
	cppVar_95306 = (cppVar_95306 & cppMask_un_5_);
	BIT_VEC cppVar_95307 = (0 << 5) | cppVar_95306;
	cppVar_95307 = (cppVar_95307 & cppMask_un_8_);
	bool cppVar_95309 = (cppVar_95307 == 144);
	if (cppVar_95309) {
	cppVar_95304 = P1;
	} else {
	BIT_VEC cppVar_95310;
	BIT_VEC cppVar_95311 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_95312 = (cppVar_95311 << 3) | 2;
	cppVar_95312 = (cppVar_95312 & cppMask_un_5_);
	BIT_VEC cppVar_95313 = (0 << 5) | cppVar_95312;
	cppVar_95313 = (cppVar_95313 & cppMask_un_8_);
	bool cppVar_95315 = (cppVar_95313 == 152);
	if (cppVar_95315) {
	cppVar_95310 = SCON;
	} else {
	BIT_VEC cppVar_95316;
	BIT_VEC cppVar_95317 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_95318 = (cppVar_95317 << 3) | 2;
	cppVar_95318 = (cppVar_95318 & cppMask_un_5_);
	BIT_VEC cppVar_95319 = (0 << 5) | cppVar_95318;
	cppVar_95319 = (cppVar_95319 & cppMask_un_8_);
	bool cppVar_95321 = (cppVar_95319 == 153);
	if (cppVar_95321) {
	cppVar_95316 = SBUF;
	} else {
	BIT_VEC cppVar_95322;
	BIT_VEC cppVar_95323 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_95324 = (cppVar_95323 << 3) | 2;
	cppVar_95324 = (cppVar_95324 & cppMask_un_5_);
	BIT_VEC cppVar_95325 = (0 << 5) | cppVar_95324;
	cppVar_95325 = (cppVar_95325 & cppMask_un_8_);
	bool cppVar_95327 = (cppVar_95325 == 160);
	if (cppVar_95327) {
	cppVar_95322 = P2;
	} else {
	BIT_VEC cppVar_95328;
	BIT_VEC cppVar_95329 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_95330 = (cppVar_95329 << 3) | 2;
	cppVar_95330 = (cppVar_95330 & cppMask_un_5_);
	BIT_VEC cppVar_95331 = (0 << 5) | cppVar_95330;
	cppVar_95331 = (cppVar_95331 & cppMask_un_8_);
	bool cppVar_95333 = (cppVar_95331 == 168);
	if (cppVar_95333) {
	cppVar_95328 = IE;
	} else {
	BIT_VEC cppVar_95334;
	BIT_VEC cppVar_95335 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_95336 = (cppVar_95335 << 3) | 2;
	cppVar_95336 = (cppVar_95336 & cppMask_un_5_);
	BIT_VEC cppVar_95337 = (0 << 5) | cppVar_95336;
	cppVar_95337 = (cppVar_95337 & cppMask_un_8_);
	bool cppVar_95339 = (cppVar_95337 == 176);
	if (cppVar_95339) {
	cppVar_95334 = P3;
	} else {
	BIT_VEC cppVar_95340;
	BIT_VEC cppVar_95341 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_95342 = (cppVar_95341 << 3) | 2;
	cppVar_95342 = (cppVar_95342 & cppMask_un_5_);
	BIT_VEC cppVar_95343 = (0 << 5) | cppVar_95342;
	cppVar_95343 = (cppVar_95343 & cppMask_un_8_);
	bool cppVar_95345 = (cppVar_95343 == 184);
	if (cppVar_95345) {
	cppVar_95340 = IP;
	} else {
	BIT_VEC cppVar_95346;
	BIT_VEC cppVar_95347 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_95348 = (cppVar_95347 << 3) | 2;
	cppVar_95348 = (cppVar_95348 & cppMask_un_5_);
	BIT_VEC cppVar_95349 = (0 << 5) | cppVar_95348;
	cppVar_95349 = (cppVar_95349 & cppMask_un_8_);
	bool cppVar_95351 = (cppVar_95349 == 208);
	if (cppVar_95351) {
	cppVar_95346 = PSW;
	} else {
	BIT_VEC cppVar_95352;
	BIT_VEC cppVar_95353 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_95354 = (cppVar_95353 << 3) | 2;
	cppVar_95354 = (cppVar_95354 & cppMask_un_5_);
	BIT_VEC cppVar_95355 = (0 << 5) | cppVar_95354;
	cppVar_95355 = (cppVar_95355 & cppMask_un_8_);
	bool cppVar_95357 = (cppVar_95355 == 224);
	if (cppVar_95357) {
	cppVar_95352 = ACC;
	} else {
	BIT_VEC cppVar_95358;
	BIT_VEC cppVar_95359 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_95360 = (cppVar_95359 << 3) | 2;
	cppVar_95360 = (cppVar_95360 & cppMask_un_5_);
	BIT_VEC cppVar_95361 = (0 << 5) | cppVar_95360;
	cppVar_95361 = (cppVar_95361 & cppMask_un_8_);
	bool cppVar_95363 = (cppVar_95361 == 240);
	if (cppVar_95363) {
	cppVar_95358 = B;
	} else {
	cppVar_95358 = 0;
	}
	cppVar_95352 = cppVar_95358;
	}
	cppVar_95346 = cppVar_95352;
	}
	cppVar_95340 = cppVar_95346;
	}
	cppVar_95334 = cppVar_95340;
	}
	cppVar_95328 = cppVar_95334;
	}
	cppVar_95322 = cppVar_95328;
	}
	cppVar_95316 = cppVar_95322;
	}
	cppVar_95310 = cppVar_95316;
	}
	cppVar_95304 = cppVar_95310;
	}
	cppVar_95298 = cppVar_95304;
	}
	cppVar_95292 = cppVar_95298;
	}
	cppVar_95286 = cppVar_95292;
	}
	cppVar_95280 = cppVar_95286;
	}
	cppVar_95274 = cppVar_95280;
	}
	cppVar_95268 = cppVar_95274;
	}
	cppVar_95262 = cppVar_95268;
	}
	cppVar_95256 = cppVar_95262;
	}
	cppVar_95250 = cppVar_95256;
	}
	cppVar_95244 = cppVar_95250;
	}
	cppVar_95238 = cppVar_95244;
	}
	cppVar_95227 = cppVar_95238;
	}
	BIT_VEC cppVar_95366 = cppVar_95227 + 1;
	cppVar_95366 = (cppVar_95366 & cppMask_un_8_);
	type_mem cppVar_95367 = IRAM;
	cppVar_95367.wr(cppVar_95226, cppVar_95366);
	cppVar_95215 = cppVar_95367;
	} else {
	cppVar_95215 = IRAM;
	}
	cppVar_95211 = cppVar_95215;
	} else {
	type_mem cppVar_95368;
	BIT_VEC cppVar_95369 = ROM.rd(PC);
	bool cppVar_95371 = (cppVar_95369 == 9);
	if (cppVar_95371) {
	type_mem cppVar_95372;
	BIT_VEC cppVar_95374 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_95376 = (cppVar_95374 << 3) | 1;
	cppVar_95376 = (cppVar_95376 & cppMask_un_5_);
	BIT_VEC cppVar_95377 = (0 << 5) | cppVar_95376;
	cppVar_95377 = (cppVar_95377 & cppMask_un_8_);
	BIT_VEC cppVar_95378 = (cppVar_95377 >> 7) & cppMask_un_1_;
	bool cppVar_95380 = (cppVar_95378 == 0);
	if (cppVar_95380) {
	BIT_VEC cppVar_95381 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_95382 = (cppVar_95381 << 3) | 1;
	cppVar_95382 = (cppVar_95382 & cppMask_un_5_);
	BIT_VEC cppVar_95383 = (0 << 5) | cppVar_95382;
	cppVar_95383 = (cppVar_95383 & cppMask_un_8_);
	BIT_VEC cppVar_95384;
	BIT_VEC cppVar_95385 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_95386 = (cppVar_95385 << 3) | 1;
	cppVar_95386 = (cppVar_95386 & cppMask_un_5_);
	BIT_VEC cppVar_95387 = (0 << 5) | cppVar_95386;
	cppVar_95387 = (cppVar_95387 & cppMask_un_8_);
	BIT_VEC cppVar_95388 = (cppVar_95387 >> 7) & cppMask_un_1_;
	bool cppVar_95390 = (cppVar_95388 == 0);
	if (cppVar_95390) {
	BIT_VEC cppVar_95391 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_95392 = (cppVar_95391 << 3) | 1;
	cppVar_95392 = (cppVar_95392 & cppMask_un_5_);
	BIT_VEC cppVar_95393 = (0 << 5) | cppVar_95392;
	cppVar_95393 = (cppVar_95393 & cppMask_un_8_);
	BIT_VEC cppVar_95394 = IRAM.rd(cppVar_95393);
	cppVar_95384 = cppVar_95394;
	} else {
	BIT_VEC cppVar_95395;
	BIT_VEC cppVar_95396 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_95397 = (cppVar_95396 << 3) | 1;
	cppVar_95397 = (cppVar_95397 & cppMask_un_5_);
	BIT_VEC cppVar_95398 = (0 << 5) | cppVar_95397;
	cppVar_95398 = (cppVar_95398 & cppMask_un_8_);
	bool cppVar_95400 = (cppVar_95398 == 128);
	if (cppVar_95400) {
	cppVar_95395 = P0;
	} else {
	BIT_VEC cppVar_95401;
	BIT_VEC cppVar_95402 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_95403 = (cppVar_95402 << 3) | 1;
	cppVar_95403 = (cppVar_95403 & cppMask_un_5_);
	BIT_VEC cppVar_95404 = (0 << 5) | cppVar_95403;
	cppVar_95404 = (cppVar_95404 & cppMask_un_8_);
	bool cppVar_95406 = (cppVar_95404 == 129);
	if (cppVar_95406) {
	cppVar_95401 = SP;
	} else {
	BIT_VEC cppVar_95407;
	BIT_VEC cppVar_95408 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_95409 = (cppVar_95408 << 3) | 1;
	cppVar_95409 = (cppVar_95409 & cppMask_un_5_);
	BIT_VEC cppVar_95410 = (0 << 5) | cppVar_95409;
	cppVar_95410 = (cppVar_95410 & cppMask_un_8_);
	bool cppVar_95412 = (cppVar_95410 == 130);
	if (cppVar_95412) {
	cppVar_95407 = DPL;
	} else {
	BIT_VEC cppVar_95413;
	BIT_VEC cppVar_95414 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_95415 = (cppVar_95414 << 3) | 1;
	cppVar_95415 = (cppVar_95415 & cppMask_un_5_);
	BIT_VEC cppVar_95416 = (0 << 5) | cppVar_95415;
	cppVar_95416 = (cppVar_95416 & cppMask_un_8_);
	bool cppVar_95418 = (cppVar_95416 == 131);
	if (cppVar_95418) {
	cppVar_95413 = DPH;
	} else {
	BIT_VEC cppVar_95419;
	BIT_VEC cppVar_95420 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_95421 = (cppVar_95420 << 3) | 1;
	cppVar_95421 = (cppVar_95421 & cppMask_un_5_);
	BIT_VEC cppVar_95422 = (0 << 5) | cppVar_95421;
	cppVar_95422 = (cppVar_95422 & cppMask_un_8_);
	bool cppVar_95424 = (cppVar_95422 == 135);
	if (cppVar_95424) {
	cppVar_95419 = PCON;
	} else {
	BIT_VEC cppVar_95425;
	BIT_VEC cppVar_95426 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_95427 = (cppVar_95426 << 3) | 1;
	cppVar_95427 = (cppVar_95427 & cppMask_un_5_);
	BIT_VEC cppVar_95428 = (0 << 5) | cppVar_95427;
	cppVar_95428 = (cppVar_95428 & cppMask_un_8_);
	bool cppVar_95430 = (cppVar_95428 == 136);
	if (cppVar_95430) {
	cppVar_95425 = TCON;
	} else {
	BIT_VEC cppVar_95431;
	BIT_VEC cppVar_95432 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_95433 = (cppVar_95432 << 3) | 1;
	cppVar_95433 = (cppVar_95433 & cppMask_un_5_);
	BIT_VEC cppVar_95434 = (0 << 5) | cppVar_95433;
	cppVar_95434 = (cppVar_95434 & cppMask_un_8_);
	bool cppVar_95436 = (cppVar_95434 == 137);
	if (cppVar_95436) {
	cppVar_95431 = TMOD;
	} else {
	BIT_VEC cppVar_95437;
	BIT_VEC cppVar_95438 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_95439 = (cppVar_95438 << 3) | 1;
	cppVar_95439 = (cppVar_95439 & cppMask_un_5_);
	BIT_VEC cppVar_95440 = (0 << 5) | cppVar_95439;
	cppVar_95440 = (cppVar_95440 & cppMask_un_8_);
	bool cppVar_95442 = (cppVar_95440 == 138);
	if (cppVar_95442) {
	cppVar_95437 = TL0;
	} else {
	BIT_VEC cppVar_95443;
	BIT_VEC cppVar_95444 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_95445 = (cppVar_95444 << 3) | 1;
	cppVar_95445 = (cppVar_95445 & cppMask_un_5_);
	BIT_VEC cppVar_95446 = (0 << 5) | cppVar_95445;
	cppVar_95446 = (cppVar_95446 & cppMask_un_8_);
	bool cppVar_95448 = (cppVar_95446 == 140);
	if (cppVar_95448) {
	cppVar_95443 = TH0;
	} else {
	BIT_VEC cppVar_95449;
	BIT_VEC cppVar_95450 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_95451 = (cppVar_95450 << 3) | 1;
	cppVar_95451 = (cppVar_95451 & cppMask_un_5_);
	BIT_VEC cppVar_95452 = (0 << 5) | cppVar_95451;
	cppVar_95452 = (cppVar_95452 & cppMask_un_8_);
	bool cppVar_95454 = (cppVar_95452 == 139);
	if (cppVar_95454) {
	cppVar_95449 = TL1;
	} else {
	BIT_VEC cppVar_95455;
	BIT_VEC cppVar_95456 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_95457 = (cppVar_95456 << 3) | 1;
	cppVar_95457 = (cppVar_95457 & cppMask_un_5_);
	BIT_VEC cppVar_95458 = (0 << 5) | cppVar_95457;
	cppVar_95458 = (cppVar_95458 & cppMask_un_8_);
	bool cppVar_95460 = (cppVar_95458 == 141);
	if (cppVar_95460) {
	cppVar_95455 = TH1;
	} else {
	BIT_VEC cppVar_95461;
	BIT_VEC cppVar_95462 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_95463 = (cppVar_95462 << 3) | 1;
	cppVar_95463 = (cppVar_95463 & cppMask_un_5_);
	BIT_VEC cppVar_95464 = (0 << 5) | cppVar_95463;
	cppVar_95464 = (cppVar_95464 & cppMask_un_8_);
	bool cppVar_95466 = (cppVar_95464 == 144);
	if (cppVar_95466) {
	cppVar_95461 = P1;
	} else {
	BIT_VEC cppVar_95467;
	BIT_VEC cppVar_95468 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_95469 = (cppVar_95468 << 3) | 1;
	cppVar_95469 = (cppVar_95469 & cppMask_un_5_);
	BIT_VEC cppVar_95470 = (0 << 5) | cppVar_95469;
	cppVar_95470 = (cppVar_95470 & cppMask_un_8_);
	bool cppVar_95472 = (cppVar_95470 == 152);
	if (cppVar_95472) {
	cppVar_95467 = SCON;
	} else {
	BIT_VEC cppVar_95473;
	BIT_VEC cppVar_95474 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_95475 = (cppVar_95474 << 3) | 1;
	cppVar_95475 = (cppVar_95475 & cppMask_un_5_);
	BIT_VEC cppVar_95476 = (0 << 5) | cppVar_95475;
	cppVar_95476 = (cppVar_95476 & cppMask_un_8_);
	bool cppVar_95478 = (cppVar_95476 == 153);
	if (cppVar_95478) {
	cppVar_95473 = SBUF;
	} else {
	BIT_VEC cppVar_95479;
	BIT_VEC cppVar_95480 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_95481 = (cppVar_95480 << 3) | 1;
	cppVar_95481 = (cppVar_95481 & cppMask_un_5_);
	BIT_VEC cppVar_95482 = (0 << 5) | cppVar_95481;
	cppVar_95482 = (cppVar_95482 & cppMask_un_8_);
	bool cppVar_95484 = (cppVar_95482 == 160);
	if (cppVar_95484) {
	cppVar_95479 = P2;
	} else {
	BIT_VEC cppVar_95485;
	BIT_VEC cppVar_95486 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_95487 = (cppVar_95486 << 3) | 1;
	cppVar_95487 = (cppVar_95487 & cppMask_un_5_);
	BIT_VEC cppVar_95488 = (0 << 5) | cppVar_95487;
	cppVar_95488 = (cppVar_95488 & cppMask_un_8_);
	bool cppVar_95490 = (cppVar_95488 == 168);
	if (cppVar_95490) {
	cppVar_95485 = IE;
	} else {
	BIT_VEC cppVar_95491;
	BIT_VEC cppVar_95492 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_95493 = (cppVar_95492 << 3) | 1;
	cppVar_95493 = (cppVar_95493 & cppMask_un_5_);
	BIT_VEC cppVar_95494 = (0 << 5) | cppVar_95493;
	cppVar_95494 = (cppVar_95494 & cppMask_un_8_);
	bool cppVar_95496 = (cppVar_95494 == 176);
	if (cppVar_95496) {
	cppVar_95491 = P3;
	} else {
	BIT_VEC cppVar_95497;
	BIT_VEC cppVar_95498 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_95499 = (cppVar_95498 << 3) | 1;
	cppVar_95499 = (cppVar_95499 & cppMask_un_5_);
	BIT_VEC cppVar_95500 = (0 << 5) | cppVar_95499;
	cppVar_95500 = (cppVar_95500 & cppMask_un_8_);
	bool cppVar_95502 = (cppVar_95500 == 184);
	if (cppVar_95502) {
	cppVar_95497 = IP;
	} else {
	BIT_VEC cppVar_95503;
	BIT_VEC cppVar_95504 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_95505 = (cppVar_95504 << 3) | 1;
	cppVar_95505 = (cppVar_95505 & cppMask_un_5_);
	BIT_VEC cppVar_95506 = (0 << 5) | cppVar_95505;
	cppVar_95506 = (cppVar_95506 & cppMask_un_8_);
	bool cppVar_95508 = (cppVar_95506 == 208);
	if (cppVar_95508) {
	cppVar_95503 = PSW;
	} else {
	BIT_VEC cppVar_95509;
	BIT_VEC cppVar_95510 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_95511 = (cppVar_95510 << 3) | 1;
	cppVar_95511 = (cppVar_95511 & cppMask_un_5_);
	BIT_VEC cppVar_95512 = (0 << 5) | cppVar_95511;
	cppVar_95512 = (cppVar_95512 & cppMask_un_8_);
	bool cppVar_95514 = (cppVar_95512 == 224);
	if (cppVar_95514) {
	cppVar_95509 = ACC;
	} else {
	BIT_VEC cppVar_95515;
	BIT_VEC cppVar_95516 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_95517 = (cppVar_95516 << 3) | 1;
	cppVar_95517 = (cppVar_95517 & cppMask_un_5_);
	BIT_VEC cppVar_95518 = (0 << 5) | cppVar_95517;
	cppVar_95518 = (cppVar_95518 & cppMask_un_8_);
	bool cppVar_95520 = (cppVar_95518 == 240);
	if (cppVar_95520) {
	cppVar_95515 = B;
	} else {
	cppVar_95515 = 0;
	}
	cppVar_95509 = cppVar_95515;
	}
	cppVar_95503 = cppVar_95509;
	}
	cppVar_95497 = cppVar_95503;
	}
	cppVar_95491 = cppVar_95497;
	}
	cppVar_95485 = cppVar_95491;
	}
	cppVar_95479 = cppVar_95485;
	}
	cppVar_95473 = cppVar_95479;
	}
	cppVar_95467 = cppVar_95473;
	}
	cppVar_95461 = cppVar_95467;
	}
	cppVar_95455 = cppVar_95461;
	}
	cppVar_95449 = cppVar_95455;
	}
	cppVar_95443 = cppVar_95449;
	}
	cppVar_95437 = cppVar_95443;
	}
	cppVar_95431 = cppVar_95437;
	}
	cppVar_95425 = cppVar_95431;
	}
	cppVar_95419 = cppVar_95425;
	}
	cppVar_95413 = cppVar_95419;
	}
	cppVar_95407 = cppVar_95413;
	}
	cppVar_95401 = cppVar_95407;
	}
	cppVar_95395 = cppVar_95401;
	}
	cppVar_95384 = cppVar_95395;
	}
	BIT_VEC cppVar_95523 = cppVar_95384 + 1;
	cppVar_95523 = (cppVar_95523 & cppMask_un_8_);
	type_mem cppVar_95524 = IRAM;
	cppVar_95524.wr(cppVar_95383, cppVar_95523);
	cppVar_95372 = cppVar_95524;
	} else {
	cppVar_95372 = IRAM;
	}
	cppVar_95368 = cppVar_95372;
	} else {
	type_mem cppVar_95525;
	BIT_VEC cppVar_95526 = ROM.rd(PC);
	bool cppVar_95528 = (cppVar_95526 == 8);
	if (cppVar_95528) {
	type_mem cppVar_95529;
	BIT_VEC cppVar_95531 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_95533 = (cppVar_95531 << 3) | 0;
	cppVar_95533 = (cppVar_95533 & cppMask_un_5_);
	BIT_VEC cppVar_95534 = (0 << 5) | cppVar_95533;
	cppVar_95534 = (cppVar_95534 & cppMask_un_8_);
	BIT_VEC cppVar_95535 = (cppVar_95534 >> 7) & cppMask_un_1_;
	bool cppVar_95537 = (cppVar_95535 == 0);
	if (cppVar_95537) {
	BIT_VEC cppVar_95538 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_95539 = (cppVar_95538 << 3) | 0;
	cppVar_95539 = (cppVar_95539 & cppMask_un_5_);
	BIT_VEC cppVar_95540 = (0 << 5) | cppVar_95539;
	cppVar_95540 = (cppVar_95540 & cppMask_un_8_);
	BIT_VEC cppVar_95541;
	BIT_VEC cppVar_95542 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_95543 = (cppVar_95542 << 3) | 0;
	cppVar_95543 = (cppVar_95543 & cppMask_un_5_);
	BIT_VEC cppVar_95544 = (0 << 5) | cppVar_95543;
	cppVar_95544 = (cppVar_95544 & cppMask_un_8_);
	BIT_VEC cppVar_95545 = (cppVar_95544 >> 7) & cppMask_un_1_;
	bool cppVar_95547 = (cppVar_95545 == 0);
	if (cppVar_95547) {
	BIT_VEC cppVar_95548 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_95549 = (cppVar_95548 << 3) | 0;
	cppVar_95549 = (cppVar_95549 & cppMask_un_5_);
	BIT_VEC cppVar_95550 = (0 << 5) | cppVar_95549;
	cppVar_95550 = (cppVar_95550 & cppMask_un_8_);
	BIT_VEC cppVar_95551 = IRAM.rd(cppVar_95550);
	cppVar_95541 = cppVar_95551;
	} else {
	BIT_VEC cppVar_95552;
	BIT_VEC cppVar_95553 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_95554 = (cppVar_95553 << 3) | 0;
	cppVar_95554 = (cppVar_95554 & cppMask_un_5_);
	BIT_VEC cppVar_95555 = (0 << 5) | cppVar_95554;
	cppVar_95555 = (cppVar_95555 & cppMask_un_8_);
	bool cppVar_95557 = (cppVar_95555 == 128);
	if (cppVar_95557) {
	cppVar_95552 = P0;
	} else {
	BIT_VEC cppVar_95558;
	BIT_VEC cppVar_95559 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_95560 = (cppVar_95559 << 3) | 0;
	cppVar_95560 = (cppVar_95560 & cppMask_un_5_);
	BIT_VEC cppVar_95561 = (0 << 5) | cppVar_95560;
	cppVar_95561 = (cppVar_95561 & cppMask_un_8_);
	bool cppVar_95563 = (cppVar_95561 == 129);
	if (cppVar_95563) {
	cppVar_95558 = SP;
	} else {
	BIT_VEC cppVar_95564;
	BIT_VEC cppVar_95565 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_95566 = (cppVar_95565 << 3) | 0;
	cppVar_95566 = (cppVar_95566 & cppMask_un_5_);
	BIT_VEC cppVar_95567 = (0 << 5) | cppVar_95566;
	cppVar_95567 = (cppVar_95567 & cppMask_un_8_);
	bool cppVar_95569 = (cppVar_95567 == 130);
	if (cppVar_95569) {
	cppVar_95564 = DPL;
	} else {
	BIT_VEC cppVar_95570;
	BIT_VEC cppVar_95571 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_95572 = (cppVar_95571 << 3) | 0;
	cppVar_95572 = (cppVar_95572 & cppMask_un_5_);
	BIT_VEC cppVar_95573 = (0 << 5) | cppVar_95572;
	cppVar_95573 = (cppVar_95573 & cppMask_un_8_);
	bool cppVar_95575 = (cppVar_95573 == 131);
	if (cppVar_95575) {
	cppVar_95570 = DPH;
	} else {
	BIT_VEC cppVar_95576;
	BIT_VEC cppVar_95577 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_95578 = (cppVar_95577 << 3) | 0;
	cppVar_95578 = (cppVar_95578 & cppMask_un_5_);
	BIT_VEC cppVar_95579 = (0 << 5) | cppVar_95578;
	cppVar_95579 = (cppVar_95579 & cppMask_un_8_);
	bool cppVar_95581 = (cppVar_95579 == 135);
	if (cppVar_95581) {
	cppVar_95576 = PCON;
	} else {
	BIT_VEC cppVar_95582;
	BIT_VEC cppVar_95583 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_95584 = (cppVar_95583 << 3) | 0;
	cppVar_95584 = (cppVar_95584 & cppMask_un_5_);
	BIT_VEC cppVar_95585 = (0 << 5) | cppVar_95584;
	cppVar_95585 = (cppVar_95585 & cppMask_un_8_);
	bool cppVar_95587 = (cppVar_95585 == 136);
	if (cppVar_95587) {
	cppVar_95582 = TCON;
	} else {
	BIT_VEC cppVar_95588;
	BIT_VEC cppVar_95589 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_95590 = (cppVar_95589 << 3) | 0;
	cppVar_95590 = (cppVar_95590 & cppMask_un_5_);
	BIT_VEC cppVar_95591 = (0 << 5) | cppVar_95590;
	cppVar_95591 = (cppVar_95591 & cppMask_un_8_);
	bool cppVar_95593 = (cppVar_95591 == 137);
	if (cppVar_95593) {
	cppVar_95588 = TMOD;
	} else {
	BIT_VEC cppVar_95594;
	BIT_VEC cppVar_95595 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_95596 = (cppVar_95595 << 3) | 0;
	cppVar_95596 = (cppVar_95596 & cppMask_un_5_);
	BIT_VEC cppVar_95597 = (0 << 5) | cppVar_95596;
	cppVar_95597 = (cppVar_95597 & cppMask_un_8_);
	bool cppVar_95599 = (cppVar_95597 == 138);
	if (cppVar_95599) {
	cppVar_95594 = TL0;
	} else {
	BIT_VEC cppVar_95600;
	BIT_VEC cppVar_95601 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_95602 = (cppVar_95601 << 3) | 0;
	cppVar_95602 = (cppVar_95602 & cppMask_un_5_);
	BIT_VEC cppVar_95603 = (0 << 5) | cppVar_95602;
	cppVar_95603 = (cppVar_95603 & cppMask_un_8_);
	bool cppVar_95605 = (cppVar_95603 == 140);
	if (cppVar_95605) {
	cppVar_95600 = TH0;
	} else {
	BIT_VEC cppVar_95606;
	BIT_VEC cppVar_95607 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_95608 = (cppVar_95607 << 3) | 0;
	cppVar_95608 = (cppVar_95608 & cppMask_un_5_);
	BIT_VEC cppVar_95609 = (0 << 5) | cppVar_95608;
	cppVar_95609 = (cppVar_95609 & cppMask_un_8_);
	bool cppVar_95611 = (cppVar_95609 == 139);
	if (cppVar_95611) {
	cppVar_95606 = TL1;
	} else {
	BIT_VEC cppVar_95612;
	BIT_VEC cppVar_95613 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_95614 = (cppVar_95613 << 3) | 0;
	cppVar_95614 = (cppVar_95614 & cppMask_un_5_);
	BIT_VEC cppVar_95615 = (0 << 5) | cppVar_95614;
	cppVar_95615 = (cppVar_95615 & cppMask_un_8_);
	bool cppVar_95617 = (cppVar_95615 == 141);
	if (cppVar_95617) {
	cppVar_95612 = TH1;
	} else {
	BIT_VEC cppVar_95618;
	BIT_VEC cppVar_95619 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_95620 = (cppVar_95619 << 3) | 0;
	cppVar_95620 = (cppVar_95620 & cppMask_un_5_);
	BIT_VEC cppVar_95621 = (0 << 5) | cppVar_95620;
	cppVar_95621 = (cppVar_95621 & cppMask_un_8_);
	bool cppVar_95623 = (cppVar_95621 == 144);
	if (cppVar_95623) {
	cppVar_95618 = P1;
	} else {
	BIT_VEC cppVar_95624;
	BIT_VEC cppVar_95625 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_95626 = (cppVar_95625 << 3) | 0;
	cppVar_95626 = (cppVar_95626 & cppMask_un_5_);
	BIT_VEC cppVar_95627 = (0 << 5) | cppVar_95626;
	cppVar_95627 = (cppVar_95627 & cppMask_un_8_);
	bool cppVar_95629 = (cppVar_95627 == 152);
	if (cppVar_95629) {
	cppVar_95624 = SCON;
	} else {
	BIT_VEC cppVar_95630;
	BIT_VEC cppVar_95631 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_95632 = (cppVar_95631 << 3) | 0;
	cppVar_95632 = (cppVar_95632 & cppMask_un_5_);
	BIT_VEC cppVar_95633 = (0 << 5) | cppVar_95632;
	cppVar_95633 = (cppVar_95633 & cppMask_un_8_);
	bool cppVar_95635 = (cppVar_95633 == 153);
	if (cppVar_95635) {
	cppVar_95630 = SBUF;
	} else {
	BIT_VEC cppVar_95636;
	BIT_VEC cppVar_95637 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_95638 = (cppVar_95637 << 3) | 0;
	cppVar_95638 = (cppVar_95638 & cppMask_un_5_);
	BIT_VEC cppVar_95639 = (0 << 5) | cppVar_95638;
	cppVar_95639 = (cppVar_95639 & cppMask_un_8_);
	bool cppVar_95641 = (cppVar_95639 == 160);
	if (cppVar_95641) {
	cppVar_95636 = P2;
	} else {
	BIT_VEC cppVar_95642;
	BIT_VEC cppVar_95643 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_95644 = (cppVar_95643 << 3) | 0;
	cppVar_95644 = (cppVar_95644 & cppMask_un_5_);
	BIT_VEC cppVar_95645 = (0 << 5) | cppVar_95644;
	cppVar_95645 = (cppVar_95645 & cppMask_un_8_);
	bool cppVar_95647 = (cppVar_95645 == 168);
	if (cppVar_95647) {
	cppVar_95642 = IE;
	} else {
	BIT_VEC cppVar_95648;
	BIT_VEC cppVar_95649 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_95650 = (cppVar_95649 << 3) | 0;
	cppVar_95650 = (cppVar_95650 & cppMask_un_5_);
	BIT_VEC cppVar_95651 = (0 << 5) | cppVar_95650;
	cppVar_95651 = (cppVar_95651 & cppMask_un_8_);
	bool cppVar_95653 = (cppVar_95651 == 176);
	if (cppVar_95653) {
	cppVar_95648 = P3;
	} else {
	BIT_VEC cppVar_95654;
	BIT_VEC cppVar_95655 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_95656 = (cppVar_95655 << 3) | 0;
	cppVar_95656 = (cppVar_95656 & cppMask_un_5_);
	BIT_VEC cppVar_95657 = (0 << 5) | cppVar_95656;
	cppVar_95657 = (cppVar_95657 & cppMask_un_8_);
	bool cppVar_95659 = (cppVar_95657 == 184);
	if (cppVar_95659) {
	cppVar_95654 = IP;
	} else {
	BIT_VEC cppVar_95660;
	BIT_VEC cppVar_95661 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_95662 = (cppVar_95661 << 3) | 0;
	cppVar_95662 = (cppVar_95662 & cppMask_un_5_);
	BIT_VEC cppVar_95663 = (0 << 5) | cppVar_95662;
	cppVar_95663 = (cppVar_95663 & cppMask_un_8_);
	bool cppVar_95665 = (cppVar_95663 == 208);
	if (cppVar_95665) {
	cppVar_95660 = PSW;
	} else {
	BIT_VEC cppVar_95666;
	BIT_VEC cppVar_95667 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_95668 = (cppVar_95667 << 3) | 0;
	cppVar_95668 = (cppVar_95668 & cppMask_un_5_);
	BIT_VEC cppVar_95669 = (0 << 5) | cppVar_95668;
	cppVar_95669 = (cppVar_95669 & cppMask_un_8_);
	bool cppVar_95671 = (cppVar_95669 == 224);
	if (cppVar_95671) {
	cppVar_95666 = ACC;
	} else {
	BIT_VEC cppVar_95672;
	BIT_VEC cppVar_95673 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_95674 = (cppVar_95673 << 3) | 0;
	cppVar_95674 = (cppVar_95674 & cppMask_un_5_);
	BIT_VEC cppVar_95675 = (0 << 5) | cppVar_95674;
	cppVar_95675 = (cppVar_95675 & cppMask_un_8_);
	bool cppVar_95677 = (cppVar_95675 == 240);
	if (cppVar_95677) {
	cppVar_95672 = B;
	} else {
	cppVar_95672 = 0;
	}
	cppVar_95666 = cppVar_95672;
	}
	cppVar_95660 = cppVar_95666;
	}
	cppVar_95654 = cppVar_95660;
	}
	cppVar_95648 = cppVar_95654;
	}
	cppVar_95642 = cppVar_95648;
	}
	cppVar_95636 = cppVar_95642;
	}
	cppVar_95630 = cppVar_95636;
	}
	cppVar_95624 = cppVar_95630;
	}
	cppVar_95618 = cppVar_95624;
	}
	cppVar_95612 = cppVar_95618;
	}
	cppVar_95606 = cppVar_95612;
	}
	cppVar_95600 = cppVar_95606;
	}
	cppVar_95594 = cppVar_95600;
	}
	cppVar_95588 = cppVar_95594;
	}
	cppVar_95582 = cppVar_95588;
	}
	cppVar_95576 = cppVar_95582;
	}
	cppVar_95570 = cppVar_95576;
	}
	cppVar_95564 = cppVar_95570;
	}
	cppVar_95558 = cppVar_95564;
	}
	cppVar_95552 = cppVar_95558;
	}
	cppVar_95541 = cppVar_95552;
	}
	BIT_VEC cppVar_95680 = cppVar_95541 + 1;
	cppVar_95680 = (cppVar_95680 & cppMask_un_8_);
	type_mem cppVar_95681 = IRAM;
	cppVar_95681.wr(cppVar_95540, cppVar_95680);
	cppVar_95529 = cppVar_95681;
	} else {
	cppVar_95529 = IRAM;
	}
	cppVar_95525 = cppVar_95529;
	} else {
	type_mem cppVar_95682;
	BIT_VEC cppVar_95683 = ROM.rd(PC);
	bool cppVar_95685 = (cppVar_95683 == 7);
	if (cppVar_95685) {
	BIT_VEC cppVar_95687 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_95689 = (cppVar_95687 << 3) | 1;
	cppVar_95689 = (cppVar_95689 & cppMask_un_5_);
	BIT_VEC cppVar_95690 = (0 << 5) | cppVar_95689;
	cppVar_95690 = (cppVar_95690 & cppMask_un_8_);
	BIT_VEC cppVar_95691 = IRAM.rd(cppVar_95690);
	BIT_VEC cppVar_95692 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_95693 = (cppVar_95692 << 3) | 1;
	cppVar_95693 = (cppVar_95693 & cppMask_un_5_);
	BIT_VEC cppVar_95694 = (0 << 5) | cppVar_95693;
	cppVar_95694 = (cppVar_95694 & cppMask_un_8_);
	BIT_VEC cppVar_95695 = IRAM.rd(cppVar_95694);
	BIT_VEC cppVar_95696 = IRAM.rd(cppVar_95695);
	BIT_VEC cppVar_95698 = cppVar_95696 + 1;
	cppVar_95698 = (cppVar_95698 & cppMask_un_8_);
	type_mem cppVar_95699 = IRAM;
	cppVar_95699.wr(cppVar_95691, cppVar_95698);
	cppVar_95682 = cppVar_95699;
	} else {
	type_mem cppVar_95700;
	BIT_VEC cppVar_95701 = ROM.rd(PC);
	bool cppVar_95703 = (cppVar_95701 == 6);
	if (cppVar_95703) {
	BIT_VEC cppVar_95705 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_95707 = (cppVar_95705 << 3) | 0;
	cppVar_95707 = (cppVar_95707 & cppMask_un_5_);
	BIT_VEC cppVar_95708 = (0 << 5) | cppVar_95707;
	cppVar_95708 = (cppVar_95708 & cppMask_un_8_);
	BIT_VEC cppVar_95709 = IRAM.rd(cppVar_95708);
	BIT_VEC cppVar_95710 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_95711 = (cppVar_95710 << 3) | 0;
	cppVar_95711 = (cppVar_95711 & cppMask_un_5_);
	BIT_VEC cppVar_95712 = (0 << 5) | cppVar_95711;
	cppVar_95712 = (cppVar_95712 & cppMask_un_8_);
	BIT_VEC cppVar_95713 = IRAM.rd(cppVar_95712);
	BIT_VEC cppVar_95714 = IRAM.rd(cppVar_95713);
	BIT_VEC cppVar_95716 = cppVar_95714 + 1;
	cppVar_95716 = (cppVar_95716 & cppMask_un_8_);
	type_mem cppVar_95717 = IRAM;
	cppVar_95717.wr(cppVar_95709, cppVar_95716);
	cppVar_95700 = cppVar_95717;
	} else {
	type_mem cppVar_95718;
	BIT_VEC cppVar_95719 = ROM.rd(PC);
	bool cppVar_95721 = (cppVar_95719 == 5);
	if (cppVar_95721) {
	type_mem cppVar_95722;
	BIT_VEC cppVar_95724 = PC + 1;
	cppVar_95724 = (cppVar_95724 & cppMask_un_16_);
	BIT_VEC cppVar_95725 = ROM.rd(cppVar_95724);
	BIT_VEC cppVar_95726 = (cppVar_95725 >> 7) & cppMask_un_1_;
	bool cppVar_95728 = (cppVar_95726 == 0);
	if (cppVar_95728) {
	BIT_VEC cppVar_95729 = PC + 1;
	cppVar_95729 = (cppVar_95729 & cppMask_un_16_);
	BIT_VEC cppVar_95730 = ROM.rd(cppVar_95729);
	BIT_VEC cppVar_95731;
	BIT_VEC cppVar_95732 = PC + 1;
	cppVar_95732 = (cppVar_95732 & cppMask_un_16_);
	BIT_VEC cppVar_95733 = ROM.rd(cppVar_95732);
	BIT_VEC cppVar_95734 = (cppVar_95733 >> 7) & cppMask_un_1_;
	bool cppVar_95736 = (cppVar_95734 == 0);
	if (cppVar_95736) {
	BIT_VEC cppVar_95737 = PC + 1;
	cppVar_95737 = (cppVar_95737 & cppMask_un_16_);
	BIT_VEC cppVar_95738 = ROM.rd(cppVar_95737);
	BIT_VEC cppVar_95739 = IRAM.rd(cppVar_95738);
	cppVar_95731 = cppVar_95739;
	} else {
	BIT_VEC cppVar_95740;
	BIT_VEC cppVar_95741 = PC + 1;
	cppVar_95741 = (cppVar_95741 & cppMask_un_16_);
	BIT_VEC cppVar_95742 = ROM.rd(cppVar_95741);
	bool cppVar_95744 = (cppVar_95742 == 128);
	if (cppVar_95744) {
	cppVar_95740 = P0;
	} else {
	BIT_VEC cppVar_95745;
	BIT_VEC cppVar_95746 = PC + 1;
	cppVar_95746 = (cppVar_95746 & cppMask_un_16_);
	BIT_VEC cppVar_95747 = ROM.rd(cppVar_95746);
	bool cppVar_95749 = (cppVar_95747 == 129);
	if (cppVar_95749) {
	cppVar_95745 = SP;
	} else {
	BIT_VEC cppVar_95750;
	BIT_VEC cppVar_95751 = PC + 1;
	cppVar_95751 = (cppVar_95751 & cppMask_un_16_);
	BIT_VEC cppVar_95752 = ROM.rd(cppVar_95751);
	bool cppVar_95754 = (cppVar_95752 == 130);
	if (cppVar_95754) {
	cppVar_95750 = DPL;
	} else {
	BIT_VEC cppVar_95755;
	BIT_VEC cppVar_95756 = PC + 1;
	cppVar_95756 = (cppVar_95756 & cppMask_un_16_);
	BIT_VEC cppVar_95757 = ROM.rd(cppVar_95756);
	bool cppVar_95759 = (cppVar_95757 == 131);
	if (cppVar_95759) {
	cppVar_95755 = DPH;
	} else {
	BIT_VEC cppVar_95760;
	BIT_VEC cppVar_95761 = PC + 1;
	cppVar_95761 = (cppVar_95761 & cppMask_un_16_);
	BIT_VEC cppVar_95762 = ROM.rd(cppVar_95761);
	bool cppVar_95764 = (cppVar_95762 == 135);
	if (cppVar_95764) {
	cppVar_95760 = PCON;
	} else {
	BIT_VEC cppVar_95765;
	BIT_VEC cppVar_95766 = PC + 1;
	cppVar_95766 = (cppVar_95766 & cppMask_un_16_);
	BIT_VEC cppVar_95767 = ROM.rd(cppVar_95766);
	bool cppVar_95769 = (cppVar_95767 == 136);
	if (cppVar_95769) {
	cppVar_95765 = TCON;
	} else {
	BIT_VEC cppVar_95770;
	BIT_VEC cppVar_95771 = PC + 1;
	cppVar_95771 = (cppVar_95771 & cppMask_un_16_);
	BIT_VEC cppVar_95772 = ROM.rd(cppVar_95771);
	bool cppVar_95774 = (cppVar_95772 == 137);
	if (cppVar_95774) {
	cppVar_95770 = TMOD;
	} else {
	BIT_VEC cppVar_95775;
	BIT_VEC cppVar_95776 = PC + 1;
	cppVar_95776 = (cppVar_95776 & cppMask_un_16_);
	BIT_VEC cppVar_95777 = ROM.rd(cppVar_95776);
	bool cppVar_95779 = (cppVar_95777 == 138);
	if (cppVar_95779) {
	cppVar_95775 = TL0;
	} else {
	BIT_VEC cppVar_95780;
	BIT_VEC cppVar_95781 = PC + 1;
	cppVar_95781 = (cppVar_95781 & cppMask_un_16_);
	BIT_VEC cppVar_95782 = ROM.rd(cppVar_95781);
	bool cppVar_95784 = (cppVar_95782 == 140);
	if (cppVar_95784) {
	cppVar_95780 = TH0;
	} else {
	BIT_VEC cppVar_95785;
	BIT_VEC cppVar_95786 = PC + 1;
	cppVar_95786 = (cppVar_95786 & cppMask_un_16_);
	BIT_VEC cppVar_95787 = ROM.rd(cppVar_95786);
	bool cppVar_95789 = (cppVar_95787 == 139);
	if (cppVar_95789) {
	cppVar_95785 = TL1;
	} else {
	BIT_VEC cppVar_95790;
	BIT_VEC cppVar_95791 = PC + 1;
	cppVar_95791 = (cppVar_95791 & cppMask_un_16_);
	BIT_VEC cppVar_95792 = ROM.rd(cppVar_95791);
	bool cppVar_95794 = (cppVar_95792 == 141);
	if (cppVar_95794) {
	cppVar_95790 = TH1;
	} else {
	BIT_VEC cppVar_95795;
	BIT_VEC cppVar_95796 = PC + 1;
	cppVar_95796 = (cppVar_95796 & cppMask_un_16_);
	BIT_VEC cppVar_95797 = ROM.rd(cppVar_95796);
	bool cppVar_95799 = (cppVar_95797 == 144);
	if (cppVar_95799) {
	cppVar_95795 = P1;
	} else {
	BIT_VEC cppVar_95800;
	BIT_VEC cppVar_95801 = PC + 1;
	cppVar_95801 = (cppVar_95801 & cppMask_un_16_);
	BIT_VEC cppVar_95802 = ROM.rd(cppVar_95801);
	bool cppVar_95804 = (cppVar_95802 == 152);
	if (cppVar_95804) {
	cppVar_95800 = SCON;
	} else {
	BIT_VEC cppVar_95805;
	BIT_VEC cppVar_95806 = PC + 1;
	cppVar_95806 = (cppVar_95806 & cppMask_un_16_);
	BIT_VEC cppVar_95807 = ROM.rd(cppVar_95806);
	bool cppVar_95809 = (cppVar_95807 == 153);
	if (cppVar_95809) {
	cppVar_95805 = SBUF;
	} else {
	BIT_VEC cppVar_95810;
	BIT_VEC cppVar_95811 = PC + 1;
	cppVar_95811 = (cppVar_95811 & cppMask_un_16_);
	BIT_VEC cppVar_95812 = ROM.rd(cppVar_95811);
	bool cppVar_95814 = (cppVar_95812 == 160);
	if (cppVar_95814) {
	cppVar_95810 = P2;
	} else {
	BIT_VEC cppVar_95815;
	BIT_VEC cppVar_95816 = PC + 1;
	cppVar_95816 = (cppVar_95816 & cppMask_un_16_);
	BIT_VEC cppVar_95817 = ROM.rd(cppVar_95816);
	bool cppVar_95819 = (cppVar_95817 == 168);
	if (cppVar_95819) {
	cppVar_95815 = IE;
	} else {
	BIT_VEC cppVar_95820;
	BIT_VEC cppVar_95821 = PC + 1;
	cppVar_95821 = (cppVar_95821 & cppMask_un_16_);
	BIT_VEC cppVar_95822 = ROM.rd(cppVar_95821);
	bool cppVar_95824 = (cppVar_95822 == 176);
	if (cppVar_95824) {
	cppVar_95820 = P3;
	} else {
	BIT_VEC cppVar_95825;
	BIT_VEC cppVar_95826 = PC + 1;
	cppVar_95826 = (cppVar_95826 & cppMask_un_16_);
	BIT_VEC cppVar_95827 = ROM.rd(cppVar_95826);
	bool cppVar_95829 = (cppVar_95827 == 184);
	if (cppVar_95829) {
	cppVar_95825 = IP;
	} else {
	BIT_VEC cppVar_95830;
	BIT_VEC cppVar_95831 = PC + 1;
	cppVar_95831 = (cppVar_95831 & cppMask_un_16_);
	BIT_VEC cppVar_95832 = ROM.rd(cppVar_95831);
	bool cppVar_95834 = (cppVar_95832 == 208);
	if (cppVar_95834) {
	cppVar_95830 = PSW;
	} else {
	BIT_VEC cppVar_95835;
	BIT_VEC cppVar_95836 = PC + 1;
	cppVar_95836 = (cppVar_95836 & cppMask_un_16_);
	BIT_VEC cppVar_95837 = ROM.rd(cppVar_95836);
	bool cppVar_95839 = (cppVar_95837 == 224);
	if (cppVar_95839) {
	cppVar_95835 = ACC;
	} else {
	BIT_VEC cppVar_95840;
	BIT_VEC cppVar_95841 = PC + 1;
	cppVar_95841 = (cppVar_95841 & cppMask_un_16_);
	BIT_VEC cppVar_95842 = ROM.rd(cppVar_95841);
	bool cppVar_95844 = (cppVar_95842 == 240);
	if (cppVar_95844) {
	cppVar_95840 = B;
	} else {
	cppVar_95840 = 0;
	}
	cppVar_95835 = cppVar_95840;
	}
	cppVar_95830 = cppVar_95835;
	}
	cppVar_95825 = cppVar_95830;
	}
	cppVar_95820 = cppVar_95825;
	}
	cppVar_95815 = cppVar_95820;
	}
	cppVar_95810 = cppVar_95815;
	}
	cppVar_95805 = cppVar_95810;
	}
	cppVar_95800 = cppVar_95805;
	}
	cppVar_95795 = cppVar_95800;
	}
	cppVar_95790 = cppVar_95795;
	}
	cppVar_95785 = cppVar_95790;
	}
	cppVar_95780 = cppVar_95785;
	}
	cppVar_95775 = cppVar_95780;
	}
	cppVar_95770 = cppVar_95775;
	}
	cppVar_95765 = cppVar_95770;
	}
	cppVar_95760 = cppVar_95765;
	}
	cppVar_95755 = cppVar_95760;
	}
	cppVar_95750 = cppVar_95755;
	}
	cppVar_95745 = cppVar_95750;
	}
	cppVar_95740 = cppVar_95745;
	}
	cppVar_95731 = cppVar_95740;
	}
	BIT_VEC cppVar_95847 = cppVar_95731 + 1;
	cppVar_95847 = (cppVar_95847 & cppMask_un_8_);
	type_mem cppVar_95848 = IRAM;
	cppVar_95848.wr(cppVar_95730, cppVar_95847);
	cppVar_95722 = cppVar_95848;
	} else {
	cppVar_95722 = IRAM;
	}
	cppVar_95718 = cppVar_95722;
	} else {
	cppVar_95718 = IRAM;
	}
	cppVar_95700 = cppVar_95718;
	}
	cppVar_95682 = cppVar_95700;
	}
	cppVar_95525 = cppVar_95682;
	}
	cppVar_95368 = cppVar_95525;
	}
	cppVar_95211 = cppVar_95368;
	}
	cppVar_95054 = cppVar_95211;
	}
	cppVar_94897 = cppVar_95054;
	}
	cppVar_94740 = cppVar_94897;
	}
	cppVar_94583 = cppVar_94740;
	}
	cppVar_94426 = cppVar_94583;
	}
	cppVar_93974 = cppVar_94426;
	}
	cppVar_93930 = cppVar_93974;
	}
	cppVar_93914 = cppVar_93930;
	}
	cppVar_93779 = cppVar_93914;
	}
	cppVar_93761 = cppVar_93779;
	}
	cppVar_93743 = cppVar_93761;
	}
	cppVar_93582 = cppVar_93743;
	}
	cppVar_93421 = cppVar_93582;
	}
	cppVar_93260 = cppVar_93421;
	}
	cppVar_93099 = cppVar_93260;
	}
	cppVar_92938 = cppVar_93099;
	}
	cppVar_92777 = cppVar_92938;
	}
	cppVar_92616 = cppVar_92777;
	}
	cppVar_92455 = cppVar_92616;
	}
	cppVar_92325 = cppVar_92455;
	}
	cppVar_92192 = cppVar_92325;
	}
	cppVar_92062 = cppVar_92192;
	}
	cppVar_91929 = cppVar_92062;
	}
	cppVar_91799 = cppVar_91929;
	}
	cppVar_91666 = cppVar_91799;
	}
	cppVar_91649 = cppVar_91666;
	}
	cppVar_91635 = cppVar_91649;
	}
	cppVar_91621 = cppVar_91635;
	}
	cppVar_91601 = cppVar_91621;
	}
	cppVar_91581 = cppVar_91601;
	}
	cppVar_91561 = cppVar_91581;
	}
	cppVar_91541 = cppVar_91561;
	}
	cppVar_91521 = cppVar_91541;
	}
	cppVar_91501 = cppVar_91521;
	}
	cppVar_91481 = cppVar_91501;
	}
	cppVar_91461 = cppVar_91481;
	}
	cppVar_91331 = cppVar_91461;
	}
	cppVar_91310 = cppVar_91331;
	}
	cppVar_91289 = cppVar_91310;
	}
	cppVar_91135 = cppVar_91289;
	}
	cppVar_90981 = cppVar_91135;
	}
	cppVar_90827 = cppVar_90981;
	}
	cppVar_90673 = cppVar_90827;
	}
	cppVar_90519 = cppVar_90673;
	}
	cppVar_90365 = cppVar_90519;
	}
	cppVar_90211 = cppVar_90365;
	}
	cppVar_90057 = cppVar_90211;
	}
	cppVar_89609 = cppVar_90057;
	}
	cppVar_89482 = cppVar_89609;
	}
	cppVar_89355 = cppVar_89482;
	}
	cppVar_89222 = cppVar_89355;
	}
	cppVar_89089 = cppVar_89222;
	}
	cppVar_88956 = cppVar_89089;
	}
	cppVar_88823 = cppVar_88956;
	}
	cppVar_88690 = cppVar_88823;
	}
	cppVar_88557 = cppVar_88690;
	}
	cppVar_88424 = cppVar_88557;
	}
	cppVar_88291 = cppVar_88424;
	}
	cppVar_87445 = cppVar_88291;
	}
	cppVar_87322 = cppVar_87445;
	}
	cppVar_87304 = cppVar_87322;
	}
	cppVar_87289 = cppVar_87304;
	}
	cppVar_87274 = cppVar_87289;
	}
	cppVar_87253 = cppVar_87274;
	}
	cppVar_87232 = cppVar_87253;
	}
	cppVar_87211 = cppVar_87232;
	}
	cppVar_87190 = cppVar_87211;
	}
	cppVar_87169 = cppVar_87190;
	}
	cppVar_87148 = cppVar_87169;
	}
	cppVar_87127 = cppVar_87148;
	}
	cppVar_87106 = cppVar_87127;
	}
	cppVar_87091 = cppVar_87106;
	}
	cppVar_86643 = cppVar_87091;
	}
	cppVar_86624 = cppVar_86643;
	}
	cppVar_86605 = cppVar_86624;
	}
	return cppVar_86605;
}

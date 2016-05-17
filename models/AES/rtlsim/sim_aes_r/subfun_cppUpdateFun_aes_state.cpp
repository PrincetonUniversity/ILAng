#include "common.hpp"
#include "model_aes_class.hpp"

BIT_VEC model_aes::cppUpdateFun_aes_state(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	BIT_VEC cppVar_711;
	bool cppVar_713 = (aes_state != 0);
	if (cppVar_713) {
	BIT_VEC cppVar_714;
	bool cppVar_716 = (aes_state == 3);
	bool cppVar_718 = (byte_cnt == 15);
	bool cppVar_719 = cppVar_716 && cppVar_718;
	if (cppVar_719) {
	BIT_VEC cppVar_720;
	BIT_VEC cppVar_722 = oped_byte_cnt + 16;
	cppVar_722 = (cppVar_722 & cppMask_un_16_);
	bool cppVar_723 = cppVar_722 < aes_len;
	if (cppVar_723) {
	cppVar_720 = 1;
	} else {
	cppVar_720 = 0;
	}
	cppVar_714 = cppVar_720;
	} else {
	BIT_VEC cppVar_726;
	bool cppVar_728 = (aes_state == 1);
	bool cppVar_730 = (byte_cnt == 15);
	bool cppVar_731 = cppVar_728 && cppVar_730;
	if (cppVar_731) {
	cppVar_726 = 2;
	} else {
	BIT_VEC cppVar_733;
	bool cppVar_735 = (aes_state == 2);
	bool cppVar_737 = (byte_cnt == 15);
	bool cppVar_738 = cppVar_735 && cppVar_737;
	bool cppVar_740 = (aes_state == 3);
	bool cppVar_742 = (byte_cnt == 14);
	bool cppVar_743 = cppVar_740 && cppVar_742;
	bool cppVar_745 = (aes_state == 2);
	bool cppVar_747 = (byte_cnt == 14);
	bool cppVar_748 = cppVar_745 && cppVar_747;
	bool cppVar_750 = (aes_state == 2);
	bool cppVar_752 = (byte_cnt == 13);
	bool cppVar_753 = cppVar_750 && cppVar_752;
	bool cppVar_755 = (aes_state == 3);
	bool cppVar_757 = (byte_cnt == 12);
	bool cppVar_758 = cppVar_755 && cppVar_757;
	bool cppVar_760 = (aes_state == 2);
	bool cppVar_762 = (byte_cnt == 12);
	bool cppVar_763 = cppVar_760 && cppVar_762;
	bool cppVar_765 = (aes_state == 2);
	bool cppVar_767 = (byte_cnt == 11);
	bool cppVar_768 = cppVar_765 && cppVar_767;
	bool cppVar_770 = (aes_state == 3);
	bool cppVar_772 = (byte_cnt == 10);
	bool cppVar_773 = cppVar_770 && cppVar_772;
	bool cppVar_775 = (aes_state == 2);
	bool cppVar_777 = (byte_cnt == 10);
	bool cppVar_778 = cppVar_775 && cppVar_777;
	bool cppVar_780 = (aes_state == 2);
	bool cppVar_782 = (byte_cnt == 9);
	bool cppVar_783 = cppVar_780 && cppVar_782;
	bool cppVar_785 = (aes_state == 3);
	bool cppVar_787 = (byte_cnt == 8);
	bool cppVar_788 = cppVar_785 && cppVar_787;
	bool cppVar_790 = (aes_state == 2);
	bool cppVar_792 = (byte_cnt == 8);
	bool cppVar_793 = cppVar_790 && cppVar_792;
	bool cppVar_795 = (aes_state == 2);
	bool cppVar_797 = (byte_cnt == 7);
	bool cppVar_798 = cppVar_795 && cppVar_797;
	bool cppVar_800 = (aes_state == 3);
	bool cppVar_802 = (byte_cnt == 6);
	bool cppVar_803 = cppVar_800 && cppVar_802;
	bool cppVar_805 = (aes_state == 2);
	bool cppVar_807 = (byte_cnt == 6);
	bool cppVar_808 = cppVar_805 && cppVar_807;
	bool cppVar_810 = (aes_state == 2);
	bool cppVar_812 = (byte_cnt == 5);
	bool cppVar_813 = cppVar_810 && cppVar_812;
	bool cppVar_815 = (aes_state == 2);
	bool cppVar_817 = (byte_cnt == 4);
	bool cppVar_818 = cppVar_815 && cppVar_817;
	bool cppVar_820 = (aes_state == 2);
	bool cppVar_822 = (byte_cnt == 3);
	bool cppVar_823 = cppVar_820 && cppVar_822;
	bool cppVar_825 = (aes_state == 2);
	bool cppVar_827 = (byte_cnt == 2);
	bool cppVar_828 = cppVar_825 && cppVar_827;
	bool cppVar_830 = (aes_state == 3);
	bool cppVar_832 = (byte_cnt == 1);
	bool cppVar_833 = cppVar_830 && cppVar_832;
	bool cppVar_835 = (aes_state == 2);
	bool cppVar_837 = (byte_cnt == 1);
	bool cppVar_838 = cppVar_835 && cppVar_837;
	bool cppVar_840 = (aes_state == 3);
	bool cppVar_842 = (byte_cnt == 0);
	bool cppVar_843 = cppVar_840 && cppVar_842;
	bool cppVar_845 = (aes_state == 2);
	bool cppVar_847 = (byte_cnt == 0);
	bool cppVar_848 = cppVar_845 && cppVar_847;
	bool cppVar_849 = cppVar_843 || cppVar_848;
	bool cppVar_850 = cppVar_838 || cppVar_849;
	bool cppVar_851 = cppVar_833 || cppVar_850;
	bool cppVar_852 = cppVar_828 || cppVar_851;
	bool cppVar_853 = cppVar_823 || cppVar_852;
	bool cppVar_854 = cppVar_818 || cppVar_853;
	bool cppVar_855 = cppVar_813 || cppVar_854;
	bool cppVar_856 = cppVar_808 || cppVar_855;
	bool cppVar_857 = cppVar_803 || cppVar_856;
	bool cppVar_858 = cppVar_798 || cppVar_857;
	bool cppVar_859 = cppVar_793 || cppVar_858;
	bool cppVar_860 = cppVar_788 || cppVar_859;
	bool cppVar_861 = cppVar_783 || cppVar_860;
	bool cppVar_862 = cppVar_778 || cppVar_861;
	bool cppVar_863 = cppVar_773 || cppVar_862;
	bool cppVar_864 = cppVar_768 || cppVar_863;
	bool cppVar_865 = cppVar_763 || cppVar_864;
	bool cppVar_866 = cppVar_758 || cppVar_865;
	bool cppVar_867 = cppVar_753 || cppVar_866;
	bool cppVar_868 = cppVar_748 || cppVar_867;
	bool cppVar_869 = cppVar_743 || cppVar_868;
	bool cppVar_870 = cppVar_738 || cppVar_869;
	if (cppVar_870) {
	cppVar_733 = 3;
	} else {
	BIT_VEC cppVar_872;
	bool cppVar_874 = (aes_state == 1);
	bool cppVar_876 = (byte_cnt == 2);
	bool cppVar_877 = cppVar_874 && cppVar_876;
	bool cppVar_879 = (aes_state == 1);
	bool cppVar_881 = (byte_cnt == 1);
	bool cppVar_882 = cppVar_879 && cppVar_881;
	bool cppVar_884 = (aes_state == 1);
	bool cppVar_886 = (byte_cnt == 0);
	bool cppVar_887 = cppVar_884 && cppVar_886;
	bool cppVar_888 = cppVar_882 || cppVar_887;
	bool cppVar_889 = cppVar_877 || cppVar_888;
	if (cppVar_889) {
	cppVar_872 = 1;
	} else {
	cppVar_872 = aes_state;
	}
	cppVar_733 = cppVar_872;
	}
	cppVar_726 = cppVar_733;
	}
	cppVar_714 = cppVar_726;
	}
	cppVar_711 = cppVar_714;
	} else {
	BIT_VEC cppVar_891;
	bool cppVar_893 = (aes_state == 0);
	bool cppVar_895 = (cmd == 2);
	bool cppVar_896 = cppVar_893 && cppVar_895;
	bool cppVar_898 = (cmdaddr == 65280);
	bool cppVar_899 = cppVar_896 && cppVar_898;
	if (cppVar_899) {
	BIT_VEC cppVar_900;
	bool cppVar_902 = (cmddata == 1);
	if (cppVar_902) {
	cppVar_900 = 1;
	} else {
	cppVar_900 = aes_state;
	}
	cppVar_891 = cppVar_900;
	} else {
	cppVar_891 = aes_state;
	}
	cppVar_711 = cppVar_891;
	}
	return cppVar_711;
}

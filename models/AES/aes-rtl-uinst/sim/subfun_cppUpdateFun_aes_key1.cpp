#include "common.hpp"
#include "model_aes_class.hpp"

BIT_VEC model_aes::cppUpdateFun_aes_key1(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	BIT_VEC cppVar_472;
	bool cppVar_474 = (aes_state == 0);
	bool cppVar_476 = (cmd == 2);
	bool cppVar_477 = cppVar_474 && cppVar_476;
	bool cppVar_479 = (cmdaddr == 65343);
	bool cppVar_480 = cppVar_477 && cppVar_479;
	if (cppVar_480) {
	BIT_VEC cppVar_481 = (aes_key1 >> 0) & cppMask_un_120_;
	BIT_VEC cppVar_482 = (cmddata << 120) | cppVar_481;
	cppVar_482 = (cppVar_482 & cppMask_un_128_);
	cppVar_472 = cppVar_482;
	} else {
	BIT_VEC cppVar_483;
	bool cppVar_485 = (aes_state == 0);
	bool cppVar_487 = (cmd == 2);
	bool cppVar_488 = cppVar_485 && cppVar_487;
	bool cppVar_490 = (cmdaddr == 65342);
	bool cppVar_491 = cppVar_488 && cppVar_490;
	if (cppVar_491) {
	BIT_VEC cppVar_492 = (aes_key1 >> 120) & cppMask_un_8_;
	BIT_VEC cppVar_493 = (cppVar_492 << 8) | cmddata;
	cppVar_493 = (cppVar_493 & cppMask_un_16_);
	BIT_VEC cppVar_494 = (aes_key1 >> 0) & cppMask_un_112_;
	BIT_VEC cppVar_495 = (cppVar_493 << 112) | cppVar_494;
	cppVar_495 = (cppVar_495 & cppMask_un_128_);
	cppVar_483 = cppVar_495;
	} else {
	BIT_VEC cppVar_496;
	bool cppVar_498 = (aes_state == 0);
	bool cppVar_500 = (cmd == 2);
	bool cppVar_501 = cppVar_498 && cppVar_500;
	bool cppVar_503 = (cmdaddr == 65341);
	bool cppVar_504 = cppVar_501 && cppVar_503;
	if (cppVar_504) {
	BIT_VEC cppVar_505 = (aes_key1 >> 112) & cppMask_un_16_;
	BIT_VEC cppVar_506 = (cppVar_505 << 8) | cmddata;
	cppVar_506 = (cppVar_506 & cppMask_un_24_);
	BIT_VEC cppVar_507 = (aes_key1 >> 0) & cppMask_un_104_;
	BIT_VEC cppVar_508 = (cppVar_506 << 104) | cppVar_507;
	cppVar_508 = (cppVar_508 & cppMask_un_128_);
	cppVar_496 = cppVar_508;
	} else {
	BIT_VEC cppVar_509;
	bool cppVar_511 = (aes_state == 0);
	bool cppVar_513 = (cmd == 2);
	bool cppVar_514 = cppVar_511 && cppVar_513;
	bool cppVar_516 = (cmdaddr == 65340);
	bool cppVar_517 = cppVar_514 && cppVar_516;
	if (cppVar_517) {
	BIT_VEC cppVar_518 = (aes_key1 >> 104) & cppMask_un_24_;
	BIT_VEC cppVar_519 = (cppVar_518 << 8) | cmddata;
	cppVar_519 = (cppVar_519 & cppMask_un_32_);
	BIT_VEC cppVar_520 = (aes_key1 >> 0) & cppMask_un_96_;
	BIT_VEC cppVar_521 = (cppVar_519 << 96) | cppVar_520;
	cppVar_521 = (cppVar_521 & cppMask_un_128_);
	cppVar_509 = cppVar_521;
	} else {
	BIT_VEC cppVar_522;
	bool cppVar_524 = (aes_state == 0);
	bool cppVar_526 = (cmd == 2);
	bool cppVar_527 = cppVar_524 && cppVar_526;
	bool cppVar_529 = (cmdaddr == 65339);
	bool cppVar_530 = cppVar_527 && cppVar_529;
	if (cppVar_530) {
	BIT_VEC cppVar_531 = (aes_key1 >> 96) & cppMask_un_32_;
	BIT_VEC cppVar_532 = (cppVar_531 << 8) | cmddata;
	cppVar_532 = (cppVar_532 & cppMask_un_40_);
	BIT_VEC cppVar_533 = (aes_key1 >> 0) & cppMask_un_88_;
	BIT_VEC cppVar_534 = (cppVar_532 << 88) | cppVar_533;
	cppVar_534 = (cppVar_534 & cppMask_un_128_);
	cppVar_522 = cppVar_534;
	} else {
	BIT_VEC cppVar_535;
	bool cppVar_537 = (aes_state == 0);
	bool cppVar_539 = (cmd == 2);
	bool cppVar_540 = cppVar_537 && cppVar_539;
	bool cppVar_542 = (cmdaddr == 65338);
	bool cppVar_543 = cppVar_540 && cppVar_542;
	if (cppVar_543) {
	BIT_VEC cppVar_544 = (aes_key1 >> 88) & cppMask_un_40_;
	BIT_VEC cppVar_545 = (cppVar_544 << 8) | cmddata;
	cppVar_545 = (cppVar_545 & cppMask_un_48_);
	BIT_VEC cppVar_546 = (aes_key1 >> 0) & cppMask_un_80_;
	BIT_VEC cppVar_547 = (cppVar_545 << 80) | cppVar_546;
	cppVar_547 = (cppVar_547 & cppMask_un_128_);
	cppVar_535 = cppVar_547;
	} else {
	BIT_VEC cppVar_548;
	bool cppVar_550 = (aes_state == 0);
	bool cppVar_552 = (cmd == 2);
	bool cppVar_553 = cppVar_550 && cppVar_552;
	bool cppVar_555 = (cmdaddr == 65337);
	bool cppVar_556 = cppVar_553 && cppVar_555;
	if (cppVar_556) {
	BIT_VEC cppVar_557 = (aes_key1 >> 80) & cppMask_un_48_;
	BIT_VEC cppVar_558 = (cppVar_557 << 8) | cmddata;
	cppVar_558 = (cppVar_558 & cppMask_un_56_);
	BIT_VEC cppVar_559 = (aes_key1 >> 0) & cppMask_un_72_;
	BIT_VEC cppVar_560 = (cppVar_558 << 72) | cppVar_559;
	cppVar_560 = (cppVar_560 & cppMask_un_128_);
	cppVar_548 = cppVar_560;
	} else {
	BIT_VEC cppVar_561;
	bool cppVar_563 = (aes_state == 0);
	bool cppVar_565 = (cmd == 2);
	bool cppVar_566 = cppVar_563 && cppVar_565;
	bool cppVar_568 = (cmdaddr == 65336);
	bool cppVar_569 = cppVar_566 && cppVar_568;
	if (cppVar_569) {
	BIT_VEC cppVar_570 = (aes_key1 >> 72) & cppMask_un_56_;
	BIT_VEC cppVar_571 = (cppVar_570 << 8) | cmddata;
	cppVar_571 = (cppVar_571 & cppMask_un_64_);
	BIT_VEC cppVar_572 = (aes_key1 >> 0) & cppMask_un_64_;
	BIT_VEC cppVar_573 = (cppVar_571 << 64) | cppVar_572;
	cppVar_573 = (cppVar_573 & cppMask_un_128_);
	cppVar_561 = cppVar_573;
	} else {
	BIT_VEC cppVar_574;
	bool cppVar_576 = (aes_state == 0);
	bool cppVar_578 = (cmd == 2);
	bool cppVar_579 = cppVar_576 && cppVar_578;
	bool cppVar_581 = (cmdaddr == 65335);
	bool cppVar_582 = cppVar_579 && cppVar_581;
	if (cppVar_582) {
	BIT_VEC cppVar_583 = (aes_key1 >> 64) & cppMask_un_64_;
	BIT_VEC cppVar_584 = (cppVar_583 << 8) | cmddata;
	cppVar_584 = (cppVar_584 & cppMask_un_72_);
	BIT_VEC cppVar_585 = (aes_key1 >> 0) & cppMask_un_56_;
	BIT_VEC cppVar_586 = (cppVar_584 << 56) | cppVar_585;
	cppVar_586 = (cppVar_586 & cppMask_un_128_);
	cppVar_574 = cppVar_586;
	} else {
	BIT_VEC cppVar_587;
	bool cppVar_589 = (aes_state == 0);
	bool cppVar_591 = (cmd == 2);
	bool cppVar_592 = cppVar_589 && cppVar_591;
	bool cppVar_594 = (cmdaddr == 65334);
	bool cppVar_595 = cppVar_592 && cppVar_594;
	if (cppVar_595) {
	BIT_VEC cppVar_596 = (aes_key1 >> 56) & cppMask_un_72_;
	BIT_VEC cppVar_597 = (cppVar_596 << 8) | cmddata;
	cppVar_597 = (cppVar_597 & cppMask_un_80_);
	BIT_VEC cppVar_598 = (aes_key1 >> 0) & cppMask_un_48_;
	BIT_VEC cppVar_599 = (cppVar_597 << 48) | cppVar_598;
	cppVar_599 = (cppVar_599 & cppMask_un_128_);
	cppVar_587 = cppVar_599;
	} else {
	BIT_VEC cppVar_600;
	bool cppVar_602 = (aes_state == 0);
	bool cppVar_604 = (cmd == 2);
	bool cppVar_605 = cppVar_602 && cppVar_604;
	bool cppVar_607 = (cmdaddr == 65333);
	bool cppVar_608 = cppVar_605 && cppVar_607;
	if (cppVar_608) {
	BIT_VEC cppVar_609 = (aes_key1 >> 48) & cppMask_un_80_;
	BIT_VEC cppVar_610 = (cppVar_609 << 8) | cmddata;
	cppVar_610 = (cppVar_610 & cppMask_un_88_);
	BIT_VEC cppVar_611 = (aes_key1 >> 0) & cppMask_un_40_;
	BIT_VEC cppVar_612 = (cppVar_610 << 40) | cppVar_611;
	cppVar_612 = (cppVar_612 & cppMask_un_128_);
	cppVar_600 = cppVar_612;
	} else {
	BIT_VEC cppVar_613;
	bool cppVar_615 = (aes_state == 0);
	bool cppVar_617 = (cmd == 2);
	bool cppVar_618 = cppVar_615 && cppVar_617;
	bool cppVar_620 = (cmdaddr == 65332);
	bool cppVar_621 = cppVar_618 && cppVar_620;
	if (cppVar_621) {
	BIT_VEC cppVar_622 = (aes_key1 >> 40) & cppMask_un_88_;
	BIT_VEC cppVar_623 = (cppVar_622 << 8) | cmddata;
	cppVar_623 = (cppVar_623 & cppMask_un_96_);
	BIT_VEC cppVar_624 = (aes_key1 >> 0) & cppMask_un_32_;
	BIT_VEC cppVar_625 = (cppVar_623 << 32) | cppVar_624;
	cppVar_625 = (cppVar_625 & cppMask_un_128_);
	cppVar_613 = cppVar_625;
	} else {
	BIT_VEC cppVar_626;
	bool cppVar_628 = (aes_state == 0);
	bool cppVar_630 = (cmd == 2);
	bool cppVar_631 = cppVar_628 && cppVar_630;
	bool cppVar_633 = (cmdaddr == 65331);
	bool cppVar_634 = cppVar_631 && cppVar_633;
	if (cppVar_634) {
	BIT_VEC cppVar_635 = (aes_key1 >> 32) & cppMask_un_96_;
	BIT_VEC cppVar_636 = (cppVar_635 << 8) | cmddata;
	cppVar_636 = (cppVar_636 & cppMask_un_104_);
	BIT_VEC cppVar_637 = (aes_key1 >> 0) & cppMask_un_24_;
	BIT_VEC cppVar_638 = (cppVar_636 << 24) | cppVar_637;
	cppVar_638 = (cppVar_638 & cppMask_un_128_);
	cppVar_626 = cppVar_638;
	} else {
	BIT_VEC cppVar_639;
	bool cppVar_641 = (aes_state == 0);
	bool cppVar_643 = (cmd == 2);
	bool cppVar_644 = cppVar_641 && cppVar_643;
	bool cppVar_646 = (cmdaddr == 65330);
	bool cppVar_647 = cppVar_644 && cppVar_646;
	if (cppVar_647) {
	BIT_VEC cppVar_648 = (aes_key1 >> 24) & cppMask_un_104_;
	BIT_VEC cppVar_649 = (cppVar_648 << 8) | cmddata;
	cppVar_649 = (cppVar_649 & cppMask_un_112_);
	BIT_VEC cppVar_650 = (aes_key1 >> 0) & cppMask_un_16_;
	BIT_VEC cppVar_651 = (cppVar_649 << 16) | cppVar_650;
	cppVar_651 = (cppVar_651 & cppMask_un_128_);
	cppVar_639 = cppVar_651;
	} else {
	BIT_VEC cppVar_652;
	bool cppVar_654 = (aes_state == 0);
	bool cppVar_656 = (cmd == 2);
	bool cppVar_657 = cppVar_654 && cppVar_656;
	bool cppVar_659 = (cmdaddr == 65329);
	bool cppVar_660 = cppVar_657 && cppVar_659;
	if (cppVar_660) {
	BIT_VEC cppVar_661 = (aes_key1 >> 16) & cppMask_un_112_;
	BIT_VEC cppVar_662 = (cppVar_661 << 8) | cmddata;
	cppVar_662 = (cppVar_662 & cppMask_un_120_);
	BIT_VEC cppVar_663 = (aes_key1 >> 0) & cppMask_un_8_;
	BIT_VEC cppVar_664 = (cppVar_662 << 8) | cppVar_663;
	cppVar_664 = (cppVar_664 & cppMask_un_128_);
	cppVar_652 = cppVar_664;
	} else {
	BIT_VEC cppVar_665;
	bool cppVar_667 = (aes_state == 0);
	bool cppVar_669 = (cmd == 2);
	bool cppVar_670 = cppVar_667 && cppVar_669;
	bool cppVar_672 = (cmdaddr == 65328);
	bool cppVar_673 = cppVar_670 && cppVar_672;
	if (cppVar_673) {
	BIT_VEC cppVar_674 = (aes_key1 >> 8) & cppMask_un_120_;
	BIT_VEC cppVar_675 = (cppVar_674 << 8) | cmddata;
	cppVar_675 = (cppVar_675 & cppMask_un_128_);
	cppVar_665 = cppVar_675;
	} else {
	cppVar_665 = aes_key1;
	}
	cppVar_652 = cppVar_665;
	}
	cppVar_639 = cppVar_652;
	}
	cppVar_626 = cppVar_639;
	}
	cppVar_613 = cppVar_626;
	}
	cppVar_600 = cppVar_613;
	}
	cppVar_587 = cppVar_600;
	}
	cppVar_574 = cppVar_587;
	}
	cppVar_561 = cppVar_574;
	}
	cppVar_548 = cppVar_561;
	}
	cppVar_535 = cppVar_548;
	}
	cppVar_522 = cppVar_535;
	}
	cppVar_509 = cppVar_522;
	}
	cppVar_496 = cppVar_509;
	}
	cppVar_483 = cppVar_496;
	}
	cppVar_472 = cppVar_483;
	}
	return cppVar_472;
}

#pragma once
#include <mintest/suit.h>

void SizeT();
void CapacityT();
void DataT();
void IsEmptyT();
void ContainerEqualT();

void FrontT();
void BackT();
void AtT();

void PushBackT();
void PushFrontT();
void PopBackT();

void InsertT();
void DeleteAtT();
void RemoveT();
void FindT();

void register_tests(TestSuit &Ts);

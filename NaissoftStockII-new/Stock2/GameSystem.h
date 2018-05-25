/*
 * GameSystem.h
 *
 * ���� ������ ó�� ���� �ֻ��� ��� ����
 *
 * Created on : 2018-05-01
 *     Author : Jeong Ji-ung
 */
#pragma once

 // Header file
#include "Market.h"
#include "GameManager.h"
#include "Company.h"
#include "Stock.h"
#include "Player.h"
#include "Bank.h"
#include "AISystem.h"

namespace GameSystem
{

// Define
#define START_MONEY			5000000
#define DEFAULT_INTER_RATE	0.05

#define ENTER				13

#define TAX(money)			(30000 + ((money) / 100))

}
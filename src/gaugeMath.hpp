#pragma once
#ifndef GAUGEMATH_HPP
#define GAUGEMATH_HPP
#include <cstdint>

static constexpr int32_t ARC_WIDTH = 35;

static constexpr int32_t RPM_ARC_SIZE = 542;
static constexpr int32_t RPM_ARC_ROTATION = 200;
static constexpr int32_t RPM_ARC_ANGLE = 140;
static constexpr int32_t RPM_MIN = 0;
static constexpr int32_t RPM_MAX = 7000;

static constexpr int32_t SPEEDO_ARC_SIZE = 672;
static constexpr int32_t SPEEDO_ARC_ROTATION = 190;
static constexpr int32_t SPEEDO_ANGLE = 160;
static constexpr int32_t SPEED_MIN = 0;
static constexpr int32_t SPEED_MAX = 130;

static constexpr int32_t FUEL_ARC_SIZE = 672;
static constexpr int32_t FUEL_ARC_ROTATION = 10;
static constexpr int32_t FUEL_ANGLE = 45;
static constexpr int32_t FUEL_MIN = 0;
static constexpr int32_t FUEL_MAX = 100;

static constexpr int32_t TEMP_ARC_SIZE = 672;
static constexpr int32_t TEMP_ARC_ROTATION = 125;
static constexpr int32_t TEMP_ANGLE = 45;
static constexpr int32_t TEMP_MIN = 0;
static constexpr int32_t TEMP_MAX = 100;

static constexpr int32_t RPM_LABEL_OFFSET = -12;
static constexpr int32_t SPEEDO_LABEL_OFFSET = -24;
static constexpr int32_t FUEL_LABEL_OFFSET = -36;
static constexpr int32_t TEMP_LABEL_OFFSET = -48;

#endif

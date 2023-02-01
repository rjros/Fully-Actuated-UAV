// -----------------------------------------------------------------------------
// This file was autogenerated by symforce from template:
//     function/FUNCTION.h.jinja
// Do NOT modify by hand.
// -----------------------------------------------------------------------------

#pragma once

#include <matrix/math.hpp>

namespace sym {

/**
 * This function was autogenerated from a symbolic function. Do not modify by hand.
 *
 * Symbolic function: computy_gravity_innov_var_and_k_and_h
 *
 * Args:
 *     state: Matrix24_1
 *     P: Matrix24_24
 *     meas: Matrix31
 *     R: Scalar
 *     epsilon: Scalar
 *
 * Outputs:
 *     innov: Matrix31
 *     innov_var: Matrix31
 *     Kx: Matrix24_1
 *     Ky: Matrix24_1
 *     Kz: Matrix24_1
 *     Hx: Matrix1_24
 *     Hy: Matrix1_24
 *     Hz: Matrix1_24
 */
template <typename Scalar>
void ComputyGravityInnovVarAndKAndH(const matrix::Matrix<Scalar, 24, 1>& state,
                                    const matrix::Matrix<Scalar, 24, 24>& P,
                                    const matrix::Matrix<Scalar, 3, 1>& meas, const Scalar R,
                                    const Scalar epsilon,
                                    matrix::Matrix<Scalar, 3, 1>* const innov = nullptr,
                                    matrix::Matrix<Scalar, 3, 1>* const innov_var = nullptr,
                                    matrix::Matrix<Scalar, 24, 1>* const Kx = nullptr,
                                    matrix::Matrix<Scalar, 24, 1>* const Ky = nullptr,
                                    matrix::Matrix<Scalar, 24, 1>* const Kz = nullptr,
                                    matrix::Matrix<Scalar, 1, 24>* const Hx = nullptr,
                                    matrix::Matrix<Scalar, 1, 24>* const Hy = nullptr,
                                    matrix::Matrix<Scalar, 1, 24>* const Hz = nullptr) {
  // Total ops: 10

  // Unused inputs
  (void)state;
  (void)P;

  // Input arrays

  // Intermediate terms (1)
  const Scalar _tmp0 =
      -std::sqrt(Scalar(epsilon + std::pow(meas(0, 0), Scalar(2)) +
                        std::pow(meas(1, 0), Scalar(2)) + std::pow(meas(2, 0), Scalar(2))));

  // Output terms (8)
  if (innov != nullptr) {
    matrix::Matrix<Scalar, 3, 1>& _innov = (*innov);

    _innov(0, 0) = _tmp0;
    _innov(1, 0) = _tmp0;
    _innov(2, 0) = -Scalar(9.8066499999999994) * R + _tmp0;
  }

  if (innov_var != nullptr) {
    matrix::Matrix<Scalar, 3, 1>& _innov_var = (*innov_var);

    _innov_var(0, 0) = R;
    _innov_var(1, 0) = R;
    _innov_var(2, 0) = R;
  }

  if (Kx != nullptr) {
    matrix::Matrix<Scalar, 24, 1>& _kx = (*Kx);

    _kx.setZero();
  }

  if (Ky != nullptr) {
    matrix::Matrix<Scalar, 24, 1>& _ky = (*Ky);

    _ky.setZero();
  }

  if (Kz != nullptr) {
    matrix::Matrix<Scalar, 24, 1>& _kz = (*Kz);

    _kz.setZero();
  }

  if (Hx != nullptr) {
    matrix::Matrix<Scalar, 1, 24>& _hx = (*Hx);

    _hx.setZero();
  }

  if (Hy != nullptr) {
    matrix::Matrix<Scalar, 1, 24>& _hy = (*Hy);

    _hy.setZero();
  }

  if (Hz != nullptr) {
    matrix::Matrix<Scalar, 1, 24>& _hz = (*Hz);

    _hz.setZero();
  }
}  // NOLINT(readability/fn_size)

// NOLINTNEXTLINE(readability/fn_size)
}  // namespace sym

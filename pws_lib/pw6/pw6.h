#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#include "../pw5/pw5.h"

/*************************************************************************************************************************
Exercise 1: Define type (typedef)
*/

typedef struct Monomial {

    float coefficient;  /* Coefficient of the monomial */

    int degree;         /* Degree of the monomial */

    struct Monomial* next; /* Pointer to the next monomial in the polynomial */

} Monomial;



typedef struct Polynomial {

    Monomial* head;     /* Pointer to the fisrt monomial in the polynomial */

} Polynomial;



/*************************************************************************************************************************
Exercise 2: Initialize
*/


/**
 * @brief Initializes a polynomial to be an empty polynomial.
 *
 * @param pol Pointer to the polynomial to be initialized.
 */
void init_pol(Polynomial* pol) {

    pol->head = NULL;
}



/*************************************************************************************************************************
Exercise 3: Destroy
*/


/**
 * @brief Frees memory allocated for a polynomial and its monomials.
 *
 * @param pol Pointer to the polynomial to be destroyed.
 */
void destroy_pol(Polynomial* pol) {

    Monomial* current = pol->head; // Pointer to the first monomial of the polynomial.

    while (current != NULL) {

        Monomial* temp = current;

        current = current->next;

        free(temp); // Free the momory allocated for the monomial.
    }
    pol->head = NULL; //  Reset head to NULL.
}



/*************************************************************************************************************************
Exercise 4: Display
*/


/**
 * @brief Displays the polynomial for debugging purposes.
 *
 * @param pol Pointer to the polynomial to be displyed.
 */
void display_debug(Polynomial* pol) {

    Monomial* current = pol->head;

    printf("(");

    while (current != NULL) {

        printf("%.2fx^%d", current->coefficient, current->degree);

        if (current->next != NULL)

            printf(" + ");

        current = current->next;
    }
    printf(")\n");
}


/*************************************************************************************************************************
Exercise 5: Nullity of a polynomial
*/


/**
 * @brief Checks if a polynomial is the zero polynomial.
 * @param pol Pointer to the polynomial to be checked.
 * @return 1 if the polynomial is the zero polynomial, 0 otherwise.
 */
int is_zero_polynomial(Polynomial* pol) {

    return pol->head == NULL;
}


/*************************************************************************************************************************
Exercise 6: Add a monomial
*/


/**
 * @brief Adds a monomial to the polynomial.
 *
 * @param pol Pointer to the polynomial.
 * @param coefficient Coefficient of the monomial to be added.
 * @param degree Degree of the monomial to be added.
 */
void add_monomial(Polynomial* pol, float coefficient, int degree) {

    Monomial* newMonomial = (Monomial*)malloc(sizeof(Monomial));

    if (newMonomial == NULL) {

        printf("Memory allocation failed\n");

        return;
    }
    newMonomial->coefficient = coefficient;

    newMonomial->degree = degree;

    newMonomial->next = NULL;

    if (is_zero_polynomial(pol)) {

        pol->head = newMonomial;

    } else {

        Monomial* current = pol->head;

        while (current->next != NULL) {

            current = current->next;
        }
        current->next = newMonomial;
    }
}



/*************************************************************************************************************************
Exercise 7: Add two polynomials
*/



/**
 * @brief Adds two polynomials.
 *
 * @param pol_1 Pointer to the first polynomial.
 * @param pol_2 Pointer to the second polynomial.
 * @return The sum of the two polynomials.
 */
Polynomial add_polynomials(Polynomial* pol_1, Polynomial* pol_2) {

    Polynomial result;

    init_pol(&result);

    Monomial* current1 = pol_1->head;

    Monomial* current2 = pol_2->head;

    while (current1 != NULL || current2 != NULL) {

        float coeff1, coeff2;

        int degree1, degree2;

        if (current1 != NULL) {

            coeff1 = current1->coefficient;

            degree1 = current1->degree;

        } else {

            coeff1 = 0;

            degree1 = INT_MIN;
        }

        if (current2 != NULL) {

            coeff2 = current2->coefficient;

            degree2 = current2->degree;

        } else {

            coeff2 = 0;

            degree2 = INT_MIN;
        }


        if (degree1 > degree2) {

            add_monomial(&result, coeff1, degree1);

            current1 = current1->next;

        } else if (degree2 > degree1) {

            add_monomial(&result, coeff2, degree2);

            current2 = current2->next;

        } else {

            float sum = coeff1 + coeff2;

            if (sum != 0)

                add_monomial(&result, sum, degree1);

            current1 = current1->next;

            current2 = current2->next;
        }
    }
    return result;
}



/*************************************************************************************************************************
Exercise 8: Remove null monomials
*/



/**
 * @brief Removes monomials with zero coefficients from the polynomial.
 *
 * @param pol Pointer to the polynomial.
 */
void remove_null_monomials(Polynomial* pol) {

    Monomial* current = pol->head;

    Monomial* prev = NULL;

    while (current != NULL) {

        if (current->coefficient == 0) {

            if (prev == NULL) {

                pol->head = current->next;

            } else {

                prev->next = current->next;
            }

            Monomial* temp = current;

            current = current->next;

            free(temp);

        } else {

            prev = current;

            current = current->next;
        }
    }
}



/*************************************************************************************************************************
Exercise 9: Putting a polynomial in canonical form
*/



/**
 * @brief Sorts the monomials of the polynomial in descending order of degrees.
 *
 * @param pol Pointer to the polynomial.
 */
void sort_monomials(Polynomial* pol) {

    Monomial* current = pol->head;

    Monomial* index = NULL;

    float tempCoeff;

    int tempDegree;

    if (current == NULL)

        return;

    while (current != NULL) {

        index = current->next;

        while (index != NULL) {

            if (current->degree < index->degree) {

                tempCoeff = current->coefficient;

                tempDegree = current->degree;

                current->coefficient = index->coefficient;

                current->degree = index->degree;

                index->coefficient = tempCoeff;

                index->degree = tempDegree;
            }

            index = index->next;
        }
        current = current->next;
    }
}



/**
 * @brief Puts the polynomial in canonical form.
 *
 * @param pol Pointer to the polynomial.
 */
void coanonical_form (Polynomial* pol) {

    sort_monomials(pol);

    remove_null_monomials(pol);
}



/*
  Example function to show the usage. 
*/
int pw_6() {
    Polynomial pol_1, pol_2, sum;
    init_pol(&pol_1); // Initialize first polynomial.
    init_pol(&pol_2); // Initialize second polynoamial.
    init_pol(&sum);  // Initialize a sum polynomial.


    // Add monomails to the first polymomial.
    add_monomial(&pol_1, 3.5, 2);
    add_monomial(&pol_1, -2.1, 1);
    add_monomial(&pol_1, 1.7, 0);

    // Add monomials to the second polynomial.
    add_monomial(&pol_2, 4.2, 3);
    add_monomial(&pol_2, 1.5, 1);

    printf("%s",WHITE);
    // Print the fisrt and second polynomials.
    printf("\nPolynomial 1: ");
    display_debug(&pol_1);
    printf("Polynomial 2: ");
    display_debug(&pol_2);

    // Add the first and the secodn polynomials.
    sum = add_polynomials(&pol_1, &pol_2);
    printf("Sum of Polynomial 1 and Polynomial 2: ");
    display_debug(&sum);

    printf("%s",RESET);
    // Destroy all three polynomails.
    destroy_pol(&pol_1);
    destroy_pol(&pol_2);
    destroy_pol(&sum);

    printf("\n%sGet the code from%s pws_lib/pw6%s directory%s\n",WHITE,GREEN,WHITE,RESET);

    return 0;
}

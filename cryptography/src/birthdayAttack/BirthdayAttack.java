package birthdayAttack;

/**
 * Created by rdimri on 10/13/16.
 */
public class BirthdayAttack {
    private  double pOfAtleastTwoPigeonsBeingInSameHole(int pigeons, int holes) {
        if (holes <= pigeons) return 1;
        float res = 1;
        for (int i = 0; i < pigeons; i++) {
            float availableHoles = holes - i;
            float probabiltyOfFindingAHole = availableHoles/holes;
            res *= probabiltyOfFindingAHole;
        }
        return  1 - res;
    }

    public static void main(String[] args) {
        BirthdayAttack birthdayAttack = new BirthdayAttack();
        for (int i = 1; i < 80 ; i++) {
            System.out.println("People = " + i + " probability = " +  birthdayAttack.pOfAtleastTwoPigeonsBeingInSameHole(i, 365));
        }

    }
}

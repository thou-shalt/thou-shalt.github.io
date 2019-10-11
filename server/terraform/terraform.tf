terraform {
  backend "s3" {
    encrypt = true
    region  = "eu-west-1"
    bucket  = "thou-shalt-terraform-state"
    key     = "global/s3/terraform.tfstate"
  }
}

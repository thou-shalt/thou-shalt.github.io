provider "aws" {
  version = "~> 2.0"
  region  = "eu-west-1"
}
resource "aws_s3_bucket" "thou-shalt-terraform-state" {
  bucket = "thou-shalt-terraform-state"

  versioning {
    enabled = false 
  }

  lifecycle {
    prevent_destroy = false 
  }

}